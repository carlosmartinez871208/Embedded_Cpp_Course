/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: template.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-08-03 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* template.c:
               Use this template for your source code files.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/

/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/
#include "systick.h"

#ifdef __cplusplus
extern "C" {
#endif
void SysTick_Handler(void);
#ifdef __cplusplus
}
#endif 

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                       Macros                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                                   Local Variables                                                 */
/*********************************************************************************************************************/
static volatile uint32_t current_tick   = 0ul;
static volatile uint32_t current_tick_p = 0ul;

/*                                                 Imported Variables                                                */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/

/*                                         Imported functions implementation                                         */
/*********************************************************************************************************************/

SysTick::SysTick(const SysTick_ConfigType* Config){
    if (SYSTICK_ENABLE==Config->Enable){
        systick = (SysTick_Type *)SYSTICK_BASE_ADDRESS;
        /* Disable SysTick IRQ and SysTick Timer */
        __disable_irq();
        /* Disable SysTick during setup */
        systick->csr &= ~SYSTICK_RESET_VALUE;
        /* Clear current value register */
        systick->cvr = SYSTICK_RESET_VALUE;
        /* Set reload register */
        systick->rvr = (Config->ReloadValue & SYSTICK_MAX_RELOAD);
        /* Set clock source */
        if (SYSTICK_PROCESSOR_CLOCK==Config->ClkSource){
            systick->csr |= SYSTICK_CSR_CLKSOURCE;
        }else{
            systick->csr &= ~SYSTICK_CSR_CLKSOURCE;
        }
        /* Enable or disable interrupt */
        if (SYSTICK_TICKINT_ENABLE==Config->TickInt){
            systick->csr |= SYSTICK_CSR_TICKINT;
        }else{
            systick->csr &= ~SYSTICK_CSR_TICKINT;
        }
        /* Enable SysTick */
        systick->csr |= SYSTICK_CSR_ENABLE;
        __enable_irq();
    }
    else
    {/* Do nothing */}
}

void SysTick_Handler(void){
    /* Increment tick count */
    current_tick+=1ul;
}

uint32_t SysTick::GetTick(void){
    __disable_irq();
    current_tick_p = current_tick;
    __enable_irq();
    return current_tick_p;
}

void SysTick::Delay(uint32_t delay){
    unsigned int tickstart = GetTick();
    unsigned int wait = delay;
    if(wait < SYSTICK_MAX_RELOAD){
        wait += 1ul;
    }else{/* Do nothing */}
    while ((GetTick() - tickstart) < wait){}
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 