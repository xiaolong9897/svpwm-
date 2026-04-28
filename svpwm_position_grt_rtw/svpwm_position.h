/*
 * svpwm_position.h
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

#ifndef svpwm_position_h_
#define svpwm_position_h_
#ifndef svpwm_position_COMMON_INCLUDES_
#define svpwm_position_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* svpwm_position_COMMON_INCLUDES_ */

#include "svpwm_position_types.h"
#include "rt_zcfcn.h"
#include "rtGetNaN.h"
#include <float.h>
#include <string.h>
#include <stddef.h>
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
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

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
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

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
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

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T TransferFcn3;                 /* '<S11>/Transfer Fcn3' */
  real_T Mod1;                         /* '<Root>/Mod1' */
  real_T Gain2;                        /* '<S19>/Gain2' */
  real_T Gain6;                        /* '<S19>/Gain6' */
  real_T Gain7;                        /* '<S19>/Gain7' */
  real_T Gain;                         /* '<S5>/Gain' */
  real_T Gain1;                        /* '<S5>/Gain1' */
  real_T Gain_l;                       /* '<S10>/Gain' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Saturation;                   /* '<S7>/Saturation' */
  real_T u;                            /* '<Root>/Integrator' */
  real_T theta;                        /* '<Root>/Gain3' */
  real_T u_m;                          /* '<Root>/Sum3' */
  real_T Saturation_a;                 /* '<S9>/Saturation' */
  real_T TransferFcn2;                 /* '<S11>/Transfer Fcn2' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Gain1_f;                      /* '<S10>/Gain1' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Saturation_b;                 /* '<S8>/Saturation' */
  real_T Ualpha;                       /* '<Root>/Ualpha' */
  real_T Ubeta;                        /* '<Root>/Ubeta' */
  real_T Mod;                          /* '<Root>/Mod' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T LookUpTable1;                 /* '<S2>/Look-Up Table1' */
  real_T Add3;                         /* '<S11>/Add3' */
  real_T Gain_h;                       /* '<S11>/Gain' */
  real_T Gain_j;                       /* '<Root>/Gain' */
  real_T Gain2_i;                      /* '<Root>/Gain2' */
  real_T Gain1_k;                      /* '<S6>/Gain1' */
  real_T Gain2_p;                      /* '<S6>/Gain2' */
  real_T Gain3;                        /* '<S6>/Gain3' */
  real_T Multiply7;                    /* '<S11>/Multiply7' */
  real_T Multiply2;                    /* '<S11>/Multiply2' */
  real_T Multiply5;                    /* '<S11>/Multiply5' */
  real_T Multiply8;                    /* '<S11>/Multiply8' */
  real_T startTime;                    /* '<S12>/startTime' */
  real_T Ta;                           /* '<Root>/矢量作用时间计算' */
  real_T Tb;                           /* '<Root>/矢量作用时间计算' */
  real_T N;                            /* '<Root>/扇区判断' */
  real_T CH1;                          /* '<Root>/六步开关的控制' */
  real_T CH1N;                         /* '<Root>/六步开关的控制' */
  real_T CH2;                          /* '<Root>/六步开关的控制' */
  real_T CH2N;                         /* '<Root>/六步开关的控制' */
  real_T CH3;                          /* '<Root>/六步开关的控制' */
  real_T CH3N;                         /* '<Root>/六步开关的控制' */
  real_T Sum_l;                        /* '<S4>/Sum' */
  real_T w_ref;                        /* '<Root>/S形加减速算法模型' */
  real_T CCR1;                         /* '<Root>/CCR值计算' */
  real_T CCR2;                         /* '<Root>/CCR值计算' */
  real_T CCR3;                         /* '<Root>/CCR值计算' */
  real_T value1;                       /* '<Root>/CCR值计算' */
  real_T value2;                       /* '<Root>/CCR值计算' */
  real_T value3;                       /* '<Root>/CCR值计算' */
} B_svpwm_position_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S4>/Unit Delay' */
  real_T v0;                           /* '<Root>/S形加减速算法模型' */
  real_T a0;                           /* '<Root>/S形加减速算法模型' */
  real_T qf;                           /* '<Root>/S形加减速算法模型' */
  real_T t0;                           /* '<Root>/S形加减速算法模型' */
  real_T Tseg;                         /* '<Root>/S形加减速算法模型' */
  real_T c0;                           /* '<Root>/S形加减速算法模型' */
  real_T c1;                           /* '<Root>/S形加减速算法模型' */
  real_T c2;                           /* '<Root>/S形加减速算法模型' */
  real_T c3;                           /* '<Root>/S形加减速算法模型' */
  real_T c4;                           /* '<Root>/S形加减速算法模型' */
  real_T c5;                           /* '<Root>/S形加减速算法模型' */
  boolean_T t0_not_empty;              /* '<Root>/S形加减速算法模型' */
} DW_svpwm_position_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn3_CSTATE;          /* '<S11>/Transfer Fcn3' */
  real_T TransferFcn_CSTATE;           /* '<S11>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S11>/Transfer Fcn1' */
  real_T Integral_CSTATE;              /* '<S7>/Integral' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integral_CSTATE_e;            /* '<S9>/Integral' */
  real_T TransferFcn2_CSTATE;          /* '<S11>/Transfer Fcn2' */
  real_T Integral_CSTATE_f;            /* '<S8>/Integral' */
} X_svpwm_position_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn3_CSTATE;          /* '<S11>/Transfer Fcn3' */
  real_T TransferFcn_CSTATE;           /* '<S11>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S11>/Transfer Fcn1' */
  real_T Integral_CSTATE;              /* '<S7>/Integral' */
  real_T Integrator_CSTATE;            /* '<Root>/Integrator' */
  real_T Integral_CSTATE_e;            /* '<S9>/Integral' */
  real_T TransferFcn2_CSTATE;          /* '<S11>/Transfer Fcn2' */
  real_T Integral_CSTATE_f;            /* '<S8>/Integral' */
} XDot_svpwm_position_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn3_CSTATE;       /* '<S11>/Transfer Fcn3' */
  boolean_T TransferFcn_CSTATE;        /* '<S11>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE;       /* '<S11>/Transfer Fcn1' */
  boolean_T Integral_CSTATE;           /* '<S7>/Integral' */
  boolean_T Integrator_CSTATE;         /* '<Root>/Integrator' */
  boolean_T Integral_CSTATE_e;         /* '<S9>/Integral' */
  boolean_T TransferFcn2_CSTATE;       /* '<S11>/Transfer Fcn2' */
  boolean_T Integral_CSTATE_f;         /* '<S8>/Integral' */
} XDis_svpwm_position_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<Root>/Triggered Subsystem' */
} PrevZCX_svpwm_position_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_svpwm_position_T_ {
  real_T pmsm1_CL;                     /* Mask Parameter: pmsm1_CL
                                        * Referenced by:
                                        *   '<S11>/Constant'
                                        *   '<S11>/Constant6'
                                        */
  real_T pmsm1_J;                      /* Mask Parameter: pmsm1_J
                                        * Referenced by: '<S11>/Constant8'
                                        */
  real_T pmsm1_Ld;                     /* Mask Parameter: pmsm1_Ld
                                        * Referenced by:
                                        *   '<S11>/Constant1'
                                        *   '<S11>/Constant5'
                                        */
  real_T pmsm1_Lq;                     /* Mask Parameter: pmsm1_Lq
                                        * Referenced by:
                                        *   '<S11>/Constant2'
                                        *   '<S11>/Constant7'
                                        */
  real_T iqref1_P;                     /* Mask Parameter: iqref1_P
                                        * Referenced by: '<S7>/Proportional'
                                        */
  real_T iqref3_P;                     /* Mask Parameter: iqref3_P
                                        * Referenced by: '<S9>/Proportional'
                                        */
  real_T iqref2_P;                     /* Mask Parameter: iqref2_P
                                        * Referenced by: '<S8>/Proportional'
                                        */
  real_T pmsm1_Pm;                     /* Mask Parameter: pmsm1_Pm
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T RepeatingSequence_rep_seq_y[3];
                                  /* Mask Parameter: RepeatingSequence_rep_seq_y
                                   * Referenced by: '<S2>/Look-Up Table1'
                                   */
  real_T pmsm1_rs;                     /* Mask Parameter: pmsm1_rs
                                        * Referenced by: '<S11>/Constant4'
                                        */
  real_T pulse_Y0;                     /* Computed Parameter: pulse_Y0
                                        * Referenced by: '<S4>/pulse'
                                        */
  real_T Constant_Value;               /* Expression: 100
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 10
                                        * Referenced by: '<S4>/Unit Delay'
                                        */
  real_T d_Value;                      /* Expression: 0
                                        * Referenced by: '<Root>/d'
                                        */
  real_T TransferFcn3_A;               /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<S11>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C;               /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<S11>/Transfer Fcn3'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Constant2_Value;              /* Expression: pi*2
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S11>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S11>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S11>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S11>/Transfer Fcn1'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S20>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: sqrt(2/3)
                                        * Referenced by: '<S19>/Gain2'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: -1/2
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T Gain3_Gain;                   /* Expression: sqrt(3)/2
                                        * Referenced by: '<S19>/Gain3'
                                        */
  real_T Gain6_Gain;                   /* Expression: sqrt(2/3)
                                        * Referenced by: '<S19>/Gain6'
                                        */
  real_T Gain_Gain_e;                  /* Expression: -1/2
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: -sqrt(3)/2
                                        * Referenced by: '<S19>/Gain4'
                                        */
  real_T Gain7_Gain;                   /* Expression: sqrt(2/3)
                                        * Referenced by: '<S19>/Gain7'
                                        */
  real_T Gain_Gain_i;                  /* Expression: sqrt(3/2)
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: sqrt(2)/2
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 1
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Integral_A;                   /* Computed Parameter: Integral_A
                                        * Referenced by: '<S7>/Integral'
                                        */
  real_T Integral_C;                   /* Computed Parameter: Integral_C
                                        * Referenced by: '<S7>/Integral'
                                        */
  real_T Saturation_UpperSat;          /* Expression: max
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: min
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  real_T Gain3_Gain_i;                 /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Integral_A_k;                 /* Computed Parameter: Integral_A_k
                                        * Referenced by: '<S9>/Integral'
                                        */
  real_T Integral_C_o;                 /* Computed Parameter: Integral_C_o
                                        * Referenced by: '<S9>/Integral'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: max
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: min
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S11>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S11>/Transfer Fcn2'
                                        */
  real_T Gain1_Gain_es;                /* Expression: 1
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Integral_A_kv;                /* Computed Parameter: Integral_A_kv
                                        * Referenced by: '<S8>/Integral'
                                        */
  real_T Integral_C_g;                 /* Computed Parameter: Integral_C_g
                                        * Referenced by: '<S8>/Integral'
                                        */
  real_T Saturation_UpperSat_db;       /* Expression: max
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: min
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Constant1_Value;              /* Expression: pi*2
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant6_Value;              /* Expression: -1
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: -1
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant10_Value;             /* Expression: 100
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Constant7_Value;              /* Expression: 100
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T Constant9_Value;              /* Expression: 3000
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T _Value;                       /* Expression: 24
                                        * Referenced by: '<Root>/线电压'
                                        */
  real_T PWM_Value;                    /* Expression: 8400
                                        * Referenced by: '<Root>/PWM周期'
                                        */
  real_T Constant_Value_f;             /* Expression: period
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T LookUpTable1_bp01Data[3];     /* Expression: rep_seq_t - min(rep_seq_t)
                                        * Referenced by: '<S2>/Look-Up Table1'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 3/2
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 180/pi
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: sqrt(2/3)
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: sqrt(2/3)
                                        * Referenced by: '<S6>/Gain2'
                                        */
  real_T Gain3_Gain_b;                 /* Expression: sqrt(2/3)
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T Constant3_Value;              /* Expression: 1.0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain_Gain_h;                  /* Expression: -1/2
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: -1/2
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real_T Gain4_Gain_d;                 /* Expression: sqrt(2/3)
                                        * Referenced by: '<S17>/Gain4'
                                        */
  real_T Gain_Gain_cd;                 /* Expression: -1
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: sqrt(3)/2
                                        * Referenced by: '<S17>/Gain2'
                                        */
  real_T Gain3_Gain_n;                 /* Expression: -sqrt(3)/2
                                        * Referenced by: '<S17>/Gain3'
                                        */
  real_T Gain5_Gain;                   /* Expression: sqrt(2/3)
                                        * Referenced by: '<S17>/Gain5'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_svpwm_position_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_svpwm_position_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_svpwm_position_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[8];
  real_T odeF[3][8];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_svpwm_position_T svpwm_position_P;

/* Block signals (default storage) */
extern B_svpwm_position_T svpwm_position_B;

/* Continuous states (default storage) */
extern X_svpwm_position_T svpwm_position_X;

/* Disabled states (default storage) */
extern XDis_svpwm_position_T svpwm_position_XDis;

/* Block states (default storage) */
extern DW_svpwm_position_T svpwm_position_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_svpwm_position_T svpwm_position_PrevZCX;

/* Model entry point functions */
extern void svpwm_position_initialize(void);
extern void svpwm_position_step(void);
extern void svpwm_position_terminate(void);

/* Real-time Model object */
extern RT_MODEL_svpwm_position_T *const svpwm_position_M;

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
 * '<Root>' : 'svpwm_position'
 * '<S1>'   : 'svpwm_position/CCR值计算'
 * '<S2>'   : 'svpwm_position/Repeating Sequence'
 * '<S3>'   : 'svpwm_position/S形加减速算法模型'
 * '<S4>'   : 'svpwm_position/Triggered Subsystem'
 * '<S5>'   : 'svpwm_position/clarke'
 * '<S6>'   : 'svpwm_position/clarke_inv1'
 * '<S7>'   : 'svpwm_position/iqref1'
 * '<S8>'   : 'svpwm_position/iqref2'
 * '<S9>'   : 'svpwm_position/iqref3'
 * '<S10>'  : 'svpwm_position/park'
 * '<S11>'  : 'svpwm_position/pmsm1'
 * '<S12>'  : 'svpwm_position/theta '
 * '<S13>'  : 'svpwm_position/六步开关的控制'
 * '<S14>'  : 'svpwm_position/扇区判断'
 * '<S15>'  : 'svpwm_position/矢量作用时间计算'
 * '<S16>'  : 'svpwm_position/Triggered Subsystem/MATLAB Function'
 * '<S17>'  : 'svpwm_position/pmsm1/Subsystem2'
 * '<S18>'  : 'svpwm_position/pmsm1/Subsystem3'
 * '<S19>'  : 'svpwm_position/pmsm1/Subsystem4'
 * '<S20>'  : 'svpwm_position/pmsm1/Subsystem5'
 */
#endif                                 /* svpwm_position_h_ */
