#ifndef PHREEQC_PR_STABLE_ROOT_H
#define PHREEQC_PR_STABLE_ROOT_H
// Root-only extension, C++11. Native PHREEQC L-atm units and rounded
// fugacity constants are deliberate. No database or mixing-rule changes.
#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>
namespace phrq_pr {
struct Component { double y, b, attraction_sum; };
struct Candidate {
    double z, vm, pressure_residual, dpdv, slope, gibbs;
    bool physical, stable, critical;
    std::vector<double> lnphi;
};
struct Selection {
    std::vector<Candidate> roots;
    int selected;
    bool degenerate, coexistence;
    Selection(): selected(-1), degenerate(false), coexistence(false) {}
};
inline Selection select(double P, double RT, double a, double b,
                        const std::vector<Component>& components) {
    if (!(std::isfinite(P) && P>0 && std::isfinite(RT) && RT>0 &&
          std::isfinite(a) && a>0 && std::isfinite(b) && b>0) || components.empty())
        throw std::runtime_error("PR_ROOT_INVALID_PARAMETERS");
    double sy=0, sb=0, sa=0;
    for (size_t i=0;i<components.size();++i) {
        const Component& c=components[i];
        if (!std::isfinite(c.y) || c.y<0) throw std::runtime_error("PR_ROOT_INVALID_COMPOSITION");
        if (c.y==0) continue; // absent components need no initialized PR cache
        if (!(std::isfinite(c.b) && c.b>0 && std::isfinite(c.attraction_sum)))
            throw std::runtime_error("PR_ROOT_INVALID_COMPONENT");
        sy+=c.y; sb+=c.y*c.b; sa+=c.y*c.attraction_sum;
    }
    if (std::abs(sy-1)>1e-9 || std::abs(sb/b-1)>1e-9 || std::abs(sa/a-1)>1e-9)
        throw std::runtime_error("PR_ROOT_INCONSISTENT_MIXTURE");
    typedef long double Real;
    Real A=Real(a)*P/(Real(RT)*RT), B=Real(b)*P/RT;
    // Z^3+c2*Z^2+c1*Z+c0=0. Long double limits cancellation.
    Real c2=B-1, c1=A-2*B-3*B*B, c0=-A*B+B*B+B*B*B;
    Real p=c1-c2*c2/3, q=2*c2*c2*c2/27-c2*c1/3+c0;
    Real d=q*q/4+p*p*p/27;
    Real dtol=64*std::numeric_limits<Real>::epsilon()*(q*q/4+std::abs(p*p*p/27));
    std::vector<Real> zs;
    Selection out;
    if (d>dtol) {
        Real h=std::sqrt(d);
        Real u=std::cbrt(-q/2-std::copysign(h,q));
        Real v=(u!=0 ? -p/(3*u) : std::cbrt(-q/2+h));
        zs.push_back(u+v-c2/3);
    } else if (d < -dtol) {
        Real r=2*std::sqrt(-p/3);
        Real arg=(3*q/(2*p))*std::sqrt(-3/p);
        arg=std::max(Real(-1),std::min(Real(1),arg));
        Real theta=std::acos(arg)/3, pi=std::acos(Real(-1));
        for(int k=0;k<3;++k) zs.push_back(r*std::cos(theta-2*pi*k/3)-c2/3);
    } else {
        out.degenerate=true;
        Real u=std::cbrt(-q/2);
        zs.push_back(2*u-c2/3); zs.push_back(-u-c2/3);
    }
    // Refine the largest-magnitude root and deflate using Vieta products.
    // This recovers tiny liquid/middle roots without subtracting two numbers
    // near 1/3, and distinguishes low-pressure roots even when Cardano's
    // discriminant loses their separation.
    Real dominant=*std::max_element(zs.begin(),zs.end(),
        [](Real x, Real y) { return std::abs(x)<std::abs(y); });
    for(int it=0;it<5;++it) {
        Real f=((dominant+c2)*dominant+c1)*dominant+c0;
        Real df=(3*dominant+2*c2)*dominant+c1;
        if(std::abs(df)<1e-14L) break;
        dominant-=f/df;
    }
    if(std::abs(dominant)>1e-20L &&
       std::abs((3*dominant+2*c2)*dominant+c1)>1e-12L) {
        Real product=-c0/dominant;
        Real sum=(c1-product)/dominant;
        Real dq=sum*sum-4*product;
        Real qt=64*std::numeric_limits<Real>::epsilon()*(sum*sum+4*std::abs(product));
        zs.clear(); zs.push_back(dominant);
        if(dq>=-qt) {
            if(std::abs(dq)<=qt) out.degenerate=true;
            Real h=std::sqrt(std::max(Real(0),dq));
            Real u=(sum+std::copysign(h,sum))/2;
            zs.push_back(u);
            zs.push_back(u!=0 ? product/u : sum/2);
        }
    }
    std::sort(zs.begin(),zs.end());
    std::vector<Real> unique;
    for(size_t k=0;k<zs.size();++k) {
        Real z=zs[k];
        // Polish only well-conditioned roots; do not jump between branches.
        for(int it=0;it<3;++it) {
            Real f=((z+c2)*z+c1)*z+c0, df=(3*z+2*c2)*z+c1;
            if (std::abs(df)<1e-16L) break;
            Real dz=f/df;
            if (std::abs(dz)>1e-2L*std::max(std::abs(z),B)) break;
            z-=dz;
        }
        if (!unique.empty() && std::abs(z-unique.back())<=1e-10L*std::max(std::abs(z),B)) {
            out.degenerate=true; continue;
        }
        unique.push_back(z);
    }
    for(size_t k=0;k<unique.size();++k) {
        Real z=unique[k], v=z*RT/P, den=v*v+2*b*v-b*b;
        Candidate c; c.z=double(z); c.vm=double(v); c.physical=false;
        c.stable=false; c.critical=false; c.gibbs=std::numeric_limits<double>::quiet_NaN();
        c.pressure_residual=c.dpdv=c.slope=std::numeric_limits<double>::quiet_NaN();
        if (z>B && v>b && den>0) {
            Real pe=RT/(v-b)-a/den;
            c.pressure_residual=double((pe-P)/P);
            c.dpdv=double(-RT/((v-b)*(v-b))+a*(2*v+2*b)/(den*den));
            c.slope=c.dpdv*c.vm/P;
            c.critical=std::abs(c.slope)<1e-7;
            c.physical=std::isfinite(c.vm) && std::isfinite(c.dpdv) && std::abs(c.pressure_residual)<1e-8;
            c.gibbs=0;
            c.stable=c.physical && c.dpdv<=0;
            // log1p avoids loss of precision as B tends to zero. Constants
            // match prep.cpp exactly (including its rounding).
            Real lr=std::log1p(Real(2.82842712)*B/(z-Real(.41421356)*B));
            for(size_t i=0;i<components.size();++i) {
                const Component& co=components[i];
                Real ln=0;
                if (co.y>0) {
                    Real br=co.b/b;
                    ln=br*(z-1)-std::log(z-B)+A/(Real(2.828427)*B)*
                        (br-2*co.attraction_sum/a)*lr;
                    if (!std::isfinite(ln)) c.stable=c.physical=false;
                    c.gibbs+=co.y*double(ln);
                }
                c.lnphi.push_back(double(ln));
            }
        }
        out.roots.push_back(c);
        if (c.stable && (out.selected<0 || c.gibbs<out.roots[out.selected].gibbs))
            out.selected=int(out.roots.size()-1);
    }
    if (out.selected<0) throw std::runtime_error("PR_ROOT_NO_ADMISSIBLE_STABLE_ROOT");
    for(size_t k=0;k<out.roots.size();++k)
        if (int(k)!=out.selected && out.roots[k].stable &&
            std::abs(out.roots[k].gibbs-out.roots[out.selected].gibbs)<=1e-8)
            out.coexistence=true;
    return out;
}
}
#endif
