/*********************************************************************************************************************/
/*                                                  HEADER GROUP                                                     */
/*********************************************************************************************************************/
/*                                               OBJECT SPECIFICATION                                                */
/*********************************************************************************************************************/
/*!
 * $File: main.h
 * $Revision: Version 1.0 $
 * $Author: Carlos Martinez $
 * $Date: 2025-08-03 $
 */
/*********************************************************************************************************************/
/* DESCRIPTION :                                                                                                     */
/* main.h:
               Use this template for your source code files.
 */
/*********************************************************************************************************************/
/* ALL RIGHTS RESERVED                                                                                               */
/*                                                                                                                   */
/* The reproduction, transmission, or use of this document or its content is                                         */
/* not permitted without express written authority. Offenders will be liable                                         */
/* for damages.                                                                                                      */
/*********************************************************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_
/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/
#include "fw.h"
#include "Std_Types.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
inline constexpr Pin_ConfigType PG13 = {
    PORTG,   // Port
    PIN13,    // Pin
    OUTPUT,  // Mode
    PUSH_PULL, // OutputType
    LOW_SPEED, // OutputSpeed
    NO_PULL,   // PullUpDown
    AF0        // Alternate
};

inline constexpr Pin_ConfigType PG14 = {
    PORTG,   // Port
    PIN14,    // Pin
    OUTPUT,  // Mode
    PUSH_PULL, // OutputType
    LOW_SPEED, // OutputSpeed
    NO_PULL,   // PullUpDown
    AF0        // Alternate
};

inline constexpr Pin_ConfigType PA0 = {
    PORTA,    // Port
    PIN0,    // Pin
    INPUT,    // Mode
    PUSH_PULL,// OutputType (no afecta en input)
    LOW_SPEED,// OutputSpeed
    NO_PULL,  // PullUpDown
    AF0       // Alternate
};

inline constexpr SysTick_ConfigType SYSTICK_CONFIG = {
    SYSTICK_ENABLE,
    SYSTICK_TICKINT_ENABLE,
    SYSTICK_PROCESSOR_CLOCK,
    SYSTICK_1_MS_TICKS
};

#define GREEN_LED   (uint8_t)0u
#define RED_LED     (uint8_t)1u
#define PUSH_BUTTON (uint8_t)2u

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/
extern uint32_t sys_clk_freq;

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/

/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 