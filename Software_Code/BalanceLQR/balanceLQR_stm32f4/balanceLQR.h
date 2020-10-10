/*
 * File: balanceLQR.h
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

#ifndef RTW_HEADER_balanceLQR_h_
#define RTW_HEADER_balanceLQR_h_
#ifndef balanceLQR_COMMON_INCLUDES_
# define balanceLQR_COMMON_INCLUDES_
#include <math.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "waijung_hwdrvlib.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#endif                                 /* balanceLQR_COMMON_INCLUDES_ */

#include "balanceLQR_types.h"

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
  real_T SFunctionBuilder1;            /* '<S2>/S-Function Builder1' */
  real_T Gain1;                        /* '<S2>/Gain1' */
  real_T SFunctionBuilder;             /* '<S2>/S-Function Builder' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T Switch;                       /* '<Root>/Switch' */
  real_T Add2;                         /* '<S2>/Add2' */
  real_T Switch1;                      /* '<Root>/Switch1' */
  real_T PWM;                          /* '<Root>/V_control' */
  real_T DIR;                          /* '<Root>/V_control' */
  int32_T QuadraturEncoder_o1;         /* '<S2>/Quadratur Encoder' */
  int32_T QuadraturEncoder_o2;         /* '<S2>/Quadratur Encoder' */
  boolean_T DigitalInput;              /* '<S2>/Digital Input' */
} B_balanceLQR_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S2>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
} DW_balanceLQR_T;

/* Parameters (auto storage) */
struct P_balanceLQR_T_ {
  real_T Constant6_Value;              /* Expression: pi
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T LQRController_Gain[4];        /* Expression: [-160.8 -20.234  10.324 10.252 ]
                                        * Referenced by: '<S3>/LQR Controller'
                                        */
  real_T Constant2_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: pi
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Constant4_Value;              /* Expression: 2*pi
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant3_Value;              /* Expression: pi
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Switch_Threshold;             /* Expression: 1
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant5_Value;              /* Expression: pi
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<Root>/Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_balanceLQR_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_balanceLQR_T balanceLQR_P;

/* Block signals (auto storage) */
extern B_balanceLQR_T balanceLQR_B;

/* Block states (auto storage) */
extern DW_balanceLQR_T balanceLQR_DW;

/* Model entry point functions */
extern void balanceLQR_initialize(void);
extern void balanceLQR_step(void);
extern void balanceLQR_terminate(void);

/* Real-time Model object */
extern RT_MODEL_balanceLQR_T *const balanceLQR_M;

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
 * '<Root>' : 'balanceLQR'
 * '<S1>'   : 'balanceLQR/Convert'
 * '<S2>'   : 'balanceLQR/Encoders'
 * '<S3>'   : 'balanceLQR/LQR Controller'
 * '<S4>'   : 'balanceLQR/SWINGUP'
 * '<S5>'   : 'balanceLQR/Switch_Funciton'
 * '<S6>'   : 'balanceLQR/V_control'
 */
#endif                                 /* RTW_HEADER_balanceLQR_h_ */

/* [EOF] */
