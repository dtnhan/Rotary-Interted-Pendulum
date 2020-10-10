/*
 * File: waijung_hwdrvlib.c
 *
 * Created with Waijung Blockset
 *
 * Real-Time Workshop code generated for Simulink model BalanceMultiNew.
 *
 * Model version                        : 1.9
 * Real-Time Workshop file version      : 8.4 (R2013a) 13-Feb-2013
 * Real-Time Workshop file generated on : Tue Jan 07 09:21:01 2014
 * TLC version                          : 8.4 (Jan 19 2013)
 * C/C++ source code generated on       : Tue Jan 07 09:21:14 2014
 *
 * Target selection: stm32f4.tlc
 * Embedded hardware selection: ARM Compatible->Cortex - M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "waijung_hwdrvlib.h"

void enable_EnabledSubsystemBasicPWM(void)
{
  /* Block: EnabledSubsystemBasicPWM */
  GPIO_InitTypeDef GPIO_InitStructure;
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_OCInitTypeDef TIM_OCInitStructure;

  /* TIM3 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

  /* GPIOA clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  /* GPIOA configuration */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Connect TIM3 pins to AF */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_TIM3);

  /* Time base configuration */
  TIM_TimeBaseStructure.TIM_Period = EnabledSubsystemBasicPWM_TIM3_ARR-1;/* 5.0E-5 sec */
  TIM_TimeBaseStructure.TIM_Prescaler = 0;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseStructure.TIM_RepetitionCounter = 0x0000;
  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

  /* Init OC */
  TIM_OCStructInit(&TIM_OCInitStructure);
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  /* PWM1 Mode configuration: Channel 1 */
  TIM_OC1Init(TIM3, &TIM_OCInitStructure);
  TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);

  /* TIM3 configure auto reload */
  TIM_ARRPreloadConfig(TIM3, ENABLE);

  /* TIM3 enable counter */
  TIM_Cmd(TIM3, ENABLE);
}

void disable_EnabledSubsystemBasicPWM(void)
{
  TIM_Cmd(TIM3, DISABLE);
}

void terminate_EnabledSubsystemBasicPWM(void)
{
  TIM_Cmd(TIM3, DISABLE);
}

/* ########################################################################
 * Name: <S2>/Digital Output
 * Id: EnabledSubsystemDigitalOutput
 * ########################################################################
 */
uint16_t EnabledSubsystemDigitalOutput_portVal;
void enable_EnabledSubsystemDigitalOutput(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  /* Configure PD in output Push Pull mode for EnabledSubsystemDigitalOutput Block*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
}

/* ########################################################################
 * UART Utilities for packet processing
 * ########################################################################
 */
/* UART process Ascii Rx packet */
uint16_t Uart_rxascii_proc(uint8_t *buffer, uint16_t count,
  UART_BIN_RX_PACKET_INFO* packet_info)
{
  uint8_t data;
  while (count > 0) {
    count--;
    data = *buffer++;
   __re_check:
    /* Matched */
    if (data == packet_info->terminator[packet_info->byte_index]) {
      packet_info->byte_index ++;
      if (packet_info->byte_index >= packet_info->terminator_size) {
        packet_info->data_ready = 1;
        packet_info->byte_index = 0;
        return count;
      }
    }

    /* Not matched */
    else {
      packet_info->byte_index = 0;
      if (packet_info->byte_index > 0) {
        goto __re_check;
      }
    }
  }

  return count;
}

/* UART process Rx packet */
uint16_t Uart_rxpacket_proc(uint8_t *buffer, uint16_t count,
  UART_BIN_RX_PACKET_INFO* packet_info)
{
  uint8_t data;
  while (count>0) {
    count--;
    data = *buffer++;
   ___re_switch:
    switch (packet_info->state) {
      /* Idle */
     case rxbin_Idle:
      packet_info->byte_index = 0;
      if (packet_info->header_size > 0) {
        packet_info->state = rxbin_Header;
      } else if (packet_info->buffer_size > 0) {
        packet_info->state = rxbin_Data;
      } else if (packet_info->terminator_size > 0) {
        packet_info->state = rxbin_Terminator;
      } else {
        /* Invalid packet, ignore */
      }

      /* Apply state change */
      if (packet_info->state != rxbin_Idle)
        goto ___re_switch;
      break;

      /* Search for header */
     case rxbin_Header:
      /* Check if data is matched to header */
      if (data == packet_info->header[packet_info->byte_index]) {
        packet_info->byte_index++;

        /* Check if done checking header */
        if (packet_info->byte_index >= packet_info->header_size) {
          packet_info->byte_index = 0;
          if (packet_info->buffer_size > 0) {
            packet_info->state = rxbin_Data;
          } else if (packet_info->terminator_size > 0) {
            packet_info->state = rxbin_Terminator;
          } else {
            packet_info->state = rxbin_Idle;
          }
        }
      }

      /* Ignore, Un-expected data */
      else {
        packet_info->state = rxbin_Idle;
      }
      break;

      /* Accept data */
     case rxbin_Data:
      /* Store received data to buffer */
      packet_info->buffer[packet_info->byte_index] = data;
      packet_info->byte_index++;

      /* Done receiving data, change to terminator */
      if (packet_info->byte_index >= packet_info->buffer_size) {
        packet_info->byte_index = 0;
        if (packet_info->terminator_size > 0) {
          packet_info->state = rxbin_Terminator;
        } else {
          /* Done */
          packet_info->state = rxbin_Idle;
          packet_info->data_ready = 1;
        }
      }
      break;

      /* Verify terminator */
     case rxbin_Terminator:
      if (data == packet_info->terminator[packet_info->byte_index]) {
        packet_info->byte_index++;

        /* Check if done checking header */
        if (packet_info->byte_index >= packet_info->terminator_size) {
          /* Done */
          packet_info->state = rxbin_Idle;
          packet_info->data_ready = 1;
        }
      }

      /* Ignore, Un-expected */
      else {
        packet_info->state = rxbin_Idle;
      }
      break;

      /* Un-handle state */
     default:
      packet_info->state = rxbin_Idle;
      break;
    }

    /* Process call-back if data packet is ready */
    if (packet_info->data_ready == 1) {
      /* Non-Blocking mode */
      if (packet_info->RxReadyCallback != (void*)0) {
        packet_info->RxReadyCallback(packet_info->buffer,
          packet_info->buffer_size);
        packet_info->data_ready = 0;
      }

      /* Blocking mode */
      else {
        return count;
      }
    }
  }

  /* Return the remainning bytes */
  return count;
}

/* ########################################################################
 * Name: <S8>/UART Tx
 * Id: UARTSendUARTTx
 * ########################################################################
 */

/* Blocking Write */
void UARTSendUARTTxBlockingWrite(uint8_t* data, uint16_t count)
{
  /* Write data to DMA buffer */
  UART1_Write(data, count);

  /* Wait for DMA buffer for blocking mode */
  UART1_FlushTxBuffer();
}

/* Enable UART-DMA module */
void enable_UARTSendUARTTx(void)
{
}

/* ########################################################################
 * Name: <Root>/UART Rx
 * Id: UARTRx
 * ########################################################################
 */

/* Packet info struct */
UART_BIN_RX_PACKET_INFO UARTRx_packet_info;
uint8_t UARTRx_AsciiCount;

/* Data */
int32_t UARTRx_data0;

/* Terminator */
uint8_t UARTRx_TERMINATOR_FORMAT[1];

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT UARTRx_read_structure;
void UARTRxNonBlockingRead(uint8_t* buffer)
{
  uint16_t count;
  do {
    UARTRx_packet_info.data_ready = 0;
    UART1_Read(&UARTRx_read_structure);
    if (UARTRx_read_structure.count > 0) {
      count = Uart_rxascii_proc(UARTRx_read_structure.buffer,
        UARTRx_read_structure.count, &UARTRx_packet_info);
      UARTRx_AsciiCount += UARTRx_read_structure.count;
      UARTRx_AsciiCount -= count;

      /* If some data left after process, keep it for next */
      UARTRx_read_structure.ndtr += count;
      UARTRx_read_structure.ndtr &= (URX1_BUFFER_SIZE-1);
    }

    if (UARTRx_packet_info.data_ready == 1) {
      /* Store the reading to buffer */
      UART1_ReadFromBuffer(&UARTRx_read_structure, buffer, UARTRx_AsciiCount);
      buffer[UARTRx_AsciiCount] = '\0';/* Append null as terminater */
      UARTRx_AsciiCount = 0;

      /* scanf */
      if (sscanf((const char*)buffer,"begin%d\n"
                 ,&UARTRx_data0
                 ) != 1) {
        /* Received packet did not matched */
      } else {
        /* Data receiveat this state */
        return;
      }
    }
  } while (UARTRx_packet_info.data_ready == 1);
}

/* Enable UART-DMA module */
void enable_UARTRx(void)
{
  /* Setup terminator */
  UARTRx_TERMINATOR_FORMAT[0] = 10;
  UARTRx_packet_info.terminator =
    UARTRx_TERMINATOR_FORMAT;
  UARTRx_packet_info.terminator_size = 1;

  /* Read structure */
  UARTRx_read_structure.ndtr = URX1_BUFFER_SIZE;
  UARTRx_AsciiCount = 0;
}

/* ########################################################################
 * Name: <Root>/UART Rx3
 * Id: UARTRx3
 * ########################################################################
 */

/* Packet info struct */
UART_BIN_RX_PACKET_INFO UARTRx3_packet_info;
uint8_t UARTRx3_AsciiCount;

/* Data */
int32_t UARTRx3_data0;

/* Terminator */
uint8_t UARTRx3_TERMINATOR_FORMAT[1];

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT UARTRx3_read_structure;
void UARTRx3NonBlockingRead(uint8_t* buffer)
{
  uint16_t count;
  do {
    UARTRx3_packet_info.data_ready = 0;
    UART1_Read(&UARTRx3_read_structure);
    if (UARTRx3_read_structure.count > 0) {
      count = Uart_rxascii_proc(UARTRx3_read_structure.buffer,
        UARTRx3_read_structure.count, &UARTRx3_packet_info);
      UARTRx3_AsciiCount += UARTRx3_read_structure.count;
      UARTRx3_AsciiCount -= count;

      /* If some data left after process, keep it for next */
      UARTRx3_read_structure.ndtr += count;
      UARTRx3_read_structure.ndtr &= (URX1_BUFFER_SIZE-1);
    }

    if (UARTRx3_packet_info.data_ready == 1) {
      /* Store the reading to buffer */
      UART1_ReadFromBuffer(&UARTRx3_read_structure, buffer, UARTRx3_AsciiCount);
      buffer[UARTRx3_AsciiCount] = '\0';/* Append null as terminater */
      UARTRx3_AsciiCount = 0;

      /* scanf */
      if (sscanf((const char*)buffer,"chooseSwing%d\n"
                 ,&UARTRx3_data0
                 ) != 1) {
        /* Received packet did not matched */
      } else {
        /* Data receiveat this state */
        return;
      }
    }
  } while (UARTRx3_packet_info.data_ready == 1);
}

/* Enable UART-DMA module */
void enable_UARTRx3(void)
{
  /* Setup terminator */
  UARTRx3_TERMINATOR_FORMAT[0] = 10;
  UARTRx3_packet_info.terminator =
    UARTRx3_TERMINATOR_FORMAT;
  UARTRx3_packet_info.terminator_size = 1;

  /* Read structure */
  UARTRx3_read_structure.ndtr = URX1_BUFFER_SIZE;
  UARTRx3_AsciiCount = 0;
}

/* ########################################################################
 * Name: <S3>/Digital Input
 * Id: EncodersDigitalInput
 * ########################################################################
 */
void enable_EncodersDigitalInput(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  /* Configure PA in input None mode for EncodersDigitalInput Block*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*
 * Custom Code Block Enable Function
 * Block: <S3>/Quadratur Encoder
 * BlockID: EncodersQuadraturEncoder
 */
void enable_EncodersQuadraturEncoder(void)
{
  enable_customio();
}

/*
 * Custom Code Block Disable Function
 * Block: <S3>/Quadratur Encoder
 * BlockID: EncodersQuadraturEncoder
 */
void disable_EncodersQuadraturEncoder(void)
{
  disable_customio();
}

/* ########################################################################
 * Name: <Root>/UART Rx2
 * Id: UARTRx2
 * ########################################################################
 */

/* Packet info struct */
UART_BIN_RX_PACKET_INFO UARTRx2_packet_info;
uint8_t UARTRx2_AsciiCount;

/* Data */
int32_t UARTRx2_data0;

/* Terminator */
uint8_t UARTRx2_TERMINATOR_FORMAT[1];

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT UARTRx2_read_structure;
void UARTRx2NonBlockingRead(uint8_t* buffer)
{
  uint16_t count;
  do {
    UARTRx2_packet_info.data_ready = 0;
    UART1_Read(&UARTRx2_read_structure);
    if (UARTRx2_read_structure.count > 0) {
      count = Uart_rxascii_proc(UARTRx2_read_structure.buffer,
        UARTRx2_read_structure.count, &UARTRx2_packet_info);
      UARTRx2_AsciiCount += UARTRx2_read_structure.count;
      UARTRx2_AsciiCount -= count;

      /* If some data left after process, keep it for next */
      UARTRx2_read_structure.ndtr += count;
      UARTRx2_read_structure.ndtr &= (URX1_BUFFER_SIZE-1);
    }

    if (UARTRx2_packet_info.data_ready == 1) {
      /* Store the reading to buffer */
      UART1_ReadFromBuffer(&UARTRx2_read_structure, buffer, UARTRx2_AsciiCount);
      buffer[UARTRx2_AsciiCount] = '\0';/* Append null as terminater */
      UARTRx2_AsciiCount = 0;

      /* scanf */
      if (sscanf((const char*)buffer,"chooseController%d\n"
                 ,&UARTRx2_data0
                 ) != 1) {
        /* Received packet did not matched */
      } else {
        /* Data receiveat this state */
        return;
      }
    }
  } while (UARTRx2_packet_info.data_ready == 1);
}

/* Enable UART-DMA module */
void enable_UARTRx2(void)
{
  /* Setup terminator */
  UARTRx2_TERMINATOR_FORMAT[0] = 10;
  UARTRx2_packet_info.terminator =
    UARTRx2_TERMINATOR_FORMAT;
  UARTRx2_packet_info.terminator_size = 1;

  /* Read structure */
  UARTRx2_read_structure.ndtr = URX1_BUFFER_SIZE;
  UARTRx2_AsciiCount = 0;
}

/* ########################################################################
 * Name: <Root>/UART Rx1
 * Id: UARTRx1
 * ########################################################################
 */

/* Packet info struct */
UART_BIN_RX_PACKET_INFO UARTRx1_packet_info;
uint8_t UARTRx1_AsciiCount;

/* Data */
float UARTRx1_data0;

/* Terminator */
uint8_t UARTRx1_TERMINATOR_FORMAT[1];

/* Data read structure */
UARTRX_BUFFER_READ_STRUCT UARTRx1_read_structure;
void UARTRx1NonBlockingRead(uint8_t* buffer)
{
  uint16_t count;
  do {
    UARTRx1_packet_info.data_ready = 0;
    UART1_Read(&UARTRx1_read_structure);
    if (UARTRx1_read_structure.count > 0) {
      count = Uart_rxascii_proc(UARTRx1_read_structure.buffer,
        UARTRx1_read_structure.count, &UARTRx1_packet_info);
      UARTRx1_AsciiCount += UARTRx1_read_structure.count;
      UARTRx1_AsciiCount -= count;

      /* If some data left after process, keep it for next */
      UARTRx1_read_structure.ndtr += count;
      UARTRx1_read_structure.ndtr &= (URX1_BUFFER_SIZE-1);
    }

    if (UARTRx1_packet_info.data_ready == 1) {
      /* Store the reading to buffer */
      UART1_ReadFromBuffer(&UARTRx1_read_structure, buffer, UARTRx1_AsciiCount);
      buffer[UARTRx1_AsciiCount] = '\0';/* Append null as terminater */
      UARTRx1_AsciiCount = 0;

      /* scanf */
      if (sscanf((const char*)buffer,"set%f\n"
                 ,&UARTRx1_data0
                 ) != 1) {
        /* Received packet did not matched */
      } else {
        /* Data receiveat this state */
        return;
      }
    }
  } while (UARTRx1_packet_info.data_ready == 1);
}

/* Enable UART-DMA module */
void enable_UARTRx1(void)
{
  /* Setup terminator */
  UARTRx1_TERMINATOR_FORMAT[0] = 10;
  UARTRx1_packet_info.terminator =
    UARTRx1_TERMINATOR_FORMAT;
  UARTRx1_packet_info.terminator_size = 1;

  /* Read structure */
  UARTRx1_read_structure.ndtr = URX1_BUFFER_SIZE;
  UARTRx1_AsciiCount = 0;
}

/* ########################################################################
 * Name: <Root>/UART Setup
 * Id: UARTSetup
 * ########################################################################
 */

/* Tx buffer */
uint8_t UART1_Tx_Buffer[UTX1_BUFFER_SIZE];
UART_TX_STATE UARTSetup_Tx_State;

/* Rx buffer */
uint8_t UART1_Rx_Buffer[URX1_BUFFER_SIZE];
uint8_t UART1_Temp_Buffer[URX1_BUFFER_SIZE];
volatile UART_BIN_RX_PACKET_INFO *UART1_RootNodeRxPacket = (void*)0;/* NULL */

/* DMA Init struct */
DMA_InitTypeDef UARTSetup_DMA_Init;

/* Init buffer read */
void UART1_ReadFromBuffer(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t*
  buffer, uint16_t readcount)
{
  uint16_t count;

  /* Data non-overlap */
  if (URX1_BUFFER_SIZE-read_struct->ndtr >= readcount) {
    memcpy(buffer, &UART1_Rx_Buffer[URX1_BUFFER_SIZE-read_struct->ndtr-readcount],
           readcount);
  }

  /* Data overlap */
  else {
    /* 1st part */
    count = URX1_BUFFER_SIZE-read_struct->ndtr;
    memcpy(&buffer[readcount-count], &UART1_Rx_Buffer[0], count);

    /* 2nd part */
    count = readcount - count;
    memcpy(&buffer[0], &UART1_Rx_Buffer[URX1_BUFFER_SIZE-count], count);
  }
}

/* Read buffer from DMA
 ** Return value: Number of bytes vaiable.
 */
void UART1_Read(UARTRX_BUFFER_READ_STRUCT *read_struct)
{
  uint16_t dma_curr_ndtr = 0;
  uint16_t data_index = 0;
  uint16_t data_count = 0;

  /* Get current NDTR */
  dma_curr_ndtr = DMA2_Stream2->NDTR;
  if (read_struct->ndtr > dma_curr_ndtr) {
    /* Data available */
    data_index = URX1_BUFFER_SIZE-read_struct->ndtr;
    data_count = (read_struct->ndtr - dma_curr_ndtr);
    read_struct->ndtr = dma_curr_ndtr;
  } else if (read_struct->ndtr < dma_curr_ndtr) {
    /* Data avaialable with overlap */
    data_index = URX1_BUFFER_SIZE - read_struct->ndtr;
    data_count = read_struct->ndtr;
    read_struct->ndtr = URX1_BUFFER_SIZE;
  } else {
    /* No new data */
  }

  /* Return the reading*/
  if (data_count > 0) {
    read_struct->buffer = &UART1_Rx_Buffer[data_index];
    read_struct->count = data_count;
  } else {
    read_struct->count = 0;
  }
}

void UART1_ReadEx(UARTRX_BUFFER_READ_STRUCT *read_struct, uint8_t *buffer,
                  uint16_t buffer_size, uint16_t*reading_count)
{
  UART1_Read(read_struct);
  if (read_struct->count <= buffer_size) {
    memcpy(buffer, read_struct->buffer, read_struct->count);
    *reading_count = read_struct->count;
  } else {
    memcpy(buffer, read_struct->buffer, buffer_size);
    *reading_count = buffer_size;

    /* Return some byte back to buffer */
    read_struct->ndtr += (read_struct->count - buffer_size);
    read_struct->ndtr &= (URX1_BUFFER_SIZE-1);
  }
}

/* Wait for DMA transfer to completion */
UART_TX_STATE UARTSetup_WaitTx(void)
{
  if (UARTSetup_Tx_State != txIdle) {
    /* Chehck last DMA transmit */
    while ((DMA_GetFlagStatus(DMA2_Stream7, DMA_FLAG_TCIF7) == RESET)
           || (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)) {
    }

    /* Clear DMA Streams flags */
    DMA_ClearFlag(DMA2_Stream7, DMA_FLAG_HTIF7 | DMA_FLAG_TCIF7);

    /* Disable the DMA Streams */
    DMA_Cmd(DMA2_Stream7, DISABLE);

    /* Disable the USART Tx DMA request */
    USART_DMACmd(USART1, USART_DMAReq_Tx, DISABLE);

    /* Update state */
    UARTSetup_Tx_State = txIdle;
  }

  return UARTSetup_Tx_State;
}

/* Write to DMA buffer */
void UART1_Write(uint8_t* data, uint16_t count)
{
  if (count > 0) {
    /* Wait for Tx state to idle */
    UARTSetup_WaitTx();

    /* Setup */
    memcpy(UART1_Tx_Buffer, data, count);
    UARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)count;
    DMA_Init(DMA2_Stream7, &UARTSetup_DMA_Init);

    /* Enable */
    USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
    USART_ClearFlag(USART1, USART_FLAG_TC);
    DMA_Cmd(DMA2_Stream7, ENABLE);

    /* Tx is busy */
    UARTSetup_Tx_State = txBusy;

    /* Wait for Tx state to idle */
    /*UARTSetup_WaitTx();*/
  }
}

/* Update transmit buffer */
void UART1_TxUpdate(uint16_t count)
{
  if (count > 0) {
    /* Wait for Tx state to idle */
    UARTSetup_WaitTx();
    UARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)count;
    DMA_Init(DMA2_Stream7, &UARTSetup_DMA_Init);

    /* Enable */
    USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
    USART_ClearFlag(USART1, USART_FLAG_TC);
    DMA_Cmd(DMA2_Stream7, ENABLE);

    /* Tx is busy */
    UARTSetup_Tx_State = txBusy;
  }
}

/* Flush Tx buffer */
void UART1_FlushTxBuffer(void)
{
  /* Wait for Tx state to idle */
  UARTSetup_WaitTx();
}

/* Enable UART-DMA module */
void enable_UARTSetup(void)
{
  USART_InitTypeDef USART_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

  /* Enable UART clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

  /* Enable the DMA clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2, ENABLE);

  /* Connect PXx to USARTx_Tx*/
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1);

  /* Connect PXx to USARTx_Rx*/
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);

  /* Configure USART pin as alternate function  */
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;

  /* Configure USART Tx */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* Configure USART Rx */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  /* USART Configuration */
  USART_InitStructure.USART_BaudRate = 256000;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  /* Over sampling x8 */
  USART_OverSampling8Cmd(USART1, ENABLE);

  /* USART configuration */
  USART_Init(USART1, &USART_InitStructure);

  /* Enable USART */
  USART_Cmd(USART1, ENABLE);

  /* DMA init struct configuration */
  UARTSetup_DMA_Init.DMA_PeripheralBaseAddr = (uint32_t)(&USART1->DR);
  UARTSetup_DMA_Init.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  UARTSetup_DMA_Init.DMA_MemoryInc = DMA_MemoryInc_Enable;
  UARTSetup_DMA_Init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  UARTSetup_DMA_Init.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  UARTSetup_DMA_Init.DMA_FIFOMode = DMA_FIFOMode_Disable;
  UARTSetup_DMA_Init.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
  UARTSetup_DMA_Init.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  UARTSetup_DMA_Init.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

  /* Configure DMA controller to manage RX DMA request */
  UARTSetup_DMA_Init.DMA_Channel = DMA_Channel_4;
  UARTSetup_DMA_Init.DMA_Memory0BaseAddr = (uint32_t)UART1_Rx_Buffer;
  UARTSetup_DMA_Init.DMA_DIR = DMA_DIR_PeripheralToMemory;
  UARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)URX1_BUFFER_SIZE;
  UARTSetup_DMA_Init.DMA_Mode = DMA_Mode_Circular;
  UARTSetup_DMA_Init.DMA_Priority = DMA_Priority_VeryHigh;
  DMA_Init(DMA2_Stream2, &UARTSetup_DMA_Init);

  /* Enable the USART Rx DMA requests */
  USART_DMACmd(USART1, USART_DMAReq_Rx , ENABLE);

  /* Enable the DMA Stream */
  DMA_Cmd(DMA2_Stream2, ENABLE);

  /* Configure DMA controller to manage TX DMA request */
  UARTSetup_DMA_Init.DMA_Channel = DMA_Channel_4;
  UARTSetup_DMA_Init.DMA_Memory0BaseAddr = (uint32_t)UART1_Tx_Buffer;
  UARTSetup_DMA_Init.DMA_DIR = DMA_DIR_MemoryToPeripheral;
  UARTSetup_DMA_Init.DMA_BufferSize = (uint16_t)UTX1_BUFFER_SIZE;
  UARTSetup_DMA_Init.DMA_Mode = DMA_Mode_Normal;
  UARTSetup_DMA_Init.DMA_Priority = DMA_Priority_High;

  /* Init Tx state */
  UARTSetup_Tx_State = txIdle;
}

/* ########################################################################
 * Timer
 * ########################################################################
 */

/* Low precision non-Blocking delay timer.
 ** Relolution of timer is one TICK step interrupt.
 */
void SysTimer_Start(SYS_TIMER_STRUCT* timer, uint32_t ms)
{
  /* Calculate amount of tick count */
  timer->length = (uint32_t)((float)ms/(1000*SYS_TICKSTEP));

  /* Capture current tick */
  timer->start = (uint32_t)systick_count;
}

int SysTimer_IsTimeout(SYS_TIMER_STRUCT* timer)
{
  uint32_t Capture;

  /* Capture current tick */
  Capture = (uint32_t)systick_count;

  /* Check */
  if (Capture >= timer->start) {
    if ((Capture - timer->start) >= timer->length)
      return 1;
  } else {
    if (((0xFFFFFFFF - timer->start)+Capture) >= timer->length)
      return 1;
  }

  return 0;
}

/* Improved precision non-Blocking delay timer.
 ** Relolution of timer is 1uS.
 */
void SysTimer_uS_Start(SYS_TIMER_uS_STRUCT *timer, uint32_t us)
{
  /* Tick */
  timer->tick = SYS_CURRENT_TICK;

  /* Tick overflow count */
  timer->tid = (uint32_t)systick_count;

  /* Target */
  timer->target_us = us*((uint32_t)HCLK/1000000);
}

int SysTimer_uS_IsTimeout(SYS_TIMER_uS_STRUCT* timer)
{
  uint32_t curr_tick;
  uint32_t curr_tid;

  /* Already timeout ? */
  if (timer->target_us == 0) {
    return 1;
  }

  /* Capture current tick */
  curr_tick = SYS_CURRENT_TICK;
  curr_tid = systick_count;

  /* Processing TID*/
  while (timer->tid != curr_tid) {
    if (timer->target_us > timer->tick) {
      timer->target_us -= timer->tick;
      timer->tid ++;
      timer->tick = SYSTICKRELOADVALUE-1;
    } else {
      timer->target_us = 0;
      return 1;                        /* Timeout */
    }
  }

  /* Processing Tick */
  if ((timer->tick > curr_tick) && ((timer->tick - curr_tick) > timer->target_us))
  {
    timer->target_us = 0;
    return 1;                          /* Timeout */
  }

  /* Need wait */
  return 0;
}

/* Blocking delay, uS */
void SysTimer_delay_us(uint32_t us)
{
  SYS_TIMER_uS_STRUCT timer;
  SysTimer_uS_Start(&timer, us);
  while (SysTimer_uS_IsTimeout(&timer) == 0) ;
}

/*
 * Custom Code Block Output Function
 * Block: <S3>/Quadratur Encoder
 * BlockID: EncodersQuadraturEncoder
 * Input Port Definitions
 * in1: Port label 'inalpha', Type: boolean_T
 * in2: Port label 'intheta', Type: boolean_T
 * Output Port Definitions
 * out1: Port label 'alpha', Type: int32_T
 * out2: Port label ' theta', Type: int32_T
 */
void output_EncodersQuadraturEncoder(boolean_T in1, boolean_T in2 , int32_T
  *out1, int32_T *out2)
{
  output_customio(in1,in2,out1,out2);
}

/* [EOF] */
