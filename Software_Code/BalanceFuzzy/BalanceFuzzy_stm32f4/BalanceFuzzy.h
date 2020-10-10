/*
 * File: BalanceFuzzy.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model BalanceFuzzy.
 *
 * Model version                        : 1.4
 * Real-Time Workshop file version      : 8.4 (R2013a) 13-Feb-2013
 * Real-Time Workshop file generated on : Tue Dec 17 19:22:55 2013
 * TLC version                          : 8.4 (Jan 19 2013)
 * C/C++ source code generated on       : Tue Dec 17 19:22:56 2013
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BalanceFuzzy_h_
#define RTW_HEADER_BalanceFuzzy_h_
#ifndef BalanceFuzzy_COMMON_INCLUDES_
# define BalanceFuzzy_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "waijung_hwdrvlib.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#endif                                 /* BalanceFuzzy_COMMON_INCLUDES_ */

#include "BalanceFuzzy_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SFunctionBuilder1;            /* '<S1>/S-Function Builder1' */
  real_T SFunctionBuilder;             /* '<S1>/S-Function Builder' */
  real_T PWM;                          /* '<Root>/V_control' */
  real_T DIR;                          /* '<Root>/V_control' */
  int32_T QuadraturEncoder_o1;         /* '<S1>/Quadratur Encoder' */
  int32_T QuadraturEncoder_o2;         /* '<S1>/Quadratur Encoder' */
  boolean_T DigitalInput;              /* '<S1>/Digital Input' */
} B_BalanceFuzzy_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
} DW_BalanceFuzzy_T;

/* Parameters for system: '<S94>/If Action Subsystem1' */
struct P_IfActionSubsystem1_BalanceF_T_ {
  real_T a_Value;                      /* Expression: a
                                        * Referenced by: '<S98>/a'
                                        */
  real_T b_Value;                      /* Expression: b
                                        * Referenced by: '<S98>/b'
                                        */
};

/* Parameters for system: '<S94>/If Action Subsystem3' */
struct P_IfActionSubsystem3_BalanceF_T_ {
  real_T c_Value;                      /* Expression: c
                                        * Referenced by: '<S100>/c'
                                        */
  real_T d_Value;                      /* Expression: d
                                        * Referenced by: '<S100>/d'
                                        */
};

/* Parameters for system: '<S96>/If Action Subsystem2' */
struct P_IfActionSubsystem2_BalanceF_T_ {
  real_T b_Value;                      /* Expression: b
                                        * Referenced by: '<S107>/b'
                                        */
  real_T c_Value;                      /* Expression: c
                                        * Referenced by: '<S107>/c'
                                        */
};

/* Parameters (auto storage) */
struct P_BalanceFuzzy_T_ {
  real_T MidRange_Value;               /* Expression: mean(cat(1,fis.output.range),2)
                                        * Referenced by: '<S4>/MidRange'
                                        */
  real_T NBConstant_Value;             /* Expression: fis.output(1).mf(1).params(1)
                                        * Referenced by: '<S88>/NB(Constant)'
                                        */
  real_T NMConstant_Value;             /* Expression: fis.output(1).mf(2).params(1)
                                        * Referenced by: '<S88>/NM(Constant)'
                                        */
  real_T NSConstant_Value;             /* Expression: fis.output(1).mf(3).params(1)
                                        * Referenced by: '<S88>/NS(Constant)'
                                        */
  real_T ZEConstant_Value;             /* Expression: fis.output(1).mf(4).params(1)
                                        * Referenced by: '<S88>/ZE(Constant)'
                                        */
  real_T PSConstant_Value;             /* Expression: fis.output(1).mf(5).params(1)
                                        * Referenced by: '<S88>/PS(Constant)'
                                        */
  real_T PMConstant_Value;             /* Expression: fis.output(1).mf(6).params(1)
                                        * Referenced by: '<S88>/PM(Constant)'
                                        */
  real_T PBConstant_Value;             /* Expression: fis.output(1).mf(7).params(1)
                                        * Referenced by: '<S88>/PB(Constant)'
                                        */
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S92>/Out1'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S92>/One'
                                        */
  real_T Out1_Y0_k;                    /* Expression: 0
                                        * Referenced by: '<S97>/Out1'
                                        */
  real_T _Value;                       /* Expression: 0
                                        * Referenced by: '<S97>/0'
                                        */
  real_T Out1_Y0_o;                    /* Expression: 0
                                        * Referenced by: '<S99>/Out1'
                                        */
  real_T _Value_n;                     /* Expression: 1
                                        * Referenced by: '<S99>/0'
                                        */
  real_T Out1_Y0_d;                    /* Expression: 0
                                        * Referenced by: '<S101>/Out1'
                                        */
  real_T _Value_a;                     /* Expression: 0
                                        * Referenced by: '<S101>/0'
                                        */
  real_T Out1_Y0_ob;                   /* Expression: 0
                                        * Referenced by: '<S103>/Out1'
                                        */
  real_T _Value_d;                     /* Expression: 1
                                        * Referenced by: '<S103>/0'
                                        */
  real_T Out1_Y0_g;                    /* Expression: 0
                                        * Referenced by: '<S105>/Out1'
                                        */
  real_T _Value_b;                     /* Expression: 0
                                        * Referenced by: '<S105>/0'
                                        */
  real_T Out1_Y0_ku;                   /* Expression: 1
                                        * Referenced by: '<S106>/Out1'
                                        */
  real_T _Value_k;                     /* Expression: 1
                                        * Referenced by: '<S106>/0'
                                        */
  real_T Out1_Y0_dn;                   /* Expression: 0
                                        * Referenced by: '<S112>/Out1'
                                        */
  real_T _Value_i;                     /* Expression: 0
                                        * Referenced by: '<S112>/0'
                                        */
  real_T Out1_Y0_p;                    /* Expression: 1
                                        * Referenced by: '<S113>/Out1'
                                        */
  real_T _Value_ad;                    /* Expression: 1
                                        * Referenced by: '<S113>/0'
                                        */
  real_T Out1_Y0_o4;                   /* Expression: 0
                                        * Referenced by: '<S116>/Out1'
                                        */
  real_T _Value_g;                     /* Expression: 0
                                        * Referenced by: '<S116>/0'
                                        */
  real_T Out1_Y0_oh;                   /* Expression: 1
                                        * Referenced by: '<S117>/Out1'
                                        */
  real_T _Value_an;                    /* Expression: 1
                                        * Referenced by: '<S117>/0'
                                        */
  real_T Out1_Y0_kuo;                  /* Expression: 0
                                        * Referenced by: '<S120>/Out1'
                                        */
  real_T _Value_h;                     /* Expression: 0
                                        * Referenced by: '<S120>/0'
                                        */
  real_T Out1_Y0_n;                    /* Expression: 1
                                        * Referenced by: '<S121>/Out1'
                                        */
  real_T _Value_dq;                    /* Expression: 1
                                        * Referenced by: '<S121>/0'
                                        */
  real_T Out1_Y0_py;                   /* Expression: 0
                                        * Referenced by: '<S127>/Out1'
                                        */
  real_T _Value_bx;                    /* Expression: 0
                                        * Referenced by: '<S127>/0'
                                        */
  real_T Out1_Y0_m;                    /* Expression: 1
                                        * Referenced by: '<S128>/Out1'
                                        */
  real_T _Value_f;                     /* Expression: 1
                                        * Referenced by: '<S128>/0'
                                        */
  real_T Out1_Y0_ks;                   /* Expression: 0
                                        * Referenced by: '<S131>/Out1'
                                        */
  real_T _Value_nx;                    /* Expression: 0
                                        * Referenced by: '<S131>/0'
                                        */
  real_T Out1_Y0_kf;                   /* Expression: 1
                                        * Referenced by: '<S132>/Out1'
                                        */
  real_T _Value_fa;                    /* Expression: 1
                                        * Referenced by: '<S132>/0'
                                        */
  real_T Out1_Y0_d4;                   /* Expression: 0
                                        * Referenced by: '<S135>/Out1'
                                        */
  real_T _Value_bi;                    /* Expression: 0
                                        * Referenced by: '<S135>/0'
                                        */
  real_T Out1_Y0_b;                    /* Expression: 1
                                        * Referenced by: '<S136>/Out1'
                                        */
  real_T _Value_fz;                    /* Expression: 1
                                        * Referenced by: '<S136>/0'
                                        */
  real_T Out1_Y0_kd;                   /* Expression: 0
                                        * Referenced by: '<S142>/Out1'
                                        */
  real_T _Value_fs;                    /* Expression: 0
                                        * Referenced by: '<S142>/0'
                                        */
  real_T Out1_Y0_e;                    /* Expression: 1
                                        * Referenced by: '<S143>/Out1'
                                        */
  real_T _Value_m;                     /* Expression: 1
                                        * Referenced by: '<S143>/0'
                                        */
  real_T Out1_Y0_f;                    /* Expression: 0
                                        * Referenced by: '<S146>/Out1'
                                        */
  real_T _Value_il;                    /* Expression: 0
                                        * Referenced by: '<S146>/0'
                                        */
  real_T Out1_Y0_gu;                   /* Expression: 1
                                        * Referenced by: '<S147>/Out1'
                                        */
  real_T _Value_g2;                    /* Expression: 1
                                        * Referenced by: '<S147>/0'
                                        */
  real_T Out1_Y0_e5;                   /* Expression: 0
                                        * Referenced by: '<S150>/Out1'
                                        */
  real_T _Value_e;                     /* Expression: 0
                                        * Referenced by: '<S150>/0'
                                        */
  real_T Out1_Y0_mp;                   /* Expression: 1
                                        * Referenced by: '<S151>/Out1'
                                        */
  real_T _Value_o;                     /* Expression: 1
                                        * Referenced by: '<S151>/0'
                                        */
  real_T Weight_Value;                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S7>/Weight'
                                        */
  real_T Constant2_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: pi
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/pi
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/10
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay1'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: 100
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/10
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Constant4_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: pi
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/pi
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Weight_Value_a;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S18>/Weight'
                                        */
  real_T Weight_Value_e;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S29>/Weight'
                                        */
  real_T Weight_Value_o;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S40>/Weight'
                                        */
  real_T Weight_Value_m;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S51>/Weight'
                                        */
  real_T Weight_Value_d;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S62>/Weight'
                                        */
  real_T Weight_Value_h;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S73>/Weight'
                                        */
  real_T Weight_Value_k;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S84>/Weight'
                                        */
  real_T Weight_Value_ou;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S87>/Weight'
                                        */
  real_T Weight_Value_b;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S8>/Weight'
                                        */
  real_T Weight_Value_p;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S9>/Weight'
                                        */
  real_T Weight_Value_g;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S10>/Weight'
                                        */
  real_T Weight_Value_ok;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S11>/Weight'
                                        */
  real_T Weight_Value_po;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S12>/Weight'
                                        */
  real_T Weight_Value_pl;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S13>/Weight'
                                        */
  real_T Weight_Value_l;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S14>/Weight'
                                        */
  real_T Weight_Value_pp;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S15>/Weight'
                                        */
  real_T Weight_Value_kb;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S16>/Weight'
                                        */
  real_T Weight_Value_h3;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S17>/Weight'
                                        */
  real_T Weight_Value_bu;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S19>/Weight'
                                        */
  real_T Weight_Value_eh;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S20>/Weight'
                                        */
  real_T Weight_Value_ka;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S21>/Weight'
                                        */
  real_T Weight_Value_kbs;             /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S22>/Weight'
                                        */
  real_T Weight_Value_db;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S23>/Weight'
                                        */
  real_T Weight_Value_bk;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S24>/Weight'
                                        */
  real_T Weight_Value_hn;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S25>/Weight'
                                        */
  real_T Weight_Value_n;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S26>/Weight'
                                        */
  real_T Weight_Value_g3;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S27>/Weight'
                                        */
  real_T Weight_Value_i;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S28>/Weight'
                                        */
  real_T Weight_Value_pm;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S30>/Weight'
                                        */
  real_T Weight_Value_of;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S31>/Weight'
                                        */
  real_T Weight_Value_p3;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S32>/Weight'
                                        */
  real_T Weight_Value_c;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S33>/Weight'
                                        */
  real_T Weight_Value_oh;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S34>/Weight'
                                        */
  real_T Weight_Value_j;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S35>/Weight'
                                        */
  real_T Weight_Value_f;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S36>/Weight'
                                        */
  real_T Weight_Value_nj;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S37>/Weight'
                                        */
  real_T Weight_Value_nt;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S38>/Weight'
                                        */
  real_T Weight_Value_lz;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S39>/Weight'
                                        */
  real_T Weight_Value_oa;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S41>/Weight'
                                        */
  real_T Weight_Value_dy;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S42>/Weight'
                                        */
  real_T Weight_Value_h5;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S43>/Weight'
                                        */
  real_T Weight_Value_jv;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S44>/Weight'
                                        */
  real_T Weight_Value_li;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S45>/Weight'
                                        */
  real_T Weight_Value_o2;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S46>/Weight'
                                        */
  real_T Weight_Value_ir;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S47>/Weight'
                                        */
  real_T Weight_Value_hj;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S48>/Weight'
                                        */
  real_T Weight_Value_pv;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S49>/Weight'
                                        */
  real_T Weight_Value_a1;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S50>/Weight'
                                        */
  real_T Weight_Value_liq;             /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S52>/Weight'
                                        */
  real_T Weight_Value_jy;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S53>/Weight'
                                        */
  real_T Weight_Value_dq;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S54>/Weight'
                                        */
  real_T Weight_Value_na;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S55>/Weight'
                                        */
  real_T Weight_Value_n5;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S56>/Weight'
                                        */
  real_T Weight_Value_mm;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S57>/Weight'
                                        */
  real_T Weight_Value_fx;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S58>/Weight'
                                        */
  real_T Weight_Value_in;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S59>/Weight'
                                        */
  real_T Weight_Value_c3;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S60>/Weight'
                                        */
  real_T Weight_Value_m1;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S61>/Weight'
                                        */
  real_T Weight_Value_b3;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S63>/Weight'
                                        */
  real_T Weight_Value_bd;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S64>/Weight'
                                        */
  real_T Weight_Value_jx;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S65>/Weight'
                                        */
  real_T Weight_Value_k4;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S66>/Weight'
                                        */
  real_T Weight_Value_kt;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S67>/Weight'
                                        */
  real_T Weight_Value_d5;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S68>/Weight'
                                        */
  real_T Weight_Value_ls;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S69>/Weight'
                                        */
  real_T Weight_Value_a0;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S70>/Weight'
                                        */
  real_T Weight_Value_pa;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S71>/Weight'
                                        */
  real_T Weight_Value_mc;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S72>/Weight'
                                        */
  real_T Weight_Value_d1;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S74>/Weight'
                                        */
  real_T Weight_Value_l2;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S75>/Weight'
                                        */
  real_T Weight_Value_hy;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S76>/Weight'
                                        */
  real_T Weight_Value_fb;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S77>/Weight'
                                        */
  real_T Weight_Value_em;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S78>/Weight'
                                        */
  real_T Weight_Value_dm;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S79>/Weight'
                                        */
  real_T Weight_Value_jm;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S80>/Weight'
                                        */
  real_T Weight_Value_do;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S81>/Weight'
                                        */
  real_T Weight_Value_oe;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S82>/Weight'
                                        */
  real_T Weight_Value_iu;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S83>/Weight'
                                        */
  real_T Weight_Value_fi;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S85>/Weight'
                                        */
  real_T Weight_Value_a0s;             /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S86>/Weight'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S4>/Zero'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T Gain5_Gain;                   /* Expression: 2
                                        * Referenced by: '<Root>/Gain5'
                                        */
  P_IfActionSubsystem2_BalanceF_T IfActionSubsystem2_h;/* '<S141>/If Action Subsystem2' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem3_f;/* '<S141>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceF_T IfActionSubsystem2_m;/* '<S140>/If Action Subsystem2' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem3_ck;/* '<S140>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceF_T IfActionSubsystem2_b;/* '<S139>/If Action Subsystem2' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem3_c;/* '<S139>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceF_T IfActionSubsystem2_k5;/* '<S126>/If Action Subsystem2' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem3_cx;/* '<S126>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceF_T IfActionSubsystem2_n;/* '<S125>/If Action Subsystem2' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem3_p;/* '<S125>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceF_T IfActionSubsystem2_i;/* '<S124>/If Action Subsystem2' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem3_n;/* '<S124>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceF_T IfActionSubsystem2_j;/* '<S111>/If Action Subsystem2' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem3_ni;/* '<S111>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceF_T IfActionSubsystem2_k;/* '<S110>/If Action Subsystem2' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem3_e;/* '<S110>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceF_T IfActionSubsystem2_a;/* '<S109>/If Action Subsystem2' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem3_b;/* '<S109>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceF_T IfActionSubsystem2_kv;/* '<S96>/If Action Subsystem2' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem3_h;/* '<S96>/If Action Subsystem3' */
  P_IfActionSubsystem3_BalanceF_T IfActionSubsystem3_i;/* '<S95>/If Action Subsystem3' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem1_iv;/* '<S95>/If Action Subsystem1' */
  P_IfActionSubsystem3_BalanceF_T IfActionSubsystem3;/* '<S94>/If Action Subsystem3' */
  P_IfActionSubsystem1_BalanceF_T IfActionSubsystem1;/* '<S94>/If Action Subsystem1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_BalanceFuzzy_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_BalanceFuzzy_T BalanceFuzzy_P;

/* Block signals (auto storage) */
extern B_BalanceFuzzy_T BalanceFuzzy_B;

/* Block states (auto storage) */
extern DW_BalanceFuzzy_T BalanceFuzzy_DW;

/* Model entry point functions */
extern void BalanceFuzzy_initialize(void);
extern void BalanceFuzzy_step(void);
extern void BalanceFuzzy_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BalanceFuzzy_T *const BalanceFuzzy_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'BalanceFuzzy'
 * '<S1>'   : 'BalanceFuzzy/Encoder'
 * '<S2>'   : 'BalanceFuzzy/Fuzzy Logic  Controller'
 * '<S3>'   : 'BalanceFuzzy/V_control'
 * '<S4>'   : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard'
 * '<S5>'   : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Defuzzification1'
 * '<S6>'   : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech'
 * '<S7>'   : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule1'
 * '<S8>'   : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule10'
 * '<S9>'   : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule11'
 * '<S10>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule12'
 * '<S11>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule13'
 * '<S12>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule14'
 * '<S13>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule15'
 * '<S14>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule16'
 * '<S15>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule17'
 * '<S16>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule18'
 * '<S17>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule19'
 * '<S18>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule2'
 * '<S19>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule20'
 * '<S20>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule21'
 * '<S21>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule22'
 * '<S22>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule23'
 * '<S23>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule24'
 * '<S24>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule25'
 * '<S25>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule26'
 * '<S26>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule27'
 * '<S27>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule28'
 * '<S28>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule29'
 * '<S29>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule3'
 * '<S30>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule30'
 * '<S31>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule31'
 * '<S32>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule32'
 * '<S33>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule33'
 * '<S34>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule34'
 * '<S35>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule35'
 * '<S36>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule36'
 * '<S37>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule37'
 * '<S38>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule38'
 * '<S39>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule39'
 * '<S40>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule4'
 * '<S41>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule40'
 * '<S42>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule41'
 * '<S43>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule42'
 * '<S44>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule43'
 * '<S45>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule44'
 * '<S46>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule45'
 * '<S47>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule46'
 * '<S48>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule47'
 * '<S49>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule48'
 * '<S50>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule49'
 * '<S51>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule5'
 * '<S52>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule50'
 * '<S53>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule51'
 * '<S54>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule52'
 * '<S55>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule53'
 * '<S56>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule54'
 * '<S57>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule55'
 * '<S58>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule56'
 * '<S59>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule57'
 * '<S60>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule58'
 * '<S61>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule59'
 * '<S62>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule6'
 * '<S63>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule60'
 * '<S64>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule61'
 * '<S65>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule62'
 * '<S66>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule63'
 * '<S67>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule64'
 * '<S68>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule65'
 * '<S69>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule66'
 * '<S70>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule67'
 * '<S71>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule68'
 * '<S72>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule69'
 * '<S73>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule7'
 * '<S74>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule70'
 * '<S75>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule71'
 * '<S76>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule72'
 * '<S77>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule73'
 * '<S78>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule74'
 * '<S79>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule75'
 * '<S80>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule76'
 * '<S81>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule77'
 * '<S82>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule78'
 * '<S83>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule79'
 * '<S84>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule8'
 * '<S85>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule80'
 * '<S86>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule81'
 * '<S87>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Rule9'
 * '<S88>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/output1'
 * '<S89>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay'
 * '<S90>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc'
 * '<S91>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay'
 * '<S92>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Defuzzification1/Action: One'
 * '<S93>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Defuzzification1/Action: u1'
 * '<S94>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/NE'
 * '<S95>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/PO'
 * '<S96>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/ZE'
 * '<S97>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/NE/If Action Subsystem'
 * '<S98>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/NE/If Action Subsystem1'
 * '<S99>'  : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/NE/If Action Subsystem2'
 * '<S100>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/NE/If Action Subsystem3'
 * '<S101>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/PO/If Action Subsystem'
 * '<S102>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/PO/If Action Subsystem1'
 * '<S103>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/PO/If Action Subsystem2'
 * '<S104>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/PO/If Action Subsystem3'
 * '<S105>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/ZE/If Action Subsystem'
 * '<S106>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/ZE/If Action Subsystem1'
 * '<S107>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/ZE/If Action Subsystem2'
 * '<S108>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/Goclech/ZE/If Action Subsystem3'
 * '<S109>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/NE'
 * '<S110>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/PO'
 * '<S111>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/ZE'
 * '<S112>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/NE/If Action Subsystem'
 * '<S113>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/NE/If Action Subsystem1'
 * '<S114>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/NE/If Action Subsystem2'
 * '<S115>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/NE/If Action Subsystem3'
 * '<S116>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/PO/If Action Subsystem'
 * '<S117>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/PO/If Action Subsystem1'
 * '<S118>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/PO/If Action Subsystem2'
 * '<S119>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/PO/If Action Subsystem3'
 * '<S120>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/ZE/If Action Subsystem'
 * '<S121>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/ZE/If Action Subsystem1'
 * '<S122>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/ZE/If Action Subsystem2'
 * '<S123>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantoccanhtay/ZE/If Action Subsystem3'
 * '<S124>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/NE'
 * '<S125>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/PO'
 * '<S126>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/ZE'
 * '<S127>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/NE/If Action Subsystem'
 * '<S128>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/NE/If Action Subsystem1'
 * '<S129>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/NE/If Action Subsystem2'
 * '<S130>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/NE/If Action Subsystem3'
 * '<S131>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/PO/If Action Subsystem'
 * '<S132>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/PO/If Action Subsystem1'
 * '<S133>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/PO/If Action Subsystem2'
 * '<S134>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/PO/If Action Subsystem3'
 * '<S135>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/ZE/If Action Subsystem'
 * '<S136>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/ZE/If Action Subsystem1'
 * '<S137>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/ZE/If Action Subsystem2'
 * '<S138>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vantocgoc/ZE/If Action Subsystem3'
 * '<S139>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/NE'
 * '<S140>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/PO'
 * '<S141>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/ZE'
 * '<S142>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/NE/If Action Subsystem'
 * '<S143>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/NE/If Action Subsystem1'
 * '<S144>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/NE/If Action Subsystem2'
 * '<S145>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/NE/If Action Subsystem3'
 * '<S146>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/PO/If Action Subsystem'
 * '<S147>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/PO/If Action Subsystem1'
 * '<S148>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/PO/If Action Subsystem2'
 * '<S149>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/PO/If Action Subsystem3'
 * '<S150>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/ZE/If Action Subsystem'
 * '<S151>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/ZE/If Action Subsystem1'
 * '<S152>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/ZE/If Action Subsystem2'
 * '<S153>' : 'BalanceFuzzy/Fuzzy Logic  Controller/FIS Wizard/vitricanhtay/ZE/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_BalanceFuzzy_h_ */

/* [EOF] */
