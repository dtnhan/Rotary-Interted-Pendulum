#ifndef __c4_balanceLQR_h__
#define __c4_balanceLQR_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc4_balanceLQRInstanceStruct
#define typedef_SFc4_balanceLQRInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_balanceLQR;
} SFc4_balanceLQRInstanceStruct;

#endif                                 /*typedef_SFc4_balanceLQRInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_balanceLQR_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_balanceLQR_get_check_sum(mxArray *plhs[]);
extern void c4_balanceLQR_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
