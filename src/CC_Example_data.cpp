//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: CC_Example_data.cpp
//
// Code generated for Simulink model 'CC_Example'.
//
// Model version                  : 8.6
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Nov  2 10:25:33 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 10
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "CC_Example.h"

// Block parameters (default storage)
P_CC_Example_T CC_Example_P{
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S2>/UD'

  0.0,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S5>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S4>/Constant'

  {
    0.0                                // Data
  },

  // Expression: 100
  //  Referenced by: '<Root>/Constant'

  100.0,

  // Expression: 0
  //  Referenced by: '<Root>/Gain2'

  0.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S2>/TSamp'

  20.0,

  // Expression: 0
  //  Referenced by: '<Root>/Integrator'

  0.0,

  // Expression: 0.01
  //  Referenced by: '<Root>/Gain1'

  0.01,

  // Expression: 1.5
  //  Referenced by: '<Root>/Saturation'

  1.5,

  // Expression: -3
  //  Referenced by: '<Root>/Saturation'

  -3.0,

  // Expression: 0
  //  Referenced by: '<Root>/Gain'

  0.0
};

//
// File trailer for generated code.
//
// [EOF]
//
