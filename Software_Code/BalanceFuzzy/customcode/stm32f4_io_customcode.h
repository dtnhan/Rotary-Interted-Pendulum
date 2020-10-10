#ifndef __STM32F4_IO_CUSTOMCODE_H
#define __STM32F4_IO_CUSTOMCODE_H


#include "waijung_hwdrvlib.h" 
#include "stm32f4xx_gpio.h"
#include "rtwtypes.h"
//#include "stm32f4xx_tim.h"
//#include "stm32f4xx_rcc.h"
//#include "stm32f4xx_tim.h"
//#include "stm32f4xx_conf.h"
//#include <stddef.h>
//#include "stm32f4xx_tim.c"

/*
 * definitions for the quadrature encoder pins
 */
// Left Motor Channels
#define ENCLA_PIN               GPIO_Pin_9
#define ENCLA_GPIO_PORT         GPIOE
#define ENCLA_GPIO_CLK          RCC_AHB1Periph_GPIOE
#define ENCLA_SOURCE            GPIO_PinSource9
#define ENCLA_AF                GPIO_AF_TIM1

#define ENCLB_PIN               GPIO_Pin_11
#define ENCLB_GPIO_PORT         GPIOE
#define ENCLB_GPIO_CLK          RCC_AHB1Periph_GPIOE
#define ENCLB_SOURCE            GPIO_PinSource11
#define ENCLB_AF                GPIO_AF_TIM1

// Right Motor Channels
#define ENCRA_PIN               GPIO_Pin_5
#define ENCRA_GPIO_PORT         GPIOA
#define ENCRA_GPIO_CLK          RCC_AHB1Periph_GPIOA
#define ENCRA_SOURCE            GPIO_PinSource5
#define ENCRA_AF                GPIO_AF_TIM2

#define ENCRB_PIN               GPIO_Pin_3
#define ENCRB_GPIO_PORT         GPIOB
#define ENCRB_GPIO_CLK          RCC_AHB1Periph_GPIOB
#define ENCRB_SOURCE            GPIO_PinSource3
#define ENCRB_AF                GPIO_AF_TIM2

// determine the timers to use
#define ENCL_TIMER              TIM1
#define ENCL_TIMER_CLK          RCC_APB2Periph_TIM1
#define ENCR_TIMER              TIM2
#define ENCR_TIMER_CLK          RCC_APB1Periph_TIM2

#define LEFT_COUNT()            ENCL_TIMER->CNT
#define RIGHT_COUNT()           ENCR_TIMER->CNT

//TimerConfig
#define TIM_EncoderMode_TI12               ((uint16_t)0x0003)
#define  TIM_ICPolarity_Rising             ((uint16_t)0x0000)

#define outD12 Peripheral_BB(GPIOD->ODR, 12)
#define outD13 Peripheral_BB(GPIOD->ODR, 13)


void enable_customio(void);

void output_customio(boolean_T in1, boolean_T in2, int32_T *out1, int32_T *out2); 

void disable_customio(void);

uint32_t TIM_GetCounter2(TIM_TypeDef* TIMx);
void TIM_EncoderInterfaceConfig2(TIM_TypeDef* TIMx, uint16_t TIM_EncoderMode,
                                uint16_t TIM_IC1Polarity, uint16_t TIM_IC2Polarity);
void TIM_SetAutoreload2(TIM_TypeDef* TIMx, uint32_t Autoreload);
void TIM_Cmd2(TIM_TypeDef* TIMx, FunctionalState NewState);
void encodersReset(void);
void TIM_SetCounter2(TIM_TypeDef* TIMx, uint32_t Counter);

#endif