/*
 * positionControlSlidingCircle_private.h
 *
 * Real-Time Workshop code generation for Simulink model "positionControlSlidingCircle.mdl".
 *
 * Model version              : 1.170
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Fri May 05 14:34:40 2017
 *
 * Target selection: rti1103.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_positionControlSlidingCircle_private_h_
#define RTW_HEADER_positionControlSlidingCircle_private_h_
#include "rtwtypes.h"
#include "dsp_rt.h"                    /* Signal Processing Blockset general run time support functions */
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

/*
 * UNUSED_PARAMETER(x)
 *   Used to specify that a function parameter (argument) is required but not
 *   accessed by the function body.
 */
#ifndef UNUSED_PARAMETER
# if defined(__LCC__)
#   define UNUSED_PARAMETER(x)                                   /* do nothing */
# else

/*
 * This is the semi-ANSI standard way of indicating that an
 * unused function parameter is required.
 */
#   define UNUSED_PARAMETER(x)         (void) (x)
# endif
#endif

extern void MWDSPCG_Pseudoinverse_D(real_T pS[], real_T pU[], real_T pV[],
  real_T pX[], const int32_T M, const int32_T N);
extern void LUf_int32_Treal_T(real_T outU[], real_T outP[], const int32_T N);

#endif                                 /* RTW_HEADER_positionControlSlidingCircle_private_h_ */
