#ifndef __c11_BalanceMultiNew_h__
#define __c11_BalanceMultiNew_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c11_ResolvedFunctionInfo
#define typedef_c11_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c11_ResolvedFunctionInfo;

#endif                                 /*typedef_c11_ResolvedFunctionInfo*/

#ifndef typedef_SFc11_BalanceMultiNewInstanceStruct
#define typedef_SFc11_BalanceMultiNewInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_isStable;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_BalanceMultiNew;
} SFc11_BalanceMultiNewInstanceStruct;

#endif                                 /*typedef_SFc11_BalanceMultiNewInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_BalanceMultiNew_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c11_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
extern void c11_BalanceMultiNew_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
