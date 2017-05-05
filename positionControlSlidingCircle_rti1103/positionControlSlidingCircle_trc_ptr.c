/***************************************************************************

   Source file positionControlSlidingCircle_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Fri May 05 14:34:40 2017

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "positionControlSlidingCircle_trc_ptr.h"

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_positionControlSlidingCircle_B_real_T_0 = 0;
volatile boolean_T *p_positionControlSlidingCircle_B_boolean_T_1 = 0;
volatile real_T *p_positionControlSlidingCircle_P_real_T_0 = 0;
volatile real_T *p_positionControlSlidingCir_DWork_real_T_0 = 0;
volatile int8_T *p_positionControlSlidingCir_DWork_int8_T_2 = 0;
