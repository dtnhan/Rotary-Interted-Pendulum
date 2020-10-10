/*
 * File: waijung_hwdrvlib.h
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

#ifndef RTW_HEADER_waijung_hwdrvlib_h_
#define RTW_HEADER_waijung_hwdrvlib_h_
#include "stm32f4_io_customcode.h"
#include "rtwtypes.h"
#include "stm32f4xx.h"

/* EncodersDigitalInput */
#define EncodersDigitalInput_A0        Peripheral_BB(GPIOA->IDR, 0) /* Output pin */

/*
 * Define PWM Generation Scale Factor
 * From TIMx_CCRx = TIMx_ARR * (Duty Cycle / 100)
 * TIMx_CCRx = (TIMx_ARR/100) * Duty Cycle
 */
#define BasicPWM_TIM3_ARR              4200
#define BasicPWM_SF                    (BasicPWM_TIM3_ARR / 100)

/* ########################################################################
 * Name: <Root>/Digital Output
 * Id: DigitalOutput
 * ########################################################################
 */
#define DigitalOutput_D12              Peripheral_BB(GPIOD->ODR, 12) /* Output pin */

/*
 * Bit banding
 *
 * The Cortex memory map includes two bit-band regions.
 * These regions map each word in an alias region of memory to a bit in
 * a bit-band region of memory. Writing to a word in the alias region
 * has the same effect as a read-modify-write operation on the targeted bit
 * in the bit-band region.
 *
 * In the STM32F4xxx both peripheral registers and SRAM are mapped in
 * a bit-band region. This allows single bit-band write and read operations
 * to be performed.
 *
 * A mapping formula shows how to reference each word in the alias region
 * to a corresponding bit in the bit-band region. The mapping formula is:
 * bit_word_addr = bit_band_base + (byte_offset x 32) + (bit_number × 4)
 *
 * BB_base      is the base address of the bit-band region for a register. (PERIPH_BB_BASE at 0x42000000 or SRAM_BB_BASE at 0x22000000)
 * Reg_base     is the base address of a register in the memory region. (PERIPH_BASE at 0x40000000 or SRAM_BASE at 0x20000000)
 * Register     is a register in the memory region that contains the targeted bit.
 * Bit_number   is the targeted bit number (0 - 31).
 *
 * PERIPH_BB_BASE, SRAM_BB_BASE, PERIPH_BASE, and SRAM_BASE are defined in stm32f10x.h
 *
 * Example for determining bit banding bit.
 * Determine DMA Transfer Complete Flag using bit banding.
 * TCIFx is the flag for DMA Channel x
 * This bit is set by hardware. It is cleared by software writing 1 to
 * the corresponding bit in the DMA_IFCR register.
 * TCIFx = 0: No transfer complete (TC) event on channel x
 * TCIFx = 1: A transfer complete (TC) event occurred on channel x
 *
 * DMA Channel:       1 2 3  4  5  6  7
 * Flag bit position: 1 5 9 13 17 21 25 (in DMA_ISR register)
 * (For DMA2 Channel 6 and 7 is irrelevant since it only has 5 channels.)
 *
 * CTCIFx: Channel x transfer complete clear (x = 1 ..7)
 * This bit is set and cleared by software.
 * CTCIFx = 0: No effect
 * CTCIFx = 1: Clear the corresponding TCIF flag in the DMA_ISR register
 *
 */
#define BitBanding(Register, Bit_number, Reg_base, BB_base) ((volatile uint32_t*) ((BB_base) + (((uint32_t) &(Register)) - ((Reg_base))<<5) + ((Bit_number)<<2)))
#define Peripheral_BB(Register, Bit_number) BitBanding(Register, Bit_number, PERIPH_BASE, PERIPH_BB_BASE)
#define SRAM_BB(Register, Bit_number)  BitBanding(Register, Bit_number, SRAM_BASE, SRAM_BB_BASE)

/*
 * Sample usage:
 * USART1->SR can be found from "stm32f4xx.h" and USART_FLAG_TC (6) can be found from "stm32f4xx_usart.h"
 * #define USART1_TC Peripheral_BB(USART1->SR, 6) USART_SR.TC bit
 *
 * Another example:
 * #define GPIOC_8 Peripheral_BB(GPIOC->ODR, 8)
 * *GPIOC_8 = 1;
 */

/*
 * Systick is configured such that the SysTick interrupt every 0.01 sec
 * which is the base sample time of the system.
 */
#define SYSTICKRELOADVALUE             1680000

/*
 * HCLK (Hz)
 */
#define HCLK                           168000000

/*
 * Each Systick counter is TIMEPERSYSTICK sec.
 */
#define TIMEPERSYSTICK                 0.01 / 1680000

extern volatile unsigned int systick_count;

/* ########################################################################
 * Name: <S2>/Digital Input
 * Id: EncodersDigitalInput
 * ########################################################################
 */
void enable_EncodersDigitalInput(void);

/*
 * Custom Code Block Enable Function
 * Block: <S2>/Quadratur Encoder
 * BlockID: EncodersQuadraturEncoder
 */
void enable_EncodersQuadraturEncoder(void);

/*
 * Custom Code Block Disable Function
 * Block: <S2>/Quadratur Encoder
 * BlockID: EncodersQuadraturEncoder
 */
void disable_EncodersQuadraturEncoder(void);
void enable_BasicPWM(void);            /* BasicPWM */

/* DigitalOutput */
void enable_DigitalOutput(void);

#ifndef __UART_PACKET_DEFINE
#define __UART_PACKET_DEFINE           1

/* UART packet process struct */
typedef void (*UART_Rx_Callback)(uint8_t *data, uint16_t size);
typedef enum {
  rxbin_Idle = 0,
  rxbin_Header,
  rxbin_Data,
  rxbin_Terminator
} UART_BIN_RX_STATE;

typedef struct {
  /* Header */
  uint8_t *header;
  uint8_t header_size;

  /* Terminator */
  uint8_t *terminator;
  uint8_t terminator_size;

  /* Output buffer */
  uint8_t *buffer;
  int16_t buffer_size;

  /* Working state */
  UART_BIN_RX_STATE state;

  /* Data ready Callback */
  UART_Rx_Callback RxReadyCallback;

  /* Bytes index */
  uint16_t byte_index;

  /* Data ready status */
  uint8_t data_ready;
} UART_BIN_RX_PACKET_INFO;

typedef enum {
  txIdle = 0,
  txBusy
} UART_TX_STATE;

/* Data read structure */
typedef struct {
  uint16_t ndtr;                       /* Store number of data to transfer, for reference with current value */
  uint16_t count;                      /* Return data count */
  uint8_t *buffer;                     /* Return buffer pointer of valid data */
} UARTRX_BUFFER_READ_STRUCT;

#endif                                 /* __UART_PACKET_DEFINE */

/* ########################################################################
 * Name: <Root>/UART Tx
 * Id: UARTTx
 * ########################################################################
 */
extern uint8_t UARTTx_packet_buffer[];
void enable_UARTTx(void);

/* ########################################################################
 * Name: <Root>/UART Setup
 * Id: UARTSetup
 * ########################################################################
 */
#define UTX1_BUFFER_SIZE               512

extern uint8_t UART1_Tx_Buffer[];
extern UART_TX_STATE UARTSetup_Tx_State;
extern void UART1_TxUpdate(uint16_t count);

#define URX1_BUFFER_SIZE               512

extern uint8_t UART1_Rx_Buffer[];
extern uint8_t UART1_Temp_Buffer[];
extern uint16_t UART1_GetInitNDTR(void);
void UART1_Read(UARTRX_BUFFER_READ_STRUCT *read_struct);
void UART1_ReadEx(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t *buffer,
                  uint16_t buffer_size, uint16_t*reading_count);
extern void UART1_ReadFromBuffer(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t*
  buffer, uint16_t readcount);
extern void UART1_Write(uint8_t* data, uint16_t count);
extern void UART1_FlushTxBuffer(void);
extern uint16_t Uart_rxascii_proc(uint8_t *buffer, uint16_t count,
  UART_BIN_RX_PACKET_INFO* packet_info);
void enable_UARTSetup(void);

/* ########################################################################
 * Timer
 * ########################################################################
 */
#define SYS_CURRENT_TICK               (SysTick->VAL)
#define SYS_TICKSTEP                   0.01f

typedef struct {
  uint32_t start;
  uint32_t length;
} SYS_TIMER_STRUCT;

#define SYSTIMER_FLAGS_TIMEOUT         0x01

typedef struct {
  uint8_t flags;
  uint32_t tid;                        /* Tick count */
  uint32_t tick;                       /* Capture cuttent tick */
  uint32_t target_us;                  /* Target of systick */
} SYS_TIMER_uS_STRUCT;

extern volatile unsigned int systick_count;
void SysTimer_Start(SYS_TIMER_STRUCT* timer, uint32_t ms);
void SysTimer_uS_Start(SYS_TIMER_uS_STRUCT *timer, uint32_t us);
int SysTimer_IsTimeout(SYS_TIMER_STRUCT* timer);
int SysTimer_uS_IsTimeout(SYS_TIMER_uS_STRUCT* timer);
void SysTimer_delay_us(uint32_t us);

/*
 * Custom Code Block Output Function
 * Block: <S2>/Quadratur Encoder
 * BlockID: EncodersQuadraturEncoder
 * Input Port Definitions
 * in1: Port label 'inalpha', Type: boolean_T
 * in2: Port label 'intheta', Type: boolean_T
 * Output Port Definitions
 * out1: Port label 'alpha', Type: int32_T
 * out2: Port label ' theta', Type: int32_T
 */
void output_EncodersQuadraturEncoder(boolean_T in1, boolean_T in2 , int32_T
  *out1, int32_T *out2);

#endif                                 /* RTW_HEADER_waijung_hwdrvlib_h_ */

/* [EOF] */
