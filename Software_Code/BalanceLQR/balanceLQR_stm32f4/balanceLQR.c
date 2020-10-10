/*
 * File: balanceLQR.c
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

/* Block signals (auto storage) */
B_balanceLQR_T balanceLQR_B;

/* Block states (auto storage) */
DW_balanceLQR_T balanceLQR_DW;

/* Real-time model */
RT_MODEL_balanceLQR_T balanceLQR_M_;
RT_MODEL_balanceLQR_T *const balanceLQR_M = &balanceLQR_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (balanceLQR_M->Timing.TaskCounters.TID[1])++;
  if ((balanceLQR_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [10.0s, 0.0s] */
    balanceLQR_M->Timing.TaskCounters.TID[1] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = -0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else {
      if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
        y = 0.0;
      } else {
        y = (tmp - floor(tmp)) * u1;
      }
    }
  }

  return y;
}

/* Model step function */
void balanceLQR_step(void)
{
  real_T rtb_Add;
  real_T rtb_Add1;
  int32_T rtb_sw;
  int32_T rtb_u;

  /* S-Function (stm32f4_digital_input): '<S2>/Digital Input' */
  balanceLQR_B.DigitalInput = *EncodersDigitalInput_A0;

  /* S-Function (waijung_basic_customcode): '<S2>/Quadratur Encoder' */

  /*
   * Custom Code Block Output Function
   * Block: <S2>/Quadratur Encoder
   * BlockID: EncodersQuadraturEncoder
   * Input Port Definitions
   * in1: Port label 'inalpha', Type: boolean_T
   * in2: Port label 'intheta', Type: boolean_T
   * Output Port Definitions
   * out1: Port label 'alpha', Type: int32_T
   * out2: Port label ' theta', Type: int32_T
   */
  output_EncodersQuadraturEncoder(balanceLQR_B.DigitalInput,
    balanceLQR_B.DigitalInput , &balanceLQR_B.QuadraturEncoder_o1,
    &balanceLQR_B.QuadraturEncoder_o2);

  /* S-Function (pulsetoangle): '<S2>/S-Function Builder1' */
  pulsetoangle_Outputs_wrapper(&balanceLQR_B.QuadraturEncoder_o1,
    &balanceLQR_B.SFunctionBuilder1 );

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   *  Math: '<S2>/Math Function2'
   */
  rtb_Add = rt_modd_snf(balanceLQR_B.SFunctionBuilder1,
                        balanceLQR_P.Constant2_Value) -
    balanceLQR_P.Constant1_Value;

  /* Gain: '<S2>/Gain1' incorporates:
   *  Sum: '<S2>/Sum1'
   *  UnitDelay: '<S2>/Unit Delay1'
   */
  balanceLQR_B.Gain1 = (balanceLQR_B.SFunctionBuilder1 -
                        balanceLQR_DW.UnitDelay1_DSTATE) *
    balanceLQR_P.Gain1_Gain;

  /* MATLAB Function: '<Root>/SWINGUP' */
  /* MATLAB Function 'SWINGUP': '<S4>:1' */
  /* #************************ */
  /* energy based control */
  /* #***********************88 */
  /* if (alpha>0.6)||(alpha<-0.6) */
  /* '<S4>:1:7' */
  if (balanceLQR_B.Gain1 * cos(rtb_Add) < 0.0) {
    /* '<S4>:1:8' */
    /* '<S4>:1:9' */
    rtb_u = -5;

    /*  % % % % % elseif (alphadot*cos(alpha))>0 */
    /*  % % % % %     u=voltage; */
    /*  if(q1>pi)&&(q1<2*pi) */
    /*      q1=q1-2*pi; */
    /*  if(abs(q2)<pi/2) */
    /*  if((alpha>=pi)&&(alpha<3*pi/2)&&(alphadot<=0)) */
    /*      u=20; */
    /*  elseif ((alpha<pi)&&(alpha>pi/2)&&(alphadot>0)) */
    /*      u=-20; */
    /*  % if((alpha>=-pi)&&(alpha<-pi/2)&&(alphadot<=0)) */
    /*  %     u=10; */
    /*  % elseif ((alpha<pi)&&(alpha>pi/2)&&(alphadot>0)) */
    /*  %     u=-10; */
    /*  elseif ((abs(q1)< pi/18)) */
    /*      u = -(q2*(-10)+ q1*(53.5434) + q2dot*(-4.9882) + q1dot*(7.4922)); */
    /*  else */
    /*      u = 0; */
    /*  end */
    /*  elseif(q2>pi) */
    /*      u=-3; */
  } else {
    /* '<S4>:1:31' */
    rtb_u = 5;
  }

  /* End of MATLAB Function: '<Root>/SWINGUP' */

  /* MATLAB Function: '<Root>/Switch_Funciton' */
  /* else u=0; */
  /*  if u >=24 */
  /*      u = 24; */
  /*  end */
  /*  if u <= -24 */
  /*      u = -24; */
  /*  end -10.0000   53.5434   -4.9882    7.4922 */
  /* MATLAB Function 'Switch_Funciton': '<S5>:1' */
  if ((rtb_Add < 0.314) && (rtb_Add > -0.314)) {
    /* '<S5>:1:2' */
    /* '<S5>:1:3' */
    rtb_sw = 0;
  } else {
    /* '<S5>:1:5' */
    rtb_sw = 1;
  }

  /* End of MATLAB Function: '<Root>/Switch_Funciton' */

  /* S-Function (pulsetoangle1): '<S2>/S-Function Builder' */
  pulsetoangle1_Outputs_wrapper(&balanceLQR_B.QuadraturEncoder_o2,
    &balanceLQR_B.SFunctionBuilder );

  /* Sum: '<S2>/Add1' incorporates:
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S2>/Constant4'
   *  Math: '<S2>/Math Function1'
   */
  rtb_Add1 = rt_modd_snf(balanceLQR_B.SFunctionBuilder,
    balanceLQR_P.Constant4_Value) - balanceLQR_P.Constant3_Value;

  /* Gain: '<S2>/Gain' incorporates:
   *  Sum: '<S2>/Sum'
   *  UnitDelay: '<S2>/Unit Delay'
   */
  balanceLQR_B.Gain = (balanceLQR_B.SFunctionBuilder -
                       balanceLQR_DW.UnitDelay_DSTATE) * balanceLQR_P.Gain_Gain;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S3>/LQR Controller'
   *  SignalConversion: '<S3>/TmpSignal ConversionAtLQR ControllerInport1'
   *  Sum: '<Root>/Add'
   */
  if (rtb_sw >= balanceLQR_P.Switch_Threshold) {
    balanceLQR_B.Switch = rtb_u;
  } else {
    balanceLQR_B.Switch = ((balanceLQR_P.LQRController_Gain[0] * rtb_Add +
      balanceLQR_P.LQRController_Gain[1] * balanceLQR_B.Gain1) + (rtb_Add1 -
      balanceLQR_P.Constant_Value) * balanceLQR_P.LQRController_Gain[2]) +
      balanceLQR_P.LQRController_Gain[3] * balanceLQR_B.Gain;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLAB Function: '<Root>/V_control' */
  /* MATLAB Function 'V_control': '<S6>:1' */
  if (balanceLQR_B.Switch < 0.0) {
    /* '<S6>:1:3' */
    /* '<S6>:1:4' */
    balanceLQR_B.DIR = 0.0;

    /* '<S6>:1:5' */
    balanceLQR_B.PWM = -balanceLQR_B.Switch * 100.0 / 24.0;
  } else {
    /*      DIR=1; */
    /*      PWM=u*100/24; */
    /* '<S6>:1:9' */
    balanceLQR_B.DIR = 1.0;

    /* '<S6>:1:10' */
    balanceLQR_B.PWM = balanceLQR_B.Switch * 100.0 / 24.0;
  }

  /* End of MATLAB Function: '<Root>/V_control' */

  /* S-Function Block: <Root>/Basic PWM (stm32f4_basicpwm) */
  TIM3->CCR1 = (uint32_t) (balanceLQR_B.PWM * BasicPWM_SF);

  /* S-Function (stm32f4_digital_output): '<Root>/Digital Output' */

  /* DigitalOutput */
  *DigitalOutput_D12 = (boolean_T) balanceLQR_B.DIR;

  /* Sum: '<S2>/Add2' incorporates:
   *  Constant: '<S2>/Constant5'
   */
  balanceLQR_B.Add2 = balanceLQR_B.SFunctionBuilder1 +
    balanceLQR_P.Constant5_Value;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S2>/Constant6'
   *  Sum: '<S2>/Add3'
   */
  if (rtb_sw >= balanceLQR_P.Switch1_Threshold) {
    balanceLQR_B.Switch1 = balanceLQR_B.SFunctionBuilder -
      balanceLQR_P.Constant6_Value;
  } else {
    balanceLQR_B.Switch1 = rtb_Add1;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* S-Function (stm32f4_usart): '<Root>/UART Tx' */

  /* UARTTx */
  UARTTx_packet_buffer[0] = 126;
  UARTTx_packet_buffer[1] = 126;
  memcpy(&(UARTTx_packet_buffer[2]), &balanceLQR_B.Add2, 8);/* Double */
  memcpy(&(UARTTx_packet_buffer[10]), &balanceLQR_B.Gain1, 8);/* Double */
  memcpy(&(UARTTx_packet_buffer[18]), &balanceLQR_B.Switch1, 8);/* Double */
  memcpy(&(UARTTx_packet_buffer[26]), &balanceLQR_B.Gain, 8);/* Double */
  memcpy(&(UARTTx_packet_buffer[34]), &balanceLQR_P.Constant_Value, 8);/* Double */
  memcpy(&(UARTTx_packet_buffer[42]), &balanceLQR_B.Switch, 8);/* Double */
  UARTTx_packet_buffer[50] = 3;
  UARTTx_packet_buffer[51] = 3;
  UARTTxBlockingWrite(UARTTx_packet_buffer, 52);

  /* Update for UnitDelay: '<S2>/Unit Delay1' */
  /* MATLAB Function 'Convert': '<S1>:1' */
  balanceLQR_DW.UnitDelay1_DSTATE = balanceLQR_B.SFunctionBuilder1;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  balanceLQR_DW.UnitDelay_DSTATE = balanceLQR_B.SFunctionBuilder;
  rate_scheduler();
}

/* Model initialize function */
void balanceLQR_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)balanceLQR_M, 0,
                sizeof(RT_MODEL_balanceLQR_T));

  /* block I/O */
  (void) memset(((void *) &balanceLQR_B), 0,
                sizeof(B_balanceLQR_T));

  /* states (dwork) */
  (void) memset((void *)&balanceLQR_DW, 0,
                sizeof(DW_balanceLQR_T));

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay1' */
  balanceLQR_DW.UnitDelay1_DSTATE = balanceLQR_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
  balanceLQR_DW.UnitDelay_DSTATE = balanceLQR_P.UnitDelay_InitialCondition;

  /* Level2 S-Function Block: '<S2>/Digital Input' (stm32f4_digital_input) */
  enable_EncodersDigitalInput();

  /* Level2 S-Function Block: '<S2>/Quadratur Encoder' (waijung_basic_customcode) */
  enable_EncodersQuadraturEncoder();

  /* Level2 S-Function Block: '<Root>/Basic PWM' (stm32f4_basicpwm) */
  enable_BasicPWM();

  /* Level2 S-Function Block: '<Root>/Digital Output' (stm32f4_digital_output) */
  enable_DigitalOutput();

  /* Level2 S-Function Block: '<Root>/UART Tx' (stm32f4_usart) */
  enable_UARTTx();

  /* Level2 S-Function Block: '<Root>/UART Setup' (stm32f4_usart) */
  enable_UARTSetup();
}

/* Model terminate function */
void balanceLQR_terminate(void)
{
  /* Terminate for S-Function (stm32f4_digital_input): '<S2>/Digital Input' */

  /* terminate_EncodersDigitalInput(); */

  /* Terminate for S-Function (stm32f4_basicpwm): '<Root>/Basic PWM' */

  /* terminate_BasicPWM(); */

  /* Terminate for S-Function (stm32f4_digital_output): '<Root>/Digital Output' */

  /* terminate_DigitalOutput(); */

  /* Terminate for S-Function (stm32f4_usart): '<Root>/UART Tx' */

  /* terminate_UARTTx(); */

  /* Terminate for S-Function (stm32f4_usart): '<Root>/UART Setup' */

  /* terminate_UARTSetup(); */
}

/* [EOF] */
