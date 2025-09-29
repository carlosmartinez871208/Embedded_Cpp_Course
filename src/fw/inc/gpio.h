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
#ifndef GPIO_H_
#define GPIO_H_
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
    __IO uint32_t moder;
    __IO uint32_t otyper;
    __IO uint32_t ospeedr;
    __IO uint32_t pupdr;
    __IO uint32_t idr;
    __IO uint32_t odr;
    __IO uint32_t bsrr;
    __IO uint32_t lckr;
    __IO uint32_t afrl;
    __IO uint32_t afrh;
}GPIO_TypeDef;

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#define GPIOG                           ((GPIO_TypeDef *) GPIOG_BASE_ADDRESS)

/* Green LED is connected to GPIOG pin 13 */
/* Pin 13 configuration bits: */
#define GPIO_MODER_PIN_13_1            ((uint32_t) (1 << 27))
#define GPIO_MODER_PIN_13_0            ((uint32_t) (1 << 26))
/* Configure GPIOG pin 13 as output: */
#define PORTG_PIN13_MODE_OUTPUT        ((uint32_t) (GPIO_MODER_PIN_13_0))
/* Pin13 output bits: */
#define GPIO_ODR_PIN_13                ((uint32_t) (1 << 13))
/* Define PORTG_PIN13  */
#define PORTG_PIN13                    GPIO_ODR_PIN_13

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/
class GPIO{
    private:
        GPIO_TypeDef* gpio;
    public:
        GPIO(GPIO_TypeDef* gpio): gpio(gpio) {};
        void InitPinMode   (const uint32_t PIN_MODE);
        void TogglePin     (const uint32_t PIN);
};


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