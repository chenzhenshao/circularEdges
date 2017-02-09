/*
 * positionControlLoopCircle.c
 *
 * Real-Time Workshop code generation for Simulink model "positionControlLoopCircle.mdl".
 *
 * Model version              : 1.109
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Tue Jan 24 00:13:25 2017
 *
 * Target selection: rti1103.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "positionControlLoopCircle_trc_ptr.h"
#include "positionControlLoopCircle.h"
#include "positionControlLoopCircle_private.h"

/* Block signals (auto storage) */
BlockIO_positionControlLoopCirc positionControlLoopCircle_B;

/* Block states (auto storage) */
D_Work_positionControlLoopCircl positionControlLoopCircle_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_positionControl positionControlL_PrevZCSigState;

/* Real-time model */
RT_MODEL_positionControlLoopCir positionControlLoopCircle_M_;
RT_MODEL_positionControlLoopCir *positionControlLoopCircle_M =
  &positionControlLoopCircle_M_;

/* Model output function */
static void positionControlLoopCircle_output(int_T tid)
{
  uint32_T initialOffset;
  real_T tmp;
  real_T tmp_0;

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlLoopCircle_B.LogicalOperator1 =
    !(positionControlLoopCircle_P.startX_Value != 0.0);

  /* Product: '<Root>/Product3' incorporates:
   *  Constant: '<Root>/input'
   */
  positionControlLoopCircle_B.Product3 = (real_T)
    positionControlLoopCircle_B.LogicalOperator1 *
    positionControlLoopCircle_P.input_Value;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/startX'
   */
  if ((positionControlLoopCircle_P.startX_Value > 0.0) &&
      (positionControlLoopCircle_DWork.DiscreteTimeIntegrator_PrevRese <= 0)) {
    positionControlLoopCircle_DWork.DiscreteTimeIntegrator_DSTATE =
      positionControlLoopCircle_P.DiscreteTimeIntegrator_IC;
  }

  positionControlLoopCircle_B.DiscreteTimeIntegrator =
    positionControlLoopCircle_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<Root>/index' */
  positionControlLoopCircle_B.index = positionControlLoopCircle_P.index_Gain *
    positionControlLoopCircle_B.DiscreteTimeIntegrator;

  /* LookupNDDirect: '<Root>/circY'
   *
   * About '<Root>/circY':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  tmp_0 = rt_SATURATE(positionControlLoopCircle_B.index, 0.0, 2513.0);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(floor(tmp_0), 4.294967296E+009);
  }

  initialOffset = tmp_0 < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp_0))) :
    (uint32_T)tmp_0;
  positionControlLoopCircle_B.circY =
    positionControlLoopCircle_P.circY_table[initialOffset];

  /* Product: '<Root>/Product5' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlLoopCircle_B.Product5 = positionControlLoopCircle_B.circY *
    positionControlLoopCircle_P.startX_Value;

  /* Sum: '<Root>/ypos' */
  positionControlLoopCircle_B.ypos = positionControlLoopCircle_B.Product3 +
    positionControlLoopCircle_B.Product5;

  /* S-Function (rti_commonblock): '<S17>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S17>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<S2>/EncoderGain' */
  positionControlLoopCircle_B.EncoderGain[0] =
    positionControlLoopCircle_P.EncoderGain_Gain *
    positionControlLoopCircle_B.SFunction1;
  positionControlLoopCircle_B.EncoderGain[1] =
    positionControlLoopCircle_P.EncoderGain_Gain *
    positionControlLoopCircle_B.SFunction2;

  /* Sum: '<Root>/yerror' */
  positionControlLoopCircle_B.yerror = positionControlLoopCircle_B.ypos -
    positionControlLoopCircle_B.EncoderGain[0];

  /* S-Function (sfix_udelay): '<S23>/Tapped Delay' */
  positionControlLoopCircle_B.TappedDelay =
    positionControlLoopCircle_DWork.TappedDelay_X;

  /* Sum: '<S8>/Add3' incorporates:
   *  Constant: '<Root>/centery'
   */
  positionControlLoopCircle_B.Add3 = positionControlLoopCircle_B.ypos -
    positionControlLoopCircle_P.centery_Value;

  /* LookupNDDirect: '<Root>/circX'
   *
   * About '<Root>/circX':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  tmp_0 = rt_SATURATE(positionControlLoopCircle_B.index, 0.0, 2513.0);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(floor(tmp_0), 4.294967296E+009);
  }

  initialOffset = tmp_0 < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-tmp_0))) :
    (uint32_T)tmp_0;
  positionControlLoopCircle_B.circX =
    positionControlLoopCircle_P.circX_table[initialOffset];

  /* Product: '<Root>/Product4' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlLoopCircle_B.Product4 =
    positionControlLoopCircle_P.startX_Value * positionControlLoopCircle_B.circX;

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlLoopCircle_B.LogicalOperator =
    !(positionControlLoopCircle_P.startX_Value != 0.0);

  /* Product: '<Root>/Product2' incorporates:
   *  Constant: '<Root>/input2'
   */
  positionControlLoopCircle_B.Product2 =
    positionControlLoopCircle_P.input2_Value * (real_T)
    positionControlLoopCircle_B.LogicalOperator;

  /* Sum: '<Root>/xpos' */
  positionControlLoopCircle_B.xpos = positionControlLoopCircle_B.Product4 +
    positionControlLoopCircle_B.Product2;

  /* Sum: '<S8>/Add1' incorporates:
   *  Constant: '<Root>/centerx'
   */
  positionControlLoopCircle_B.Add1 = positionControlLoopCircle_B.xpos -
    positionControlLoopCircle_P.centerx_Value;

  /* Trigonometry: '<S8>/Trigonometric Function' */
  positionControlLoopCircle_B.TrigonometricFunction = rt_atan2_snf
    (positionControlLoopCircle_B.Add3, positionControlLoopCircle_B.Add1);

  /* Trigonometry: '<S8>/Trigonometric Function2' */
  positionControlLoopCircle_B.TrigonometricFunction2 = sin
    (positionControlLoopCircle_B.TrigonometricFunction);

  /* Trigonometry: '<S8>/Trigonometric Function1' */
  positionControlLoopCircle_B.TrigonometricFunction1 = cos
    (positionControlLoopCircle_B.TrigonometricFunction);

  /* Fcn: '<S8>/Fcn1' incorporates:
   *  Constant: '<Root>/2pi45'
   *  Constant: '<Root>/centerx1'
   */
  tmp_0 = positionControlLoopCircle_P.pi45_Value;
  tmp = rt_pow_snf(tmp_0, 2.0);
  tmp_0 = positionControlLoopCircle_P.centerx1_Value;
  tmp_0 = rt_pow_snf(tmp_0, 2.0);
  tmp_0 = fabs(tmp * positionControlLoopCircle_B.TrigonometricFunction1 - tmp_0 *
               positionControlLoopCircle_B.TrigonometricFunction2);
  tmp_0 = sqrt(tmp_0);
  positionControlLoopCircle_B.Fcn1 = tmp_0;

  /* Abs: '<S8>/Abs1' */
  positionControlLoopCircle_B.Abs1 = fabs(positionControlLoopCircle_B.Fcn1);

  /* Fcn: '<S10>/Drterm2' incorporates:
   *  Constant: '<Root>/B'
   *  Constant: '<Root>/J'
   *  Constant: '<Root>/zeta2'
   */
  positionControlLoopCircle_B.Drterm2 = (2.0 *
    positionControlLoopCircle_P.zeta2_Value * positionControlLoopCircle_B.Abs1 *
    0.01 - 2.0) / (2.0 * positionControlLoopCircle_P.zeta2_Value *
                   positionControlLoopCircle_B.Abs1 * 0.01 + 2.0);

  /* DotProduct: '<S23>/Dot1' */
  positionControlLoopCircle_B.Dot1 = positionControlLoopCircle_B.TappedDelay *
    positionControlLoopCircle_B.Drterm2;

  /* Sum: '<S23>/Sum' */
  positionControlLoopCircle_B.Sum = positionControlLoopCircle_B.yerror -
    positionControlLoopCircle_B.Dot1;

  /* DataTypeConversion: '<S23>/Downcast1' */
  positionControlLoopCircle_B.Downcast1 = positionControlLoopCircle_B.Sum;

  /* SignalConversion: '<S23>/TmpSignal ConversionAtDot2Inport1' */
  positionControlLoopCircle_B.TmpSignalConversionAtDot2Inport[0] =
    positionControlLoopCircle_B.Downcast1;
  positionControlLoopCircle_B.TmpSignalConversionAtDot2Inport[1] =
    positionControlLoopCircle_B.TappedDelay;

  /* Fcn: '<S10>/Nrterm1' incorporates:
   *  Constant: '<Root>/B'
   *  Constant: '<Root>/J'
   *  Constant: '<Root>/zeta2'
   */
  tmp_0 = positionControlLoopCircle_B.Abs1;
  tmp = rt_pow_snf(tmp_0, 2.0);
  tmp_0 = positionControlLoopCircle_B.Abs1;
  tmp_0 = rt_pow_snf(tmp_0, 2.0);
  positionControlLoopCircle_B.Nrterm1 = (2.0 *
    positionControlLoopCircle_P.J_Value * tmp +
    positionControlLoopCircle_P.B_Value * tmp_0 * 0.01) / (2.0 *
    positionControlLoopCircle_P.zeta2_Value * positionControlLoopCircle_B.Abs1 *
    0.01 + 2.0);

  /* Fcn: '<S10>/Nrterm2' incorporates:
   *  Constant: '<Root>/B'
   *  Constant: '<Root>/J'
   *  Constant: '<Root>/zeta2'
   */
  tmp_0 = positionControlLoopCircle_B.Abs1;
  tmp = rt_pow_snf(tmp_0, 2.0);
  tmp_0 = positionControlLoopCircle_B.Abs1;
  tmp_0 = rt_pow_snf(tmp_0, 2.0);
  positionControlLoopCircle_B.Nrterm2 = (positionControlLoopCircle_P.B_Value *
    0.01 * tmp - 2.0 * positionControlLoopCircle_P.J_Value * tmp_0) / (2.0 *
    positionControlLoopCircle_P.zeta2_Value * positionControlLoopCircle_B.Abs1 *
    0.01 + 2.0);

  /* SignalConversion: '<S23>/TmpSignal ConversionAtDot2Inport2' */
  positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_i[0] =
    positionControlLoopCircle_B.Nrterm1;
  positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_i[1] =
    positionControlLoopCircle_B.Nrterm2;

  /* DotProduct: '<S23>/Dot2' */
  tmp_0 = positionControlLoopCircle_B.TmpSignalConversionAtDot2Inport[0] *
    positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_i[0];
  tmp_0 += positionControlLoopCircle_B.TmpSignalConversionAtDot2Inport[1] *
    positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_i[1];
  positionControlLoopCircle_B.Dot2 = tmp_0;

  /* DataTypeConversion: '<S23>/Downcast' */
  positionControlLoopCircle_B.Downcast = positionControlLoopCircle_B.Dot2;

  /* Fcn: '<S8>/Fcn' incorporates:
   *  Constant: '<Root>/2pi45'
   *  Constant: '<Root>/centerx1'
   */
  tmp_0 = positionControlLoopCircle_P.centerx1_Value;
  tmp = rt_pow_snf(tmp_0, 2.0);
  tmp_0 = positionControlLoopCircle_P.pi45_Value;
  tmp_0 = rt_pow_snf(tmp_0, 2.0);
  tmp_0 = fabs(tmp * positionControlLoopCircle_B.TrigonometricFunction1 + tmp_0 *
               positionControlLoopCircle_B.TrigonometricFunction2);
  tmp_0 = sqrt(tmp_0);
  positionControlLoopCircle_B.Fcn = tmp_0;

  /* Abs: '<S8>/Abs' */
  positionControlLoopCircle_B.Abs = fabs(positionControlLoopCircle_B.Fcn);

  /* Fcn: '<Root>/Fcn1' */
  tmp_0 = positionControlLoopCircle_B.Abs;
  tmp_0 = rt_pow_snf(tmp_0, 2.0);
  positionControlLoopCircle_B.Fcn1_l = tmp_0;

  /* S-Function (rti_commonblock): '<S15>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S15>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S13>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S13>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Sum: '<S1>/Add' */
  positionControlLoopCircle_B.Add[0] = positionControlLoopCircle_B.SFunction1_b
    + positionControlLoopCircle_B.SFunction1_f;
  positionControlLoopCircle_B.Add[1] = positionControlLoopCircle_B.SFunction2_l
    + positionControlLoopCircle_B.SFunction2_h;

  /* Gain: '<S1>/EncoderGain' */
  positionControlLoopCircle_B.EncoderGain_j[0] =
    positionControlLoopCircle_P.EncoderGain_Gain_o *
    positionControlLoopCircle_B.Add[0];

  /* Gain: '<S1>/convert2radians ' */
  positionControlLoopCircle_B.convert2radians[0] =
    positionControlLoopCircle_P.convert2radians_Gain *
    positionControlLoopCircle_B.EncoderGain_j[0];

  /* Gain: '<S1>/EncoderGain' */
  positionControlLoopCircle_B.EncoderGain_j[1] =
    positionControlLoopCircle_P.EncoderGain_Gain_o *
    positionControlLoopCircle_B.Add[1];

  /* Gain: '<S1>/convert2radians ' */
  positionControlLoopCircle_B.convert2radians[1] =
    positionControlLoopCircle_P.convert2radians_Gain *
    positionControlLoopCircle_B.EncoderGain_j[1];

  /* Sum: '<Root>/xerror' */
  positionControlLoopCircle_B.xerror = positionControlLoopCircle_B.xpos -
    positionControlLoopCircle_B.convert2radians[0];

  /* S-Function (sfix_udelay): '<S22>/Tapped Delay' */
  positionControlLoopCircle_B.TappedDelay_d =
    positionControlLoopCircle_DWork.TappedDelay_X_l;

  /* Fcn: '<S9>/Drterm2' incorporates:
   *  Constant: '<Root>/B1'
   *  Constant: '<Root>/J1'
   *  Constant: '<Root>/zeta1'
   */
  positionControlLoopCircle_B.Drterm2_k = (2.0 *
    positionControlLoopCircle_P.zeta1_Value * positionControlLoopCircle_B.Abs *
    0.01 - 2.0) / (2.0 * positionControlLoopCircle_P.zeta1_Value *
                   positionControlLoopCircle_B.Abs * 0.01 + 2.0);

  /* DotProduct: '<S22>/Dot1' */
  positionControlLoopCircle_B.Dot1_d = positionControlLoopCircle_B.TappedDelay_d
    * positionControlLoopCircle_B.Drterm2_k;

  /* Sum: '<S22>/Sum' */
  positionControlLoopCircle_B.Sum_h = positionControlLoopCircle_B.xerror -
    positionControlLoopCircle_B.Dot1_d;

  /* DataTypeConversion: '<S22>/Downcast1' */
  positionControlLoopCircle_B.Downcast1_b = positionControlLoopCircle_B.Sum_h;

  /* SignalConversion: '<S22>/TmpSignal ConversionAtDot2Inport1' */
  positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_j[0] =
    positionControlLoopCircle_B.Downcast1_b;
  positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_j[1] =
    positionControlLoopCircle_B.TappedDelay_d;

  /* Fcn: '<S9>/Nrterm1' incorporates:
   *  Constant: '<Root>/B1'
   *  Constant: '<Root>/J1'
   *  Constant: '<Root>/zeta1'
   */
  tmp_0 = positionControlLoopCircle_B.Abs;
  tmp = rt_pow_snf(tmp_0, 2.0);
  tmp_0 = positionControlLoopCircle_B.Abs;
  tmp_0 = rt_pow_snf(tmp_0, 2.0);
  positionControlLoopCircle_B.Nrterm1_a = (2.0 *
    positionControlLoopCircle_P.J1_Value * tmp +
    positionControlLoopCircle_P.B1_Value * tmp_0 * 0.01) / (2.0 *
    positionControlLoopCircle_P.zeta1_Value * positionControlLoopCircle_B.Abs *
    0.01 + 2.0);

  /* Fcn: '<S9>/Nrterm2' incorporates:
   *  Constant: '<Root>/B1'
   *  Constant: '<Root>/J1'
   *  Constant: '<Root>/zeta1'
   */
  tmp_0 = positionControlLoopCircle_B.Abs;
  tmp = rt_pow_snf(tmp_0, 2.0);
  tmp_0 = positionControlLoopCircle_B.Abs;
  tmp_0 = rt_pow_snf(tmp_0, 2.0);
  positionControlLoopCircle_B.Nrterm2_b = (positionControlLoopCircle_P.B1_Value *
    0.01 * tmp - 2.0 * positionControlLoopCircle_P.J1_Value * tmp_0) / (2.0 *
    positionControlLoopCircle_P.zeta1_Value * positionControlLoopCircle_B.Abs *
    0.01 + 2.0);

  /* SignalConversion: '<S22>/TmpSignal ConversionAtDot2Inport2' */
  positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_c[0] =
    positionControlLoopCircle_B.Nrterm1_a;
  positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_c[1] =
    positionControlLoopCircle_B.Nrterm2_b;

  /* DotProduct: '<S22>/Dot2' */
  tmp_0 = positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_j[0] *
    positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_c[0];
  tmp_0 += positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_j[1] *
    positionControlLoopCircle_B.TmpSignalConversionAtDot2Inpo_c[1];
  positionControlLoopCircle_B.Dot2_k = tmp_0;

  /* DataTypeConversion: '<S22>/Downcast' */
  positionControlLoopCircle_B.Downcast_p = positionControlLoopCircle_B.Dot2_k;

  /* Fcn: '<Root>/Fcn' */
  tmp_0 = positionControlLoopCircle_B.Abs1;
  tmp_0 = rt_pow_snf(tmp_0, 2.0);
  positionControlLoopCircle_B.Fcn_c = tmp_0;

  /* Product: '<Root>/Product1' incorporates:
   *  Constant: '<Root>/DA On-Off'
   */
  positionControlLoopCircle_B.Product1 =
    positionControlLoopCircle_P.DAOnOff_Value *
    positionControlLoopCircle_B.Downcast_p;

  /* Gain: '<Root>/DA GainY1' */
  positionControlLoopCircle_B.DAGainY1 =
    positionControlLoopCircle_P.DAGainY1_Gain *
    positionControlLoopCircle_B.Product1;

  /* S-Function (rti_commonblock): '<S11>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(1, positionControlLoopCircle_B.DAGainY1);

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/DA On-Off'
   */
  positionControlLoopCircle_B.Product =
    positionControlLoopCircle_P.DAOnOff_Value *
    positionControlLoopCircle_B.Downcast;

  /* Gain: '<Root>/DA GainY' */
  positionControlLoopCircle_B.DAGainY = positionControlLoopCircle_P.DAGainY_Gain
    * positionControlLoopCircle_B.Product;

  /* S-Function (rti_commonblock): '<S12>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(2, positionControlLoopCircle_B.DAGainY);

  /* Outputs for trigger SubSystem: '<S1>/DS1103ENC_SET_POS_C2' incorporates:
   *  Constant: '<Root>/ENC Reset'
   *  TriggerPort: '<S14>/Trigger'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &positionControlL_PrevZCSigState.DS1103ENC_SET_POS_C2_Trig_ZCE,
               (positionControlLoopCircle_P.ENCReset_Value)) != NO_ZCEVENT) {
    /* S-Function (rti_commonblock): '<S14>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1103 Unit:ENC_SET */
    ds1103_inc_position_write(2, 0, DS1103_INC_LINE_SUBDIV_4);
  }

  /* end of Outputs for SubSystem: '<S1>/DS1103ENC_SET_POS_C2' */

  /* Outputs for trigger SubSystem: '<S1>/_DS1103ENC_SET_POS_C1' incorporates:
   *  Constant: '<Root>/ENC Reset'
   *  TriggerPort: '<S16>/Trigger'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &positionControlL_PrevZCSigState._DS1103ENC_SET_POS_C1_Trig_ZCE,
               (positionControlLoopCircle_P.ENCReset_Value)) != NO_ZCEVENT) {
    /* S-Function (rti_commonblock): '<S16>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1103 Unit:ENC_SET */
    ds1103_inc_position_write(1, 0, DS1103_INC_LINE_SUBDIV_4);
  }

  /* end of Outputs for SubSystem: '<S1>/_DS1103ENC_SET_POS_C1' */

  /* Outputs for trigger SubSystem: '<S2>/DS1103ENC_SET_POS_C3' incorporates:
   *  Constant: '<Root>/ENC Reset'
   *  TriggerPort: '<S18>/Trigger'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &positionControlL_PrevZCSigState.DS1103ENC_SET_POS_C3_Trig_ZCE,
               (positionControlLoopCircle_P.ENCReset_Value)) != NO_ZCEVENT) {
    /* S-Function (rti_commonblock): '<S18>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1103 Unit:ENC_SET */
    ds1103_inc_position_write(3, 0, DS1103_INC_LINE_SUBDIV_4);
  }

  /* end of Outputs for SubSystem: '<S2>/DS1103ENC_SET_POS_C3' */

  /* Fcn: '<S8>/Fcn2' */
  tmp_0 = positionControlLoopCircle_B.Fcn;
  tmp = rt_pow_snf(tmp_0, 2.0);
  tmp_0 = positionControlLoopCircle_B.Fcn1;
  tmp_0 = rt_pow_snf(tmp_0, 2.0);
  positionControlLoopCircle_B.Fcn2 = tmp + tmp_0;

  /* Gain: '<Root>/currentNegated' */
  positionControlLoopCircle_B.currentNegated =
    positionControlLoopCircle_P.currentNegated_Gain *
    positionControlLoopCircle_B.Product;

  /* Gain: '<Root>/differentiated' */
  positionControlLoopCircle_B.differentiated =
    positionControlLoopCircle_P.differentiated_Gain *
    positionControlLoopCircle_B.convert2radians[1];

  /* Gain: '<Root>/differentiated1' */
  positionControlLoopCircle_B.differentiated1 =
    positionControlLoopCircle_P.differentiated1_Gain *
    positionControlLoopCircle_B.EncoderGain[1];

  /* S-Function (rti_commonblock): '<S3>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<Root>/ADC Gain' */
  positionControlLoopCircle_B.ADCGain = positionControlLoopCircle_P.ADCGain_Gain
    * positionControlLoopCircle_B.SFunction;

  /* Gain: '<Root>/GainFx' */
  positionControlLoopCircle_B.GainFx = positionControlLoopCircle_P.GainFx_Gain *
    positionControlLoopCircle_B.ADCGain;

  /* S-Function (rti_commonblock): '<S4>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<Root>/ADC Gain1' */
  positionControlLoopCircle_B.ADCGain1 =
    positionControlLoopCircle_P.ADCGain1_Gain *
    positionControlLoopCircle_B.SFunction_a;

  /* Gain: '<Root>/GainFy' */
  positionControlLoopCircle_B.GainFy = positionControlLoopCircle_P.GainFy_Gain *
    positionControlLoopCircle_B.ADCGain1;

  /* S-Function (rti_commonblock): '<S5>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<Root>/ADC Gain2' */
  positionControlLoopCircle_B.ADCGain2 =
    positionControlLoopCircle_P.ADCGain2_Gain *
    positionControlLoopCircle_B.SFunction_b;

  /* Gain: '<Root>/GainFz' */
  positionControlLoopCircle_B.GainFz = positionControlLoopCircle_P.GainFz_Gain *
    positionControlLoopCircle_B.ADCGain2;

  /* S-Function (rti_commonblock): '<S6>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function3' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function4' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function5' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function6' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S6>/S-Function7' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* user code (Output function Trailer) */

  /* dSPACE Data Capture block: (none) */
  /* ... Service number: 1 */
  /* ... Service name:   (default) */
  {
    host_service(1, rtk_current_task_absolute_time_ptr_get());
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
static void positionControlLoopCircle_update(int_T tid)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlLoopCircle_DWork.DiscreteTimeIntegrator_DSTATE =
    positionControlLoopCircle_P.DiscreteTimeIntegrator_gainval *
    positionControlLoopCircle_P.startX_Value +
    positionControlLoopCircle_DWork.DiscreteTimeIntegrator_DSTATE;
  if (positionControlLoopCircle_P.startX_Value > 0.0) {
    positionControlLoopCircle_DWork.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (positionControlLoopCircle_P.startX_Value < 0.0) {
    positionControlLoopCircle_DWork.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (positionControlLoopCircle_P.startX_Value == 0.0) {
    positionControlLoopCircle_DWork.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    positionControlLoopCircle_DWork.DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* Update for S-Function (sfix_udelay): '<S23>/Tapped Delay' */
  positionControlLoopCircle_DWork.TappedDelay_X =
    positionControlLoopCircle_B.Downcast1;

  /* Update for S-Function (sfix_udelay): '<S22>/Tapped Delay' */
  positionControlLoopCircle_DWork.TappedDelay_X_l =
    positionControlLoopCircle_B.Downcast1_b;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++positionControlLoopCircle_M->Timing.clockTick0)) {
    ++positionControlLoopCircle_M->Timing.clockTickH0;
  }

  positionControlLoopCircle_M->Timing.t[0] =
    positionControlLoopCircle_M->Timing.clockTick0 *
    positionControlLoopCircle_M->Timing.stepSize0 +
    positionControlLoopCircle_M->Timing.clockTickH0 *
    positionControlLoopCircle_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void positionControlLoopCircle_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)positionControlLoopCircle_M, 0,
                sizeof(RT_MODEL_positionControlLoopCir));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = positionControlLoopCircle_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    positionControlLoopCircle_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    positionControlLoopCircle_M->Timing.sampleTimes =
      (&positionControlLoopCircle_M->Timing.sampleTimesArray[0]);
    positionControlLoopCircle_M->Timing.offsetTimes =
      (&positionControlLoopCircle_M->Timing.offsetTimesArray[0]);

    /* task periods */
    positionControlLoopCircle_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    positionControlLoopCircle_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(positionControlLoopCircle_M,
             &positionControlLoopCircle_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = positionControlLoopCircle_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    positionControlLoopCircle_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(positionControlLoopCircle_M, -1);
  positionControlLoopCircle_M->Timing.stepSize0 = 0.01;
  positionControlLoopCircle_M->solverInfoPtr =
    (&positionControlLoopCircle_M->solverInfo);
  positionControlLoopCircle_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&positionControlLoopCircle_M->solverInfo, 0.01);
  rtsiSetSolverMode(&positionControlLoopCircle_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  positionControlLoopCircle_M->ModelData.blockIO = ((void *)
    &positionControlLoopCircle_B);
  (void) memset(((void *) &positionControlLoopCircle_B), 0,
                sizeof(BlockIO_positionControlLoopCirc));

  /* parameters */
  positionControlLoopCircle_M->ModelData.defaultParam = ((real_T *)
    &positionControlLoopCircle_P);

  /* states (dwork) */
  positionControlLoopCircle_M->Work.dwork = ((void *)
    &positionControlLoopCircle_DWork);
  (void) memset((void *)&positionControlLoopCircle_DWork, 0,
                sizeof(D_Work_positionControlLoopCircl));

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  positionControlL_PrevZCSigState.DS1103ENC_SET_POS_C3_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
  positionControlL_PrevZCSigState._DS1103ENC_SET_POS_C1_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
  positionControlL_PrevZCSigState.DS1103ENC_SET_POS_C2_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void positionControlLoopCircle_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S11>/S-Function1' */

  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(1, 0);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  positionControlLoopCircle_output(tid);
}

void MdlUpdate(int_T tid)
{
  positionControlLoopCircle_update(tid);
}

void MdlInitializeSizes(void)
{
  positionControlLoopCircle_M->Sizes.numContStates = (0);/* Number of continuous states */
  positionControlLoopCircle_M->Sizes.numY = (0);/* Number of model outputs */
  positionControlLoopCircle_M->Sizes.numU = (0);/* Number of model inputs */
  positionControlLoopCircle_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  positionControlLoopCircle_M->Sizes.numSampTimes = (1);/* Number of sample times */
  positionControlLoopCircle_M->Sizes.numBlocks = (122);/* Number of blocks */
  positionControlLoopCircle_M->Sizes.numBlockIO = (74);/* Number of block outputs */
  positionControlLoopCircle_M->Sizes.numBlockPrms = (5062);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  positionControlLoopCircle_DWork.DiscreteTimeIntegrator_DSTATE =
    positionControlLoopCircle_P.DiscreteTimeIntegrator_IC;
  positionControlLoopCircle_DWork.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for S-Function (sfix_udelay): '<S23>/Tapped Delay' */
  positionControlLoopCircle_DWork.TappedDelay_X =
    positionControlLoopCircle_P.TappedDelay_InitialCondition;

  /* InitializeConditions for S-Function (sfix_udelay): '<S22>/Tapped Delay' */
  positionControlLoopCircle_DWork.TappedDelay_X_l =
    positionControlLoopCircle_P.TappedDelay_InitialCondition_j;
}

void MdlStart(void)
{
  MdlInitialize();
}

void MdlTerminate(void)
{
  positionControlLoopCircle_terminate();
}

RT_MODEL_positionControlLoopCir *positionControlLoopCircle(void)
{
  positionControlLoopCircle_initialize(1);
  return positionControlLoopCircle_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
