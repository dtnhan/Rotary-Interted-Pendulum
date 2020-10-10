/*
 * File: BalanceMultiNew.h
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model BalanceMultiNew.
 *
 * Model version                        : 1.9
 * Real-Time Workshop file version      : 8.4 (R2013a) 13-Feb-2013
 * Real-Time Workshop file generated on : Tue Jan 07 09:21:01 2014
 * TLC version                          : 8.4 (Jan 19 2013)
 * C/C++ source code generated on       : Tue Jan 07 09:21:14 2014
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BalanceMultiNew_h_
#define RTW_HEADER_BalanceMultiNew_h_
#ifndef BalanceMultiNew_COMMON_INCLUDES_
# define BalanceMultiNew_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "waijung_hwdrvlib.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* BalanceMultiNew_COMMON_INCLUDES_ */

#include "BalanceMultiNew_types.h"

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
  real_T x;                            /* '<Root>/MATLAB Function' */
  real_T y;                            /* '<Root>/MATLAB Function' */
  real32_T UARTRx1_o2;                 /* '<Root>/UART Rx1' */
  real32_T DataTypeConversion;         /* '<S1>/Data Type Conversion' */
  real32_T DataTypeConversion1;        /* '<S1>/Data Type Conversion1' */
  real32_T DataTypeConversion2;        /* '<S1>/Data Type Conversion2' */
  real32_T DataTypeConversion3;        /* '<S1>/Data Type Conversion3' */
  real32_T DataTypeConversion4;        /* '<S1>/Data Type Conversion4' */
  real32_T DataTypeConversion5;        /* '<S1>/Data Type Conversion5' */
  int32_T UARTRx_o2;                   /* '<Root>/UART Rx' */
  int32_T UARTRx3_o2;                  /* '<Root>/UART Rx3' */
  int32_T QuadraturEncoder_o1;         /* '<S3>/Quadratur Encoder' */
  int32_T QuadraturEncoder_o2;         /* '<S3>/Quadratur Encoder' */
  int32_T UARTRx2_o2;                  /* '<Root>/UART Rx2' */
  uint8_T UARTRx_o1;                   /* '<Root>/UART Rx' */
  uint8_T UARTRx3_o1;                  /* '<Root>/UART Rx3' */
  uint8_T UARTRx2_o1;                  /* '<Root>/UART Rx2' */
  uint8_T UARTRx1_o1;                  /* '<Root>/UART Rx1' */
  boolean_T DigitalInput;              /* '<S3>/Digital Input' */
} B_BalanceMultiNew_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S3>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S3>/Unit Delay' */
  boolean_T UARTSend_MODE;             /* '<Root>/UART Send' */
} DW_BalanceMultiNew_T;

/* Parameters for system: '<S27>/If Action Subsystem3' */
struct P_IfActionSubsystem3_BalanceM_T_ {
  real_T a_Value;                      /* Expression: a
                                        * Referenced by: '<S35>/a'
                                        */
  real_T b_Value;                      /* Expression: b
                                        * Referenced by: '<S35>/b'
                                        */
};

/* Parameters for system: '<S27>/If Action Subsystem2' */
struct P_IfActionSubsystem2_BalanceM_T_ {
  real_T b_Value;                      /* Expression: b
                                        * Referenced by: '<S34>/b'
                                        */
  real_T c_Value;                      /* Expression: c
                                        * Referenced by: '<S34>/c'
                                        */
};

/* Parameters (auto storage) */
struct P_BalanceMultiNew_T_ {
  real_T Saturation_UpperSat;          /* Expression: 23
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -23
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T MidRange_Value;               /* Expression: mean(cat(1,fis.output.range),2)
                                        * Referenced by: '<S16>/MidRange'
                                        */
  real_T xdata_Value[101];             /* Expression: Xdata
                                        * Referenced by: '<S17>/x data'
                                        */
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S25>/Out1'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S25>/One'
                                        */
  real_T Out1_Y0_n;                    /* Expression: 0
                                        * Referenced by: '<S32>/Out1'
                                        */
  real_T _Value;                       /* Expression: 0
                                        * Referenced by: '<S32>/0'
                                        */
  real_T Out1_Y0_l;                    /* Expression: 1
                                        * Referenced by: '<S33>/Out1'
                                        */
  real_T _Value_e;                     /* Expression: 1
                                        * Referenced by: '<S33>/0'
                                        */
  real_T Out1_Y0_p;                    /* Expression: 0
                                        * Referenced by: '<S36>/Out1'
                                        */
  real_T _Value_h;                     /* Expression: 0
                                        * Referenced by: '<S36>/0'
                                        */
  real_T Out1_Y0_e;                    /* Expression: 1
                                        * Referenced by: '<S37>/Out1'
                                        */
  real_T _Value_p;                     /* Expression: 1
                                        * Referenced by: '<S37>/0'
                                        */
  real_T Out1_Y0_m;                    /* Expression: 0
                                        * Referenced by: '<S40>/Out1'
                                        */
  real_T _Value_d;                     /* Expression: 0
                                        * Referenced by: '<S40>/0'
                                        */
  real_T Out1_Y0_k;                    /* Expression: 1
                                        * Referenced by: '<S41>/Out1'
                                        */
  real_T _Value_dj;                    /* Expression: 1
                                        * Referenced by: '<S41>/0'
                                        */
  real_T Out1_Y0_f;                    /* Expression: 0
                                        * Referenced by: '<S44>/Out1'
                                        */
  real_T _Value_g;                     /* Expression: 0
                                        * Referenced by: '<S44>/0'
                                        */
  real_T Out1_Y0_h;                    /* Expression: 1
                                        * Referenced by: '<S45>/Out1'
                                        */
  real_T _Value_f;                     /* Expression: 1
                                        * Referenced by: '<S45>/0'
                                        */
  real_T Out1_Y0_g;                    /* Expression: 0
                                        * Referenced by: '<S48>/Out1'
                                        */
  real_T _Value_l;                     /* Expression: 0
                                        * Referenced by: '<S48>/0'
                                        */
  real_T Out1_Y0_a;                    /* Expression: 1
                                        * Referenced by: '<S49>/Out1'
                                        */
  real_T _Value_b;                     /* Expression: 1
                                        * Referenced by: '<S49>/0'
                                        */
  real_T MidRange_Value_h;             /* Expression: mean(cat(1,fis.output.range),2)
                                        * Referenced by: '<S52>/MidRange'
                                        */
  real_T PBConstant_Value;             /* Expression: fis.output(1).mf(7).params(1)
                                        * Referenced by: '<S136>/PB(Constant)'
                                        */
  real_T PMConstant_Value;             /* Expression: fis.output(1).mf(6).params(1)
                                        * Referenced by: '<S136>/PM(Constant)'
                                        */
  real_T PSConstant_Value;             /* Expression: fis.output(1).mf(5).params(1)
                                        * Referenced by: '<S136>/PS(Constant)'
                                        */
  real_T ZEConstant_Value;             /* Expression: fis.output(1).mf(4).params(1)
                                        * Referenced by: '<S136>/ZE(Constant)'
                                        */
  real_T NSConstant_Value;             /* Expression: fis.output(1).mf(3).params(1)
                                        * Referenced by: '<S136>/NS(Constant)'
                                        */
  real_T NMConstant_Value;             /* Expression: fis.output(1).mf(2).params(1)
                                        * Referenced by: '<S136>/NM(Constant)'
                                        */
  real_T NBConstant_Value;             /* Expression: fis.output(1).mf(1).params(1)
                                        * Referenced by: '<S136>/NB(Constant)'
                                        */
  real_T Out1_Y0_i;                    /* Expression: 0
                                        * Referenced by: '<S140>/Out1'
                                        */
  real_T One_Value_c;                  /* Expression: 1
                                        * Referenced by: '<S140>/One'
                                        */
  real_T Out1_Y0_ng;                   /* Expression: 0
                                        * Referenced by: '<S145>/Out1'
                                        */
  real_T _Value_a;                     /* Expression: 0
                                        * Referenced by: '<S145>/0'
                                        */
  real_T Out1_Y0_gr;                   /* Expression: 1
                                        * Referenced by: '<S146>/Out1'
                                        */
  real_T _Value_j;                     /* Expression: 1
                                        * Referenced by: '<S146>/0'
                                        */
  real_T Out1_Y0_c;                    /* Expression: 0
                                        * Referenced by: '<S149>/Out1'
                                        */
  real_T _Value_lt;                    /* Expression: 0
                                        * Referenced by: '<S149>/0'
                                        */
  real_T Out1_Y0_ed;                   /* Expression: 1
                                        * Referenced by: '<S150>/Out1'
                                        */
  real_T _Value_gn;                    /* Expression: 1
                                        * Referenced by: '<S150>/0'
                                        */
  real_T Out1_Y0_b;                    /* Expression: 0
                                        * Referenced by: '<S153>/Out1'
                                        */
  real_T _Value_k;                     /* Expression: 0
                                        * Referenced by: '<S153>/0'
                                        */
  real_T Out1_Y0_lf;                   /* Expression: 1
                                        * Referenced by: '<S154>/Out1'
                                        */
  real_T _Value_ka;                    /* Expression: 1
                                        * Referenced by: '<S154>/0'
                                        */
  real_T Out1_Y0_gw;                   /* Expression: 0
                                        * Referenced by: '<S160>/Out1'
                                        */
  real_T _Value_hk;                    /* Expression: 0
                                        * Referenced by: '<S160>/0'
                                        */
  real_T Out1_Y0_pp;                   /* Expression: 1
                                        * Referenced by: '<S161>/Out1'
                                        */
  real_T _Value_ez;                    /* Expression: 1
                                        * Referenced by: '<S161>/0'
                                        */
  real_T Out1_Y0_lq;                   /* Expression: 0
                                        * Referenced by: '<S164>/Out1'
                                        */
  real_T _Value_lz;                    /* Expression: 0
                                        * Referenced by: '<S164>/0'
                                        */
  real_T Out1_Y0_hu;                   /* Expression: 1
                                        * Referenced by: '<S165>/Out1'
                                        */
  real_T _Value_l3;                    /* Expression: 1
                                        * Referenced by: '<S165>/0'
                                        */
  real_T Out1_Y0_m5;                   /* Expression: 0
                                        * Referenced by: '<S168>/Out1'
                                        */
  real_T _Value_c;                     /* Expression: 0
                                        * Referenced by: '<S168>/0'
                                        */
  real_T Out1_Y0_j;                    /* Expression: 1
                                        * Referenced by: '<S169>/Out1'
                                        */
  real_T _Value_bi;                    /* Expression: 1
                                        * Referenced by: '<S169>/0'
                                        */
  real_T Out1_Y0_lft;                  /* Expression: 0
                                        * Referenced by: '<S175>/Out1'
                                        */
  real_T _Value_n;                     /* Expression: 0
                                        * Referenced by: '<S175>/0'
                                        */
  real_T Out1_Y0_ls;                   /* Expression: 1
                                        * Referenced by: '<S176>/Out1'
                                        */
  real_T _Value_cn;                    /* Expression: 1
                                        * Referenced by: '<S176>/0'
                                        */
  real_T Out1_Y0_n1;                   /* Expression: 0
                                        * Referenced by: '<S179>/Out1'
                                        */
  real_T _Value_fc;                    /* Expression: 0
                                        * Referenced by: '<S179>/0'
                                        */
  real_T Out1_Y0_lh;                   /* Expression: 1
                                        * Referenced by: '<S180>/Out1'
                                        */
  real_T _Value_c3;                    /* Expression: 1
                                        * Referenced by: '<S180>/0'
                                        */
  real_T Out1_Y0_j3;                   /* Expression: 0
                                        * Referenced by: '<S183>/Out1'
                                        */
  real_T _Value_o;                     /* Expression: 0
                                        * Referenced by: '<S183>/0'
                                        */
  real_T Out1_Y0_ih;                   /* Expression: 1
                                        * Referenced by: '<S184>/Out1'
                                        */
  real_T _Value_df;                    /* Expression: 1
                                        * Referenced by: '<S184>/0'
                                        */
  real_T Out1_Y0_fa;                   /* Expression: 0
                                        * Referenced by: '<S190>/Out1'
                                        */
  real_T _Value_i;                     /* Expression: 0
                                        * Referenced by: '<S190>/0'
                                        */
  real_T Out1_Y0_a2;                   /* Expression: 1
                                        * Referenced by: '<S191>/Out1'
                                        */
  real_T _Value_ac;                    /* Expression: 1
                                        * Referenced by: '<S191>/0'
                                        */
  real_T Out1_Y0_kp;                   /* Expression: 0
                                        * Referenced by: '<S194>/Out1'
                                        */
  real_T _Value_dv;                    /* Expression: 0
                                        * Referenced by: '<S194>/0'
                                        */
  real_T Out1_Y0_jr;                   /* Expression: 1
                                        * Referenced by: '<S195>/Out1'
                                        */
  real_T _Value_is;                    /* Expression: 1
                                        * Referenced by: '<S195>/0'
                                        */
  real_T Out1_Y0_o;                    /* Expression: 0
                                        * Referenced by: '<S198>/Out1'
                                        */
  real_T _Value_nm;                    /* Expression: 0
                                        * Referenced by: '<S198>/0'
                                        */
  real_T Out1_Y0_b4;                   /* Expression: 1
                                        * Referenced by: '<S199>/Out1'
                                        */
  real_T _Value_os;                    /* Expression: 1
                                        * Referenced by: '<S199>/0'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T LQRController_Gain[4];        /* Expression: [-160.8 -22.234  3.324 12.052]
                                        * Referenced by: '<S5>/LQR Controller'
                                        */
  real_T Weight_Value;                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S18>/Weight'
                                        */
  real_T LQRController1_Gain;          /* Expression: 2
                                        * Referenced by: '<S5>/LQR Controller1'
                                        */
  real_T LQRController2_Gain;          /* Expression: 0.2765
                                        * Referenced by: '<S5>/LQR Controller2'
                                        */
  real_T LQRController3_Gain;          /* Expression: -0.29
                                        * Referenced by: '<S5>/LQR Controller3'
                                        */
  real_T LQRController4_Gain;          /* Expression: -0.15
                                        * Referenced by: '<S5>/LQR Controller4'
                                        */
  real_T mf1_Value[101];               /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(1).params)
                                        * Referenced by: '<S24>/mf1'
                                        */
  real_T Weight_Value_c;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S19>/Weight'
                                        */
  real_T mf2_Value[101];               /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(2).params)
                                        * Referenced by: '<S24>/mf2'
                                        */
  real_T Weight_Value_h;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S20>/Weight'
                                        */
  real_T mf3_Value[101];               /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(3).params)
                                        * Referenced by: '<S24>/mf3'
                                        */
  real_T Weight_Value_cs;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S21>/Weight'
                                        */
  real_T mf4_Value[101];               /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(4).params)
                                        * Referenced by: '<S24>/mf4'
                                        */
  real_T Weight_Value_g;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S22>/Weight'
                                        */
  real_T mf5_Value[101];               /* Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(5).params)
                                        * Referenced by: '<S24>/mf5'
                                        */
  real_T Zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S16>/Zero'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<S16>/Switch'
                                        */
  real_T FuzzyGain_Gain;               /* Expression: -90
                                        * Referenced by: '<S5>/FuzzyGain'
                                        */
  real_T Weight_Value_j;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S55>/Weight'
                                        */
  real_T Weight_Value_b;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S66>/Weight'
                                        */
  real_T Weight_Value_m;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S77>/Weight'
                                        */
  real_T Weight_Value_mv;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S88>/Weight'
                                        */
  real_T Weight_Value_i;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S99>/Weight'
                                        */
  real_T Weight_Value_p;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S110>/Weight'
                                        */
  real_T Weight_Value_o;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S121>/Weight'
                                        */
  real_T Weight_Value_jo;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S132>/Weight'
                                        */
  real_T Weight_Value_l;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S135>/Weight'
                                        */
  real_T Weight_Value_pg;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S56>/Weight'
                                        */
  real_T Weight_Value_a;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S57>/Weight'
                                        */
  real_T Weight_Value_jj;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S58>/Weight'
                                        */
  real_T Weight_Value_ld;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S59>/Weight'
                                        */
  real_T Weight_Value_pw;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S60>/Weight'
                                        */
  real_T Weight_Value_il;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S61>/Weight'
                                        */
  real_T Weight_Value_ja;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S62>/Weight'
                                        */
  real_T Weight_Value_n;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S63>/Weight'
                                        */
  real_T Weight_Value_jom;             /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S64>/Weight'
                                        */
  real_T Weight_Value_nj;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S65>/Weight'
                                        */
  real_T Weight_Value_f;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S67>/Weight'
                                        */
  real_T Weight_Value_e;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S68>/Weight'
                                        */
  real_T Weight_Value_jd;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S69>/Weight'
                                        */
  real_T Weight_Value_bs;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S70>/Weight'
                                        */
  real_T Weight_Value_al;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S71>/Weight'
                                        */
  real_T Weight_Value_ce;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S72>/Weight'
                                        */
  real_T Weight_Value_ay;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S73>/Weight'
                                        */
  real_T Weight_Value_hi;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S74>/Weight'
                                        */
  real_T Weight_Value_d;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S75>/Weight'
                                        */
  real_T Weight_Value_py;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S76>/Weight'
                                        */
  real_T Weight_Value_hh;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S78>/Weight'
                                        */
  real_T Weight_Value_hc;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S79>/Weight'
                                        */
  real_T Weight_Value_ni;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S80>/Weight'
                                        */
  real_T Weight_Value_ia;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S81>/Weight'
                                        */
  real_T Weight_Value_bk;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S82>/Weight'
                                        */
  real_T Weight_Value_j5;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S83>/Weight'
                                        */
  real_T Weight_Value_oe;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S84>/Weight'
                                        */
  real_T Weight_Value_hht;             /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S85>/Weight'
                                        */
  real_T Weight_Value_h2;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S86>/Weight'
                                        */
  real_T Weight_Value_ih;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S87>/Weight'
                                        */
  real_T Weight_Value_cr;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S89>/Weight'
                                        */
  real_T Weight_Value_as;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S90>/Weight'
                                        */
  real_T Weight_Value_jb;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S91>/Weight'
                                        */
  real_T Weight_Value_ps;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S92>/Weight'
                                        */
  real_T Weight_Value_m0;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S93>/Weight'
                                        */
  real_T Weight_Value_k;               /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S94>/Weight'
                                        */
  real_T Weight_Value_px;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S95>/Weight'
                                        */
  real_T Weight_Value_ge;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S96>/Weight'
                                        */
  real_T Weight_Value_ew;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S97>/Weight'
                                        */
  real_T Weight_Value_dx;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S98>/Weight'
                                        */
  real_T Weight_Value_fd;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S100>/Weight'
                                        */
  real_T Weight_Value_nb;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S101>/Weight'
                                        */
  real_T Weight_Value_ft;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S102>/Weight'
                                        */
  real_T Weight_Value_ca;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S103>/Weight'
                                        */
  real_T Weight_Value_ae;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S104>/Weight'
                                        */
  real_T Weight_Value_jr;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S105>/Weight'
                                        */
  real_T Weight_Value_lc;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S106>/Weight'
                                        */
  real_T Weight_Value_j0;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S107>/Weight'
                                        */
  real_T Weight_Value_ju;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S108>/Weight'
                                        */
  real_T Weight_Value_bu;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S109>/Weight'
                                        */
  real_T Weight_Value_b2;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S111>/Weight'
                                        */
  real_T Weight_Value_mp;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S112>/Weight'
                                        */
  real_T Weight_Value_ag;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S113>/Weight'
                                        */
  real_T Weight_Value_gb;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S114>/Weight'
                                        */
  real_T Weight_Value_oo;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S115>/Weight'
                                        */
  real_T Weight_Value_eg;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S116>/Weight'
                                        */
  real_T Weight_Value_gf;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S117>/Weight'
                                        */
  real_T Weight_Value_gu;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S118>/Weight'
                                        */
  real_T Weight_Value_ng;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S119>/Weight'
                                        */
  real_T Weight_Value_js;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S120>/Weight'
                                        */
  real_T Weight_Value_o5;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S122>/Weight'
                                        */
  real_T Weight_Value_pz;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S123>/Weight'
                                        */
  real_T Weight_Value_pr;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S124>/Weight'
                                        */
  real_T Weight_Value_dr;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S125>/Weight'
                                        */
  real_T Weight_Value_hr;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S126>/Weight'
                                        */
  real_T Weight_Value_pu;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S127>/Weight'
                                        */
  real_T Weight_Value_dk;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S128>/Weight'
                                        */
  real_T Weight_Value_jz;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S129>/Weight'
                                        */
  real_T Weight_Value_a5;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S130>/Weight'
                                        */
  real_T Weight_Value_hf;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S131>/Weight'
                                        */
  real_T Weight_Value_jw;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S133>/Weight'
                                        */
  real_T Weight_Value_m4;              /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S134>/Weight'
                                        */
  real_T Zero_Value_e;                 /* Expression: 0
                                        * Referenced by: '<S52>/Zero'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 1
                                        * Referenced by: '<S52>/Switch'
                                        */
  real_T FuzzyGain1_Gain;              /* Expression: -90
                                        * Referenced by: '<S5>/FuzzyGain1'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 1
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<Root>/Switch1'
                                        */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_cc;/* '<S189>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_pe;/* '<S189>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_ji;/* '<S188>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_o;/* '<S188>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_l;/* '<S187>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_p;/* '<S187>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_e;/* '<S174>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_h;/* '<S174>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_k;/* '<S173>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_dn;/* '<S173>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_j;/* '<S172>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_e;/* '<S172>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_g;/* '<S159>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_gn;/* '<S159>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_m;/* '<S158>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_o1;/* '<S158>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_oi;/* '<S157>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_dr;/* '<S157>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_mo;/* '<S144>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_n;/* '<S144>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_ov;/* '<S143>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_hm;/* '<S143>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_pn;/* '<S142>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_f;/* '<S142>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_c;/* '<S31>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_b;/* '<S31>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_p;/* '<S30>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_g;/* '<S30>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_h;/* '<S29>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_i;/* '<S29>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2_o;/* '<S28>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3_d;/* '<S28>/If Action Subsystem3' */
  P_IfActionSubsystem2_BalanceM_T IfActionSubsystem2;/* '<S27>/If Action Subsystem2' */
  P_IfActionSubsystem3_BalanceM_T IfActionSubsystem3;/* '<S27>/If Action Subsystem3' */
};

/* Real-time Model Data Structure */
struct tag_RTM_BalanceMultiNew_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_BalanceMultiNew_T BalanceMultiNew_P;

/* Block signals (auto storage) */
extern B_BalanceMultiNew_T BalanceMultiNew_B;

/* Block states (auto storage) */
extern DW_BalanceMultiNew_T BalanceMultiNew_DW;

/* Model entry point functions */
extern void BalanceMultiNew_initialize(void);
extern void BalanceMultiNew_step(void);
extern void BalanceMultiNew_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BalanceMultiNew_T *const BalanceMultiNew_M;

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
 * '<Root>' : 'BalanceMultiNew'
 * '<S1>'   : 'BalanceMultiNew/Convert'
 * '<S2>'   : 'BalanceMultiNew/Enabled Subsystem'
 * '<S3>'   : 'BalanceMultiNew/Encoders'
 * '<S4>'   : 'BalanceMultiNew/MATLAB Function'
 * '<S5>'   : 'BalanceMultiNew/Multi_Controllers'
 * '<S6>'   : 'BalanceMultiNew/Subsystem'
 * '<S7>'   : 'BalanceMultiNew/Switch_Funciton'
 * '<S8>'   : 'BalanceMultiNew/UART Send'
 * '<S9>'   : 'BalanceMultiNew/V_control'
 * '<S10>'  : 'BalanceMultiNew/Encoders/MATLAB Function'
 * '<S11>'  : 'BalanceMultiNew/Encoders/MATLAB Function1'
 * '<S12>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller'
 * '<S13>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1'
 * '<S14>'  : 'BalanceMultiNew/Multi_Controllers/MATLAB Function'
 * '<S15>'  : 'BalanceMultiNew/Multi_Controllers/MATLAB Function1'
 * '<S16>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard'
 * '<S17>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/Defuzzification1'
 * '<S18>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/Rule1'
 * '<S19>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/Rule2'
 * '<S20>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/Rule3'
 * '<S21>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/Rule4'
 * '<S22>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/Rule5'
 * '<S23>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1'
 * '<S24>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/output1'
 * '<S25>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/Defuzzification1/Action: One'
 * '<S26>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/Defuzzification1/Action: u1'
 * '<S27>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf1'
 * '<S28>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf2'
 * '<S29>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf3'
 * '<S30>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf4'
 * '<S31>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf5'
 * '<S32>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf1/If Action Subsystem'
 * '<S33>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf1/If Action Subsystem1'
 * '<S34>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf1/If Action Subsystem2'
 * '<S35>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf1/If Action Subsystem3'
 * '<S36>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf2/If Action Subsystem'
 * '<S37>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf2/If Action Subsystem1'
 * '<S38>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf2/If Action Subsystem2'
 * '<S39>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf2/If Action Subsystem3'
 * '<S40>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf3/If Action Subsystem'
 * '<S41>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf3/If Action Subsystem1'
 * '<S42>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf3/If Action Subsystem2'
 * '<S43>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf3/If Action Subsystem3'
 * '<S44>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf4/If Action Subsystem'
 * '<S45>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf4/If Action Subsystem1'
 * '<S46>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf4/If Action Subsystem2'
 * '<S47>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf4/If Action Subsystem3'
 * '<S48>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf5/If Action Subsystem'
 * '<S49>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf5/If Action Subsystem1'
 * '<S50>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf5/If Action Subsystem2'
 * '<S51>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller/FIS Wizard/input1/mf5/If Action Subsystem3'
 * '<S52>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard'
 * '<S53>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Defuzzification1'
 * '<S54>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech'
 * '<S55>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule1'
 * '<S56>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule10'
 * '<S57>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule11'
 * '<S58>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule12'
 * '<S59>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule13'
 * '<S60>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule14'
 * '<S61>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule15'
 * '<S62>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule16'
 * '<S63>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule17'
 * '<S64>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule18'
 * '<S65>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule19'
 * '<S66>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule2'
 * '<S67>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule20'
 * '<S68>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule21'
 * '<S69>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule22'
 * '<S70>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule23'
 * '<S71>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule24'
 * '<S72>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule25'
 * '<S73>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule26'
 * '<S74>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule27'
 * '<S75>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule28'
 * '<S76>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule29'
 * '<S77>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule3'
 * '<S78>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule30'
 * '<S79>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule31'
 * '<S80>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule32'
 * '<S81>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule33'
 * '<S82>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule34'
 * '<S83>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule35'
 * '<S84>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule36'
 * '<S85>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule37'
 * '<S86>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule38'
 * '<S87>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule39'
 * '<S88>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule4'
 * '<S89>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule40'
 * '<S90>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule41'
 * '<S91>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule42'
 * '<S92>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule43'
 * '<S93>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule44'
 * '<S94>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule45'
 * '<S95>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule46'
 * '<S96>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule47'
 * '<S97>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule48'
 * '<S98>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule49'
 * '<S99>'  : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule5'
 * '<S100>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule50'
 * '<S101>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule51'
 * '<S102>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule52'
 * '<S103>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule53'
 * '<S104>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule54'
 * '<S105>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule55'
 * '<S106>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule56'
 * '<S107>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule57'
 * '<S108>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule58'
 * '<S109>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule59'
 * '<S110>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule6'
 * '<S111>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule60'
 * '<S112>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule61'
 * '<S113>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule62'
 * '<S114>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule63'
 * '<S115>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule64'
 * '<S116>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule65'
 * '<S117>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule66'
 * '<S118>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule67'
 * '<S119>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule68'
 * '<S120>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule69'
 * '<S121>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule7'
 * '<S122>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule70'
 * '<S123>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule71'
 * '<S124>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule72'
 * '<S125>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule73'
 * '<S126>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule74'
 * '<S127>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule75'
 * '<S128>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule76'
 * '<S129>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule77'
 * '<S130>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule78'
 * '<S131>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule79'
 * '<S132>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule8'
 * '<S133>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule80'
 * '<S134>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule81'
 * '<S135>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Rule9'
 * '<S136>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/output1'
 * '<S137>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc'
 * '<S138>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe'
 * '<S139>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe'
 * '<S140>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Defuzzification1/Action: One'
 * '<S141>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Defuzzification1/Action: u1'
 * '<S142>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/NE'
 * '<S143>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/PO'
 * '<S144>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/ZE'
 * '<S145>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/NE/If Action Subsystem'
 * '<S146>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/NE/If Action Subsystem1'
 * '<S147>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/NE/If Action Subsystem2'
 * '<S148>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/NE/If Action Subsystem3'
 * '<S149>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/PO/If Action Subsystem'
 * '<S150>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/PO/If Action Subsystem1'
 * '<S151>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/PO/If Action Subsystem2'
 * '<S152>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/PO/If Action Subsystem3'
 * '<S153>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/ZE/If Action Subsystem'
 * '<S154>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/ZE/If Action Subsystem1'
 * '<S155>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/ZE/If Action Subsystem2'
 * '<S156>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/Goclech/ZE/If Action Subsystem3'
 * '<S157>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/NE'
 * '<S158>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/PO'
 * '<S159>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/ZE'
 * '<S160>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/NE/If Action Subsystem'
 * '<S161>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/NE/If Action Subsystem1'
 * '<S162>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/NE/If Action Subsystem2'
 * '<S163>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/NE/If Action Subsystem3'
 * '<S164>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/PO/If Action Subsystem'
 * '<S165>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/PO/If Action Subsystem1'
 * '<S166>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/PO/If Action Subsystem2'
 * '<S167>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/PO/If Action Subsystem3'
 * '<S168>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/ZE/If Action Subsystem'
 * '<S169>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/ZE/If Action Subsystem1'
 * '<S170>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/ZE/If Action Subsystem2'
 * '<S171>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocgoc/ZE/If Action Subsystem3'
 * '<S172>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/NE'
 * '<S173>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/PO'
 * '<S174>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/ZE'
 * '<S175>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/NE/If Action Subsystem'
 * '<S176>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/NE/If Action Subsystem1'
 * '<S177>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/NE/If Action Subsystem2'
 * '<S178>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/NE/If Action Subsystem3'
 * '<S179>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/PO/If Action Subsystem'
 * '<S180>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/PO/If Action Subsystem1'
 * '<S181>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/PO/If Action Subsystem2'
 * '<S182>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/PO/If Action Subsystem3'
 * '<S183>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/ZE/If Action Subsystem'
 * '<S184>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/ZE/If Action Subsystem1'
 * '<S185>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/ZE/If Action Subsystem2'
 * '<S186>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vantocxe/ZE/If Action Subsystem3'
 * '<S187>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/NE'
 * '<S188>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/PO'
 * '<S189>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/ZE'
 * '<S190>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/NE/If Action Subsystem'
 * '<S191>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/NE/If Action Subsystem1'
 * '<S192>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/NE/If Action Subsystem2'
 * '<S193>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/NE/If Action Subsystem3'
 * '<S194>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/PO/If Action Subsystem'
 * '<S195>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/PO/If Action Subsystem1'
 * '<S196>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/PO/If Action Subsystem2'
 * '<S197>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/PO/If Action Subsystem3'
 * '<S198>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/ZE/If Action Subsystem'
 * '<S199>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/ZE/If Action Subsystem1'
 * '<S200>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/ZE/If Action Subsystem2'
 * '<S201>' : 'BalanceMultiNew/Multi_Controllers/Fuzzy Logic  Controller1/FIS Wizard/vitrixe/ZE/If Action Subsystem3'
 * '<S202>' : 'BalanceMultiNew/Subsystem/Choose_Swing'
 * '<S203>' : 'BalanceMultiNew/Subsystem/EnergySWINGUP'
 * '<S204>' : 'BalanceMultiNew/Subsystem/EnergySWINGUP1'
 * '<S205>' : 'BalanceMultiNew/Subsystem/SWINGUP'
 */
#endif                                 /* RTW_HEADER_BalanceMultiNew_h_ */

/* [EOF] */
