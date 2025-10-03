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
#include "gpio.h"
#include "rcc.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                       Macros                                                      */
/*********************************************************************************************************************/

/*                                                      Constants                                                    */
/*********************************************************************************************************************/

/*                                                   Local Variables                                                 */
/*********************************************************************************************************************/

/*                                                 Imported Variables                                                */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/

/*                                         Imported functions implementation                                         */
/*********************************************************************************************************************/
void GPIO::SetPinMode        (const uint8_t Pin, const uint8_t Mode){
    this->gpio->moder  = REG_MASKING(this->gpio->moder,   GPIO_2Bit_control[Pin][0]); /* Clear mode bits */
    if(INPUT!=Mode) /* If not input mode */{
        this->gpio->moder  = REG_ENABLE_BITS(this->gpio->moder, GPIO_2Bit_control[Pin][Mode]); /* Set mode bits */
    }else{/* Input mode, do nothing */}
}

void GPIO::SetPinOutputType  (const uint8_t Pin, const uint8_t OutputType){
    this->gpio->otyper = REG_MASKING(this->gpio->otyper, GPIO_1Bit_control[Pin][0]); /* Clear output type bit */
    if(PUSH_PULL!=OutputType) /* If not push-pull */{
        this->gpio->otyper = REG_ENABLE_BITS(this->gpio->otyper, GPIO_1Bit_control[Pin][1]); /* Set output type bit */
    }else{/* Push-pull, do nothing */}
}

void GPIO::SetPinOutputSpeed (const uint8_t Pin, const uint8_t OutputSpeed){
    this->gpio->ospeedr = REG_MASKING(this->gpio->ospeedr, GPIO_2Bit_control[Pin][0]); /* Clear speed bits */
    if(LOW_SPEED!=OutputSpeed) /* If not low speed */{
        this->gpio->ospeedr = REG_ENABLE_BITS(this->gpio->ospeedr, GPIO_2Bit_control[Pin][OutputSpeed]); /* Set speed bits */
    }else{/* Low speed, do nothing */}
}

void GPIO::SetPinPullUpDown  (const uint8_t Pin, const uint8_t PullUpDown){
    this->gpio->pupdr = REG_MASKING(this->gpio->pupdr, GPIO_2Bit_control[Pin][0]); /* Clear pull-up/pull-down bits */
    if(NO_PULL!=PullUpDown) /* If not pull-up */{
        this->gpio->pupdr = REG_ENABLE_BITS(this->gpio->pupdr, GPIO_2Bit_control[Pin][PullUpDown]); /* Set pull-up/pull-down bits */
    }else{/* No pull-up/pull-down, do nothing */}
}
void GPIO::SetPinAlternate   (const uint8_t Pin, const uint8_t Alternate){
    if(Pin < 8){
        /* GPIOx->AFR[0] */
        this->gpio->afrl = REG_MASKING(this->gpio->afrl, GPIO_4Bit_control[Pin][0]); /* Clear alternate function bits */
        if(AF0!=Alternate){
            this->gpio->afrl = REG_ENABLE_BITS(this->gpio->afrl, GPIO_4Bit_control[Pin][Alternate]); /* Set alternate function bits */
        }else{/* AF0, do nothing */}
    }else{
        /* GPIOx->AFR[1] */
        this->gpio->afrh = REG_MASKING(this->gpio->afrh, GPIO_4Bit_control[Pin][0]); /* Clear alternate function bits */
        if(AF0!=Alternate){
            this->gpio->afrh = REG_ENABLE_BITS(this->gpio->afrh, GPIO_4Bit_control[Pin][Alternate]); /* Set alternate function bits */
        }else{/* AF0, do nothing */}
    }
}

Port::Port(const Port_ConfigType* ConfigPtr){
    PortConfigPtr = ConfigPtr;
    RCC rcc;
    for(uint8_t i=0; i<PortConfigPtr->NumberOfPins; i++){
        const Pin_ConfigType* PinConfig = PortConfigPtr->PinConfigList + i;
        /* Enable GPIOx peripheral */
        GPIO GPIOx(GPIO_Base[PinConfig->Port]);
        uint8_t pin = PinConfig->Pin;
        /* Check if GPIO clock is enabled: */
        if(!rcc.GetPortClockState(PinConfig->Port)) {
            /* GPIO clock is disabled, enable it: */
            rcc.SetPortClockState(PinConfig->Port,STD_ON);
        }else{/* GPIO clock is enabled, do nothing */}
        /* Configure Pin Mode: */
        GPIOx.SetPinMode(pin, PinConfig->Mode);
        /* Configure Output Type: */
        if(OUTPUT==PinConfig->Mode || ALTERNATE==PinConfig->Mode){
            GPIOx.SetPinOutputType(pin, PinConfig->OutputType);
            /* Configure Speed: */
            GPIOx.SetPinOutputSpeed(pin, PinConfig->OutputSpeed);
            /* Configure Pull-up/Pull-down: */
            GPIOx.SetPinPullUpDown(pin, PinConfig->PullUpDown);
            /* Configure Alternate Function: */
            if(ALTERNATE==PinConfig->Mode){
                GPIOx.SetPinAlternate(pin, PinConfig->Alternate);
           }else{/* Not alternate function mode, do nothing */}
        }else{/* Not output or alternate mode, do nothing */}
    }
}

void Port::TooglePin        (const uint8_t Pin){
    uint8_t PinIdx = this->PortConfigPtr->PinConfigList[Pin].Pin;
    uint8_t PortIdx = this->PortConfigPtr->PinConfigList[Pin].Port;
    GPIO_TypeDef* GPIOx = GPIO_Base[PortIdx];
    /* Toggle the output data register */
    GPIOx->odr ^= GPIO_1Bit_control[PinIdx][1];
}

void Port::SetPinState      (const uint8_t Pin, uint8_t State){
    uint8_t PinIdx = this->PortConfigPtr->PinConfigList[Pin].Pin;
    uint8_t PortIdx = this->PortConfigPtr->PinConfigList[Pin].Port;
    GPIO_TypeDef* GPIOx = GPIO_Base[PortIdx];
    if(State){
        GPIOx->odr |= GPIO_1Bit_control[PinIdx][1]; // Set bit
    }
    else{
        GPIOx->odr &= ~GPIO_1Bit_control[PinIdx][1]; // Reset bit
    }
}

boolean Port::GetPinState   (const uint8_t Pin){
    uint8_t PinIdx = this->PortConfigPtr->PinConfigList[Pin].Pin;
    uint8_t PortIdx = this->PortConfigPtr->PinConfigList[Pin].Port;
    GPIO_TypeDef* GPIOx = GPIO_Base[PortIdx];
    return REG_COMPARER(GPIOx->idr & GPIO_1Bit_control[PinIdx][1]);
}
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 