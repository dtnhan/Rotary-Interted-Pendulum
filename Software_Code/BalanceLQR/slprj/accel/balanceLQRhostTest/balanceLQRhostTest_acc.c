#include "__cf_balanceLQRhostTest.h"
#include <math.h>
#include "balanceLQRhostTest_acc.h"
#include "balanceLQRhostTest_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { B_balanceLQRhostTest_T
* _rtB ; P_balanceLQRhostTest_T * _rtP ; _rtP = ( ( P_balanceLQRhostTest_T *
) ssGetDefaultParam ( S ) ) ; _rtB = ( ( B_balanceLQRhostTest_T * )
_ssGetBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 0 , 1 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 2 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock
( S , 0 , 3 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 4 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 5 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 0 , 6 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 7 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 0 , 8 , SS_CALL_MDL_OUTPUTS ) ; }
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER ( tid
) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S
, 0 , 2648892487U ) ; ssSetChecksumVal ( S , 1 , 2289402684U ) ;
ssSetChecksumVal ( S , 2 , 2643339473U ) ; ssSetChecksumVal ( S , 3 ,
4189307088U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.1" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_balanceLQRhostTest_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_balanceLQRhostTest_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_balanceLQRhostTest_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & balanceLQRhostTest_rtDefaultP ) ; rt_InitInfAndNaN ( sizeof (
real_T ) ) ; ( ( P_balanceLQRhostTest_T * ) ssGetDefaultParam ( S ) ) -> P_63
= rtInf ; } static void mdlInitializeSampleTimes ( SimStruct * S ) { } static
void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
