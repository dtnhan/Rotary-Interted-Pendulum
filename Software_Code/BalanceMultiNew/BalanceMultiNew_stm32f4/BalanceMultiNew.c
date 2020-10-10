/*
 * File: BalanceMultiNew.c
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

/* Block signals (auto storage) */
B_BalanceMultiNew_T BalanceMultiNew_B;

/* Block states (auto storage) */
DW_BalanceMultiNew_T BalanceMultiNew_DW;

/* Real-time model */
RT_MODEL_BalanceMultiNew_T BalanceMultiNew_M_;
RT_MODEL_BalanceMultiNew_T *const BalanceMultiNew_M = &BalanceMultiNew_M_;

/*
 * Output and update for action system:
 *    '<S17>/Action: u1'
 *    '<S53>/Action: u1'
 */
void BalanceMultiNew_Actionu1(real_T rtu_0, real_T *rty_u2)
{
  /* Inport: '<S26>/u1' */
  *rty_u2 = rtu_0;
}

/*
 * Output and update for action system:
 *    '<S27>/If Action Subsystem3'
 *    '<S28>/If Action Subsystem3'
 *    '<S29>/If Action Subsystem3'
 *    '<S30>/If Action Subsystem3'
 *    '<S31>/If Action Subsystem3'
 *    '<S142>/If Action Subsystem3'
 *    '<S143>/If Action Subsystem3'
 *    '<S144>/If Action Subsystem3'
 *    '<S157>/If Action Subsystem3'
 *    '<S158>/If Action Subsystem3'
 *    ...
 */
void BalanceMulti_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem3_BalanceM_T *localP)
{
  /* Product: '<S35>/Product ab (trimf)' incorporates:
   *  Constant: '<S35>/a'
   *  Constant: '<S35>/b'
   *  Sum: '<S35>/Sum'
   *  Sum: '<S35>/Sum1'
   */
  *rty_Out1 = (rtu_x - localP->a_Value) / (localP->b_Value - localP->a_Value);
}

/*
 * Output and update for action system:
 *    '<S27>/If Action Subsystem2'
 *    '<S28>/If Action Subsystem2'
 *    '<S29>/If Action Subsystem2'
 *    '<S30>/If Action Subsystem2'
 *    '<S31>/If Action Subsystem2'
 *    '<S142>/If Action Subsystem2'
 *    '<S143>/If Action Subsystem2'
 *    '<S144>/If Action Subsystem2'
 *    '<S157>/If Action Subsystem2'
 *    '<S158>/If Action Subsystem2'
 *    ...
 */
void BalanceMulti_IfActionSubsystem2(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem2_BalanceM_T *localP)
{
  /* Product: '<S34>/Product cd (trimf)' incorporates:
   *  Constant: '<S34>/b'
   *  Constant: '<S34>/c'
   *  Sum: '<S34>/Sum2'
   *  Sum: '<S34>/Sum3'
   */
  *rty_Out1 = 1.0 / (localP->c_Value - localP->b_Value) * (localP->c_Value -
    rtu_x);
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

/* Model step function */
void BalanceMultiNew_step(void)
{
  /* local block i/o variables */
  real_T rtb_LQRController1;
  real_T rtb_LQRController2;
  real_T rtb_LQRController3;
  real_T rtb_LQRController4;
  real_T rtb_Merge;
  real_T rtb_Merge_i;
  real_T rtb_Merge_o;
  real_T rtb_Merge_j;
  real_T rtb_Merge_b;
  real_T rtb_Sum1_h;
  real_T rtb_Merge_oz;
  real_T rtb_Merge_h;
  real_T rtb_Merge_n;
  real_T rtb_Merge_f;
  real_T rtb_Merge_e;
  real_T rtb_Merge_n1;
  real_T rtb_Merge_g;
  real_T rtb_Merge_fo;
  real_T rtb_Merge_gj;
  real_T rtb_Merge_m;
  real_T rtb_Merge_gjy;
  real_T rtb_Merge_it;
  real_T rtb_Merge_nc;
  real_T rtb_TotalFiringStrength_f;
  real_T rtb_Merge_a;
  real_T rtb_y;
  real_T minV[101];
  real_T minV_0[101];
  real_T minV_1[101];
  real_T thetadisplay;
  real_T r;
  boolean_T rtb_DataTypeConversion7;
  real_T rtb_Gain1;
  real_T rtb_DataTypeConversion1_a;
  real_T rtb_Gain;
  real_T rtb_Weighting_gx;
  real_T rtb_Weighting_gd;
  real_T rtb_Switch1;
  real_T rtb_Weighting_a;
  real_T rtb_Weighting_d;
  real_T rtb_Weighting_ah;
  real_T rtb_Weighting_m;
  real_T rtb_Weighting_o;
  real_T rtb_Weighting_b;
  real_T rtb_Weighting_f;
  real_T rtb_Weighting_mt;
  real_T rtb_Weighting_me;
  real_T rtb_Weighting_l1;
  real_T rtb_Weighting_fh;
  real_T rtb_Weighting_o2;
  real_T rtb_Weighting_aw;
  real_T rtb_Weighting_h;
  real_T rtb_Weighting_o2m;
  real_T rtb_Weighting_ow;
  real_T rtb_Weighting_lb;
  real_T rtb_Weighting_hl;
  real_T rtb_Weighting_c;
  real_T rtb_Weighting_ac;
  real_T rtb_Weighting_ai;
  real_T rtb_Weighting_ec;
  real_T rtb_Weighting_bq;
  real_T rtb_Weighting_on;
  real_T rtb_Weighting_od;
  real_T rtb_Weighting_f5;
  real_T rtb_Weighting_j;
  real_T rtb_Weighting_lp;
  real_T rtb_Weighting_lo;
  real_T rtb_Weighting_hr;
  real_T rtb_Weighting_ol;
  real_T rtb_Weighting_i;
  real_T rtb_Weighting_bz;
  real_T rtb_Weighting_ka;
  real_T rtb_Weighting_ja;
  real_T rtb_Weighting_n;
  real_T rtb_Weighting_e0;
  real_T rtb_Weighting_p;
  real_T rtb_Weighting_lv;
  real_T rtb_Weighting_jw;
  real_T rtb_Weighting_fz;
  real_T rtb_Weighting_hs;
  real_T rtb_Weighting_mv;
  real_T rtb_Weighting_kn;
  real_T rtb_Weighting_bg;
  real_T rtb_Weighting_bt;
  real_T rtb_Weighting_ou;
  real_T rtb_Weighting_ny;
  real_T rtb_Weighting_hq;
  real_T rtb_Weighting_lvs;
  real_T rtb_Weighting_a5;
  real_T rtb_Weighting_g;
  real_T rtb_Weighting_ft;
  real_T rtb_Weighting_jb;
  real_T rtb_Weighting_ih;
  real_T rtb_Weighting_dt;
  real_T rtb_Weighting_pp;
  real_T rtb_Weighting_mm;
  real_T rtb_Weighting_cx;
  real_T rtb_Weighting_bo;
  real_T rtb_Weighting_nv;
  real_T rtb_Weighting_lc;
  real_T rtb_Weighting_dy;
  real_T rtb_Weighting_ppe;
  real_T rtb_Weighting_h4;
  real_T rtb_Weighting_ppm;
  real_T rtb_Weighting_nw;
  real_T rtb_Weighting_pa;
  real_T rtb_Weighting_kan;
  real_T rtb_Weighting_k0;
  real_T rtb_Weighting_jx;
  real_T rtb_Weighting_j5;
  real_T rtb_Weighting_mk;
  real_T rtb_Weighting_o3;
  real_T rtb_Weighting_mw;
  real_T rtb_Weighting_n5;
  real_T rtb_alphadisplay;
  int32_T rtb_sw;
  real_T rtb_u_m;
  real_T rtb_u;
  real_T rtb_u_p;
  real_T rtb_ProductCOA[101];
  real_T rtb_Sum_g;
  real_T tmpForInput[81];
  int32_T i;
  real_T rtb_LQRController_0;

  /* S-Function (stm32f4_usart): '<Root>/UART Rx' */

  /* UARTRx */
  UARTRxNonBlockingRead(UART1_Temp_Buffer);
  BalanceMultiNew_B.UARTRx_o1 = UARTRx_packet_info.data_ready;
  if (UARTRx_packet_info.data_ready) {
    BalanceMultiNew_B.UARTRx_o2 = UARTRx_data0;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion7' */
  rtb_DataTypeConversion7 = (BalanceMultiNew_B.UARTRx_o2 != 0);

  /* S-Function (stm32f4_usart): '<Root>/UART Rx3' */

  /* UARTRx3 */
  UARTRx3NonBlockingRead(UART1_Temp_Buffer);
  BalanceMultiNew_B.UARTRx3_o1 = UARTRx3_packet_info.data_ready;
  if (UARTRx3_packet_info.data_ready) {
    BalanceMultiNew_B.UARTRx3_o2 = UARTRx3_data0;
  }

  /* S-Function (stm32f4_digital_input): '<S3>/Digital Input' */
  BalanceMultiNew_B.DigitalInput = *EncodersDigitalInput_A0;

  /* S-Function (waijung_basic_customcode): '<S3>/Quadratur Encoder' */

  /*
   * Custom Code Block Output Function
   * Block: <S3>/Quadratur Encoder
   * BlockID: EncodersQuadraturEncoder
   * Input Port Definitions
   * in1: Port label 'inalpha', Type: boolean_T
   * in2: Port label 'intheta', Type: boolean_T
   * Output Port Definitions
   * out1: Port label 'alpha', Type: int32_T
   * out2: Port label ' theta', Type: int32_T
   */
  output_EncodersQuadraturEncoder(BalanceMultiNew_B.DigitalInput,
    BalanceMultiNew_B.DigitalInput , &BalanceMultiNew_B.QuadraturEncoder_o1,
    &BalanceMultiNew_B.QuadraturEncoder_o2);

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  /* MATLAB Function 'Encoders/MATLAB Function': '<S10>:1' */
  /* '<S10>:1:3' */
  rtb_u_m = (real_T)BalanceMultiNew_B.QuadraturEncoder_o1 * 2.0 *
    3.1415926535897931;

  /* '<S10>:1:4' */
  rtb_Weighting_gd = ((rtb_u_m / 4096.0 + 3.1415926535897931) -
                      3.1415926535897931) / 6.2831853071795862;
  if (fabs(rtb_Weighting_gd - rt_roundd_snf(rtb_Weighting_gd)) <=
      2.2204460492503131E-16 * fabs(rtb_Weighting_gd)) {
    rtb_Weighting_gd = 0.0;
  } else {
    rtb_Weighting_gd = (rtb_Weighting_gd - floor(rtb_Weighting_gd)) *
      6.2831853071795862;
  }

  rtb_alphadisplay = rtb_u_m / 4096.0 + 3.1415926535897931;

  /* Gain: '<S3>/Gain1' incorporates:
   *  Sum: '<S3>/Sum1'
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  rtb_Gain1 = (rtb_alphadisplay - BalanceMultiNew_DW.UnitDelay1_DSTATE) *
    BalanceMultiNew_P.Gain1_Gain;

  /* MATLAB Function: '<S6>/EnergySWINGUP' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  /* MATLAB Function 'Subsystem/EnergySWINGUP': '<S203>:1' */
  /* #************************ */
  /* energy based control */
  /* #***********************88 */
  /* if (alpha>0.6)||(alpha<-0.6) */
  /* '<S203>:1:7' */
  if (cos(rtb_Weighting_gd - 3.1415926535897931) * rtb_Gain1 < 0.0) {
    /* '<S203>:1:8' */
    /* '<S203>:1:9' */
    rtb_u_m = -3.5;

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
    /* '<S203>:1:31' */
    rtb_u_m = 3.5;
  }

  /* End of MATLAB Function: '<S6>/EnergySWINGUP' */

  /* MATLAB Function: '<S6>/SWINGUP' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  /* else u=0; */
  /*  if u >=24 */
  /*      u = 24; */
  /*  end */
  /*  if u <= -24 */
  /*      u = -24; */
  /*  end -10.0000   53.5434   -4.9882    7.4922 */
  /* MATLAB Function 'Subsystem/SWINGUP': '<S205>:1' */
  /* #************************ */
  /* energy based control */
  /* #***********************88 */
  /* if (alpha>0.6)||(alpha<-0.6) */
  /* '<S205>:1:7' */
  /*  if (alphadot*cos(alpha))<0 */
  /*      u=-voltage; */
  /*  % % % % % elseif (alphadot*cos(alpha))>0 */
  /*  % % % % %     u=voltage; */
  /*  if(q1>pi)&&(q1<2*pi) */
  /*      q1=q1-2*pi; */
  /*  if(abs(q2)<pi/2) */
  /*  if((alpha>=pi)&&(alpha<3*pi/2)&&(alphadot<=0)) */
  /*      u=20; */
  /*  elseif ((alpha<pi)&&(alpha>pi/2)&&(alphadot>0)) */
  /*      u=-20; */
  if ((rtb_Weighting_gd - 3.1415926535897931 >= -3.1415926535897931) &&
      (rtb_Weighting_gd - 3.1415926535897931 < -1.5707963267948966) &&
      (rtb_Gain1 <= 0.0)) {
    /* '<S205>:1:19' */
    /* '<S205>:1:20' */
    rtb_u = 7.5;
  } else if ((rtb_Weighting_gd - 3.1415926535897931 < 3.1415926535897931) &&
             (rtb_Weighting_gd - 3.1415926535897931 > 1.5707963267948966) &&
             (rtb_Gain1 > 0.0)) {
    /* '<S205>:1:21' */
    /* '<S205>:1:22' */
    rtb_u = -7.5;

    /*  elseif ((abs(q1)< pi/18)) */
    /*      u = -(q2*(-10)+ q1*(53.5434) + q2dot*(-4.9882) + q1dot*(7.4922)); */
    /*  else */
    /*      u = 0; */
    /*  end */
    /*  elseif(q2>pi) */
    /*      u=-3; */
  } else {
    /* '<S205>:1:31' */
    rtb_u = 0.0;
  }

  /* End of MATLAB Function: '<S6>/SWINGUP' */

  /* MATLAB Function: '<S6>/EnergySWINGUP1' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  /* else u=0; */
  /* end */
  /*  if u >=24 */
  /*      u = 24; */
  /*  end */
  /*  if u <= -24 */
  /*      u = -24; */
  /*  end -10.0000   53.5434   -4.9882    7.4922 */
  /* MATLAB Function 'Subsystem/EnergySWINGUP1': '<S204>:1' */
  /* #************************ */
  /* energy based control */
  /* #***********************88 */
  /* if (alpha>0.6)||(alpha<-0.6) */
  /* '<S204>:1:7' */
  if (cos(rtb_Weighting_gd - 3.1415926535897931) * rtb_Gain1 < 0.0) {
    /* '<S204>:1:8' */
    /* '<S204>:1:9' */
    rtb_u_p = -5.0;

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
    /* '<S204>:1:31' */
    rtb_u_p = 5.0;
  }

  /* End of MATLAB Function: '<S6>/EnergySWINGUP1' */

  /* MATLAB Function: '<S6>/Choose_Swing' */
  /* else u=0; */
  /*  if u >=24 */
  /*      u = 24; */
  /*  end */
  /*  if u <= -24 */
  /*      u = -24; */
  /*  end -10.0000   53.5434   -4.9882    7.4922 */
  /* MATLAB Function 'Subsystem/Choose_Swing': '<S202>:1' */
  if (BalanceMultiNew_B.UARTRx3_o2 == 0) {
    /* '<S202>:1:4' */
    /* '<S202>:1:5' */
    rtb_u_p = rtb_u_m;
  } else if (BalanceMultiNew_B.UARTRx3_o2 == 1) {
    /* '<S202>:1:6' */
    /* '<S202>:1:7' */
    rtb_u_p = rtb_u;
  } else {
    /* '<S202>:1:8' */
  }

  /* End of MATLAB Function: '<S6>/Choose_Swing' */

  /* MATLAB Function: '<Root>/Switch_Funciton' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  /* MATLAB Function 'Switch_Funciton': '<S7>:1' */
  if ((rtb_Weighting_gd - 3.1415926535897931 < 0.5) && (rtb_Weighting_gd -
       3.1415926535897931 > -0.5)) {
    /* '<S7>:1:2' */
    /* '<S7>:1:3' */
    rtb_sw = 0;
  } else {
    /* '<S7>:1:5' */
    rtb_sw = 1;
  }

  /* End of MATLAB Function: '<Root>/Switch_Funciton' */

  /* S-Function (stm32f4_usart): '<Root>/UART Rx2' */

  /* UARTRx2 */
  UARTRx2NonBlockingRead(UART1_Temp_Buffer);
  BalanceMultiNew_B.UARTRx2_o1 = UARTRx2_packet_info.data_ready;
  if (UARTRx2_packet_info.data_ready) {
    BalanceMultiNew_B.UARTRx2_o2 = UARTRx2_data0;
  }

  /* MATLAB Function: '<S3>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion1'
   */
  /* MATLAB Function 'Encoders/MATLAB Function1': '<S11>:1' */
  /* '<S11>:1:3' */
  thetadisplay = (real_T)BalanceMultiNew_B.QuadraturEncoder_o2 * 2.0 *
    3.1415926535897931 / 4000.0;

  /* '<S11>:1:4' */
  r = (thetadisplay + 3.1415926535897931) / 6.2831853071795862;
  if (fabs(r - rt_roundd_snf(r)) <= 2.2204460492503131E-16 * fabs(r)) {
    r = 0.0;
  } else {
    r = (r - floor(r)) * 6.2831853071795862;
  }

  /* S-Function (stm32f4_usart): '<Root>/UART Rx1' */

  /* UARTRx1 */
  UARTRx1NonBlockingRead(UART1_Temp_Buffer);
  BalanceMultiNew_B.UARTRx1_o1 = UARTRx1_packet_info.data_ready;
  if (UARTRx1_packet_info.data_ready) {
    BalanceMultiNew_B.UARTRx1_o2 = UARTRx1_data0;
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_DataTypeConversion1_a = BalanceMultiNew_B.UARTRx1_o2;

  /* Sum: '<Root>/Add' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  MATLAB Function: '<S3>/MATLAB Function1'
   */
  rtb_Weighting_gx = (r - 3.1415926535897931) - BalanceMultiNew_B.UARTRx1_o2;

  /* Gain: '<S3>/Gain' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function1'
   *  Sum: '<S3>/Sum'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtb_Gain = (thetadisplay - BalanceMultiNew_DW.UnitDelay_DSTATE) *
    BalanceMultiNew_P.Gain_Gain;

  /* Gain: '<S5>/LQR Controller' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   *  SignalConversion: '<S5>/TmpSignal ConversionAtLQR ControllerInport1'
   */
  rtb_LQRController_0 = (((rtb_Weighting_gd - 3.1415926535897931) *
    BalanceMultiNew_P.LQRController_Gain[0] +
    BalanceMultiNew_P.LQRController_Gain[1] * rtb_Gain1) +
    BalanceMultiNew_P.LQRController_Gain[2] * rtb_Weighting_gx) +
    BalanceMultiNew_P.LQRController_Gain[3] * rtb_Gain;

  /* Gain: '<S5>/LQR Controller1' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function'
   */
  rtb_LQRController1 = (rtb_Weighting_gd - 3.1415926535897931) *
    BalanceMultiNew_P.LQRController1_Gain;

  /* Gain: '<S5>/LQR Controller2' */
  rtb_LQRController2 = BalanceMultiNew_P.LQRController2_Gain * rtb_Gain1;

  /* Gain: '<S5>/LQR Controller3' */
  rtb_LQRController3 = BalanceMultiNew_P.LQRController3_Gain * rtb_Weighting_gx;

  /* Gain: '<S5>/LQR Controller4' */
  rtb_LQRController4 = BalanceMultiNew_P.LQRController4_Gain * rtb_Gain;

  /* MATLAB Function: '<S5>/MATLAB Function1' */
  /* MATLAB Function 'Multi_Controllers/MATLAB Function1': '<S15>:1' */
  /* '<S15>:1:6' */
  rtb_y = (((rtb_LQRController1 + rtb_LQRController2) + rtb_LQRController3) +
           rtb_LQRController4) / 2.0;

  /* If: '<S27>/If' incorporates:
   *  Constant: '<S32>/0'
   *  Constant: '<S33>/0'
   */
  if ((rtb_y < -1.5) || (rtb_y > -0.5)) {
    /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem' incorporates:
     *  ActionPort: '<S32>/Action Port'
     */
    rtb_Merge = BalanceMultiNew_P._Value;

    /* End of Outputs for SubSystem: '<S27>/If Action Subsystem' */
  } else if (rtb_y == -1.0) {
    /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    rtb_Merge = BalanceMultiNew_P._Value_e;

    /* End of Outputs for SubSystem: '<S27>/If Action Subsystem1' */
  } else if (rtb_y < -1.0) {
    /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_y, &rtb_Merge,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S27>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_y, &rtb_Merge,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S27>/If Action Subsystem2' */
  }

  /* End of If: '<S27>/If' */

  /* Product: '<S18>/Weighting' incorporates:
   *  Constant: '<S18>/Weight'
   */
  rtb_Weighting_gx = BalanceMultiNew_P.Weight_Value * rtb_Merge;

  /* MinMax: '<S18>/impMethod' incorporates:
   *  Constant: '<S24>/mf1'
   */
  for (i = 0; i < 101; i++) {
    if ((rtb_Weighting_gx <= BalanceMultiNew_P.mf1_Value[i]) || rtIsNaN
        (BalanceMultiNew_P.mf1_Value[i])) {
      rtb_ProductCOA[i] = rtb_Weighting_gx;
    } else {
      rtb_ProductCOA[i] = BalanceMultiNew_P.mf1_Value[i];
    }
  }

  /* If: '<S28>/If' incorporates:
   *  Constant: '<S36>/0'
   *  Constant: '<S37>/0'
   */
  if ((rtb_y < -1.0) || (rtb_y > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S28>/If Action Subsystem' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    rtb_Merge_i = BalanceMultiNew_P._Value_h;

    /* End of Outputs for SubSystem: '<S28>/If Action Subsystem' */
  } else if (rtb_y == -0.5) {
    /* Outputs for IfAction SubSystem: '<S28>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S37>/Action Port'
     */
    rtb_Merge_i = BalanceMultiNew_P._Value_p;

    /* End of Outputs for SubSystem: '<S28>/If Action Subsystem1' */
  } else if (rtb_y < -0.5) {
    /* Outputs for IfAction SubSystem: '<S28>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S39>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_y, &rtb_Merge_i,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3_d);

    /* End of Outputs for SubSystem: '<S28>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S28>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S38>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_y, &rtb_Merge_i,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2_o);

    /* End of Outputs for SubSystem: '<S28>/If Action Subsystem2' */
  }

  /* End of If: '<S28>/If' */

  /* Product: '<S19>/Weighting' incorporates:
   *  Constant: '<S19>/Weight'
   */
  rtb_u_m = BalanceMultiNew_P.Weight_Value_c * rtb_Merge_i;

  /* MinMax: '<S19>/impMethod' incorporates:
   *  Constant: '<S24>/mf2'
   */
  for (i = 0; i < 101; i++) {
    if ((rtb_u_m <= BalanceMultiNew_P.mf2_Value[i]) || rtIsNaN
        (BalanceMultiNew_P.mf2_Value[i])) {
      minV[i] = rtb_u_m;
    } else {
      minV[i] = BalanceMultiNew_P.mf2_Value[i];
    }
  }

  /* If: '<S29>/If' incorporates:
   *  Constant: '<S40>/0'
   *  Constant: '<S41>/0'
   */
  if ((rtb_y < -0.5) || (rtb_y > 0.5)) {
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem' incorporates:
     *  ActionPort: '<S40>/Action Port'
     */
    rtb_Merge_o = BalanceMultiNew_P._Value_d;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem' */
  } else if (rtb_y == 0.0) {
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    rtb_Merge_o = BalanceMultiNew_P._Value_dj;

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem1' */
  } else if (rtb_y < 0.0) {
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S43>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_y, &rtb_Merge_o,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3_i);

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S29>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_y, &rtb_Merge_o,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2_h);

    /* End of Outputs for SubSystem: '<S29>/If Action Subsystem2' */
  }

  /* End of If: '<S29>/If' */

  /* Product: '<S20>/Weighting' incorporates:
   *  Constant: '<S20>/Weight'
   */
  rtb_u = BalanceMultiNew_P.Weight_Value_h * rtb_Merge_o;

  /* MinMax: '<S20>/impMethod' incorporates:
   *  Constant: '<S24>/mf3'
   */
  for (i = 0; i < 101; i++) {
    if ((rtb_u <= BalanceMultiNew_P.mf3_Value[i]) || rtIsNaN
        (BalanceMultiNew_P.mf3_Value[i])) {
      minV_0[i] = rtb_u;
    } else {
      minV_0[i] = BalanceMultiNew_P.mf3_Value[i];
    }
  }

  /* If: '<S30>/If' incorporates:
   *  Constant: '<S44>/0'
   *  Constant: '<S45>/0'
   */
  if ((rtb_y < 0.0) || (rtb_y > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem' incorporates:
     *  ActionPort: '<S44>/Action Port'
     */
    rtb_Merge_j = BalanceMultiNew_P._Value_g;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem' */
  } else if (rtb_y == 0.5) {
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S45>/Action Port'
     */
    rtb_Merge_j = BalanceMultiNew_P._Value_f;

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem1' */
  } else if (rtb_y < 0.5) {
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S47>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_y, &rtb_Merge_j,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3_g);

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S46>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_y, &rtb_Merge_j,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2_p);

    /* End of Outputs for SubSystem: '<S30>/If Action Subsystem2' */
  }

  /* End of If: '<S30>/If' */

  /* Product: '<S21>/Weighting' incorporates:
   *  Constant: '<S21>/Weight'
   */
  rtb_Weighting_gd = BalanceMultiNew_P.Weight_Value_cs * rtb_Merge_j;

  /* MinMax: '<S21>/impMethod' incorporates:
   *  Constant: '<S24>/mf4'
   */
  for (i = 0; i < 101; i++) {
    if ((rtb_Weighting_gd <= BalanceMultiNew_P.mf4_Value[i]) || rtIsNaN
        (BalanceMultiNew_P.mf4_Value[i])) {
      minV_1[i] = rtb_Weighting_gd;
    } else {
      minV_1[i] = BalanceMultiNew_P.mf4_Value[i];
    }
  }

  /* If: '<S31>/If' incorporates:
   *  Constant: '<S48>/0'
   *  Constant: '<S49>/0'
   */
  if ((rtb_y < 0.5) || (rtb_y > 1.5)) {
    /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */
    rtb_Merge_b = BalanceMultiNew_P._Value_l;

    /* End of Outputs for SubSystem: '<S31>/If Action Subsystem' */
  } else if (rtb_y == 1.0) {
    /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S49>/Action Port'
     */
    rtb_Merge_b = BalanceMultiNew_P._Value_b;

    /* End of Outputs for SubSystem: '<S31>/If Action Subsystem1' */
  } else if (rtb_y < 1.0) {
    /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_y, &rtb_Merge_b,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3_b);

    /* End of Outputs for SubSystem: '<S31>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S31>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_y, &rtb_Merge_b,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2_c);

    /* End of Outputs for SubSystem: '<S31>/If Action Subsystem2' */
  }

  /* End of If: '<S31>/If' */

  /* Product: '<S22>/Weighting' incorporates:
   *  Constant: '<S22>/Weight'
   */
  rtb_Switch1 = BalanceMultiNew_P.Weight_Value_g * rtb_Merge_b;

  /* MinMax: '<S16>/AggMethod1' incorporates:
   *  Constant: '<S24>/mf5'
   *  MinMax: '<S18>/impMethod'
   *  MinMax: '<S19>/impMethod'
   *  MinMax: '<S20>/impMethod'
   *  MinMax: '<S21>/impMethod'
   *  MinMax: '<S22>/impMethod'
   */
  for (i = 0; i < 101; i++) {
    if ((rtb_ProductCOA[i] >= minV[i]) || rtIsNaN(minV[i])) {
      rtb_Sum_g = rtb_ProductCOA[i];
    } else {
      rtb_Sum_g = minV[i];
    }

    if (!((rtb_Sum_g >= minV_0[i]) || rtIsNaN(minV_0[i]))) {
      rtb_Sum_g = minV_0[i];
    }

    if (!((rtb_Sum_g >= minV_1[i]) || rtIsNaN(minV_1[i]))) {
      rtb_Sum_g = minV_1[i];
    }

    if ((rtb_Switch1 <= BalanceMultiNew_P.mf5_Value[i]) || rtIsNaN
        (BalanceMultiNew_P.mf5_Value[i])) {
      rtb_Weighting_d = rtb_Switch1;
    } else {
      rtb_Weighting_d = BalanceMultiNew_P.mf5_Value[i];
    }

    if ((rtb_Sum_g >= rtb_Weighting_d) || rtIsNaN(rtb_Weighting_d)) {
      rtb_Weighting_d = rtb_Sum_g;
    }

    rtb_ProductCOA[i] = rtb_Weighting_d;
  }

  /* Sum: '<S17>/Sum1' incorporates:
   *  MinMax: '<S16>/AggMethod1'
   */
  rtb_Weighting_a = rtb_ProductCOA[0];
  for (i = 0; i < 100; i++) {
    rtb_Weighting_a += rtb_ProductCOA[i + 1];
  }

  rtb_Sum1_h = rtb_Weighting_a;

  /* End of Sum: '<S17>/Sum1' */

  /* If: '<S17>/If' incorporates:
   *  Constant: '<S25>/One'
   */
  if (rtb_Sum1_h <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S17>/Action: One' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    rtb_Merge_oz = BalanceMultiNew_P.One_Value;

    /* End of Outputs for SubSystem: '<S17>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S17>/Action: u1' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    BalanceMultiNew_Actionu1(rtb_Sum1_h, &rtb_Merge_oz);

    /* End of Outputs for SubSystem: '<S17>/Action: u1' */
  }

  /* End of If: '<S17>/If' */

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/MidRange'
   *  Constant: '<S16>/Zero'
   *  Product: '<S17>/Averaging (COA)'
   *  RelationalOperator: '<S16>/Zero Firing Strength?'
   *  Sum: '<S16>/Total Firing Strength'
   */
  if (((((rtb_Weighting_gx + rtb_u_m) + rtb_u) + rtb_Weighting_gd) + rtb_Switch1
       > BalanceMultiNew_P.Zero_Value) >= BalanceMultiNew_P.Switch_Threshold) {
    /* Product: '<S17>/Product (COA)' incorporates:
     *  Constant: '<S17>/x data'
     *  MinMax: '<S16>/AggMethod1'
     */
    for (i = 0; i < 101; i++) {
      rtb_ProductCOA[i] *= BalanceMultiNew_P.xdata_Value[i];
    }

    /* End of Product: '<S17>/Product (COA)' */

    /* Sum: '<S17>/Sum' */
    rtb_Sum_g = rtb_ProductCOA[0];
    for (i = 0; i < 100; i++) {
      rtb_Sum_g += rtb_ProductCOA[i + 1];
    }

    /* End of Sum: '<S17>/Sum' */
    rtb_Switch1 = rtb_Sum_g / rtb_Merge_oz;
  } else {
    rtb_Switch1 = BalanceMultiNew_P.MidRange_Value;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Gain: '<S5>/FuzzyGain' */
  rtb_Weighting_gd = BalanceMultiNew_P.FuzzyGain_Gain * rtb_Switch1;

  /* If: '<S142>/If' incorporates:
   *  Constant: '<S145>/0'
   *  Constant: '<S146>/0'
   */
  if ((rtb_LQRController1 < -2.0) || (rtb_LQRController1 > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S142>/If Action Subsystem' incorporates:
     *  ActionPort: '<S145>/Action Port'
     */
    rtb_Merge_h = BalanceMultiNew_P._Value_a;

    /* End of Outputs for SubSystem: '<S142>/If Action Subsystem' */
  } else if (rtb_LQRController1 == -1.0) {
    /* Outputs for IfAction SubSystem: '<S142>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S146>/Action Port'
     */
    rtb_Merge_h = BalanceMultiNew_P._Value_j;

    /* End of Outputs for SubSystem: '<S142>/If Action Subsystem1' */
  } else if (rtb_LQRController1 < -1.0) {
    /* Outputs for IfAction SubSystem: '<S142>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S148>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController1, &rtb_Merge_h,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3_f);

    /* End of Outputs for SubSystem: '<S142>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S142>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S147>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController1, &rtb_Merge_h,
      (P_IfActionSubsystem2_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem2_pn);

    /* End of Outputs for SubSystem: '<S142>/If Action Subsystem2' */
  }

  /* End of If: '<S142>/If' */

  /* If: '<S157>/If' incorporates:
   *  Constant: '<S160>/0'
   *  Constant: '<S161>/0'
   */
  if ((rtb_LQRController2 < -5.0) || (rtb_LQRController2 > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S157>/If Action Subsystem' incorporates:
     *  ActionPort: '<S160>/Action Port'
     */
    rtb_Merge_n = BalanceMultiNew_P._Value_hk;

    /* End of Outputs for SubSystem: '<S157>/If Action Subsystem' */
  } else if (rtb_LQRController2 == -1.0) {
    /* Outputs for IfAction SubSystem: '<S157>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S161>/Action Port'
     */
    rtb_Merge_n = BalanceMultiNew_P._Value_ez;

    /* End of Outputs for SubSystem: '<S157>/If Action Subsystem1' */
  } else if (rtb_LQRController2 < -1.0) {
    /* Outputs for IfAction SubSystem: '<S157>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S163>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController2, &rtb_Merge_n,
      (P_IfActionSubsystem3_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem3_dr);

    /* End of Outputs for SubSystem: '<S157>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S157>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S162>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController2, &rtb_Merge_n,
      (P_IfActionSubsystem2_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem2_oi);

    /* End of Outputs for SubSystem: '<S157>/If Action Subsystem2' */
  }

  /* End of If: '<S157>/If' */

  /* If: '<S172>/If' incorporates:
   *  Constant: '<S175>/0'
   *  Constant: '<S176>/0'
   */
  if ((rtb_LQRController4 < -5.0) || (rtb_LQRController4 > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S172>/If Action Subsystem' incorporates:
     *  ActionPort: '<S175>/Action Port'
     */
    rtb_Merge_f = BalanceMultiNew_P._Value_n;

    /* End of Outputs for SubSystem: '<S172>/If Action Subsystem' */
  } else if (rtb_LQRController4 == -1.0) {
    /* Outputs for IfAction SubSystem: '<S172>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S176>/Action Port'
     */
    rtb_Merge_f = BalanceMultiNew_P._Value_cn;

    /* End of Outputs for SubSystem: '<S172>/If Action Subsystem1' */
  } else if (rtb_LQRController4 < -1.0) {
    /* Outputs for IfAction SubSystem: '<S172>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S178>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController4, &rtb_Merge_f,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3_e);

    /* End of Outputs for SubSystem: '<S172>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S172>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S177>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController4, &rtb_Merge_f,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2_j);

    /* End of Outputs for SubSystem: '<S172>/If Action Subsystem2' */
  }

  /* End of If: '<S172>/If' */

  /* If: '<S187>/If' incorporates:
   *  Constant: '<S190>/0'
   *  Constant: '<S191>/0'
   */
  if ((rtb_LQRController3 < -4.0) || (rtb_LQRController3 > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S187>/If Action Subsystem' incorporates:
     *  ActionPort: '<S190>/Action Port'
     */
    rtb_Merge_e = BalanceMultiNew_P._Value_i;

    /* End of Outputs for SubSystem: '<S187>/If Action Subsystem' */
  } else if (rtb_LQRController3 == -1.0) {
    /* Outputs for IfAction SubSystem: '<S187>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S191>/Action Port'
     */
    rtb_Merge_e = BalanceMultiNew_P._Value_ac;

    /* End of Outputs for SubSystem: '<S187>/If Action Subsystem1' */
  } else if (rtb_LQRController3 < -1.0) {
    /* Outputs for IfAction SubSystem: '<S187>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S193>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController3, &rtb_Merge_e,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3_p);

    /* End of Outputs for SubSystem: '<S187>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S187>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S192>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController3, &rtb_Merge_e,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2_l);

    /* End of Outputs for SubSystem: '<S187>/If Action Subsystem2' */
  }

  /* End of If: '<S187>/If' */

  /* Product: '<S55>/Weighting' incorporates:
   *  Constant: '<S55>/Weight'
   *  Product: '<S55>/andorMethod'
   */
  rtb_u_m = rtb_Merge_h * rtb_Merge_n * rtb_Merge_e * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_j;

  /* If: '<S174>/If' incorporates:
   *  Constant: '<S183>/0'
   *  Constant: '<S184>/0'
   */
  if ((rtb_LQRController4 < -1.0) || (rtb_LQRController4 > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem' incorporates:
     *  ActionPort: '<S183>/Action Port'
     */
    rtb_Merge_n1 = BalanceMultiNew_P._Value_o;

    /* End of Outputs for SubSystem: '<S174>/If Action Subsystem' */
  } else if (rtb_LQRController4 == 0.0) {
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S184>/Action Port'
     */
    rtb_Merge_n1 = BalanceMultiNew_P._Value_df;

    /* End of Outputs for SubSystem: '<S174>/If Action Subsystem1' */
  } else if (rtb_LQRController4 < 0.0) {
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S186>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController4, &rtb_Merge_n1,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3_h);

    /* End of Outputs for SubSystem: '<S174>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S174>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S185>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController4, &rtb_Merge_n1,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2_e);

    /* End of Outputs for SubSystem: '<S174>/If Action Subsystem2' */
  }

  /* End of If: '<S174>/If' */

  /* Product: '<S66>/Weighting' incorporates:
   *  Constant: '<S66>/Weight'
   *  Product: '<S66>/andorMethod'
   */
  rtb_Weighting_a = rtb_Merge_h * rtb_Merge_n * rtb_Merge_e * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_b;

  /* If: '<S173>/If' incorporates:
   *  Constant: '<S179>/0'
   *  Constant: '<S180>/0'
   */
  if ((rtb_LQRController4 < 0.0) || (rtb_LQRController4 > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S173>/If Action Subsystem' incorporates:
     *  ActionPort: '<S179>/Action Port'
     */
    rtb_Merge_g = BalanceMultiNew_P._Value_fc;

    /* End of Outputs for SubSystem: '<S173>/If Action Subsystem' */
  } else if (rtb_LQRController4 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S173>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S180>/Action Port'
     */
    rtb_Merge_g = BalanceMultiNew_P._Value_c3;

    /* End of Outputs for SubSystem: '<S173>/If Action Subsystem1' */
  } else if (rtb_LQRController4 < 1.0) {
    /* Outputs for IfAction SubSystem: '<S173>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S182>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController4, &rtb_Merge_g,
      (P_IfActionSubsystem3_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem3_dn);

    /* End of Outputs for SubSystem: '<S173>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S173>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S181>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController4, &rtb_Merge_g,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2_k);

    /* End of Outputs for SubSystem: '<S173>/If Action Subsystem2' */
  }

  /* End of If: '<S173>/If' */

  /* Product: '<S77>/Weighting' incorporates:
   *  Constant: '<S77>/Weight'
   *  Product: '<S77>/andorMethod'
   */
  rtb_Weighting_gx = rtb_Merge_h * rtb_Merge_n * rtb_Merge_e * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_m;

  /* If: '<S189>/If' incorporates:
   *  Constant: '<S198>/0'
   *  Constant: '<S199>/0'
   */
  if ((rtb_LQRController3 < -1.0) || (rtb_LQRController3 > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S189>/If Action Subsystem' incorporates:
     *  ActionPort: '<S198>/Action Port'
     */
    rtb_Merge_fo = BalanceMultiNew_P._Value_nm;

    /* End of Outputs for SubSystem: '<S189>/If Action Subsystem' */
  } else if (rtb_LQRController3 == 0.0) {
    /* Outputs for IfAction SubSystem: '<S189>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S199>/Action Port'
     */
    rtb_Merge_fo = BalanceMultiNew_P._Value_os;

    /* End of Outputs for SubSystem: '<S189>/If Action Subsystem1' */
  } else if (rtb_LQRController3 < 0.0) {
    /* Outputs for IfAction SubSystem: '<S189>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S201>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController3, &rtb_Merge_fo,
      (P_IfActionSubsystem3_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem3_pe);

    /* End of Outputs for SubSystem: '<S189>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S189>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S200>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController3, &rtb_Merge_fo,
      (P_IfActionSubsystem2_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem2_cc);

    /* End of Outputs for SubSystem: '<S189>/If Action Subsystem2' */
  }

  /* End of If: '<S189>/If' */

  /* Product: '<S88>/Weighting' incorporates:
   *  Constant: '<S88>/Weight'
   *  Product: '<S88>/andorMethod'
   */
  rtb_Sum_g = rtb_Merge_h * rtb_Merge_n * rtb_Merge_fo * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_mv;

  /* Product: '<S99>/Weighting' incorporates:
   *  Constant: '<S99>/Weight'
   *  Product: '<S99>/andorMethod'
   */
  rtb_Weighting_d = rtb_Merge_h * rtb_Merge_n * rtb_Merge_fo * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_i;

  /* Product: '<S110>/Weighting' incorporates:
   *  Constant: '<S110>/Weight'
   *  Product: '<S110>/andorMethod'
   */
  rtb_Switch1 = rtb_Merge_h * rtb_Merge_n * rtb_Merge_fo * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_p;

  /* If: '<S188>/If' incorporates:
   *  Constant: '<S194>/0'
   *  Constant: '<S195>/0'
   */
  if ((rtb_LQRController3 < 0.0) || (rtb_LQRController3 > 3.0)) {
    /* Outputs for IfAction SubSystem: '<S188>/If Action Subsystem' incorporates:
     *  ActionPort: '<S194>/Action Port'
     */
    rtb_Merge_gj = BalanceMultiNew_P._Value_dv;

    /* End of Outputs for SubSystem: '<S188>/If Action Subsystem' */
  } else if (rtb_LQRController3 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S188>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S195>/Action Port'
     */
    rtb_Merge_gj = BalanceMultiNew_P._Value_is;

    /* End of Outputs for SubSystem: '<S188>/If Action Subsystem1' */
  } else if (rtb_LQRController3 < 1.0) {
    /* Outputs for IfAction SubSystem: '<S188>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S197>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController3, &rtb_Merge_gj,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3_o);

    /* End of Outputs for SubSystem: '<S188>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S188>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S196>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController3, &rtb_Merge_gj,
      (P_IfActionSubsystem2_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem2_ji);

    /* End of Outputs for SubSystem: '<S188>/If Action Subsystem2' */
  }

  /* End of If: '<S188>/If' */

  /* Product: '<S121>/Weighting' incorporates:
   *  Constant: '<S121>/Weight'
   *  Product: '<S121>/andorMethod'
   */
  rtb_Weighting_ah = rtb_Merge_h * rtb_Merge_n * rtb_Merge_gj * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_o;

  /* Product: '<S132>/Weighting' incorporates:
   *  Constant: '<S132>/Weight'
   *  Product: '<S132>/andorMethod'
   */
  rtb_Weighting_m = rtb_Merge_h * rtb_Merge_n * rtb_Merge_gj * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_jo;

  /* Product: '<S135>/Weighting' incorporates:
   *  Constant: '<S135>/Weight'
   *  Product: '<S135>/andorMethod'
   */
  rtb_Weighting_o = rtb_Merge_h * rtb_Merge_n * rtb_Merge_gj * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_l;

  /* If: '<S159>/If' incorporates:
   *  Constant: '<S168>/0'
   *  Constant: '<S169>/0'
   */
  if ((rtb_LQRController2 < -1.0) || (rtb_LQRController2 > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S159>/If Action Subsystem' incorporates:
     *  ActionPort: '<S168>/Action Port'
     */
    rtb_Merge_m = BalanceMultiNew_P._Value_c;

    /* End of Outputs for SubSystem: '<S159>/If Action Subsystem' */
  } else if (rtb_LQRController2 == 0.0) {
    /* Outputs for IfAction SubSystem: '<S159>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S169>/Action Port'
     */
    rtb_Merge_m = BalanceMultiNew_P._Value_bi;

    /* End of Outputs for SubSystem: '<S159>/If Action Subsystem1' */
  } else if (rtb_LQRController2 < 0.0) {
    /* Outputs for IfAction SubSystem: '<S159>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S171>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController2, &rtb_Merge_m,
      (P_IfActionSubsystem3_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem3_gn);

    /* End of Outputs for SubSystem: '<S159>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S159>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S170>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController2, &rtb_Merge_m,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2_g);

    /* End of Outputs for SubSystem: '<S159>/If Action Subsystem2' */
  }

  /* End of If: '<S159>/If' */

  /* Product: '<S56>/Weighting' incorporates:
   *  Constant: '<S56>/Weight'
   *  Product: '<S56>/andorMethod'
   */
  rtb_Weighting_b = rtb_Merge_h * rtb_Merge_m * rtb_Merge_e * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_pg;

  /* Product: '<S57>/Weighting' incorporates:
   *  Constant: '<S57>/Weight'
   *  Product: '<S57>/andorMethod'
   */
  rtb_Weighting_f = rtb_Merge_h * rtb_Merge_m * rtb_Merge_e * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_a;

  /* Product: '<S58>/Weighting' incorporates:
   *  Constant: '<S58>/Weight'
   *  Product: '<S58>/andorMethod'
   */
  rtb_Weighting_mt = rtb_Merge_h * rtb_Merge_m * rtb_Merge_e * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_jj;

  /* Product: '<S59>/Weighting' incorporates:
   *  Constant: '<S59>/Weight'
   *  Product: '<S59>/andorMethod'
   */
  rtb_Weighting_me = rtb_Merge_h * rtb_Merge_m * rtb_Merge_fo * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_ld;

  /* Product: '<S60>/Weighting' incorporates:
   *  Constant: '<S60>/Weight'
   *  Product: '<S60>/andorMethod'
   */
  rtb_Weighting_l1 = rtb_Merge_h * rtb_Merge_m * rtb_Merge_fo * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_pw;

  /* Product: '<S61>/Weighting' incorporates:
   *  Constant: '<S61>/Weight'
   *  Product: '<S61>/andorMethod'
   */
  rtb_Weighting_fh = rtb_Merge_h * rtb_Merge_m * rtb_Merge_fo * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_il;

  /* Product: '<S62>/Weighting' incorporates:
   *  Constant: '<S62>/Weight'
   *  Product: '<S62>/andorMethod'
   */
  rtb_Weighting_o2 = rtb_Merge_h * rtb_Merge_m * rtb_Merge_gj * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_ja;

  /* Product: '<S63>/Weighting' incorporates:
   *  Constant: '<S63>/Weight'
   *  Product: '<S63>/andorMethod'
   */
  rtb_Weighting_aw = rtb_Merge_h * rtb_Merge_m * rtb_Merge_gj * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_n;

  /* Product: '<S64>/Weighting' incorporates:
   *  Constant: '<S64>/Weight'
   *  Product: '<S64>/andorMethod'
   */
  rtb_Weighting_h = rtb_Merge_h * rtb_Merge_m * rtb_Merge_gj * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_jom;

  /* If: '<S158>/If' incorporates:
   *  Constant: '<S164>/0'
   *  Constant: '<S165>/0'
   */
  if ((rtb_LQRController2 < 0.0) || (rtb_LQRController2 > 3.0)) {
    /* Outputs for IfAction SubSystem: '<S158>/If Action Subsystem' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    rtb_Merge_gjy = BalanceMultiNew_P._Value_lz;

    /* End of Outputs for SubSystem: '<S158>/If Action Subsystem' */
  } else if (rtb_LQRController2 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S158>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    rtb_Merge_gjy = BalanceMultiNew_P._Value_l3;

    /* End of Outputs for SubSystem: '<S158>/If Action Subsystem1' */
  } else if (rtb_LQRController2 < 1.0) {
    /* Outputs for IfAction SubSystem: '<S158>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S167>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController2, &rtb_Merge_gjy,
      (P_IfActionSubsystem3_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem3_o1);

    /* End of Outputs for SubSystem: '<S158>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S158>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S166>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController2, &rtb_Merge_gjy,
      (P_IfActionSubsystem2_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem2_m);

    /* End of Outputs for SubSystem: '<S158>/If Action Subsystem2' */
  }

  /* End of If: '<S158>/If' */

  /* Product: '<S65>/Weighting' incorporates:
   *  Constant: '<S65>/Weight'
   *  Product: '<S65>/andorMethod'
   */
  rtb_Weighting_o2m = rtb_Merge_h * rtb_Merge_gjy * rtb_Merge_e * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_nj;

  /* Product: '<S67>/Weighting' incorporates:
   *  Constant: '<S67>/Weight'
   *  Product: '<S67>/andorMethod'
   */
  rtb_Weighting_ow = rtb_Merge_h * rtb_Merge_gjy * rtb_Merge_e * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_f;

  /* Product: '<S68>/Weighting' incorporates:
   *  Constant: '<S68>/Weight'
   *  Product: '<S68>/andorMethod'
   */
  rtb_Weighting_lb = rtb_Merge_h * rtb_Merge_gjy * rtb_Merge_e * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_e;

  /* Product: '<S69>/Weighting' incorporates:
   *  Constant: '<S69>/Weight'
   *  Product: '<S69>/andorMethod'
   */
  rtb_Weighting_hl = rtb_Merge_h * rtb_Merge_gjy * rtb_Merge_fo * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_jd;

  /* Product: '<S70>/Weighting' incorporates:
   *  Constant: '<S70>/Weight'
   *  Product: '<S70>/andorMethod'
   */
  rtb_Weighting_c = rtb_Merge_h * rtb_Merge_gjy * rtb_Merge_fo * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_bs;

  /* Product: '<S71>/Weighting' incorporates:
   *  Constant: '<S71>/Weight'
   *  Product: '<S71>/andorMethod'
   */
  rtb_Weighting_ac = rtb_Merge_h * rtb_Merge_gjy * rtb_Merge_fo * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_al;

  /* Product: '<S72>/Weighting' incorporates:
   *  Constant: '<S72>/Weight'
   *  Product: '<S72>/andorMethod'
   */
  rtb_Weighting_ai = rtb_Merge_h * rtb_Merge_gjy * rtb_Merge_gj * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_ce;

  /* Product: '<S73>/Weighting' incorporates:
   *  Constant: '<S73>/Weight'
   *  Product: '<S73>/andorMethod'
   */
  rtb_Weighting_ec = rtb_Merge_h * rtb_Merge_gjy * rtb_Merge_gj * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_ay;

  /* Product: '<S74>/Weighting' incorporates:
   *  Constant: '<S74>/Weight'
   *  Product: '<S74>/andorMethod'
   */
  rtb_Weighting_bq = rtb_Merge_h * rtb_Merge_gjy * rtb_Merge_gj * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_hi;

  /* If: '<S144>/If' incorporates:
   *  Constant: '<S153>/0'
   *  Constant: '<S154>/0'
   */
  if ((rtb_LQRController1 < -1.0) || (rtb_LQRController1 > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S144>/If Action Subsystem' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    rtb_Merge_it = BalanceMultiNew_P._Value_k;

    /* End of Outputs for SubSystem: '<S144>/If Action Subsystem' */
  } else if (rtb_LQRController1 == 0.0) {
    /* Outputs for IfAction SubSystem: '<S144>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    rtb_Merge_it = BalanceMultiNew_P._Value_ka;

    /* End of Outputs for SubSystem: '<S144>/If Action Subsystem1' */
  } else if (rtb_LQRController1 < 0.0) {
    /* Outputs for IfAction SubSystem: '<S144>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController1, &rtb_Merge_it,
      (P_IfActionSubsystem3_BalanceM_T *)&BalanceMultiNew_P.IfActionSubsystem3_n);

    /* End of Outputs for SubSystem: '<S144>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S144>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController1, &rtb_Merge_it,
      (P_IfActionSubsystem2_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem2_mo);

    /* End of Outputs for SubSystem: '<S144>/If Action Subsystem2' */
  }

  /* End of If: '<S144>/If' */

  /* Product: '<S75>/Weighting' incorporates:
   *  Constant: '<S75>/Weight'
   *  Product: '<S75>/andorMethod'
   */
  rtb_Weighting_on = rtb_Merge_it * rtb_Merge_n * rtb_Merge_e * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_d;

  /* Product: '<S76>/Weighting' incorporates:
   *  Constant: '<S76>/Weight'
   *  Product: '<S76>/andorMethod'
   */
  rtb_Weighting_od = rtb_Merge_it * rtb_Merge_n * rtb_Merge_e * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_py;

  /* Product: '<S78>/Weighting' incorporates:
   *  Constant: '<S78>/Weight'
   *  Product: '<S78>/andorMethod'
   */
  rtb_Weighting_f5 = rtb_Merge_it * rtb_Merge_n * rtb_Merge_e * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_hh;

  /* Product: '<S79>/Weighting' incorporates:
   *  Constant: '<S79>/Weight'
   *  Product: '<S79>/andorMethod'
   */
  rtb_Weighting_j = rtb_Merge_it * rtb_Merge_n * rtb_Merge_fo * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_hc;

  /* Product: '<S80>/Weighting' incorporates:
   *  Constant: '<S80>/Weight'
   *  Product: '<S80>/andorMethod'
   */
  rtb_Weighting_lp = rtb_Merge_it * rtb_Merge_n * rtb_Merge_fo * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_ni;

  /* Product: '<S81>/Weighting' incorporates:
   *  Constant: '<S81>/Weight'
   *  Product: '<S81>/andorMethod'
   */
  rtb_Weighting_lo = rtb_Merge_it * rtb_Merge_n * rtb_Merge_fo * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_ia;

  /* Product: '<S82>/Weighting' incorporates:
   *  Constant: '<S82>/Weight'
   *  Product: '<S82>/andorMethod'
   */
  rtb_Weighting_hr = rtb_Merge_it * rtb_Merge_n * rtb_Merge_gj * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_bk;

  /* Product: '<S83>/Weighting' incorporates:
   *  Constant: '<S83>/Weight'
   *  Product: '<S83>/andorMethod'
   */
  rtb_Weighting_ol = rtb_Merge_it * rtb_Merge_n * rtb_Merge_gj * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_j5;

  /* Product: '<S84>/Weighting' incorporates:
   *  Constant: '<S84>/Weight'
   *  Product: '<S84>/andorMethod'
   */
  rtb_Weighting_i = rtb_Merge_it * rtb_Merge_n * rtb_Merge_gj * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_oe;

  /* Product: '<S85>/Weighting' incorporates:
   *  Constant: '<S85>/Weight'
   *  Product: '<S85>/andorMethod'
   */
  rtb_Weighting_bz = rtb_Merge_it * rtb_Merge_m * rtb_Merge_e * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_hht;

  /* Product: '<S86>/Weighting' incorporates:
   *  Constant: '<S86>/Weight'
   *  Product: '<S86>/andorMethod'
   */
  rtb_Weighting_ka = rtb_Merge_it * rtb_Merge_m * rtb_Merge_e * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_h2;

  /* Product: '<S87>/Weighting' incorporates:
   *  Constant: '<S87>/Weight'
   *  Product: '<S87>/andorMethod'
   */
  rtb_Weighting_ja = rtb_Merge_it * rtb_Merge_m * rtb_Merge_e * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_ih;

  /* Product: '<S89>/Weighting' incorporates:
   *  Constant: '<S89>/Weight'
   *  Product: '<S89>/andorMethod'
   */
  rtb_Weighting_n = rtb_Merge_it * rtb_Merge_m * rtb_Merge_fo * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_cr;

  /* Product: '<S90>/Weighting' incorporates:
   *  Constant: '<S90>/Weight'
   *  Product: '<S90>/andorMethod'
   */
  rtb_Weighting_e0 = rtb_Merge_it * rtb_Merge_m * rtb_Merge_fo * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_as;

  /* Product: '<S91>/Weighting' incorporates:
   *  Constant: '<S91>/Weight'
   *  Product: '<S91>/andorMethod'
   */
  rtb_Weighting_p = rtb_Merge_it * rtb_Merge_m * rtb_Merge_fo * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_jb;

  /* Product: '<S92>/Weighting' incorporates:
   *  Constant: '<S92>/Weight'
   *  Product: '<S92>/andorMethod'
   */
  rtb_Weighting_lv = rtb_Merge_it * rtb_Merge_m * rtb_Merge_gj * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_ps;

  /* Product: '<S93>/Weighting' incorporates:
   *  Constant: '<S93>/Weight'
   *  Product: '<S93>/andorMethod'
   */
  rtb_Weighting_jw = rtb_Merge_it * rtb_Merge_m * rtb_Merge_gj * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_m0;

  /* Product: '<S94>/Weighting' incorporates:
   *  Constant: '<S94>/Weight'
   *  Product: '<S94>/andorMethod'
   */
  rtb_Weighting_fz = rtb_Merge_it * rtb_Merge_m * rtb_Merge_gj * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_k;

  /* Product: '<S95>/Weighting' incorporates:
   *  Constant: '<S95>/Weight'
   *  Product: '<S95>/andorMethod'
   */
  rtb_Weighting_hs = rtb_Merge_it * rtb_Merge_gjy * rtb_Merge_e * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_px;

  /* Product: '<S96>/Weighting' incorporates:
   *  Constant: '<S96>/Weight'
   *  Product: '<S96>/andorMethod'
   */
  rtb_Weighting_mv = rtb_Merge_it * rtb_Merge_gjy * rtb_Merge_e * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_ge;

  /* Product: '<S97>/Weighting' incorporates:
   *  Constant: '<S97>/Weight'
   *  Product: '<S97>/andorMethod'
   */
  rtb_Weighting_kn = rtb_Merge_it * rtb_Merge_gjy * rtb_Merge_e * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_ew;

  /* Product: '<S98>/Weighting' incorporates:
   *  Constant: '<S98>/Weight'
   *  Product: '<S98>/andorMethod'
   */
  rtb_Weighting_bg = rtb_Merge_it * rtb_Merge_gjy * rtb_Merge_fo * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_dx;

  /* Product: '<S100>/Weighting' incorporates:
   *  Constant: '<S100>/Weight'
   *  Product: '<S100>/andorMethod'
   */
  rtb_Weighting_bt = rtb_Merge_it * rtb_Merge_gjy * rtb_Merge_fo * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_fd;

  /* Product: '<S101>/Weighting' incorporates:
   *  Constant: '<S101>/Weight'
   *  Product: '<S101>/andorMethod'
   */
  rtb_Weighting_ou = rtb_Merge_it * rtb_Merge_gjy * rtb_Merge_fo * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_nb;

  /* Product: '<S102>/Weighting' incorporates:
   *  Constant: '<S102>/Weight'
   *  Product: '<S102>/andorMethod'
   */
  rtb_Weighting_ny = rtb_Merge_it * rtb_Merge_gjy * rtb_Merge_gj * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_ft;

  /* Product: '<S103>/Weighting' incorporates:
   *  Constant: '<S103>/Weight'
   *  Product: '<S103>/andorMethod'
   */
  rtb_Weighting_hq = rtb_Merge_it * rtb_Merge_gjy * rtb_Merge_gj * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_ca;

  /* Product: '<S104>/Weighting' incorporates:
   *  Constant: '<S104>/Weight'
   *  Product: '<S104>/andorMethod'
   */
  rtb_Weighting_lvs = rtb_Merge_it * rtb_Merge_gjy * rtb_Merge_gj * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_ae;

  /* If: '<S143>/If' incorporates:
   *  Constant: '<S149>/0'
   *  Constant: '<S150>/0'
   */
  if ((rtb_LQRController1 < 0.0) || (rtb_LQRController1 > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S143>/If Action Subsystem' incorporates:
     *  ActionPort: '<S149>/Action Port'
     */
    rtb_Merge_nc = BalanceMultiNew_P._Value_lt;

    /* End of Outputs for SubSystem: '<S143>/If Action Subsystem' */
  } else if (rtb_LQRController1 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S143>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    rtb_Merge_nc = BalanceMultiNew_P._Value_gn;

    /* End of Outputs for SubSystem: '<S143>/If Action Subsystem1' */
  } else if (rtb_LQRController1 < 1.0) {
    /* Outputs for IfAction SubSystem: '<S143>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    BalanceMulti_IfActionSubsystem3(rtb_LQRController1, &rtb_Merge_nc,
      (P_IfActionSubsystem3_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem3_hm);

    /* End of Outputs for SubSystem: '<S143>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S143>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    BalanceMulti_IfActionSubsystem2(rtb_LQRController1, &rtb_Merge_nc,
      (P_IfActionSubsystem2_BalanceM_T *)
      &BalanceMultiNew_P.IfActionSubsystem2_ov);

    /* End of Outputs for SubSystem: '<S143>/If Action Subsystem2' */
  }

  /* End of If: '<S143>/If' */

  /* Product: '<S105>/Weighting' incorporates:
   *  Constant: '<S105>/Weight'
   *  Product: '<S105>/andorMethod'
   */
  rtb_Weighting_a5 = rtb_Merge_nc * rtb_Merge_n * rtb_Merge_e * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_jr;

  /* Product: '<S106>/Weighting' incorporates:
   *  Constant: '<S106>/Weight'
   *  Product: '<S106>/andorMethod'
   */
  rtb_Weighting_g = rtb_Merge_nc * rtb_Merge_n * rtb_Merge_e * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_lc;

  /* Product: '<S107>/Weighting' incorporates:
   *  Constant: '<S107>/Weight'
   *  Product: '<S107>/andorMethod'
   */
  rtb_Weighting_ft = rtb_Merge_nc * rtb_Merge_n * rtb_Merge_e * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_j0;

  /* Product: '<S108>/Weighting' incorporates:
   *  Constant: '<S108>/Weight'
   *  Product: '<S108>/andorMethod'
   */
  rtb_Weighting_jb = rtb_Merge_nc * rtb_Merge_n * rtb_Merge_fo * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_ju;

  /* Product: '<S109>/Weighting' incorporates:
   *  Constant: '<S109>/Weight'
   *  Product: '<S109>/andorMethod'
   */
  rtb_Weighting_ih = rtb_Merge_nc * rtb_Merge_n * rtb_Merge_fo * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_bu;

  /* Product: '<S111>/Weighting' incorporates:
   *  Constant: '<S111>/Weight'
   *  Product: '<S111>/andorMethod'
   */
  rtb_Weighting_dt = rtb_Merge_nc * rtb_Merge_n * rtb_Merge_fo * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_b2;

  /* Product: '<S112>/Weighting' incorporates:
   *  Constant: '<S112>/Weight'
   *  Product: '<S112>/andorMethod'
   */
  rtb_Weighting_pp = rtb_Merge_nc * rtb_Merge_n * rtb_Merge_gj * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_mp;

  /* Product: '<S113>/Weighting' incorporates:
   *  Constant: '<S113>/Weight'
   *  Product: '<S113>/andorMethod'
   */
  rtb_Weighting_mm = rtb_Merge_nc * rtb_Merge_n * rtb_Merge_gj * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_ag;

  /* Product: '<S114>/Weighting' incorporates:
   *  Constant: '<S114>/Weight'
   *  Product: '<S114>/andorMethod'
   */
  rtb_Weighting_cx = rtb_Merge_nc * rtb_Merge_n * rtb_Merge_gj * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_gb;

  /* Product: '<S115>/Weighting' incorporates:
   *  Constant: '<S115>/Weight'
   *  Product: '<S115>/andorMethod'
   */
  rtb_Weighting_bo = rtb_Merge_nc * rtb_Merge_m * rtb_Merge_e * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_oo;

  /* Product: '<S116>/Weighting' incorporates:
   *  Constant: '<S116>/Weight'
   *  Product: '<S116>/andorMethod'
   */
  rtb_Weighting_nv = rtb_Merge_nc * rtb_Merge_m * rtb_Merge_e * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_eg;

  /* Product: '<S117>/Weighting' incorporates:
   *  Constant: '<S117>/Weight'
   *  Product: '<S117>/andorMethod'
   */
  rtb_Weighting_lc = rtb_Merge_nc * rtb_Merge_m * rtb_Merge_e * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_gf;

  /* Product: '<S118>/Weighting' incorporates:
   *  Constant: '<S118>/Weight'
   *  Product: '<S118>/andorMethod'
   */
  rtb_Weighting_dy = rtb_Merge_nc * rtb_Merge_m * rtb_Merge_fo * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_gu;

  /* Product: '<S119>/Weighting' incorporates:
   *  Constant: '<S119>/Weight'
   *  Product: '<S119>/andorMethod'
   */
  rtb_Weighting_ppe = rtb_Merge_nc * rtb_Merge_m * rtb_Merge_fo * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_ng;

  /* Product: '<S120>/Weighting' incorporates:
   *  Constant: '<S120>/Weight'
   *  Product: '<S120>/andorMethod'
   */
  rtb_Weighting_h4 = rtb_Merge_nc * rtb_Merge_m * rtb_Merge_fo * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_js;

  /* Product: '<S122>/Weighting' incorporates:
   *  Constant: '<S122>/Weight'
   *  Product: '<S122>/andorMethod'
   */
  rtb_Weighting_ppm = rtb_Merge_nc * rtb_Merge_m * rtb_Merge_gj * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_o5;

  /* Product: '<S123>/Weighting' incorporates:
   *  Constant: '<S123>/Weight'
   *  Product: '<S123>/andorMethod'
   */
  rtb_Weighting_nw = rtb_Merge_nc * rtb_Merge_m * rtb_Merge_gj * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_pz;

  /* Product: '<S124>/Weighting' incorporates:
   *  Constant: '<S124>/Weight'
   *  Product: '<S124>/andorMethod'
   */
  rtb_Weighting_pa = rtb_Merge_nc * rtb_Merge_m * rtb_Merge_gj * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_pr;

  /* Product: '<S125>/Weighting' incorporates:
   *  Constant: '<S125>/Weight'
   *  Product: '<S125>/andorMethod'
   */
  rtb_Weighting_kan = rtb_Merge_nc * rtb_Merge_gjy * rtb_Merge_e * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_dr;

  /* Product: '<S126>/Weighting' incorporates:
   *  Constant: '<S126>/Weight'
   *  Product: '<S126>/andorMethod'
   */
  rtb_Weighting_k0 = rtb_Merge_nc * rtb_Merge_gjy * rtb_Merge_e * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_hr;

  /* Product: '<S127>/Weighting' incorporates:
   *  Constant: '<S127>/Weight'
   *  Product: '<S127>/andorMethod'
   */
  rtb_Weighting_jx = rtb_Merge_nc * rtb_Merge_gjy * rtb_Merge_e * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_pu;

  /* Product: '<S128>/Weighting' incorporates:
   *  Constant: '<S128>/Weight'
   *  Product: '<S128>/andorMethod'
   */
  rtb_Weighting_j5 = rtb_Merge_nc * rtb_Merge_gjy * rtb_Merge_fo * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_dk;

  /* Product: '<S129>/Weighting' incorporates:
   *  Constant: '<S129>/Weight'
   *  Product: '<S129>/andorMethod'
   */
  rtb_Weighting_mk = rtb_Merge_nc * rtb_Merge_gjy * rtb_Merge_fo * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_jz;

  /* Product: '<S130>/Weighting' incorporates:
   *  Constant: '<S130>/Weight'
   *  Product: '<S130>/andorMethod'
   */
  rtb_Weighting_o3 = rtb_Merge_nc * rtb_Merge_gjy * rtb_Merge_fo * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_a5;

  /* Product: '<S131>/Weighting' incorporates:
   *  Constant: '<S131>/Weight'
   *  Product: '<S131>/andorMethod'
   */
  rtb_Weighting_mw = rtb_Merge_nc * rtb_Merge_gjy * rtb_Merge_gj * rtb_Merge_f *
    BalanceMultiNew_P.Weight_Value_hf;

  /* Product: '<S133>/Weighting' incorporates:
   *  Constant: '<S133>/Weight'
   *  Product: '<S133>/andorMethod'
   */
  rtb_Weighting_n5 = rtb_Merge_nc * rtb_Merge_gjy * rtb_Merge_gj * rtb_Merge_n1 *
    BalanceMultiNew_P.Weight_Value_jw;

  /* Product: '<S134>/Weighting' incorporates:
   *  Constant: '<S134>/Weight'
   *  Product: '<S134>/andorMethod'
   */
  rtb_u = rtb_Merge_nc * rtb_Merge_gjy * rtb_Merge_gj * rtb_Merge_g *
    BalanceMultiNew_P.Weight_Value_m4;

  /* Sum: '<S52>/Total Firing Strength' */
  rtb_TotalFiringStrength_f =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((rtb_u_m + rtb_Weighting_a) + rtb_Weighting_gx) + rtb_Sum_g) +
    rtb_Weighting_d) + rtb_Switch1) + rtb_Weighting_ah) + rtb_Weighting_m) +
    rtb_Weighting_o) + rtb_Weighting_b) + rtb_Weighting_f) + rtb_Weighting_mt) +
    rtb_Weighting_me) + rtb_Weighting_l1) + rtb_Weighting_fh) + rtb_Weighting_o2)
    + rtb_Weighting_aw) + rtb_Weighting_h) + rtb_Weighting_o2m) +
    rtb_Weighting_ow) + rtb_Weighting_lb) + rtb_Weighting_hl) + rtb_Weighting_c)
    + rtb_Weighting_ac) + rtb_Weighting_ai) + rtb_Weighting_ec) +
    rtb_Weighting_bq) + rtb_Weighting_on) + rtb_Weighting_od) + rtb_Weighting_f5)
    + rtb_Weighting_j) + rtb_Weighting_lp) + rtb_Weighting_lo) +
    rtb_Weighting_hr) + rtb_Weighting_ol) + rtb_Weighting_i) + rtb_Weighting_bz)
    + rtb_Weighting_ka) + rtb_Weighting_ja) + rtb_Weighting_n) +
    rtb_Weighting_e0) + rtb_Weighting_p) + rtb_Weighting_lv) + rtb_Weighting_jw)
    + rtb_Weighting_fz) + rtb_Weighting_hs) + rtb_Weighting_mv) +
    rtb_Weighting_kn) + rtb_Weighting_bg) + rtb_Weighting_bt) + rtb_Weighting_ou)
    + rtb_Weighting_ny) + rtb_Weighting_hq) + rtb_Weighting_lvs) +
    rtb_Weighting_a5) + rtb_Weighting_g) + rtb_Weighting_ft) + rtb_Weighting_jb)
    + rtb_Weighting_ih) + rtb_Weighting_dt) + rtb_Weighting_pp) +
                       rtb_Weighting_mm) + rtb_Weighting_cx) + rtb_Weighting_bo)
                    + rtb_Weighting_nv) + rtb_Weighting_lc) + rtb_Weighting_dy)
                 + rtb_Weighting_ppe) + rtb_Weighting_h4) + rtb_Weighting_ppm) +
              rtb_Weighting_nw) + rtb_Weighting_pa) + rtb_Weighting_kan) +
           rtb_Weighting_k0) + rtb_Weighting_jx) + rtb_Weighting_j5) +
        rtb_Weighting_mk) + rtb_Weighting_o3) + rtb_Weighting_mw) +
     rtb_Weighting_n5) + rtb_u;

  /* If: '<S53>/If' incorporates:
   *  Constant: '<S140>/One'
   */
  if (rtb_TotalFiringStrength_f < 0.0) {
    /* Outputs for IfAction SubSystem: '<S53>/Action: One' incorporates:
     *  ActionPort: '<S140>/Action Port'
     */
    rtb_Merge_a = BalanceMultiNew_P.One_Value_c;

    /* End of Outputs for SubSystem: '<S53>/Action: One' */
  } else {
    /* Outputs for IfAction SubSystem: '<S53>/Action: u1' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    BalanceMultiNew_Actionu1(rtb_TotalFiringStrength_f, &rtb_Merge_a);

    /* End of Outputs for SubSystem: '<S53>/Action: u1' */
  }

  /* End of If: '<S53>/If' */

  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/MidRange'
   *  Constant: '<S52>/Zero'
   *  Product: '<S53>/Product'
   *  RelationalOperator: '<S52>/Zero Firing Strength?'
   */
  if ((rtb_TotalFiringStrength_f > BalanceMultiNew_P.Zero_Value_e) >=
      BalanceMultiNew_P.Switch_Threshold_g) {
    /* Product: '<S55>/impMethod' incorporates:
     *  Constant: '<S136>/NB(Constant)'
     */
    rtb_u_m *= BalanceMultiNew_P.NBConstant_Value;

    /* Sum: '<S53>/Sum1' incorporates:
     *  Constant: '<S136>/NB(Constant)'
     *  Constant: '<S136>/NM(Constant)'
     *  Constant: '<S136>/NS(Constant)'
     *  Constant: '<S136>/PB(Constant)'
     *  Constant: '<S136>/PM(Constant)'
     *  Constant: '<S136>/PS(Constant)'
     *  Constant: '<S136>/ZE(Constant)'
     *  Product: '<S100>/impMethod'
     *  Product: '<S101>/impMethod'
     *  Product: '<S102>/impMethod'
     *  Product: '<S103>/impMethod'
     *  Product: '<S104>/impMethod'
     *  Product: '<S105>/impMethod'
     *  Product: '<S106>/impMethod'
     *  Product: '<S107>/impMethod'
     *  Product: '<S108>/impMethod'
     *  Product: '<S109>/impMethod'
     *  Product: '<S110>/impMethod'
     *  Product: '<S111>/impMethod'
     *  Product: '<S112>/impMethod'
     *  Product: '<S113>/impMethod'
     *  Product: '<S114>/impMethod'
     *  Product: '<S115>/impMethod'
     *  Product: '<S116>/impMethod'
     *  Product: '<S117>/impMethod'
     *  Product: '<S118>/impMethod'
     *  Product: '<S119>/impMethod'
     *  Product: '<S120>/impMethod'
     *  Product: '<S121>/impMethod'
     *  Product: '<S122>/impMethod'
     *  Product: '<S123>/impMethod'
     *  Product: '<S124>/impMethod'
     *  Product: '<S125>/impMethod'
     *  Product: '<S126>/impMethod'
     *  Product: '<S127>/impMethod'
     *  Product: '<S128>/impMethod'
     *  Product: '<S129>/impMethod'
     *  Product: '<S130>/impMethod'
     *  Product: '<S131>/impMethod'
     *  Product: '<S132>/impMethod'
     *  Product: '<S133>/impMethod'
     *  Product: '<S134>/impMethod'
     *  Product: '<S135>/impMethod'
     *  Product: '<S56>/impMethod'
     *  Product: '<S57>/impMethod'
     *  Product: '<S58>/impMethod'
     *  Product: '<S59>/impMethod'
     *  Product: '<S60>/impMethod'
     *  Product: '<S61>/impMethod'
     *  Product: '<S62>/impMethod'
     *  Product: '<S63>/impMethod'
     *  Product: '<S64>/impMethod'
     *  Product: '<S65>/impMethod'
     *  Product: '<S66>/impMethod'
     *  Product: '<S67>/impMethod'
     *  Product: '<S68>/impMethod'
     *  Product: '<S69>/impMethod'
     *  Product: '<S70>/impMethod'
     *  Product: '<S71>/impMethod'
     *  Product: '<S72>/impMethod'
     *  Product: '<S73>/impMethod'
     *  Product: '<S74>/impMethod'
     *  Product: '<S75>/impMethod'
     *  Product: '<S76>/impMethod'
     *  Product: '<S77>/impMethod'
     *  Product: '<S78>/impMethod'
     *  Product: '<S79>/impMethod'
     *  Product: '<S80>/impMethod'
     *  Product: '<S81>/impMethod'
     *  Product: '<S82>/impMethod'
     *  Product: '<S83>/impMethod'
     *  Product: '<S84>/impMethod'
     *  Product: '<S85>/impMethod'
     *  Product: '<S86>/impMethod'
     *  Product: '<S87>/impMethod'
     *  Product: '<S88>/impMethod'
     *  Product: '<S89>/impMethod'
     *  Product: '<S90>/impMethod'
     *  Product: '<S91>/impMethod'
     *  Product: '<S92>/impMethod'
     *  Product: '<S93>/impMethod'
     *  Product: '<S94>/impMethod'
     *  Product: '<S95>/impMethod'
     *  Product: '<S96>/impMethod'
     *  Product: '<S97>/impMethod'
     *  Product: '<S98>/impMethod'
     *  Product: '<S99>/impMethod'
     */
    tmpForInput[0] = rtb_u_m;
    tmpForInput[1] = rtb_Weighting_a * BalanceMultiNew_P.NBConstant_Value;
    tmpForInput[2] = rtb_Weighting_gx * BalanceMultiNew_P.NMConstant_Value;
    tmpForInput[3] = rtb_Sum_g * BalanceMultiNew_P.NBConstant_Value;
    tmpForInput[4] = rtb_Weighting_d * BalanceMultiNew_P.NMConstant_Value;
    tmpForInput[5] = rtb_Switch1 * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[6] = rtb_Weighting_ah * BalanceMultiNew_P.NMConstant_Value;
    tmpForInput[7] = rtb_Weighting_m * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[8] = rtb_Weighting_o * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[9] = rtb_Weighting_b * BalanceMultiNew_P.NBConstant_Value;
    tmpForInput[10] = rtb_Weighting_f * BalanceMultiNew_P.NMConstant_Value;
    tmpForInput[11] = rtb_Weighting_mt * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[12] = rtb_Weighting_me * BalanceMultiNew_P.NMConstant_Value;
    tmpForInput[13] = rtb_Weighting_l1 * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[14] = rtb_Weighting_fh * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[15] = rtb_Weighting_o2 * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[16] = rtb_Weighting_aw * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[17] = rtb_Weighting_h * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[18] = rtb_Weighting_o2m * BalanceMultiNew_P.NMConstant_Value;
    tmpForInput[19] = rtb_Weighting_ow * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[20] = rtb_Weighting_lb * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[21] = rtb_Weighting_hl * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[22] = rtb_Weighting_c * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[23] = rtb_Weighting_ac * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[24] = rtb_Weighting_ai * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[25] = rtb_Weighting_ec * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[26] = rtb_Weighting_bq * BalanceMultiNew_P.PMConstant_Value;
    tmpForInput[27] = rtb_Weighting_on * BalanceMultiNew_P.NBConstant_Value;
    tmpForInput[28] = rtb_Weighting_od * BalanceMultiNew_P.NMConstant_Value;
    tmpForInput[29] = rtb_Weighting_f5 * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[30] = rtb_Weighting_j * BalanceMultiNew_P.NMConstant_Value;
    tmpForInput[31] = rtb_Weighting_lp * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[32] = rtb_Weighting_lo * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[33] = rtb_Weighting_hr * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[34] = rtb_Weighting_ol * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[35] = rtb_Weighting_i * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[36] = rtb_Weighting_bz * BalanceMultiNew_P.NMConstant_Value;
    tmpForInput[37] = rtb_Weighting_ka * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[38] = rtb_Weighting_ja * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[39] = rtb_Weighting_n * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[40] = rtb_Weighting_e0 * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[41] = rtb_Weighting_p * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[42] = rtb_Weighting_lv * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[43] = rtb_Weighting_jw * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[44] = rtb_Weighting_fz * BalanceMultiNew_P.PMConstant_Value;
    tmpForInput[45] = rtb_Weighting_hs * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[46] = rtb_Weighting_mv * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[47] = rtb_Weighting_kn * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[48] = rtb_Weighting_bg * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[49] = rtb_Weighting_bt * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[50] = rtb_Weighting_ou * BalanceMultiNew_P.PMConstant_Value;
    tmpForInput[51] = rtb_Weighting_ny * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[52] = rtb_Weighting_hq * BalanceMultiNew_P.PMConstant_Value;
    tmpForInput[53] = rtb_Weighting_lvs * BalanceMultiNew_P.PBConstant_Value;
    tmpForInput[54] = rtb_Weighting_a5 * BalanceMultiNew_P.NMConstant_Value;
    tmpForInput[55] = rtb_Weighting_g * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[56] = rtb_Weighting_ft * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[57] = rtb_Weighting_jb * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[58] = rtb_Weighting_ih * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[59] = rtb_Weighting_dt * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[60] = rtb_Weighting_pp * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[61] = rtb_Weighting_mm * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[62] = rtb_Weighting_cx * BalanceMultiNew_P.PMConstant_Value;
    tmpForInput[63] = rtb_Weighting_bo * BalanceMultiNew_P.NSConstant_Value;
    tmpForInput[64] = rtb_Weighting_nv * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[65] = rtb_Weighting_lc * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[66] = rtb_Weighting_dy * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[67] = rtb_Weighting_ppe * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[68] = rtb_Weighting_h4 * BalanceMultiNew_P.PMConstant_Value;
    tmpForInput[69] = rtb_Weighting_ppm * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[70] = rtb_Weighting_nw * BalanceMultiNew_P.PMConstant_Value;
    tmpForInput[71] = rtb_Weighting_pa * BalanceMultiNew_P.PBConstant_Value;
    tmpForInput[72] = rtb_Weighting_kan * BalanceMultiNew_P.ZEConstant_Value;
    tmpForInput[73] = rtb_Weighting_k0 * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[74] = rtb_Weighting_jx * BalanceMultiNew_P.PMConstant_Value;
    tmpForInput[75] = rtb_Weighting_j5 * BalanceMultiNew_P.PSConstant_Value;
    tmpForInput[76] = rtb_Weighting_mk * BalanceMultiNew_P.PMConstant_Value;
    tmpForInput[77] = rtb_Weighting_o3 * BalanceMultiNew_P.PBConstant_Value;
    tmpForInput[78] = rtb_Weighting_mw * BalanceMultiNew_P.PMConstant_Value;
    tmpForInput[79] = rtb_Weighting_n5 * BalanceMultiNew_P.PBConstant_Value;
    tmpForInput[80] = rtb_u * BalanceMultiNew_P.PBConstant_Value;
    for (i = 0; i < 80; i++) {
      rtb_u_m += tmpForInput[i + 1];
    }

    /* End of Sum: '<S53>/Sum1' */
    rtb_Switch1 = rtb_u_m / rtb_Merge_a;
  } else {
    rtb_Switch1 = BalanceMultiNew_P.MidRange_Value_h;
  }

  /* End of Switch: '<S52>/Switch' */

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Gain: '<S5>/FuzzyGain1'
   *  Gain: '<S5>/LQR Controller'
   */
  /* MATLAB Function 'Multi_Controllers/MATLAB Function': '<S14>:1' */
  if (BalanceMultiNew_B.UARTRx2_o2 == 0) {
    /* '<S14>:1:3' */
    /* '<S14>:1:4' */
    rtb_Weighting_gd = rtb_LQRController_0;
  } else if (BalanceMultiNew_B.UARTRx2_o2 != 1) {
    /* '<S14>:1:7' */
    rtb_Weighting_gd = BalanceMultiNew_P.FuzzyGain1_Gain * rtb_Switch1;
  } else {
    /* '<S14>:1:5' */
    /* '<S14>:1:6' */
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* Switch: '<Root>/Switch' */
  if (!(rtb_sw >= BalanceMultiNew_P.Switch_Threshold_h)) {
    /* Saturate: '<S5>/Saturation' */
    if (rtb_Weighting_gd >= BalanceMultiNew_P.Saturation_UpperSat) {
      rtb_u_p = BalanceMultiNew_P.Saturation_UpperSat;
    } else if (rtb_Weighting_gd <= BalanceMultiNew_P.Saturation_LowerSat) {
      rtb_u_p = BalanceMultiNew_P.Saturation_LowerSat;
    } else {
      rtb_u_p = rtb_Weighting_gd;
    }

    /* End of Saturate: '<S5>/Saturation' */
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLAB Function: '<Root>/V_control' */
  /* MATLAB Function 'V_control': '<S9>:1' */
  if (rtb_u_p < 0.0) {
    /* '<S9>:1:3' */
    /* '<S9>:1:4' */
    rtb_u_m = 0.0;

    /* '<S9>:1:5' */
    rtb_u = -rtb_u_p * 100.0 / 24.0;
  } else {
    /*      DIR=1; */
    /*      PWM=u*100/24; */
    /* '<S9>:1:9' */
    rtb_u_m = 1.0;

    /* '<S9>:1:10' */
    rtb_u = rtb_u_p * 100.0 / 24.0;
  }

  /* End of MATLAB Function: '<Root>/V_control' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  /* MATLAB Function 'MATLAB Function': '<S4>:1' */
  if (rtb_DataTypeConversion7) {
    /* '<S4>:1:3' */
    /* '<S4>:1:4' */
    BalanceMultiNew_B.x = rtb_u;

    /* '<S4>:1:5' */
    BalanceMultiNew_B.y = rtb_u_m;
  } else {
    /* '<S4>:1:7' */
    BalanceMultiNew_B.x = 0.0;

    /* '<S4>:1:7' */
    BalanceMultiNew_B.y = 0.0;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Outputs for Atomic SubSystem: '<Root>/Enabled Subsystem' */

  /* S-Function Block: <S2>/Basic PWM (stm32f4_basicpwm) */
  TIM3->CCR1 = (uint32_t) (BalanceMultiNew_B.x * EnabledSubsystemBasicPWM_SF);

  /* S-Function (stm32f4_digital_output): '<S2>/Digital Output' */

  /* EnabledSubsystemDigitalOutput */
  *EnabledSubsystemDigitalOutput_D12 = (boolean_T) BalanceMultiNew_B.y;

  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  BalanceMultiNew_B.DataTypeConversion = (real32_T)rtb_alphadisplay;

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  BalanceMultiNew_B.DataTypeConversion1 = (real32_T)rtb_Gain1;

  /* Switch: '<Root>/Switch1' */
  if (rtb_sw >= BalanceMultiNew_P.Switch1_Threshold) {
    /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
     *  MATLAB Function: '<S3>/MATLAB Function1'
     */
    BalanceMultiNew_B.DataTypeConversion2 = (real32_T)thetadisplay;
  } else {
    /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
     *  MATLAB Function: '<S3>/MATLAB Function1'
     */
    BalanceMultiNew_B.DataTypeConversion2 = (real32_T)(r - 3.1415926535897931);
  }

  /* End of Switch: '<Root>/Switch1' */

  /* DataTypeConversion: '<S1>/Data Type Conversion3' */
  BalanceMultiNew_B.DataTypeConversion3 = (real32_T)rtb_Gain;

  /* DataTypeConversion: '<S1>/Data Type Conversion4' */
  BalanceMultiNew_B.DataTypeConversion4 = (real32_T)rtb_DataTypeConversion1_a;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' */
  BalanceMultiNew_B.DataTypeConversion5 = (real32_T)rtb_u_p;

  /* Outputs for Enabled SubSystem: '<Root>/UART Send' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (BalanceMultiNew_B.UARTRx_o2 > 0) {
    if (!BalanceMultiNew_DW.UARTSend_MODE) {
      /* Level2 S-Function Block: '<S8>/UART Tx' (stm32f4_usart) */
      enable_UARTSendUARTTx();
      BalanceMultiNew_DW.UARTSend_MODE = TRUE;
    }

    /* S-Function (stm32f4_usart): '<S8>/UART Tx' */

    /* UARTSendUARTTx */
    UART1_FlushTxBuffer();             /* Flush tx, so we can print to DMA buffer directly */
    sprintf((char*)UART1_Tx_Buffer, "a,%f,%f,%f,%f,%f,%f,\n"
            ,BalanceMultiNew_B.DataTypeConversion
            ,BalanceMultiNew_B.DataTypeConversion1
            ,BalanceMultiNew_B.DataTypeConversion2
            ,BalanceMultiNew_B.DataTypeConversion3
            ,BalanceMultiNew_B.DataTypeConversion4
            ,BalanceMultiNew_B.DataTypeConversion5
            );
    UART1_TxUpdate(strlen((char*)UART1_Tx_Buffer));

    /* Wait for DMA buffer for blocking mode */
    UART1_FlushTxBuffer();
  } else {
    if (BalanceMultiNew_DW.UARTSend_MODE) {
      /* Level2 S-Function Block: '<S8>/UART Tx' (stm32f4_usart) */

      /* disable_UARTSendUARTTx(); */
      BalanceMultiNew_DW.UARTSend_MODE = FALSE;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/UART Send' */

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  BalanceMultiNew_DW.UnitDelay1_DSTATE = rtb_alphadisplay;

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  MATLAB Function: '<S3>/MATLAB Function1'
   */
  BalanceMultiNew_DW.UnitDelay_DSTATE = thetadisplay;
}

/* Model initialize function */
void BalanceMultiNew_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(BalanceMultiNew_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &BalanceMultiNew_B), 0,
                sizeof(B_BalanceMultiNew_T));

  /* states (dwork) */
  (void) memset((void *)&BalanceMultiNew_DW, 0,
                sizeof(DW_BalanceMultiNew_T));

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay1' */
  BalanceMultiNew_DW.UnitDelay1_DSTATE =
    BalanceMultiNew_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  BalanceMultiNew_DW.UnitDelay_DSTATE =
    BalanceMultiNew_P.UnitDelay_InitialCondition;

  /* Level2 S-Function Block: '<Root>/UART Rx' (stm32f4_usart) */
  enable_UARTRx();

  /* Level2 S-Function Block: '<Root>/UART Rx3' (stm32f4_usart) */
  enable_UARTRx3();

  /* Level2 S-Function Block: '<S3>/Digital Input' (stm32f4_digital_input) */
  enable_EncodersDigitalInput();

  /* Level2 S-Function Block: '<S3>/Quadratur Encoder' (waijung_basic_customcode) */
  enable_EncodersQuadraturEncoder();

  /* Level2 S-Function Block: '<Root>/UART Rx2' (stm32f4_usart) */
  enable_UARTRx2();

  /* Level2 S-Function Block: '<Root>/UART Rx1' (stm32f4_usart) */
  enable_UARTRx1();

  /* Enable for Atomic SubSystem: '<Root>/Enabled Subsystem' */

  /* Level2 S-Function Block: '<S2>/Basic PWM' (stm32f4_basicpwm) */
  enable_EnabledSubsystemBasicPWM();

  /* Level2 S-Function Block: '<S2>/Digital Output' (stm32f4_digital_output) */
  enable_EnabledSubsystemDigitalOutput();

  /* End of Enable for SubSystem: '<Root>/Enabled Subsystem' */

  /* Level2 S-Function Block: '<Root>/UART Setup' (stm32f4_usart) */
  enable_UARTSetup();
}

/* Model terminate function */
void BalanceMultiNew_terminate(void)
{
  /* Terminate for S-Function (stm32f4_usart): '<Root>/UART Rx' */

  /* terminate_UARTRx(); */

  /* Terminate for S-Function (stm32f4_usart): '<Root>/UART Rx3' */

  /* terminate_UARTRx3(); */

  /* Terminate for S-Function (stm32f4_digital_input): '<S3>/Digital Input' */

  /* terminate_EncodersDigitalInput(); */

  /* Terminate for S-Function (stm32f4_usart): '<Root>/UART Rx2' */

  /* terminate_UARTRx2(); */

  /* Terminate for S-Function (stm32f4_usart): '<Root>/UART Rx1' */

  /* terminate_UARTRx1(); */

  /* Terminate for Atomic SubSystem: '<Root>/Enabled Subsystem' */

  /* Terminate for S-Function (stm32f4_basicpwm): '<S2>/Basic PWM' */

  /* terminate_EnabledSubsystemBasicPWM(); */

  /* Terminate for S-Function (stm32f4_digital_output): '<S2>/Digital Output' */

  /* terminate_EnabledSubsystemDigitalOutput(); */

  /* End of Terminate for SubSystem: '<Root>/Enabled Subsystem' */

  /* Terminate for Enabled SubSystem: '<Root>/UART Send' */

  /* Terminate for S-Function (stm32f4_usart): '<S8>/UART Tx' */

  /* terminate_UARTSendUARTTx(); */

  /* End of Terminate for SubSystem: '<Root>/UART Send' */

  /* Terminate for S-Function (stm32f4_usart): '<Root>/UART Setup' */

  /* terminate_UARTSetup(); */
}

/* [EOF] */
