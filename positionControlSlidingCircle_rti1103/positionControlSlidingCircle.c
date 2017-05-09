/*
 * positionControlSlidingCircle.c
 *
 * Real-Time Workshop code generation for Simulink model "positionControlSlidingCircle.mdl".
 *
 * Model version              : 1.171
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Tue May 09 11:04:09 2017
 *
 * Target selection: rti1103.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "positionControlSlidingCircle_trc_ptr.h"
#include "positionControlSlidingCircle.h"
#include "positionControlSlidingCircle_private.h"

/* Block signals (auto storage) */
BlockIO_positionControlSlidingC positionControlSlidingCircle_B;

/* Block states (auto storage) */
D_Work_positionControlSlidingCi positionControlSlidingCir_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_positionControl positionControlS_PrevZCSigState;

/* Real-time model */
RT_MODEL_positionControlSliding positionControlSlidingCircle_M_;
RT_MODEL_positionControlSliding *positionControlSlidingCircle_M =
  &positionControlSlidingCircle_M_;
void MWDSPCG_Pseudoinverse_D(real_T pS[], real_T pU[], real_T pV[], real_T pX[],
  const int32_T M, const int32_T N)
{
  int32_T ppSIdx;
  real_T tol;
  real_T cabsS;
  int32_T P;
  int32_T rank;
  int32_T ppXIdx;
  int32_T ppUIdx;
  int32_T ppVIdx;
  int32_T j;
  int32_T k;
  rank = 0;
  P = rt_MIN(M, N);
  cabsS = fabs(pS[0]);
  if (0.0 < cabsS) {
    rank = 1;
    tol = (real_T)rt_MAX(M, N) * pS[0U] * 2.2204460492503131E-016;
    ppSIdx = P - 1;
    while (P > 0) {
      cabsS = fabs(pS[ppSIdx]);
      ppSIdx = ppSIdx - 1;
      if (cabsS >= tol) {
        rank = P;
        P = 0;
      }

      P = P - 1;
    }
  }

  ppXIdx = 0;
  for (P = 0; P < N * M; P = P + 1) {
    pX[ppXIdx] = 0.0;
    ppXIdx = ppXIdx + 1;
  }

  if (rank != 0) {
    ppXIdx = 0;
    for (j = 0; j < M; j = j + 1) {
      for (P = 0; P < N; P = P + 1) {
        ppVIdx = P;
        ppUIdx = j;
        ppSIdx = 0;
        for (k = 0; k < rank; k = k + 1) {
          cabsS = pV[ppVIdx] * pU[ppUIdx] / pS[ppSIdx];
          pX[ppXIdx] = pX[ppXIdx] + cabsS;
          ppSIdx = ppSIdx + 1;
          ppVIdx = ppVIdx + N;
          ppUIdx = ppUIdx + M;
        }

        ppXIdx = ppXIdx + 1;
      }
    }
  }
}

void LUf_int32_Treal_T(real_T outU[], real_T outP[], const int32_T N)
{
  int32_T k;
  int32_T c;
  int32_T r;
  int32_T idx1;
  real_T tmp;
  int32_T p;
  real_T mTmp1;
  boolean_T isDiagZero;
  real_T mAccum;

  /* initialize row-pivot indices */
  for (k = 0; k < N; k = k + 1) {
    outP[k] = (real_T)(k + 1);
  }

  for (k = 0; k < N; k = k + 1) {
    p = k;

    /* Scan the lower triangular part of this column only. */
    /* Record row of largest value */
    idx1 = k * N;
    mTmp1 = outU[idx1 + k];
    if (mTmp1 < 0.0) {
      mTmp1 = -mTmp1;
    }

    for (r = k + 1; r < N; r = r + 1) {
      tmp = outU[idx1 + r];
      if (tmp < 0.0) {
        tmp = -tmp;
      }

      if (tmp > mTmp1) {
        p = r;
        mTmp1 = tmp;
      }
    }

    /* swap rows if required */
    if (p != k) {
      for (c = 0; c < N; c = c + 1) {
        idx1 = c * N;
        mTmp1 = outU[idx1 + p];
        tmp = outU[idx1 + k];
        outU[idx1 + p] = tmp;
        outU[idx1 + k] = mTmp1;
      }

      /* swap pivot row indices */
      tmp = outP[p];
      outP[p] = outP[k];
      outP[k] = tmp;
    }

    idx1 = k * N + k;
    isDiagZero = FALSE;
    if (outU[idx1] == 0.0) {
      isDiagZero = TRUE;
    }

    if (!isDiagZero) {
      p = k * N;
      for (r = k + 1; r < N; r = r + 1) {
        mTmp1 = outU[p + r];
        tmp = outU[idx1];
        outU[p + r] = mTmp1 / tmp;
      }

      for (c = k + 1; c < N; c = c + 1) {
        idx1 = c * N;
        for (r = k + 1; r < N; r = r + 1) {
          mAccum = outU[idx1 + r];
          mTmp1 = outU[p + r];
          tmp = outU[idx1 + k] * mTmp1;
          mAccum = mAccum - tmp;
          outU[idx1 + r] = mAccum;
        }
      }
    }
  }
}

/* Model output function */
static void positionControlSlidingCircle_output(int_T tid)
{
  uint32_T initialOffset;
  int32_T k;
  int32_T idxLU;
  real_T denAccum;
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  real_T tmp_3;
  real_T tmp_4;
  real_T tmp_5;
  real_T tmp_6;
  real_T tmp_7;
  real_T tmp_8;
  real_T tmp_9;
  real_T tmp_a;
  real_T tmp_b;
  real_T tmp_c;
  real_T tmp_d;
  real_T tmp_e;
  real_T tmp_f;
  real_T tmp_g;
  real_T tmp_h;
  real_T tmp_i;
  real_T tmp_j;
  real_T tmp_k;
  real_T tmp_l;
  real_T tmp_m;
  real_T tmp_n;
  real_T tmp_o;
  real_T tmp_p;
  real_T tmp_q;
  real_T tmp_r;
  real_T tmp_s;
  real_T tmp_t;
  real_T tmp_u;
  real_T tmp_v;
  real_T tmp_w;
  real_T tmp_x;
  real_T tmp_y;
  real_T tmp_z;
  real_T tmp_10;
  real_T tmp_11;
  real_T tmp_12;
  real_T tmp_13;
  real_T tmp_14;
  real_T tmp_15;
  real_T tmp_16;
  real_T tmp_17;
  real_T tmp_18;
  real_T tmp_19;
  real_T tmp_1a;
  real_T tmp_1b;
  real_T tmp_1c;
  real_T tmp_1d;
  real_T tmp_1e;
  real_T tmp_1f;
  real_T tmp_1g;
  real_T tmp_1h;
  real_T tmp_1i;
  real_T tmp_1j;
  real_T tmp_1k;
  real_T tmp_1l;
  real_T tmp_1m;
  real_T tmp_1n;
  real_T tmp_1o;
  real_T tmp_1p;
  real_T tmp_1q;
  real_T tmp_1r;
  real_T tmp_1s;

  /* Logic: '<Root>/Logical Operator1' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlSlidingCircle_B.LogicalOperator1 =
    !(positionControlSlidingCircle_P.startX_Value != 0.0);

  /* Product: '<Root>/Product3' incorporates:
   *  Constant: '<Root>/input'
   */
  positionControlSlidingCircle_B.Product3 = (real_T)
    positionControlSlidingCircle_B.LogicalOperator1 *
    positionControlSlidingCircle_P.input_Value;

  /* DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/startX'
   */
  if ((positionControlSlidingCircle_P.startX_Value > 0.0) &&
      (positionControlSlidingCir_DWork.DiscreteTimeIntegrator_PrevRese <= 0)) {
    positionControlSlidingCir_DWork.DiscreteTimeIntegrator_DSTATE =
      positionControlSlidingCircle_P.DiscreteTimeIntegrator_IC;
  }

  positionControlSlidingCircle_B.DiscreteTimeIntegrator =
    positionControlSlidingCir_DWork.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<Root>/index' */
  positionControlSlidingCircle_B.index =
    positionControlSlidingCircle_P.index_Gain *
    positionControlSlidingCircle_B.DiscreteTimeIntegrator;

  /* LookupNDDirect: '<Root>/circX1'
   *
   * About '<Root>/circX1':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  denAccum = rt_SATURATE(positionControlSlidingCircle_B.index, 0.0, 9853.0);
  if (rtIsNaN(denAccum) || rtIsInf(denAccum)) {
    denAccum = 0.0;
  } else {
    denAccum = fmod(floor(denAccum), 4.294967296E+009);
  }

  initialOffset = denAccum < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-denAccum)))
    : (uint32_T)denAccum;
  positionControlSlidingCircle_B.circX1 =
    positionControlSlidingCircle_P.circX1_table[initialOffset];

  /* Product: '<Root>/Product5' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlSlidingCircle_B.Product5 =
    positionControlSlidingCircle_B.circX1 *
    positionControlSlidingCircle_P.startX_Value;

  /* Sum: '<Root>/xposr' */
  positionControlSlidingCircle_B.xr = positionControlSlidingCircle_B.Product3 +
    positionControlSlidingCircle_B.Product5;

  /* LookupNDDirect: '<Root>/circY'
   *
   * About '<Root>/circY':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  denAccum = rt_SATURATE(positionControlSlidingCircle_B.index, 0.0, 9853.0);
  if (rtIsNaN(denAccum) || rtIsInf(denAccum)) {
    denAccum = 0.0;
  } else {
    denAccum = fmod(floor(denAccum), 4.294967296E+009);
  }

  initialOffset = denAccum < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-denAccum)))
    : (uint32_T)denAccum;
  positionControlSlidingCircle_B.circY =
    positionControlSlidingCircle_P.circY_table[initialOffset];

  /* Product: '<Root>/Product4' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlSlidingCircle_B.Product4 =
    positionControlSlidingCircle_P.startX_Value *
    positionControlSlidingCircle_B.circY;

  /* Sum: '<Root>/yposr' */
  positionControlSlidingCircle_B.yr = 0.0 +
    positionControlSlidingCircle_B.Product4;

  /* Fcn: '<S10>/theta' incorporates:
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   */
  positionControlSlidingCircle_B.theta = rt_atan2_snf
    ((-positionControlSlidingCircle_P.yc_Value) +
     positionControlSlidingCircle_B.yr,
     (-positionControlSlidingCircle_P.xc_Value) +
     positionControlSlidingCircle_B.xr);

  /* Fcn: '<S14>/Fcn' */
  positionControlSlidingCircle_B.MatrixConcatenate1[0] = -sin
    (positionControlSlidingCircle_B.theta);

  /* Fcn: '<S14>/Fcn1' */
  positionControlSlidingCircle_B.MatrixConcatenate1[1] = -cos
    (positionControlSlidingCircle_B.theta);

  /* Fcn: '<S14>/Fcn2' */
  positionControlSlidingCircle_B.MatrixConcatenate4[0] = cos
    (positionControlSlidingCircle_B.theta);

  /* Fcn: '<S14>/Fcn3' */
  positionControlSlidingCircle_B.MatrixConcatenate4[1] = -sin
    (positionControlSlidingCircle_B.theta);

  /* Concatenate: '<S14>/coeffmat2X1' */
  positionControlSlidingCircle_B.coeffmat2X1[0] =
    positionControlSlidingCircle_B.MatrixConcatenate1[0];
  positionControlSlidingCircle_B.coeffmat2X1[2] =
    positionControlSlidingCircle_B.MatrixConcatenate1[1];
  positionControlSlidingCircle_B.coeffmat2X1[1] =
    positionControlSlidingCircle_B.MatrixConcatenate4[0];
  positionControlSlidingCircle_B.coeffmat2X1[3] =
    positionControlSlidingCircle_B.MatrixConcatenate4[1];

  /* Constant: '<S15>/zero' */
  positionControlSlidingCircle_B.VectorConcatenate_h[0] =
    positionControlSlidingCircle_P.zero_Value;

  /* Fcn: '<S12>/xrefForce' incorporates:
   *  Constant: '<Root>/rNormal'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   */
  positionControlSlidingCircle_B.xrefForce =
    positionControlSlidingCircle_P.rNormal_Value * cos
    (positionControlSlidingCircle_B.theta) +
    positionControlSlidingCircle_P.xc_Value;

  /* S-Function (rti_commonblock): '<S21>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S21>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S19>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S19>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Sum: '<S1>/Add' */
  positionControlSlidingCircle_B.Add[0] =
    positionControlSlidingCircle_B.SFunction1 +
    positionControlSlidingCircle_B.SFunction1_c;
  positionControlSlidingCircle_B.Add[1] =
    positionControlSlidingCircle_B.SFunction2 +
    positionControlSlidingCircle_B.SFunction2_h;

  /* Gain: '<S1>/EncoderGain' */
  positionControlSlidingCircle_B.EncoderGain[0] =
    positionControlSlidingCircle_P.EncoderGain_Gain *
    positionControlSlidingCircle_B.Add[0];

  /* Gain: '<S1>/convert2radians ' */
  positionControlSlidingCircle_B.convert2radians[0] =
    positionControlSlidingCircle_P.convert2radians_Gain *
    positionControlSlidingCircle_B.EncoderGain[0];

  /* Gain: '<S1>/EncoderGain' */
  positionControlSlidingCircle_B.EncoderGain[1] =
    positionControlSlidingCircle_P.EncoderGain_Gain *
    positionControlSlidingCircle_B.Add[1];

  /* Gain: '<S1>/convert2radians ' */
  positionControlSlidingCircle_B.convert2radians[1] =
    positionControlSlidingCircle_P.convert2radians_Gain *
    positionControlSlidingCircle_B.EncoderGain[1];

  /* Sum: '<S13>/Add3' */
  positionControlSlidingCircle_B.VectorConcatenate[0] =
    positionControlSlidingCircle_B.xrefForce -
    positionControlSlidingCircle_B.convert2radians[0];

  /* Fcn: '<S12>/yrefForce' incorporates:
   *  Constant: '<Root>/rNormal'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   */
  positionControlSlidingCircle_B.yrefForce =
    positionControlSlidingCircle_P.rNormal_Value * sin
    (positionControlSlidingCircle_B.theta) +
    positionControlSlidingCircle_P.yc_Value;

  /* S-Function (rti_commonblock): '<S23>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* S-Function (rti_commonblock): '<S23>/S-Function2' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<S2>/EncoderGain' */
  positionControlSlidingCircle_B.EncoderGain_o[0] =
    positionControlSlidingCircle_P.EncoderGain_Gain_f *
    positionControlSlidingCircle_B.SFunction1_c2;
  positionControlSlidingCircle_B.EncoderGain_o[1] =
    positionControlSlidingCircle_P.EncoderGain_Gain_f *
    positionControlSlidingCircle_B.SFunction2_l;

  /* Sum: '<S13>/Add4' */
  positionControlSlidingCircle_B.VectorConcatenate[1] =
    positionControlSlidingCircle_B.yrefForce -
    positionControlSlidingCircle_B.EncoderGain_o[0];

  /* Fcn: '<S13>/Fcn1' */
  positionControlSlidingCircle_B.VectorConcatenate1[0] = -cos
    (positionControlSlidingCircle_B.theta);

  /* Fcn: '<S13>/Fcn' */
  positionControlSlidingCircle_B.VectorConcatenate1[1] = -sin
    (positionControlSlidingCircle_B.theta);

  /* DotProduct: '<S13>/Dot Product' */
  denAccum = positionControlSlidingCircle_B.VectorConcatenate[0] *
    positionControlSlidingCircle_B.VectorConcatenate1[0];
  denAccum += positionControlSlidingCircle_B.VectorConcatenate[1] *
    positionControlSlidingCircle_B.VectorConcatenate1[1];
  positionControlSlidingCircle_B.DotProduct = denAccum;

  /* Product: '<S15>/Product10' incorporates:
   *  Constant: '<Root>/knorm'
   */
  positionControlSlidingCircle_B.VectorConcatenate_h[1] =
    positionControlSlidingCircle_P.knorm_Value *
    positionControlSlidingCircle_B.DotProduct;

  /* Product: '<Root>/Kp epsilond1' */
  positionControlSlidingCircle_B.Kpepsilond1[0] = 0.0;
  positionControlSlidingCircle_B.Kpepsilond1[0] =
    positionControlSlidingCircle_B.coeffmat2X1[0] *
    positionControlSlidingCircle_B.VectorConcatenate_h[0] +
    positionControlSlidingCircle_B.Kpepsilond1[0];
  positionControlSlidingCircle_B.Kpepsilond1[0] =
    positionControlSlidingCircle_B.coeffmat2X1[2] *
    positionControlSlidingCircle_B.VectorConcatenate_h[1] +
    positionControlSlidingCircle_B.Kpepsilond1[0];
  positionControlSlidingCircle_B.Kpepsilond1[1] = 0.0;
  positionControlSlidingCircle_B.Kpepsilond1[1] =
    positionControlSlidingCircle_B.coeffmat2X1[1] *
    positionControlSlidingCircle_B.VectorConcatenate_h[0] +
    positionControlSlidingCircle_B.Kpepsilond1[1];
  positionControlSlidingCircle_B.Kpepsilond1[1] =
    positionControlSlidingCircle_B.coeffmat2X1[3] *
    positionControlSlidingCircle_B.VectorConcatenate_h[1] +
    positionControlSlidingCircle_B.Kpepsilond1[1];

  /* Gain: '<Root>/gainAddX' */
  positionControlSlidingCircle_B.gainAddX =
    positionControlSlidingCircle_P.gainAddX_Gain *
    positionControlSlidingCircle_B.Kpepsilond1[0];

  /* DiscreteFilter: '<Root>/filterux4' */
  denAccum = positionControlSlidingCircle_B.gainAddX;
  denAccum -= positionControlSlidingCircle_P.filterux4_Denominator[1] *
    positionControlSlidingCir_DWork.filterux4_DSTATE;
  denAccum /= positionControlSlidingCircle_P.filterux4_Denominator[0];
  positionControlSlidingCir_DWork.filterux4_tmp = denAccum;
  denAccum = positionControlSlidingCircle_P.filterux4_Numerator *
    positionControlSlidingCir_DWork.filterux4_tmp;
  positionControlSlidingCircle_B.filterux4 = denAccum;

  /* Gain: '<Root>/differentiated1' */
  positionControlSlidingCircle_B.xd =
    positionControlSlidingCircle_P.differentiated1_Gain *
    positionControlSlidingCircle_B.convert2radians[1];

  /* DiscreteFilter: '<Root>/filterux2' */
  denAccum = positionControlSlidingCircle_B.xd;
  denAccum -= positionControlSlidingCircle_P.filterux2_Denominator[1] *
    positionControlSlidingCir_DWork.filterux2_DSTATE;
  denAccum /= positionControlSlidingCircle_P.filterux2_Denominator[0];
  positionControlSlidingCir_DWork.filterux2_tmp = denAccum;
  denAccum = positionControlSlidingCircle_P.filterux2_Numerator *
    positionControlSlidingCir_DWork.filterux2_tmp;
  positionControlSlidingCircle_B.filterux2 = denAccum;

  /* Gain: '<Root>/differentiated' */
  positionControlSlidingCircle_B.yd =
    positionControlSlidingCircle_P.differentiated_Gain *
    positionControlSlidingCircle_B.EncoderGain_o[1];

  /* DiscreteFilter: '<Root>/filterux3' */
  denAccum = positionControlSlidingCircle_B.yd;
  denAccum -= positionControlSlidingCircle_P.filterux3_Denominator[1] *
    positionControlSlidingCir_DWork.filterux3_DSTATE;
  denAccum /= positionControlSlidingCircle_P.filterux3_Denominator[0];
  positionControlSlidingCir_DWork.filterux3_tmp = denAccum;
  denAccum = positionControlSlidingCircle_P.filterux3_Numerator *
    positionControlSlidingCir_DWork.filterux3_tmp;
  positionControlSlidingCircle_B.filterux3 = denAccum;

  /* LookupNDDirect: '<Root>/circXd1'
   *
   * About '<Root>/circXd1':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  denAccum = rt_SATURATE(positionControlSlidingCircle_B.index, 0.0, 9853.0);
  if (rtIsNaN(denAccum) || rtIsInf(denAccum)) {
    denAccum = 0.0;
  } else {
    denAccum = fmod(floor(denAccum), 4.294967296E+009);
  }

  initialOffset = denAccum < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-denAccum)))
    : (uint32_T)denAccum;
  positionControlSlidingCircle_B.circXd1 =
    positionControlSlidingCircle_P.circXd1_table[initialOffset];

  /* Product: '<Root>/Product8' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlSlidingCircle_B.xrd = positionControlSlidingCircle_B.circXd1 *
    positionControlSlidingCircle_P.startX_Value;

  /* LookupNDDirect: '<Root>/circYd'
   *
   * About '<Root>/circYd':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  denAccum = rt_SATURATE(positionControlSlidingCircle_B.index, 0.0, 9853.0);
  if (rtIsNaN(denAccum) || rtIsInf(denAccum)) {
    denAccum = 0.0;
  } else {
    denAccum = fmod(floor(denAccum), 4.294967296E+009);
  }

  initialOffset = denAccum < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-denAccum)))
    : (uint32_T)denAccum;
  positionControlSlidingCircle_B.circYd =
    positionControlSlidingCircle_P.circYd_table[initialOffset];

  /* Product: '<Root>/Product6' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlSlidingCircle_B.yrd =
    positionControlSlidingCircle_P.startX_Value *
    positionControlSlidingCircle_B.circYd;

  /* LookupNDDirect: '<Root>/circXdd1'
   *
   * About '<Root>/circXdd1':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  denAccum = rt_SATURATE(positionControlSlidingCircle_B.index, 0.0, 9853.0);
  if (rtIsNaN(denAccum) || rtIsInf(denAccum)) {
    denAccum = 0.0;
  } else {
    denAccum = fmod(floor(denAccum), 4.294967296E+009);
  }

  initialOffset = denAccum < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-denAccum)))
    : (uint32_T)denAccum;
  positionControlSlidingCircle_B.circXdd1 =
    positionControlSlidingCircle_P.circXdd1_table[initialOffset];

  /* Product: '<Root>/Product9' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlSlidingCircle_B.xrdd = positionControlSlidingCircle_B.circXdd1 *
    positionControlSlidingCircle_P.startX_Value;

  /* LookupNDDirect: '<Root>/circYdd'
   *
   * About '<Root>/circYdd':
   *  1-dimensional Direct Look-Up returning a Scalar
   */
  denAccum = rt_SATURATE(positionControlSlidingCircle_B.index, 0.0, 9853.0);
  if (rtIsNaN(denAccum) || rtIsInf(denAccum)) {
    denAccum = 0.0;
  } else {
    denAccum = fmod(floor(denAccum), 4.294967296E+009);
  }

  initialOffset = denAccum < 0.0 ? (uint32_T)(-((int32_T)(uint32_T)(-denAccum)))
    : (uint32_T)denAccum;
  positionControlSlidingCircle_B.circYdd =
    positionControlSlidingCircle_P.circYdd_table[initialOffset];

  /* Product: '<Root>/Product7' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlSlidingCircle_B.yrdd =
    positionControlSlidingCircle_P.startX_Value *
    positionControlSlidingCircle_B.circYdd;

  /* Fcn: '<Root>/coeffmat(1,1)' incorporates:
   *  Constant: '<Root>/r0'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   *  Constant: '<S10>/cx'
   *  Constant: '<S10>/cy'
   *  Constant: '<S10>/mx'
   *  Constant: '<S10>/my'
   */
  denAccum = positionControlSlidingCircle_P.mx_Value;
  tmp = rt_pow_snf(denAccum, -1.0);
  denAccum = (-positionControlSlidingCircle_P.xc_Value) +
    positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    tmp_0 = -rt_pow_snf(-denAccum, -1.5);
  } else {
    tmp_0 = rt_pow_snf(denAccum, -1.5);
  }

  denAccum = positionControlSlidingCircle_P.xc_Value;
  denAccum = rt_pow_snf(denAccum, 2.0);
  positionControlSlidingCircle_B.MatrixConcatenate2[0] =
    (((((-positionControlSlidingCircle_B.xr) +
        positionControlSlidingCircle_P.xc_Value) *
       positionControlSlidingCircle_B.convert2radians[0] + (-denAccum)) +
      positionControlSlidingCircle_P.xc_Value *
      positionControlSlidingCircle_B.xr) +
     ((-positionControlSlidingCircle_P.yc_Value) +
      positionControlSlidingCircle_B.EncoderGain_o[0]) *
     ((-positionControlSlidingCircle_B.yr) +
      positionControlSlidingCircle_P.yc_Value)) * ((-tmp) * tmp_0 *
    ((-positionControlSlidingCircle_P.yc_Value) +
     positionControlSlidingCircle_B.EncoderGain_o[0]));

  /* Fcn: '<Root>/coeffmat(1,2)' incorporates:
   *  Constant: '<Root>/r0'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   *  Constant: '<S10>/cx'
   *  Constant: '<S10>/cy'
   *  Constant: '<S10>/mx'
   *  Constant: '<S10>/my'
   */
  denAccum = positionControlSlidingCircle_P.my_Value;
  tmp = rt_pow_snf(denAccum, -1.0);
  denAccum = (-positionControlSlidingCircle_P.xc_Value) +
    positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    tmp_0 = -rt_pow_snf(-denAccum, -1.5);
  } else {
    tmp_0 = rt_pow_snf(denAccum, -1.5);
  }

  denAccum = positionControlSlidingCircle_P.xc_Value;
  denAccum = rt_pow_snf(denAccum, 2.0);
  positionControlSlidingCircle_B.MatrixConcatenate2[1] =
    (((((-positionControlSlidingCircle_B.xr) +
        positionControlSlidingCircle_P.xc_Value) *
       positionControlSlidingCircle_B.convert2radians[0] + (-denAccum)) +
      positionControlSlidingCircle_P.xc_Value *
      positionControlSlidingCircle_B.xr) +
     ((-positionControlSlidingCircle_P.yc_Value) +
      positionControlSlidingCircle_B.EncoderGain_o[0]) *
     ((-positionControlSlidingCircle_B.yr) +
      positionControlSlidingCircle_P.yc_Value)) *
    (((-positionControlSlidingCircle_P.xc_Value) +
      positionControlSlidingCircle_B.convert2radians[0]) * tmp * tmp_0);

  /* Fcn: '<Root>/coeffmat(2,1)' incorporates:
   *  Constant: '<Root>/r0'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   *  Constant: '<S10>/cx'
   *  Constant: '<S10>/cy'
   *  Constant: '<S10>/mx'
   *  Constant: '<S10>/my'
   */
  denAccum = positionControlSlidingCircle_P.mx_Value;
  tmp = rt_pow_snf(denAccum, -1.0);
  denAccum = (-positionControlSlidingCircle_P.xc_Value) +
    positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    denAccum = -rt_pow_snf(-denAccum, -0.5);
  } else {
    denAccum = rt_pow_snf(denAccum, -0.5);
  }

  positionControlSlidingCircle_B.MatrixConcatenate3[0] =
    ((-positionControlSlidingCircle_P.xc_Value) +
     positionControlSlidingCircle_B.convert2radians[0]) * tmp * denAccum;

  /* Fcn: '<Root>/coeffmat(2,2)' incorporates:
   *  Constant: '<Root>/r0'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   *  Constant: '<S10>/cx'
   *  Constant: '<S10>/cy'
   *  Constant: '<S10>/mx'
   *  Constant: '<S10>/my'
   */
  denAccum = positionControlSlidingCircle_P.my_Value;
  tmp = rt_pow_snf(denAccum, -1.0);
  denAccum = (-positionControlSlidingCircle_P.xc_Value) +
    positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    denAccum = -rt_pow_snf(-denAccum, -0.5);
  } else {
    denAccum = rt_pow_snf(denAccum, -0.5);
  }

  positionControlSlidingCircle_B.MatrixConcatenate3[1] =
    ((-positionControlSlidingCircle_P.yc_Value) +
     positionControlSlidingCircle_B.EncoderGain_o[0]) * (tmp * denAccum);

  /* Concatenate: '<S16>/coeffmat2X2' */
  positionControlSlidingCircle_B.coeffmat2X2[0] =
    positionControlSlidingCircle_B.MatrixConcatenate2[0];
  positionControlSlidingCircle_B.coeffmat2X2[2] =
    positionControlSlidingCircle_B.MatrixConcatenate2[1];
  positionControlSlidingCircle_B.coeffmat2X2[1] =
    positionControlSlidingCircle_B.MatrixConcatenate3[0];
  positionControlSlidingCircle_B.coeffmat2X2[3] =
    positionControlSlidingCircle_B.MatrixConcatenate3[1];

  /* S-Function (sdsppinv): '<S16>/Pseudoinverse' */
  /* Copy input to temporary space */
  positionControlSlidingCir_DWork.Pseudoinverse_X[0] =
    positionControlSlidingCircle_B.coeffmat2X2[0];
  positionControlSlidingCir_DWork.Pseudoinverse_X[1] =
    positionControlSlidingCircle_B.coeffmat2X2[1];
  positionControlSlidingCir_DWork.Pseudoinverse_X[2] =
    positionControlSlidingCircle_B.coeffmat2X2[2];
  positionControlSlidingCir_DWork.Pseudoinverse_X[3] =
    positionControlSlidingCircle_B.coeffmat2X2[3];

  /* Call SVD */
  k = MWDSP_SVD_D(&positionControlSlidingCir_DWork.Pseudoinverse_X[0], 2, 2,
                  &positionControlSlidingCir_DWork.Pseudoinverse_S[0],
                  &positionControlSlidingCir_DWork.Pseudoinverse_E[0],
                  &positionControlSlidingCir_DWork.Pseudoinverse_WORK[0],
                  &positionControlSlidingCir_DWork.Pseudoinverse_U[0],
                  &positionControlSlidingCir_DWork.Pseudoinverse_V[0], 1);

  /* Only call 'pinv' function if SVD succeeded */
  if (k == 0) {
    MWDSPCG_Pseudoinverse_D(&positionControlSlidingCir_DWork.Pseudoinverse_S[0],
      &positionControlSlidingCir_DWork.Pseudoinverse_U[0],
      &positionControlSlidingCir_DWork.Pseudoinverse_V[0],
      &positionControlSlidingCircle_B.Pseudoinverse[0], 2, 2);
  }

  /* Constant: '<Root>/Ks1,1' */
  positionControlSlidingCircle_B.MatrixConcatenate4_e[0] =
    positionControlSlidingCircle_P.Ks11_Value;

  /* Constant: '<Root>/Ks1,2' */
  positionControlSlidingCircle_B.MatrixConcatenate4_e[1] =
    positionControlSlidingCircle_P.Ks12_Value;

  /* Constant: '<Root>/Ks2,1' */
  positionControlSlidingCircle_B.MatrixConcatenate4_e[2] =
    positionControlSlidingCircle_P.Ks21_Value;

  /* Constant: '<Root>/Ks 2,2' */
  positionControlSlidingCircle_B.MatrixConcatenate4_e[3] =
    positionControlSlidingCircle_P.Ks22_Value;

  /* Product: '<Root>/-Minv Ks' incorporates:
   *  Constant: '<Root>/-Minv'
   */
  for (k = 0; k < 2; k++) {
    positionControlSlidingCircle_B.MinvKs[k] = 0.0;
    positionControlSlidingCircle_B.MinvKs[k] =
      positionControlSlidingCircle_P.Minv_Value[k] *
      positionControlSlidingCircle_B.MatrixConcatenate4_e[0] +
      positionControlSlidingCircle_B.MinvKs[k];
    positionControlSlidingCircle_B.MinvKs[k] =
      positionControlSlidingCircle_P.Minv_Value[k + 2] *
      positionControlSlidingCircle_B.MatrixConcatenate4_e[1] +
      positionControlSlidingCircle_B.MinvKs[k];
    positionControlSlidingCircle_B.MinvKs[k + 2] = 0.0;
    positionControlSlidingCircle_B.MinvKs[k + 2] =
      positionControlSlidingCircle_B.MinvKs[k + 2] +
      positionControlSlidingCircle_P.Minv_Value[k] *
      positionControlSlidingCircle_B.MatrixConcatenate4_e[2];
    positionControlSlidingCircle_B.MinvKs[k + 2] =
      positionControlSlidingCircle_P.Minv_Value[k + 2] *
      positionControlSlidingCircle_B.MatrixConcatenate4_e[3] +
      positionControlSlidingCircle_B.MinvKs[k + 2];
  }

  /* Constant: '<Root>/Kp1,1' */
  positionControlSlidingCircle_B.MatrixConcatenate4_o[0] =
    positionControlSlidingCircle_P.Kp11_Value;

  /* Constant: '<Root>/Kp2,1' */
  positionControlSlidingCircle_B.MatrixConcatenate4_o[1] =
    positionControlSlidingCircle_P.Kp21_Value;

  /* Constant: '<Root>/Kp1,2' */
  positionControlSlidingCircle_B.MatrixConcatenate4_o[2] =
    positionControlSlidingCircle_P.Kp12_Value;

  /* Constant: '<Root>/Kp2,2' */
  positionControlSlidingCircle_B.MatrixConcatenate4_o[3] =
    positionControlSlidingCircle_P.Kp22_Value;

  /* Fcn: '<Root>/epsilon(1)' incorporates:
   *  Constant: '<Root>/r0'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   *  Constant: '<S10>/cx'
   *  Constant: '<S10>/cy'
   *  Constant: '<S10>/mx'
   *  Constant: '<S10>/my'
   */
  denAccum = (-positionControlSlidingCircle_P.xc_Value) +
    positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    denAccum = -rt_pow_snf(-denAccum, -0.5);
  } else {
    denAccum = rt_pow_snf(denAccum, -0.5);
  }

  positionControlSlidingCircle_B.epsilon2X1[0] = (((-1.0 *
    positionControlSlidingCircle_B.EncoderGain_o[0] +
    positionControlSlidingCircle_P.yc_Value) * positionControlSlidingCircle_B.xr
    + ((-positionControlSlidingCircle_B.yr) +
       positionControlSlidingCircle_B.EncoderGain_o[0]) *
    positionControlSlidingCircle_P.xc_Value) +
    ((-positionControlSlidingCircle_P.yc_Value) +
     positionControlSlidingCircle_B.yr) *
    positionControlSlidingCircle_B.convert2radians[0]) * denAccum;

  /* Fcn: '<Root>/epsilon(2)' incorporates:
   *  Constant: '<Root>/r0'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   *  Constant: '<S10>/cx'
   *  Constant: '<S10>/cy'
   *  Constant: '<S10>/mx'
   *  Constant: '<S10>/my'
   */
  denAccum = (-positionControlSlidingCircle_P.xc_Value) +
    positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    denAccum = -rt_pow_snf(-denAccum, 0.5);
  } else {
    denAccum = rt_pow_snf(denAccum, 0.5);
  }

  positionControlSlidingCircle_B.epsilon2X1[1] =
    (-positionControlSlidingCircle_P.r0_Value) + denAccum;

  /* Product: '<S16>/Kp epsilon' */
  positionControlSlidingCircle_B.Kpepsilon[0] = 0.0;
  positionControlSlidingCircle_B.Kpepsilon[0] =
    positionControlSlidingCircle_B.MatrixConcatenate4_o[0] *
    positionControlSlidingCircle_B.epsilon2X1[0] +
    positionControlSlidingCircle_B.Kpepsilon[0];
  positionControlSlidingCircle_B.Kpepsilon[0] =
    positionControlSlidingCircle_B.MatrixConcatenate4_o[2] *
    positionControlSlidingCircle_B.epsilon2X1[1] +
    positionControlSlidingCircle_B.Kpepsilon[0];
  positionControlSlidingCircle_B.Kpepsilon[1] = 0.0;
  positionControlSlidingCircle_B.Kpepsilon[1] =
    positionControlSlidingCircle_B.MatrixConcatenate4_o[1] *
    positionControlSlidingCircle_B.epsilon2X1[0] +
    positionControlSlidingCircle_B.Kpepsilon[1];
  positionControlSlidingCircle_B.Kpepsilon[1] =
    positionControlSlidingCircle_B.MatrixConcatenate4_o[3] *
    positionControlSlidingCircle_B.epsilon2X1[1] +
    positionControlSlidingCircle_B.Kpepsilon[1];

  /* Constant: '<Root>/Kd1,3' */
  positionControlSlidingCircle_B.MatrixConcatenate4_b[0] =
    positionControlSlidingCircle_P.Kd13_Value;

  /* Constant: '<Root>/Kd2,3' */
  positionControlSlidingCircle_B.MatrixConcatenate4_b[1] =
    positionControlSlidingCircle_P.Kd23_Value;

  /* Constant: '<Root>/Kd1,4' */
  positionControlSlidingCircle_B.MatrixConcatenate4_b[2] =
    positionControlSlidingCircle_P.Kd14_Value;

  /* Constant: '<Root>/Kd2,4' */
  positionControlSlidingCircle_B.MatrixConcatenate4_b[3] =
    positionControlSlidingCircle_P.Kd24_Value;

  /* Fcn: '<Root>/epsilond(1)' incorporates:
   *  Constant: '<Root>/r0'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   *  Constant: '<S10>/cx'
   *  Constant: '<S10>/cy'
   *  Constant: '<S10>/mx'
   *  Constant: '<S10>/my'
   */
  denAccum = (-positionControlSlidingCircle_P.xc_Value) +
    positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    tmp_1 = -rt_pow_snf(-denAccum, -1.5);
  } else {
    tmp_1 = rt_pow_snf(denAccum, -1.5);
  }

  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_2 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_3 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_4 = rt_pow_snf(denAccum, 3.0);
  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp = rt_pow_snf(denAccum, 3.0);
  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  denAccum = rt_pow_snf(denAccum, 2.0);
  positionControlSlidingCircle_B.epsilond2X1[0] =
    (((((((((((-positionControlSlidingCircle_B.xrd) *
              positionControlSlidingCircle_B.EncoderGain_o[0] +
              positionControlSlidingCircle_B.filterux2 *
              positionControlSlidingCircle_B.EncoderGain_o[0]) +
             (-positionControlSlidingCircle_B.filterux2) *
             positionControlSlidingCircle_P.yc_Value) +
            positionControlSlidingCircle_B.xrd *
            positionControlSlidingCircle_P.yc_Value) +
           (-positionControlSlidingCircle_B.xr) *
           positionControlSlidingCircle_B.filterux3) * tmp_2 +
          (((positionControlSlidingCircle_B.xrd *
             positionControlSlidingCircle_B.EncoderGain_o[0] +
             positionControlSlidingCircle_B.filterux2 *
             positionControlSlidingCircle_P.yc_Value) +
            (-positionControlSlidingCircle_B.xrd) *
            positionControlSlidingCircle_P.yc_Value) +
           (-positionControlSlidingCircle_B.filterux2) *
           positionControlSlidingCircle_B.yr) * (-tmp_3)) +
         ((-positionControlSlidingCircle_B.yrd) +
          positionControlSlidingCircle_B.filterux3) * tmp_4) + tmp *
        positionControlSlidingCircle_B.yrd) + ((((-1.0 *
           positionControlSlidingCircle_B.EncoderGain_o[0] +
           positionControlSlidingCircle_P.yc_Value) *
          positionControlSlidingCircle_B.xrd +
          positionControlSlidingCircle_P.xc_Value *
          positionControlSlidingCircle_B.filterux3) +
         (-positionControlSlidingCircle_B.xr) *
         positionControlSlidingCircle_B.filterux3) + -3.0 *
        positionControlSlidingCircle_P.xc_Value *
        positionControlSlidingCircle_B.yrd) * tmp_0) +
      ((((positionControlSlidingCircle_B.filterux2 *
          positionControlSlidingCircle_B.xr +
          positionControlSlidingCircle_P.yc_Value *
          positionControlSlidingCircle_B.filterux3) +
         (-positionControlSlidingCircle_B.filterux3) *
         positionControlSlidingCircle_B.yr) +
        positionControlSlidingCircle_B.EncoderGain_o[0] *
        positionControlSlidingCircle_B.yrd) +
       (-positionControlSlidingCircle_P.yc_Value) *
       positionControlSlidingCircle_B.yrd) *
      (((-positionControlSlidingCircle_P.yc_Value) +
        positionControlSlidingCircle_B.EncoderGain_o[0]) *
       (-positionControlSlidingCircle_P.xc_Value))) +
     (((((((-positionControlSlidingCircle_B.filterux2) *
           positionControlSlidingCircle_B.EncoderGain_o[0] + 2.0 *
           positionControlSlidingCircle_B.xrd *
           positionControlSlidingCircle_B.EncoderGain_o[0]) +
          positionControlSlidingCircle_B.filterux2 *
          positionControlSlidingCircle_P.yc_Value) + -2.0 *
         positionControlSlidingCircle_B.xrd *
         positionControlSlidingCircle_P.yc_Value) + 2.0 *
        positionControlSlidingCircle_B.xr *
        positionControlSlidingCircle_B.filterux3) *
       positionControlSlidingCircle_P.xc_Value + (-2.0 *
        positionControlSlidingCircle_B.filterux3 + 3.0 *
        positionControlSlidingCircle_B.yrd) * denAccum) +
      ((((positionControlSlidingCircle_B.filterux2 *
          positionControlSlidingCircle_B.xr +
          positionControlSlidingCircle_P.yc_Value *
          positionControlSlidingCircle_B.filterux3) +
         (-positionControlSlidingCircle_B.filterux3) *
         positionControlSlidingCircle_B.yr) +
        positionControlSlidingCircle_B.EncoderGain_o[0] *
        positionControlSlidingCircle_B.yrd) +
       (-positionControlSlidingCircle_P.yc_Value) *
       positionControlSlidingCircle_B.yrd) *
      ((-positionControlSlidingCircle_P.yc_Value) +
       positionControlSlidingCircle_B.EncoderGain_o[0])) *
     positionControlSlidingCircle_B.convert2radians[0]) * tmp_1;

  /* Fcn: '<Root>/epsilond(2)' incorporates:
   *  Constant: '<Root>/r0'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   *  Constant: '<S10>/cx'
   *  Constant: '<S10>/cy'
   *  Constant: '<S10>/mx'
   *  Constant: '<S10>/my'
   */
  denAccum = (-positionControlSlidingCircle_P.xc_Value) +
    positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    tmp_1 = -rt_pow_snf(-denAccum, -1.5);
  } else {
    tmp_1 = rt_pow_snf(denAccum, -1.5);
  }

  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_2 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_3 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_4 = rt_pow_snf(denAccum, 3.0);
  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp = rt_pow_snf(denAccum, 3.0);
  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  denAccum = rt_pow_snf(denAccum, 2.0);
  positionControlSlidingCircle_B.epsilond2X1[1] =
    (((((((((((-positionControlSlidingCircle_B.xrd) *
              positionControlSlidingCircle_B.EncoderGain_o[0] +
              positionControlSlidingCircle_B.filterux2 *
              positionControlSlidingCircle_B.EncoderGain_o[0]) +
             (-positionControlSlidingCircle_B.filterux2) *
             positionControlSlidingCircle_P.yc_Value) +
            positionControlSlidingCircle_B.xrd *
            positionControlSlidingCircle_P.yc_Value) +
           (-positionControlSlidingCircle_B.xr) *
           positionControlSlidingCircle_B.filterux3) * tmp_2 +
          (((positionControlSlidingCircle_B.xrd *
             positionControlSlidingCircle_B.EncoderGain_o[0] +
             positionControlSlidingCircle_B.filterux2 *
             positionControlSlidingCircle_P.yc_Value) +
            (-positionControlSlidingCircle_B.xrd) *
            positionControlSlidingCircle_P.yc_Value) +
           (-positionControlSlidingCircle_B.filterux2) *
           positionControlSlidingCircle_B.yr) * (-tmp_3)) +
         ((-positionControlSlidingCircle_B.yrd) +
          positionControlSlidingCircle_B.filterux3) * tmp_4) + tmp *
        positionControlSlidingCircle_B.yrd) + ((((-1.0 *
           positionControlSlidingCircle_B.EncoderGain_o[0] +
           positionControlSlidingCircle_P.yc_Value) *
          positionControlSlidingCircle_B.xrd +
          positionControlSlidingCircle_P.xc_Value *
          positionControlSlidingCircle_B.filterux3) +
         (-positionControlSlidingCircle_B.xr) *
         positionControlSlidingCircle_B.filterux3) + -3.0 *
        positionControlSlidingCircle_P.xc_Value *
        positionControlSlidingCircle_B.yrd) * tmp_0) +
      ((((positionControlSlidingCircle_B.filterux2 *
          positionControlSlidingCircle_B.xr +
          positionControlSlidingCircle_P.yc_Value *
          positionControlSlidingCircle_B.filterux3) +
         (-positionControlSlidingCircle_B.filterux3) *
         positionControlSlidingCircle_B.yr) +
        positionControlSlidingCircle_B.EncoderGain_o[0] *
        positionControlSlidingCircle_B.yrd) +
       (-positionControlSlidingCircle_P.yc_Value) *
       positionControlSlidingCircle_B.yrd) *
      (((-positionControlSlidingCircle_P.yc_Value) +
        positionControlSlidingCircle_B.EncoderGain_o[0]) *
       (-positionControlSlidingCircle_P.xc_Value))) +
     (((((((-positionControlSlidingCircle_B.filterux2) *
           positionControlSlidingCircle_B.EncoderGain_o[0] + 2.0 *
           positionControlSlidingCircle_B.xrd *
           positionControlSlidingCircle_B.EncoderGain_o[0]) +
          positionControlSlidingCircle_B.filterux2 *
          positionControlSlidingCircle_P.yc_Value) + -2.0 *
         positionControlSlidingCircle_B.xrd *
         positionControlSlidingCircle_P.yc_Value) + 2.0 *
        positionControlSlidingCircle_B.xr *
        positionControlSlidingCircle_B.filterux3) *
       positionControlSlidingCircle_P.xc_Value + (-2.0 *
        positionControlSlidingCircle_B.filterux3 + 3.0 *
        positionControlSlidingCircle_B.yrd) * denAccum) +
      ((((positionControlSlidingCircle_B.filterux2 *
          positionControlSlidingCircle_B.xr +
          positionControlSlidingCircle_P.yc_Value *
          positionControlSlidingCircle_B.filterux3) +
         (-positionControlSlidingCircle_B.filterux3) *
         positionControlSlidingCircle_B.yr) +
        positionControlSlidingCircle_B.EncoderGain_o[0] *
        positionControlSlidingCircle_B.yrd) +
       (-positionControlSlidingCircle_P.yc_Value) *
       positionControlSlidingCircle_B.yrd) *
      ((-positionControlSlidingCircle_P.yc_Value) +
       positionControlSlidingCircle_B.EncoderGain_o[0])) *
     positionControlSlidingCircle_B.convert2radians[0]) * tmp_1;

  /* Product: '<S16>/Kd epsilond' */
  positionControlSlidingCircle_B.Kdepsilond[0] = 0.0;
  positionControlSlidingCircle_B.Kdepsilond[0] =
    positionControlSlidingCircle_B.MatrixConcatenate4_b[0] *
    positionControlSlidingCircle_B.epsilond2X1[0] +
    positionControlSlidingCircle_B.Kdepsilond[0];
  positionControlSlidingCircle_B.Kdepsilond[0] =
    positionControlSlidingCircle_B.MatrixConcatenate4_b[2] *
    positionControlSlidingCircle_B.epsilond2X1[1] +
    positionControlSlidingCircle_B.Kdepsilond[0];

  /* Sum: '<S16>/Add' */
  positionControlSlidingCircle_B.Add_h[0] =
    positionControlSlidingCircle_B.Kpepsilon[0] +
    positionControlSlidingCircle_B.Kdepsilond[0];

  /* Product: '<S16>/Kd epsilond' */
  positionControlSlidingCircle_B.Kdepsilond[1] = 0.0;
  positionControlSlidingCircle_B.Kdepsilond[1] =
    positionControlSlidingCircle_B.MatrixConcatenate4_b[1] *
    positionControlSlidingCircle_B.epsilond2X1[0] +
    positionControlSlidingCircle_B.Kdepsilond[1];
  positionControlSlidingCircle_B.Kdepsilond[1] =
    positionControlSlidingCircle_B.MatrixConcatenate4_b[3] *
    positionControlSlidingCircle_B.epsilond2X1[1] +
    positionControlSlidingCircle_B.Kdepsilond[1];

  /* Sum: '<S16>/Add' */
  positionControlSlidingCircle_B.Add_h[1] =
    positionControlSlidingCircle_B.Kpepsilon[1] +
    positionControlSlidingCircle_B.Kdepsilond[1];

  /* Product: '<S16>/-Minv Ks (Kp epsilon+Kd epsilond)' */
  positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[0] = 0.0;
  positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[0] =
    positionControlSlidingCircle_B.MinvKs[0] *
    positionControlSlidingCircle_B.Add_h[0] +
    positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[0];
  positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[0] =
    positionControlSlidingCircle_B.MinvKs[2] *
    positionControlSlidingCircle_B.Add_h[1] +
    positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[0];

  /* Product: '<S16>/Kp epsilond' */
  positionControlSlidingCircle_B.Kpepsilond[0] = 0.0;
  positionControlSlidingCircle_B.Kpepsilond[0] =
    positionControlSlidingCircle_B.MatrixConcatenate4_o[0] *
    positionControlSlidingCircle_B.epsilond2X1[0] +
    positionControlSlidingCircle_B.Kpepsilond[0];
  positionControlSlidingCircle_B.Kpepsilond[0] =
    positionControlSlidingCircle_B.MatrixConcatenate4_o[2] *
    positionControlSlidingCircle_B.epsilond2X1[1] +
    positionControlSlidingCircle_B.Kpepsilond[0];

  /* Sum: '<S16>/Add1' */
  positionControlSlidingCircle_B.Add1[0] =
    positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[0] -
    positionControlSlidingCircle_B.Kpepsilond[0];

  /* Math: '<S28>/Math Function' */
  positionControlSlidingCircle_B.MathFunction[0] =
    positionControlSlidingCircle_B.Add1[0];

  /* Product: '<S16>/-Minv Ks (Kp epsilon+Kd epsilond)' */
  positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[1] = 0.0;
  positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[1] =
    positionControlSlidingCircle_B.MinvKs[1] *
    positionControlSlidingCircle_B.Add_h[0] +
    positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[1];
  positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[1] =
    positionControlSlidingCircle_B.MinvKs[3] *
    positionControlSlidingCircle_B.Add_h[1] +
    positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[1];

  /* Product: '<S16>/Kp epsilond' */
  positionControlSlidingCircle_B.Kpepsilond[1] = 0.0;
  positionControlSlidingCircle_B.Kpepsilond[1] =
    positionControlSlidingCircle_B.MatrixConcatenate4_o[1] *
    positionControlSlidingCircle_B.epsilond2X1[0] +
    positionControlSlidingCircle_B.Kpepsilond[1];
  positionControlSlidingCircle_B.Kpepsilond[1] =
    positionControlSlidingCircle_B.MatrixConcatenate4_o[3] *
    positionControlSlidingCircle_B.epsilond2X1[1] +
    positionControlSlidingCircle_B.Kpepsilond[1];

  /* Sum: '<S16>/Add1' */
  positionControlSlidingCircle_B.Add1[1] =
    positionControlSlidingCircle_B.MinvKsKpepsilonKdepsilond[1] -
    positionControlSlidingCircle_B.Kpepsilond[1];

  /* Math: '<S28>/Math Function' */
  positionControlSlidingCircle_B.MathFunction[1] =
    positionControlSlidingCircle_B.Add1[1];

  /* S-Function (sdsplu2): '<S31>/LU Factorization' */
  for (k = 0; k < 4; k++) {
    positionControlSlidingCircle_B.LUFactorization_o1[k] =
      positionControlSlidingCircle_B.MatrixConcatenate4_b[k];
  }

  LUf_int32_Treal_T(&positionControlSlidingCircle_B.LUFactorization_o1[0],
                    &positionControlSlidingCircle_B.LUFactorization_o2[0], 2);

  /* Signal Processing Blockset Permute Matrix (sdspperm2) - '<S31>/Permute Matrix' */
  /* Permute rows port 0 input rows = 2, output rows = 2 */
  {
    int_T iRows;
    for (iRows=0; iRows<2; iRows++) {
      int32_T i_idx = (int32_T)
        (positionControlSlidingCircle_B.LUFactorization_o2[iRows] - 1);

      /* Clip bad index */
      if (i_idx < 0) {
        i_idx = 0;
      } else if (i_idx > 1) {
        i_idx = 1;
      }

      {
        int_T A_idx = i_idx;
        int_T jNp = 0;
        int_T j;
        for (j=0; j < 2; j++) {
          *(&positionControlSlidingCircle_B.PermuteMatrix[iRows] + jNp) =
            positionControlSlidingCircle_B.IdentityMatrix[A_idx];
          A_idx += 2;
          jNp += 2;
        }
      }
    }
  }

  /* S-Function (sdspfbsub2): '<S31>/Forward Substitution' */
  positionControlSlidingCircle_B.y[0] =
    positionControlSlidingCircle_B.PermuteMatrix[0];
  k = 1;
  denAccum = positionControlSlidingCircle_B.PermuteMatrix[1];
  for (idxLU = 0; idxLU < 1; idxLU = 1) {
    denAccum -= positionControlSlidingCircle_B.LUFactorization_o1[k] *
      positionControlSlidingCircle_B.y[0];
    k += 2;
  }

  positionControlSlidingCircle_B.y[1] = denAccum;
  positionControlSlidingCircle_B.y[2] =
    positionControlSlidingCircle_B.PermuteMatrix[2];
  k = 1;
  denAccum = positionControlSlidingCircle_B.PermuteMatrix[3];
  for (idxLU = 0; idxLU < 1; idxLU = 1) {
    denAccum -= positionControlSlidingCircle_B.LUFactorization_o1[k] *
      positionControlSlidingCircle_B.y[2];
    k += 2;
  }

  positionControlSlidingCircle_B.y[3] = denAccum;

  /* S-Function (sdspfbsub2): '<S31>/Backward Substitution' */
  positionControlSlidingCircle_B.BackwardSubstitution[1] =
    positionControlSlidingCircle_B.y[1] /
    positionControlSlidingCircle_B.LUFactorization_o1[3];
  idxLU = 2;
  denAccum = positionControlSlidingCircle_B.y[0];
  for (k = 1; k > 0; k = 0) {
    denAccum -= positionControlSlidingCircle_B.LUFactorization_o1[idxLU] *
      positionControlSlidingCircle_B.BackwardSubstitution[1];
    idxLU -= 2;
  }

  positionControlSlidingCircle_B.BackwardSubstitution[0] = denAccum /
    positionControlSlidingCircle_B.LUFactorization_o1[idxLU];
  positionControlSlidingCircle_B.BackwardSubstitution[3] =
    positionControlSlidingCircle_B.y[3] /
    positionControlSlidingCircle_B.LUFactorization_o1[3];
  idxLU = 2;
  denAccum = positionControlSlidingCircle_B.y[2];
  for (k = 1; k > 0; k = 0) {
    denAccum -= positionControlSlidingCircle_B.LUFactorization_o1[idxLU] *
      positionControlSlidingCircle_B.BackwardSubstitution[3];
    idxLU -= 2;
  }

  positionControlSlidingCircle_B.BackwardSubstitution[2] = denAccum /
    positionControlSlidingCircle_B.LUFactorization_o1[idxLU];

  /* Product: '<S16>/matrix mult' */
  positionControlSlidingCircle_B.matrixmult[0] = 0.0;
  positionControlSlidingCircle_B.matrixmult[0] =
    positionControlSlidingCircle_B.MathFunction[0] *
    positionControlSlidingCircle_B.BackwardSubstitution[0] +
    positionControlSlidingCircle_B.matrixmult[0];
  positionControlSlidingCircle_B.matrixmult[0] =
    positionControlSlidingCircle_B.MathFunction[1] *
    positionControlSlidingCircle_B.BackwardSubstitution[1] +
    positionControlSlidingCircle_B.matrixmult[0];
  positionControlSlidingCircle_B.matrixmult[1] = 0.0;
  positionControlSlidingCircle_B.matrixmult[1] =
    positionControlSlidingCircle_B.MathFunction[0] *
    positionControlSlidingCircle_B.BackwardSubstitution[2] +
    positionControlSlidingCircle_B.matrixmult[1];
  positionControlSlidingCircle_B.matrixmult[1] =
    positionControlSlidingCircle_B.MathFunction[1] *
    positionControlSlidingCircle_B.BackwardSubstitution[3] +
    positionControlSlidingCircle_B.matrixmult[1];

  /* Fcn: '<Root>/rem(1)' incorporates:
   *  Constant: '<Root>/r0'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   *  Constant: '<S10>/cx'
   *  Constant: '<S10>/cy'
   *  Constant: '<S10>/mx'
   *  Constant: '<S10>/my'
   */
  denAccum = positionControlSlidingCircle_P.mx_Value;
  tmp_5 = rt_pow_snf(denAccum, -1.0);
  denAccum = positionControlSlidingCircle_P.my_Value;
  tmp_6 = rt_pow_snf(denAccum, -1.0);
  denAccum = (-positionControlSlidingCircle_P.xc_Value) +
    positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    tmp_7 = -rt_pow_snf(-denAccum, -2.5);
  } else {
    tmp_7 = rt_pow_snf(denAccum, -2.5);
  }

  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp_8 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_9 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_a = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_b = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp_c = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_d = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_e = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_f = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_g = rt_pow_snf(denAccum, 4.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_h = rt_pow_snf(denAccum, 3.0);
  denAccum = positionControlSlidingCircle_B.filterux2;
  tmp_i = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_j = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_k = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux2;
  tmp_l = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_m = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp_n = rt_pow_snf(denAccum, 5.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_o = rt_pow_snf(denAccum, 5.0);
  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp_p = rt_pow_snf(denAccum, 4.0);
  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp_q = rt_pow_snf(denAccum, 3.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_r = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_s = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_t = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_u = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.yc_Value;
  tmp_v = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_w = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux2;
  tmp_x = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_y = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_z = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.yc_Value;
  tmp_10 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_11 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_12 = rt_pow_snf(denAccum, 3.0);
  denAccum = positionControlSlidingCircle_B.filterux2;
  tmp_13 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_14 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_15 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_16 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.yc_Value;
  tmp_17 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_18 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_19 = rt_pow_snf(denAccum, 3.0);
  denAccum = positionControlSlidingCircle_B.filterux2;
  tmp_1a = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_1b = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_1c = rt_pow_snf(denAccum, 4.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_1d = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux2;
  tmp_1e = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_1f = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_1g = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.yc_Value;
  tmp_1h = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_1i = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_1j = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux2;
  tmp_1k = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_1l = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_1m = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_1n = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.yc_Value;
  tmp_1o = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_1p = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp_1q = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_1r = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux2;
  tmp_1s = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_1 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_2 = rt_pow_snf(denAccum, 3.0);
  denAccum = positionControlSlidingCircle_B.filterux2;
  tmp_3 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  tmp_4 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.yc_Value;
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux3;
  denAccum = rt_pow_snf(denAccum, 2.0);
  positionControlSlidingCircle_B.rem2X1[0] =
    (((((((((((((((((((-positionControlSlidingCircle_P.yc_Value) +
                      positionControlSlidingCircle_B.EncoderGain_o[0]) *
                     positionControlSlidingCircle_B.xrd +
                     ((-positionControlSlidingCircle_P.xc_Value) +
                      positionControlSlidingCircle_B.xr) *
                     positionControlSlidingCircle_B.filterux3) * (2.0 *
    positionControlSlidingCircle_B.filterux2) +
                    positionControlSlidingCircle_P.yc_Value * tmp_r) +
                   (((-positionControlSlidingCircle_B.xrdd) *
                     positionControlSlidingCircle_P.yc_Value +
                     positionControlSlidingCircle_B.xrdd *
                     positionControlSlidingCircle_B.EncoderGain_o[0]) + 2.0 *
                    positionControlSlidingCircle_B.xrd *
                    positionControlSlidingCircle_B.filterux3) * (4.0 *
    positionControlSlidingCircle_P.xc_Value)) + (-tmp_s) *
                  positionControlSlidingCircle_B.yr) + -2.0 *
                 positionControlSlidingCircle_B.EncoderGain_o[0] *
                 positionControlSlidingCircle_B.filterux3 *
                 positionControlSlidingCircle_B.yrd) + 2.0 *
                positionControlSlidingCircle_P.yc_Value *
                positionControlSlidingCircle_B.filterux3 *
                positionControlSlidingCircle_B.yrd) + 10.0 * tmp_t *
               positionControlSlidingCircle_B.yrdd) + 2.0 * tmp_u *
              positionControlSlidingCircle_B.yrdd) + -4.0 *
             positionControlSlidingCircle_B.EncoderGain_o[0] *
             positionControlSlidingCircle_P.yc_Value *
             positionControlSlidingCircle_B.yrdd) + 2.0 * tmp_v *
            positionControlSlidingCircle_B.yrdd) * tmp_q +
           ((((((((((-positionControlSlidingCircle_B.yrd) +
                    positionControlSlidingCircle_B.filterux3) *
                   positionControlSlidingCircle_P.yc_Value +
                   (-positionControlSlidingCircle_B.filterux3) *
                   positionControlSlidingCircle_B.yr) +
                  positionControlSlidingCircle_B.EncoderGain_o[0] *
                  positionControlSlidingCircle_B.yrd) * (2.0 *
    positionControlSlidingCircle_B.filterux2) +
                 ((-positionControlSlidingCircle_B.xrdd) * tmp_j + tmp_i *
                  positionControlSlidingCircle_B.xr)) * tmp_h +
                (((-positionControlSlidingCircle_B.xrd) +
                  positionControlSlidingCircle_B.filterux2) * 2.0 *
                 positionControlSlidingCircle_B.filterux3 + (-1.0 *
    positionControlSlidingCircle_B.EncoderGain_o[0] +
    positionControlSlidingCircle_P.yc_Value) *
                 positionControlSlidingCircle_B.xrdd) * tmp_g) + ((((2.0 *
    positionControlSlidingCircle_B.xrd *
    positionControlSlidingCircle_B.EncoderGain_o[0] + -2.0 *
    positionControlSlidingCircle_B.xrd * positionControlSlidingCircle_P.yc_Value)
    + -3.0 * positionControlSlidingCircle_B.xr *
    positionControlSlidingCircle_B.filterux3) *
    positionControlSlidingCircle_B.filterux3 + (2.0 * tmp_l *
    positionControlSlidingCircle_B.xr + 2.0 *
    positionControlSlidingCircle_B.xrdd * tmp_m)) + (((2.0 *
    positionControlSlidingCircle_B.EncoderGain_o[0] *
    positionControlSlidingCircle_B.filterux3 + -2.0 *
    positionControlSlidingCircle_B.filterux3 * positionControlSlidingCircle_B.yr)
    + -1.0 * positionControlSlidingCircle_B.EncoderGain_o[0] *
    positionControlSlidingCircle_B.yrd) +
    positionControlSlidingCircle_P.yc_Value * positionControlSlidingCircle_B.yrd)
    * (2.0 * positionControlSlidingCircle_B.filterux2)) *
               (((-positionControlSlidingCircle_P.yc_Value) +
                 positionControlSlidingCircle_B.EncoderGain_o[0]) * (-tmp_k))) +
              tmp_n * positionControlSlidingCircle_B.yrdd) + (-tmp_o) *
             positionControlSlidingCircle_B.yrdd) +
            ((((-positionControlSlidingCircle_P.yc_Value) +
               positionControlSlidingCircle_B.EncoderGain_o[0]) *
              positionControlSlidingCircle_B.xrdd + 2.0 *
              positionControlSlidingCircle_B.xrd *
              positionControlSlidingCircle_B.filterux3) + 5.0 *
             positionControlSlidingCircle_P.xc_Value *
             positionControlSlidingCircle_B.yrdd) * (-tmp_p))) +
          (((((((((-positionControlSlidingCircle_P.yc_Value) +
                  positionControlSlidingCircle_B.EncoderGain_o[0]) *
                 positionControlSlidingCircle_B.xrd + -2.0 *
                 positionControlSlidingCircle_B.xr *
                 positionControlSlidingCircle_B.filterux3) * (2.0 *
    positionControlSlidingCircle_B.filterux2) + ((2.0 *
    positionControlSlidingCircle_P.yc_Value +
    positionControlSlidingCircle_B.EncoderGain_o[0]) + -3.0 *
    positionControlSlidingCircle_B.yr) * tmp_x) + 2.0 * tmp_y *
               positionControlSlidingCircle_B.yr) + -2.0 *
              positionControlSlidingCircle_B.EncoderGain_o[0] *
              positionControlSlidingCircle_B.filterux3 *
              positionControlSlidingCircle_B.yrd) + tmp_z *
             positionControlSlidingCircle_B.yrdd) + tmp_10 *
            positionControlSlidingCircle_B.yrdd) +
           (((-positionControlSlidingCircle_B.filterux3) *
             positionControlSlidingCircle_B.yrd + tmp_11) +
            positionControlSlidingCircle_B.EncoderGain_o[0] *
            positionControlSlidingCircle_B.yrdd) * (-2.0 *
            positionControlSlidingCircle_P.yc_Value)) *
          ((-positionControlSlidingCircle_P.xc_Value) * tmp_w)) +
         (((((((((-positionControlSlidingCircle_P.yc_Value) +
                 positionControlSlidingCircle_B.EncoderGain_o[0]) *
                positionControlSlidingCircle_B.xrd +
                positionControlSlidingCircle_B.xr *
                positionControlSlidingCircle_B.filterux3) * (-2.0 *
    positionControlSlidingCircle_B.filterux2) +
               (((-positionControlSlidingCircle_P.yc_Value) +
                 positionControlSlidingCircle_B.EncoderGain_o[0]) * (2.0 *
    tmp_13) + 2.0 * positionControlSlidingCircle_P.yc_Value * tmp_14)) + tmp_15 *
              positionControlSlidingCircle_B.yr) + -2.0 *
             positionControlSlidingCircle_P.yc_Value *
             positionControlSlidingCircle_B.filterux3 *
             positionControlSlidingCircle_B.yrd) + -2.0 * tmp_16 *
            positionControlSlidingCircle_B.yrdd) + -2.0 * tmp_17 *
           positionControlSlidingCircle_B.yrdd) + ((2.0 *
            positionControlSlidingCircle_B.filterux3 *
            positionControlSlidingCircle_B.yrd + -3.0 * tmp_18) + 4.0 *
           positionControlSlidingCircle_P.yc_Value *
           positionControlSlidingCircle_B.yrdd) *
          positionControlSlidingCircle_B.EncoderGain_o[0]) * tmp_12) +
        (((((((((((-positionControlSlidingCircle_P.yc_Value) +
                  positionControlSlidingCircle_B.EncoderGain_o[0]) *
                 positionControlSlidingCircle_B.xrd + -2.0 *
                 positionControlSlidingCircle_B.xr *
                 positionControlSlidingCircle_B.filterux3) * (2.0 *
    positionControlSlidingCircle_B.filterux2) +
                ((-positionControlSlidingCircle_B.yr) +
                 positionControlSlidingCircle_P.yc_Value) * (3.0 * tmp_1e)) +
               2.0 * tmp_1f * positionControlSlidingCircle_B.yr) + -2.0 *
              positionControlSlidingCircle_B.EncoderGain_o[0] *
              positionControlSlidingCircle_B.filterux3 *
              positionControlSlidingCircle_B.yrd) + tmp_1g *
             positionControlSlidingCircle_B.yrdd) + tmp_1h *
            positionControlSlidingCircle_B.yrdd) +
           (((-positionControlSlidingCircle_B.filterux3) *
             positionControlSlidingCircle_B.yrd + tmp_1i) +
            positionControlSlidingCircle_B.EncoderGain_o[0] *
            positionControlSlidingCircle_B.yrdd) * (-2.0 *
            positionControlSlidingCircle_P.yc_Value)) * tmp_1d +
          (((((((-positionControlSlidingCircle_P.yc_Value) +
                positionControlSlidingCircle_B.EncoderGain_o[0]) * (2.0 *
    positionControlSlidingCircle_B.xrd) + -3.0 *
               positionControlSlidingCircle_B.xr *
               positionControlSlidingCircle_B.filterux3) *
              positionControlSlidingCircle_B.filterux3 + (2.0 * tmp_1a *
    positionControlSlidingCircle_B.xr + 2.0 *
    positionControlSlidingCircle_B.xrdd * tmp_1b)) +
             ((((-positionControlSlidingCircle_B.yrd) +
                positionControlSlidingCircle_B.filterux3) *
               positionControlSlidingCircle_B.EncoderGain_o[0] + -2.0 *
               positionControlSlidingCircle_B.filterux3 *
               positionControlSlidingCircle_B.yr) +
              (positionControlSlidingCircle_B.filterux3 +
               positionControlSlidingCircle_B.yrd) *
              positionControlSlidingCircle_P.yc_Value) * (2.0 *
              positionControlSlidingCircle_B.filterux2)) *
            (((-positionControlSlidingCircle_P.yc_Value) +
              positionControlSlidingCircle_B.EncoderGain_o[0]) * (2.0 *
              positionControlSlidingCircle_P.xc_Value)) +
            ((((-positionControlSlidingCircle_P.yc_Value) +
               positionControlSlidingCircle_B.EncoderGain_o[0]) * (4.0 *
    positionControlSlidingCircle_B.xrdd) + -6.0 *
              positionControlSlidingCircle_B.filterux2 *
              positionControlSlidingCircle_B.filterux3) + 8.0 *
             positionControlSlidingCircle_B.xrd *
             positionControlSlidingCircle_B.filterux3) * tmp_19) + 5.0 * tmp_1c *
           positionControlSlidingCircle_B.yrdd)) +
         (((((((((-positionControlSlidingCircle_P.yc_Value) +
                 positionControlSlidingCircle_B.EncoderGain_o[0]) *
                positionControlSlidingCircle_B.xrd +
                positionControlSlidingCircle_B.xr *
                positionControlSlidingCircle_B.filterux3) * (6.0 *
    positionControlSlidingCircle_B.filterux2) +
               (((-positionControlSlidingCircle_P.yc_Value) +
                 positionControlSlidingCircle_B.EncoderGain_o[0]) * (-4.0 *
    tmp_1k) + -3.0 * positionControlSlidingCircle_P.yc_Value * tmp_1l)) + -3.0 *
              tmp_1m * positionControlSlidingCircle_B.yr) + 6.0 *
             positionControlSlidingCircle_P.yc_Value *
             positionControlSlidingCircle_B.filterux3 *
             positionControlSlidingCircle_B.yrd) + 6.0 * tmp_1n *
            positionControlSlidingCircle_B.yrdd) + 6.0 * tmp_1o *
           positionControlSlidingCircle_B.yrdd) +
          (((-positionControlSlidingCircle_B.filterux3) *
            positionControlSlidingCircle_B.yrd + tmp_1p) + -2.0 *
           positionControlSlidingCircle_P.yc_Value *
           positionControlSlidingCircle_B.yrdd) * (6.0 *
           positionControlSlidingCircle_B.EncoderGain_o[0])) * tmp_1j) *
        positionControlSlidingCircle_B.convert2radians[0]) + (((((((2.0 *
              positionControlSlidingCircle_B.xrd *
              positionControlSlidingCircle_B.EncoderGain_o[0] + -2.0 *
              positionControlSlidingCircle_B.xrd *
              positionControlSlidingCircle_P.yc_Value) + -3.0 *
             positionControlSlidingCircle_B.xr *
             positionControlSlidingCircle_B.filterux3) *
            positionControlSlidingCircle_B.filterux3 + (2.0 * tmp_1s *
             positionControlSlidingCircle_B.xr + 2.0 *
             positionControlSlidingCircle_B.xrdd * tmp_1)) + ((-2.0 *
             positionControlSlidingCircle_B.filterux3 *
             positionControlSlidingCircle_B.yr + -1.0 *
             positionControlSlidingCircle_B.EncoderGain_o[0] *
             positionControlSlidingCircle_B.yrd) + (2.0 *
             positionControlSlidingCircle_B.filterux3 +
             positionControlSlidingCircle_B.yrd) *
            positionControlSlidingCircle_P.yc_Value) * (2.0 *
            positionControlSlidingCircle_B.filterux2)) *
          ((-positionControlSlidingCircle_P.yc_Value) +
           positionControlSlidingCircle_B.EncoderGain_o[0]) +
          ((((-positionControlSlidingCircle_B.xrdd) *
             positionControlSlidingCircle_P.yc_Value +
             positionControlSlidingCircle_B.xrdd *
             positionControlSlidingCircle_B.EncoderGain_o[0]) +
            (-positionControlSlidingCircle_B.filterux2) *
            positionControlSlidingCircle_B.filterux3) + 2.0 *
           positionControlSlidingCircle_B.xrd *
           positionControlSlidingCircle_B.filterux3) * (6.0 * tmp_1r)) + 10.0 *
         tmp_2 * positionControlSlidingCircle_B.yrdd) + (((((2.0 *
             positionControlSlidingCircle_P.yc_Value *
             positionControlSlidingCircle_B.filterux3 *
             positionControlSlidingCircle_B.yrd + (-tmp_4) *
             positionControlSlidingCircle_B.yr) + 2.0 * tmp *
            positionControlSlidingCircle_B.yrdd) + 2.0 * tmp_0 *
           positionControlSlidingCircle_B.yrdd) + ((-2.0 *
            positionControlSlidingCircle_B.filterux3 *
            positionControlSlidingCircle_B.yrd + denAccum) + -4.0 *
           positionControlSlidingCircle_P.yc_Value *
           positionControlSlidingCircle_B.yrdd) *
          positionControlSlidingCircle_B.EncoderGain_o[0]) * 3.0 +
         ((((-positionControlSlidingCircle_P.yc_Value) +
            positionControlSlidingCircle_B.EncoderGain_o[0]) *
           positionControlSlidingCircle_B.xrd +
           positionControlSlidingCircle_B.xr *
           positionControlSlidingCircle_B.filterux3) * (6.0 *
           positionControlSlidingCircle_B.filterux2) +
          ((-positionControlSlidingCircle_P.yc_Value) +
           positionControlSlidingCircle_B.EncoderGain_o[0]) * (-2.0 * tmp_3))) *
        positionControlSlidingCircle_P.xc_Value) * (-tmp_1q)) *
      positionControlSlidingCircle_P.my_Value + (((-2.0 *
         positionControlSlidingCircle_B.convert2radians[0] *
         positionControlSlidingCircle_P.xc_Value + tmp_c) + tmp_d) + tmp_e) *
      (((-positionControlSlidingCircle_P.xc_Value) +
        positionControlSlidingCircle_B.convert2radians[0]) *
       (-positionControlSlidingCircle_P.cy_Value)) *
      positionControlSlidingCircle_B.filterux3 *
      (((((-positionControlSlidingCircle_B.xr) +
          positionControlSlidingCircle_P.xc_Value) *
         positionControlSlidingCircle_B.convert2radians[0] + (-tmp_f)) +
        positionControlSlidingCircle_P.xc_Value *
        positionControlSlidingCircle_B.xr) +
       ((-positionControlSlidingCircle_P.yc_Value) +
        positionControlSlidingCircle_B.EncoderGain_o[0]) *
       ((-positionControlSlidingCircle_B.yr) +
        positionControlSlidingCircle_P.yc_Value))) *
     positionControlSlidingCircle_P.mx_Value + (((-2.0 *
        positionControlSlidingCircle_B.convert2radians[0] *
        positionControlSlidingCircle_P.xc_Value + tmp_8) + tmp_9) + tmp_a) *
     (positionControlSlidingCircle_P.cx_Value *
      positionControlSlidingCircle_P.my_Value *
      positionControlSlidingCircle_B.filterux2) *
     ((-positionControlSlidingCircle_P.yc_Value) +
      positionControlSlidingCircle_B.EncoderGain_o[0]) *
     (((((-positionControlSlidingCircle_B.xr) +
         positionControlSlidingCircle_P.xc_Value) *
        positionControlSlidingCircle_B.convert2radians[0] + (-tmp_b)) +
       positionControlSlidingCircle_P.xc_Value *
       positionControlSlidingCircle_B.xr) +
      ((-positionControlSlidingCircle_P.yc_Value) +
       positionControlSlidingCircle_B.EncoderGain_o[0]) *
      ((-positionControlSlidingCircle_B.yr) +
       positionControlSlidingCircle_P.yc_Value))) * (tmp_5 * tmp_6 * tmp_7);

  /* Fcn: '<Root>/rem(2)' incorporates:
   *  Constant: '<Root>/r0'
   *  Constant: '<Root>/xc'
   *  Constant: '<Root>/yc'
   *  Constant: '<S10>/cx'
   *  Constant: '<S10>/cy'
   *  Constant: '<S10>/mx'
   *  Constant: '<S10>/my'
   */
  denAccum = positionControlSlidingCircle_P.mx_Value;
  tmp_1q = rt_pow_snf(denAccum, -1.0);
  denAccum = positionControlSlidingCircle_P.my_Value;
  tmp_1r = rt_pow_snf(denAccum, -1.0);
  denAccum = (-positionControlSlidingCircle_P.xc_Value) +
    positionControlSlidingCircle_B.convert2radians[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    tmp_1s = -rt_pow_snf(-denAccum, -1.5);
  } else {
    tmp_1s = rt_pow_snf(denAccum, -1.5);
  }

  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp_1 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp_2 = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_3 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.convert2radians[0];
  tmp_4 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_P.xc_Value;
  tmp = rt_pow_snf(denAccum, 2.0);
  denAccum = (-positionControlSlidingCircle_P.yc_Value) +
    positionControlSlidingCircle_B.EncoderGain_o[0];
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = ((-positionControlSlidingCircle_P.yc_Value) +
              positionControlSlidingCircle_B.EncoderGain_o[0]) *
    positionControlSlidingCircle_B.filterux2 + (-1.0 *
    positionControlSlidingCircle_B.convert2radians[0] +
    positionControlSlidingCircle_P.xc_Value) *
    positionControlSlidingCircle_B.filterux3;
  denAccum = rt_pow_snf(denAccum, 2.0);
  positionControlSlidingCircle_B.rem2X1[1] = (((((-2.0 *
    positionControlSlidingCircle_B.convert2radians[0] *
    positionControlSlidingCircle_P.xc_Value + tmp_4) + tmp) + tmp_0) *
    (-positionControlSlidingCircle_P.cy_Value) *
    ((-positionControlSlidingCircle_P.yc_Value) +
     positionControlSlidingCircle_B.EncoderGain_o[0]) *
    positionControlSlidingCircle_B.filterux3 +
    positionControlSlidingCircle_P.my_Value * denAccum) *
    positionControlSlidingCircle_P.mx_Value + (((-2.0 *
    positionControlSlidingCircle_B.convert2radians[0] *
    positionControlSlidingCircle_P.xc_Value + tmp_1) + tmp_2) + tmp_3) *
    ((-positionControlSlidingCircle_P.cx_Value) *
     positionControlSlidingCircle_P.my_Value *
     ((-positionControlSlidingCircle_P.xc_Value) +
      positionControlSlidingCircle_B.convert2radians[0]) *
     positionControlSlidingCircle_B.filterux2)) * (tmp_1q * tmp_1r * tmp_1s);

  /* Sum: '<S16>/Add2' */
  positionControlSlidingCircle_B.Add2[0] =
    positionControlSlidingCircle_B.matrixmult[0] -
    positionControlSlidingCircle_B.rem2X1[0];

  /* Math: '<S29>/Math Function' */
  positionControlSlidingCircle_B.MathFunction_g[0] =
    positionControlSlidingCircle_B.Add2[0];

  /* Sum: '<S16>/Add2' */
  positionControlSlidingCircle_B.Add2[1] =
    positionControlSlidingCircle_B.matrixmult[1] -
    positionControlSlidingCircle_B.rem2X1[1];

  /* Math: '<S29>/Math Function' */
  positionControlSlidingCircle_B.MathFunction_g[1] =
    positionControlSlidingCircle_B.Add2[1];

  /* Product: '<S16>/matrix mult1' */
  positionControlSlidingCircle_B.matrixmult1[0] = 0.0;
  positionControlSlidingCircle_B.matrixmult1[0] =
    positionControlSlidingCircle_B.Pseudoinverse[0] *
    positionControlSlidingCircle_B.MathFunction_g[0] +
    positionControlSlidingCircle_B.matrixmult1[0];
  positionControlSlidingCircle_B.matrixmult1[0] =
    positionControlSlidingCircle_B.Pseudoinverse[2] *
    positionControlSlidingCircle_B.MathFunction_g[1] +
    positionControlSlidingCircle_B.matrixmult1[0];
  positionControlSlidingCircle_B.matrixmult1[1] = 0.0;
  positionControlSlidingCircle_B.matrixmult1[1] =
    positionControlSlidingCircle_B.Pseudoinverse[1] *
    positionControlSlidingCircle_B.MathFunction_g[0] +
    positionControlSlidingCircle_B.matrixmult1[1];
  positionControlSlidingCircle_B.matrixmult1[1] =
    positionControlSlidingCircle_B.Pseudoinverse[3] *
    positionControlSlidingCircle_B.MathFunction_g[1] +
    positionControlSlidingCircle_B.matrixmult1[1];

  /* Gain: '<Root>/uxorig' */
  positionControlSlidingCircle_B.uxorig =
    positionControlSlidingCircle_P.uxorig_Gain *
    positionControlSlidingCircle_B.matrixmult1[0];

  /* Sum: '<Root>/Add' */
  positionControlSlidingCircle_B.Add_h2 =
    positionControlSlidingCircle_B.filterux4 +
    positionControlSlidingCircle_B.uxorig;

  /* Product: '<Root>/uxact' incorporates:
   *  Constant: '<Root>/DA On-Off'
   */
  positionControlSlidingCircle_B.uxact =
    positionControlSlidingCircle_P.DAOnOff_Value *
    positionControlSlidingCircle_B.Add_h2;

  /* Gain: '<Root>/DA GainY' */
  positionControlSlidingCircle_B.DAGainY =
    positionControlSlidingCircle_P.DAGainY_Gain *
    positionControlSlidingCircle_B.uxact;

  /* Saturate: '<Root>/Saturation' */
  denAccum = positionControlSlidingCircle_B.DAGainY;
  positionControlSlidingCircle_B.Saturation = rt_SATURATE(denAccum,
    positionControlSlidingCircle_P.Saturation_LowerSat,
    positionControlSlidingCircle_P.Saturation_UpperSat);

  /* DiscreteFilter: '<Root>/filterux' */
  denAccum = positionControlSlidingCircle_B.Saturation;
  denAccum -= positionControlSlidingCircle_P.filterux_Denominator[1] *
    positionControlSlidingCir_DWork.filterux_DSTATE;
  denAccum /= positionControlSlidingCircle_P.filterux_Denominator[0];
  positionControlSlidingCir_DWork.filterux_tmp = denAccum;
  denAccum = positionControlSlidingCircle_P.filterux_Numerator *
    positionControlSlidingCir_DWork.filterux_tmp;
  positionControlSlidingCircle_B.filterux = denAccum;

  /* S-Function (rti_commonblock): '<S17>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(1, positionControlSlidingCircle_B.filterux);

  /* Gain: '<Root>/uyorig' */
  positionControlSlidingCircle_B.uyorig =
    positionControlSlidingCircle_P.uyorig_Gain *
    positionControlSlidingCircle_B.matrixmult1[1];

  /* Sum: '<Root>/Add1' */
  positionControlSlidingCircle_B.Add1_o = 0.0 +
    positionControlSlidingCircle_B.uyorig;

  /* Product: '<Root>/uyact' incorporates:
   *  Constant: '<Root>/DA On-Off'
   */
  positionControlSlidingCircle_B.uyact =
    positionControlSlidingCircle_P.DAOnOff_Value *
    positionControlSlidingCircle_B.Add1_o;

  /* Gain: '<Root>/DA GainY1' */
  positionControlSlidingCircle_B.DAGainY1 =
    positionControlSlidingCircle_P.DAGainY1_Gain *
    positionControlSlidingCircle_B.uyact;

  /* Saturate: '<Root>/Saturation1' */
  denAccum = positionControlSlidingCircle_B.DAGainY1;
  positionControlSlidingCircle_B.Saturation1 = rt_SATURATE(denAccum,
    positionControlSlidingCircle_P.Saturation1_LowerSat,
    positionControlSlidingCircle_P.Saturation1_UpperSat);

  /* DiscreteFilter: '<Root>/filterux1' */
  denAccum = positionControlSlidingCircle_B.Saturation1;
  denAccum -= positionControlSlidingCircle_P.filterux1_Denominator[1] *
    positionControlSlidingCir_DWork.filterux1_DSTATE;
  denAccum /= positionControlSlidingCircle_P.filterux1_Denominator[0];
  positionControlSlidingCir_DWork.filterux1_tmp = denAccum;
  denAccum = positionControlSlidingCircle_P.filterux1_Numerator *
    positionControlSlidingCir_DWork.filterux1_tmp;
  positionControlSlidingCircle_B.filterux1 = denAccum;

  /* S-Function (rti_commonblock): '<S18>/S-Function1' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(2, positionControlSlidingCircle_B.filterux1);

  /* Outputs for trigger SubSystem: '<S1>/DS1103ENC_SET_POS_C2' incorporates:
   *  Constant: '<Root>/ENC Reset'
   *  TriggerPort: '<S20>/Trigger'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &positionControlS_PrevZCSigState.DS1103ENC_SET_POS_C2_Trig_ZCE,
               (positionControlSlidingCircle_P.ENCReset_Value)) != NO_ZCEVENT) {
    /* S-Function (rti_commonblock): '<S20>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1103 Unit:ENC_SET */
    ds1103_inc_position_write(2, 0, DS1103_INC_LINE_SUBDIV_4);
  }

  /* end of Outputs for SubSystem: '<S1>/DS1103ENC_SET_POS_C2' */

  /* Outputs for trigger SubSystem: '<S1>/_DS1103ENC_SET_POS_C1' incorporates:
   *  Constant: '<Root>/ENC Reset'
   *  TriggerPort: '<S22>/Trigger'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &positionControlS_PrevZCSigState._DS1103ENC_SET_POS_C1_Trig_ZCE,
               (positionControlSlidingCircle_P.ENCReset_Value)) != NO_ZCEVENT) {
    /* S-Function (rti_commonblock): '<S22>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1103 Unit:ENC_SET */
    ds1103_inc_position_write(1, 0, DS1103_INC_LINE_SUBDIV_4);
  }

  /* end of Outputs for SubSystem: '<S1>/_DS1103ENC_SET_POS_C1' */

  /* Outputs for trigger SubSystem: '<S2>/DS1103ENC_SET_POS_C3' incorporates:
   *  Constant: '<Root>/ENC Reset'
   *  TriggerPort: '<S24>/Trigger'
   */
  if (rt_ZCFcn(RISING_ZERO_CROSSING,
               &positionControlS_PrevZCSigState.DS1103ENC_SET_POS_C3_Trig_ZCE,
               (positionControlSlidingCircle_P.ENCReset_Value)) != NO_ZCEVENT) {
    /* S-Function (rti_commonblock): '<S24>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1103 Unit:ENC_SET */
    ds1103_inc_position_write(3, 0, DS1103_INC_LINE_SUBDIV_4);
  }

  /* end of Outputs for SubSystem: '<S2>/DS1103ENC_SET_POS_C3' */

  /* Gain: '<Root>/gainAddY' */
  positionControlSlidingCircle_B.gainAddY =
    positionControlSlidingCircle_P.gainAddY_Gain *
    positionControlSlidingCircle_B.Kpepsilond1[1];

  /* DiscreteFilter: '<Root>/filterux5' */
  denAccum = positionControlSlidingCircle_B.gainAddY;
  denAccum -= positionControlSlidingCircle_P.filterux5_Denominator[1] *
    positionControlSlidingCir_DWork.filterux5_DSTATE;
  denAccum /= positionControlSlidingCircle_P.filterux5_Denominator[0];
  positionControlSlidingCir_DWork.filterux5_tmp = denAccum;
  denAccum = positionControlSlidingCircle_P.filterux5_Numerator *
    positionControlSlidingCir_DWork.filterux5_tmp;
  positionControlSlidingCircle_B.filterux5 = denAccum;

  /* Fcn: '<Root>/Fcn' */
  denAccum = positionControlSlidingCircle_B.filterux4;
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.filterux5;
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    denAccum = -sqrt(-denAccum);
  } else {
    denAccum = sqrt(denAccum);
  }

  positionControlSlidingCircle_B.Fcn = denAccum;

  /* Fcn: '<Root>/Fcn1' */
  denAccum = positionControlSlidingCircle_B.uxorig;
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.uyorig;
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp_0;
  if (denAccum < 0.0) {
    denAccum = -sqrt(-denAccum);
  } else {
    denAccum = sqrt(denAccum);
  }

  positionControlSlidingCircle_B.Fcn1 = denAccum;

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlSlidingCircle_B.LogicalOperator =
    !(positionControlSlidingCircle_P.startX_Value != 0.0);

  /* Product: '<Root>/Product2' incorporates:
   *  Constant: '<Root>/input2'
   */
  positionControlSlidingCircle_B.Product2 =
    positionControlSlidingCircle_P.input2_Value * (real_T)
    positionControlSlidingCircle_B.LogicalOperator;

  /* Gain: '<Root>/currentNegated' */
  positionControlSlidingCircle_B.currentNegated =
    positionControlSlidingCircle_P.currentNegated_Gain *
    positionControlSlidingCircle_B.uxact;

  /* Gain: '<Root>/utotal' */
  positionControlSlidingCircle_B.utotal =
    positionControlSlidingCircle_P.utotal_Gain *
    positionControlSlidingCircle_B.Fcn;

  /* Gain: '<Root>/utotalorig' */
  positionControlSlidingCircle_B.utotalorig =
    positionControlSlidingCircle_P.utotalorig_Gain *
    positionControlSlidingCircle_B.Fcn1;

  /* S-Function (rti_commonblock): '<S3>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<Root>/ADC Gain' */
  positionControlSlidingCircle_B.ADCGain =
    positionControlSlidingCircle_P.ADCGain_Gain *
    positionControlSlidingCircle_B.SFunction;

  /* S-Function (rti_commonblock): '<S4>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<Root>/ADC Gain1' */
  positionControlSlidingCircle_B.ADCGain1 =
    positionControlSlidingCircle_P.ADCGain1_Gain *
    positionControlSlidingCircle_B.SFunction_g;

  /* S-Function (rti_commonblock): '<S5>/S-Function' */
  /* This comment workarounds a Real-Time Workshop code generation problem */

  /* Gain: '<Root>/ADC Gain2' */
  positionControlSlidingCircle_B.ADCGain2 =
    positionControlSlidingCircle_P.ADCGain2_Gain *
    positionControlSlidingCircle_B.SFunction_m;

  /* Gain: '<Root>/GainFx' */
  positionControlSlidingCircle_B.GainFx =
    positionControlSlidingCircle_P.GainFx_Gain *
    positionControlSlidingCircle_B.ADCGain;

  /* Gain: '<Root>/GainFy' */
  positionControlSlidingCircle_B.GainFy =
    positionControlSlidingCircle_P.GainFy_Gain *
    positionControlSlidingCircle_B.ADCGain1;

  /* Gain: '<Root>/GainFz' */
  positionControlSlidingCircle_B.GainFz =
    positionControlSlidingCircle_P.GainFz_Gain *
    positionControlSlidingCircle_B.ADCGain2;

  /* Fcn: '<Root>/ForceMag' */
  denAccum = positionControlSlidingCircle_B.GainFx;
  tmp = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.GainFy;
  tmp_0 = rt_pow_snf(denAccum, 2.0);
  denAccum = positionControlSlidingCircle_B.GainFz;
  denAccum = rt_pow_snf(denAccum, 2.0);
  denAccum += tmp + tmp_0;
  if (denAccum < 0.0) {
    denAccum = -sqrt(-denAccum);
  } else {
    denAccum = sqrt(denAccum);
  }

  positionControlSlidingCircle_B.ForceMag = denAccum;

  /* Constant: '<Root>/Kd1,1' */
  positionControlSlidingCircle_B.Kd11 =
    positionControlSlidingCircle_P.Kd11_Value;

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
static void positionControlSlidingCircle_update(int_T tid)
{
  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/startX'
   */
  positionControlSlidingCir_DWork.DiscreteTimeIntegrator_DSTATE =
    positionControlSlidingCircle_P.DiscreteTimeIntegrator_gainval *
    positionControlSlidingCircle_P.startX_Value +
    positionControlSlidingCir_DWork.DiscreteTimeIntegrator_DSTATE;
  if (positionControlSlidingCircle_P.startX_Value > 0.0) {
    positionControlSlidingCir_DWork.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (positionControlSlidingCircle_P.startX_Value < 0.0) {
    positionControlSlidingCir_DWork.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (positionControlSlidingCircle_P.startX_Value == 0.0) {
    positionControlSlidingCir_DWork.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    positionControlSlidingCir_DWork.DiscreteTimeIntegrator_PrevRese = 2;
  }

  /* Update for DiscreteFilter: '<Root>/filterux4' */
  positionControlSlidingCir_DWork.filterux4_DSTATE =
    positionControlSlidingCir_DWork.filterux4_tmp;

  /* Update for DiscreteFilter: '<Root>/filterux2' */
  positionControlSlidingCir_DWork.filterux2_DSTATE =
    positionControlSlidingCir_DWork.filterux2_tmp;

  /* Update for DiscreteFilter: '<Root>/filterux3' */
  positionControlSlidingCir_DWork.filterux3_DSTATE =
    positionControlSlidingCir_DWork.filterux3_tmp;

  /* Update for DiscreteFilter: '<Root>/filterux' */
  positionControlSlidingCir_DWork.filterux_DSTATE =
    positionControlSlidingCir_DWork.filterux_tmp;

  /* Update for DiscreteFilter: '<Root>/filterux1' */
  positionControlSlidingCir_DWork.filterux1_DSTATE =
    positionControlSlidingCir_DWork.filterux1_tmp;

  /* Update for DiscreteFilter: '<Root>/filterux5' */
  positionControlSlidingCir_DWork.filterux5_DSTATE =
    positionControlSlidingCir_DWork.filterux5_tmp;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++positionControlSlidingCircle_M->Timing.clockTick0)) {
    ++positionControlSlidingCircle_M->Timing.clockTickH0;
  }

  positionControlSlidingCircle_M->Timing.t[0] =
    positionControlSlidingCircle_M->Timing.clockTick0 *
    positionControlSlidingCircle_M->Timing.stepSize0 +
    positionControlSlidingCircle_M->Timing.clockTickH0 *
    positionControlSlidingCircle_M->Timing.stepSize0 * 4294967296.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void positionControlSlidingCircle_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)positionControlSlidingCircle_M, 0,
                sizeof(RT_MODEL_positionControlSliding));

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      positionControlSlidingCircle_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    positionControlSlidingCircle_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    positionControlSlidingCircle_M->Timing.sampleTimes =
      (&positionControlSlidingCircle_M->Timing.sampleTimesArray[0]);
    positionControlSlidingCircle_M->Timing.offsetTimes =
      (&positionControlSlidingCircle_M->Timing.offsetTimesArray[0]);

    /* task periods */
    positionControlSlidingCircle_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    positionControlSlidingCircle_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(positionControlSlidingCircle_M,
             &positionControlSlidingCircle_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = positionControlSlidingCircle_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    positionControlSlidingCircle_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(positionControlSlidingCircle_M, -1);
  positionControlSlidingCircle_M->Timing.stepSize0 = 0.001;
  positionControlSlidingCircle_M->solverInfoPtr =
    (&positionControlSlidingCircle_M->solverInfo);
  positionControlSlidingCircle_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&positionControlSlidingCircle_M->solverInfo, 0.001);
  rtsiSetSolverMode(&positionControlSlidingCircle_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  positionControlSlidingCircle_M->ModelData.blockIO = ((void *)
    &positionControlSlidingCircle_B);
  (void) memset(((void *) &positionControlSlidingCircle_B), 0,
                sizeof(BlockIO_positionControlSlidingC));

  /* parameters */
  positionControlSlidingCircle_M->ModelData.defaultParam = ((real_T *)
    &positionControlSlidingCircle_P);

  /* states (dwork) */
  positionControlSlidingCircle_M->Work.dwork = ((void *)
    &positionControlSlidingCir_DWork);
  (void) memset((void *)&positionControlSlidingCir_DWork, 0,
                sizeof(D_Work_positionControlSlidingCi));

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  positionControlS_PrevZCSigState.DS1103ENC_SET_POS_C3_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
  positionControlS_PrevZCSigState._DS1103ENC_SET_POS_C1_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
  positionControlS_PrevZCSigState.DS1103ENC_SET_POS_C2_Trig_ZCE =
    UNINITIALIZED_ZCSIG;
}

/* Model terminate function */
void positionControlSlidingCircle_terminate(void)
{
  /* Terminate for S-Function (rti_commonblock): '<S17>/S-Function1' */

  /* dSPACE I/O Board DS1103 #1 Unit:DAC */
  ds1103_dac_write(1, 0);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  positionControlSlidingCircle_output(tid);
}

void MdlUpdate(int_T tid)
{
  positionControlSlidingCircle_update(tid);
}

void MdlInitializeSizes(void)
{
  positionControlSlidingCircle_M->Sizes.numContStates = (0);/* Number of continuous states */
  positionControlSlidingCircle_M->Sizes.numY = (0);/* Number of model outputs */
  positionControlSlidingCircle_M->Sizes.numU = (0);/* Number of model inputs */
  positionControlSlidingCircle_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  positionControlSlidingCircle_M->Sizes.numSampTimes = (1);/* Number of sample times */
  positionControlSlidingCircle_M->Sizes.numBlocks = (176);/* Number of blocks */
  positionControlSlidingCircle_M->Sizes.numBlockIO = (105);/* Number of block outputs */
  positionControlSlidingCircle_M->Sizes.numBlockPrms = (59207);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' */
  positionControlSlidingCir_DWork.DiscreteTimeIntegrator_DSTATE =
    positionControlSlidingCircle_P.DiscreteTimeIntegrator_IC;
  positionControlSlidingCir_DWork.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for DiscreteFilter: '<Root>/filterux4' */
  positionControlSlidingCir_DWork.filterux4_DSTATE =
    positionControlSlidingCircle_P.filterux4_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<Root>/filterux2' */
  positionControlSlidingCir_DWork.filterux2_DSTATE =
    positionControlSlidingCircle_P.filterux2_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<Root>/filterux3' */
  positionControlSlidingCir_DWork.filterux3_DSTATE =
    positionControlSlidingCircle_P.filterux3_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<Root>/filterux' */
  positionControlSlidingCir_DWork.filterux_DSTATE =
    positionControlSlidingCircle_P.filterux_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<Root>/filterux1' */
  positionControlSlidingCir_DWork.filterux1_DSTATE =
    positionControlSlidingCircle_P.filterux1_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<Root>/filterux5' */
  positionControlSlidingCir_DWork.filterux5_DSTATE =
    positionControlSlidingCircle_P.filterux5_InitialStates;
}

void MdlStart(void)
{
  /* Start for S-Function (sdspeye): '<S30>/Identity Matrix' */
  positionControlSlidingCircle_B.IdentityMatrix[0] = 0.0;
  positionControlSlidingCircle_B.IdentityMatrix[1] = 0.0;
  positionControlSlidingCircle_B.IdentityMatrix[2] = 0.0;
  positionControlSlidingCircle_B.IdentityMatrix[3] = 0.0;

  /* Fill in 1's on the diagonal. */
  positionControlSlidingCircle_B.IdentityMatrix[0] = 1.0;
  positionControlSlidingCircle_B.IdentityMatrix[3] = 1.0;
  MdlInitialize();
}

void MdlTerminate(void)
{
  positionControlSlidingCircle_terminate();
}

RT_MODEL_positionControlSliding *positionControlSlidingCircle(void)
{
  positionControlSlidingCircle_initialize(1);
  return positionControlSlidingCircle_M;
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
