/************************************************************/
/* AUTHOR      : RAGAB REDA EL-KATTAWY Modified by Islam ElShater                     */
/* DESCRIPTION : NVIC DRIVER    [ NVIC_prog.c]              */
/* DATE        : AUGUST 23, 2019                            */
/************************************************************/

#include "STD_types.h"
#include "BIT_MATH.h"
#include "NVIC_priv.h"
#include "NVIC_int1.h"

#define FIRST_REG_END  32
#define SECOND_REG_END 64
#define THIRD_REG_END  96
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
extern NVIC_INT_status_t NVIC_NVIC_INT_statusGetIntStatus(INT_idx_t INT_idx_tIdxCpy)
{
	NVIC_INT_status_t INT_status_Stat_loc;
    INT_status_Stat_loc.EnableState = NVIC_NVIC_INT_stateGetEnable(INT_idx_tIdxCpy);
    INT_status_Stat_loc.PendingState = NVIC_NVIC_INT_stateGetPending(INT_idx_tIdxCpy);
    INT_status_Stat_loc.ACtiveState = NVIC_NVIC_INT_stateGetActive(INT_idx_tIdxCpy);
    INT_status_Stat_loc.PriorityLevel = NVIC_u8GetIntPriority(INT_idx_tIdxCpy);
    return INT_status_Stat_loc;
}

/************************************************************/
/*  API        : NVIC_voidEnableInt                         */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : void                                       */
/*  Description: Enables the indexed interrupt.             */
/************************************************************/
extern void NVIC_voidEnableInt(INT_idx_t INT_idx_tIdxCpy)
{
    /* check for proper register */
    if(INT_idx_tIdxCpy < FIRST_REG_END) /* the index is in the ISER0 range */
    {
        /* Set the corresponding bit */
        NVIC_ISER[0] = 1 << INT_idx_tIdxCpy;
    }
    else if(INT_idx_tIdxCpy < SECOND_REG_END) /* the index is in the ISER1 range */
    {
        /* re-adjust index */
        INT_idx_tIdxCpy -= FIRST_REG_END;
        /* Set the corresponding bit */
        NVIC_ISER[1] = 1 << INT_idx_tIdxCpy;
    }
    else
    {
        /* NOT A VALID INDEX NUMBER */
    }
}

/************************************************************/
/*  API        : NVIC_voidEnableInt                         */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : void                                       */
/*  Description: Disables the indexed interrupt.            */
/************************************************************/
extern void NVIC_voidDisableInt(INT_idx_t INT_idx_tIdxCpy)
{
    /* check for proper register */
    if(INT_idx_tIdxCpy < FIRST_REG_END) /* the index is in the ICER0 range */
    {
        /* Set the corresponding bit */
        NVIC_ICER[0] = 1 << INT_idx_tIdxCpy;
    }
    else if(INT_idx_tIdxCpy < SECOND_REG_END) /* the index is in the ICER1 range */
    {
        /* re-adjust index */
        INT_idx_tIdxCpy -= FIRST_REG_END;
        /* Set the corresponding bit */
        NVIC_ICER[1] = 1 << INT_idx_tIdxCpy;
    }
    else
    {
        /* NOT A VALID INDEX NUMBER */
    }
}

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
extern INT_state NVIC_NVIC_INT_stateGetEnable(INT_idx_t INT_idx_tIdxCpy)
{
    /* check for proper register */
    if(INT_idx_tIdxCpy < FIRST_REG_END) /* the index is in the ISER0 range */
    {
        /* return the Interrupt status */
        return (GET_BIT(NVIC_ISER[0],INT_idx_tIdxCpy)|INTERRUPT_DISABLED);
    }
    else if(INT_idx_tIdxCpy < SECOND_REG_END) /* the index is in the ISER1 range */
    {
        /* re-adjust index */
        INT_idx_tIdxCpy -= FIRST_REG_END;
        /* return the Interrupt status */
        return (GET_BIT(NVIC_ISER[1],INT_idx_tIdxCpy)|INTERRUPT_DISABLED);
    }
    else
    {
        /* NOT A VALID INDEX NUMBER */
        return INTERRUPT_OUTOFRANGE;
    }
}

/************************************************************/
/*  API        : NVIC_voidSetPending                        */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : void                                       */
/*  Description: Forces the indexed interrupt to be pending */
/************************************************************/
extern void NVIC_voidSetPending(INT_idx_t INT_idx_tIdxCpy)
{
    /* check for proper register */
    if(INT_idx_tIdxCpy < FIRST_REG_END) /* the index is in the ISPR0 range */
    {
        /* Set the corresponding bit */
        NVIC_ISPR[0] = 1 << INT_idx_tIdxCpy;
    }
    else if(INT_idx_tIdxCpy < SECOND_REG_END) /* the index is in the ISPR1 range */
    {
        /* re-adjust index */
        INT_idx_tIdxCpy -= FIRST_REG_END;
        /* Set the corresponding bit */
        NVIC_ISPR[1] = 1 << INT_idx_tIdxCpy;
    }
    else
    {
        /* NOT A VALID INDEX NUMBER */
    }
}
/************************************************************/
/*  API        : NVIC_voidClrPending                        */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : void                                       */
/*  Description: Clears the indexed interrupt pending bit   */
/************************************************************/
extern void NVIC_voidClrPending(INT_idx_t INT_idx_tIdxCpy)
{
    /* check for proper register */
    if(INT_idx_tIdxCpy < FIRST_REG_END) /* the index is in the ICPR0 range */
    {
        /* Set the corresponding bit */
        NVIC_ICPR[0] = 1 << INT_idx_tIdxCpy;
    }
    else if(INT_idx_tIdxCpy < SECOND_REG_END) /* the index is in the ICPR1 range */
    {
        /* re-adjust index */
        INT_idx_tIdxCpy -= FIRST_REG_END;
        /* Set the corresponding bit */
        NVIC_ICPR[1] = 1 << INT_idx_tIdxCpy;
    }
    else
    {
        /* NOT A VALID INDEX NUMBER */
    }
}

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
extern INT_state NVIC_NVIC_INT_stateGetPending(INT_idx_t INT_idx_tIdxCpy)
{
    /* check for proper register */
    if(INT_idx_tIdxCpy < FIRST_REG_END) /* the index is in the ISPR0 range */
    {
        /* return the Interrupt status */
        return (GET_BIT(NVIC_ISPR[0],INT_idx_tIdxCpy)|INTERRUPT_NOT_PENDING);
    }
    else if(INT_idx_tIdxCpy < SECOND_REG_END) /* the index is in the ISPR1 range */
    {
        /* re-adjust index */
        INT_idx_tIdxCpy -= FIRST_REG_END;
        /* return the Interrupt status */
        return (INT_state)(GET_BIT(NVIC_ISPR[1],INT_idx_tIdxCpy)|INTERRUPT_NOT_PENDING);
    }
    else
    {
        /* NOT A VALID INDEX NUMBER */
        return INTERRUPT_OUTOFRANGE;
    }
}

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
extern INT_state NVIC_NVIC_INT_stateGetActive(INT_idx_t INT_idx_tIdxCpy)
{
    /* check for proper register */
    if(INT_idx_tIdxCpy < FIRST_REG_END) /* the index is in the IABR0 range */
    {
        /* return the Interrupt status */
        return (GET_BIT(NVIC_IABR[0],INT_idx_tIdxCpy)|INTERRUPT_NOT_PENDING);
    }
    else if(INT_idx_tIdxCpy < SECOND_REG_END) /* the index is in the IABR1 range */
    {
        /* re-adjust index */
        INT_idx_tIdxCpy -= FIRST_REG_END;
        /* return the Interrupt status */
        return (GET_BIT(NVIC_IABR[1],INT_idx_tIdxCpy)|INTERRUPT_NOT_PENDING);
    }
    else
    {
        /* NOT A VALID INDEX NUMBER */
        return INTERRUPT_OUTOFRANGE;
    }
}

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
extern void NVIC_voidSetIntPriority(INT_idx_t INT_idx_tIdxCpy, u8 u8Periority)
{
    /* check if the index in range */
    if (INT_idx_tIdxCpy >= NVIC_WWDG_IDX && INT_idx_tIdxCpy <= NVIC_DMA2_CHANNEL4_5_IDX)
    {
        /* Set priority level */
        NVIC_IPR[INT_idx_tIdxCpy] = u8Periority;
    }
    else
    {
        /* NOT A VALID INDEX NUMBER */
    }
}

/************************************************************/
/*  API        : NVIC_u8GetIntPriority                      */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : u8 [periority level]                       */
/*  Description: Gets the priority level of the indexed     */
/*               interrupt.                                 */
/************************************************************/
extern u8 NVIC_u8GetIntPriority(INT_idx_t INT_idx_tIdxCpy)
{
    /* check if the index in range */
    if (INT_idx_tIdxCpy >= NVIC_WWDG_IDX && INT_idx_tIdxCpy <= NVIC_DMA2_CHANNEL4_5_IDX)
    {
        /* Set priority level */
        return NVIC_IPR[INT_idx_tIdxCpy];
    }
    else
    {
        /* NOT A VALID INDEX NUMBER */
        return INTERRUPT_OUTOFRANGE;
    }
}

/************************************************************/
/*  API        : NVIC_voidTriggerInt                        */
/*	Parameters : INT_idx_tIdxCpy  [See Range below]         */
/*	Return     : void                                       */
/*  Description: Forces the indexed interrupt to be         */
/*               triggered                                  */
/************************************************************/
extern void NVIC_voidTriggerInt(INT_idx_t INT_idx_tIdxCpy)
{
	/* enable interrupt*/
	NVIC_voidEnableInt(INT_idx_tIdxCpy);
    /* check if the index in range */
    if (INT_idx_tIdxCpy >= NVIC_WWDG_IDX && INT_idx_tIdxCpy <= NVIC_DMA2_CHANNEL4_5_IDX)
    {
        /* Add the index to the NVIC_STIR */
        NVIC_STIR = INT_idx_tIdxCpy;
    }
    else
    {
        /* NOT A VALID INDEX NUMBER */
    }
}
