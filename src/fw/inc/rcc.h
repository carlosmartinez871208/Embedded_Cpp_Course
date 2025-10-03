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
#include "Data_Types.h"
#include "peripherals.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef struct
{
    __IO uint32_t CR;        /* Clock control register */
    __IO uint32_t CFGR;      /* Clock configuration register */
    __IO uint32_t CIR;       /* Clock interrupt register */
    __IO uint32_t APB2RSTR;  /* APB2 peripheral reset register */
    __IO uint32_t APB1RSTR;  /* APB1 peripheral reset register */
    __IO uint32_t AHBENR;    /* AHB peripheral clock enable register */
    __IO uint32_t APB2ENR;   /* APB2 peripheral clock enable register */
    __IO uint32_t APB1ENR;   /* APB1 peripheral clock enable register */
    __IO uint32_t BDCR;      /* Backup domain control register */
    __IO uint32_t CSR;       /* Control/status register */
    __IO uint32_t AHBRSTR;   /* AHB peripheral reset register */
    __IO uint32_t CFGR2;     /* Clock configuration register 2 */
    __IO uint32_t CFGR3;     /* Clock configuration register 3 */
}RCC_TypeDef;

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#define RCC                             ((RCC_TypeDef *) RCC_BASE_ADDRESS)

/*                                                       Class                                                       */
/*********************************************************************************************************************/

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