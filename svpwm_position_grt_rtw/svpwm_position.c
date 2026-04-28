/*
 * svpwm_position.c
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
#include "rtwtypes.h"
#include "svpwm_position_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"
#include <string.h>
#include <float.h>

/* Block signals (default storage) */
B_svpwm_position_T svpwm_position_B;

/* Continuous states */
X_svpwm_position_T svpwm_position_X;

/* Disabled State Vector */
XDis_svpwm_position_T svpwm_position_XDis;

/* Block states (default storage) */
DW_svpwm_position_T svpwm_position_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_svpwm_position_T svpwm_position_PrevZCX;

/* Real-time model */
static RT_MODEL_svpwm_position_T svpwm_position_M_;
RT_MODEL_svpwm_position_T *const svpwm_position_M = &svpwm_position_M_;

/* Forward declaration for local functions */
static void svpwm_position_coeffs(real_T q0, real_T v0, real_T a0, real_T qf,
  real_T T, real_T *c0, real_T *c1, real_T *c2, real_T *c3, real_T *c4, real_T
  *c5);
static void svpwm_position_eval_poly(real_T c0, real_T c1, real_T c2, real_T c3,
  real_T c4, real_T c5, real_T tau, real_T T, real_T qf, real_T *q, real_T *w,
  real_T *a);
static void rate_scheduler(void);
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (svpwm_position_M->Timing.TaskCounters.TID[2])++;
  if ((svpwm_position_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [0.01s, 0.0s] */
    svpwm_position_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 8;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  svpwm_position_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  svpwm_position_step();
  svpwm_position_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  svpwm_position_step();
  svpwm_position_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/S形加减速算法模型' */
static void svpwm_position_coeffs(real_T q0, real_T v0, real_T a0, real_T qf,
  real_T T, real_T *c0, real_T *c1, real_T *c2, real_T *c3, real_T *c4, real_T
  *c5)
{
  real_T A;
  real_T B;
  real_T C;
  real_T T2;
  real_T T3;
  real_T T4;
  *c0 = q0;
  *c1 = v0;
  *c2 = 0.5 * a0;
  T2 = T * T;
  T3 = T2 * T;
  T4 = T3 * T;
  A = qf - ((v0 * T + q0) + *c2 * T2);
  B = -(2.0 * *c2 * T + v0);
  C = -(2.0 * *c2);
  *c3 = (10.0 * A / T3 + -4.0 * B / T2) + 0.5 * C / T;
  *c4 = (-15.0 * A / T4 + 7.0 * B / T3) + -C / T2;
  *c5 = (6.0 * A / (T4 * T) + -3.0 * B / T4) + 0.5 * C / T3;
}

/* Function for MATLAB Function: '<Root>/S形加减速算法模型' */
static void svpwm_position_eval_poly(real_T c0, real_T c1, real_T c2, real_T c3,
  real_T c4, real_T c5, real_T tau, real_T T, real_T qf, real_T *q, real_T *w,
  real_T *a)
{
  real_T t2;
  real_T t3;
  real_T t4;
  if (tau <= 0.0) {
    *q = c0;
    *w = c1;
    *a = 2.0 * c2;
  } else if (tau >= T) {
    *q = qf;
    *w = 0.0;
    *a = 0.0;
  } else {
    t2 = tau * tau;
    t3 = t2 * tau;
    t4 = t3 * tau;
    *q = ((((c1 * tau + c0) + c2 * t2) + c3 * t3) + c4 * t4) + t4 * tau * c5;
    *w = (((2.0 * c2 * tau + c1) + 3.0 * c3 * t2) + 4.0 * c4 * t3) + 5.0 * c5 *
      t4;
    *a = ((6.0 * c3 * tau + 2.0 * c2) + 12.0 * c4 * t2) + 20.0 * c5 * t3;
  }
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void svpwm_position_step(void)
{
  real_T Amax;
  real_T Clock_tmp;
  real_T b_x;
  real_T rtb_Gain4_c;
  real_T rtb_Gain5_tmp;
  real_T rtb_TransferFcn;
  real_T rtb_TransferFcn1;
  real_T rtb_TrigonometricFunction;
  real_T rtb_TrigonometricFunction_tmp;
  real_T rtb_a_ref;
  real_T scale;
  real_T u1;
  int32_T i;
  int_T iy;
  boolean_T exitg1;
  boolean_T tmp;
  boolean_T tmp_0;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(svpwm_position_M)) {
    /* set solver stop time */
    if (!(svpwm_position_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&svpwm_position_M->solverInfo,
                            ((svpwm_position_M->Timing.clockTickH0 + 1) *
        svpwm_position_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&svpwm_position_M->solverInfo,
                            ((svpwm_position_M->Timing.clockTick0 + 1) *
        svpwm_position_M->Timing.stepSize0 +
        svpwm_position_M->Timing.clockTickH0 *
        svpwm_position_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(svpwm_position_M)) {
    svpwm_position_M->Timing.t[0] = rtsiGetT(&svpwm_position_M->solverInfo);
  }

  /* TransferFcn: '<S11>/Transfer Fcn3' */
  svpwm_position_B.TransferFcn3 = 0.0;
  svpwm_position_B.TransferFcn3 += svpwm_position_P.TransferFcn3_C *
    svpwm_position_X.TransferFcn3_CSTATE;

  /* Math: '<Root>/Mod1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Gain: '<Root>/Gain1'
   */
  svpwm_position_B.Mod1 = rt_modd_snf(svpwm_position_P.Gain1_Gain *
    svpwm_position_B.TransferFcn3, svpwm_position_P.Constant2_Value);

  /* Fcn: '<S10>/Fcn1' incorporates:
   *  Fcn: '<Root>/Ualpha'
   *  Fcn: '<Root>/Ubeta'
   */
  Amax = cos(svpwm_position_B.Mod1);

  /* Fcn: '<S10>/Fcn' incorporates:
   *  Fcn: '<Root>/Ualpha'
   *  Fcn: '<Root>/Ubeta'
   */
  rtb_a_ref = sin(svpwm_position_B.Mod1);

  /* TransferFcn: '<S11>/Transfer Fcn' */
  rtb_TransferFcn = svpwm_position_P.TransferFcn_C *
    svpwm_position_X.TransferFcn_CSTATE;

  /* Trigonometry: '<S20>/Trigonometric Function1' incorporates:
   *  Trigonometry: '<S18>/Trigonometric Function1'
   */
  rtb_Gain5_tmp = cos(svpwm_position_B.TransferFcn3);

  /* TransferFcn: '<S11>/Transfer Fcn1' */
  rtb_TransferFcn1 = svpwm_position_P.TransferFcn1_C *
    svpwm_position_X.TransferFcn1_CSTATE;

  /* Trigonometry: '<S20>/Trigonometric Function' incorporates:
   *  Trigonometry: '<S18>/Trigonometric Function'
   */
  rtb_TrigonometricFunction_tmp = sin(svpwm_position_B.TransferFcn3);

  /* Sum: '<S20>/Sum1' incorporates:
   *  Gain: '<S20>/Gain'
   *  Product: '<S20>/multiply'
   *  Product: '<S20>/multiply2'
   *  Trigonometry: '<S20>/Trigonometric Function'
   *  Trigonometry: '<S20>/Trigonometric Function1'
   */
  rtb_Gain4_c = svpwm_position_P.Gain_Gain * rtb_TrigonometricFunction_tmp *
    rtb_TransferFcn1 + rtb_TransferFcn * rtb_Gain5_tmp;

  /* Gain: '<S19>/Gain2' */
  svpwm_position_B.Gain2 = svpwm_position_P.Gain2_Gain * rtb_Gain4_c;

  /* Sum: '<S20>/Sum' incorporates:
   *  Product: '<S20>/multiply1'
   *  Product: '<S20>/multiply3'
   *  Trigonometry: '<S20>/Trigonometric Function'
   *  Trigonometry: '<S20>/Trigonometric Function1'
   */
  rtb_TrigonometricFunction = rtb_TransferFcn * rtb_TrigonometricFunction_tmp +
    rtb_TransferFcn1 * rtb_Gain5_tmp;

  /* Gain: '<S19>/Gain6' incorporates:
   *  Gain: '<S19>/Gain1'
   *  Gain: '<S19>/Gain3'
   *  Sum: '<S19>/Add1'
   */
  svpwm_position_B.Gain6 = (svpwm_position_P.Gain1_Gain_g * rtb_Gain4_c +
    svpwm_position_P.Gain3_Gain * rtb_TrigonometricFunction) *
    svpwm_position_P.Gain6_Gain;

  /* Gain: '<S19>/Gain7' incorporates:
   *  Gain: '<S19>/Gain'
   *  Gain: '<S19>/Gain4'
   *  Sum: '<S19>/Add2'
   */
  svpwm_position_B.Gain7 = (svpwm_position_P.Gain_Gain_e * rtb_Gain4_c +
    svpwm_position_P.Gain4_Gain * rtb_TrigonometricFunction) *
    svpwm_position_P.Gain7_Gain;

  /* Gain: '<S5>/Gain' incorporates:
   *  Fcn: '<S5>/i_alpha'
   */
  svpwm_position_B.Gain = svpwm_position_P.Gain_Gain_i * svpwm_position_B.Gain2;

  /* Gain: '<S5>/Gain1' incorporates:
   *  Fcn: '<S5>/i_beta'
   */
  svpwm_position_B.Gain1 = (2.0 * svpwm_position_B.Gain6 +
    svpwm_position_B.Gain2) * svpwm_position_P.Gain1_Gain_e;

  /* Fcn: '<S10>/id' incorporates:
   *  Fcn: '<S10>/Fcn'
   *  Fcn: '<S10>/Fcn1'
   */
  rtb_Gain4_c = Amax * svpwm_position_B.Gain + rtb_a_ref *
    svpwm_position_B.Gain1;

  /* Gain: '<S10>/Gain' */
  svpwm_position_B.Gain_l = svpwm_position_P.Gain_Gain_c * rtb_Gain4_c;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/d'
   */
  svpwm_position_B.Sum = svpwm_position_P.d_Value - svpwm_position_B.Gain_l;

  /* TransferFcn: '<S7>/Integral' */
  rtb_Gain4_c = svpwm_position_P.Integral_C * svpwm_position_X.Integral_CSTATE;

  /* Sum: '<S7>/Sum' incorporates:
   *  Gain: '<S7>/Proportional'
   */
  rtb_Gain4_c += svpwm_position_P.iqref1_P * svpwm_position_B.Sum;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Gain4_c > svpwm_position_P.Saturation_UpperSat) {
    /* Saturate: '<S7>/Saturation' */
    svpwm_position_B.Saturation = svpwm_position_P.Saturation_UpperSat;
  } else if (rtb_Gain4_c < svpwm_position_P.Saturation_LowerSat) {
    /* Saturate: '<S7>/Saturation' */
    svpwm_position_B.Saturation = svpwm_position_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S7>/Saturation' */
    svpwm_position_B.Saturation = rtb_Gain4_c;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Integrator: '<Root>/Integrator' */
  svpwm_position_B.u = svpwm_position_X.Integrator_CSTATE;

  /* Gain: '<Root>/Gain3' */
  svpwm_position_B.theta = svpwm_position_P.Gain3_Gain_i *
    svpwm_position_B.TransferFcn3;

  /* Sum: '<Root>/Sum3' */
  svpwm_position_B.u_m = svpwm_position_B.u - svpwm_position_B.theta;

  /* TransferFcn: '<S9>/Integral' */
  rtb_Gain4_c = svpwm_position_P.Integral_C_o *
    svpwm_position_X.Integral_CSTATE_e;

  /* Sum: '<S9>/Sum' incorporates:
   *  Gain: '<S9>/Proportional'
   */
  rtb_Gain4_c += svpwm_position_P.iqref3_P * svpwm_position_B.u_m;

  /* Saturate: '<S9>/Saturation' */
  if (rtb_Gain4_c > svpwm_position_P.Saturation_UpperSat_d) {
    /* Saturate: '<S9>/Saturation' */
    svpwm_position_B.Saturation_a = svpwm_position_P.Saturation_UpperSat_d;
  } else if (rtb_Gain4_c < svpwm_position_P.Saturation_LowerSat_h) {
    /* Saturate: '<S9>/Saturation' */
    svpwm_position_B.Saturation_a = svpwm_position_P.Saturation_LowerSat_h;
  } else {
    /* Saturate: '<S9>/Saturation' */
    svpwm_position_B.Saturation_a = rtb_Gain4_c;
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* TransferFcn: '<S11>/Transfer Fcn2' */
  svpwm_position_B.TransferFcn2 = 0.0;
  svpwm_position_B.TransferFcn2 += svpwm_position_P.TransferFcn2_C *
    svpwm_position_X.TransferFcn2_CSTATE;

  /* Sum: '<Root>/Sum2' */
  svpwm_position_B.Sum2 = svpwm_position_B.Saturation_a -
    svpwm_position_B.TransferFcn2;

  /* Gain: '<S10>/Gain1' incorporates:
   *  Fcn: '<S10>/Fcn'
   *  Fcn: '<S10>/Fcn1'
   *  Fcn: '<S10>/iq'
   */
  svpwm_position_B.Gain1_f = (-rtb_a_ref * svpwm_position_B.Gain + Amax *
    svpwm_position_B.Gain1) * svpwm_position_P.Gain1_Gain_es;

  /* Sum: '<Root>/Sum1' */
  svpwm_position_B.Sum1 = svpwm_position_B.Sum2 - svpwm_position_B.Gain1_f;

  /* TransferFcn: '<S8>/Integral' */
  rtb_Gain4_c = svpwm_position_P.Integral_C_g *
    svpwm_position_X.Integral_CSTATE_f;

  /* Sum: '<S8>/Sum' incorporates:
   *  Gain: '<S8>/Proportional'
   */
  rtb_Gain4_c += svpwm_position_P.iqref2_P * svpwm_position_B.Sum1;

  /* Saturate: '<S8>/Saturation' */
  if (rtb_Gain4_c > svpwm_position_P.Saturation_UpperSat_db) {
    /* Saturate: '<S8>/Saturation' */
    svpwm_position_B.Saturation_b = svpwm_position_P.Saturation_UpperSat_db;
  } else if (rtb_Gain4_c < svpwm_position_P.Saturation_LowerSat_a) {
    /* Saturate: '<S8>/Saturation' */
    svpwm_position_B.Saturation_b = svpwm_position_P.Saturation_LowerSat_a;
  } else {
    /* Saturate: '<S8>/Saturation' */
    svpwm_position_B.Saturation_b = rtb_Gain4_c;
  }

  /* End of Saturate: '<S8>/Saturation' */
  tmp = (rtmIsMajorTimeStep(svpwm_position_M) &&
         svpwm_position_M->Timing.TaskCounters.TID[1] == 0);
  if (tmp) {
  }

  /* Fcn: '<Root>/Ualpha' */
  svpwm_position_B.Ualpha = svpwm_position_B.Saturation * Amax -
    svpwm_position_B.Saturation_b * rtb_a_ref;

  /* Fcn: '<Root>/Ubeta' */
  svpwm_position_B.Ubeta = svpwm_position_B.Saturation * rtb_a_ref +
    svpwm_position_B.Saturation_b * Amax;
  if (rtmIsMajorTimeStep(svpwm_position_M) &&
      svpwm_position_M->Timing.TaskCounters.TID[2] == 0) {
  }

  if (tmp) {
  }

  /* Math: '<Root>/Mod' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  svpwm_position_B.Mod = rt_modd_snf(svpwm_position_B.TransferFcn3,
    svpwm_position_P.Constant1_Value);
  if (tmp) {
    /* Outputs for Triggered SubSystem: '<Root>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S4>/Trigger'
     */
    if (rtsiIsModeUpdateTimeStep(&svpwm_position_M->solverInfo)) {
      /* Constant: '<Root>/Constant4' */
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &svpwm_position_PrevZCX.TriggeredSubsystem_Trig_ZCE,
                         (svpwm_position_P.Constant4_Value));
      if (zcEvent != NO_ZCEVENT) {
        /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
         *  Constant: '<Root>/Constant6'
         *  Constant: '<S4>/Constant'
         */
        rtb_Gain4_c = 0.0;
        if (svpwm_position_P.Constant6_Value > 0.0) {
          rtb_Gain4_c = svpwm_position_P.Constant_Value;
        }

        if (svpwm_position_P.Constant6_Value < 0.0) {
          rtb_Gain4_c = -svpwm_position_P.Constant_Value;
        }

        if (svpwm_position_P.Constant6_Value == 0.0) {
          rtb_Gain4_c = 0.0;
        }

        /* End of MATLAB Function: '<S4>/MATLAB Function' */

        /* Sum: '<S4>/Sum' incorporates:
         *  UnitDelay: '<S4>/Unit Delay'
         */
        svpwm_position_B.Sum_l = svpwm_position_DW.UnitDelay_DSTATE +
          rtb_Gain4_c;

        /* Update for UnitDelay: '<S4>/Unit Delay' */
        svpwm_position_DW.UnitDelay_DSTATE = svpwm_position_B.Sum_l;
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Triggered Subsystem' */
  }

  /* Clock: '<Root>/Clock' incorporates:
   *  Clock: '<S2>/Clock'
   */
  Clock_tmp = svpwm_position_M->Timing.t[0];

  /* Clock: '<Root>/Clock' */
  svpwm_position_B.Clock = Clock_tmp;
  if (tmp) {
    /* MATLAB Function: '<Root>/S形加减速算法模型' incorporates:
     *  Constant: '<Root>/Constant10'
     *  Constant: '<Root>/Constant4'
     *  Constant: '<Root>/Constant7'
     *  Constant: '<Root>/Constant9'
     */
    if (!svpwm_position_DW.t0_not_empty) {
      svpwm_position_DW.qf = svpwm_position_B.Sum_l;
      svpwm_position_DW.t0 = svpwm_position_B.Clock;
      svpwm_position_DW.t0_not_empty = true;
      svpwm_position_coeffs(svpwm_position_B.Sum_l, svpwm_position_DW.v0,
                            svpwm_position_DW.a0, svpwm_position_DW.qf,
                            svpwm_position_DW.Tseg, &svpwm_position_DW.c0,
                            &svpwm_position_DW.c1, &svpwm_position_DW.c2,
                            &svpwm_position_DW.c3, &svpwm_position_DW.c4,
                            &svpwm_position_DW.c5);
    }

    svpwm_position_eval_poly(svpwm_position_DW.c0, svpwm_position_DW.c1,
      svpwm_position_DW.c2, svpwm_position_DW.c3, svpwm_position_DW.c4,
      svpwm_position_DW.c5, svpwm_position_B.Clock - svpwm_position_DW.t0,
      svpwm_position_DW.Tseg, svpwm_position_DW.qf, &rtb_Gain4_c, &Amax,
      &rtb_a_ref);
    if (svpwm_position_P.Constant4_Value != 0.0) {
      svpwm_position_DW.v0 = Amax;
      svpwm_position_DW.a0 = rtb_a_ref;
      svpwm_position_DW.qf = svpwm_position_B.Sum_l;
      svpwm_position_DW.t0 = svpwm_position_B.Clock;
      rtb_a_ref = svpwm_position_DW.qf - rtb_Gain4_c;
      if (rtb_a_ref >= 0.0) {
        Amax = fabs(svpwm_position_P.Constant10_Value);
      } else {
        Amax = fabs(svpwm_position_P.Constant7_Value);
      }

      rtb_a_ref = fabs(rtb_a_ref);
      svpwm_position_DW.Tseg = 0.001;
      if (rtb_a_ref > 1.0E-12) {
        if (Amax > 0.0) {
          u1 = sqrt(5.7735026918962573 * rtb_a_ref / Amax);
          if ((!(u1 <= 0.001)) && (!rtIsNaN(u1))) {
            svpwm_position_DW.Tseg = u1;
          }
        }

        tmp_0 = ((!rtIsInf(svpwm_position_P.Constant9_Value)) && (!rtIsNaN
                  (svpwm_position_P.Constant9_Value)));
        if (tmp_0 && (svpwm_position_P.Constant9_Value > 0.0)) {
          u1 = 1.875 * rtb_a_ref / fabs(svpwm_position_P.Constant9_Value);
          if ((!(svpwm_position_DW.Tseg >= u1)) && (!rtIsNaN(u1))) {
            svpwm_position_DW.Tseg = u1;
          }
        }

        iy = 0;
        exitg1 = false;
        while ((!exitg1) && (iy < 4)) {
          svpwm_position_coeffs(rtb_Gain4_c, svpwm_position_DW.v0,
                                svpwm_position_DW.a0, svpwm_position_DW.qf,
                                svpwm_position_DW.Tseg, &svpwm_position_DW.c0,
                                &svpwm_position_DW.c1, &svpwm_position_DW.c2,
                                &svpwm_position_DW.c3, &svpwm_position_DW.c4,
                                &svpwm_position_DW.c5);
          rtb_a_ref = 0.0;
          rtb_TrigonometricFunction = 0.0;
          for (i = 0; i < 26; i++) {
            svpwm_position_eval_poly(svpwm_position_DW.c0, svpwm_position_DW.c1,
              svpwm_position_DW.c2, svpwm_position_DW.c3, svpwm_position_DW.c4,
              svpwm_position_DW.c5, svpwm_position_DW.Tseg * (real_T)i / 25.0,
              svpwm_position_DW.Tseg, 0.0, &scale, &u1, &b_x);
            u1 = fabs(u1);
            if ((!(rtb_a_ref >= u1)) && (!rtIsNaN(u1))) {
              rtb_a_ref = u1;
            }

            u1 = fabs(b_x);
            if ((!(rtb_TrigonometricFunction >= u1)) && (!rtIsNaN(u1))) {
              rtb_TrigonometricFunction = u1;
            }
          }

          scale = 1.0;
          if (tmp_0 && (svpwm_position_P.Constant9_Value > 0.0)) {
            u1 = rtb_a_ref / fabs(svpwm_position_P.Constant9_Value);
            if ((!(u1 <= 1.0)) && (!rtIsNaN(u1))) {
              scale = u1;
            }
          }

          if (Amax > 0.0) {
            u1 = sqrt(rtb_TrigonometricFunction / Amax);
            if ((!(scale >= u1)) && (!rtIsNaN(u1))) {
              scale = u1;
            }
          }

          if (scale <= 1.001) {
            exitg1 = true;
          } else {
            svpwm_position_DW.Tseg = svpwm_position_DW.Tseg * scale * 1.05;
            iy++;
          }
        }
      }

      svpwm_position_coeffs(rtb_Gain4_c, svpwm_position_DW.v0,
                            svpwm_position_DW.a0, svpwm_position_DW.qf,
                            svpwm_position_DW.Tseg, &svpwm_position_DW.c0,
                            &svpwm_position_DW.c1, &svpwm_position_DW.c2,
                            &svpwm_position_DW.c3, &svpwm_position_DW.c4,
                            &svpwm_position_DW.c5);
      svpwm_position_B.w_ref = svpwm_position_DW.v0;
      rtb_a_ref = svpwm_position_DW.a0;
    } else {
      svpwm_position_B.w_ref = Amax;
    }

    /* End of MATLAB Function: '<Root>/S形加减速算法模型' */
  }

  /* MATLAB Function: '<Root>/扇区判断' incorporates:
   *  Fcn: '<Root>/A'
   *  Fcn: '<Root>/B'
   *  Fcn: '<Root>/C'
   */
  svpwm_position_B.N = 0.0;
  if (svpwm_position_B.Ubeta > 0.0) {
    svpwm_position_B.N++;
  }

  if (svpwm_position_B.Ualpha * 1.7320508075688772 / 2.0 -
      svpwm_position_B.Ubeta / 2.0 > 0.0) {
    svpwm_position_B.N += 2.0;
  }

  if (-svpwm_position_B.Ualpha * 1.7320508075688772 / 2.0 -
      svpwm_position_B.Ubeta / 2.0 > 0.0) {
    svpwm_position_B.N += 4.0;
  }

  /* End of MATLAB Function: '<Root>/扇区判断' */
  if (tmp) {
  }

  /* MATLAB Function: '<Root>/矢量作用时间计算' incorporates:
   *  Constant: '<Root>/PWM周期'
   *  Constant: '<Root>/线电压'
   *  Fcn: '<Root>/C1'
   *  Fcn: '<Root>/C2'
   */
  svpwm_position_B.Ta = 0.0;
  svpwm_position_B.Tb = 0.0;
  rtb_a_ref = 1.7320508075688772 * svpwm_position_P.PWM_Value /
    svpwm_position_P._Value;
  rtb_Gain4_c = rtb_a_ref * svpwm_position_B.Ubeta;
  Amax = (0.8660254037844386 * svpwm_position_B.Ualpha - 0.5 *
          svpwm_position_B.Ubeta) * rtb_a_ref;
  rtb_a_ref *= -0.8660254037844386 * svpwm_position_B.Ualpha - 0.5 *
    svpwm_position_B.Ubeta;
  if (svpwm_position_B.N == 3.0) {
    svpwm_position_B.Ta = Amax;
    svpwm_position_B.Tb = rtb_Gain4_c;
  }

  if (svpwm_position_B.N == 1.0) {
    svpwm_position_B.Ta = -Amax;
    svpwm_position_B.Tb = -rtb_a_ref;
  }

  if (svpwm_position_B.N == 5.0) {
    svpwm_position_B.Ta = rtb_Gain4_c;
    svpwm_position_B.Tb = rtb_a_ref;
  }

  if (svpwm_position_B.N == 4.0) {
    svpwm_position_B.Ta = -rtb_Gain4_c;
    svpwm_position_B.Tb = -Amax;
  }

  if (svpwm_position_B.N == 6.0) {
    svpwm_position_B.Ta = rtb_a_ref;
    svpwm_position_B.Tb = Amax;
  }

  if (svpwm_position_B.N == 2.0) {
    svpwm_position_B.Ta = -rtb_a_ref;
    svpwm_position_B.Tb = -rtb_Gain4_c;
  }

  /* End of MATLAB Function: '<Root>/矢量作用时间计算' */
  if (tmp) {
  }

  /* MATLAB Function: '<Root>/CCR值计算' incorporates:
   *  Constant: '<Root>/PWM周期'
   */
  rtb_a_ref = svpwm_position_B.Ta;
  rtb_Gain4_c = svpwm_position_B.Tb;
  svpwm_position_B.CCR1 = 0.0;
  svpwm_position_B.CCR2 = 0.0;
  svpwm_position_B.CCR3 = 0.0;
  Amax = svpwm_position_B.Ta + svpwm_position_B.Tb;
  if (Amax > svpwm_position_P.PWM_Value) {
    rtb_a_ref = svpwm_position_B.Ta / Amax * svpwm_position_P.PWM_Value;
    rtb_Gain4_c = svpwm_position_B.Tb / Amax * svpwm_position_P.PWM_Value;
  }

  Amax = ((svpwm_position_P.PWM_Value - rtb_a_ref) - rtb_Gain4_c) / 4.0;
  rtb_a_ref = rtb_a_ref / 2.0 + Amax;
  rtb_Gain4_c = rtb_Gain4_c / 2.0 + rtb_a_ref;
  switch ((int32_T)svpwm_position_B.N) {
   case 3:
    svpwm_position_B.CCR1 = Amax;
    svpwm_position_B.CCR2 = rtb_a_ref;
    svpwm_position_B.CCR3 = rtb_Gain4_c;
    break;

   case 1:
    svpwm_position_B.CCR1 = rtb_a_ref;
    svpwm_position_B.CCR2 = Amax;
    svpwm_position_B.CCR3 = rtb_Gain4_c;
    break;

   case 5:
    svpwm_position_B.CCR1 = rtb_Gain4_c;
    svpwm_position_B.CCR2 = Amax;
    svpwm_position_B.CCR3 = rtb_a_ref;
    break;

   case 4:
    svpwm_position_B.CCR1 = rtb_Gain4_c;
    svpwm_position_B.CCR2 = rtb_a_ref;
    svpwm_position_B.CCR3 = Amax;
    break;

   case 6:
    svpwm_position_B.CCR1 = rtb_a_ref;
    svpwm_position_B.CCR2 = rtb_Gain4_c;
    svpwm_position_B.CCR3 = Amax;
    break;

   case 2:
    svpwm_position_B.CCR1 = Amax;
    svpwm_position_B.CCR2 = rtb_Gain4_c;
    svpwm_position_B.CCR3 = rtb_a_ref;
    break;
  }

  svpwm_position_B.value1 = Amax;
  svpwm_position_B.value2 = rtb_a_ref;
  svpwm_position_B.value3 = rtb_Gain4_c;

  /* End of MATLAB Function: '<Root>/CCR值计算' */
  if (tmp) {
  }

  /* Lookup_n-D: '<S2>/Look-Up Table1' incorporates:
   *  Constant: '<S2>/Constant'
   *  Math: '<S2>/Math Function'
   */
  svpwm_position_B.LookUpTable1 = look1_binlxpw(rt_remd_snf(Clock_tmp,
    svpwm_position_P.Constant_Value_f), svpwm_position_P.LookUpTable1_bp01Data,
    svpwm_position_P.RepeatingSequence_rep_seq_y, 2U);
  if (tmp) {
  }

  /* MATLAB Function: '<Root>/六步开关的控制' */
  if (svpwm_position_B.LookUpTable1 < svpwm_position_B.CCR1) {
    svpwm_position_B.CH1 = 0.0;
    svpwm_position_B.CH1N = 1.0;
  } else {
    svpwm_position_B.CH1 = 1.0;
    svpwm_position_B.CH1N = 0.0;
  }

  if (svpwm_position_B.LookUpTable1 < svpwm_position_B.CCR2) {
    svpwm_position_B.CH2 = 0.0;
    svpwm_position_B.CH2N = 1.0;
  } else {
    svpwm_position_B.CH2 = 1.0;
    svpwm_position_B.CH2N = 0.0;
  }

  if (svpwm_position_B.LookUpTable1 < svpwm_position_B.CCR3) {
    svpwm_position_B.CH3 = 0.0;
    svpwm_position_B.CH3N = 1.0;
  } else {
    svpwm_position_B.CH3 = 1.0;
    svpwm_position_B.CH3N = 0.0;
  }

  /* End of MATLAB Function: '<Root>/六步开关的控制' */
  if (tmp) {
    /* Sum: '<S11>/Add3' incorporates:
     *  Constant: '<S11>/Constant1'
     *  Constant: '<S11>/Constant7'
     */
    svpwm_position_B.Add3 = svpwm_position_P.pmsm1_Ld -
      svpwm_position_P.pmsm1_Lq;
  }

  /* Gain: '<S11>/Gain' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant3'
   *  Product: '<S11>/Multiply10'
   *  Product: '<S11>/Multiply12'
   *  Product: '<S11>/Multiply9'
   *  Sum: '<S11>/Add5'
   */
  svpwm_position_B.Gain_h = (rtb_TransferFcn * rtb_TransferFcn1 *
    svpwm_position_B.Add3 + rtb_TransferFcn1 * svpwm_position_P.pmsm1_CL) *
    svpwm_position_P.pmsm1_Pm * svpwm_position_P.Gain_Gain_o;

  /* Gain: '<Root>/Gain' */
  svpwm_position_B.Gain_j = svpwm_position_P.Gain_Gain_d *
    svpwm_position_B.TransferFcn3;

  /* Gain: '<Root>/Gain2' */
  svpwm_position_B.Gain2_i = svpwm_position_P.Gain2_Gain_o *
    svpwm_position_B.Mod;
  if (tmp) {
  }

  /* Gain: '<S6>/Gain1' incorporates:
   *  Fcn: '<Root>/C1'
   */
  svpwm_position_B.Gain1_k = svpwm_position_P.Gain1_Gain_f *
    svpwm_position_B.Ualpha;

  /* Fcn: '<S6>/Fcn' incorporates:
   *  Fcn: '<Root>/C1'
   *  Fcn: '<Root>/C2'
   *  Fcn: '<S6>/Fcn1'
   */
  Amax = -svpwm_position_B.Ualpha / 2.0;
  rtb_a_ref = 1.73205081 * svpwm_position_B.Ubeta / 2.0;

  /* Gain: '<S6>/Gain2' incorporates:
   *  Fcn: '<S6>/Fcn'
   */
  svpwm_position_B.Gain2_p = (rtb_a_ref + Amax) * svpwm_position_P.Gain2_Gain_g;

  /* Gain: '<S6>/Gain3' incorporates:
   *  Fcn: '<S6>/Fcn1'
   */
  svpwm_position_B.Gain3 = (Amax - rtb_a_ref) * svpwm_position_P.Gain3_Gain_b;
  if (tmp) {
  }

  /* Gain: '<S17>/Gain4' incorporates:
   *  Gain: '<S17>/Gain'
   *  Gain: '<S17>/Gain1'
   *  Sum: '<S17>/Add'
   */
  rtb_Gain4_c = ((svpwm_position_P.Gain_Gain_h * svpwm_position_B.Gain2_p +
                  svpwm_position_B.Gain1_k) + svpwm_position_P.Gain1_Gain_j *
                 svpwm_position_B.Gain3) * svpwm_position_P.Gain4_Gain_d;

  /* Gain: '<S17>/Gain5' incorporates:
   *  Gain: '<S17>/Gain2'
   *  Gain: '<S17>/Gain3'
   *  Sum: '<S17>/Add1'
   */
  Amax = (svpwm_position_P.Gain2_Gain_j * svpwm_position_B.Gain2_p +
          svpwm_position_P.Gain3_Gain_n * svpwm_position_B.Gain3) *
    svpwm_position_P.Gain5_Gain;

  /* Product: '<S11>/Multiply7' incorporates:
   *  Constant: '<S11>/Constant3'
   */
  svpwm_position_B.Multiply7 = svpwm_position_B.TransferFcn2 *
    svpwm_position_P.pmsm1_Pm;

  /* Product: '<S11>/Multiply2' incorporates:
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant4'
   *  Constant: '<S11>/Constant5'
   *  Constant: '<S11>/Constant6'
   *  Gain: '<S18>/Gain'
   *  Product: '<S11>/Multiply'
   *  Product: '<S11>/Multiply1'
   *  Product: '<S11>/Multiply4'
   *  Product: '<S18>/Product2'
   *  Product: '<S18>/Product3'
   *  Sum: '<S11>/Add'
   *  Sum: '<S18>/Sum1'
   */
  svpwm_position_B.Multiply2 = ((((svpwm_position_P.Gain_Gain_cd *
    rtb_TrigonometricFunction_tmp * rtb_Gain4_c + Amax * rtb_Gain5_tmp) -
    rtb_TransferFcn1 * svpwm_position_P.pmsm1_rs) - svpwm_position_B.Multiply7 *
    svpwm_position_P.pmsm1_CL) - rtb_TransferFcn * svpwm_position_P.pmsm1_Ld *
    svpwm_position_B.Multiply7) / svpwm_position_P.pmsm1_Lq;

  /* Product: '<S11>/Multiply5' incorporates:
   *  Constant: '<S11>/Constant2'
   *  Constant: '<S11>/Constant4'
   *  Constant: '<S11>/Constant5'
   *  Product: '<S11>/Multiply3'
   *  Product: '<S11>/Multiply6'
   *  Product: '<S18>/Product'
   *  Product: '<S18>/Product1'
   *  Sum: '<S11>/Add4'
   *  Sum: '<S18>/Sum'
   */
  svpwm_position_B.Multiply5 = (((rtb_Gain4_c * rtb_Gain5_tmp + Amax *
    rtb_TrigonometricFunction_tmp) - rtb_TransferFcn * svpwm_position_P.pmsm1_rs)
    + rtb_TransferFcn1 * svpwm_position_P.pmsm1_Lq * svpwm_position_B.Multiply7)
    / svpwm_position_P.pmsm1_Ld;

  /* Product: '<S11>/Multiply8' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S11>/Constant8'
   *  Sum: '<S11>/Add2'
   */
  svpwm_position_B.Multiply8 = (svpwm_position_B.Gain_h -
    svpwm_position_P.Constant3_Value) / svpwm_position_P.pmsm1_J;

  /* S-Function (sfun_tstart): '<S12>/startTime' */
  svpwm_position_B.startTime = 0.0;
  if (rtmIsMajorTimeStep(svpwm_position_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(svpwm_position_M->rtwLogInfo,
                        (svpwm_position_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(svpwm_position_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(svpwm_position_M)!=-1) &&
          !((rtmGetTFinal(svpwm_position_M)-
             (((svpwm_position_M->Timing.clockTick1+
                svpwm_position_M->Timing.clockTickH1* 4294967296.0)) * 1.0E-5)) >
            (((svpwm_position_M->Timing.clockTick1+
               svpwm_position_M->Timing.clockTickH1* 4294967296.0)) * 1.0E-5) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(svpwm_position_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&svpwm_position_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++svpwm_position_M->Timing.clockTick0)) {
      ++svpwm_position_M->Timing.clockTickH0;
    }

    svpwm_position_M->Timing.t[0] = rtsiGetSolverStopTime
      (&svpwm_position_M->solverInfo);

    {
      /* Update absolute timer for sample time: [1.0E-5s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      svpwm_position_M->Timing.clockTick1++;
      if (!svpwm_position_M->Timing.clockTick1) {
        svpwm_position_M->Timing.clockTickH1++;
      }
    }

    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void svpwm_position_derivatives(void)
{
  XDot_svpwm_position_T *_rtXdot;
  _rtXdot = ((XDot_svpwm_position_T *) svpwm_position_M->derivs);

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE = svpwm_position_P.TransferFcn3_A *
    svpwm_position_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += svpwm_position_B.Multiply7;

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = svpwm_position_P.TransferFcn_A *
    svpwm_position_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += svpwm_position_B.Multiply5;

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = svpwm_position_P.TransferFcn1_A *
    svpwm_position_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += svpwm_position_B.Multiply2;

  /* Derivatives for TransferFcn: '<S7>/Integral' */
  _rtXdot->Integral_CSTATE = svpwm_position_P.Integral_A *
    svpwm_position_X.Integral_CSTATE;
  _rtXdot->Integral_CSTATE += svpwm_position_B.Sum;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = svpwm_position_B.w_ref;

  /* Derivatives for TransferFcn: '<S9>/Integral' */
  _rtXdot->Integral_CSTATE_e = svpwm_position_P.Integral_A_k *
    svpwm_position_X.Integral_CSTATE_e;
  _rtXdot->Integral_CSTATE_e += svpwm_position_B.u_m;

  /* Derivatives for TransferFcn: '<S11>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = svpwm_position_P.TransferFcn2_A *
    svpwm_position_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += svpwm_position_B.Multiply8;

  /* Derivatives for TransferFcn: '<S8>/Integral' */
  _rtXdot->Integral_CSTATE_f = svpwm_position_P.Integral_A_kv *
    svpwm_position_X.Integral_CSTATE_f;
  _rtXdot->Integral_CSTATE_f += svpwm_position_B.Sum1;
}

/* Model initialize function */
void svpwm_position_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)svpwm_position_M, 0,
                sizeof(RT_MODEL_svpwm_position_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&svpwm_position_M->solverInfo,
                          &svpwm_position_M->Timing.simTimeStep);
    rtsiSetTPtr(&svpwm_position_M->solverInfo, &rtmGetTPtr(svpwm_position_M));
    rtsiSetStepSizePtr(&svpwm_position_M->solverInfo,
                       &svpwm_position_M->Timing.stepSize0);
    rtsiSetdXPtr(&svpwm_position_M->solverInfo, &svpwm_position_M->derivs);
    rtsiSetContStatesPtr(&svpwm_position_M->solverInfo, (real_T **)
                         &svpwm_position_M->contStates);
    rtsiSetNumContStatesPtr(&svpwm_position_M->solverInfo,
      &svpwm_position_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&svpwm_position_M->solverInfo,
      &svpwm_position_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&svpwm_position_M->solverInfo,
      &svpwm_position_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&svpwm_position_M->solverInfo,
      &svpwm_position_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&svpwm_position_M->solverInfo, (boolean_T**)
      &svpwm_position_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&svpwm_position_M->solverInfo, (&rtmGetErrorStatus
      (svpwm_position_M)));
    rtsiSetRTModelPtr(&svpwm_position_M->solverInfo, svpwm_position_M);
  }

  rtsiSetSimTimeStep(&svpwm_position_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&svpwm_position_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&svpwm_position_M->solverInfo, false);
  svpwm_position_M->intgData.y = svpwm_position_M->odeY;
  svpwm_position_M->intgData.f[0] = svpwm_position_M->odeF[0];
  svpwm_position_M->intgData.f[1] = svpwm_position_M->odeF[1];
  svpwm_position_M->intgData.f[2] = svpwm_position_M->odeF[2];
  svpwm_position_M->contStates = ((X_svpwm_position_T *) &svpwm_position_X);
  svpwm_position_M->contStateDisabled = ((XDis_svpwm_position_T *)
    &svpwm_position_XDis);
  svpwm_position_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&svpwm_position_M->solverInfo, (void *)
                    &svpwm_position_M->intgData);
  rtsiSetSolverName(&svpwm_position_M->solverInfo,"ode3");
  rtmSetTPtr(svpwm_position_M, &svpwm_position_M->Timing.tArray[0]);
  rtmSetTFinal(svpwm_position_M, -1);
  svpwm_position_M->Timing.stepSize0 = 1.0E-5;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    svpwm_position_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(svpwm_position_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(svpwm_position_M->rtwLogInfo, (NULL));
    rtliSetLogT(svpwm_position_M->rtwLogInfo, "tout");
    rtliSetLogX(svpwm_position_M->rtwLogInfo, "");
    rtliSetLogXFinal(svpwm_position_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(svpwm_position_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(svpwm_position_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(svpwm_position_M->rtwLogInfo, 0);
    rtliSetLogDecimation(svpwm_position_M->rtwLogInfo, 1);
    rtliSetLogY(svpwm_position_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(svpwm_position_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(svpwm_position_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &svpwm_position_B), 0,
                sizeof(B_svpwm_position_T));

  /* states (continuous) */
  {
    (void) memset((void *)&svpwm_position_X, 0,
                  sizeof(X_svpwm_position_T));
  }

  /* disabled states */
  {
    (void) memset((void *)&svpwm_position_XDis, 0,
                  sizeof(XDis_svpwm_position_T));
  }

  /* states (dwork) */
  (void) memset((void *)&svpwm_position_DW, 0,
                sizeof(DW_svpwm_position_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(svpwm_position_M->rtwLogInfo, 0.0,
    rtmGetTFinal(svpwm_position_M), svpwm_position_M->Timing.stepSize0,
    (&rtmGetErrorStatus(svpwm_position_M)));
  svpwm_position_PrevZCX.TriggeredSubsystem_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn3' */
  svpwm_position_X.TransferFcn3_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn' */
  svpwm_position_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn1' */
  svpwm_position_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S7>/Integral' */
  svpwm_position_X.Integral_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  svpwm_position_X.Integrator_CSTATE = svpwm_position_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<S9>/Integral' */
  svpwm_position_X.Integral_CSTATE_e = 0.0;

  /* InitializeConditions for TransferFcn: '<S11>/Transfer Fcn2' */
  svpwm_position_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S8>/Integral' */
  svpwm_position_X.Integral_CSTATE_f = 0.0;

  /* SystemInitialize for Triggered SubSystem: '<Root>/Triggered Subsystem' */
  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  svpwm_position_DW.UnitDelay_DSTATE =
    svpwm_position_P.UnitDelay_InitialCondition;

  /* SystemInitialize for Sum: '<S4>/Sum' incorporates:
   *  Outport: '<S4>/pulse'
   */
  svpwm_position_B.Sum_l = svpwm_position_P.pulse_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Triggered Subsystem' */

  /* SystemInitialize for MATLAB Function: '<Root>/S形加减速算法模型' */
  svpwm_position_DW.t0_not_empty = false;
  svpwm_position_DW.v0 = 0.0;
  svpwm_position_DW.a0 = 0.0;
  svpwm_position_DW.Tseg = 0.001;
}

/* Model terminate function */
void svpwm_position_terminate(void)
{
  /* (no terminate code required) */
}
