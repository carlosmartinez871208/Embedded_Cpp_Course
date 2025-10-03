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
#ifndef RCC_H_
#define RCC_H_
/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/
#include "Std_Types.h"
#include "peripherals.h"
#include "Register.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef struct
{
    __IO uint32_t cr;
    __IO uint32_t pllcfgr;
    __IO uint32_t cfgr;
    __IO uint32_t cir;
    __IO uint32_t ahb1rstr;
    __IO uint32_t ahb2rstr;
    __IO uint32_t ahb3rstr;
    __IO uint32_t dummy0;
    __IO uint32_t apb1rstr;
    __IO uint32_t apb2rstr;
    __IO uint32_t dummy1;
    __IO uint32_t dummy2;
    __IO uint32_t ahb1enr;
    __IO uint32_t ahb2enr;
    __IO uint32_t ahb3enr;
    __IO uint32_t dummy3;
    __IO uint32_t apb1enr;
    __IO uint32_t apb2enr;
    __IO uint32_t dummy4;
    __IO uint32_t dummy5;
    __IO uint32_t ahb1lpenr;
    __IO uint32_t ahb2lpenr;
    __IO uint32_t ahb3lpenr;
    __IO uint32_t dummy6;
    __IO uint32_t apb1lpenr;
    __IO uint32_t apb2lpenr;
    __IO uint32_t dummy7;
    __IO uint32_t dummy8;
    __IO uint32_t bdcr;
    __IO uint32_t csr;
    __IO uint32_t dummy9;
    __IO uint32_t dumm10;
    __IO uint32_t sscgr;
    __IO uint32_t plli2scfgr;
    __IO uint32_t pllsaicfgr;
    __IO uint32_t dckcfgr;
}RCC_TypeDef;

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
static const uint32_t RCC_GPIO_Clk_Enable[9] = {
    0x00000001ul, /* ... 00000001*/
    0x00000002ul, /* ... 00000010*/
    0x00000004ul,
    0x00000008ul,
    0x00000010ul,
    0x00000020ul,
    0x00000040ul,
    0x00000080ul,
    0x00000100ul,
};

/*                                                       Class                                                       */
/*********************************************************************************************************************/
class RCC
{
    private:
        RCC_TypeDef* rcc;
    public:
        RCC(void){rcc = (RCC_TypeDef *) RCC_BASE_ADDRESS;}
        void    SetPortClockState (const uint8_t Port, const uint8_t State);
        boolean GetPortClockState(const uint8_t Port);
};

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 