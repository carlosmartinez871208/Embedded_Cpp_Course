/*********************************************************************************************************************/
/*                                                  SOURCE GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: Stm32f429zi_Startup.c
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-09-29 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* Stm32f429zi_Startup.c:
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
#include "Data_Types.h"
#include "main.h"

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/
/* Into linker script can be found _estack
** it is used as the first vector table element.
*/
extern uint32_t _estack;

/* Global symbols */
extern uint32_t _stext;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

/*                                                 Imported Variables                                                */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/
void Reset_Handler(void) __attribute__((noreturn));
void Default_Handler(void);
void SystemInit(void) __attribute__((weak));
void SystemInit(void) {}

/* Main function prototype */
extern int main(void);

#ifdef __NEWLIB__
void __libc_init_array(void);
#endif

#define WEAK_DEFAULT(name) void name(void) __attribute__((weak,alias("Default_Handler")))

/* Interrupt and exceptions handlers: from GNU collections page 601 (GCC-14.2)
** Provide 'weak' aliases for each exception handler to the deault handler.
** As they are 'weak' aliasses, any function with the same name will override
** this definition.
** The alias attribute causes the declaration to be emitted as an alias for another
** symbol, which must have been previously declared with the same type, and for
** variables, also the same size and aligment.
** Declaring an alias with different type than the target is undefined and my be
** diagnosed.
** e.g.
** void __f () {}
** void f () __attribute__ ((weak,alias ("__f")))
*/
/* Exceptions */
/* Excepciones núcleo */
WEAK_DEFAULT(NMI_Handler);
WEAK_DEFAULT(HardFault_Handler);
WEAK_DEFAULT(MemManage_Handler);
WEAK_DEFAULT(BusFault_Handler);
WEAK_DEFAULT(UsageFault_Handler);
WEAK_DEFAULT(SVCall_Handler);
WEAK_DEFAULT(DebugMonitor_Handler);
WEAK_DEFAULT(PendSV_Handler);
WEAK_DEFAULT(SysTick_Handler);

/* IRQs (orden según RM0090) */
WEAK_DEFAULT(WWDOG_IRQHandler);
WEAK_DEFAULT(EXTI_PVD_IRQHandler);
WEAK_DEFAULT(EXTI_TAMP_STAMP_IRQHandler);
WEAK_DEFAULT(EXTI_RTC_WKUP_IRQHandler);
WEAK_DEFAULT(FLASH_IRQHandler);
WEAK_DEFAULT(RCC_IRQHandler);
WEAK_DEFAULT(EXTI0_IRQHandler);
WEAK_DEFAULT(EXTI1_IRQHandler);
WEAK_DEFAULT(EXTI2_IRQHandler);
WEAK_DEFAULT(EXTI3_IRQHandler);
WEAK_DEFAULT(EXTI4_IRQHandler);
WEAK_DEFAULT(DMA1_Stream0_IRQHandler);
WEAK_DEFAULT(DMA1_Stream1_IRQHandler);
WEAK_DEFAULT(DMA1_Stream2_IRQHandler);
WEAK_DEFAULT(DMA1_Stream3_IRQHandler);
WEAK_DEFAULT(DMA1_Stream4_IRQHandler);
WEAK_DEFAULT(DMA1_Stream5_IRQHandler);
WEAK_DEFAULT(DMA1_Stream6_IRQHandler);
WEAK_DEFAULT(ADC_IRQHandler);
WEAK_DEFAULT(CAN1_TX_IRQHandler);
WEAK_DEFAULT(CAN1_RX0_IRQHandler);
WEAK_DEFAULT(CAN1_RX1_IRQHandler);
WEAK_DEFAULT(CAN1_SCE_IRQHandler);
WEAK_DEFAULT(EXTI9_5_IRQHandler);
WEAK_DEFAULT(TIM1_BRK_TIM9_IRQHandler);
WEAK_DEFAULT(TIM1_UP_TIM10_IRQHandler);
WEAK_DEFAULT(TIM1_TRG_COM_TIM11_IRQHandler);
WEAK_DEFAULT(TIM1_CC_IRQHandler);
WEAK_DEFAULT(TIM2_IRQHandler);
WEAK_DEFAULT(TIM3_IRQHandler);
WEAK_DEFAULT(TIM4_IRQHandler);
WEAK_DEFAULT(I2C1_EV_IRQHandler);
WEAK_DEFAULT(I2C1_ER_IRQHandler);
WEAK_DEFAULT(I2C2_EV_IRQHandler);
WEAK_DEFAULT(I2C2_ER_IRQHandler);
WEAK_DEFAULT(SPI1_IRQHandler);
WEAK_DEFAULT(SPI2_IRQHandler);
WEAK_DEFAULT(USART1_IRQHandler);
WEAK_DEFAULT(USART2_IRQHandler);
WEAK_DEFAULT(USART3_IRQHandler);
WEAK_DEFAULT(EXTI15_10_IRQHandler);
WEAK_DEFAULT(RTC_Alarm_IRQHandler);
WEAK_DEFAULT(OTG_FS_WKUP_IRQHandler);
WEAK_DEFAULT(TIM8_BRK_TIM12_IRQHandler);
WEAK_DEFAULT(TIM8_UP_TIM13_IRQHandler);
WEAK_DEFAULT(TIM8_TRG_COM_TIM14_IRQHandler);
WEAK_DEFAULT(TIM8_CC_IRQHandler);
WEAK_DEFAULT(DMA1_Stream7_IRQHandler);
WEAK_DEFAULT(FSMC_IRQHandler);
WEAK_DEFAULT(SDIO_IRQHandler);
WEAK_DEFAULT(TIM5_IRQHandler);
WEAK_DEFAULT(SPI3_IRQHandler);
WEAK_DEFAULT(USART4_IRQHandler);
WEAK_DEFAULT(USART5_IRQHandler);
WEAK_DEFAULT(TIM6_DAC_IRQHandler);
WEAK_DEFAULT(TIM7_IRQHandler);
WEAK_DEFAULT(DMA2_Stream0_IRQHandler);
WEAK_DEFAULT(DMA2_Stream1_IRQHandler);
WEAK_DEFAULT(DMA2_Stream2_IRQHandler);
WEAK_DEFAULT(DMA2_Stream3_IRQHandler);
WEAK_DEFAULT(DMA2_Stream4_IRQHandler);
WEAK_DEFAULT(ETH_IRQHandler);
WEAK_DEFAULT(ETH_WKUP_IRQHandler);
WEAK_DEFAULT(CAN2_TX_IRQHandler);
WEAK_DEFAULT(CAN2_RX0_IRQHandler);
WEAK_DEFAULT(CAN2_RX1_IRQHandler);
WEAK_DEFAULT(CAN2_SCE_IRQHandler);
WEAK_DEFAULT(OTG_FS_IRQHandler);
WEAK_DEFAULT(DMA2_Stream5_IRQHandler);
WEAK_DEFAULT(DMA2_Stream6_IRQHandler);
WEAK_DEFAULT(DMA2_Stream7_IRQHandler);
WEAK_DEFAULT(USART6_IRQHandler);
WEAK_DEFAULT(I2C3_EV_IRQHandler);
WEAK_DEFAULT(I2C3_ER_IRQHandler);
WEAK_DEFAULT(OTG_HS_EP1_OUT_IRQHandler);
WEAK_DEFAULT(OTG_HS_EP1_IN_IRQHandler);
WEAK_DEFAULT(OTG_HS_WKUP_IRQHandler);
WEAK_DEFAULT(OTG_HS_IRQHandler);
WEAK_DEFAULT(DCMI_IRQHandler);
WEAK_DEFAULT(CRYP_IRQHandler);
WEAK_DEFAULT(HASH_RNG_IRQHandler);
WEAK_DEFAULT(FPU_IRQHandler);
WEAK_DEFAULT(USART7_IRQHandler);
WEAK_DEFAULT(USART8_IRQHandler);
WEAK_DEFAULT(SPI4_IRQHandler);
WEAK_DEFAULT(SPI5_IRQHandler);
WEAK_DEFAULT(SPI6_IRQHandler);
WEAK_DEFAULT(SAI1_IRQHandler);
WEAK_DEFAULT(LCD_TFT_IRQHandler);
WEAK_DEFAULT(LCD_TFT_ERR_IRQHandler);
WEAK_DEFAULT(DMA2D_IRQHandler);

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
/* From GNU Compiler Collection: pages 674 and 675 (GCC-14.2)
** Normally, the compiler places the objects it generates in sections like data and bss.
** Sometimes, however, you need additional sections, or you need certain
** particular variables to appear in special sections, for example to map to special
** hardware.
** The section attribute specifies that a variable (or function) lives
** in a particular section. For example, this small program uses several specific
** section names:
** e.g.
** int init_data __attribute__ ((section ("INITDATA")));
*/
/* Vector table, see reference manual page: 378 */
__attribute__((section(".isr_vector_table"),used,aligned(256)))
const uint32_t vector_table[] = {
    (uint32_t) &_estack,
    (uint32_t) &Reset_Handler,
    (uint32_t) &NMI_Handler,
    (uint32_t) &HardFault_Handler,
    (uint32_t) &MemManage_Handler,
    (uint32_t) &BusFault_Handler,
    (uint32_t) &UsageFault_Handler,
    0u,
    0u,
    0u,
    0u,
    (uint32_t) &SVCall_Handler,
    (uint32_t) &DebugMonitor_Handler,
    0u,
    (uint32_t) &PendSV_Handler,
    (uint32_t) &SysTick_Handler,
    (uint32_t) &WWDOG_IRQHandler,/* Microcontroller interrupts. WWDOG address: 0x0000 0040*/
    (uint32_t) &EXTI_PVD_IRQHandler,
    (uint32_t) &EXTI_TAMP_STAMP_IRQHandler,
    (uint32_t) &EXTI_RTC_WKUP_IRQHandler,
    (uint32_t) &FLASH_IRQHandler,
    (uint32_t) &RCC_IRQHandler,
    (uint32_t) &EXTI0_IRQHandler,
    (uint32_t) &EXTI1_IRQHandler,
    (uint32_t) &EXTI2_IRQHandler,
    (uint32_t) &EXTI3_IRQHandler,
    (uint32_t) &EXTI4_IRQHandler,
    (uint32_t) &DMA1_Stream0_IRQHandler,
    (uint32_t) &DMA1_Stream1_IRQHandler,
    (uint32_t) &DMA1_Stream2_IRQHandler,
    (uint32_t) &DMA1_Stream3_IRQHandler,
    (uint32_t) &DMA1_Stream4_IRQHandler,
    (uint32_t) &DMA1_Stream5_IRQHandler,
    (uint32_t) &DMA1_Stream6_IRQHandler,
    (uint32_t) &ADC_IRQHandler,
    (uint32_t) &CAN1_TX_IRQHandler,
    (uint32_t) &CAN1_RX0_IRQHandler,
    (uint32_t) &CAN1_RX1_IRQHandler,
    (uint32_t) &CAN1_SCE_IRQHandler,
    (uint32_t) &EXTI9_5_IRQHandler,
    (uint32_t) &TIM1_BRK_TIM9_IRQHandler,
    (uint32_t) &TIM1_UP_TIM10_IRQHandler,
    (uint32_t) &TIM1_TRG_COM_TIM11_IRQHandler,
    (uint32_t) &TIM1_CC_IRQHandler,
    (uint32_t) &TIM2_IRQHandler,
    (uint32_t) &TIM3_IRQHandler,
    (uint32_t) &TIM4_IRQHandler,
    (uint32_t) &I2C1_EV_IRQHandler,
    (uint32_t) &I2C1_ER_IRQHandler,
    (uint32_t) &I2C2_EV_IRQHandler,
    (uint32_t) &I2C2_ER_IRQHandler,
    (uint32_t) &SPI1_IRQHandler,
    (uint32_t) &SPI2_IRQHandler,
    (uint32_t) &USART1_IRQHandler,
    (uint32_t) &USART2_IRQHandler,
    (uint32_t) &USART3_IRQHandler,
    (uint32_t) &EXTI15_10_IRQHandler,
    (uint32_t) &RTC_Alarm_IRQHandler,
    (uint32_t) &OTG_FS_WKUP_IRQHandler,
    (uint32_t) &TIM8_BRK_TIM12_IRQHandler,
    (uint32_t) &TIM8_UP_TIM13_IRQHandler,
    (uint32_t) &TIM8_TRG_COM_TIM14_IRQHandler,
    (uint32_t) &TIM8_CC_IRQHandler,
    (uint32_t) &DMA1_Stream7_IRQHandler,
    (uint32_t) &FSMC_IRQHandler,
    (uint32_t) &SDIO_IRQHandler,
    (uint32_t) &TIM5_IRQHandler,
    (uint32_t) &SPI3_IRQHandler,
    (uint32_t) &USART4_IRQHandler,
    (uint32_t) &USART5_IRQHandler,
    (uint32_t) &TIM6_DAC_IRQHandler,
    (uint32_t) &TIM7_IRQHandler,
    (uint32_t) &DMA2_Stream0_IRQHandler,
    (uint32_t) &DMA2_Stream1_IRQHandler,
    (uint32_t) &DMA2_Stream2_IRQHandler,
    (uint32_t) &DMA2_Stream3_IRQHandler,
    (uint32_t) &DMA2_Stream4_IRQHandler,
    (uint32_t) &ETH_IRQHandler,
    (uint32_t) &ETH_WKUP_IRQHandler,
    (uint32_t) &CAN2_TX_IRQHandler,
    (uint32_t) &CAN2_RX0_IRQHandler,
    (uint32_t) &CAN2_RX1_IRQHandler,
    (uint32_t) &CAN2_SCE_IRQHandler,
    (uint32_t) &OTG_FS_IRQHandler,
    (uint32_t) &DMA2_Stream5_IRQHandler,
    (uint32_t) &DMA2_Stream6_IRQHandler,
    (uint32_t) &DMA2_Stream7_IRQHandler,
    (uint32_t) &USART6_IRQHandler,
    (uint32_t) &I2C3_EV_IRQHandler,
    (uint32_t) &I2C3_ER_IRQHandler,
    (uint32_t) &OTG_HS_EP1_OUT_IRQHandler,
    (uint32_t) &OTG_HS_EP1_IN_IRQHandler,
    (uint32_t) &OTG_HS_WKUP_IRQHandler,
    (uint32_t) &OTG_HS_IRQHandler,
    (uint32_t) &DCMI_IRQHandler,
    (uint32_t) &CRYP_IRQHandler,
    (uint32_t) &HASH_RNG_IRQHandler,
    (uint32_t) &FPU_IRQHandler,
    (uint32_t) &USART7_IRQHandler,
    (uint32_t) &USART8_IRQHandler,
    (uint32_t) &SPI4_IRQHandler,
    (uint32_t) &SPI5_IRQHandler,
    (uint32_t) &SPI6_IRQHandler,
    (uint32_t) &SAI1_IRQHandler,
    (uint32_t) &LCD_TFT_IRQHandler,
    (uint32_t) &LCD_TFT_ERR_IRQHandler,
    (uint32_t) &DMA2D_IRQHandler
};

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
/* Default handler */
void Default_Handler(void)
{
    while (1) {
        __asm volatile ("wfi");
    }
}

/* Reset Handler */
void Reset_Handler(void)
{
    /* Copiar .data desde FLASH (LMA = _etext) a RAM */
    uint32_t *src = (uint32_t*)&_etext;
    uint32_t *dst = (uint32_t*)&_sdata;
    while (dst < (uint32_t*)&_edata) {
        *dst++ = *src++;
    }

    /* Limpiar .bss */
    dst = (uint32_t*)&_sbss;
    while (dst < (uint32_t*)&_ebss) {
        *dst++ = 0u;
    }

    SystemInit();

#ifdef __NEWLIB__
    __libc_init_array();   /* Constructores estáticos C++ */
#endif

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif
    (void)main();
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

    while (1) {
        __asm volatile ("wfi");
    }
}

#ifdef __cplusplus
} /* extern "C" */
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 