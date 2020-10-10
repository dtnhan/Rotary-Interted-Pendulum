/*
 * File: balanceLQR_data.c
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model balanceLQR.
 *
 * Model version                        : 1.69
 * Real-Time Workshop file version      : 8.4 (R2013a) 13-Feb-2013
 * Real-Time Workshop file generated on : Tue Dec 17 18:01:43 2013
 * TLC version                          : 8.4 (Jan 19 2013)
 * C/C++ source code generated on       : Tue Dec 17 18:01:44 2013
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "balanceLQR.h"
#include "balanceLQR_private.h"

/* Block parameters (auto storage) */
P_balanceLQR_T balanceLQR_P = {
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S2>/Constant6'
                                        */

  /*  Expression: [-160.8 -20.234  10.324 10.252 ]
   * Referenced by: '<S3>/LQR Controller'
   */
  { -160.8, -20.234, 10.324, 10.252 },
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S2>/Constant2'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S2>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay1'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S2>/Gain1'
                                        */
  6.2831853071795862,                  /* Expression: 2*pi
                                        * Referenced by: '<S2>/Constant4'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S2>/Constant3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay'
                                        */
  100.0,                               /* Expression: 100
                                        * Referenced by: '<S2>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Switch'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S2>/Constant5'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/Switch1'
                                        */
};

/* [EOF] */
