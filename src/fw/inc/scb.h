/*********************************************************************************************************************/
/*                                                  HEADER GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: template.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-08-03 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* template.h:
               Use this template for your source code files.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef SCB_H_
#define SCB_H_
/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/
#include "interrupts.h"
#include "peripherals.h"
#include "Register.h"
#include "Std_Types.h"

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef struct
{
    __IO uint8_t  mmsr;
    __IO uint8_t  bfsr;
    __IO uint16_t ufsr;
}cfsr_type;

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
/* SBC Control Block Register (SBC_ACTLR): */
#ifndef SCB_ACTLR
 #define SCB_ACTLR_OFFSET         (0x0ul)
 #define SCB_ACTLR                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_ACTLR_OFFSET))
#endif

#ifndef SCB_CPUID
 #define SCB_CPUID_OFFSET         (0xCF8ul)
 #define SCB_CPUID                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_CPUID_OFFSET))
#endif

#ifndef SCB_ICSR
 #define SCB_ICSR_OFFSET          (0xCFCul)
 #define SCB_ICSR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_ICSR_OFFSET))
#endif

#ifndef SCB_VTOR
 #define SCB_VTOR_OFFSET          (0xD00ul)
 #define SCB_VTOR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_VTOR_OFFSET))
#endif

#ifndef SCB_AIRCR
 #define SCB_AIRCR_OFFSET         (0xD04l)
 #define SCB_AIRCR                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_AIRCR_OFFSET))
#endif

#ifndef SCB_SCR
 #define SCB_SCR_OFFSET           (0xD08ul)
 #define SCB_SCR                  (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_SCR_OFFSET))
#endif

#ifndef SCB_CCR
 #define SCB_CCR_OFFSET           (0xD0Cul)
 #define SCB_CCR                  (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_CCR_OFFSET))
#endif

#ifndef SCB_SPHR1
 #define SCB_SPHR1_OFFSET         (0xD10ul)
 #define SCB_SPHR1                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_SPHR1_OFFSET))
#endif

#ifndef SCB_SPHR2
 #define SCB_SPHR2_OFFSET         (0xD14ul)
 #define SCB_SPHR2                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_SPHR2_OFFSET))
#endif

#ifndef SCB_SPHR3
 #define SCB_SPHR3_OFFSET         (0xD18ul)
 #define SCB_SPHR3                (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_SPHR3_OFFSET))
#endif

#ifndef SCB_SPHCRS
 #define SCB_SPHCRS_OFFSET        (0xD1Cul)
 #define SCB_SPHCRS               (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_SPHCRS_OFFSET))
#endif

#ifndef SCB_CFSR
 #define SCB_CFSR_OFFSET          (0xD20ul)
 #define SCB_CFSR                 ((cfsr_type*)(SCB_BASE_ADDRESS + SCB_CFSR_OFFSET))
#endif

#ifndef SCB_HFSR
 #define SCB_HFSR_OFFSET          (0xD24ul)
 #define SCB_HFSR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_HFSR_OFFSET))
#endif

#ifndef SCB_MMAR
 #define SCB_MMAR_OFFSET          (0xD2Cul)
 #define SCB_MMAR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_MMAR_OFFSET))
#endif

#ifndef SCB_BFAR
 #define SCB_BFAR_OFFSET          (0xD30ul)
 #define SCB_BFAR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_BFAR_OFFSET))
#endif

#ifndef SCB_AFSR
 #define SCB_AFSR_OFFSET          (0xD34ul)
 #define SCB_AFSR                 (*(__IO uint32_t*)(SCB_BASE_ADDRESS + SCB_AFSR_OFFSET))
#endif

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/
#define SCB_ISCR_SET_PEN_BIT         (0x1ul<<26)
#define SCB_ISCR_SET_PENSV_BIT   (0x10000000ul)
#define SCB_SHPR_SYSTICK_RST         (0x00FFFFFFul)
#define SCB_SHPR_SYSTICK_PRI_14      (0xE0000000ul)
#define SCB_SHPR_PENDSV_RST          (0xFF00FFFFul)
#define SCB_SHPR_PENDSV_PRI_15       (0x00F00000ul)

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/
class SCB{
    public:
        void SetVectorOffset     (const uint32_t Address, const uint32_t Offset);
        void TriggerSysTick      (void);
        void SetPendSV           (void);
        void ClearPendSV         (void);
        void SetSysTickPriority  (void);
        void SetPendSVPriority   (void);
};

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 