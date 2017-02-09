/*
 * positionControlLoopCircle.h
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
#ifndef RTW_HEADER_positionControlLoopCircle_h_
#define RTW_HEADER_positionControlLoopCircle_h_
#ifndef positionControlLoopCircle_COMMON_INCLUDES_
# define positionControlLoopCircle_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_SATURATE.h"
#include "rt_atan2_snf.h"
#include "rt_pow_snf.h"
#endif                                 /* positionControlLoopCircle_COMMON_INCLUDES_ */

#include "positionControlLoopCircle_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ()
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define positionControlLoopCircle_rtModel RT_MODEL_positionControlLoopCir

/* Block signals (auto storage) */
typedef struct {
  real_T Product3;                     /* '<Root>/Product3' */
  real_T DiscreteTimeIntegrator;       /* '<Root>/Discrete-Time Integrator' */
  real_T index;                        /* '<Root>/index' */
  real_T circY;                        /* '<Root>/circY' */
  real_T Product5;                     /* '<Root>/Product5' */
  real_T ypos;                         /* '<Root>/ypos' */
  real_T SFunction1;                   /* '<S17>/S-Function1' */
  real_T SFunction2;                   /* '<S17>/S-Function2' */
  real_T EncoderGain[2];               /* '<S2>/EncoderGain' */
  real_T yerror;                       /* '<Root>/yerror' */
  real_T TappedDelay;                  /* '<S23>/Tapped Delay' */
  real_T Add3;                         /* '<S8>/Add3' */
  real_T circX;                        /* '<Root>/circX' */
  real_T Product4;                     /* '<Root>/Product4' */
  real_T Product2;                     /* '<Root>/Product2' */
  real_T xpos;                         /* '<Root>/xpos' */
  real_T Add1;                         /* '<S8>/Add1' */
  real_T TrigonometricFunction;        /* '<S8>/Trigonometric Function' */
  real_T TrigonometricFunction2;       /* '<S8>/Trigonometric Function2' */
  real_T TrigonometricFunction1;       /* '<S8>/Trigonometric Function1' */
  real_T Fcn1;                         /* '<S8>/Fcn1' */
  real_T Abs1;                         /* '<S8>/Abs1' */
  real_T Drterm2;                      /* '<S10>/Drterm2' */
  real_T Dot1;                         /* '<S23>/Dot1' */
  real_T Sum;                          /* '<S23>/Sum' */
  real_T Downcast1;                    /* '<S23>/Downcast1' */
  real_T TmpSignalConversionAtDot2Inport[2];/* '<S23>/Mux' */
  real_T Nrterm1;                      /* '<S10>/Nrterm1' */
  real_T Nrterm2;                      /* '<S10>/Nrterm2' */
  real_T TmpSignalConversionAtDot2Inpo_i[2];/* '<S23>/Num' */
  real_T Dot2;                         /* '<S23>/Dot2' */
  real_T Downcast;                     /* '<S23>/Downcast' */
  real_T Fcn;                          /* '<S8>/Fcn' */
  real_T Abs;                          /* '<S8>/Abs' */
  real_T Fcn1_l;                       /* '<Root>/Fcn1' */
  real_T SFunction1_b;                 /* '<S15>/S-Function1' */
  real_T SFunction2_l;                 /* '<S15>/S-Function2' */
  real_T SFunction1_f;                 /* '<S13>/S-Function1' */
  real_T SFunction2_h;                 /* '<S13>/S-Function2' */
  real_T Add[2];                       /* '<S1>/Add' */
  real_T EncoderGain_j[2];             /* '<S1>/EncoderGain' */
  real_T convert2radians[2];           /* '<S1>/convert2radians ' */
  real_T xerror;                       /* '<Root>/xerror' */
  real_T TappedDelay_d;                /* '<S22>/Tapped Delay' */
  real_T Drterm2_k;                    /* '<S9>/Drterm2' */
  real_T Dot1_d;                       /* '<S22>/Dot1' */
  real_T Sum_h;                        /* '<S22>/Sum' */
  real_T Downcast1_b;                  /* '<S22>/Downcast1' */
  real_T TmpSignalConversionAtDot2Inpo_j[2];/* '<S22>/Mux' */
  real_T Nrterm1_a;                    /* '<S9>/Nrterm1' */
  real_T Nrterm2_b;                    /* '<S9>/Nrterm2' */
  real_T TmpSignalConversionAtDot2Inpo_c[2];/* '<S22>/Num' */
  real_T Dot2_k;                       /* '<S22>/Dot2' */
  real_T Downcast_p;                   /* '<S22>/Downcast' */
  real_T Fcn_c;                        /* '<Root>/Fcn' */
  real_T Product1;                     /* '<Root>/Product1' */
  real_T DAGainY1;                     /* '<Root>/DA GainY1' */
  real_T Product;                      /* '<Root>/Product' */
  real_T DAGainY;                      /* '<Root>/DA GainY' */
  real_T Fcn2;                         /* '<S8>/Fcn2' */
  real_T currentNegated;               /* '<Root>/currentNegated' */
  real_T differentiated;               /* '<Root>/differentiated' */
  real_T differentiated1;              /* '<Root>/differentiated1' */
  real_T SFunction;                    /* '<S3>/S-Function' */
  real_T ADCGain;                      /* '<Root>/ADC Gain' */
  real_T GainFx;                       /* '<Root>/GainFx' */
  real_T SFunction_a;                  /* '<S4>/S-Function' */
  real_T ADCGain1;                     /* '<Root>/ADC Gain1' */
  real_T GainFy;                       /* '<Root>/GainFy' */
  real_T SFunction_b;                  /* '<S5>/S-Function' */
  real_T ADCGain2;                     /* '<Root>/ADC Gain2' */
  real_T GainFz;                       /* '<Root>/GainFz' */
  boolean_T LogicalOperator1;          /* '<Root>/Logical Operator1' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
} BlockIO_positionControlLoopCirc;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T TappedDelay_X;                /* '<S23>/Tapped Delay' */
  real_T TappedDelay_X_l;              /* '<S22>/Tapped Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_h;                     /* '<S8>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_c;                    /* '<S8>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_o;                    /* '<S8>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_b;                    /* '<S8>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_k;                    /* '<S8>/Scope4' */

  int8_T DiscreteTimeIntegrator_PrevRese;/* '<Root>/Discrete-Time Integrator' */
} D_Work_positionControlLoopCircl;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState DS1103ENC_SET_POS_C3_Trig_ZCE;/* '<S2>/DS1103ENC_SET_POS_C3' */
  ZCSigState _DS1103ENC_SET_POS_C1_Trig_ZCE;/* '<S1>/_DS1103ENC_SET_POS_C1' */
  ZCSigState DS1103ENC_SET_POS_C2_Trig_ZCE;/* '<S1>/DS1103ENC_SET_POS_C2' */
} PrevZCSigStates_positionControl;

/* Backward compatible GRT Identifiers */
#define rtB                            positionControlLoopCircle_B
#define BlockIO                        BlockIO_positionControlLoopCirc
#define rtXdot                         positionControlLoopCircle_Xdot
#define StateDerivatives               StateDerivatives_positionContro
#define tXdis                          positionControlLoopCircle_Xdis
#define StateDisabled                  StateDisabled_positionControlLo
#define rtP                            positionControlLoopCircle_P
#define Parameters                     Parameters_positionControlLoopC
#define rtDWork                        positionControlLoopCircle_DWork
#define D_Work                         D_Work_positionControlLoopCircl
#define rtPrevZCSigState               positionControlL_PrevZCSigState
#define PrevZCSigStates                PrevZCSigStates_positionControl

/* Parameters (auto storage) */
struct Parameters_positionControlLoopC_ {
  real_T startX_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/startX'
                                        */
  real_T input_Value;                  /* Expression: circY(2)
                                        * Referenced by: '<Root>/input'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<Root>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T index_Gain;                   /* Expression: 1/Ts
                                        * Referenced by: '<Root>/index'
                                        */
  real_T circY_table[2514];            /* Expression: circY
                                        * Referenced by: '<Root>/circY'
                                        */
  real_T EncoderGain_Gain;             /* Expression: 4/5614
                                        * Referenced by: '<S2>/EncoderGain'
                                        */
  real_T TappedDelay_InitialCondition; /* Expression: vinit
                                        * Referenced by: '<S23>/Tapped Delay'
                                        */
  real_T J_Value;                      /* Expression: Jy
                                        * Referenced by: '<Root>/J'
                                        */
  real_T B_Value;                      /* Expression: By
                                        * Referenced by: '<Root>/B'
                                        */
  real_T centerx1_Value;               /* Expression: 2*pi*15
                                        * Referenced by: '<Root>/centerx1'
                                        */
  real_T pi45_Value;                   /* Expression: 2*pi*20
                                        * Referenced by: '<Root>/2pi45'
                                        */
  real_T centery_Value;                /* Expression: center(2)
                                        * Referenced by: '<Root>/centery'
                                        */
  real_T circX_table[2514];            /* Expression: circX
                                        * Referenced by: '<Root>/circX'
                                        */
  real_T input2_Value;                 /* Expression: circX(2)
                                        * Referenced by: '<Root>/input2'
                                        */
  real_T centerx_Value;                /* Expression: center(1)
                                        * Referenced by: '<Root>/centerx'
                                        */
  real_T zeta2_Value;                  /* Expression: zeta
                                        * Referenced by: '<Root>/zeta2'
                                        */
  real_T EncoderGain_Gain_o;           /* Expression: 4/5614
                                        * Referenced by: '<S1>/EncoderGain'
                                        */
  real_T convert2radians_Gain;         /* Expression: .5
                                        * Referenced by: '<S1>/convert2radians '
                                        */
  real_T TappedDelay_InitialCondition_j;/* Expression: vinit
                                         * Referenced by: '<S22>/Tapped Delay'
                                         */
  real_T J1_Value;                     /* Expression: Jx
                                        * Referenced by: '<Root>/J1'
                                        */
  real_T B1_Value;                     /* Expression: Bx
                                        * Referenced by: '<Root>/B1'
                                        */
  real_T zeta1_Value;                  /* Expression: zeta
                                        * Referenced by: '<Root>/zeta1'
                                        */
  real_T DAOnOff_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/DA On-Off'
                                        */
  real_T DAGainY1_Gain;                /* Expression: 0.1
                                        * Referenced by: '<Root>/DA GainY1'
                                        */
  real_T DAGainY_Gain;                 /* Expression: 0.1
                                        * Referenced by: '<Root>/DA GainY'
                                        */
  real_T ENCReset_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/ENC Reset'
                                        */
  real_T currentNegated_Gain;          /* Expression: -1
                                        * Referenced by: '<Root>/currentNegated'
                                        */
  real_T differentiated_Gain;          /* Expression: 1/Ts
                                        * Referenced by: '<Root>/differentiated'
                                        */
  real_T differentiated1_Gain;         /* Expression: 1/Ts
                                        * Referenced by: '<Root>/differentiated1'
                                        */
  real_T ADCGain_Gain;                 /* Expression: 10
                                        * Referenced by: '<Root>/ADC Gain'
                                        */
  real_T GainFx_Gain;                  /* Expression: 10
                                        * Referenced by: '<Root>/GainFx'
                                        */
  real_T ADCGain1_Gain;                /* Expression: 10
                                        * Referenced by: '<Root>/ADC Gain1'
                                        */
  real_T GainFy_Gain;                  /* Expression: 100
                                        * Referenced by: '<Root>/GainFy'
                                        */
  real_T ADCGain2_Gain;                /* Expression: 10
                                        * Referenced by: '<Root>/ADC Gain2'
                                        */
  real_T GainFz_Gain;                  /* Expression: 10
                                        * Referenced by: '<Root>/GainFz'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_positionControlLoopCir {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_positionControlLoopC positionControlLoopCircle_P;

/* Block signals (auto storage) */
extern BlockIO_positionControlLoopCirc positionControlLoopCircle_B;

/* Block states (auto storage) */
extern D_Work_positionControlLoopCircl positionControlLoopCircle_DWork;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_positionControl positionControlL_PrevZCSigState;

/* Real-time Model object */
extern struct RT_MODEL_positionControlLoopCir *positionControlLoopCircle_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : positionControlLoopCircle
 * '<S1>'   : positionControlLoopCircle/ EncoderX
 * '<S2>'   : positionControlLoopCircle/ EncoderY
 * '<S3>'   : positionControlLoopCircle/DS1103ADC_C17
 * '<S4>'   : positionControlLoopCircle/DS1103ADC_C18
 * '<S5>'   : positionControlLoopCircle/DS1103ADC_C19
 * '<S6>'   : positionControlLoopCircle/DS1103ENC_SETUP
 * '<S7>'   : positionControlLoopCircle/RTI Data
 * '<S8>'   : positionControlLoopCircle/Subsystem
 * '<S9>'   : positionControlLoopCircle/Subsystem1
 * '<S10>'  : positionControlLoopCircle/Subsystem2
 * '<S11>'  : positionControlLoopCircle/controlX
 * '<S12>'  : positionControlLoopCircle/controlY
 * '<S13>'  : positionControlLoopCircle/ EncoderX/DS1103ENC_POS_C2
 * '<S14>'  : positionControlLoopCircle/ EncoderX/DS1103ENC_SET_POS_C2
 * '<S15>'  : positionControlLoopCircle/ EncoderX/_DS1103ENC_POS_C1
 * '<S16>'  : positionControlLoopCircle/ EncoderX/_DS1103ENC_SET_POS_C1
 * '<S17>'  : positionControlLoopCircle/ EncoderY/DS1103ENC_POS_C3
 * '<S18>'  : positionControlLoopCircle/ EncoderY/DS1103ENC_SET_POS_C3
 * '<S19>'  : positionControlLoopCircle/RTI Data/RTI Data Store
 * '<S20>'  : positionControlLoopCircle/RTI Data/RTI Data Store/RTI Data Store
 * '<S21>'  : positionControlLoopCircle/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store
 * '<S22>'  : positionControlLoopCircle/Subsystem1/Transfer Fcn Direct Form II Time Varying
 * '<S23>'  : positionControlLoopCircle/Subsystem2/Transfer Fcn Direct Form II Time Varying
 */
#endif                                 /* RTW_HEADER_positionControlLoopCircle_h_ */
