/*
 * File: BalanceFuzzy.c
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

/* Block signals (auto storage) */
B_BalanceFuzzy_T BalanceFuzzy_B;

/* Block states (auto storage) */
DW_BalanceFuzzy_T BalanceFuzzy_DW;

/* Real-time model */
RT_MODEL_BalanceFuzzy_T BalanceFuzzy_M_;
RT_MODEL_BalanceFuzzy_T *const BalanceFuzzy_M = &BalanceFuzzy_M_;

/*
 * Output and update for action system:
 *    '<S94>/If Action Subsystem1'
 *    '<S95>/If Action Subsystem1'
 *    '<S96>/If Action Subsystem3'
 *    '<S109>/If Action Subsystem3'
 *    '<S110>/If Action Subsystem3'
 *    '<S111>/If Action Subsystem3'
 *    '<S124>/If Action Subsystem3'
 *    '<S125>/If Action Subsystem3'
 *    '<S126>/If Action Subsystem3'
 *    '<S139>/If Action Subsystem3'
 *    ...
 */
void BalanceFuzzy_IfActionSubsystem1(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem1_BalanceF_T *localP)
{
  /* Product: '<S98>/Product ab (trimf)' incorporates:
   *  Constant: '<S98>/a'
   *  Constant: '<S98>/b'
   *  Sum: '<S98>/Sum'
   *  Sum: '<S98>/Sum1'
   */
  *rty_Out1 = (rtu_x - localP->a_Value) / (localP->b_Value - localP->a_Value);
}

/*
 * Output and update for action system:
 *    '<S94>/If Action Subsystem3'
 *    '<S95>/If Action Subsystem3'
 */
void BalanceFuzzy_IfActionSubsystem3(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem3_BalanceF_T *localP)
{
  /* Product: '<S100>/Product cd (trimf)' incorporates:
   *  Constant: '<S100>/c'
   *  Constant: '<S100>/d'
   *  Sum: '<S100>/Sum2'
   *  Sum: '<S100>/Sum3'
   */
  *rty_Out1 = 1.0 / (localP->d_Value - localP->c_Value) * (localP->d_Value -
    rtu_x);
}

/*
 * Output and update for action system:
 *    '<S96>/If Action Subsystem2'
 *    '<S109>/If Action Subsystem2'
 *    '<S110>/If Action Subsystem2'
 *    '<S111>/If Action Subsystem2'
 *    '<S124>/If Action Subsystem2'
 *    '<S125>/If Action Subsystem2'
 *    '<S126>/If Action Subsystem2'
 *    '<S139>/If Action Subsystem2'
 *    '<S140>/If Action Subsystem2'
 *    '<S141>/If Action Subsystem2'
 */
void BalanceFuzzy_IfActionSubsystem2(real_T rtu_x, real_T *rty_Out1,
  P_IfActionSubsystem2_BalanceF_T *localP)
{
  /* Product: '<S107>/Product cd (trimf)' incorporates:
   *  Constant: '<S107>/b'
   *  Constant: '<S107>/c'
   *  Sum: '<S107>/Sum2'
   *  Sum: '<S107>/Sum3'
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
void BalanceFuzzy_step(void)
{
  /* local block i/o variables */
  real_T rtb_Saturation;
  real_T rtb_Saturation3;
  real_T rtb_Saturation1;
  real_T rtb_Saturation2;
  real_T rtb_Merge;
  real_T rtb_Merge_b;
  real_T rtb_Merge_p;
  real_T rtb_Merge_m;
  real_T rtb_Merge_o;
  real_T rtb_Merge_j;
  real_T rtb_Merge_k;
  real_T rtb_Merge_g;
  real_T rtb_Merge_i;
  real_T rtb_Merge_a;
  real_T rtb_Merge_gm;
  real_T rtb_Merge_h;
  real_T rtb_Switch;
  real_T rtb_Weighting_d;
  real_T rtb_Weighting_c;
  real_T rtb_Weighting_k;
  real_T rtb_Weighting_h;
  real_T rtb_Weighting_b;
  real_T rtb_Weighting_l;
  real_T rtb_Weighting_f;
  real_T rtb_Weighting_g;
  real_T rtb_Weighting_i;
  real_T rtb_Weighting_fu;
  real_T rtb_Weighting_cj;
  real_T rtb_Weighting_bd;
  real_T rtb_Weighting_h1;
  real_T rtb_Weighting_j;
  real_T rtb_Weighting_lg;
  real_T rtb_Weighting_a;
  real_T rtb_Weighting_m;
  real_T rtb_Weighting_p;
  real_T rtb_Weighting_k2;
  real_T rtb_Weighting_e;
  real_T rtb_Weighting_e5;
  real_T rtb_Weighting_kj;
  real_T rtb_Weighting_bz;
  real_T rtb_Weighting_al;
  real_T rtb_Weighting_o;
  real_T rtb_Weighting_mp;
  real_T rtb_Weighting_pc;
  real_T rtb_Weighting_lf;
  real_T rtb_Weighting_fv;
  real_T rtb_Weighting_bw;
  real_T rtb_Weighting_gk;
  real_T rtb_Weighting_jb;
  real_T rtb_Weighting_op;
  real_T rtb_Weighting_jo;
  real_T rtb_Weighting_bv;
  real_T rtb_Weighting_iq;
  real_T rtb_Weighting_dr;
  real_T rtb_Weighting_dd;
  real_T rtb_Weighting_b2;
  real_T rtb_Weighting_hs;
  real_T rtb_Weighting_cz;
  real_T rtb_Weighting_jl;
  real_T rtb_Weighting_gy;
  real_T rtb_Weighting_cw;
  real_T rtb_Weighting_a5;
  real_T rtb_Weighting_fh;
  real_T rtb_Weighting_oy;
  real_T rtb_Weighting_n;
  real_T rtb_Weighting_ee;
  real_T rtb_Weighting_hf;
  real_T rtb_Weighting_ar;
  real_T rtb_Weighting_o2;
  real_T rtb_Weighting_o0;
  real_T rtb_Weighting_by;
  real_T rtb_Weighting_md;
  real_T rtb_Weighting_ns;
  real_T rtb_Weighting_ad;
  real_T rtb_Weighting_cv;
  real_T rtb_Weighting_fd;
  real_T rtb_Weighting_p2;
  real_T rtb_Weighting_kv;
  real_T rtb_Weighting_gv;
  real_T rtb_Weighting_drb;
  real_T rtb_Weighting_hd;
  real_T rtb_Weighting_nk;
  real_T rtb_Weighting_ei;
  real_T rtb_Weighting_czj;
  real_T rtb_Weighting_ok;
  real_T rtb_Weighting_ai;
  real_T rtb_Weighting_it;
  real_T rtb_Weighting_cn;
  real_T rtb_Weighting_gs;
  real_T rtb_Weighting_g2;
  real_T rtb_Weighting_h5;
  real_T rtb_Weighting_fo;
  real_T rtb_Weighting_ag;
  real_T rtb_Weighting_dc;
  real_T rtb_Weighting_nq;
  real_T rtb_Weighting_cc;
  real_T rtb_Weighting_dj;
  real_T rtb_TotalFiringStrength;
  real_T tmpForInput[81];
  int32_T i;

  /* S-Function (stm32f4_usart): '<Root>/UART Tx' */

  /* UARTTx */
  UARTTx_packet_buffer[0] = 126;
  UARTTx_packet_buffer[1] = 126;

#warning Port is not connected.
#warning Port is not connected.
#warning Port is not connected.
#warning Port is not connected.
#warning Port is not connected.
#warning Port is not connected.

  UARTTx_packet_buffer[50] = 3;
  UARTTx_packet_buffer[51] = 3;
  UARTTxBlockingWrite(UARTTx_packet_buffer, 52);

  /* S-Function (stm32f4_digital_input): '<S1>/Digital Input' */
  BalanceFuzzy_B.DigitalInput = *EncoderDigitalInput_A0;

  /* S-Function (waijung_basic_customcode): '<S1>/Quadratur Encoder' */

  /*
   * Custom Code Block Output Function
   * Block: <S1>/Quadratur Encoder
   * BlockID: EncoderQuadraturEncoder
   * Input Port Definitions
   * in1: Port label 'inalpha', Type: boolean_T
   * in2: Port label 'intheta', Type: boolean_T
   * Output Port Definitions
   * out1: Port label 'alpha', Type: int32_T
   * out2: Port label ' theta', Type: int32_T
   */
  output_EncoderQuadraturEncoder(BalanceFuzzy_B.DigitalInput,
    BalanceFuzzy_B.DigitalInput , &BalanceFuzzy_B.QuadraturEncoder_o1,
    &BalanceFuzzy_B.QuadraturEncoder_o2);

  /* S-Function (pulsetoangle): '<S1>/S-Function Builder1' */
  pulsetoangle_Outputs_wrapper(&BalanceFuzzy_B.QuadraturEncoder_o1,
    &BalanceFuzzy_B.SFunctionBuilder1 );

  /* Gain: '<Root>/Gain1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Math: '<S1>/Math Function2'
   *  Sum: '<S1>/Add'
   */
  rtb_Switch = (rt_modd_snf(BalanceFuzzy_B.SFunctionBuilder1,
    BalanceFuzzy_P.Constant2_Value) - BalanceFuzzy_P.Constant1_Value) *
    BalanceFuzzy_P.Gain1_Gain;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Switch >= BalanceFuzzy_P.Saturation_UpperSat) {
    rtb_Saturation = BalanceFuzzy_P.Saturation_UpperSat;
  } else if (rtb_Switch <= BalanceFuzzy_P.Saturation_LowerSat) {
    rtb_Saturation = BalanceFuzzy_P.Saturation_LowerSat;
  } else {
    rtb_Saturation = rtb_Switch;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* If: '<S94>/If' incorporates:
   *  Constant: '<S97>/0'
   *  Constant: '<S99>/0'
   */
  if ((rtb_Saturation < -5.97) || (rtb_Saturation > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem' incorporates:
     *  ActionPort: '<S97>/Action Port'
     */
    rtb_Merge = BalanceFuzzy_P._Value;

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem' */
  } else if ((rtb_Saturation >= -3.46) && (rtb_Saturation <= -1.89)) {
    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S99>/Action Port'
     */
    rtb_Merge = BalanceFuzzy_P._Value_n;

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem2' */
  } else if (rtb_Saturation < -3.46) {
    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S98>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation, &rtb_Merge,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S94>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S100>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem3(rtb_Saturation, &rtb_Merge,
      (P_IfActionSubsystem3_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S94>/If Action Subsystem3' */
  }

  /* End of If: '<S94>/If' */

  /* S-Function (pulsetoangle1): '<S1>/S-Function Builder' */
  pulsetoangle1_Outputs_wrapper(&BalanceFuzzy_B.QuadraturEncoder_o2,
    &BalanceFuzzy_B.SFunctionBuilder );

  /* Gain: '<Root>/Gain4' incorporates:
   *  Gain: '<S1>/Gain'
   *  Sum: '<S1>/Sum'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Switch = (BalanceFuzzy_B.SFunctionBuilder -
                BalanceFuzzy_DW.UnitDelay_DSTATE) * BalanceFuzzy_P.Gain_Gain *
    BalanceFuzzy_P.Gain4_Gain;

  /* Saturate: '<Root>/Saturation3' */
  if (rtb_Switch >= BalanceFuzzy_P.Saturation3_UpperSat) {
    rtb_Saturation3 = BalanceFuzzy_P.Saturation3_UpperSat;
  } else if (rtb_Switch <= BalanceFuzzy_P.Saturation3_LowerSat) {
    rtb_Saturation3 = BalanceFuzzy_P.Saturation3_LowerSat;
  } else {
    rtb_Saturation3 = rtb_Switch;
  }

  /* End of Saturate: '<Root>/Saturation3' */

  /* If: '<S109>/If' incorporates:
   *  Constant: '<S112>/0'
   *  Constant: '<S113>/0'
   */
  if ((rtb_Saturation3 < -5.0) || (rtb_Saturation3 > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    rtb_Merge_b = BalanceFuzzy_P._Value_i;

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem' */
  } else if (rtb_Saturation3 == -1.0) {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    rtb_Merge_b = BalanceFuzzy_P._Value_ad;

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem1' */
  } else if (rtb_Saturation3 < -1.0) {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation3, &rtb_Merge_b,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_b);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem2(rtb_Saturation3, &rtb_Merge_b,
      (P_IfActionSubsystem2_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem2_a);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem2' */
  }

  /* End of If: '<S109>/If' */

  /* Gain: '<Root>/Gain2' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Sum: '<S1>/Sum1'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  rtb_Switch = (BalanceFuzzy_B.SFunctionBuilder1 -
                BalanceFuzzy_DW.UnitDelay1_DSTATE) * BalanceFuzzy_P.Gain1_Gain_c
    * BalanceFuzzy_P.Gain2_Gain;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Switch >= BalanceFuzzy_P.Saturation1_UpperSat) {
    rtb_Saturation1 = BalanceFuzzy_P.Saturation1_UpperSat;
  } else if (rtb_Switch <= BalanceFuzzy_P.Saturation1_LowerSat) {
    rtb_Saturation1 = BalanceFuzzy_P.Saturation1_LowerSat;
  } else {
    rtb_Saturation1 = rtb_Switch;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* If: '<S124>/If' incorporates:
   *  Constant: '<S127>/0'
   *  Constant: '<S128>/0'
   */
  if ((rtb_Saturation1 < -5.0) || (rtb_Saturation1 > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S124>/If Action Subsystem' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    rtb_Merge_p = BalanceFuzzy_P._Value_bx;

    /* End of Outputs for SubSystem: '<S124>/If Action Subsystem' */
  } else if (rtb_Saturation1 == -1.0) {
    /* Outputs for IfAction SubSystem: '<S124>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    rtb_Merge_p = BalanceFuzzy_P._Value_f;

    /* End of Outputs for SubSystem: '<S124>/If Action Subsystem1' */
  } else if (rtb_Saturation1 < -1.0) {
    /* Outputs for IfAction SubSystem: '<S124>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation1, &rtb_Merge_p,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_n);

    /* End of Outputs for SubSystem: '<S124>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S124>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem2(rtb_Saturation1, &rtb_Merge_p,
      (P_IfActionSubsystem2_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem2_i);

    /* End of Outputs for SubSystem: '<S124>/If Action Subsystem2' */
  }

  /* End of If: '<S124>/If' */

  /* Gain: '<Root>/Gain3' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant4'
   *  Math: '<S1>/Math Function1'
   *  Sum: '<S1>/Add1'
   */
  rtb_Switch = (rt_modd_snf(BalanceFuzzy_B.SFunctionBuilder,
    BalanceFuzzy_P.Constant4_Value) - BalanceFuzzy_P.Constant3_Value) *
    BalanceFuzzy_P.Gain3_Gain;

  /* Saturate: '<Root>/Saturation2' */
  if (rtb_Switch >= BalanceFuzzy_P.Saturation2_UpperSat) {
    rtb_Saturation2 = BalanceFuzzy_P.Saturation2_UpperSat;
  } else if (rtb_Switch <= BalanceFuzzy_P.Saturation2_LowerSat) {
    rtb_Saturation2 = BalanceFuzzy_P.Saturation2_LowerSat;
  } else {
    rtb_Saturation2 = rtb_Switch;
  }

  /* End of Saturate: '<Root>/Saturation2' */

  /* If: '<S139>/If' incorporates:
   *  Constant: '<S142>/0'
   *  Constant: '<S143>/0'
   */
  if ((rtb_Saturation2 < -12.57) || (rtb_Saturation2 > 0.0)) {
    /* Outputs for IfAction SubSystem: '<S139>/If Action Subsystem' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    rtb_Merge_m = BalanceFuzzy_P._Value_fs;

    /* End of Outputs for SubSystem: '<S139>/If Action Subsystem' */
  } else if (rtb_Saturation2 == -3.142) {
    /* Outputs for IfAction SubSystem: '<S139>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    rtb_Merge_m = BalanceFuzzy_P._Value_m;

    /* End of Outputs for SubSystem: '<S139>/If Action Subsystem1' */
  } else if (rtb_Saturation2 < -3.142) {
    /* Outputs for IfAction SubSystem: '<S139>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S145>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation2, &rtb_Merge_m,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_c);

    /* End of Outputs for SubSystem: '<S139>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S139>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S144>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem2(rtb_Saturation2, &rtb_Merge_m,
      (P_IfActionSubsystem2_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem2_b);

    /* End of Outputs for SubSystem: '<S139>/If Action Subsystem2' */
  }

  /* End of If: '<S139>/If' */

  /* Product: '<S7>/Weighting' incorporates:
   *  Constant: '<S7>/Weight'
   *  Product: '<S7>/andorMethod'
   */
  rtb_Switch = rtb_Merge * rtb_Merge_p * rtb_Merge_m * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value;

  /* If: '<S111>/If' incorporates:
   *  Constant: '<S120>/0'
   *  Constant: '<S121>/0'
   */
  if ((rtb_Saturation3 < -1.0) || (rtb_Saturation3 > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    rtb_Merge_o = BalanceFuzzy_P._Value_h;

    /* End of Outputs for SubSystem: '<S111>/If Action Subsystem' */
  } else if (rtb_Saturation3 == 0.0) {
    /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    rtb_Merge_o = BalanceFuzzy_P._Value_dq;

    /* End of Outputs for SubSystem: '<S111>/If Action Subsystem1' */
  } else if (rtb_Saturation3 < 0.0) {
    /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation3, &rtb_Merge_o,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_ni);

    /* End of Outputs for SubSystem: '<S111>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S111>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem2(rtb_Saturation3, &rtb_Merge_o,
      (P_IfActionSubsystem2_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem2_j);

    /* End of Outputs for SubSystem: '<S111>/If Action Subsystem2' */
  }

  /* End of If: '<S111>/If' */

  /* Product: '<S18>/Weighting' incorporates:
   *  Constant: '<S18>/Weight'
   *  Product: '<S18>/andorMethod'
   */
  rtb_Weighting_d = rtb_Merge * rtb_Merge_p * rtb_Merge_m * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_a;

  /* If: '<S110>/If' incorporates:
   *  Constant: '<S116>/0'
   *  Constant: '<S117>/0'
   */
  if ((rtb_Saturation3 < 0.0) || (rtb_Saturation3 > 2.0)) {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    rtb_Merge_j = BalanceFuzzy_P._Value_g;

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem' */
  } else if (rtb_Saturation3 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    rtb_Merge_j = BalanceFuzzy_P._Value_an;

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem1' */
  } else if (rtb_Saturation3 < 1.0) {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation3, &rtb_Merge_j,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_e);

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S110>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem2(rtb_Saturation3, &rtb_Merge_j,
      (P_IfActionSubsystem2_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem2_k);

    /* End of Outputs for SubSystem: '<S110>/If Action Subsystem2' */
  }

  /* End of If: '<S110>/If' */

  /* Product: '<S29>/Weighting' incorporates:
   *  Constant: '<S29>/Weight'
   *  Product: '<S29>/andorMethod'
   */
  rtb_Weighting_c = rtb_Merge * rtb_Merge_p * rtb_Merge_m * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_e;

  /* If: '<S141>/If' incorporates:
   *  Constant: '<S150>/0'
   *  Constant: '<S151>/0'
   */
  if ((rtb_Saturation2 < -3.142) || (rtb_Saturation2 > 3.142)) {
    /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    rtb_Merge_k = BalanceFuzzy_P._Value_e;

    /* End of Outputs for SubSystem: '<S141>/If Action Subsystem' */
  } else if (rtb_Saturation2 == 0.0) {
    /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    rtb_Merge_k = BalanceFuzzy_P._Value_o;

    /* End of Outputs for SubSystem: '<S141>/If Action Subsystem1' */
  } else if (rtb_Saturation2 < 0.0) {
    /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation2, &rtb_Merge_k,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_f);

    /* End of Outputs for SubSystem: '<S141>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem2(rtb_Saturation2, &rtb_Merge_k,
      (P_IfActionSubsystem2_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem2_h);

    /* End of Outputs for SubSystem: '<S141>/If Action Subsystem2' */
  }

  /* End of If: '<S141>/If' */

  /* Product: '<S40>/Weighting' incorporates:
   *  Constant: '<S40>/Weight'
   *  Product: '<S40>/andorMethod'
   */
  rtb_Weighting_k = rtb_Merge * rtb_Merge_p * rtb_Merge_k * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_o;

  /* Product: '<S51>/Weighting' incorporates:
   *  Constant: '<S51>/Weight'
   *  Product: '<S51>/andorMethod'
   */
  rtb_Weighting_h = rtb_Merge * rtb_Merge_p * rtb_Merge_k * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_m;

  /* Product: '<S62>/Weighting' incorporates:
   *  Constant: '<S62>/Weight'
   *  Product: '<S62>/andorMethod'
   */
  rtb_Weighting_b = rtb_Merge * rtb_Merge_p * rtb_Merge_k * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_d;

  /* If: '<S140>/If' incorporates:
   *  Constant: '<S146>/0'
   *  Constant: '<S147>/0'
   */
  if ((rtb_Saturation2 < 0.0) || (rtb_Saturation2 > 9.425)) {
    /* Outputs for IfAction SubSystem: '<S140>/If Action Subsystem' incorporates:
     *  ActionPort: '<S146>/Action Port'
     */
    rtb_Merge_g = BalanceFuzzy_P._Value_il;

    /* End of Outputs for SubSystem: '<S140>/If Action Subsystem' */
  } else if (rtb_Saturation2 == 3.142) {
    /* Outputs for IfAction SubSystem: '<S140>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S147>/Action Port'
     */
    rtb_Merge_g = BalanceFuzzy_P._Value_g2;

    /* End of Outputs for SubSystem: '<S140>/If Action Subsystem1' */
  } else if (rtb_Saturation2 < 3.142) {
    /* Outputs for IfAction SubSystem: '<S140>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S149>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation2, &rtb_Merge_g,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_ck);

    /* End of Outputs for SubSystem: '<S140>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S140>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S148>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem2(rtb_Saturation2, &rtb_Merge_g,
      (P_IfActionSubsystem2_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem2_m);

    /* End of Outputs for SubSystem: '<S140>/If Action Subsystem2' */
  }

  /* End of If: '<S140>/If' */

  /* Product: '<S73>/Weighting' incorporates:
   *  Constant: '<S73>/Weight'
   *  Product: '<S73>/andorMethod'
   */
  rtb_Weighting_l = rtb_Merge * rtb_Merge_p * rtb_Merge_g * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_h;

  /* Product: '<S84>/Weighting' incorporates:
   *  Constant: '<S84>/Weight'
   *  Product: '<S84>/andorMethod'
   */
  rtb_Weighting_f = rtb_Merge * rtb_Merge_p * rtb_Merge_g * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_k;

  /* Product: '<S87>/Weighting' incorporates:
   *  Constant: '<S87>/Weight'
   *  Product: '<S87>/andorMethod'
   */
  rtb_Weighting_g = rtb_Merge * rtb_Merge_p * rtb_Merge_g * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_ou;

  /* If: '<S126>/If' incorporates:
   *  Constant: '<S135>/0'
   *  Constant: '<S136>/0'
   */
  if ((rtb_Saturation1 < -1.0) || (rtb_Saturation1 > 1.0)) {
    /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem' incorporates:
     *  ActionPort: '<S135>/Action Port'
     */
    rtb_Merge_i = BalanceFuzzy_P._Value_bi;

    /* End of Outputs for SubSystem: '<S126>/If Action Subsystem' */
  } else if (rtb_Saturation1 == 0.0) {
    /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S136>/Action Port'
     */
    rtb_Merge_i = BalanceFuzzy_P._Value_fz;

    /* End of Outputs for SubSystem: '<S126>/If Action Subsystem1' */
  } else if (rtb_Saturation1 < 0.0) {
    /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S138>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation1, &rtb_Merge_i,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_cx);

    /* End of Outputs for SubSystem: '<S126>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S126>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S137>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem2(rtb_Saturation1, &rtb_Merge_i,
      (P_IfActionSubsystem2_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem2_k5);

    /* End of Outputs for SubSystem: '<S126>/If Action Subsystem2' */
  }

  /* End of If: '<S126>/If' */

  /* Product: '<S8>/Weighting' incorporates:
   *  Constant: '<S8>/Weight'
   *  Product: '<S8>/andorMethod'
   */
  rtb_Weighting_i = rtb_Merge * rtb_Merge_i * rtb_Merge_m * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_b;

  /* Product: '<S9>/Weighting' incorporates:
   *  Constant: '<S9>/Weight'
   *  Product: '<S9>/andorMethod'
   */
  rtb_Weighting_fu = rtb_Merge * rtb_Merge_i * rtb_Merge_m * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_p;

  /* Product: '<S10>/Weighting' incorporates:
   *  Constant: '<S10>/Weight'
   *  Product: '<S10>/andorMethod'
   */
  rtb_Weighting_cj = rtb_Merge * rtb_Merge_i * rtb_Merge_m * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_g;

  /* Product: '<S11>/Weighting' incorporates:
   *  Constant: '<S11>/Weight'
   *  Product: '<S11>/andorMethod'
   */
  rtb_Weighting_bd = rtb_Merge * rtb_Merge_i * rtb_Merge_k * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_ok;

  /* Product: '<S12>/Weighting' incorporates:
   *  Constant: '<S12>/Weight'
   *  Product: '<S12>/andorMethod'
   */
  rtb_Weighting_h1 = rtb_Merge * rtb_Merge_i * rtb_Merge_k * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_po;

  /* Product: '<S13>/Weighting' incorporates:
   *  Constant: '<S13>/Weight'
   *  Product: '<S13>/andorMethod'
   */
  rtb_Weighting_j = rtb_Merge * rtb_Merge_i * rtb_Merge_k * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_pl;

  /* Product: '<S14>/Weighting' incorporates:
   *  Constant: '<S14>/Weight'
   *  Product: '<S14>/andorMethod'
   */
  rtb_Weighting_lg = rtb_Merge * rtb_Merge_i * rtb_Merge_g * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_l;

  /* Product: '<S15>/Weighting' incorporates:
   *  Constant: '<S15>/Weight'
   *  Product: '<S15>/andorMethod'
   */
  rtb_Weighting_a = rtb_Merge * rtb_Merge_i * rtb_Merge_g * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_pp;

  /* Product: '<S16>/Weighting' incorporates:
   *  Constant: '<S16>/Weight'
   *  Product: '<S16>/andorMethod'
   */
  rtb_Weighting_m = rtb_Merge * rtb_Merge_i * rtb_Merge_g * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_kb;

  /* If: '<S125>/If' incorporates:
   *  Constant: '<S131>/0'
   *  Constant: '<S132>/0'
   */
  if ((rtb_Saturation1 < 0.0) || (rtb_Saturation1 > 3.0)) {
    /* Outputs for IfAction SubSystem: '<S125>/If Action Subsystem' incorporates:
     *  ActionPort: '<S131>/Action Port'
     */
    rtb_Merge_a = BalanceFuzzy_P._Value_nx;

    /* End of Outputs for SubSystem: '<S125>/If Action Subsystem' */
  } else if (rtb_Saturation1 == 1.0) {
    /* Outputs for IfAction SubSystem: '<S125>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S132>/Action Port'
     */
    rtb_Merge_a = BalanceFuzzy_P._Value_fa;

    /* End of Outputs for SubSystem: '<S125>/If Action Subsystem1' */
  } else if (rtb_Saturation1 < 1.0) {
    /* Outputs for IfAction SubSystem: '<S125>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S134>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation1, &rtb_Merge_a,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_p);

    /* End of Outputs for SubSystem: '<S125>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S125>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S133>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem2(rtb_Saturation1, &rtb_Merge_a,
      (P_IfActionSubsystem2_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem2_n);

    /* End of Outputs for SubSystem: '<S125>/If Action Subsystem2' */
  }

  /* End of If: '<S125>/If' */

  /* Product: '<S17>/Weighting' incorporates:
   *  Constant: '<S17>/Weight'
   *  Product: '<S17>/andorMethod'
   */
  rtb_Weighting_p = rtb_Merge * rtb_Merge_a * rtb_Merge_m * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_h3;

  /* Product: '<S19>/Weighting' incorporates:
   *  Constant: '<S19>/Weight'
   *  Product: '<S19>/andorMethod'
   */
  rtb_Weighting_k2 = rtb_Merge * rtb_Merge_a * rtb_Merge_m * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_bu;

  /* Product: '<S20>/Weighting' incorporates:
   *  Constant: '<S20>/Weight'
   *  Product: '<S20>/andorMethod'
   */
  rtb_Weighting_e = rtb_Merge * rtb_Merge_a * rtb_Merge_m * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_eh;

  /* Product: '<S21>/Weighting' incorporates:
   *  Constant: '<S21>/Weight'
   *  Product: '<S21>/andorMethod'
   */
  rtb_Weighting_e5 = rtb_Merge * rtb_Merge_a * rtb_Merge_k * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_ka;

  /* Product: '<S22>/Weighting' incorporates:
   *  Constant: '<S22>/Weight'
   *  Product: '<S22>/andorMethod'
   */
  rtb_Weighting_kj = rtb_Merge * rtb_Merge_a * rtb_Merge_k * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_kbs;

  /* Product: '<S23>/Weighting' incorporates:
   *  Constant: '<S23>/Weight'
   *  Product: '<S23>/andorMethod'
   */
  rtb_Weighting_bz = rtb_Merge * rtb_Merge_a * rtb_Merge_k * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_db;

  /* Product: '<S24>/Weighting' incorporates:
   *  Constant: '<S24>/Weight'
   *  Product: '<S24>/andorMethod'
   */
  rtb_Weighting_al = rtb_Merge * rtb_Merge_a * rtb_Merge_g * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_bk;

  /* Product: '<S25>/Weighting' incorporates:
   *  Constant: '<S25>/Weight'
   *  Product: '<S25>/andorMethod'
   */
  rtb_Weighting_o = rtb_Merge * rtb_Merge_a * rtb_Merge_g * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_hn;

  /* Product: '<S26>/Weighting' incorporates:
   *  Constant: '<S26>/Weight'
   *  Product: '<S26>/andorMethod'
   */
  rtb_Weighting_mp = rtb_Merge * rtb_Merge_a * rtb_Merge_g * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_n;

  /* If: '<S96>/If' incorporates:
   *  Constant: '<S105>/0'
   *  Constant: '<S106>/0'
   */
  if ((rtb_Saturation < -3.14159265358979) || (rtb_Saturation > 3.14)) {
    /* Outputs for IfAction SubSystem: '<S96>/If Action Subsystem' incorporates:
     *  ActionPort: '<S105>/Action Port'
     */
    rtb_Merge_gm = BalanceFuzzy_P._Value_b;

    /* End of Outputs for SubSystem: '<S96>/If Action Subsystem' */
  } else if (rtb_Saturation == 0.0) {
    /* Outputs for IfAction SubSystem: '<S96>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S106>/Action Port'
     */
    rtb_Merge_gm = BalanceFuzzy_P._Value_k;

    /* End of Outputs for SubSystem: '<S96>/If Action Subsystem1' */
  } else if (rtb_Saturation < 0.0) {
    /* Outputs for IfAction SubSystem: '<S96>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S108>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation, &rtb_Merge_gm,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_h);

    /* End of Outputs for SubSystem: '<S96>/If Action Subsystem3' */
  } else {
    /* Outputs for IfAction SubSystem: '<S96>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S107>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem2(rtb_Saturation, &rtb_Merge_gm,
      (P_IfActionSubsystem2_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem2_kv);

    /* End of Outputs for SubSystem: '<S96>/If Action Subsystem2' */
  }

  /* End of If: '<S96>/If' */

  /* Product: '<S27>/Weighting' incorporates:
   *  Constant: '<S27>/Weight'
   *  Product: '<S27>/andorMethod'
   */
  rtb_Weighting_pc = rtb_Merge_gm * rtb_Merge_p * rtb_Merge_m * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_g3;

  /* Product: '<S28>/Weighting' incorporates:
   *  Constant: '<S28>/Weight'
   *  Product: '<S28>/andorMethod'
   */
  rtb_Weighting_lf = rtb_Merge_gm * rtb_Merge_p * rtb_Merge_m * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_i;

  /* Product: '<S30>/Weighting' incorporates:
   *  Constant: '<S30>/Weight'
   *  Product: '<S30>/andorMethod'
   */
  rtb_Weighting_fv = rtb_Merge_gm * rtb_Merge_p * rtb_Merge_m * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_pm;

  /* Product: '<S31>/Weighting' incorporates:
   *  Constant: '<S31>/Weight'
   *  Product: '<S31>/andorMethod'
   */
  rtb_Weighting_bw = rtb_Merge_gm * rtb_Merge_p * rtb_Merge_k * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_of;

  /* Product: '<S32>/Weighting' incorporates:
   *  Constant: '<S32>/Weight'
   *  Product: '<S32>/andorMethod'
   */
  rtb_Weighting_gk = rtb_Merge_gm * rtb_Merge_p * rtb_Merge_k * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_p3;

  /* Product: '<S33>/Weighting' incorporates:
   *  Constant: '<S33>/Weight'
   *  Product: '<S33>/andorMethod'
   */
  rtb_Weighting_jb = rtb_Merge_gm * rtb_Merge_p * rtb_Merge_k * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_c;

  /* Product: '<S34>/Weighting' incorporates:
   *  Constant: '<S34>/Weight'
   *  Product: '<S34>/andorMethod'
   */
  rtb_Weighting_op = rtb_Merge_gm * rtb_Merge_p * rtb_Merge_g * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_oh;

  /* Product: '<S35>/Weighting' incorporates:
   *  Constant: '<S35>/Weight'
   *  Product: '<S35>/andorMethod'
   */
  rtb_Weighting_jo = rtb_Merge_gm * rtb_Merge_p * rtb_Merge_g * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_j;

  /* Product: '<S36>/Weighting' incorporates:
   *  Constant: '<S36>/Weight'
   *  Product: '<S36>/andorMethod'
   */
  rtb_Weighting_bv = rtb_Merge_gm * rtb_Merge_p * rtb_Merge_g * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_f;

  /* Product: '<S37>/Weighting' incorporates:
   *  Constant: '<S37>/Weight'
   *  Product: '<S37>/andorMethod'
   */
  rtb_Weighting_iq = rtb_Merge_gm * rtb_Merge_i * rtb_Merge_m * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_nj;

  /* Product: '<S38>/Weighting' incorporates:
   *  Constant: '<S38>/Weight'
   *  Product: '<S38>/andorMethod'
   */
  rtb_Weighting_dr = rtb_Merge_gm * rtb_Merge_i * rtb_Merge_m * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_nt;

  /* Product: '<S39>/Weighting' incorporates:
   *  Constant: '<S39>/Weight'
   *  Product: '<S39>/andorMethod'
   */
  rtb_Weighting_dd = rtb_Merge_gm * rtb_Merge_i * rtb_Merge_m * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_lz;

  /* Product: '<S41>/Weighting' incorporates:
   *  Constant: '<S41>/Weight'
   *  Product: '<S41>/andorMethod'
   */
  rtb_Weighting_b2 = rtb_Merge_gm * rtb_Merge_i * rtb_Merge_k * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_oa;

  /* Product: '<S42>/Weighting' incorporates:
   *  Constant: '<S42>/Weight'
   *  Product: '<S42>/andorMethod'
   */
  rtb_Weighting_hs = rtb_Merge_gm * rtb_Merge_i * rtb_Merge_k * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_dy;

  /* Product: '<S43>/Weighting' incorporates:
   *  Constant: '<S43>/Weight'
   *  Product: '<S43>/andorMethod'
   */
  rtb_Weighting_cz = rtb_Merge_gm * rtb_Merge_i * rtb_Merge_k * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_h5;

  /* Product: '<S44>/Weighting' incorporates:
   *  Constant: '<S44>/Weight'
   *  Product: '<S44>/andorMethod'
   */
  rtb_Weighting_jl = rtb_Merge_gm * rtb_Merge_i * rtb_Merge_g * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_jv;

  /* Product: '<S45>/Weighting' incorporates:
   *  Constant: '<S45>/Weight'
   *  Product: '<S45>/andorMethod'
   */
  rtb_Weighting_gy = rtb_Merge_gm * rtb_Merge_i * rtb_Merge_g * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_li;

  /* Product: '<S46>/Weighting' incorporates:
   *  Constant: '<S46>/Weight'
   *  Product: '<S46>/andorMethod'
   */
  rtb_Weighting_cw = rtb_Merge_gm * rtb_Merge_i * rtb_Merge_g * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_o2;

  /* Product: '<S47>/Weighting' incorporates:
   *  Constant: '<S47>/Weight'
   *  Product: '<S47>/andorMethod'
   */
  rtb_Weighting_a5 = rtb_Merge_gm * rtb_Merge_a * rtb_Merge_m * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_ir;

  /* Product: '<S48>/Weighting' incorporates:
   *  Constant: '<S48>/Weight'
   *  Product: '<S48>/andorMethod'
   */
  rtb_Weighting_fh = rtb_Merge_gm * rtb_Merge_a * rtb_Merge_m * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_hj;

  /* Product: '<S49>/Weighting' incorporates:
   *  Constant: '<S49>/Weight'
   *  Product: '<S49>/andorMethod'
   */
  rtb_Weighting_oy = rtb_Merge_gm * rtb_Merge_a * rtb_Merge_m * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_pv;

  /* Product: '<S50>/Weighting' incorporates:
   *  Constant: '<S50>/Weight'
   *  Product: '<S50>/andorMethod'
   */
  rtb_Weighting_n = rtb_Merge_gm * rtb_Merge_a * rtb_Merge_k * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_a1;

  /* Product: '<S52>/Weighting' incorporates:
   *  Constant: '<S52>/Weight'
   *  Product: '<S52>/andorMethod'
   */
  rtb_Weighting_ee = rtb_Merge_gm * rtb_Merge_a * rtb_Merge_k * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_liq;

  /* Product: '<S53>/Weighting' incorporates:
   *  Constant: '<S53>/Weight'
   *  Product: '<S53>/andorMethod'
   */
  rtb_Weighting_hf = rtb_Merge_gm * rtb_Merge_a * rtb_Merge_k * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_jy;

  /* Product: '<S54>/Weighting' incorporates:
   *  Constant: '<S54>/Weight'
   *  Product: '<S54>/andorMethod'
   */
  rtb_Weighting_ar = rtb_Merge_gm * rtb_Merge_a * rtb_Merge_g * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_dq;

  /* Product: '<S55>/Weighting' incorporates:
   *  Constant: '<S55>/Weight'
   *  Product: '<S55>/andorMethod'
   */
  rtb_Weighting_o2 = rtb_Merge_gm * rtb_Merge_a * rtb_Merge_g * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_na;

  /* Product: '<S56>/Weighting' incorporates:
   *  Constant: '<S56>/Weight'
   *  Product: '<S56>/andorMethod'
   */
  rtb_Weighting_o0 = rtb_Merge_gm * rtb_Merge_a * rtb_Merge_g * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_n5;

  /* If: '<S95>/If' incorporates:
   *  Constant: '<S101>/0'
   *  Constant: '<S103>/0'
   */
  if ((rtb_Saturation < 0.0) || (rtb_Saturation > 5.82)) {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem' incorporates:
     *  ActionPort: '<S101>/Action Port'
     */
    rtb_Merge_h = BalanceFuzzy_P._Value_a;

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem' */
  } else if ((rtb_Saturation >= 2.05) && (rtb_Saturation <= 4.18)) {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S103>/Action Port'
     */
    rtb_Merge_h = BalanceFuzzy_P._Value_d;

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem2' */
  } else if (rtb_Saturation < 2.05) {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S102>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem1(rtb_Saturation, &rtb_Merge_h,
      (P_IfActionSubsystem1_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem1_iv);

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem1' */
  } else {
    /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S104>/Action Port'
     */
    BalanceFuzzy_IfActionSubsystem3(rtb_Saturation, &rtb_Merge_h,
      (P_IfActionSubsystem3_BalanceF_T *)&BalanceFuzzy_P.IfActionSubsystem3_i);

    /* End of Outputs for SubSystem: '<S95>/If Action Subsystem3' */
  }

  /* End of If: '<S95>/If' */

  /* Product: '<S57>/Weighting' incorporates:
   *  Constant: '<S57>/Weight'
   *  Product: '<S57>/andorMethod'
   */
  rtb_Weighting_by = rtb_Merge_h * rtb_Merge_p * rtb_Merge_m * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_mm;

  /* Product: '<S58>/Weighting' incorporates:
   *  Constant: '<S58>/Weight'
   *  Product: '<S58>/andorMethod'
   */
  rtb_Weighting_md = rtb_Merge_h * rtb_Merge_p * rtb_Merge_m * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_fx;

  /* Product: '<S59>/Weighting' incorporates:
   *  Constant: '<S59>/Weight'
   *  Product: '<S59>/andorMethod'
   */
  rtb_Weighting_ns = rtb_Merge_h * rtb_Merge_p * rtb_Merge_m * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_in;

  /* Product: '<S60>/Weighting' incorporates:
   *  Constant: '<S60>/Weight'
   *  Product: '<S60>/andorMethod'
   */
  rtb_Weighting_ad = rtb_Merge_h * rtb_Merge_p * rtb_Merge_k * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_c3;

  /* Product: '<S61>/Weighting' incorporates:
   *  Constant: '<S61>/Weight'
   *  Product: '<S61>/andorMethod'
   */
  rtb_Weighting_cv = rtb_Merge_h * rtb_Merge_p * rtb_Merge_k * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_m1;

  /* Product: '<S63>/Weighting' incorporates:
   *  Constant: '<S63>/Weight'
   *  Product: '<S63>/andorMethod'
   */
  rtb_Weighting_fd = rtb_Merge_h * rtb_Merge_p * rtb_Merge_k * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_b3;

  /* Product: '<S64>/Weighting' incorporates:
   *  Constant: '<S64>/Weight'
   *  Product: '<S64>/andorMethod'
   */
  rtb_Weighting_p2 = rtb_Merge_h * rtb_Merge_p * rtb_Merge_g * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_bd;

  /* Product: '<S65>/Weighting' incorporates:
   *  Constant: '<S65>/Weight'
   *  Product: '<S65>/andorMethod'
   */
  rtb_Weighting_kv = rtb_Merge_h * rtb_Merge_p * rtb_Merge_g * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_jx;

  /* Product: '<S66>/Weighting' incorporates:
   *  Constant: '<S66>/Weight'
   *  Product: '<S66>/andorMethod'
   */
  rtb_Weighting_gv = rtb_Merge_h * rtb_Merge_p * rtb_Merge_g * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_k4;

  /* Product: '<S67>/Weighting' incorporates:
   *  Constant: '<S67>/Weight'
   *  Product: '<S67>/andorMethod'
   */
  rtb_Weighting_drb = rtb_Merge_h * rtb_Merge_i * rtb_Merge_m * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_kt;

  /* Product: '<S68>/Weighting' incorporates:
   *  Constant: '<S68>/Weight'
   *  Product: '<S68>/andorMethod'
   */
  rtb_Weighting_hd = rtb_Merge_h * rtb_Merge_i * rtb_Merge_m * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_d5;

  /* Product: '<S69>/Weighting' incorporates:
   *  Constant: '<S69>/Weight'
   *  Product: '<S69>/andorMethod'
   */
  rtb_Weighting_nk = rtb_Merge_h * rtb_Merge_i * rtb_Merge_m * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_ls;

  /* Product: '<S70>/Weighting' incorporates:
   *  Constant: '<S70>/Weight'
   *  Product: '<S70>/andorMethod'
   */
  rtb_Weighting_ei = rtb_Merge_h * rtb_Merge_i * rtb_Merge_k * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_a0;

  /* Product: '<S71>/Weighting' incorporates:
   *  Constant: '<S71>/Weight'
   *  Product: '<S71>/andorMethod'
   */
  rtb_Weighting_czj = rtb_Merge_h * rtb_Merge_i * rtb_Merge_k * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_pa;

  /* Product: '<S72>/Weighting' incorporates:
   *  Constant: '<S72>/Weight'
   *  Product: '<S72>/andorMethod'
   */
  rtb_Weighting_ok = rtb_Merge_h * rtb_Merge_i * rtb_Merge_k * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_mc;

  /* Product: '<S74>/Weighting' incorporates:
   *  Constant: '<S74>/Weight'
   *  Product: '<S74>/andorMethod'
   */
  rtb_Weighting_ai = rtb_Merge_h * rtb_Merge_i * rtb_Merge_g * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_d1;

  /* Product: '<S75>/Weighting' incorporates:
   *  Constant: '<S75>/Weight'
   *  Product: '<S75>/andorMethod'
   */
  rtb_Weighting_it = rtb_Merge_h * rtb_Merge_i * rtb_Merge_g * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_l2;

  /* Product: '<S76>/Weighting' incorporates:
   *  Constant: '<S76>/Weight'
   *  Product: '<S76>/andorMethod'
   */
  rtb_Weighting_cn = rtb_Merge_h * rtb_Merge_i * rtb_Merge_g * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_hy;

  /* Product: '<S77>/Weighting' incorporates:
   *  Constant: '<S77>/Weight'
   *  Product: '<S77>/andorMethod'
   */
  rtb_Weighting_gs = rtb_Merge_h * rtb_Merge_a * rtb_Merge_m * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_fb;

  /* Product: '<S78>/Weighting' incorporates:
   *  Constant: '<S78>/Weight'
   *  Product: '<S78>/andorMethod'
   */
  rtb_Weighting_g2 = rtb_Merge_h * rtb_Merge_a * rtb_Merge_m * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_em;

  /* Product: '<S79>/Weighting' incorporates:
   *  Constant: '<S79>/Weight'
   *  Product: '<S79>/andorMethod'
   */
  rtb_Weighting_h5 = rtb_Merge_h * rtb_Merge_a * rtb_Merge_m * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_dm;

  /* Product: '<S80>/Weighting' incorporates:
   *  Constant: '<S80>/Weight'
   *  Product: '<S80>/andorMethod'
   */
  rtb_Weighting_fo = rtb_Merge_h * rtb_Merge_a * rtb_Merge_k * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_jm;

  /* Product: '<S81>/Weighting' incorporates:
   *  Constant: '<S81>/Weight'
   *  Product: '<S81>/andorMethod'
   */
  rtb_Weighting_ag = rtb_Merge_h * rtb_Merge_a * rtb_Merge_k * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_do;

  /* Product: '<S82>/Weighting' incorporates:
   *  Constant: '<S82>/Weight'
   *  Product: '<S82>/andorMethod'
   */
  rtb_Weighting_dc = rtb_Merge_h * rtb_Merge_a * rtb_Merge_k * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_oe;

  /* Product: '<S83>/Weighting' incorporates:
   *  Constant: '<S83>/Weight'
   *  Product: '<S83>/andorMethod'
   */
  rtb_Weighting_nq = rtb_Merge_h * rtb_Merge_a * rtb_Merge_g * rtb_Merge_b *
    BalanceFuzzy_P.Weight_Value_iu;

  /* Product: '<S85>/Weighting' incorporates:
   *  Constant: '<S85>/Weight'
   *  Product: '<S85>/andorMethod'
   */
  rtb_Weighting_cc = rtb_Merge_h * rtb_Merge_a * rtb_Merge_g * rtb_Merge_o *
    BalanceFuzzy_P.Weight_Value_fi;

  /* Product: '<S86>/Weighting' incorporates:
   *  Constant: '<S86>/Weight'
   *  Product: '<S86>/andorMethod'
   */
  rtb_Weighting_dj = rtb_Merge_h * rtb_Merge_a * rtb_Merge_g * rtb_Merge_j *
    BalanceFuzzy_P.Weight_Value_a0s;

  /* Sum: '<S4>/Total Firing Strength' */
  rtb_TotalFiringStrength =
    (((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
    ((rtb_Switch + rtb_Weighting_d) + rtb_Weighting_c) + rtb_Weighting_k) +
    rtb_Weighting_h) + rtb_Weighting_b) + rtb_Weighting_l) + rtb_Weighting_f) +
    rtb_Weighting_g) + rtb_Weighting_i) + rtb_Weighting_fu) + rtb_Weighting_cj)
    + rtb_Weighting_bd) + rtb_Weighting_h1) + rtb_Weighting_j) +
    rtb_Weighting_lg) + rtb_Weighting_a) + rtb_Weighting_m) + rtb_Weighting_p) +
    rtb_Weighting_k2) + rtb_Weighting_e) + rtb_Weighting_e5) + rtb_Weighting_kj)
    + rtb_Weighting_bz) + rtb_Weighting_al) + rtb_Weighting_o) +
    rtb_Weighting_mp) + rtb_Weighting_pc) + rtb_Weighting_lf) + rtb_Weighting_fv)
    + rtb_Weighting_bw) + rtb_Weighting_gk) + rtb_Weighting_jb) +
    rtb_Weighting_op) + rtb_Weighting_jo) + rtb_Weighting_bv) + rtb_Weighting_iq)
    + rtb_Weighting_dr) + rtb_Weighting_dd) + rtb_Weighting_b2) +
    rtb_Weighting_hs) + rtb_Weighting_cz) + rtb_Weighting_jl) + rtb_Weighting_gy)
    + rtb_Weighting_cw) + rtb_Weighting_a5) + rtb_Weighting_fh) +
    rtb_Weighting_oy) + rtb_Weighting_n) + rtb_Weighting_ee) + rtb_Weighting_hf)
    + rtb_Weighting_ar) + rtb_Weighting_o2) + rtb_Weighting_o0) +
    rtb_Weighting_by) + rtb_Weighting_md) + rtb_Weighting_ns) + rtb_Weighting_ad)
    + rtb_Weighting_cv) + rtb_Weighting_fd) + rtb_Weighting_p2) +
                       rtb_Weighting_kv) + rtb_Weighting_gv) + rtb_Weighting_drb)
                    + rtb_Weighting_hd) + rtb_Weighting_nk) + rtb_Weighting_ei)
                 + rtb_Weighting_czj) + rtb_Weighting_ok) + rtb_Weighting_ai) +
              rtb_Weighting_it) + rtb_Weighting_cn) + rtb_Weighting_gs) +
           rtb_Weighting_g2) + rtb_Weighting_h5) + rtb_Weighting_fo) +
        rtb_Weighting_ag) + rtb_Weighting_dc) + rtb_Weighting_nq) +
     rtb_Weighting_cc) + rtb_Weighting_dj;

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/MidRange'
   *  Constant: '<S4>/Zero'
   *  Product: '<S5>/Product'
   *  RelationalOperator: '<S4>/Zero Firing Strength?'
   */
  if ((rtb_TotalFiringStrength > BalanceFuzzy_P.Zero_Value) >=
      BalanceFuzzy_P.Switch_Threshold) {
    /* Sum: '<S5>/Sum1' incorporates:
     *  Constant: '<S88>/NB(Constant)'
     *  Constant: '<S88>/NM(Constant)'
     *  Constant: '<S88>/NS(Constant)'
     *  Constant: '<S88>/PB(Constant)'
     *  Constant: '<S88>/PM(Constant)'
     *  Constant: '<S88>/PS(Constant)'
     *  Constant: '<S88>/ZE(Constant)'
     *  Product: '<S10>/impMethod'
     *  Product: '<S11>/impMethod'
     *  Product: '<S12>/impMethod'
     *  Product: '<S13>/impMethod'
     *  Product: '<S14>/impMethod'
     *  Product: '<S15>/impMethod'
     *  Product: '<S16>/impMethod'
     *  Product: '<S17>/impMethod'
     *  Product: '<S18>/impMethod'
     *  Product: '<S19>/impMethod'
     *  Product: '<S20>/impMethod'
     *  Product: '<S21>/impMethod'
     *  Product: '<S22>/impMethod'
     *  Product: '<S23>/impMethod'
     *  Product: '<S24>/impMethod'
     *  Product: '<S25>/impMethod'
     *  Product: '<S26>/impMethod'
     *  Product: '<S27>/impMethod'
     *  Product: '<S28>/impMethod'
     *  Product: '<S29>/impMethod'
     *  Product: '<S30>/impMethod'
     *  Product: '<S31>/impMethod'
     *  Product: '<S32>/impMethod'
     *  Product: '<S33>/impMethod'
     *  Product: '<S34>/impMethod'
     *  Product: '<S35>/impMethod'
     *  Product: '<S36>/impMethod'
     *  Product: '<S37>/impMethod'
     *  Product: '<S38>/impMethod'
     *  Product: '<S39>/impMethod'
     *  Product: '<S40>/impMethod'
     *  Product: '<S41>/impMethod'
     *  Product: '<S42>/impMethod'
     *  Product: '<S43>/impMethod'
     *  Product: '<S44>/impMethod'
     *  Product: '<S45>/impMethod'
     *  Product: '<S46>/impMethod'
     *  Product: '<S47>/impMethod'
     *  Product: '<S48>/impMethod'
     *  Product: '<S49>/impMethod'
     *  Product: '<S50>/impMethod'
     *  Product: '<S51>/impMethod'
     *  Product: '<S52>/impMethod'
     *  Product: '<S53>/impMethod'
     *  Product: '<S54>/impMethod'
     *  Product: '<S55>/impMethod'
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
     *  Product: '<S7>/impMethod'
     *  Product: '<S80>/impMethod'
     *  Product: '<S81>/impMethod'
     *  Product: '<S82>/impMethod'
     *  Product: '<S83>/impMethod'
     *  Product: '<S84>/impMethod'
     *  Product: '<S85>/impMethod'
     *  Product: '<S86>/impMethod'
     *  Product: '<S87>/impMethod'
     *  Product: '<S8>/impMethod'
     *  Product: '<S9>/impMethod'
     */
    tmpForInput[0] = rtb_Switch * BalanceFuzzy_P.PBConstant_Value;
    tmpForInput[1] = rtb_Weighting_d * BalanceFuzzy_P.PBConstant_Value;
    tmpForInput[2] = rtb_Weighting_c * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[3] = rtb_Weighting_k * BalanceFuzzy_P.PBConstant_Value;
    tmpForInput[4] = rtb_Weighting_h * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[5] = rtb_Weighting_b * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[6] = rtb_Weighting_l * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[7] = rtb_Weighting_f * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[8] = rtb_Weighting_g * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[9] = rtb_Weighting_i * BalanceFuzzy_P.PBConstant_Value;
    tmpForInput[10] = rtb_Weighting_fu * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[11] = rtb_Weighting_cj * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[12] = rtb_Weighting_bd * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[13] = rtb_Weighting_h1 * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[14] = rtb_Weighting_j * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[15] = rtb_Weighting_lg * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[16] = rtb_Weighting_a * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[17] = rtb_Weighting_m * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[18] = rtb_Weighting_p * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[19] = rtb_Weighting_k2 * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[20] = rtb_Weighting_e * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[21] = rtb_Weighting_e5 * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[22] = rtb_Weighting_kj * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[23] = rtb_Weighting_bz * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[24] = rtb_Weighting_al * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[25] = rtb_Weighting_o * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[26] = rtb_Weighting_mp * BalanceFuzzy_P.NMConstant_Value;
    tmpForInput[27] = rtb_Weighting_pc * BalanceFuzzy_P.PBConstant_Value;
    tmpForInput[28] = rtb_Weighting_lf * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[29] = rtb_Weighting_fv * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[30] = rtb_Weighting_bw * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[31] = rtb_Weighting_gk * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[32] = rtb_Weighting_jb * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[33] = rtb_Weighting_op * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[34] = rtb_Weighting_jo * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[35] = rtb_Weighting_bv * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[36] = rtb_Weighting_iq * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[37] = rtb_Weighting_dr * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[38] = rtb_Weighting_dd * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[39] = rtb_Weighting_b2 * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[40] = rtb_Weighting_hs * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[41] = rtb_Weighting_cz * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[42] = rtb_Weighting_jl * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[43] = rtb_Weighting_gy * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[44] = rtb_Weighting_cw * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[45] = rtb_Weighting_a5 * BalanceFuzzy_P.NMConstant_Value;
    tmpForInput[46] = rtb_Weighting_fh * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[47] = rtb_Weighting_oy * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[48] = rtb_Weighting_n * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[49] = rtb_Weighting_ee * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[50] = rtb_Weighting_hf * BalanceFuzzy_P.NMConstant_Value;
    tmpForInput[51] = rtb_Weighting_ar * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[52] = rtb_Weighting_o2 * BalanceFuzzy_P.NMConstant_Value;
    tmpForInput[53] = rtb_Weighting_o0 * BalanceFuzzy_P.NBConstant_Value;
    tmpForInput[54] = rtb_Weighting_by * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[55] = rtb_Weighting_md * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[56] = rtb_Weighting_ns * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[57] = rtb_Weighting_ad * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[58] = rtb_Weighting_cv * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[59] = rtb_Weighting_fd * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[60] = rtb_Weighting_p2 * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[61] = rtb_Weighting_kv * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[62] = rtb_Weighting_gv * BalanceFuzzy_P.PMConstant_Value;
    tmpForInput[63] = rtb_Weighting_drb * BalanceFuzzy_P.PSConstant_Value;
    tmpForInput[64] = rtb_Weighting_hd * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[65] = rtb_Weighting_nk * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[66] = rtb_Weighting_ei * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[67] = rtb_Weighting_czj * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[68] = rtb_Weighting_ok * BalanceFuzzy_P.NMConstant_Value;
    tmpForInput[69] = rtb_Weighting_ai * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[70] = rtb_Weighting_it * BalanceFuzzy_P.NMConstant_Value;
    tmpForInput[71] = rtb_Weighting_cn * BalanceFuzzy_P.NBConstant_Value;
    tmpForInput[72] = rtb_Weighting_gs * BalanceFuzzy_P.ZEConstant_Value;
    tmpForInput[73] = rtb_Weighting_g2 * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[74] = rtb_Weighting_h5 * BalanceFuzzy_P.NMConstant_Value;
    tmpForInput[75] = rtb_Weighting_fo * BalanceFuzzy_P.NSConstant_Value;
    tmpForInput[76] = rtb_Weighting_ag * BalanceFuzzy_P.NMConstant_Value;
    tmpForInput[77] = rtb_Weighting_dc * BalanceFuzzy_P.NBConstant_Value;
    tmpForInput[78] = rtb_Weighting_nq * BalanceFuzzy_P.NMConstant_Value;
    tmpForInput[79] = rtb_Weighting_cc * BalanceFuzzy_P.NBConstant_Value;
    tmpForInput[80] = rtb_Weighting_dj * BalanceFuzzy_P.NBConstant_Value;
    rtb_Switch *= BalanceFuzzy_P.PBConstant_Value;
    for (i = 0; i < 80; i++) {
      rtb_Switch += tmpForInput[i + 1];
    }

    /* End of Sum: '<S5>/Sum1' */

    /* If: '<S5>/If' incorporates:
     *  Constant: '<S92>/One'
     */
    if (rtb_TotalFiringStrength < 0.0) {
      /* Outputs for IfAction SubSystem: '<S5>/Action: One' incorporates:
       *  ActionPort: '<S92>/Action Port'
       */
      rtb_TotalFiringStrength = BalanceFuzzy_P.One_Value;

      /* End of Outputs for SubSystem: '<S5>/Action: One' */
    }

    /* End of If: '<S5>/If' */
    rtb_Switch /= rtb_TotalFiringStrength;
  } else {
    rtb_Switch = BalanceFuzzy_P.MidRange_Value;
  }

  /* End of Switch: '<S4>/Switch' */

  /* Gain: '<Root>/Gain5' */
  rtb_Switch *= BalanceFuzzy_P.Gain5_Gain;

  /* MATLAB Function: '<Root>/V_control' */
  /* MATLAB Function 'V_control': '<S3>:1' */
  if (rtb_Switch < 0.0) {
    /* '<S3>:1:3' */
    /* '<S3>:1:4' */
    BalanceFuzzy_B.DIR = 0.0;

    /* '<S3>:1:5' */
    BalanceFuzzy_B.PWM = -rtb_Switch * 100.0 / 24.0;
  } else {
    /*      DIR=1; */
    /*      PWM=u*100/24; */
    /* '<S3>:1:9' */
    BalanceFuzzy_B.DIR = 1.0;

    /* '<S3>:1:10' */
    BalanceFuzzy_B.PWM = rtb_Switch * 100.0 / 24.0;
  }

  /* End of MATLAB Function: '<Root>/V_control' */

  /* S-Function Block: <Root>/Basic PWM (stm32f4_basicpwm) */
  TIM3->CCR1 = (uint32_t) (BalanceFuzzy_B.PWM * BasicPWM_SF);

  /* S-Function (stm32f4_digital_output): '<Root>/Digital Output' */

  /* DigitalOutput */
  *DigitalOutput_D12 = (boolean_T) BalanceFuzzy_B.DIR;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  BalanceFuzzy_DW.UnitDelay_DSTATE = BalanceFuzzy_B.SFunctionBuilder;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  BalanceFuzzy_DW.UnitDelay1_DSTATE = BalanceFuzzy_B.SFunctionBuilder1;
}

/* Model initialize function */
void BalanceFuzzy_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(BalanceFuzzy_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &BalanceFuzzy_B), 0,
                sizeof(B_BalanceFuzzy_T));

  /* states (dwork) */
  (void) memset((void *)&BalanceFuzzy_DW, 0,
                sizeof(DW_BalanceFuzzy_T));

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  BalanceFuzzy_DW.UnitDelay_DSTATE = BalanceFuzzy_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay1' */
  BalanceFuzzy_DW.UnitDelay1_DSTATE = BalanceFuzzy_P.UnitDelay1_InitialCondition;

  /* Level2 S-Function Block: '<Root>/UART Tx' (stm32f4_usart) */
  enable_UARTTx();

  /* Level2 S-Function Block: '<Root>/UART Setup' (stm32f4_usart) */
  enable_UARTSetup();

  /* Level2 S-Function Block: '<S1>/Digital Input' (stm32f4_digital_input) */
  enable_EncoderDigitalInput();

  /* Level2 S-Function Block: '<S1>/Quadratur Encoder' (waijung_basic_customcode) */
  enable_EncoderQuadraturEncoder();

  /* Level2 S-Function Block: '<Root>/Basic PWM' (stm32f4_basicpwm) */
  enable_BasicPWM();

  /* Level2 S-Function Block: '<Root>/Digital Output' (stm32f4_digital_output) */
  enable_DigitalOutput();
}

/* Model terminate function */
void BalanceFuzzy_terminate(void)
{
  /* Terminate for S-Function (stm32f4_usart): '<Root>/UART Tx' */

  /* terminate_UARTTx(); */

  /* Terminate for S-Function (stm32f4_usart): '<Root>/UART Setup' */

  /* terminate_UARTSetup(); */

  /* Terminate for S-Function (stm32f4_digital_input): '<S1>/Digital Input' */

  /* terminate_EncoderDigitalInput(); */

  /* Terminate for S-Function (stm32f4_basicpwm): '<Root>/Basic PWM' */

  /* terminate_BasicPWM(); */

  /* Terminate for S-Function (stm32f4_digital_output): '<Root>/Digital Output' */

  /* terminate_DigitalOutput(); */
}

/* [EOF] */
