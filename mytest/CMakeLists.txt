cmake_minimum_required (VERSION 3.10)

set(TESTS
  NH4_2_SO4
  14C_isotopes
  a_e_t2
  adapted_minteq
  advect_ranges
  aj1
  alkalinity
  all_llnl
  Amm
  andra_kin_ss
  andsurfcomplex4
  anh_P_NaCl
  anhy_K2SO4
  anhy_Na2SO4
  anhy_NaCl
  Anhy_NaCl_T&P
  antarcticite
  Apelbl_Na2CO3
  aquia
  aquia2
  As
  as.ex
  asf
  bad_graph
  ball
  balonis
  Barite_MCl2
  Barite_NaCl
  Barite_tc
  basic_test
  brown
  Ca_Na_K_Clmix
  Ca-As-Mahoney
  CaCl2_P_T
  calc_density
  calc_SC
  calc_values
  calcite_rate
  CalPortDiff
  Carnallite
  cc_1barCO2
  cc_Ellis
  cc_Malin
  cc_P
  cc_P0
  cc_P2
  cc_P3
  cd_ddl
  cdmus3
  cdmusic_hiemstra
  cdmusic_related
  cell_operations
  CFAscmtest
  CH4_conc_PR_IS
  ch4-valid
  co2
  CO2_4M_NaCl
  CO2_anal
  CO2_conc_PR_EQ
  CO2_conc_PR_GP
  CO2_conc_PR_GP1
  CO2_conc_PR_IS
  CO2_K_H
  CO2_Na2SO4
  co2_pressure_bug
  CO2_sp_IS
  co2_t30
  co2_tc
  co2_VP
  colloid_U
  colt1
  colt2
  colt3
  colt3_mi
  colt4
  colt5
  comments
  connect_graph
  convert_units
  count_database_species
  count_database_species_core10
  Cub
  cumulativetime
  current_analytical
  current1
  current2
  DanPhuong
  ddl_flux
  ddl_set
  ddlsurf
  de
  deb1
  deb2
  debye1
  delta_h
  deltas
  densities
  desc
  diel
  diff_c
  dissolve_only
  dist_x
  dl_type_error
  donly
  DonnanBug
  dump_test
  eco
  edl_species
  empty_conc
  eq_EC
  eq_phase_mod
  Equiv_Conduct
  erm
  evap
  evap_sea
  ex_ild
  ex1
  ex10
  ex10_pz
  ex11
  ex12
  ex12b
  ex13_impl
  ex15.cvode
  ex16mp
  ex17mp
  ex18mp
  ex2
  ex20_debug
  ex3
  ex4
  ex5
  ex6
  ex6.cvode
  ex7
  ex7_T_P
  ex8
  ex8_tail_biter
  ex9
  ex9.cvode
  exch_kin_related
  exch_kin_related_pz
  exch_related
  exch_related_pz
  ExchangeGamma
  ExchMixRelatedKin
  ExchMixRelatedMin
  f_viscos
  Fe+2
  feb
  febmp
  feedwater
  ferri_surface
  fig1
  fiona
  fix_P
  fix_V
  fixed_volume_gas
  fixed_volume_gas_pz
  fluorite
  gas
  gas_binary_parameters
  gas_fix_P
  gas_fix_V
  Gas_FixVolume
  gas_mod
  gas_phase_mix
  gas_phase_pressure
  gas_type_switch
  gas9
  get_put_
  gfw
  Goldsack
  gyps_Na2SO4
  gyps_NaCl
  gypsum
  gypsum_P
  gypsum_P2
  gypsum_P5
  H_HCl_HBr
  H_K
  H2
  H2S_71C
  H2S_Amm
  H2S_NaCl_Na2SO4
  H2S_numerical
  H2S_pz
  H2S_pz_appt
  H2S_sit
  halite
  Halite_P
  Hao
  Hao_wateq4fhao
  hard.tests
  harm_mean
  Hebach
  Hefter_KClNaOH
  high_mu
  HighTPwaterGas
  hittorf1
  HNaK_Cl
  homo
  i2
  i3
  i4
  i5
  i6
  i7
  IL_flux
  IllitisationCEC
  Ilulissat_diff3
  implicit_as
  include
  initial_gas
  Int_vs_Don
  is
  iso_example
  iso_inverse
  iso10
  jgb2col
  jgbcol
  Jiang_pz
  jm_trans
  joe
  K2SO4
  katz
  KCl
  KCl-SO4
  kin_r
  kin_time
  kinetic_rates
  kinetic_rates_plus
  kinetic_rates_carbfix
  kinex
  KinSorbNp
  kinsurf
  krest
  lam10
  lam7
  lassin
  lk_phase
  lkspecies
  llnl
  llnl_extended
  llnl_phreeqc_dha_dhb
  local_min_pz
  low_p
  low_t
  M_M2Cl_SC
  mahoney
  MassWater
  McBride_rho
  McClesk
  mean_gammas
  membrane
  MethEthPropIsotopes
  MgCl2
  mgcl2mgso4_pz
  MgCl-SO4
  MgSO4
  millero
  minteq
  minteqv4
  missing_surf_related_equi
  missing_surf_related_kin
  mix_unequal
  mixes
  mmb
  mmb2
  mmb2_pitzer
  modify_ignore
  modify_test
  modify_zero
  modifyact
  MoreExchMix
  mu
  multi_punch
  mV_SO4_rho
  mV1_rho
  mV2_rho
  N2_conc_PR_IS
  N2_ideal
  n3
  Na_MgCl
  Na2SO4
  Na2SO4_phr
  NaCl
  NaCl_temp
  NaCl-SO4
  NaK_ClSO4
  NaK_Mg_ClSO4
  NaKCl
  NaKCl_Lang
  NaK_ClBr
  NaMgCl
  NaNH4K_ClBrSO4
  NaOH_density
  Nardi
  negative_mix
  negative_user_number
  negexp_totmol
  netpathxl
  no_negative_dump
  notab
  np.test
  np.testmp
  num_spread
  O2_conc_PR_IS
  opa_col2
  opa_col3
  org_gas
  osmotic
  oxygen
  oxygenmp
  P_CO2_Na2SO4
  p_dep_species
  P_Vm
  peng_SO2
  PercentSC
  phantom_surface
  phase_formula
  phase_vm
  phi_Angus
  phi_CO2-CH4_GP
  phi_Duan_PR
  phi_Duan_PR_EQ
  phreeqc.test
  phrqpitz.tst
  pitzalphas
  pitzer_fail
  pitzer_redef
  pitzer_redef_2
  pitzgas
  pKw
  ppdump
  PR_EQ
  PR_EQ_GP
  PR_equil
  PR_equil2
  PR_error_incremental
  pr_h2o
  PR_initial_gas
  PR_initial_gas_noredox
  PR_mx_new
  precipitate_only
  pressure_si
  prob8
  punch_stream
  pyrite_34s
  R-04_01_PHRC
  rahn
  rate_parameters
  rate_xmpls
  Ratework
  raw
  reaction_p
  reaction_pressure_gas
  rho_CaKMgNaCl
  rho_CaNaCl
  rho_H3PO4
  rho_MgCaCl
  rho_MgNaCl
  rotter
  Ruby
  run_cell_range
  run_cells
  s1
  salt_ec
  salt_ec_chart
  salt_sc
  salt_sc1
  samemodel
  sar
  Sat_P_rho
  saunders
  saver
  SC_Ohm
  SC_Ohm1
  SC_temp
  sc1
  sc2
  sc3
  sc4
  sc5
  sc6
  sc6a
  sc6b
  sc7
  seaw
  seaw_0_200C
  seaw_anhyd
  seaw_Fabuss
  seaw_SC
  sit_edl
  sit_redox
  solid_solution
  solid_solution_pz
  soln_vol
  solution_s
  spec_cond
  species_equation
  species_formula
  spread_redox
  spread_solution
  SrSO4_P
  SrSO4_tc
  ss_incr
  ss_kinetics
  ss_r
  stag_diss_only
  str_f
  stuyfz
  surf_check
  surf_error
  surf_kin_related
  surf_kin_related_pz
  surf_related
  surf_related_pz
  surf_related_warnings
  surf_total
  surf_transport
  surf3
  surf3_density
  surface_mix
  surface_punch_all
  SurfMixRelatedKin
  SurfMixRelatedMin
  Syn1_acidbase
  sys_equi
  sys_equi_fix
  sys_ex
  sys_gas
  sys_kin
  sys_sort
  t2
  t922
  ternary
  test_sit
  tn_KBr
  Tn_M_M2Cl
  toner
  TonyLitharge2a
  TotalPlus
  transport
  transport.dl
  trim
  unequal
  uphill_NP
  uphill_NPa
  user_print
  using
  v_TP_K2SO4
  v_TP_MgSO4
  v_TP_Na2SO4
  variable_cell_diffusion
  visc_anio_tc
  visc_cat_tc
  visc_MgSO4
  visc_NaK2SO4
  visc_NaKCl
  Vm_BaCl2_sol
  Vm_CaCl2_sol
  Vm_HCl_sol
  Vm_KCl_sol
  Vm_KF
  Vm_KHCO3_sol
  Vm_LiCl_sol
  Vm_MgCl2_sol
  Vm_Na2CO3_sol
  Vm_Na2SO4_sol
  Vm_NaCl_sol
  Vm_NaF
  Vm_NaHCO3_sol
  Vm_NaNO3_sol
  Vm_NH4Cl_sol
  Vm_salt
  Vm_salt_65
  Vm_salt_fig
  Vm_SrCl2_sol
  Vm0_tc
  volume-zero
  water_vp
  water_vp1
  wjAs2
  xsoln_visc
  y_H2O
  Yang_mix
  zero_modify
  zeta
  Zhang_mix
  zn.test
)

# expect to fail
set(FAILS
  CFAscmtest
  feedwater
  Hao
  high_mu
  IllitisationCEC
  missing_surf_related_equi
  missing_surf_related_kin
  modify_test
  negative_user_number
  negexp_totmol
  pitzer_fail
  punch_stream
  raw
  surf_error
  surf_related_warnings
  Syn1_acidbase
  wjAs2
)

# mytest misc files
set(mytest_MISC
  adapted_minteq.dat
  angus.dat
  anh_nacl.csv
  anh_P_100tc.csv
  anh_P_150tc.csv
  anh_P_200tc.csv
  Apelbl_Na2CO3.dat
  Barite_NaCl.dat
  Barite_tc.dat
  Ca_K2SO4.csv
  Carnallite.csv
  casf_na.csv
  cc_1barCO2.dat
  cc_Ellis.dat
  cc_Malin.dat
  cc_p_CO2.dat
  cc_P.dat
  cc_tc100.dat
  cdmusic_hiemstra.dat
  ch4_100c.dat
  ch4_25c.dat
  ch4_50c.dat
  co2_4m_NaCl.dat
  CO2_Na2SO4.dat
  co2_t30.dat
  co2_tc.dat
  co2_VP.dat
  co2.dat
  co2.dat
  co2.dat
  co2.dat
  Cub_export.txt
  Cub_Jdsb_export.txt
  Cub_JdsbSr.txt
  Cub_Sr.txt
  dens.csv
  densities.dat
  eco.dat
  eq_phase_mod.dat
  ex15.dat
  f_CO2_50.dat
  f_CO2_50.dat
  f_CO2_75.dat
  f_CO2.dat
  f_CO2.dat
  gas_no_redox.dat
  gyps_Na2SO4.csv
  gyps_NaCl.csv
  H2.dat
  H2_NaCl.dat
  H2_NaCl_100C.dat
  H_K.tsv
  H2S.dat
  H2S_Na2SO4.dat
  H2S_NaCl.dat
  H2S_71C.dat
  halite.dat
  Hebach.dat
  include2
  include3
  include4
  jm_trans.dat
  kinetic_rates.dat
  LangmuirAs_wateq4f.dat
  mahoney.dat
  McCleskey.phr
  McBride_rho.tsv
  McBride_rho2.tsv
  McBride_rho3.tsv
  mgso4.csv
  mV_SO4_rho.dat
  mV1_rho.dat
  mV2_rho.dat
  n2_25C.dat
  na2so4.csv
  nakcl.csv
  NaKCl.dat
  NaKCl_Lang.dat
  Nardi.dat
  O2_27.dat
  p_CO2_Na2SO4.dat
  Pabalan.dat
  pfw.dat
  Phmaster14.dat
  Phreeqc_master_NEA_Ra_Mo_V_MCJ.dat
  pitzer-04.dat
  Qin_CH4.dat
  Qin_CO2.dat
  sar.dat
  seaw.dat
  srso4_P.dat
  THEREDA_PIT_PHRC_r04.dat
  Tipping&Hurley.dat
  Vm0_tc.dat
  wateq4fhao.dat
  y_H2O.dat
  zeta.tsv
  Zhang_CaCl.dat
  Zhang_KCaCl.dat
  Zhang_NaCaCl.dat
)

# label H2S_files
# ctest -L H2S_files
set(H2S_FILES
  mytest.CO2_conc_PR_GP1
  mytest.H2S_71C
  mytest.H2S_Amm
  mytest.H2S_NaCl_Na2SO4
  mytest.H2S_numerical
  mytest.H2S_pz
  mytest.H2S_pz_appt
  mytest.H2S_sit
  mytest.Jiang_pz
)

# label current
# ctest -L current
set(CURRENT
  #mytest.Clogging
  mytest.current_analytical
  mytest.current2
)

# label pitzer
# ctest -L pitzer
set(PITZER
  mytest.anh_P_NaCl
  mytest.anhy_K2SO4
  mytest.anhy_Na2SO4
  mytest.anhy_NaCl
  mytest.Barite_MCl2
  mytest.Barite_NaCl
  mytest.Carnallite
  mytest.cc_1barCO2
  mytest.CO2_4M_NaCl
  mytest.CO2_Na2SO4
  mytest.evap
  mytest.evap_sea
  mytest.ex10_pz
  mytest.exch_kin_related_pz
  mytest.exch_related_pz
  #mytest.fail1
  #mytest.fail2
  #mytest.fail3
  mytest.fixed_volume_gas_pz
  mytest.gyps_Na2SO4
  mytest.gyps_NaCl
  mytest.gypsum
  mytest.gypsum_P2
  mytest.gypsum_P5
  mytest.halite
  mytest.Halite_P
  mytest.K2SO4
  mytest.KCl
  mytest.KCl-SO4
  mytest.local_min_pz
  mytest.MgCl-SO4
  mytest.MgCl2
  mytest.mgcl2mgso4_pz
  mytest.MgSO4
  mytest.Na2SO4
  mytest.NaCl
  mytest.NaCl_temp
  mytest.NaCl-SO4
  mytest.NaKCl
  mytest.NaMgCl
)

# frezchem labels
# ctest -L frezchem
set(FREZCHEM
  mytest.anh_P_NaCl
  mytest.anhy_K2SO4
  mytest.anhy_Na2SO4
  mytest.anhy_NaCl
  mytest.Carnallite
  mytest.evap_sea
  mytest.ex10_pz
  mytest.exch_kin_related_pz
  mytest.exch_related_pz
  mytest.fixed_volume_gas_pz
  mytest.gyps_Na2SO4
  mytest.gyps_NaCl
  mytest.gypsum
  mytest.gypsum_P2
  mytest.gypsum_P5
  mytest.halite
  mytest.Halite_P
  mytest.K2SO4
  mytest.KCl-SO4
  mytest.MgCl-SO4
  mytest.mgcl2mgso4_pz
  mytest.Na2SO4
  mytest.NaCl-SO4
  mytest.NaKCl
  mytest.NaMgCl
)

# ss labels
# ctest -L ss
set(SS
  mytest.basic_test
  mytest.cell_operations
  mytest.ex20_debug
  mytest.iso_example
  mytest.iso10
  mytest.kin_time
  mytest.mixes
  mytest.modify_ignore
  mytest.multi_punch
  mytest.no_negative_dump
  mytest.phase_formula
  mytest.ppdump
  mytest.pyrite_34s
  mytest.solid_solution
  mytest.solid_solution_pz
  mytest.ss_incr
  mytest.ss_r
  mytest.surface_punch_all
)


# long_debug
# > 600 seconds Debug
# ctest -L long_debug
set(LONG_DEBUG
  mytest.adapted_minteq
  mytest.count_database_species
  mytest.Cub
  mytest.current_analytical
  mytest.current2
  mytest.membrane
  mytest.mmb2
  mytest.TonyLitharge2a
  mytest.unequal
)

# long_memcheck
# > 600 seconds valgrind
# ctest -L long_memcheck
set(LONG_MEMCHECK
  mytest.andra_kin_ss
  mytest.balonis
  mytest.current1
  mytest.opa_col3
)

# for mytest tests
# copy to build directory
foreach(misc ${mytest_MISC})
  configure_file(${misc} ${misc} COPYONLY)
endforeach()

# add tests
foreach(test ${TESTS})
  configure_file(${test} ${test} COPYONLY)
  add_test(NAME mytest.${test}
           COMMAND $<TARGET_FILE:phreeqc> ${test} ${test}.out xxx ${test}.log
  )
endforeach()

# expect to fail
foreach(test ${FAILS})
  set_tests_properties(mytest.${test} PROPERTIES WILL_FAIL TRUE)
endforeach()

# Note when setting labels we can't use the following:
#   set_tests_properties(${test} PROPERTIES LABELS "pitzer")
# since it will overwrite any existing labels already set

# H2S_files labels
foreach(test ${H2S_FILES})
  set_property(TEST ${test} APPEND PROPERTY LABELS "H2S_files")
endforeach()

# current labels
foreach(test ${CURRENT})
  set_property(TEST ${test} APPEND PROPERTY LABELS "current")
endforeach()

# pitzer labels
foreach(test ${PITZER})
  set_property(TEST ${test} APPEND PROPERTY LABELS "pitzer")
endforeach()

# frezchem labels
foreach(test ${FREZCHEM})
  set_property(TEST ${test} APPEND PROPERTY LABELS "frezchem")
endforeach()

# ss labels
foreach(test ${SS})
  set_property(TEST ${test} APPEND PROPERTY LABELS "ss")
endforeach()

# Label tests that run longer than 600 seconds (Debug)
#
# Note that when using multi-configuration generators you must specify
# the configuration when using the --print-labels option
# ie
#   ctest --print-labels -C Debug
#
# Override default TIMEOUT using CTEST_TEST_TIMEOUT or
# command line option --timeout <time>
# ie
#   ctest --timeout 1200
# or set for each test explicitly using
#   set_tests_properties(test PROPERTIES TIMEOUT 1200)
#
foreach(test ${LONG_DEBUG})
  set_property(TEST ${test} APPEND PROPERTY LABELS "long_debug")
  set_property(TEST ${test} APPEND PROPERTY LABELS "long_memcheck")
endforeach()

foreach(test ${LONG_MEMCHECK})
  set_property(TEST ${test} APPEND PROPERTY LABELS "long_memcheck")
endforeach()

# numdiff tests
set(REL_ERROR 1e-3)
find_program(NUMDIFF_COMMAND NAMES numdiff PATHS ${CMAKE_SOURCE_DIR}/mingw64/bin)
if (NUMDIFF_COMMAND)
  file(GLOB NUMDIFFS
    RELATIVE ${CMAKE_CURRENT_LIST_DIR}
    *_101.sel
  )
  foreach(numdiff ${NUMDIFFS})
    configure_file(${numdiff} ${numdiff}.expected COPYONLY)
    string(REGEX REPLACE "_101.sel" "" prefix ${numdiff})
    set(test_name mytest.${prefix}.numdiff)
    # add if not expected to fail
    if (NOT ${prefix} IN_LIST FAILS)
      add_test(NAME ${test_name}
               COMMAND ${NUMDIFF_COMMAND} --relative-tolerance=${REL_ERROR} ${numdiff} ${numdiff}.expected
      )
      
      # must run mytest.${prefix} first (to generate ${prefix}_101.sel)
      set_tests_properties(${test_name} PROPERTIES DEPENDS mytest.${prefix})

      # add corresponding labels to numdiff tests
      get_test_property(mytest.${prefix} LABELS labels)
      foreach(label ${labels})
        if (label)
          set_property(TEST ${test_name} APPEND PROPERTY LABELS ${label})
        endif()
      endforeach()
    endif()
  endforeach()
endif()

if (NOT PHRQC_ENABLE_REGRESSION_TESTING)
  get_property(all_tests DIRECTORY PROPERTY TESTS)
  foreach(test ${all_tests})
    get_test_property(${test} LABELS test_labels)
    if ("long_debug" IN_LIST test_labels OR "long_memcheck" IN_LIST test_labels)
      # message(STATUS "disabling ${test}" )
      set_tests_properties(${test} PROPERTIES DISABLED TRUE)
    endif()
  endforeach()
endif()
