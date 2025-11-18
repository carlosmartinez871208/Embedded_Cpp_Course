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
#ifndef OS_H_
#define OS_H_
/*                                                 Standard libraries                                                */
/*********************************************************************************************************************/

/*                                                   User libraries                                                  */
/*********************************************************************************************************************/
#include "interrupts.h"
#include "peripherals.h"
#include "Register.h"
#include "scb.h"
#include "Std_Types.h"
#include "systick.h"

/*                                                        Types                                                      */
/*********************************************************************************************************************/
typedef struct
{
    uint32_t*         Stack_Pointer; /* Apunta hasta el inicio del stack (hay que recordar que se incrementa hacia abajo):
                                     Esto tiene como objetivo guardar el contexto de cada tarea. */
    uint8_t           Priority;      /* Nos brinda la prioridad de la tarea. */
    uint8_t           Status;        /* Nos da informacion del estatus de la tarea. */
    uint32_t          Offset;        /* Este es el offset de ejecución. */
}ThreadControlBlock_Type; /* Esta estructura nos ayuda a manipular cada uno de nuestros hilos de ejecución. */

typedef ThreadControlBlock_Type TCB_Type; /* Definimos un alias para la estructura ThreadControlBlock_Type. */

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
/* Un sistema operativo debe tener la capacidad de proveer cierto tiempo de procesamiento a cada tarea especifica 
   en el caso de los sistemas operativos de tiempo real lo que los caracteriza es el concepto de "deadline", esto
   significa que cada hilo de ejecucion (thread) debe cumplir ese deadline, cabe mencionar que una tarea (task)
   es la ejecución de un hilo. */

#define MAX_NUMBER_OF_TASKS (5ul) /* Al estar usando sistemas embebidos es recomendable no usar memoria dinamica
                                      debido a los recursos de los microcontroladores que son limitados:
                                      Memoria limitada, capacidad de procesamiento limitado. */

#define STACK_SIZE          (100) /* Reserves 400 bytes for task configuration and task context. */

#define THUMB_MODE          (1ul<<24) /* PSR: Habilitar THUMB mode (2 bytes words). */

#define FIFO_SIZE           (50ul)

/*                                                 Exported Constants                                                */
/*********************************************************************************************************************/

/*                                                 Exported Variables                                                */
/*********************************************************************************************************************/

/*                                            Exported functions prototypes                                          */
/*********************************************************************************************************************/
/* Prototypes for the OS functions: */
extern void OS_Init                (uint8_t Threads); /* Receive as argument the number of threads. */

/* Exported Threads: */
extern void OS_Thread_0            (void);
extern void OS_Thread_1            (void);
extern void OS_Thread_2            (void);
extern void OS_Thread_3            (void);
extern void OS_Thread_4            (void);

/* Exported Periodic tasks: */
extern void OS_Periodic_25mS       (void);
extern void OS_Periodic_100mS      (void);
extern void OS_Periodic_250mS      (void);
extern void OS_Periodic_500mS      (void);
extern void OS_Periodic_1S         (void);


/*********************************************************************************************************************/
#endif
/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/ 