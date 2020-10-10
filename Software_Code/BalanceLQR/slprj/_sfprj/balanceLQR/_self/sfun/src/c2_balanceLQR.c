/* Include files */

#include <stddef.h>
#include "blas.h"
#include "balanceLQR_sfun.h"
#include "c2_balanceLQR.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "balanceLQR_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[6] = { "voltage", "nargin", "nargout",
  "alpha", "alphadot", "u" };

/* Function Declarations */
static void initialize_c2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance);
static void initialize_params_c2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance);
static void enable_c2_balanceLQR(SFc2_balanceLQRInstanceStruct *chartInstance);
static void disable_c2_balanceLQR(SFc2_balanceLQRInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c2_balanceLQR(SFc2_balanceLQRInstanceStruct *
  chartInstance);
static void set_sim_state_c2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_balanceLQR(SFc2_balanceLQRInstanceStruct *chartInstance);
static void sf_c2_balanceLQR(SFc2_balanceLQRInstanceStruct *chartInstance);
static void initSimStructsc2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance);
static void registerMessagesc2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_balanceLQRInstanceStruct *chartInstance,
  const mxArray *c2_u, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_balanceLQRInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_balanceLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_balanceLQRInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_balanceLQR, const char_T
  *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_balanceLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_balanceLQRInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_balanceLQR = 0U;
}

static void initialize_params_c2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance)
{
}

static void enable_c2_balanceLQR(SFc2_balanceLQRInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_balanceLQR(SFc2_balanceLQRInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c2_balanceLQR(SFc2_balanceLQRInstanceStruct *
  chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_c_u;
  c2_c_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  c2_hoistedGlobal = *c2_c_u;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_balanceLQR;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_b_u;
  c2_b_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_b_u = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "u");
  chartInstance->c2_is_active_c2_balanceLQR = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_balanceLQR");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_balanceLQR(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_balanceLQR(SFc2_balanceLQRInstanceStruct *chartInstance)
{
}

static void sf_c2_balanceLQR(SFc2_balanceLQRInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_alpha;
  real_T c2_alphadot;
  uint32_T c2_debug_family_var_map[6];
  real_T c2_voltage;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  real_T c2_u;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_a;
  real_T c2_b;
  real_T c2_y;
  real_T *c2_b_u;
  real_T *c2_b_alpha;
  real_T *c2_b_alphadot;
  c2_b_alphadot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_alpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c2_b_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_alpha, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_alphadot, 2U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_alpha;
  c2_b_hoistedGlobal = *c2_b_alphadot;
  c2_alpha = c2_hoistedGlobal;
  c2_alphadot = c2_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_voltage, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_alpha, 3U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_alphadot, 4U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_u, 5U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  c2_voltage = 5.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_x = c2_alpha;
  c2_b_x = c2_x;
  c2_b_x = muDoubleScalarCos(c2_b_x);
  c2_a = c2_alphadot;
  c2_b = c2_b_x;
  c2_y = c2_a * c2_b;
  if (CV_EML_IF(0, 1, 0, c2_y < 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
    c2_u = -c2_voltage;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
    c2_u = c2_voltage;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_u = c2_u;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_balanceLQRMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc2_balanceLQR(SFc2_balanceLQRInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_balanceLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_balanceLQRInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_balanceLQRInstanceStruct *chartInstance,
  const mxArray *c2_u, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_u), &c2_thisId);
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_balanceLQRInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_u;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_balanceLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_balanceLQRInstanceStruct *)chartInstanceVoid;
  c2_u = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_u), &c2_thisId);
  sf_mex_destroy(&c2_u);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_balanceLQR_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[3];
  c2_ResolvedFunctionInfo (*c2_b_info)[3];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[3])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "cos";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c2_b_info)[0].fileTimeLo = 1343812372U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c2_b_info)[1].name = "eml_scalar_cos";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c2_b_info)[1].fileTimeLo = 1286800722U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context = "";
  (*c2_b_info)[2].name = "mtimes";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[2].fileTimeLo = 1289498092U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 3), FALSE);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_balanceLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_balanceLQRInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_balanceLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i1;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_balanceLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_balanceLQRInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_balanceLQRInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_balanceLQR, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_balanceLQR), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_balanceLQR);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_balanceLQRInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_balanceLQRInstanceStruct *chartInstance)
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

void sf_c2_balanceLQR_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(926334188U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(202332172U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1500197872U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(853006491U);
}

mxArray *sf_c2_balanceLQR_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("t22PANtdkHkLJH6ikblrHG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_balanceLQR_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_balanceLQR(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[4],T\"u\",},{M[8],M[0],T\"is_active_c2_balanceLQR\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_balanceLQR_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_balanceLQRInstanceStruct *chartInstance;
    chartInstance = (SFc2_balanceLQRInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _balanceLQRMachineNumber_,
           2,
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
          init_script_number_translation(_balanceLQRMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_balanceLQRMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _balanceLQRMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"u");
          _SFD_SET_DATA_PROPS(1,1,1,0,"alpha");
          _SFD_SET_DATA_PROPS(2,1,1,0,"alphadot");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",78,-1,778);
        _SFD_CV_INIT_EML_IF(0,1,0,157,183,740,763);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_u;
          real_T *c2_alpha;
          real_T *c2_alphadot;
          c2_alphadot = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_alpha = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c2_u = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_alpha);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_alphadot);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _balanceLQRMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "nJsQFzYlzgHuwGrdYnjSrB";
}

static void sf_opaque_initialize_c2_balanceLQR(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_balanceLQRInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c2_balanceLQR((SFc2_balanceLQRInstanceStruct*)
    chartInstanceVar);
  initialize_c2_balanceLQR((SFc2_balanceLQRInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_balanceLQR(void *chartInstanceVar)
{
  enable_c2_balanceLQR((SFc2_balanceLQRInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_balanceLQR(void *chartInstanceVar)
{
  disable_c2_balanceLQR((SFc2_balanceLQRInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_balanceLQR(void *chartInstanceVar)
{
  sf_c2_balanceLQR((SFc2_balanceLQRInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_balanceLQR(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_balanceLQR
    ((SFc2_balanceLQRInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_balanceLQR();/* state var info */
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

extern void sf_internal_set_sim_state_c2_balanceLQR(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_balanceLQR();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_balanceLQR((SFc2_balanceLQRInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_balanceLQR(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_balanceLQR(S);
}

static void sf_opaque_set_sim_state_c2_balanceLQR(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_balanceLQR(S, st);
}

static void sf_opaque_terminate_c2_balanceLQR(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_balanceLQRInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_balanceLQR_optimization_info();
    }

    finalize_c2_balanceLQR((SFc2_balanceLQRInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_balanceLQR((SFc2_balanceLQRInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_balanceLQR(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_balanceLQR((SFc2_balanceLQRInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_balanceLQR(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_balanceLQR_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(961897793U));
  ssSetChecksum1(S,(2116050684U));
  ssSetChecksum2(S,(2818072576U));
  ssSetChecksum3(S,(544040655U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_balanceLQR(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_balanceLQR(SimStruct *S)
{
  SFc2_balanceLQRInstanceStruct *chartInstance;
  chartInstance = (SFc2_balanceLQRInstanceStruct *)utMalloc(sizeof
    (SFc2_balanceLQRInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_balanceLQRInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_balanceLQR;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_balanceLQR;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_balanceLQR;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_balanceLQR;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_balanceLQR;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_balanceLQR;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_balanceLQR;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_balanceLQR;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_balanceLQR;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_balanceLQR;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_balanceLQR;
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

void c2_balanceLQR_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_balanceLQR(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_balanceLQR(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_balanceLQR(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_balanceLQR_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
