/*
 * svpwm_position_data.c
 *
 * Code generation for model "svpwm_position".
 *
 * Model version              : 1.33
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C source code generated on : Thu Apr 16 11:18:29 2026
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "svpwm_position.h"

/* Block parameters (default storage) */
P_svpwm_position_T svpwm_position_P = {
  /* Mask Parameter: pmsm1_CL
   * Referenced by:
   *   '<S11>/Constant'
   *   '<S11>/Constant6'
   */
  0.175,

  /* Mask Parameter: pmsm1_J
   * Referenced by: '<S11>/Constant8'
   */
  0.0008,

  /* Mask Parameter: pmsm1_Ld
   * Referenced by:
   *   '<S11>/Constant1'
   *   '<S11>/Constant5'
   */
  0.0085,

  /* Mask Parameter: pmsm1_Lq
   * Referenced by:
   *   '<S11>/Constant2'
   *   '<S11>/Constant7'
   */
  0.0085,

  /* Mask Parameter: iqref1_P
   * Referenced by: '<S7>/Proportional'
   */
  0.0,

  /* Mask Parameter: iqref3_P
   * Referenced by: '<S9>/Proportional'
   */
  1.0,

  /* Mask Parameter: iqref2_P
   * Referenced by: '<S8>/Proportional'
   */
  1.0,

  /* Mask Parameter: pmsm1_Pm
   * Referenced by: '<S11>/Constant3'
   */
  4.0,

  /* Mask Parameter: RepeatingSequence_rep_seq_y
   * Referenced by: '<S2>/Look-Up Table1'
   */
  { 0.0, 4200.0, 0.0 },

  /* Mask Parameter: pmsm1_rs
   * Referenced by: '<S11>/Constant4'
   */
  2.875,

  /* Computed Parameter: pulse_Y0
   * Referenced by: '<S4>/pulse'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S4>/Constant'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<S4>/Unit Delay'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/d'
   */
  0.0,

  /* Computed Parameter: TransferFcn3_A
   * Referenced by: '<S11>/Transfer Fcn3'
   */
  -0.0,

  /* Computed Parameter: TransferFcn3_C
   * Referenced by: '<S11>/Transfer Fcn3'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Gain1'
   */
  1.0,

  /* Expression: pi*2
   * Referenced by: '<Root>/Constant2'
   */
  6.2831853071795862,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S11>/Transfer Fcn'
   */
  -0.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S11>/Transfer Fcn'
   */
  1.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S11>/Transfer Fcn1'
   */
  -0.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S11>/Transfer Fcn1'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S20>/Gain'
   */
  -1.0,

  /* Expression: sqrt(2/3)
   * Referenced by: '<S19>/Gain2'
   */
  0.816496580927726,

  /* Expression: -1/2
   * Referenced by: '<S19>/Gain1'
   */
  -0.5,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S19>/Gain3'
   */
  0.8660254037844386,

  /* Expression: sqrt(2/3)
   * Referenced by: '<S19>/Gain6'
   */
  0.816496580927726,

  /* Expression: -1/2
   * Referenced by: '<S19>/Gain'
   */
  -0.5,

  /* Expression: -sqrt(3)/2
   * Referenced by: '<S19>/Gain4'
   */
  -0.8660254037844386,

  /* Expression: sqrt(2/3)
   * Referenced by: '<S19>/Gain7'
   */
  0.816496580927726,

  /* Expression: sqrt(3/2)
   * Referenced by: '<S5>/Gain'
   */
  1.2247448713915889,

  /* Expression: sqrt(2)/2
   * Referenced by: '<S5>/Gain1'
   */
  0.70710678118654757,

  /* Expression: 1
   * Referenced by: '<S10>/Gain'
   */
  1.0,

  /* Computed Parameter: Integral_A
   * Referenced by: '<S7>/Integral'
   */
  -0.0,

  /* Computed Parameter: Integral_C
   * Referenced by: '<S7>/Integral'
   */
  0.0,

  /* Expression: max
   * Referenced by: '<S7>/Saturation'
   */
  500.0,

  /* Expression: min
   * Referenced by: '<S7>/Saturation'
   */
  -500.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain3'
   */
  57.295779513082323,

  /* Computed Parameter: Integral_A_k
   * Referenced by: '<S9>/Integral'
   */
  -0.0,

  /* Computed Parameter: Integral_C_o
   * Referenced by: '<S9>/Integral'
   */
  0.1,

  /* Expression: max
   * Referenced by: '<S9>/Saturation'
   */
  500.0,

  /* Expression: min
   * Referenced by: '<S9>/Saturation'
   */
  -500.0,

  /* Computed Parameter: TransferFcn2_A
   * Referenced by: '<S11>/Transfer Fcn2'
   */
  -0.0,

  /* Computed Parameter: TransferFcn2_C
   * Referenced by: '<S11>/Transfer Fcn2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S10>/Gain1'
   */
  1.0,

  /* Computed Parameter: Integral_A_kv
   * Referenced by: '<S8>/Integral'
   */
  -0.0,

  /* Computed Parameter: Integral_C_g
   * Referenced by: '<S8>/Integral'
   */
  0.0,

  /* Expression: max
   * Referenced by: '<S8>/Saturation'
   */
  500.0,

  /* Expression: min
   * Referenced by: '<S8>/Saturation'
   */
  -500.0,

  /* Expression: pi*2
   * Referenced by: '<Root>/Constant1'
   */
  6.2831853071795862,

  /* Expression: -1
   * Referenced by: '<Root>/Constant6'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<Root>/Constant5'
   */
  -1.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant10'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<Root>/Constant7'
   */
  100.0,

  /* Expression: 3000
   * Referenced by: '<Root>/Constant9'
   */
  3000.0,

  /* Expression: 24
   * Referenced by: '<Root>/线电压'
   */
  24.0,

  /* Expression: 8400
   * Referenced by: '<Root>/PWM周期'
   */
  8400.0,

  /* Expression: period
   * Referenced by: '<S2>/Constant'
   */
  0.0001,

  /* Expression: rep_seq_t - min(rep_seq_t)
   * Referenced by: '<S2>/Look-Up Table1'
   */
  { 0.0, 5.0E-5, 0.0001 },

  /* Expression: 3/2
   * Referenced by: '<S11>/Gain'
   */
  1.5,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain'
   */
  57.295779513082323,

  /* Expression: 180/pi
   * Referenced by: '<Root>/Gain2'
   */
  57.295779513082323,

  /* Expression: sqrt(2/3)
   * Referenced by: '<S6>/Gain1'
   */
  0.816496580927726,

  /* Expression: sqrt(2/3)
   * Referenced by: '<S6>/Gain2'
   */
  0.816496580927726,

  /* Expression: sqrt(2/3)
   * Referenced by: '<S6>/Gain3'
   */
  0.816496580927726,

  /* Expression: 1.0
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

  /* Expression: -1/2
   * Referenced by: '<S17>/Gain'
   */
  -0.5,

  /* Expression: -1/2
   * Referenced by: '<S17>/Gain1'
   */
  -0.5,

  /* Expression: sqrt(2/3)
   * Referenced by: '<S17>/Gain4'
   */
  0.816496580927726,

  /* Expression: -1
   * Referenced by: '<S18>/Gain'
   */
  -1.0,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S17>/Gain2'
   */
  0.8660254037844386,

  /* Expression: -sqrt(3)/2
   * Referenced by: '<S17>/Gain3'
   */
  -0.8660254037844386,

  /* Expression: sqrt(2/3)
   * Referenced by: '<S17>/Gain5'
   */
  0.816496580927726
};
