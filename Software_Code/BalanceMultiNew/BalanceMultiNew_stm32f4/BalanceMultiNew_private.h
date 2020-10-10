/*
 * File: BalanceMultiNew_private.h
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

#ifndef RTW_HEADER_BalanceMultiNew_private_h_
#define RTW_HEADER_BalanceMultiNew_private_h_
#include "rtwtypes.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

extern real_T rt_roundd_snf(real_T u);
extern void BalanceMultiNew_Actionu1(real_T rtu_0, real_T *rty_u2);
extern void BalanceMulti_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem3_BalanceM_T *localP);
extern void BalanceMulti_IfActionSubsystem2(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem2_BalanceM_T *localP);

#endif                                 /* RTW_HEADER_BalanceMultiNew_private_h_ */

/* [EOF] */
