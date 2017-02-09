  /*********************** dSPACE target specific file *************************

   Header file positionControlLoopCircle_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1103 6.5 (10-May-2010)
   Tue Jan 24 00:13:25 2017

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_positionControlLoopCircle_trc_ptr_h_
  #define RTI_HEADER_positionControlLoopCircle_trc_ptr_h_
  /* Include the model header file. */
  #include "positionControlLoopCircle.h"
  #include "positionControlLoopCircle_private.h"

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
              EXTERN_C volatile  real_T *p_positionControlLoopCircle_B_real_T_0;
              EXTERN_C volatile  boolean_T *p_positionControlLoopCircle_B_boolean_T_1;
              EXTERN_C volatile  real_T *p_positionControlLoopCircle_P_real_T_0;
              EXTERN_C volatile  real_T *p_positionControlLoopCircle_DWork_real_T_0;
              EXTERN_C volatile  int8_T *p_positionControlLoopCircle_DWork_int8_T_2;

   #define RTI_INIT_TRC_POINTERS() \
              p_positionControlLoopCircle_B_real_T_0 = &positionControlLoopCircle_B.Product3;\
              p_positionControlLoopCircle_B_boolean_T_1 = &positionControlLoopCircle_B.LogicalOperator1;\
              p_positionControlLoopCircle_P_real_T_0 = &positionControlLoopCircle_P.startX_Value;\
              p_positionControlLoopCircle_DWork_real_T_0 = &positionControlLoopCircle_DWork.DiscreteTimeIntegrator_DSTATE;\
              p_positionControlLoopCircle_DWork_int8_T_2 = &positionControlLoopCircle_DWork.DiscreteTimeIntegrator_PrevRese;\

   #endif                       /* RTI_HEADER_positionControlLoopCircle_trc_ptr_h_ */
