/*
 * File: BalanceFuzzy_data.c
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
#include "BalanceFuzzy.h"
#include "BalanceFuzzy_private.h"

/* Block parameters (auto storage) */
P_BalanceFuzzy_T BalanceFuzzy_P = {
  0.5,                                 /* Expression: mean(cat(1,fis.output.range),2)
                                        * Referenced by: '<S4>/MidRange'
                                        */
  -20.0,                               /* Expression: fis.output(1).mf(1).params(1)
                                        * Referenced by: '<S88>/NB(Constant)'
                                        */
  -14.0,                               /* Expression: fis.output(1).mf(2).params(1)
                                        * Referenced by: '<S88>/NM(Constant)'
                                        */
  -5.0,                                /* Expression: fis.output(1).mf(3).params(1)
                                        * Referenced by: '<S88>/NS(Constant)'
                                        */
  0.0,                                 /* Expression: fis.output(1).mf(4).params(1)
                                        * Referenced by: '<S88>/ZE(Constant)'
                                        */
  5.0,                                 /* Expression: fis.output(1).mf(5).params(1)
                                        * Referenced by: '<S88>/PS(Constant)'
                                        */
  14.0,                                /* Expression: fis.output(1).mf(6).params(1)
                                        * Referenced by: '<S88>/PM(Constant)'
                                        */
  20.0,                                /* Expression: fis.output(1).mf(7).params(1)
                                        * Referenced by: '<S88>/PB(Constant)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S92>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S92>/One'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S97>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S97>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S99>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S99>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S101>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S101>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S103>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S103>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S105>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S105>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S106>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S106>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S112>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S112>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S113>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S113>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S116>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S116>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S117>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S117>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S120>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S120>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S121>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S121>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S127>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S127>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S128>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S128>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S131>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S131>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S132>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S132>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S135>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S135>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S136>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S136>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S142>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S142>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S143>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S143>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S146>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S146>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S147>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S147>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S150>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S150>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S151>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S151>/0'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S7>/Weight'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S1>/Constant2'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S1>/Constant1'
                                        */
  0.31830988618379069,                 /* Expression: 1/pi
                                        * Referenced by: '<Root>/Gain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S1>/Gain'
                                        */
  0.1,                                 /* Expression: 1/10
                                        * Referenced by: '<Root>/Gain4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S1>/Gain1'
                                        */
  0.1,                                 /* Expression: 1/10
                                        * Referenced by: '<Root>/Gain2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S1>/Constant4'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S1>/Constant3'
                                        */
  0.31830988618379069,                 /* Expression: 1/pi
                                        * Referenced by: '<Root>/Gain3'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S18>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S29>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S40>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S51>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S62>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S73>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S84>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S87>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S8>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S9>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S10>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S11>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S12>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S13>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S14>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S15>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S16>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S17>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S19>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S20>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S21>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S22>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S23>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S24>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S25>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S26>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S27>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S28>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S30>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S31>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S32>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S33>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S34>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S35>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S36>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S37>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S38>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S39>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S41>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S42>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S43>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S44>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S45>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S46>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S47>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S48>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S49>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S50>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S52>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S53>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S54>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S55>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S56>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S57>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S58>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S59>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S60>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S61>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S63>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S64>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S65>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S66>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S67>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S68>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S69>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S70>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S71>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S72>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S74>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S75>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S76>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S77>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S78>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S79>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S80>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S81>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S82>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S83>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S85>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S86>/Weight'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Zero'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Switch'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Gain5'
                                        */

  /* Start of '<S141>/If Action Subsystem2' */
  {
    0.0,                               /* Expression: b
                                        * Referenced by: '<S152>/b'
                                        */
    3.142                              /* Expression: c
                                        * Referenced by: '<S152>/c'
                                        */
  }
  /* End of '<S141>/If Action Subsystem2' */
  ,

  /* Start of '<S141>/If Action Subsystem3' */
  {
    -3.142,                            /* Expression: a
                                        * Referenced by: '<S153>/a'
                                        */
    0.0                                /* Expression: b
                                        * Referenced by: '<S153>/b'
                                        */
  }
  /* End of '<S141>/If Action Subsystem3' */
  ,

  /* Start of '<S140>/If Action Subsystem2' */
  {
    3.142,                             /* Expression: b
                                        * Referenced by: '<S148>/b'
                                        */
    9.425                              /* Expression: c
                                        * Referenced by: '<S148>/c'
                                        */
  }
  /* End of '<S140>/If Action Subsystem2' */
  ,

  /* Start of '<S140>/If Action Subsystem3' */
  {
    0.0,                               /* Expression: a
                                        * Referenced by: '<S149>/a'
                                        */
    3.142                              /* Expression: b
                                        * Referenced by: '<S149>/b'
                                        */
  }
  /* End of '<S140>/If Action Subsystem3' */
  ,

  /* Start of '<S139>/If Action Subsystem2' */
  {
    -3.142,                            /* Expression: b
                                        * Referenced by: '<S144>/b'
                                        */
    0.0                                /* Expression: c
                                        * Referenced by: '<S144>/c'
                                        */
  }
  /* End of '<S139>/If Action Subsystem2' */
  ,

  /* Start of '<S139>/If Action Subsystem3' */
  {
    -12.57,                            /* Expression: a
                                        * Referenced by: '<S145>/a'
                                        */
    -3.142                             /* Expression: b
                                        * Referenced by: '<S145>/b'
                                        */
  }
  /* End of '<S139>/If Action Subsystem3' */
  ,

  /* Start of '<S126>/If Action Subsystem2' */
  {
    0.0,                               /* Expression: b
                                        * Referenced by: '<S137>/b'
                                        */
    1.0                                /* Expression: c
                                        * Referenced by: '<S137>/c'
                                        */
  }
  /* End of '<S126>/If Action Subsystem2' */
  ,

  /* Start of '<S126>/If Action Subsystem3' */
  {
    -1.0,                              /* Expression: a
                                        * Referenced by: '<S138>/a'
                                        */
    0.0                                /* Expression: b
                                        * Referenced by: '<S138>/b'
                                        */
  }
  /* End of '<S126>/If Action Subsystem3' */
  ,

  /* Start of '<S125>/If Action Subsystem2' */
  {
    1.0,                               /* Expression: b
                                        * Referenced by: '<S133>/b'
                                        */
    3.0                                /* Expression: c
                                        * Referenced by: '<S133>/c'
                                        */
  }
  /* End of '<S125>/If Action Subsystem2' */
  ,

  /* Start of '<S125>/If Action Subsystem3' */
  {
    0.0,                               /* Expression: a
                                        * Referenced by: '<S134>/a'
                                        */
    1.0                                /* Expression: b
                                        * Referenced by: '<S134>/b'
                                        */
  }
  /* End of '<S125>/If Action Subsystem3' */
  ,

  /* Start of '<S124>/If Action Subsystem2' */
  {
    -1.0,                              /* Expression: b
                                        * Referenced by: '<S129>/b'
                                        */
    0.0                                /* Expression: c
                                        * Referenced by: '<S129>/c'
                                        */
  }
  /* End of '<S124>/If Action Subsystem2' */
  ,

  /* Start of '<S124>/If Action Subsystem3' */
  {
    -5.0,                              /* Expression: a
                                        * Referenced by: '<S130>/a'
                                        */
    -1.0                               /* Expression: b
                                        * Referenced by: '<S130>/b'
                                        */
  }
  /* End of '<S124>/If Action Subsystem3' */
  ,

  /* Start of '<S111>/If Action Subsystem2' */
  {
    0.0,                               /* Expression: b
                                        * Referenced by: '<S122>/b'
                                        */
    1.0                                /* Expression: c
                                        * Referenced by: '<S122>/c'
                                        */
  }
  /* End of '<S111>/If Action Subsystem2' */
  ,

  /* Start of '<S111>/If Action Subsystem3' */
  {
    -1.0,                              /* Expression: a
                                        * Referenced by: '<S123>/a'
                                        */
    0.0                                /* Expression: b
                                        * Referenced by: '<S123>/b'
                                        */
  }
  /* End of '<S111>/If Action Subsystem3' */
  ,

  /* Start of '<S110>/If Action Subsystem2' */
  {
    1.0,                               /* Expression: b
                                        * Referenced by: '<S118>/b'
                                        */
    2.0                                /* Expression: c
                                        * Referenced by: '<S118>/c'
                                        */
  }
  /* End of '<S110>/If Action Subsystem2' */
  ,

  /* Start of '<S110>/If Action Subsystem3' */
  {
    0.0,                               /* Expression: a
                                        * Referenced by: '<S119>/a'
                                        */
    1.0                                /* Expression: b
                                        * Referenced by: '<S119>/b'
                                        */
  }
  /* End of '<S110>/If Action Subsystem3' */
  ,

  /* Start of '<S109>/If Action Subsystem2' */
  {
    -1.0,                              /* Expression: b
                                        * Referenced by: '<S114>/b'
                                        */
    0.0                                /* Expression: c
                                        * Referenced by: '<S114>/c'
                                        */
  }
  /* End of '<S109>/If Action Subsystem2' */
  ,

  /* Start of '<S109>/If Action Subsystem3' */
  {
    -5.0,                              /* Expression: a
                                        * Referenced by: '<S115>/a'
                                        */
    -1.0                               /* Expression: b
                                        * Referenced by: '<S115>/b'
                                        */
  }
  /* End of '<S109>/If Action Subsystem3' */
  ,

  /* Start of '<S96>/If Action Subsystem2' */
  {
    0.0,                               /* Expression: b
                                        * Referenced by: '<S107>/b'
                                        */
    3.14                               /* Expression: c
                                        * Referenced by: '<S107>/c'
                                        */
  }
  /* End of '<S96>/If Action Subsystem2' */
  ,

  /* Start of '<S96>/If Action Subsystem3' */
  {
    -3.14159265358979,                 /* Expression: a
                                        * Referenced by: '<S108>/a'
                                        */
    0.0                                /* Expression: b
                                        * Referenced by: '<S108>/b'
                                        */
  }
  /* End of '<S96>/If Action Subsystem3' */
  ,

  /* Start of '<S95>/If Action Subsystem3' */
  {
    4.18,                              /* Expression: c
                                        * Referenced by: '<S104>/c'
                                        */
    5.82                               /* Expression: d
                                        * Referenced by: '<S104>/d'
                                        */
  }
  /* End of '<S95>/If Action Subsystem3' */
  ,

  /* Start of '<S95>/If Action Subsystem1' */
  {
    0.0,                               /* Expression: a
                                        * Referenced by: '<S102>/a'
                                        */
    2.05                               /* Expression: b
                                        * Referenced by: '<S102>/b'
                                        */
  }
  /* End of '<S95>/If Action Subsystem1' */
  ,

  /* Start of '<S94>/If Action Subsystem3' */
  {
    -1.89,                             /* Expression: c
                                        * Referenced by: '<S100>/c'
                                        */
    0.0                                /* Expression: d
                                        * Referenced by: '<S100>/d'
                                        */
  }
  /* End of '<S94>/If Action Subsystem3' */
  ,

  /* Start of '<S94>/If Action Subsystem1' */
  {
    -5.97,                             /* Expression: a
                                        * Referenced by: '<S98>/a'
                                        */
    -3.46                              /* Expression: b
                                        * Referenced by: '<S98>/b'
                                        */
  }
  /* End of '<S94>/If Action Subsystem1' */
};

/* [EOF] */
