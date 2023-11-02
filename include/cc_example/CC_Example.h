//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CC_Example.h
//
// Code generated for Simulink model 'CC_Example'.
//
// Model version                  : 8.6
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Nov  1 22:52:27 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 10
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_CC_Example_h_
#define RTW_HEADER_CC_Example_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "CC_Example_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include <cstring>

// Macros for accessing real-time model data structure
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

// Block signals (default storage)
struct B_CC_Example_T {
  real_T Gain2;                        // '<Root>/Gain2'
  real_T Gain1;                        // '<Root>/Gain1'
  real_T Gain;                         // '<Root>/Gain'
  SL_Bus_CC_Example_std_msgs_Float64 In1;// '<S4>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_CC_Example_T {
  ros_slroscpp_internal_block_P_T obj; // '<S2>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S3>/SourceBlock'
  real_T TimeStampA;                   // '<Root>/Derivative'
  real_T LastUAtTimeA;                 // '<Root>/Derivative'
  real_T TimeStampB;                   // '<Root>/Derivative'
  real_T LastUAtTimeB;                 // '<Root>/Derivative'
};

// Continuous states (default storage)
struct X_CC_Example_T {
  real_T Integrator_CSTATE;            // '<Root>/Integrator'
};

// State derivatives (default storage)
struct XDot_CC_Example_T {
  real_T Integrator_CSTATE;            // '<Root>/Integrator'
};

// State disabled
struct XDis_CC_Example_T {
  boolean_T Integrator_CSTATE;         // '<Root>/Integrator'
};

#ifndef ODE3_INTG
#define ODE3_INTG

// ODE3 Integration Data
struct ODE3_IntgData {
  real_T *y;                           // output
  real_T *f[3];                        // derivatives
};

#endif

// Parameters (default storage)
struct P_CC_Example_T_ {
  SL_Bus_CC_Example_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                       //  Referenced by: '<S1>/Constant'

  SL_Bus_CC_Example_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                //  Referenced by: '<S4>/Out1'

  SL_Bus_CC_Example_std_msgs_Float64 Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                         //  Referenced by: '<S3>/Constant'

  real_T Constant_Value_b;             // Expression: 20
                                          //  Referenced by: '<Root>/Constant'

  real_T Gain2_Gain;                   // Expression: 1
                                          //  Referenced by: '<Root>/Gain2'

  real_T Integrator_IC;                // Expression: 0
                                          //  Referenced by: '<Root>/Integrator'

  real_T Gain1_Gain;                   // Expression: 1
                                          //  Referenced by: '<Root>/Gain1'

  real_T Saturation_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<Root>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -3
                                          //  Referenced by: '<Root>/Saturation'

  real_T Gain_Gain;                    // Expression: 1
                                          //  Referenced by: '<Root>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_CC_Example_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_CC_Example_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_CC_Example_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[3][1];
  ODE3_IntgData intgData;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_CC_Example_T CC_Example_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_CC_Example_T CC_Example_B;

#ifdef __cplusplus

}

#endif

// Continuous states (default storage)
extern X_CC_Example_T CC_Example_X;

// Disabled states (default storage)
extern XDis_CC_Example_T CC_Example_XDis;

// Block states (default storage)
extern struct DW_CC_Example_T CC_Example_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void CC_Example_initialize(void);
  extern void CC_Example_step(void);
  extern void CC_Example_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_CC_Example_T *const CC_Example_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'CC_Example'
//  '<S1>'   : 'CC_Example/Blank Message'
//  '<S2>'   : 'CC_Example/Publish'
//  '<S3>'   : 'CC_Example/Subscribe1'
//  '<S4>'   : 'CC_Example/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_CC_Example_h_

//
// File trailer for generated code.
//
// [EOF]
//
