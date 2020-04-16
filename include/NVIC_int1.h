/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY Modified by Islam ElShater                     */
/* DESCRIPTION : NVIC DRIVER    [ NVIC_int.h]               */
/* DATE        : AUGUST 23, 2019                            */
/************************************************************/

#ifndef _NVIC_INT_H
#define _NVIC_INT_H

/******************** Public Data types *********************/
typedef enum
{
    INTERRUPT_DISABLED = 0,
    INTERRUPT_ENABLED,
    INTERRUPT_NOT_PENDING,
    INTERRUPT_PENDING,
    INTERRUPT_NOT_ACTIVE,
    INTERRUPT_ACTIVE,
    INTERRUPT_OUTOFRANGE = 0xFF
}INT_state;

typedef struct
{
    INT_state EnableState;
    INT_state PendingState;
    INT_state ACtiveState;
    u8        PriorityLevel;
}NVIC_INT_status_t;

/******************* interrupt indexes **********************/
typedef enum
{
    NVIC_WWDG_IDX = 0,           /* Window watchdog interrupt */
    NVIC_PVD_IDX,                /* PVD through EXTI Line detection interrupt */
    NVIC_TAMPER_IDX,             /* Tamper interrupt */
    NVIC_RTC_IDX,                /* RTC global interrupt */
    NVIC_FLASH_IDX,              /* Flash global interrupt */
    NVIC_RCC_IDX,                /* RCC global interrupt */
    NVIC_EXTI0_IDX,              /* EXTI Line0 interrupt */
    NVIC_EXTI1_IDX,              /* EXTI Line1 interrupt */
    NVIC_EXTI2_IDX,              /* EXTI Line2 interrupt */
    NVIC_EXTI3_IDX,              /* EXTI Line3 interrupt */
    NVIC_EXTI4_IDX,              /* EXTI Line4 interrupt */
    NVIC_DMA1_CHANNEL1_IDX,      /* DMA1 Channel1 global interrupt */
    NVIC_DMA1_CHANNEL2_IDX,      /* DMA1 Channel2 global interrupt */
    NVIC_DMA1_CHANNEL3_IDX,      /* DMA1 Channel3 global interrupt */
    NVIC_DMA1_CHANNEL4_IDX,      /* DMA1 Channel4 global interrupt */
    NVIC_DMA1_CHANNEL5_IDX,      /* DMA1 Channel5 global interrupt */
    NVIC_DMA1_CHANNEL6_IDX,      /* DMA1 Channel6 global interrupt */
    NVIC_DMA1_CHANNEL7_IDX,      /* DMA1 Channel7 global interrupt */
    NVIC_ADC1_2_IDX,             /* ADC1 and ADC2 global interrupt */
    NVIC_USB_HP_CAN_TX_IDX,      /* USB High Priority or CAN TX interrupts */
    NVIC_USB_LP_CAN_RX0_IDX,     /* USB Low Priority or CAN RX0 interrupts */
    NVIC_CAN_RX1_IDX,            /* CAN RX1 interrupt */
    NVIC_CAN_SCE_IDX,            /* CAN SCE interrupt */
    NVIC_EXTI9_5_IDX,            /* EXTI Line[9:5] interrupts */
    NVIC_TIM1_BRK_IDX,           /* TIM1 Break interrupt */
    NVIC_TIM1_UP_IDX,            /* TIM1 Update interrupt */
    NVIC_TIM1_TRG_COM_IDX,       /* TIM1 Trigger and Commutation interrupts */
    NVIC_TIM1_CC_IDX,            /* TIM1 Capture Compare interrupt */
    NVIC_TIM2_IDX,               /* TIM2 global interrupt */
    NVIC_TIM3_IDX,               /* TIM3 global interrupt */
    NVIC_TIM4_IDX,               /* TIM4 global interrupt */
    NVIC_I2C1_EV_IDX,            /* I2C1 event interrupt */
    NVIC_I2C1_ER_IDX,            /* I2C1 error interrupt */
    NVIC_I2C2_EV_IDX,            /* I2C2 event interrupt */
    NVIC_I2C2_ER_IDX,            /* I2C2 error interrupt */
    NVIC_SPI1_IDX,               /* SPI1 global interrupt */
    NVIC_SPI2_IDX,               /* SPI2 global interrupt */
    NVIC_USART1_IDX,             /* USART1 global interrupt */
    NVIC_USART2_IDX,             /* USART2 global interrupt */
    NVIC_USART3_IDX,             /* USART3 global interrupt */
    NVIC_EXTI15_10_IDX,          /* EXTI Line[15:10] interrupts */
    NVIC_RTCALARM_IDX,           /* RTC alarm through EXTI line interrupt */
    NVIC_USBWAKEUP_IDX,          /* USB wakeup from suspend through EXTI line interrupt */
    NVIC_TIM8_BRK_IDX,           /* TIM8 Break interrupt */
    NVIC_TIM8_UP_IDX,            /* TIM8 Update interrupt */
    NVIC_TIM8_TRG_COM_IDX,       /* TIM8 Trigger and Commutation interrupts */
    NVIC_TIM8_CC_IDX,            /* TIM8 Capture Compare interrupt */
    NVIC_ADC3_IDX,               /* ADC3 global interrupt */
    NVIC_FSMC_IDX,               /* FSMC global interrupt */
    NVIC_SDIO_IDX,               /* SDIO global interrupt */
    NVIC_TIM5_IDX,               /* TIM5 global interrupt */
    NVIC_SPI3_IDX,               /* SPI3 global interrupt */
    NVIC_UART4_IDX,              /* UART4 global interrupt */
    NVIC_UART5_IDX,              /* UART5 global interrupt */
    NVIC_TIM6_IDX,               /* TIM6 global interrupt */
    NVIC_TIM7_IDX,               /* TIM7 global interrupt */
    NVIC_DMA2_CHANNEL1_IDX,      /* DMA2 Channel1 global interrupt */
    NVIC_DMA2_CHANNEL2_IDX,      /* DMA2 Channel2 global interrupt */
    NVIC_DMA2_CHANNEL3_IDX,      /* DMA2 Channel3 global interrupt */
    NVIC_DMA2_CHANNEL4_5_IDX     /* DMA2 Channel4 and Channel5 global interrupts */
}INT_idx_t;
/*************************** APIs ***************************/

/************************************************************/
/*  API        : NVIC_NVIC_INT_statusGetIntStatus           */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : [INT_status]                               */
/*               sruct contains the interrupt status        */
/*                         {EnableState,                    */
/*                          PendingState,                   */
/*                          ACtiveState,                    */
/*                          PriorityLevel}                  */
/*  Description: Gets the status of the indexed interrupt.  */
/************************************************************/
extern NVIC_INT_status_t NVIC_NVIC_INT_statusGetIntStatus(INT_idx_t INT_idx_tIdxCpy);

/************************************************************/
/*  API        : NVIC_voidEnableInt                         */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : void                                       */
/*  Description: Enables the indexed interrupt.             */
/************************************************************/
extern void NVIC_voidEnableInt(INT_idx_t INT_idx_tIdxCpy);

/************************************************************/
/*  API        : NVIC_voidEnableInt                         */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : void                                       */
/*  Description: Disables the indexed interrupt.            */
/************************************************************/
extern void NVIC_voidDisableInt(INT_idx_t INT_idx_tIdxCpy);

/************************************************************/
/*  API        : NVIC_NVIC_INT_stateGetEnable               */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : [INT_state]                                */
/*               Enumerator indectaes the Enable status     */
/*  Description: Gets the enable status of the indexed      */
/*               interrupt.                                 */
/*               returns INTERRUPT_ENABLED if the interrupt */
/*               is Enabled or INTERRUPT_DISABLED if the    */
/*               interrupt is Disabled.                     */
/************************************************************/
extern INT_state NVIC_NVIC_INT_stateGetEnable(INT_idx_t INT_idx_tIdxCpy);

/************************************************************/
/*  API        : NVIC_voidSetPending                        */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : void                                       */
/*  Description: Forces the indexed interrupt to be pending */
/************************************************************/
extern void NVIC_voidSetPending(INT_idx_t INT_idx_tIdxCpy);
/************************************************************/
/*  API        : NVIC_voidClrPending                        */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : void                                       */
/*  Description: Clears the indexed interrupt pending bit   */
/************************************************************/
extern void NVIC_voidClrPending(INT_idx_t INT_idx_tIdxCpy);

/************************************************************/
/*  API        : NVIC_NVIC_INT_stateGetPending              */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : [INT_state]                                */
/*               Enumerator indectaes the Pending status    */
/*  Description: Gets the Pending status of the indexed     */
/*               interrupt.                                 */
/*               returns INTERRUPT_PENDING if the interrupt */
/*               is Pending or INTERRUPT_NOT_PENDING if the */
/*               interrupt is NOT Pending.                  */
/************************************************************/
extern INT_state NVIC_NVIC_INT_stateGetPending(INT_idx_t INT_idx_tIdxCpy);

/************************************************************/
/*  API        : NVIC_NVIC_INT_stateGetActive               */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : [INT_state]                                */
/*               Enumerator indectaes the Active status     */
/*  Description: Gets the Active status of the indexed      */
/*               interrupt.                                 */
/*               returns INTERRUPT_ACTIVE if the interrupt  */
/*               is Active or INTERRUPT_NOT_ACTIVE if the   */
/*               interrupt is NOT Active.                   */
/************************************************************/
extern INT_state NVIC_NVIC_INT_stateGetActive(INT_idx_t INT_idx_tIdxCpy);

/************************************************************/
/*  API        : NVIC_voidSetIntPriority                    */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*               u8Periority                                */
/*               Range:[0x00, 0x10, 0x20, 0x30, 0x40, 0x50, */
/*                      0x60, 0x70, 0x80, 0x90, 0xA0, 0xB0, */
/*                      0xC0, 0xD0, 0xE0, 0xF0]             */
/*	Return     : void                                       */
/*  Description: Sets the indexed interrupt to be periority */
/************************************************************/
extern void NVIC_voidSetIntPriority(INT_idx_t INT_idx_tIdxCpy, u8 u8Periority);

/************************************************************/
/*  API        : NVIC_u8GetIntPriority                      */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : u8 [priority level]                        */
/*  Description: Gets the priority level of the indexed     */
/*               interrupt.                                 */
/************************************************************/
extern u8 NVIC_u8GetIntPriority(INT_idx_t INT_idx_tIdxCpy);

/************************************************************/
/*  API        : NVIC_voidTriggerInt                        */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : void                                       */
/*  Description: Forces the indexed interrupt to be         */
/*               triggered                                  */
/************************************************************/
extern void NVIC_voidTriggerInt(INT_idx_t INT_idx_tIdxCpy);


#endif
