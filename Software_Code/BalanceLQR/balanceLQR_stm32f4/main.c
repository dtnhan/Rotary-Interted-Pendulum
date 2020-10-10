/*
 * File: main.c
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model balanceLQR.
 *
 * Model version                        : 1.69
 * Real-Time Workshop file version      : 8.4 (R2013a) 13-Feb-2013
 * Real-Time Workshop file generated on : Tue Dec 17 18:01:43 2013
 * TLC version                          : 8.4 (Jan 19 2013)
 * C/C++ source code generated on       : Tue Dec 17 18:01:44 2013
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "waijung_hwdrvlib.h"
#include "balanceLQR.h"
#include "rtwtypes.h"                  /* MathWorks types */

/*
 * rt_Onestep is called from a timer ISR at the base sample time of 0.01 sec.
 * The ISR is void SysTick_Handler(void) and is defined in stm32f4xx_it.c
 */
void rt_OneStep(void);
volatile unsigned int systick_count = 0;
static volatile int systick_active = 1;

/* Main program */
int_T main(void)
{
  /* Initialize model */
  balanceLQR_initialize();

  /* Continue indefinitely */
  if (SysTick_Config(SYSTICKRELOADVALUE)) {
    /* Capture error */
    while (1) ;
  }

  while (1) {
    if (systick_active) {
      systick_active = 0;
      balanceLQR_step();

      /* Get model outputs here */

      /* Profiler update */
    }
  }
}

void rt_OneStep(void)
{
  systick_active = 1;

  /* Tick counter */
  systick_count++;
}

/* [EOF] */
