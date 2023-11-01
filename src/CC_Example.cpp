//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CC_Example.cpp
//
// Code generated for Simulink model 'CC_Example'.
//
// Model version                  : 8.6
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Nov  1 14:54:48 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 10
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "CC_Example.h"
#include "rtwtypes.h"
#include "CC_Example_types.h"
#include "CC_Example_private.h"

// Block signals (default storage)
B_CC_Example_T CC_Example_B;

// Continuous states
X_CC_Example_T CC_Example_X;

// Disabled State Vector
XDis_CC_Example_T CC_Example_XDis;

// Block states (default storage)
DW_CC_Example_T CC_Example_DW;

// Real-time model
RT_MODEL_CC_Example_T CC_Example_M_{ };

RT_MODEL_CC_Example_T *const CC_Example_M{ &CC_Example_M_ };

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3]{
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3]{
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t { rtsiGetT(si) };

  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE3_IntgData *id { static_cast<ODE3_IntgData *>(rtsiGetSolverData(si)) };

  real_T *y { id->y };

  real_T *f0 { id->f[0] };

  real_T *f1 { id->f[1] };

  real_T *f2 { id->f[2] };

  real_T hB[3];
  int_T i;
  int_T nXc { 2 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  CC_Example_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  CC_Example_step();
  CC_Example_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  CC_Example_step();
  CC_Example_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void CC_Example_step(void)
{
  SL_Bus_CC_Example_std_msgs_Float64 rtb_BusAssignment;
  SL_Bus_CC_Example_std_msgs_Float64 rtb_BusAssignment2;
  real_T rtb_Sum;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(CC_Example_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&CC_Example_M->solverInfo,
                          ((CC_Example_M->Timing.clockTick0+1)*
      CC_Example_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(CC_Example_M)) {
    CC_Example_M->Timing.t[0] = rtsiGetT(&CC_Example_M->solverInfo);
  }

  // TransferFcn: '<S8>/Transfer Fcn2'
  rtb_Sum = CC_Example_P.TransferFcn2_C * CC_Example_X.TransferFcn2_CSTATE;

  // BusAssignment: '<Root>/Bus Assignment'
  rtb_BusAssignment.Data = rtb_Sum;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_CC_Example_38.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(CC_Example_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S7>/SourceBlock'
    b_varargout_1 = Sub_CC_Example_36.getLatestMessage(&rtb_BusAssignment);

    // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S10>/In1'
      CC_Example_B.In1 = rtb_BusAssignment;
    }

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // SignalConversion generated from: '<Root>/Bus Selector'
    CC_Example_B.Data = CC_Example_B.In1.Data;
  }

  // Sum: '<Root>/Sum'
  rtb_Sum = CC_Example_B.Data - rtb_Sum;

  // Sum: '<Root>/Sum1' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Integrator: '<Root>/Integrator'

  CC_Example_B.Sum1 = CC_Example_P.Gain1_Gain * rtb_Sum +
    CC_Example_X.Integrator_CSTATE;

  // BusAssignment: '<Root>/Bus Assignment2'
  rtb_BusAssignment2.Data = CC_Example_B.Sum1;

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_CC_Example_40.publish(&rtb_BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish2'

  // Gain: '<Root>/Gain'
  CC_Example_B.Gain = CC_Example_P.Gain_Gain * rtb_Sum;
  if (rtmIsMajorTimeStep(CC_Example_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Publish1'
    // MATLABSystem: '<S4>/SinkBlock'
    Pub_CC_Example_39.publish(&CC_Example_B.In1);

    // End of Outputs for SubSystem: '<Root>/Publish1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S6>/SourceBlock'
    Sub_CC_Example_37.getLatestMessage(&rtb_BusAssignment);

    // End of Outputs for SubSystem: '<Root>/Subscribe'
  }

  if (rtmIsMajorTimeStep(CC_Example_M)) {
    rt_ertODEUpdateContinuousStates(&CC_Example_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++CC_Example_M->Timing.clockTick0;
    CC_Example_M->Timing.t[0] = rtsiGetSolverStopTime(&CC_Example_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      CC_Example_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void CC_Example_derivatives(void)
{
  XDot_CC_Example_T *_rtXdot;
  _rtXdot = ((XDot_CC_Example_T *) CC_Example_M->derivs);

  // Derivatives for TransferFcn: '<S8>/Transfer Fcn2'
  _rtXdot->TransferFcn2_CSTATE = CC_Example_P.TransferFcn2_A *
    CC_Example_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += CC_Example_B.Sum1;

  // Derivatives for Integrator: '<Root>/Integrator'
  _rtXdot->Integrator_CSTATE = CC_Example_B.Gain;
}

// Model initialize function
void CC_Example_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&CC_Example_M->solverInfo,
                          &CC_Example_M->Timing.simTimeStep);
    rtsiSetTPtr(&CC_Example_M->solverInfo, &rtmGetTPtr(CC_Example_M));
    rtsiSetStepSizePtr(&CC_Example_M->solverInfo,
                       &CC_Example_M->Timing.stepSize0);
    rtsiSetdXPtr(&CC_Example_M->solverInfo, &CC_Example_M->derivs);
    rtsiSetContStatesPtr(&CC_Example_M->solverInfo, (real_T **)
                         &CC_Example_M->contStates);
    rtsiSetNumContStatesPtr(&CC_Example_M->solverInfo,
      &CC_Example_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&CC_Example_M->solverInfo,
      &CC_Example_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&CC_Example_M->solverInfo,
      &CC_Example_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&CC_Example_M->solverInfo,
      &CC_Example_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&CC_Example_M->solverInfo, (boolean_T**)
      &CC_Example_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&CC_Example_M->solverInfo, (&rtmGetErrorStatus
      (CC_Example_M)));
    rtsiSetRTModelPtr(&CC_Example_M->solverInfo, CC_Example_M);
  }

  rtsiSetSimTimeStep(&CC_Example_M->solverInfo, MAJOR_TIME_STEP);
  CC_Example_M->intgData.y = CC_Example_M->odeY;
  CC_Example_M->intgData.f[0] = CC_Example_M->odeF[0];
  CC_Example_M->intgData.f[1] = CC_Example_M->odeF[1];
  CC_Example_M->intgData.f[2] = CC_Example_M->odeF[2];
  CC_Example_M->contStates = ((X_CC_Example_T *) &CC_Example_X);
  CC_Example_M->contStateDisabled = ((XDis_CC_Example_T *) &CC_Example_XDis);
  CC_Example_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&CC_Example_M->solverInfo, static_cast<void *>
                    (&CC_Example_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&CC_Example_M->solverInfo, false);
  rtsiSetSolverName(&CC_Example_M->solverInfo,"ode3");
  rtmSetTPtr(CC_Example_M, &CC_Example_M->Timing.tArray[0]);
  CC_Example_M->Timing.stepSize0 = 0.05;

  {
    static const char_T b_zeroDelimTopic_2[30]{ "/car/state/suggested_velocity"
    };

    static const char_T b_zeroDelimTopic_5[24]{ "/car/state/vel_x_echoed" };

    static const char_T b_zeroDelimTopic_3[17]{ "/car/state/vel_x" };

    static const char_T b_zeroDelimTopic_4[16]{ "/car/state/step" };

    static const char_T b_zeroDelimTopic_6[11]{ "/lead_dist" };

    int32_T i;
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_0[16];
    char_T b_zeroDelimTopic_1[11];

    // InitializeConditions for TransferFcn: '<S8>/Transfer Fcn2'
    CC_Example_X.TransferFcn2_CSTATE = 0.0;

    // InitializeConditions for Integrator: '<Root>/Integrator'
    CC_Example_X.Integrator_CSTATE = CC_Example_P.Integrator_IC;

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    CC_Example_DW.obj_g.matlabCodegenIsDeleted = false;
    CC_Example_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 30; i++) {
      CC_Example_B.b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Pub_CC_Example_38.createPublisher(&CC_Example_B.b_zeroDelimTopic[0], 1);
    CC_Example_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S10>/In1' incorporates:
    //   Outport: '<S10>/Out1'

    CC_Example_B.In1 = CC_Example_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    CC_Example_DW.obj_gf.matlabCodegenIsDeleted = false;
    CC_Example_DW.obj_gf.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_3[i];
    }

    Sub_CC_Example_36.createSubscriber(&b_zeroDelimTopic[0], 1);
    CC_Example_DW.obj_gf.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    CC_Example_DW.obj.matlabCodegenIsDeleted = false;
    CC_Example_DW.obj.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_4[i];
    }

    Pub_CC_Example_40.createPublisher(&b_zeroDelimTopic_0[0], 1);
    CC_Example_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    CC_Example_DW.obj_p.matlabCodegenIsDeleted = false;
    CC_Example_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      CC_Example_B.b_zeroDelimTopic_m[i] = b_zeroDelimTopic_5[i];
    }

    Pub_CC_Example_39.createPublisher(&CC_Example_B.b_zeroDelimTopic_m[0], 1);
    CC_Example_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // Start for MATLABSystem: '<S6>/SourceBlock'
    CC_Example_DW.obj_e.matlabCodegenIsDeleted = false;
    CC_Example_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_6[i];
    }

    Sub_CC_Example_37.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    CC_Example_DW.obj_e.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'
  }
}

// Model terminate function
void CC_Example_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!CC_Example_DW.obj_g.matlabCodegenIsDeleted) {
    CC_Example_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!CC_Example_DW.obj_gf.matlabCodegenIsDeleted) {
    CC_Example_DW.obj_gf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!CC_Example_DW.obj.matlabCodegenIsDeleted) {
    CC_Example_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!CC_Example_DW.obj_p.matlabCodegenIsDeleted) {
    CC_Example_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!CC_Example_DW.obj_e.matlabCodegenIsDeleted) {
    CC_Example_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'
}

//
// File trailer for generated code.
//
// [EOF]
//
