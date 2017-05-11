/*
 * positionControlSlidingCircle.h
 *
 * Real-Time Workshop code generation for Simulink model "positionControlSlidingCircle.mdl".
 *
 * Model version              : 1.173
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Wed May 10 16:26:30 2017
 *
 * Target selection: rti1103.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_positionControlSlidingCircle_h_
#define RTW_HEADER_positionControlSlidingCircle_h_
#ifndef positionControlSlidingCircle_COMMON_INCLUDES_
# define positionControlSlidingCircle_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dspsvd_rt.h"
#include "rt_zcfcn.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_SATURATE.h"
#include "rt_atan2_snf.h"
#include "rt_pow_snf.h"
#include "rt_MAX.h"
#include "rt_MIN.h"
#endif                                 /* positionControlSlidingCircle_COMMON_INCLUDES_ */

#include "positionControlSlidingCircle_types.h"

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
#define positionControlSlidingCircle_rtModel RT_MODEL_positionControlSliding

/* Block signals (auto storage) */
typedef struct {
  real_T Product3;                     /* '<Root>/Product3' */
  real_T DiscreteTimeIntegrator;       /* '<Root>/Discrete-Time Integrator' */
  real_T index;                        /* '<Root>/index' */
  real_T circX1;                       /* '<Root>/circX1' */
  real_T Product5;                     /* '<Root>/Product5' */
  real_T xr;                           /* '<Root>/xposr' */
  real_T Product2;                     /* '<Root>/Product2' */
  real_T circY;                        /* '<Root>/circY' */
  real_T Product4;                     /* '<Root>/Product4' */
  real_T yr;                           /* '<Root>/yposr' */
  real_T theta;                        /* '<S10>/theta' */
  real_T MatrixConcatenate1[2];        /* '<S14>/Matrix Concatenate1' */
  real_T MatrixConcatenate4[2];        /* '<S14>/Matrix Concatenate4' */
  real_T coeffmat2X1[4];               /* '<S14>/coeffmat2X1' */
  real_T xrefForce;                    /* '<S12>/xrefForce' */
  real_T SFunction1;                   /* '<S21>/S-Function1' */
  real_T SFunction2;                   /* '<S21>/S-Function2' */
  real_T SFunction1_c;                 /* '<S19>/S-Function1' */
  real_T SFunction2_h;                 /* '<S19>/S-Function2' */
  real_T Add[2];                       /* '<S1>/Add' */
  real_T EncoderGain[2];               /* '<S1>/EncoderGain' */
  real_T convert2radians[2];           /* '<S1>/convert2radians ' */
  real_T yrefForce;                    /* '<S12>/yrefForce' */
  real_T SFunction1_c2;                /* '<S23>/S-Function1' */
  real_T SFunction2_l;                 /* '<S23>/S-Function2' */
  real_T EncoderGain_o[2];             /* '<S2>/EncoderGain' */
  real_T VectorConcatenate[2];         /* '<S13>/Vector Concatenate' */
  real_T VectorConcatenate1[2];        /* '<S13>/Vector Concatenate1' */
  real_T DotProduct;                   /* '<S13>/Dot Product' */
  real_T VectorConcatenate_h[2];       /* '<S15>/Vector Concatenate' */
  real_T Kpepsilond1[2];               /* '<Root>/Kp epsilond1' */
  real_T gainAddX;                     /* '<Root>/gainAddX' */
  real_T filterux4;                    /* '<Root>/filterux4' */
  real_T xd;                           /* '<Root>/differentiated1' */
  real_T filterux2;                    /* '<Root>/filterux2' */
  real_T yd;                           /* '<Root>/differentiated' */
  real_T filterux3;                    /* '<Root>/filterux3' */
  real_T circXd1;                      /* '<Root>/circXd1' */
  real_T xrd;                          /* '<Root>/Product8' */
  real_T circYd;                       /* '<Root>/circYd' */
  real_T yrd;                          /* '<Root>/Product6' */
  real_T circXdd1;                     /* '<Root>/circXdd1' */
  real_T xrdd;                         /* '<Root>/Product9' */
  real_T circYdd;                      /* '<Root>/circYdd' */
  real_T yrdd;                         /* '<Root>/Product7' */
  real_T MatrixConcatenate2[2];        /* '<S16>/Matrix Concatenate2' */
  real_T MatrixConcatenate3[2];        /* '<S16>/Matrix Concatenate3' */
  real_T coeffmat2X2[4];               /* '<S16>/coeffmat2X2' */
  real_T Pseudoinverse[4];             /* '<S16>/Pseudoinverse' */
  real_T MatrixConcatenate4_e[4];      /* '<S11>/Matrix Concatenate4' */
  real_T MinvKs[4];                    /* '<Root>/-Minv Ks' */
  real_T MatrixConcatenate4_o[4];      /* '<S8>/Matrix Concatenate4' */
  real_T epsilon2X1[2];                /* '<S16>/epsilon2X1' */
  real_T Kpepsilon[2];                 /* '<S16>/Kp epsilon' */
  real_T MatrixConcatenate4_b[4];      /* '<S9>/Matrix Concatenate4' */
  real_T epsilond2X1[2];               /* '<S16>/epsilond2X1' */
  real_T Kdepsilond[2];                /* '<S16>/Kd epsilond' */
  real_T Add_h[2];                     /* '<S16>/Add' */
  real_T MinvKsKpepsilonKdepsilond[2]; /* '<S16>/-Minv Ks (Kp epsilon+Kd epsilond)' */
  real_T Kpepsilond[2];                /* '<S16>/Kp epsilond' */
  real_T Add1[2];                      /* '<S16>/Add1' */
  real_T MathFunction[2];              /* '<S28>/Math Function' */
  real_T LUFactorization_o1[4];        /* '<S31>/LU Factorization' */
  real_T LUFactorization_o2[2];        /* '<S31>/LU Factorization' */
  real_T IdentityMatrix[4];            /* '<S30>/Identity Matrix' */
  real_T PermuteMatrix[4];             /* '<S31>/Permute Matrix' */
  real_T y[4];                         /* '<S31>/Forward Substitution' */
  real_T BackwardSubstitution[4];      /* '<S31>/Backward Substitution' */
  real_T matrixmult[2];                /* '<S16>/matrix mult' */
  real_T rem2X1[2];                    /* '<S16>/rem2X1' */
  real_T Add2[2];                      /* '<S16>/Add2' */
  real_T MathFunction_g[2];            /* '<S29>/Math Function' */
  real_T matrixmult1[2];               /* '<S16>/matrix mult1' */
  real_T uxorig;                       /* '<Root>/uxorig' */
  real_T Add_h2;                       /* '<Root>/Add' */
  real_T uxact;                        /* '<Root>/uxact' */
  real_T DAGainY;                      /* '<Root>/DA GainY' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T filterux;                     /* '<Root>/filterux' */
  real_T uyorig;                       /* '<Root>/uyorig' */
  real_T Add1_o;                       /* '<Root>/Add1' */
  real_T uyact;                        /* '<Root>/uyact' */
  real_T DAGainY1;                     /* '<Root>/DA GainY1' */
  real_T Saturation1;                  /* '<Root>/Saturation1' */
  real_T filterux1;                    /* '<Root>/filterux1' */
  real_T gainAddY;                     /* '<Root>/gainAddY' */
  real_T filterux5;                    /* '<Root>/filterux5' */
  real_T Fcn;                          /* '<Root>/Fcn' */
  real_T Fcn1;                         /* '<Root>/Fcn1' */
  real_T currentNegated;               /* '<Root>/currentNegated' */
  real_T utotal;                       /* '<Root>/utotal' */
  real_T utotalorig;                   /* '<Root>/utotalorig' */
  real_T SFunction;                    /* '<S3>/S-Function' */
  real_T ADCGain;                      /* '<Root>/ADC Gain' */
  real_T SFunction_g;                  /* '<S4>/S-Function' */
  real_T ADCGain1;                     /* '<Root>/ADC Gain1' */
  real_T SFunction_m;                  /* '<S5>/S-Function' */
  real_T ADCGain2;                     /* '<Root>/ADC Gain2' */
  real_T GainFx;                       /* '<Root>/GainFx' */
  real_T GainFy;                       /* '<Root>/GainFy' */
  real_T GainFz;                       /* '<Root>/GainFz' */
  real_T ForceMag;                     /* '<Root>/ForceMag' */
  real_T Kd11;                         /* '<Root>/Kd1,1' */
  boolean_T LogicalOperator1;          /* '<Root>/Logical Operator1' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
} BlockIO_positionControlSlidingC;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T filterux4_DSTATE;             /* '<Root>/filterux4' */
  real_T filterux2_DSTATE;             /* '<Root>/filterux2' */
  real_T filterux3_DSTATE;             /* '<Root>/filterux3' */
  real_T filterux_DSTATE;              /* '<Root>/filterux' */
  real_T filterux1_DSTATE;             /* '<Root>/filterux1' */
  real_T filterux5_DSTATE;             /* '<Root>/filterux5' */
  real_T filterux4_tmp;                /* '<Root>/filterux4' */
  real_T filterux2_tmp;                /* '<Root>/filterux2' */
  real_T filterux3_tmp;                /* '<Root>/filterux3' */
  real_T Pseudoinverse_X[4];           /* '<S16>/Pseudoinverse' */
  real_T Pseudoinverse_E[2];           /* '<S16>/Pseudoinverse' */
  real_T Pseudoinverse_WORK[2];        /* '<S16>/Pseudoinverse' */
  real_T Pseudoinverse_S[2];           /* '<S16>/Pseudoinverse' */
  real_T Pseudoinverse_U[4];           /* '<S16>/Pseudoinverse' */
  real_T Pseudoinverse_V[4];           /* '<S16>/Pseudoinverse' */
  real_T filterux_tmp;                 /* '<Root>/filterux' */
  real_T filterux1_tmp;                /* '<Root>/filterux1' */
  real_T filterux5_tmp;                /* '<Root>/filterux5' */
  struct {
    void *LoggedData;
  } thetaScope_PWORK;                  /* '<S10>/thetaScope' */

  int8_T DiscreteTimeIntegrator_PrevRese;/* '<Root>/Discrete-Time Integrator' */
} D_Work_positionControlSlidingCi;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState DS1103ENC_SET_POS_C3_Trig_ZCE;/* '<S2>/DS1103ENC_SET_POS_C3' */
  ZCSigState _DS1103ENC_SET_POS_C1_Trig_ZCE;/* '<S1>/_DS1103ENC_SET_POS_C1' */
  ZCSigState DS1103ENC_SET_POS_C2_Trig_ZCE;/* '<S1>/DS1103ENC_SET_POS_C2' */
} PrevZCSigStates_positionControl;

/* Backward compatible GRT Identifiers */
#define rtB                            positionControlSlidingCircle_B
#define BlockIO                        BlockIO_positionControlSlidingC
#define rtXdot                         positionControlSlidingCirc_Xdot
#define StateDerivatives               StateDerivatives_positionContro
#define tXdis                          positionControlSlidingCirc_Xdis
#define StateDisabled                  StateDisabled_positionControlSl
#define rtP                            positionControlSlidingCircle_P
#define Parameters                     Parameters_positionControlSlidi
#define rtDWork                        positionControlSlidingCir_DWork
#define D_Work                         D_Work_positionControlSlidingCi
#define rtPrevZCSigState               positionControlS_PrevZCSigState
#define PrevZCSigStates                PrevZCSigStates_positionControl

/* Parameters (auto storage) */
struct Parameters_positionControlSlidi_ {
  real_T DAOnOff_Value;                /* Expression: 0
                                        * Referenced by: '<Root>/DA On-Off'
                                        */
  real_T xc_Value;                     /* Expression: xc
                                        * Referenced by: '<Root>/xc'
                                        */
  real_T yc_Value;                     /* Expression: yc
                                        * Referenced by: '<Root>/yc'
                                        */
  real_T startX_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/startX'
                                        */
  real_T input_Value;                  /* Expression: circX(1)
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
  real_T circX1_table[7236];           /* Expression: circX
                                        * Referenced by: '<Root>/circX1'
                                        */
  real_T input2_Value;                 /* Expression: circY(1)
                                        * Referenced by: '<Root>/input2'
                                        */
  real_T circY_table[7236];            /* Expression: circY
                                        * Referenced by: '<Root>/circY'
                                        */
  real_T zero_Value;                   /* Expression: 0
                                        * Referenced by: '<S15>/zero'
                                        */
  real_T knorm_Value;                  /* Expression: kNorm
                                        * Referenced by: '<Root>/knorm'
                                        */
  real_T rNormal_Value;                /* Expression: rNormal
                                        * Referenced by: '<Root>/rNormal'
                                        */
  real_T EncoderGain_Gain;             /* Expression: 4/5614
                                        * Referenced by: '<S1>/EncoderGain'
                                        */
  real_T convert2radians_Gain;         /* Expression: .5
                                        * Referenced by: '<S1>/convert2radians '
                                        */
  real_T EncoderGain_Gain_f;           /* Expression: 4/5614
                                        * Referenced by: '<S2>/EncoderGain'
                                        */
  real_T gainAddX_Gain;                /* Expression: 1
                                        * Referenced by: '<Root>/gainAddX'
                                        */
  real_T filterux4_InitialStates;      /* Expression: 0
                                        * Referenced by: '<Root>/filterux4'
                                        */
  real_T filterux4_Numerator;          /* Expression: [1-bLP]
                                        * Referenced by: '<Root>/filterux4'
                                        */
  real_T filterux4_Denominator[2];     /* Expression: [1 -bLP]
                                        * Referenced by: '<Root>/filterux4'
                                        */
  real_T differentiated1_Gain;         /* Expression: 1/Ts
                                        * Referenced by: '<Root>/differentiated1'
                                        */
  real_T filterux2_InitialStates;      /* Expression: 0
                                        * Referenced by: '<Root>/filterux2'
                                        */
  real_T filterux2_Numerator;          /* Expression: [1-bLP]
                                        * Referenced by: '<Root>/filterux2'
                                        */
  real_T filterux2_Denominator[2];     /* Expression: [1 -bLP]
                                        * Referenced by: '<Root>/filterux2'
                                        */
  real_T differentiated_Gain;          /* Expression: 1/Ts
                                        * Referenced by: '<Root>/differentiated'
                                        */
  real_T filterux3_InitialStates;      /* Expression: 0
                                        * Referenced by: '<Root>/filterux3'
                                        */
  real_T filterux3_Numerator;          /* Expression: [1-bLP]
                                        * Referenced by: '<Root>/filterux3'
                                        */
  real_T filterux3_Denominator[2];     /* Expression: [1 -bLP]
                                        * Referenced by: '<Root>/filterux3'
                                        */
  real_T circXd1_table[7236];          /* Expression: circXd
                                        * Referenced by: '<Root>/circXd1'
                                        */
  real_T circYd_table[7236];           /* Expression: circYd
                                        * Referenced by: '<Root>/circYd'
                                        */
  real_T circXdd1_table[7236];         /* Expression: circXdd
                                        * Referenced by: '<Root>/circXdd1'
                                        */
  real_T circYdd_table[7236];          /* Expression: circYdd
                                        * Referenced by: '<Root>/circYdd'
                                        */
  real_T r0_Value;                     /* Expression: r0
                                        * Referenced by: '<Root>/r0'
                                        */
  real_T cx_Value;                     /* Expression: cx
                                        * Referenced by: '<S10>/cx'
                                        */
  real_T cy_Value;                     /* Expression: cy
                                        * Referenced by: '<S10>/cy'
                                        */
  real_T mx_Value;                     /* Expression: mx
                                        * Referenced by: '<S10>/mx'
                                        */
  real_T my_Value;                     /* Expression: my
                                        * Referenced by: '<S10>/my'
                                        */
  real_T Minv_Value[4];                /* Expression: -Minv
                                        * Referenced by: '<Root>/-Minv'
                                        */
  real_T Ks11_Value;                   /* Expression: Ks(1,1)
                                        * Referenced by: '<Root>/Ks1,1'
                                        */
  real_T Ks12_Value;                   /* Expression: Ks(2,1)
                                        * Referenced by: '<Root>/Ks1,2'
                                        */
  real_T Ks21_Value;                   /* Expression: Ks(1,2)
                                        * Referenced by: '<Root>/Ks2,1'
                                        */
  real_T Ks22_Value;                   /* Expression: Ks(2,2)
                                        * Referenced by: '<Root>/Ks 2,2'
                                        */
  real_T Kp11_Value;                   /* Expression: Kp(1,1)
                                        * Referenced by: '<Root>/Kp1,1'
                                        */
  real_T Kp21_Value;                   /* Expression: Kp(2,1)
                                        * Referenced by: '<Root>/Kp2,1'
                                        */
  real_T Kp12_Value;                   /* Expression: Kp(1,2)
                                        * Referenced by: '<Root>/Kp1,2'
                                        */
  real_T Kp22_Value;                   /* Expression: Kp(2,2)
                                        * Referenced by: '<Root>/Kp2,2'
                                        */
  real_T Kd13_Value;                   /* Expression: Kd(1,1)
                                        * Referenced by: '<Root>/Kd1,3'
                                        */
  real_T Kd23_Value;                   /* Expression: Kd(2,1)
                                        * Referenced by: '<Root>/Kd2,3'
                                        */
  real_T Kd14_Value;                   /* Expression: Kd(1,2)
                                        * Referenced by: '<Root>/Kd1,4'
                                        */
  real_T Kd24_Value;                   /* Expression: Kd(2,2)
                                        * Referenced by: '<Root>/Kd2,4'
                                        */
  real_T uxorig_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/uxorig'
                                        */
  real_T DAGainY_Gain;                 /* Expression: 0.1
                                        * Referenced by: '<Root>/DA GainY'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 7
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -7
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T filterux_InitialStates;       /* Expression: 0
                                        * Referenced by: '<Root>/filterux'
                                        */
  real_T filterux_Numerator;           /* Expression: [1-bLP]
                                        * Referenced by: '<Root>/filterux'
                                        */
  real_T filterux_Denominator[2];      /* Expression: [1 -bLP]
                                        * Referenced by: '<Root>/filterux'
                                        */
  real_T uyorig_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/uyorig'
                                        */
  real_T DAGainY1_Gain;                /* Expression: 0.1
                                        * Referenced by: '<Root>/DA GainY1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 7
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -7
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T filterux1_InitialStates;      /* Expression: 0
                                        * Referenced by: '<Root>/filterux1'
                                        */
  real_T filterux1_Numerator;          /* Expression: [1-bLP]
                                        * Referenced by: '<Root>/filterux1'
                                        */
  real_T filterux1_Denominator[2];     /* Expression: [1 -bLP]
                                        * Referenced by: '<Root>/filterux1'
                                        */
  real_T ENCReset_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/ENC Reset'
                                        */
  real_T gainAddY_Gain;                /* Expression: 1
                                        * Referenced by: '<Root>/gainAddY'
                                        */
  real_T filterux5_InitialStates;      /* Expression: 0
                                        * Referenced by: '<Root>/filterux5'
                                        */
  real_T filterux5_Numerator;          /* Expression: [1-bLP]
                                        * Referenced by: '<Root>/filterux5'
                                        */
  real_T filterux5_Denominator[2];     /* Expression: [1 -bLP]
                                        * Referenced by: '<Root>/filterux5'
                                        */
  real_T currentNegated_Gain;          /* Expression: -1
                                        * Referenced by: '<Root>/currentNegated'
                                        */
  real_T utotal_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/utotal'
                                        */
  real_T utotalorig_Gain;              /* Expression: 1
                                        * Referenced by: '<Root>/utotalorig'
                                        */
  real_T ADCGain_Gain;                 /* Expression: 10
                                        * Referenced by: '<Root>/ADC Gain'
                                        */
  real_T ADCGain1_Gain;                /* Expression: 10
                                        * Referenced by: '<Root>/ADC Gain1'
                                        */
  real_T ADCGain2_Gain;                /* Expression: 10
                                        * Referenced by: '<Root>/ADC Gain2'
                                        */
  real_T GainFx_Gain;                  /* Expression: 10
                                        * Referenced by: '<Root>/GainFx'
                                        */
  real_T GainFy_Gain;                  /* Expression: 100
                                        * Referenced by: '<Root>/GainFy'
                                        */
  real_T GainFz_Gain;                  /* Expression: 10
                                        * Referenced by: '<Root>/GainFz'
                                        */
  real_T Kd11_Value;                   /* Expression: Kd(1,1)
                                        * Referenced by: '<Root>/Kd1,1'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_positionControlSliding {
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
extern Parameters_positionControlSlidi positionControlSlidingCircle_P;

/* Block signals (auto storage) */
extern BlockIO_positionControlSlidingC positionControlSlidingCircle_B;

/* Block states (auto storage) */
extern D_Work_positionControlSlidingCi positionControlSlidingCir_DWork;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_positionControl positionControlS_PrevZCSigState;

/* Real-time Model object */
extern struct RT_MODEL_positionControlSliding *positionControlSlidingCircle_M;

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
 * '<Root>' : positionControlSlidingCircle
 * '<S1>'   : positionControlSlidingCircle/ EncoderX
 * '<S2>'   : positionControlSlidingCircle/ EncoderY
 * '<S3>'   : positionControlSlidingCircle/DS1103ADC_C17
 * '<S4>'   : positionControlSlidingCircle/DS1103ADC_C18
 * '<S5>'   : positionControlSlidingCircle/DS1103ADC_C19
 * '<S6>'   : positionControlSlidingCircle/DS1103ENC_SETUP
 * '<S7>'   : positionControlSlidingCircle/RTI Data
 * '<S8>'   : positionControlSlidingCircle/Subsystem
 * '<S9>'   : positionControlSlidingCircle/Subsystem1
 * '<S10>'  : positionControlSlidingCircle/Subsystem2
 * '<S11>'  : positionControlSlidingCircle/Subsystem3
 * '<S12>'  : positionControlSlidingCircle/Subsystem4
 * '<S13>'  : positionControlSlidingCircle/Subsystem5
 * '<S14>'  : positionControlSlidingCircle/Subsystem6
 * '<S15>'  : positionControlSlidingCircle/Subsystem7
 * '<S16>'  : positionControlSlidingCircle/Subsystem8
 * '<S17>'  : positionControlSlidingCircle/controlX
 * '<S18>'  : positionControlSlidingCircle/controlY
 * '<S19>'  : positionControlSlidingCircle/ EncoderX/DS1103ENC_POS_C2
 * '<S20>'  : positionControlSlidingCircle/ EncoderX/DS1103ENC_SET_POS_C2
 * '<S21>'  : positionControlSlidingCircle/ EncoderX/_DS1103ENC_POS_C1
 * '<S22>'  : positionControlSlidingCircle/ EncoderX/_DS1103ENC_SET_POS_C1
 * '<S23>'  : positionControlSlidingCircle/ EncoderY/DS1103ENC_POS_C3
 * '<S24>'  : positionControlSlidingCircle/ EncoderY/DS1103ENC_SET_POS_C3
 * '<S25>'  : positionControlSlidingCircle/RTI Data/RTI Data Store
 * '<S26>'  : positionControlSlidingCircle/RTI Data/RTI Data Store/RTI Data Store
 * '<S27>'  : positionControlSlidingCircle/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store
 * '<S28>'  : positionControlSlidingCircle/Subsystem8/Transpose
 * '<S29>'  : positionControlSlidingCircle/Subsystem8/Transpose1
 * '<S30>'  : positionControlSlidingCircle/Subsystem8/coeffmatInv1
 * '<S31>'  : positionControlSlidingCircle/Subsystem8/coeffmatInv1/LU Solver
 * '<S32>'  : positionControlSlidingCircle/Subsystem8/coeffmatInv1/LU Solver/Check Signal Attributes
 * '<S33>'  : positionControlSlidingCircle/Subsystem8/coeffmatInv1/LU Solver/Check Signal Attributes1
 * '<S34>'  : positionControlSlidingCircle/Subsystem8/coeffmatInv1/LU Solver/Check Signal Attributes2
 */
#endif                                 /* RTW_HEADER_positionControlSlidingCircle_h_ */
