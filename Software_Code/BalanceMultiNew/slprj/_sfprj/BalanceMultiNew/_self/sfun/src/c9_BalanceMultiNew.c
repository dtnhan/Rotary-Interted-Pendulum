/* Include files */

#include <stddef.h>
#include "blas.h"
#include "BalanceMultiNew_sfun.h"
#include "c9_BalanceMultiNew.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "BalanceMultiNew_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[5] = { "nargin", "nargout",
  "pulsealpha", "alphadisplay", "alpha" };

/* Function Declarations */
static void initialize_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance);
static void initialize_params_c9_BalanceMultiNew
  (SFc9_BalanceMultiNewInstanceStruct *chartInstance);
static void enable_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance);
static void disable_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_BalanceMultiNew
  (SFc9_BalanceMultiNewInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_BalanceMultiNew
  (SFc9_BalanceMultiNewInstanceStruct *chartInstance);
static void set_sim_state_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct *
  chartInstance, const mxArray *c9_st);
static void finalize_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance);
static void sf_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance);
static void initSimStructsc9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct *
  chartInstance);
static void registerMessagesc9_BalanceMultiNew
  (SFc9_BalanceMultiNewInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c9_alpha, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[17]);
static void c9_eml_scalar_eg(SFc9_BalanceMultiNewInstanceStruct *chartInstance);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_c_emlrt_marshallIn(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_d_emlrt_marshallIn(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_BalanceMultiNew, const char_T
  *c9_identifier);
static uint8_T c9_e_emlrt_marshallIn(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_BalanceMultiNew = 0U;
}

static void initialize_params_c9_BalanceMultiNew
  (SFc9_BalanceMultiNewInstanceStruct *chartInstance)
{
}

static void enable_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_BalanceMultiNew
  (SFc9_BalanceMultiNewInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_BalanceMultiNew
  (SFc9_BalanceMultiNewInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  uint8_T c9_c_hoistedGlobal;
  uint8_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  real_T *c9_alpha;
  real_T *c9_alphadisplay;
  c9_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_alphadisplay = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(3), FALSE);
  c9_hoistedGlobal = *c9_alpha;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *c9_alphadisplay;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = chartInstance->c9_is_active_c9_BalanceMultiNew;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct *
  chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T *c9_alpha;
  real_T *c9_alphadisplay;
  c9_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_alphadisplay = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  *c9_alpha = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u,
    0)), "alpha");
  *c9_alphadisplay = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 1)), "alphadisplay");
  chartInstance->c9_is_active_c9_BalanceMultiNew = c9_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)),
     "is_active_c9_BalanceMultiNew");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_BalanceMultiNew(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance)
{
}

static void sf_c9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_pulsealpha;
  uint32_T c9_debug_family_var_map[5];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 2.0;
  real_T c9_alphadisplay;
  real_T c9_alpha;
  real_T c9_a;
  real_T c9_y;
  real_T c9_b_a;
  real_T c9_b_y;
  real_T c9_A;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_c_y;
  real_T c9_c_x;
  real_T c9_xk;
  real_T c9_d_x;
  real_T c9_r;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_d_y;
  real_T c9_h_x;
  real_T c9_e_y;
  real_T c9_b;
  real_T c9_f_y;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T *c9_b_alpha;
  real_T *c9_b_alphadisplay;
  real_T *c9_b_pulsealpha;
  c9_b_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_alphadisplay = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_pulsealpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c9_b_pulsealpha, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_b_alphadisplay, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_b_alpha, 2U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = *c9_b_pulsealpha;
  c9_pulsealpha = c9_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_pulsealpha, 2U, c9_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_alphadisplay, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_alpha, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  c9_a = c9_pulsealpha;
  c9_y = c9_a * 2.0;
  c9_b_a = c9_y;
  c9_b_y = c9_b_a * 3.1415926535897931;
  c9_A = c9_b_y;
  c9_x = c9_A;
  c9_b_x = c9_x;
  c9_c_y = c9_b_x / 4096.0;
  c9_alphadisplay = c9_c_y + 3.1415926535897931;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_c_x = c9_alphadisplay - 3.1415926535897931;
  c9_eml_scalar_eg(chartInstance);
  c9_xk = c9_c_x;
  c9_d_x = c9_xk;
  c9_eml_scalar_eg(chartInstance);
  c9_r = c9_d_x / 6.2831853071795862;
  c9_e_x = c9_r;
  c9_f_x = c9_e_x;
  c9_f_x = muDoubleScalarRound(c9_f_x);
  c9_g_x = c9_r - c9_f_x;
  c9_d_y = muDoubleScalarAbs(c9_g_x);
  c9_h_x = c9_r;
  c9_e_y = muDoubleScalarAbs(c9_h_x);
  c9_b = c9_e_y;
  c9_f_y = 2.2204460492503131E-16 * c9_b;
  if (c9_d_y <= c9_f_y) {
    c9_r = 0.0;
  } else {
    c9_i_x = c9_r;
    c9_j_x = c9_i_x;
    c9_j_x = muDoubleScalarFloor(c9_j_x);
    c9_r = (c9_r - c9_j_x) * 6.2831853071795862;
  }

  c9_alpha = c9_r - 3.1415926535897931;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *c9_b_alphadisplay = c9_alphadisplay;
  *c9_b_alpha = c9_alpha;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_BalanceMultiNewMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc9_BalanceMultiNew(SFc9_BalanceMultiNewInstanceStruct *
  chartInstance)
{
}

static void registerMessagesc9_BalanceMultiNew
  (SFc9_BalanceMultiNewInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_BalanceMultiNewInstanceStruct *chartInstance;
  chartInstance = (SFc9_BalanceMultiNewInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c9_alpha, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_alpha), &c9_thisId);
  sf_mex_destroy(&c9_alpha);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_alpha;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_BalanceMultiNewInstanceStruct *chartInstance;
  chartInstance = (SFc9_BalanceMultiNewInstanceStruct *)chartInstanceVoid;
  c9_alpha = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_alpha), &c9_thisId);
  sf_mex_destroy(&c9_alpha);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_BalanceMultiNew_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[17];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i0;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 17), FALSE);
  for (c9_i0 = 0; c9_i0 < 17; c9_i0++) {
    c9_r0 = &c9_info[c9_i0];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i0);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[17])
{
  c9_info[0].context = "";
  c9_info[0].name = "mtimes";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[0].fileTimeLo = 1289498092U;
  c9_info[0].fileTimeHi = 0U;
  c9_info[0].mFileTimeLo = 0U;
  c9_info[0].mFileTimeHi = 0U;
  c9_info[1].context = "";
  c9_info[1].name = "mrdivide";
  c9_info[1].dominantType = "double";
  c9_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c9_info[1].fileTimeLo = 1357929948U;
  c9_info[1].fileTimeHi = 0U;
  c9_info[1].mFileTimeLo = 1319711966U;
  c9_info[1].mFileTimeHi = 0U;
  c9_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c9_info[2].name = "rdivide";
  c9_info[2].dominantType = "double";
  c9_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[2].fileTimeLo = 1346492388U;
  c9_info[2].fileTimeHi = 0U;
  c9_info[2].mFileTimeLo = 0U;
  c9_info[2].mFileTimeHi = 0U;
  c9_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[3].name = "eml_scalexp_compatible";
  c9_info[3].dominantType = "double";
  c9_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c9_info[3].fileTimeLo = 1286800796U;
  c9_info[3].fileTimeHi = 0U;
  c9_info[3].mFileTimeLo = 0U;
  c9_info[3].mFileTimeHi = 0U;
  c9_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[4].name = "eml_div";
  c9_info[4].dominantType = "double";
  c9_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c9_info[4].fileTimeLo = 1313329810U;
  c9_info[4].fileTimeHi = 0U;
  c9_info[4].mFileTimeLo = 0U;
  c9_info[4].mFileTimeHi = 0U;
  c9_info[5].context = "";
  c9_info[5].name = "mod";
  c9_info[5].dominantType = "double";
  c9_info[5].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c9_info[5].fileTimeLo = 1343812382U;
  c9_info[5].fileTimeHi = 0U;
  c9_info[5].mFileTimeLo = 0U;
  c9_info[5].mFileTimeHi = 0U;
  c9_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c9_info[6].name = "eml_scalar_eg";
  c9_info[6].dominantType = "double";
  c9_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[6].fileTimeLo = 1286800796U;
  c9_info[6].fileTimeHi = 0U;
  c9_info[6].mFileTimeLo = 0U;
  c9_info[6].mFileTimeHi = 0U;
  c9_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c9_info[7].name = "eml_scalexp_alloc";
  c9_info[7].dominantType = "double";
  c9_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[7].fileTimeLo = 1352403260U;
  c9_info[7].fileTimeHi = 0U;
  c9_info[7].mFileTimeLo = 0U;
  c9_info[7].mFileTimeHi = 0U;
  c9_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c9_info[8].name = "eml_scalar_eg";
  c9_info[8].dominantType = "double";
  c9_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[8].fileTimeLo = 1286800796U;
  c9_info[8].fileTimeHi = 0U;
  c9_info[8].mFileTimeLo = 0U;
  c9_info[8].mFileTimeHi = 0U;
  c9_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c9_info[9].name = "eml_scalar_floor";
  c9_info[9].dominantType = "double";
  c9_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c9_info[9].fileTimeLo = 1286800726U;
  c9_info[9].fileTimeHi = 0U;
  c9_info[9].mFileTimeLo = 0U;
  c9_info[9].mFileTimeHi = 0U;
  c9_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c9_info[10].name = "eml_scalar_round";
  c9_info[10].dominantType = "double";
  c9_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c9_info[10].fileTimeLo = 1307633238U;
  c9_info[10].fileTimeHi = 0U;
  c9_info[10].mFileTimeLo = 0U;
  c9_info[10].mFileTimeHi = 0U;
  c9_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c9_info[11].name = "eml_scalar_abs";
  c9_info[11].dominantType = "double";
  c9_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c9_info[11].fileTimeLo = 1286800712U;
  c9_info[11].fileTimeHi = 0U;
  c9_info[11].mFileTimeLo = 0U;
  c9_info[11].mFileTimeHi = 0U;
  c9_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c9_info[12].name = "eps";
  c9_info[12].dominantType = "char";
  c9_info[12].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c9_info[12].fileTimeLo = 1326706396U;
  c9_info[12].fileTimeHi = 0U;
  c9_info[12].mFileTimeLo = 0U;
  c9_info[12].mFileTimeHi = 0U;
  c9_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c9_info[13].name = "eml_is_float_class";
  c9_info[13].dominantType = "char";
  c9_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c9_info[13].fileTimeLo = 1286800782U;
  c9_info[13].fileTimeHi = 0U;
  c9_info[13].mFileTimeLo = 0U;
  c9_info[13].mFileTimeHi = 0U;
  c9_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c9_info[14].name = "eml_eps";
  c9_info[14].dominantType = "char";
  c9_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c9_info[14].fileTimeLo = 1326706396U;
  c9_info[14].fileTimeHi = 0U;
  c9_info[14].mFileTimeLo = 0U;
  c9_info[14].mFileTimeHi = 0U;
  c9_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c9_info[15].name = "eml_float_model";
  c9_info[15].dominantType = "char";
  c9_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c9_info[15].fileTimeLo = 1326706396U;
  c9_info[15].fileTimeHi = 0U;
  c9_info[15].mFileTimeLo = 0U;
  c9_info[15].mFileTimeHi = 0U;
  c9_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c9_info[16].name = "mtimes";
  c9_info[16].dominantType = "double";
  c9_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[16].fileTimeLo = 1289498092U;
  c9_info[16].fileTimeHi = 0U;
  c9_info[16].mFileTimeLo = 0U;
  c9_info[16].mFileTimeHi = 0U;
}

static void c9_eml_scalar_eg(SFc9_BalanceMultiNewInstanceStruct *chartInstance)
{
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_BalanceMultiNewInstanceStruct *chartInstance;
  chartInstance = (SFc9_BalanceMultiNewInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_c_emlrt_marshallIn(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i1;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i1, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i1;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_BalanceMultiNewInstanceStruct *chartInstance;
  chartInstance = (SFc9_BalanceMultiNewInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_d_emlrt_marshallIn(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_BalanceMultiNew, const char_T
  *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_BalanceMultiNew), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_BalanceMultiNew);
  return c9_y;
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_BalanceMultiNewInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c9_BalanceMultiNew_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2681354045U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1870894405U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3524651024U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(944315054U);
}

mxArray *sf_c9_BalanceMultiNew_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("pNvBCP5Z23TMCKwCkgICSD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_BalanceMultiNew_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c9_BalanceMultiNew(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"alpha\",},{M[1],M[5],T\"alphadisplay\",},{M[8],M[0],T\"is_active_c9_BalanceMultiNew\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_BalanceMultiNew_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_BalanceMultiNewInstanceStruct *chartInstance;
    chartInstance = (SFc9_BalanceMultiNewInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _BalanceMultiNewMachineNumber_,
           9,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_BalanceMultiNewMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_BalanceMultiNewMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _BalanceMultiNewMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"pulsealpha");
          _SFD_SET_DATA_PROPS(1,2,0,1,"alphadisplay");
          _SFD_SET_DATA_PROPS(2,2,0,1,"alpha");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,146);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);

        {
          real_T *c9_pulsealpha;
          real_T *c9_alphadisplay;
          real_T *c9_alpha;
          c9_alpha = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_alphadisplay = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c9_pulsealpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_pulsealpha);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_alphadisplay);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_alpha);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _BalanceMultiNewMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "asMPZKcirhBxkw0j5KTc3C";
}

static void sf_opaque_initialize_c9_BalanceMultiNew(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_BalanceMultiNewInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_BalanceMultiNew((SFc9_BalanceMultiNewInstanceStruct*)
    chartInstanceVar);
  initialize_c9_BalanceMultiNew((SFc9_BalanceMultiNewInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_BalanceMultiNew(void *chartInstanceVar)
{
  enable_c9_BalanceMultiNew((SFc9_BalanceMultiNewInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_BalanceMultiNew(void *chartInstanceVar)
{
  disable_c9_BalanceMultiNew((SFc9_BalanceMultiNewInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_BalanceMultiNew(void *chartInstanceVar)
{
  sf_c9_BalanceMultiNew((SFc9_BalanceMultiNewInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_BalanceMultiNew(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_BalanceMultiNew
    ((SFc9_BalanceMultiNewInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_BalanceMultiNew();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c9_BalanceMultiNew(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_BalanceMultiNew();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_BalanceMultiNew((SFc9_BalanceMultiNewInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_BalanceMultiNew(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_BalanceMultiNew(S);
}

static void sf_opaque_set_sim_state_c9_BalanceMultiNew(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_BalanceMultiNew(S, st);
}

static void sf_opaque_terminate_c9_BalanceMultiNew(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_BalanceMultiNewInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_BalanceMultiNew_optimization_info();
    }

    finalize_c9_BalanceMultiNew((SFc9_BalanceMultiNewInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_BalanceMultiNew((SFc9_BalanceMultiNewInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_BalanceMultiNew(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_BalanceMultiNew((SFc9_BalanceMultiNewInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_BalanceMultiNew(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BalanceMultiNew_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1639583988U));
  ssSetChecksum1(S,(876989418U));
  ssSetChecksum2(S,(3032395210U));
  ssSetChecksum3(S,(4062265943U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_BalanceMultiNew(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_BalanceMultiNew(SimStruct *S)
{
  SFc9_BalanceMultiNewInstanceStruct *chartInstance;
  chartInstance = (SFc9_BalanceMultiNewInstanceStruct *)utMalloc(sizeof
    (SFc9_BalanceMultiNewInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_BalanceMultiNewInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_BalanceMultiNew;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_BalanceMultiNew;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_BalanceMultiNew;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_BalanceMultiNew;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_BalanceMultiNew;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_BalanceMultiNew;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_BalanceMultiNew;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_BalanceMultiNew;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_BalanceMultiNew;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_BalanceMultiNew;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_BalanceMultiNew;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c9_BalanceMultiNew_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_BalanceMultiNew(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_BalanceMultiNew(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_BalanceMultiNew(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_BalanceMultiNew_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
