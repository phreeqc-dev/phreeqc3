#ifndef PHREEQC_PR_ROOT_RUNTIME_H
#define PHREEQC_PR_ROOT_RUNTIME_H
#include "PrStableRoot.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>
namespace phrq_pr {
struct Runtime {
    bool stable;
    unsigned long call;
    std::ofstream log;
    Runtime():stable(false),call(0) {
        const char* p=std::getenv("PHREEQC_PR_ROOT_POLICY");
        std::string policy=p ? p : "legacy";
        if(policy!="legacy" && policy!="stable_homogeneous")
            throw std::runtime_error("PHREEQC_PR_ROOT_POLICY must be legacy or stable_homogeneous");
        stable=(policy=="stable_homogeneous");
        const char* path=std::getenv("PHREEQC_PR_ROOT_LOG");
        if(path && *path) {
            log.open(path, std::ios::out | std::ios::trunc);
            if(!log) throw std::runtime_error("Cannot open PHREEQC_PR_ROOT_LOG");
            log<<std::setprecision(17);
        }
    }
};
// Immutable policy once per process; do not mutate env while embedding PHREEQC.
inline Runtime& runtime() { static Runtime r; return r; }
inline void number(std::ostream& os,double v) {
    if(std::isfinite(v)) os<<v; else os<<"null";
}
inline void diagnose(const Selection& s, double P,double TK,double a,double b,
                     double vm, const std::vector<Component>& cs,
                     int context,int state,int iteration,double initial_volume,
                     const std::vector<double>& applied_raw, const std::vector<double>& applied_lnphi) {
    Runtime& r=runtime(); if(!r.log.is_open()) return;
    std::ostream& o=r.log;
    o<<"{\"call\":"<<++r.call<<",\"policy\":\""<<(r.stable?"stable_homogeneous":"legacy")
     <<"\",\"context\":"<<context<<",\"state\":"<<state<<",\"iteration\":"<<iteration
     <<",\"P_atm\":"<<P<<",\"T_K\":"<<TK<<",\"a\":"<<a<<",\"b\":"<<b
     <<",\"Vm_applied_L_mol\":"<<vm<<",\"initial_volume_L\":";
    if(context==1) o<<initial_volume; else o<<"null";
    o<<",\"initial_moles\":"; if(context==1) o<<initial_volume/vm; else o<<"null";
    o<<",\"selected_minimum\":"<<s.selected<<",\"near_coexistence\":"<<(s.coexistence?"true":"false")
     <<",\"root_degenerate\":"<<(s.degenerate?"true":"false")
     <<",\"mixture_global_stability\":\"MIXTURE_PHASE_STABILITY_UNVERIFIED\",\"components\":[";
    for(size_t i=0;i<cs.size();++i) {
        if(i)o<<",";
        o<<"{\"y\":"<<cs[i].y<<",\"b\":"; number(o,cs[i].b);
        o<<",\"attraction_sum\":"; number(o,cs[i].attraction_sum); o<<"}";
    }
    o<<"],\"applied_lnphi_raw\":[";
    for(size_t i=0;i<applied_raw.size();++i) { if(i)o<<","; number(o,applied_raw[i]); }
    o<<"],\"applied_lnphi\":[";
    for(size_t i=0;i<applied_lnphi.size();++i) { if(i)o<<","; number(o,applied_lnphi[i]); }
    o<<"],\"candidates\":[";
    for(size_t k=0;k<s.roots.size();++k) {
        if(k)o<<",";
        const Candidate& c=s.roots[k];
        o<<"{\"Z\":"<<c.z<<",\"Vm_L_mol\":"<<c.vm<<",\"pressure_relative_residual\":";
        number(o,c.pressure_residual); o<<",\"dP_dVm\":"; number(o,c.dpdv);
        o<<",\"physical\":"<<(c.physical?"true":"false")<<",\"mechanically_stable\":"<<(c.stable?"true":"false")
         <<",\"critical_or_spinodal\":"<<(c.critical?"true":"false")<<",\"g_RT\":";
        number(o,c.gibbs); o<<",\"lnphi_raw\":[";
        for(size_t i=0;i<c.lnphi.size();++i) { if(i)o<<","; number(o,c.lnphi[i]); }
        o<<"],\"lnphi_clipped\":[";
        for(size_t i=0;i<c.lnphi.size();++i) { if(i)o<<","; number(o,std::max(-4.6,std::min(4.44,c.lnphi[i]))); }
        o<<"]}";
    }
    o<<"]}\n"; o.flush();
    if(!o) throw std::runtime_error("PR_ROOT_DIAGNOSTIC_WRITE_FAILED");
}
}
#endif
