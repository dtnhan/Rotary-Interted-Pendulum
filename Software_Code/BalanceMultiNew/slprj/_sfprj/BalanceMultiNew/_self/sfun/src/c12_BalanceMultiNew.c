/* Include files */

#include <stddef.h>
#include "blas.h"
#include "BalanceMultiNew_sfun.h"
#include "c12_BalanceMultiNew.h"
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
static const char * c12_debug_family_names[4] = { "nargin", "nargout", "u", "y"
};

/* Function Declarations */
static void initialize_c12_BalanceMultiNew(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance);
static void initialize_params_c12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance);
static void enable_c12_BalanceMultiNew(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance);
static void disable_c12_BalanceMultiNew(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance);
static void c12_update_debugger_state_c12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance);
static void set_sim_state_c12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance, const mxArray *c12_st);
static void finalize_c12_BalanceMultiNew(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance);
static void sf_c12_BalanceMultiNew(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance);
static void initSimStructsc12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance);
static void registerMessagesc12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_emlrt_marshallIn(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c12_y, const char_T *c12_identifier);
static real_T c12_b_emlrt_marshallIn(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_c_emlrt_marshallIn(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_d_emlrt_marshallIn(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_BalanceMultiNew, const
  char_T *c12_identifier);
static uint8_T c12_e_emlrt_marshallIn(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c12_BalanceMultiNew(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c12_is_active_c12_BalanceMultiNew = 0U;
}

static void initialize_params_c12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance)
{
}

static void enable_c12_BalanceMultiNew(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_BalanceMultiNew(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  real_T c12_hoistedGlobal;
  real_T c12_u;
  const mxArray *c12_b_y = NULL;
  uint8_T c12_b_hoistedGlobal;
  uint8_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T *c12_d_y;
  c12_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(2), FALSE);
  c12_hoistedGlobal = *c12_d_y;
  c12_u = c12_hoistedGlobal;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_hoistedGlobal = chartInstance->c12_is_active_c12_BalanceMultiNew;
  c12_b_u = c12_b_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  sf_mex_assign(&c12_st, c12_y, FALSE);
  return c12_st;
}

static void set_sim_state_c12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  real_T *c12_y;
  c12_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  *c12_y = c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u,
    0)), "y");
  chartInstance->c12_is_active_c12_BalanceMultiNew = c12_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 1)),
     "is_active_c12_BalanceMultiNew");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_BalanceMultiNew(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_BalanceMultiNew(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance)
{
}

static void sf_c12_BalanceMultiNew(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance)
{
  real_T c12_hoistedGlobal;
  real_T c12_u;
  uint32_T c12_debug_family_var_map[4];
  real_T c12_nargin = 1.0;
  real_T c12_nargout = 1.0;
  real_T c12_y;
  real_T c12_x;
  real_T c12_b_x;
  real_T *c12_b_u;
  real_T *c12_b_y;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c12_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c12_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c12_b_y, 1U);
  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  c12_hoistedGlobal = *c12_b_u;
  c12_u = c12_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c12_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 0U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 1U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_u, 2U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_y, 3U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 3);
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  if (CV_EML_COND(0, 1, 0, 0.0 < c12_u)) {
    if (CV_EML_COND(0, 1, 1, c12_u < 0.5)) {
      guard2 = TRUE;
    } else {
      guard3 = TRUE;
    }
  } else {
    guard3 = TRUE;
  }

  if (guard3 == TRUE) {
    if (CV_EML_COND(0, 1, 2, 0.0 > c12_u)) {
      if (CV_EML_COND(0, 1, 3, c12_u > -0.5)) {
        guard2 = TRUE;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }
  }

  if (guard2 == TRUE) {
    CV_EML_MCDC(0, 1, 0, TRUE);
    CV_EML_IF(0, 1, 0, TRUE);
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 4);
    c12_x = c12_u;
    c12_y = c12_x;
    c12_b_x = c12_y;
    c12_y = c12_b_x;
    c12_y = muDoubleScalarAtan(c12_y);
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 6);
    c12_y = c12_u;
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  *c12_b_y = c12_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_BalanceMultiNewMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance)
{
}

static void registerMessagesc12_BalanceMultiNew
  (SFc12_BalanceMultiNewInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_BalanceMultiNewInstanceStruct *chartInstance;
  chartInstance = (SFc12_BalanceMultiNewInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_emlrt_marshallIn(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c12_y, const char_T *c12_identifier)
{
  real_T c12_b_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_y), &c12_thisId);
  sf_mex_destroy(&c12_y);
  return c12_b_y;
}

static real_T c12_b_emlrt_marshallIn(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_y;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_b_y;
  SFc12_BalanceMultiNewInstanceStruct *chartInstance;
  chartInstance = (SFc12_BalanceMultiNewInstanceStruct *)chartInstanceVoid;
  c12_y = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_y), &c12_thisId);
  sf_mex_destroy(&c12_y);
  *(real_T *)c12_outData = c12_b_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_BalanceMultiNew_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo;
  c12_ResolvedFunctionInfo c12_info[2];
  c12_ResolvedFunctionInfo (*c12_b_info)[2];
  const mxArray *c12_m0 = NULL;
  int32_T c12_i0;
  c12_ResolvedFunctionInfo *c12_r0;
  c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  c12_b_info = (c12_ResolvedFunctionInfo (*)[2])c12_info;
  (*c12_b_info)[0].context = "";
  (*c12_b_info)[0].name = "atan";
  (*c12_b_info)[0].dominantType = "double";
  (*c12_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  (*c12_b_info)[0].fileTimeLo = 1343812372U;
  (*c12_b_info)[0].fileTimeHi = 0U;
  (*c12_b_info)[0].mFileTimeLo = 0U;
  (*c12_b_info)[0].mFileTimeHi = 0U;
  (*c12_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m";
  (*c12_b_info)[1].name = "eml_scalar_atan";
  (*c12_b_info)[1].dominantType = "double";
  (*c12_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m";
  (*c12_b_info)[1].fileTimeLo = 1286800718U;
  (*c12_b_info)[1].fileTimeHi = 0U;
  (*c12_b_info)[1].mFileTimeLo = 0U;
  (*c12_b_info)[1].mFileTimeHi = 0U;
  sf_mex_assign(&c12_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2), FALSE);
  for (c12_i0 = 0; c12_i0 < 2; c12_i0++) {
    c12_r0 = &c12_info[c12_i0];
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->context)), "context", "nameCaptureInfo",
                    c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->name)), "name", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      c12_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->resolved)), "resolved",
                    "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c12_i0);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c12_i0);
  }

  sf_mex_assign(&c12_nameCaptureInfo, c12_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c12_nameCaptureInfo);
  return c12_nameCaptureInfo;
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_BalanceMultiNewInstanceStruct *chartInstance;
  chartInstance = (SFc12_BalanceMultiNewInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static int32_T c12_c_emlrt_marshallIn(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i1;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i1, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i1;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_BalanceMultiNewInstanceStruct *chartInstance;
  chartInstance = (SFc12_BalanceMultiNewInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_d_emlrt_marshallIn(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_BalanceMultiNew, const
  char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_BalanceMultiNew), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_BalanceMultiNew);
  return c12_y;
}

static uint8_T c12_e_emlrt_marshallIn(SFc12_BalanceMultiNewInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info(SFc12_BalanceMultiNewInstanceStruct
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

void sf_c12_BalanceMultiNew_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3152842252U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(751832233U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3746971053U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2278188679U);
}

mxArray *sf_c12_BalanceMultiNew_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("23h7edRmzdY1KMOgI3A3YG");
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

mxArray *sf_c12_BalanceMultiNew_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c12_BalanceMultiNew(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c12_BalanceMultiNew\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_BalanceMultiNew_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_BalanceMultiNewInstanceStruct *chartInstance;
    chartInstance = (SFc12_BalanceMultiNewInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _BalanceMultiNewMachineNumber_,
           12,
           1,
           1,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,100);
        _SFD_CV_INIT_EML_IF(0,1,0,30,69,85,100);

        {
          static int condStart[] = { 35, 42, 53, 60 };

          static int condEnd[] = { 38, 47, 56, 66 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,33,68,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);

        {
          real_T *c12_u;
          real_T *c12_y;
          c12_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c12_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c12_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c12_y);
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
  return "npBosZBwQ4Ix5PDfp4iWxF";
}

static void sf_opaque_initialize_c12_BalanceMultiNew(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_BalanceMultiNewInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c12_BalanceMultiNew((SFc12_BalanceMultiNewInstanceStruct*)
    chartInstanceVar);
  initialize_c12_BalanceMultiNew((SFc12_BalanceMultiNewInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c12_BalanceMultiNew(void *chartInstanceVar)
{
  enable_c12_BalanceMultiNew((SFc12_BalanceMultiNewInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c12_BalanceMultiNew(void *chartInstanceVar)
{
  disable_c12_BalanceMultiNew((SFc12_BalanceMultiNewInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c12_BalanceMultiNew(void *chartInstanceVar)
{
  sf_c12_BalanceMultiNew((SFc12_BalanceMultiNewInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_BalanceMultiNew(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_BalanceMultiNew
    ((SFc12_BalanceMultiNewInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_BalanceMultiNew();/* state var info */
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

extern void sf_internal_set_sim_state_c12_BalanceMultiNew(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_BalanceMultiNew();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_BalanceMultiNew((SFc12_BalanceMultiNewInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_BalanceMultiNew(SimStruct* S)
{
  return sf_internal_get_sim_state_c12_BalanceMultiNew(S);
}

static void sf_opaque_set_sim_state_c12_BalanceMultiNew(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c12_BalanceMultiNew(S, st);
}

static void sf_opaque_terminate_c12_BalanceMultiNew(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_BalanceMultiNewInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_BalanceMultiNew_optimization_info();
    }

    finalize_c12_BalanceMultiNew((SFc12_BalanceMultiNewInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_BalanceMultiNew((SFc12_BalanceMultiNewInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_BalanceMultiNew(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_BalanceMultiNew((SFc12_BalanceMultiNewInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_BalanceMultiNew(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_BalanceMultiNew_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,12,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1268593763U));
  ssSetChecksum1(S,(3043790797U));
  ssSetChecksum2(S,(2097780259U));
  ssSetChecksum3(S,(2748337335U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_BalanceMultiNew(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_BalanceMultiNew(SimStruct *S)
{
  SFc12_BalanceMultiNewInstanceStruct *chartInstance;
  chartInstance = (SFc12_BalanceMultiNewInstanceStruct *)utMalloc(sizeof
    (SFc12_BalanceMultiNewInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_BalanceMultiNewInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_BalanceMultiNew;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_BalanceMultiNew;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c12_BalanceMultiNew;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_BalanceMultiNew;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_BalanceMultiNew;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_BalanceMultiNew;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_BalanceMultiNew;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_BalanceMultiNew;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_BalanceMultiNew;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_BalanceMultiNew;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c12_BalanceMultiNew;
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

void c12_BalanceMultiNew_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_BalanceMultiNew(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_BalanceMultiNew(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_BalanceMultiNew(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_BalanceMultiNew_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
