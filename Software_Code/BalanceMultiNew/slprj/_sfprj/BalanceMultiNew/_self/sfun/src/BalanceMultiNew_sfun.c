/* Include files */

#include "BalanceMultiNew_sfun.h"
#include "BalanceMultiNew_sfun_debug_macros.h"
#include "c1_BalanceMultiNew.h"
#include "c2_BalanceMultiNew.h"
#include "c3_BalanceMultiNew.h"
#include "c4_BalanceMultiNew.h"
#include "c5_BalanceMultiNew.h"
#include "c6_BalanceMultiNew.h"
#include "c7_BalanceMultiNew.h"
#include "c8_BalanceMultiNew.h"
#include "c9_BalanceMultiNew.h"
#include "c10_BalanceMultiNew.h"
#include "c11_BalanceMultiNew.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _BalanceMultiNewMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void BalanceMultiNew_initializer(void)
{
}

void BalanceMultiNew_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_BalanceMultiNew_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_BalanceMultiNew_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_BalanceMultiNew_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2334374669U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(260462881U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1698543381U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1250395365U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(245149552U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1730058501U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2237739074U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2402703670U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c1_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c2_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c3_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c4_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c5_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c6_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c7_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c8_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c9_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c10_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_BalanceMultiNew_get_check_sum(mxArray *plhs[]);
          sf_c11_BalanceMultiNew_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3548963729U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2792466983U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3260694609U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(971669281U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_BalanceMultiNew_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "CXe3Yg1zWUXI5lTFbxXgdF") == 0) {
          extern mxArray *sf_c1_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c1_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "yW6U0kUgZZEOToi5WFmoDH") == 0) {
          extern mxArray *sf_c2_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c2_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "gUr4pzL4ho0MK3VgJCbiQB") == 0) {
          extern mxArray *sf_c3_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c3_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "UuDYg5Gmp2jhJfzlXGqrX") == 0) {
          extern mxArray *sf_c4_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c4_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "jUKCTPSpEO0d20UJaf6ZhD") == 0) {
          extern mxArray *sf_c5_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c5_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "ynIGTcrb99a9CnXJUMSnXB") == 0) {
          extern mxArray *sf_c6_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c6_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "Nk47HruehN0ykXPNhzvIkD") == 0) {
          extern mxArray *sf_c7_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c7_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "t22PANtdkHkLJH6ikblrHG") == 0) {
          extern mxArray *sf_c8_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c8_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "pNvBCP5Z23TMCKwCkgICSD") == 0) {
          extern mxArray *sf_c9_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c9_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "Y2o7ucqrM2QOKf96Bhl7u") == 0) {
          extern mxArray *sf_c10_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c10_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "IlRsqRACA3q7hpZfX4v26C") == 0) {
          extern mxArray *sf_c11_BalanceMultiNew_get_autoinheritance_info(void);
          plhs[0] = sf_c11_BalanceMultiNew_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_BalanceMultiNew_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_BalanceMultiNew_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_BalanceMultiNew_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_BalanceMultiNew_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "5fkbBgHjWMVlZzj53hX5UB") == 0) {
          extern mxArray *sf_c1_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c1_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "RRmahpfEexwD101FI4fuWC") == 0) {
          extern mxArray *sf_c2_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c2_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "Zx2bAGpvSbHmTFzNd2rFzD") == 0) {
          extern mxArray *sf_c3_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c3_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "L2lzATG6dIcMyo3Eh2lwlC") == 0) {
          extern mxArray *sf_c4_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c4_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "K4iROfYjVqscoxihJjhhPC") == 0) {
          extern mxArray *sf_c5_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c5_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "s8tuCt9rDBKfQIfehhJF0D") == 0) {
          extern mxArray *sf_c6_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c6_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "BZKXTx1GaUBmsXGSHx0jOH") == 0) {
          extern mxArray *sf_c7_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c7_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "nJsQFzYlzgHuwGrdYnjSrB") == 0) {
          extern mxArray *sf_c8_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c8_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "asMPZKcirhBxkw0j5KTc3C") == 0) {
          extern mxArray *sf_c9_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c9_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "WZDbMlam95uSCTu7UOm17G") == 0) {
          extern mxArray *sf_c10_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c10_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "b5UP3KaeOV6P9U3ZeDO8N") == 0) {
          extern mxArray *sf_c11_BalanceMultiNew_third_party_uses_info(void);
          plhs[0] = sf_c11_BalanceMultiNew_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void BalanceMultiNew_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _BalanceMultiNewMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "BalanceMultiNew","sfun",0,11,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _BalanceMultiNewMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _BalanceMultiNewMachineNumber_,0);
}

void BalanceMultiNew_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_BalanceMultiNew_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("BalanceMultiNew",
      "BalanceMultiNew");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_BalanceMultiNew_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
