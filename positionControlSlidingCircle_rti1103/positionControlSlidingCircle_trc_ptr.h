  /*********************** dSPACE target specific file *************************

   Header file positionControlSlidingCircle_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Wed May 03 16:45:45 2017

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_positionControlSlidingCircle_trc_ptr_h_
  #define RTI_HEADER_positionControlSlidingCircle_trc_ptr_h_
  /* Include the model header file. */
  #include "positionControlSlidingCircle.h"
  #include "positionControlSlidingCircle_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_positionControlSlidingCircle_B_real_T_0;
              EXTERN_C volatile  boolean_T *p_positionControlSlidingCircle_B_boolean_T_1;
              EXTERN_C volatile  real_T *p_positionControlSlidingCircle_P_real_T_0;
              EXTERN_C volatile  real_T *p_positionControlSlidingCir_DWork_real_T_0;
              EXTERN_C volatile  int8_T *p_positionControlSlidingCir_DWork_int8_T_2;

   #define RTI_INIT_TRC_POINTERS() \
              p_positionControlSlidingCircle_B_real_T_0 = &positionControlSlidingCircle_B.Product3;\
              p_positionControlSlidingCircle_B_boolean_T_1 = &positionControlSlidingCircle_B.LogicalOperator1;\
              p_positionControlSlidingCircle_P_real_T_0 = &positionControlSlidingCircle_P.DAOnOff_Value;\
              p_positionControlSlidingCir_DWork_real_T_0 = &positionControlSlidingCir_DWork.DiscreteTimeIntegrator_DSTATE;\
              p_positionControlSlidingCir_DWork_int8_T_2 = &positionControlSlidingCir_DWork.DiscreteTimeIntegrator_PrevRese;\

   #endif                       /* RTI_HEADER_positionControlSlidingCircle_trc_ptr_h_ */
