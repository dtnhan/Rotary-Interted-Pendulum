/*
 * File: BalanceMultiNew_data.c
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
#include "BalanceMultiNew.h"
#include "BalanceMultiNew_private.h"

/* Block parameters (auto storage) */
P_BalanceMultiNew_T BalanceMultiNew_P = {
  23.0,                                /* Expression: 23
                                        * Referenced by: '<S5>/Saturation'
                                        */
  -23.0,                               /* Expression: -23
                                        * Referenced by: '<S5>/Saturation'
                                        */
  0.0,                                 /* Expression: mean(cat(1,fis.output.range),2)
                                        * Referenced by: '<S16>/MidRange'
                                        */

  /*  Expression: Xdata
   * Referenced by: '<S17>/x data'
   */
  { -1.0, -0.98, -0.96, -0.94, -0.92, -0.9, -0.88, -0.86, -0.84,
    -0.82000000000000006, -0.8, -0.78, -0.76, -0.74, -0.72, -0.7,
    -0.67999999999999994, -0.65999999999999992, -0.64, -0.62, -0.6,
    -0.58000000000000007, -0.56, -0.54, -0.52, -0.5, -0.48, -0.45999999999999996,
    -0.43999999999999995, -0.42000000000000004, -0.4, -0.38, -0.36,
    -0.33999999999999997, -0.31999999999999995, -0.30000000000000004, -0.28,
    -0.26, -0.24, -0.21999999999999997, -0.19999999999999996,
    -0.18000000000000005, -0.16000000000000003, -0.14, -0.12,
    -0.099999999999999978, -0.07999999999999996, -0.060000000000000053,
    -0.040000000000000036, -0.020000000000000018, 0.0, 0.020000000000000018,
    0.040000000000000036, 0.060000000000000053, 0.080000000000000071,
    0.10000000000000009, 0.12000000000000011, 0.1399999999999999,
    0.15999999999999992, 0.17999999999999994, 0.19999999999999996,
    0.21999999999999997, 0.24, 0.26, 0.28, 0.30000000000000004,
    0.32000000000000006, 0.34000000000000008, 0.3600000000000001,
    0.37999999999999989, 0.39999999999999991, 0.41999999999999993,
    0.43999999999999995, 0.45999999999999996, 0.48, 0.5, 0.52, 0.54, 0.56,
    0.58000000000000007, 0.60000000000000009, 0.62000000000000011,
    0.6399999999999999, 0.65999999999999992, 0.67999999999999994, 0.7, 0.72,
    0.74, 0.76, 0.78, 0.8, 0.82000000000000006, 0.84000000000000008,
    0.8600000000000001, 0.87999999999999989, 0.89999999999999991,
    0.91999999999999993, 0.94, 0.96, 0.98, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S25>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S25>/One'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S36>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S37>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S37>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S40>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S40>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S41>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S41>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S44>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S44>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S45>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S45>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S48>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S49>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S49>/0'
                                        */
  0.5,                                 /* Expression: mean(cat(1,fis.output.range),2)
                                        * Referenced by: '<S52>/MidRange'
                                        */
  1.0,                                 /* Expression: fis.output(1).mf(7).params(1)
                                        * Referenced by: '<S136>/PB(Constant)'
                                        */
  0.66,                                /* Expression: fis.output(1).mf(6).params(1)
                                        * Referenced by: '<S136>/PM(Constant)'
                                        */
  0.33,                                /* Expression: fis.output(1).mf(5).params(1)
                                        * Referenced by: '<S136>/PS(Constant)'
                                        */
  0.0,                                 /* Expression: fis.output(1).mf(4).params(1)
                                        * Referenced by: '<S136>/ZE(Constant)'
                                        */
  -0.33,                               /* Expression: fis.output(1).mf(3).params(1)
                                        * Referenced by: '<S136>/NS(Constant)'
                                        */
  -0.66,                               /* Expression: fis.output(1).mf(2).params(1)
                                        * Referenced by: '<S136>/NM(Constant)'
                                        */
  -1.0,                                /* Expression: fis.output(1).mf(1).params(1)
                                        * Referenced by: '<S136>/NB(Constant)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S140>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S140>/One'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S145>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S145>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S146>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S146>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S149>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S149>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S150>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S150>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S153>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S153>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S154>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S154>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S160>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S160>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S161>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S161>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S164>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S164>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S165>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S165>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S168>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S168>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S169>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S169>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S175>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S175>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S176>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S176>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S179>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S179>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S180>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S180>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S183>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S183>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S184>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S184>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S190>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S190>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S191>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S191>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S194>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S194>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S195>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S195>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S198>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S198>/0'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S199>/Out1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S199>/0'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S3>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S3>/Gain'
                                        */

  /*  Expression: [-160.8 -22.234  3.324 12.052]
   * Referenced by: '<S5>/LQR Controller'
   */
  { -160.8, -22.234, 3.324, 12.052 },
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S18>/Weight'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<S5>/LQR Controller1'
                                        */
  0.2765,                              /* Expression: 0.2765
                                        * Referenced by: '<S5>/LQR Controller2'
                                        */
  -0.29,                               /* Expression: -0.29
                                        * Referenced by: '<S5>/LQR Controller3'
                                        */
  -0.15,                               /* Expression: -0.15
                                        * Referenced by: '<S5>/LQR Controller4'
                                        */

  /*  Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(1).params)
   * Referenced by: '<S24>/mf1'
   */
  { 1.0, 0.96, 0.91999999999999993, 0.87999999999999989, 0.84000000000000008,
    0.8, 0.76, 0.72, 0.67999999999999994, 0.64000000000000012,
    0.60000000000000009, 0.56, 0.52, 0.48, 0.43999999999999995,
    0.39999999999999991, 0.35999999999999988, 0.31999999999999984, 0.28, 0.24,
    0.19999999999999996, 0.16000000000000014, 0.12000000000000011,
    0.080000000000000071, 0.040000000000000036, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S19>/Weight'
                                        */

  /*  Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(2).params)
   * Referenced by: '<S24>/mf2'
   */
  { 0.0, 0.040000000000000036, 0.080000000000000071, 0.12000000000000011,
    0.15999999999999992, 0.19999999999999996, 0.24, 0.28, 0.32000000000000006,
    0.35999999999999988, 0.39999999999999991, 0.43999999999999995, 0.48, 0.52,
    0.56, 0.60000000000000009, 0.64000000000000012, 0.68000000000000016, 0.72,
    0.76, 0.8, 0.83999999999999986, 0.87999999999999989, 0.91999999999999993,
    0.96, 1.0, 0.96, 0.91999999999999993, 0.87999999999999989,
    0.84000000000000008, 0.8, 0.76, 0.72, 0.67999999999999994,
    0.6399999999999999, 0.60000000000000009, 0.56, 0.52, 0.48,
    0.43999999999999995, 0.39999999999999991, 0.3600000000000001,
    0.32000000000000006, 0.28, 0.24, 0.19999999999999996, 0.15999999999999992,
    0.12000000000000011, 0.080000000000000071, 0.040000000000000036, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S20>/Weight'
                                        */

  /*  Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(3).params)
   * Referenced by: '<S24>/mf3'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.040000000000000036,
    0.080000000000000071, 0.12000000000000011, 0.15999999999999992,
    0.19999999999999996, 0.24, 0.28, 0.32000000000000006, 0.3600000000000001,
    0.39999999999999991, 0.43999999999999995, 0.48, 0.52, 0.56,
    0.60000000000000009, 0.6399999999999999, 0.67999999999999994, 0.72, 0.76,
    0.8, 0.84000000000000008, 0.87999999999999989, 0.91999999999999993, 0.96,
    1.0, 0.96, 0.91999999999999993, 0.87999999999999989, 0.83999999999999986,
    0.79999999999999982, 0.75999999999999979, 0.7200000000000002,
    0.68000000000000016, 0.64000000000000012, 0.60000000000000009, 0.56, 0.52,
    0.48, 0.43999999999999995, 0.39999999999999991, 0.35999999999999988,
    0.31999999999999984, 0.2799999999999998, 0.24000000000000021,
    0.20000000000000018, 0.16000000000000014, 0.12000000000000011,
    0.080000000000000071, 0.040000000000000036, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 },
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S21>/Weight'
                                        */

  /*  Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(4).params)
   * Referenced by: '<S24>/mf4'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.040000000000000036, 0.080000000000000071,
    0.12000000000000011, 0.16000000000000014, 0.20000000000000018,
    0.24000000000000021, 0.2799999999999998, 0.31999999999999984,
    0.35999999999999988, 0.39999999999999991, 0.43999999999999995, 0.48, 0.52,
    0.56, 0.60000000000000009, 0.64000000000000012, 0.68000000000000016,
    0.7200000000000002, 0.75999999999999979, 0.79999999999999982,
    0.83999999999999986, 0.87999999999999989, 0.91999999999999993, 0.96, 1.0,
    0.96, 0.91999999999999993, 0.87999999999999989, 0.83999999999999986,
    0.79999999999999982, 0.75999999999999979, 0.7200000000000002,
    0.68000000000000016, 0.64000000000000012, 0.60000000000000009, 0.56, 0.52,
    0.48, 0.43999999999999995, 0.39999999999999991, 0.35999999999999988,
    0.31999999999999984, 0.2799999999999998, 0.24000000000000021,
    0.20000000000000018, 0.16000000000000014, 0.12000000000000011,
    0.080000000000000071, 0.040000000000000036, 0.0 },
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S22>/Weight'
                                        */

  /*  Expression: trimf(linspace(fis.output(1).range(1),fis.output(1).range(2),101),fis.output(1).mf(5).params)
   * Referenced by: '<S24>/mf5'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.040000000000000036, 0.080000000000000071, 0.12000000000000011,
    0.16000000000000014, 0.20000000000000018, 0.24000000000000021,
    0.2799999999999998, 0.31999999999999984, 0.35999999999999988,
    0.39999999999999991, 0.43999999999999995, 0.48, 0.52, 0.56,
    0.60000000000000009, 0.64000000000000012, 0.68000000000000016,
    0.7200000000000002, 0.75999999999999979, 0.79999999999999982,
    0.83999999999999986, 0.87999999999999989, 0.91999999999999993, 0.96, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Zero'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S16>/Switch'
                                        */
  -90.0,                               /* Expression: -90
                                        * Referenced by: '<S5>/FuzzyGain'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S55>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S66>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S77>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S88>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S99>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S110>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S121>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S132>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S135>/Weight'
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
                                        * Referenced by: '<S62>/Weight'
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
                                        * Referenced by: '<S73>/Weight'
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
                                        * Referenced by: '<S84>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S85>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S86>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S87>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S89>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S90>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S91>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S92>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S93>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S94>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S95>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S96>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S97>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S98>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S100>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S101>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S102>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S103>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S104>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S105>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S106>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S107>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S108>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S109>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S111>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S112>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S113>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S114>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S115>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S116>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S117>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S118>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S119>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S120>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S122>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S123>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S124>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S125>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S126>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S127>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S128>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S129>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S130>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S131>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S133>/Weight'
                                        */
  1.0,                                 /* Expression: fis.rule(j_rule).weight
                                        * Referenced by: '<S134>/Weight'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S52>/Zero'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S52>/Switch'
                                        */
  -90.0,                               /* Expression: -90
                                        * Referenced by: '<S5>/FuzzyGain1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Switch1'
                                        */

  /* Start of '<S189>/If Action Subsystem2' */
  {
    0.0,                               /* Expression: b
                                        * Referenced by: '<S200>/b'
                                        */
    1.0                                /* Expression: c
                                        * Referenced by: '<S200>/c'
                                        */
  }
  /* End of '<S189>/If Action Subsystem2' */
  ,

  /* Start of '<S189>/If Action Subsystem3' */
  {
    -1.0,                              /* Expression: a
                                        * Referenced by: '<S201>/a'
                                        */
    0.0                                /* Expression: b
                                        * Referenced by: '<S201>/b'
                                        */
  }
  /* End of '<S189>/If Action Subsystem3' */
  ,

  /* Start of '<S188>/If Action Subsystem2' */
  {
    1.0,                               /* Expression: b
                                        * Referenced by: '<S196>/b'
                                        */
    3.0                                /* Expression: c
                                        * Referenced by: '<S196>/c'
                                        */
  }
  /* End of '<S188>/If Action Subsystem2' */
  ,

  /* Start of '<S188>/If Action Subsystem3' */
  {
    0.0,                               /* Expression: a
                                        * Referenced by: '<S197>/a'
                                        */
    1.0                                /* Expression: b
                                        * Referenced by: '<S197>/b'
                                        */
  }
  /* End of '<S188>/If Action Subsystem3' */
  ,

  /* Start of '<S187>/If Action Subsystem2' */
  {
    -1.0,                              /* Expression: b
                                        * Referenced by: '<S192>/b'
                                        */
    0.0                                /* Expression: c
                                        * Referenced by: '<S192>/c'
                                        */
  }
  /* End of '<S187>/If Action Subsystem2' */
  ,

  /* Start of '<S187>/If Action Subsystem3' */
  {
    -4.0,                              /* Expression: a
                                        * Referenced by: '<S193>/a'
                                        */
    -1.0                               /* Expression: b
                                        * Referenced by: '<S193>/b'
                                        */
  }
  /* End of '<S187>/If Action Subsystem3' */
  ,

  /* Start of '<S174>/If Action Subsystem2' */
  {
    0.0,                               /* Expression: b
                                        * Referenced by: '<S185>/b'
                                        */
    1.0                                /* Expression: c
                                        * Referenced by: '<S185>/c'
                                        */
  }
  /* End of '<S174>/If Action Subsystem2' */
  ,

  /* Start of '<S174>/If Action Subsystem3' */
  {
    -1.0,                              /* Expression: a
                                        * Referenced by: '<S186>/a'
                                        */
    0.0                                /* Expression: b
                                        * Referenced by: '<S186>/b'
                                        */
  }
  /* End of '<S174>/If Action Subsystem3' */
  ,

  /* Start of '<S173>/If Action Subsystem2' */
  {
    1.0,                               /* Expression: b
                                        * Referenced by: '<S181>/b'
                                        */
    2.0                                /* Expression: c
                                        * Referenced by: '<S181>/c'
                                        */
  }
  /* End of '<S173>/If Action Subsystem2' */
  ,

  /* Start of '<S173>/If Action Subsystem3' */
  {
    0.0,                               /* Expression: a
                                        * Referenced by: '<S182>/a'
                                        */
    1.0                                /* Expression: b
                                        * Referenced by: '<S182>/b'
                                        */
  }
  /* End of '<S173>/If Action Subsystem3' */
  ,

  /* Start of '<S172>/If Action Subsystem2' */
  {
    -1.0,                              /* Expression: b
                                        * Referenced by: '<S177>/b'
                                        */
    0.0                                /* Expression: c
                                        * Referenced by: '<S177>/c'
                                        */
  }
  /* End of '<S172>/If Action Subsystem2' */
  ,

  /* Start of '<S172>/If Action Subsystem3' */
  {
    -5.0,                              /* Expression: a
                                        * Referenced by: '<S178>/a'
                                        */
    -1.0                               /* Expression: b
                                        * Referenced by: '<S178>/b'
                                        */
  }
  /* End of '<S172>/If Action Subsystem3' */
  ,

  /* Start of '<S159>/If Action Subsystem2' */
  {
    0.0,                               /* Expression: b
                                        * Referenced by: '<S170>/b'
                                        */
    1.0                                /* Expression: c
                                        * Referenced by: '<S170>/c'
                                        */
  }
  /* End of '<S159>/If Action Subsystem2' */
  ,

  /* Start of '<S159>/If Action Subsystem3' */
  {
    -1.0,                              /* Expression: a
                                        * Referenced by: '<S171>/a'
                                        */
    0.0                                /* Expression: b
                                        * Referenced by: '<S171>/b'
                                        */
  }
  /* End of '<S159>/If Action Subsystem3' */
  ,

  /* Start of '<S158>/If Action Subsystem2' */
  {
    1.0,                               /* Expression: b
                                        * Referenced by: '<S166>/b'
                                        */
    3.0                                /* Expression: c
                                        * Referenced by: '<S166>/c'
                                        */
  }
  /* End of '<S158>/If Action Subsystem2' */
  ,

  /* Start of '<S158>/If Action Subsystem3' */
  {
    0.0,                               /* Expression: a
                                        * Referenced by: '<S167>/a'
                                        */
    1.0                                /* Expression: b
                                        * Referenced by: '<S167>/b'
                                        */
  }
  /* End of '<S158>/If Action Subsystem3' */
  ,

  /* Start of '<S157>/If Action Subsystem2' */
  {
    -1.0,                              /* Expression: b
                                        * Referenced by: '<S162>/b'
                                        */
    0.0                                /* Expression: c
                                        * Referenced by: '<S162>/c'
                                        */
  }
  /* End of '<S157>/If Action Subsystem2' */
  ,

  /* Start of '<S157>/If Action Subsystem3' */
  {
    -5.0,                              /* Expression: a
                                        * Referenced by: '<S163>/a'
                                        */
    -1.0                               /* Expression: b
                                        * Referenced by: '<S163>/b'
                                        */
  }
  /* End of '<S157>/If Action Subsystem3' */
  ,

  /* Start of '<S144>/If Action Subsystem2' */
  {
    0.0,                               /* Expression: b
                                        * Referenced by: '<S155>/b'
                                        */
    1.0                                /* Expression: c
                                        * Referenced by: '<S155>/c'
                                        */
  }
  /* End of '<S144>/If Action Subsystem2' */
  ,

  /* Start of '<S144>/If Action Subsystem3' */
  {
    -1.0,                              /* Expression: a
                                        * Referenced by: '<S156>/a'
                                        */
    0.0                                /* Expression: b
                                        * Referenced by: '<S156>/b'
                                        */
  }
  /* End of '<S144>/If Action Subsystem3' */
  ,

  /* Start of '<S143>/If Action Subsystem2' */
  {
    1.0,                               /* Expression: b
                                        * Referenced by: '<S151>/b'
                                        */
    2.0                                /* Expression: c
                                        * Referenced by: '<S151>/c'
                                        */
  }
  /* End of '<S143>/If Action Subsystem2' */
  ,

  /* Start of '<S143>/If Action Subsystem3' */
  {
    0.0,                               /* Expression: a
                                        * Referenced by: '<S152>/a'
                                        */
    1.0                                /* Expression: b
                                        * Referenced by: '<S152>/b'
                                        */
  }
  /* End of '<S143>/If Action Subsystem3' */
  ,

  /* Start of '<S142>/If Action Subsystem2' */
  {
    -1.0,                              /* Expression: b
                                        * Referenced by: '<S147>/b'
                                        */
    0.0                                /* Expression: c
                                        * Referenced by: '<S147>/c'
                                        */
  }
  /* End of '<S142>/If Action Subsystem2' */
  ,

  /* Start of '<S142>/If Action Subsystem3' */
  {
    -2.0,                              /* Expression: a
                                        * Referenced by: '<S148>/a'
                                        */
    -1.0                               /* Expression: b
                                        * Referenced by: '<S148>/b'
                                        */
  }
  /* End of '<S142>/If Action Subsystem3' */
  ,

  /* Start of '<S31>/If Action Subsystem2' */
  {
    1.0,                               /* Expression: b
                                        * Referenced by: '<S50>/b'
                                        */
    1.5                                /* Expression: c
                                        * Referenced by: '<S50>/c'
                                        */
  }
  /* End of '<S31>/If Action Subsystem2' */
  ,

  /* Start of '<S31>/If Action Subsystem3' */
  {
    0.5,                               /* Expression: a
                                        * Referenced by: '<S51>/a'
                                        */
    1.0                                /* Expression: b
                                        * Referenced by: '<S51>/b'
                                        */
  }
  /* End of '<S31>/If Action Subsystem3' */
  ,

  /* Start of '<S30>/If Action Subsystem2' */
  {
    0.5,                               /* Expression: b
                                        * Referenced by: '<S46>/b'
                                        */
    1.0                                /* Expression: c
                                        * Referenced by: '<S46>/c'
                                        */
  }
  /* End of '<S30>/If Action Subsystem2' */
  ,

  /* Start of '<S30>/If Action Subsystem3' */
  {
    0.0,                               /* Expression: a
                                        * Referenced by: '<S47>/a'
                                        */
    0.5                                /* Expression: b
                                        * Referenced by: '<S47>/b'
                                        */
  }
  /* End of '<S30>/If Action Subsystem3' */
  ,

  /* Start of '<S29>/If Action Subsystem2' */
  {
    0.0,                               /* Expression: b
                                        * Referenced by: '<S42>/b'
                                        */
    0.5                                /* Expression: c
                                        * Referenced by: '<S42>/c'
                                        */
  }
  /* End of '<S29>/If Action Subsystem2' */
  ,

  /* Start of '<S29>/If Action Subsystem3' */
  {
    -0.5,                              /* Expression: a
                                        * Referenced by: '<S43>/a'
                                        */
    0.0                                /* Expression: b
                                        * Referenced by: '<S43>/b'
                                        */
  }
  /* End of '<S29>/If Action Subsystem3' */
  ,

  /* Start of '<S28>/If Action Subsystem2' */
  {
    -0.5,                              /* Expression: b
                                        * Referenced by: '<S38>/b'
                                        */
    0.0                                /* Expression: c
                                        * Referenced by: '<S38>/c'
                                        */
  }
  /* End of '<S28>/If Action Subsystem2' */
  ,

  /* Start of '<S28>/If Action Subsystem3' */
  {
    -1.0,                              /* Expression: a
                                        * Referenced by: '<S39>/a'
                                        */
    -0.5                               /* Expression: b
                                        * Referenced by: '<S39>/b'
                                        */
  }
  /* End of '<S28>/If Action Subsystem3' */
  ,

  /* Start of '<S27>/If Action Subsystem2' */
  {
    -1.0,                              /* Expression: b
                                        * Referenced by: '<S34>/b'
                                        */
    -0.5                               /* Expression: c
                                        * Referenced by: '<S34>/c'
                                        */
  }
  /* End of '<S27>/If Action Subsystem2' */
  ,

  /* Start of '<S27>/If Action Subsystem3' */
  {
    -1.5,                              /* Expression: a
                                        * Referenced by: '<S35>/a'
                                        */
    -1.0                               /* Expression: b
                                        * Referenced by: '<S35>/b'
                                        */
  }
  /* End of '<S27>/If Action Subsystem3' */
};

/* [EOF] */
