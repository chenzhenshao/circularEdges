/***************************************************************************

   Source file positionControlLoopCircle_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Tue Jan 24 00:13:25 2017

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "positionControlLoopCircle_trc_ptr.h"

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_positionControlLoopCircle_B_real_T_0 = 0;
volatile boolean_T *p_positionControlLoopCircle_B_boolean_T_1 = 0;
volatile real_T *p_positionControlLoopCircle_P_real_T_0 = 0;
volatile real_T *p_positionControlLoopCircle_DWork_real_T_0 = 0;
volatile int8_T *p_positionControlLoopCircle_DWork_int8_T_2 = 0;
