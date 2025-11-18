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
#include "os.h"

#ifdef __cplusplus
extern "C" {
#endif
void PendSV_Handler(void);
void OS_Scheduler_Kernel_Control(void);
#ifdef __cplusplus
}
#endif

/*                                                        Types                                                      */
/*********************************************************************************************************************/

/*                                                       Macros                                                      */
/*********************************************************************************************************************/
#define _25_MS_TASK_    (uint16_t)(25)
#define _100_MS_TASK_   (uint16_t)(100)
#define _250_MS_TASK_   (uint16_t)(250)
#define _500_MS_TASK_   (uint16_t)(500)
#define _1_S_TASK_      (uint16_t)(1000)

/*                                                      Constants                                                    */
/*********************************************************************************************************************/
static func_ptr Thread_Callouts  [MAX_NUMBER_OF_TASKS] = {\
    &OS_Thread_0,&OS_Thread_1,&OS_Thread_2,&OS_Thread_3,&OS_Thread_4
};

static func_ptr PeriodicTasks_Callouts [MAX_NUMBER_OF_TASKS] = {\
    &OS_Periodic_25mS,&OS_Periodic_100mS,&OS_Periodic_250mS,&OS_Periodic_500mS,&OS_Periodic_1S
};

static TCB_Type Thread_Configuration [MAX_NUMBER_OF_TASKS]; /* Este arreglo contiene la configuracion de nuestro thread. */

static uint32_t TCB_Stack [MAX_NUMBER_OF_TASKS][STACK_SIZE];

static uint8_t Thread_Counter;

TCB_Type* Current_Thread_Pointer;

/* Tick Configuration: */
inline constexpr SysTick_ConfigType SYSTICK_CONFIG = {
    SYSTICK_ENABLE,
    SYSTICK_TICKINT_ENABLE,
    SYSTICK_PROCESSOR_CLOCK,
    SYSTICK_1_MS_TICKS
};

/*                                                   Local Variables                                                 */
/*********************************************************************************************************************/
static uint32_t put_index;
static uint32_t get_index;
static uint32_t os_fifo[FIFO_SIZE];
static sint32_t current_fifo_size;
static uint32_t lost_data;

static uint16_t PT0_counter=0u;
static uint16_t PT1_counter=0u;
static uint16_t PT2_counter=0u;
static uint16_t PT3_counter=0u;
static uint16_t PT4_counter=0u;

/*                                                 Imported Variables                                                */
/*********************************************************************************************************************/

/*                                             Local functions prototypes                                            */
/*********************************************************************************************************************/
static void OS_Scheduler_Launch         (void);

/*                                           Local functions implementation                                          */
/*********************************************************************************************************************/
void OS_Scheduler_Launch (void){
    __asm("ldr r0,=Current_Thread_Pointer"); /* First cycle: R0 = &kernel_os_threads[0]. */
    __asm("ldr r2,[r0]");                    /* R2 = R0 = current_thread_ptr = &kernel_os_threads[0]. */
    __asm("ldr sp,[r2]");                    /* SP = R2 = current_thread_ptr = R0 = &kernel_os_threads[0]. */
    __asm("pop {r4-r11}");                   /* Restores r4,r5,r6,r7,r8,r10,r11: */
    __asm("pop {r0-r3}");                    /* Restores r0,r1,r2,r3: */
    __asm("pop {r12}");                      /* Restore Link Register (R12): */
    __asm("add sp,sp,#4");                   /* Skips LR: */
    __asm("pop {lr}");                       /* Create a new start location by popping LR: */
    __asm("add sp,sp,#4");                   /* Skip PSR by adding 4 to SP: */
    __asm("cpsie i");                        /* Enable Global interrupts: */
    __asm("bx lr");                          /* Return from exception. */
}

extern "C" void OS_Scheduler_Kernel_Control (void){
    /* //Increment periodic task counters
    PT0_counter++;
    PT1_counter++;
    PT2_counter++;
    PT3_counter++;
    PT4_counter++;
    if(_25_MS_TASK_ == PT0_counter){
        PeriodicTasks_Callouts[0]();
        PT0_counter=0;
    }else{}
    if(_100_MS_TASK_ == PT1_counter){
        PeriodicTasks_Callouts[1]();
        PT1_counter=0;
    }else{}
    if(_250_MS_TASK_ == PT2_counter){
        PeriodicTasks_Callouts[2]();
        PT2_counter=0;
    }else{}
    if(_500_MS_TASK_ == PT3_counter){
        PeriodicTasks_Callouts[3]();
        PT3_counter=0;
    }else{}
    if(_1_S_TASK_ == PT4_counter){
        PeriodicTasks_Callouts[4]();
        PT4_counter=0;
    }else{}
    */
    Thread_Counter++;
    Current_Thread_Pointer = &Thread_Configuration[Thread_Counter];
    if(MAX_NUMBER_OF_TASKS==Thread_Counter){
        Thread_Counter=0;
        Current_Thread_Pointer = &Thread_Configuration[Thread_Counter];
    }else{}
}

/*                                         Imported functions implementation                                         */
/*********************************************************************************************************************/
void OS_Init (uint8_t Threads){
    for(uint8_t index=0u;index<Threads;index++){
        Thread_Configuration[index].Stack_Pointer = &TCB_Stack[index][STACK_SIZE-16];
        TCB_Stack[index][STACK_SIZE-1] = THUMB_MODE;
        TCB_Stack[index][STACK_SIZE-2] = (uint32_t)Thread_Callouts[index];
    }
    Thread_Configuration[0].Status = 0u; /* Ready status*/
    Current_Thread_Pointer = &Thread_Configuration[0];
    SysTick systick(&SYSTICK_CONFIG);
    OS_Scheduler_Launch();
}

/* PendSV */
__attribute__((naked)) void PendSV_Handler (void){
    __asm("cpsid i");                            /* Suspend current thread: current_thread_ptr = &kernel_os_threads[0]. Disable global interrupt:*/
    __asm("push {r4-r11}");                      /* Save r4,r5,r6,r7,r8,r10,r11: this is the current context. */
    __asm("ldr r0,=Current_Thread_Pointer");         /* R0 = current_thread_ptr = &kernel_os_threads[0]. */
    __asm("ldr r1,[r0]");                        /* R1 = R0 = current_thread_ptr = &kernel_os_threads[0]. */
    __asm("str sp,[r1]");                        /* R1 = SP = R0 = current_thread_ptr = &kernel_os_threads[0]. */
    __asm("push {r0,lr}");                       /* Saves context. */
    __asm("bl OS_Scheduler_Kernel_Control");   /* Calls a function that performs round robin scheduling. */
    __asm("pop {r0,lr}");                        /* Restores context. */
    __asm("ldr r1,[r0]");                        /* R1 = R0 = current_thread_ptr = &kernel_os_threads[1]. */
    __asm("ldr sp,[r1]");                        /* SP = R1 = &kernel_os_threads[1]. */
    __asm("pop {r4-r11}");                       /* Restores r4,r5,r6,r7,r8,r10,r11: */
    __asm("cpsie i");                            /* Enables interrutps */
    __asm("bx lr");                              /* Return from exception. */
}

void OS_Yield (void){
    SYSTICK->cvr = SYST_CVR_CURRENT_CLR; /* Clear current value to trigger SysTick */
    SCB_ICSR |= SCB_ISCR_SET_PEN_BIT; /* Set PendSV to pending */
}

/* Declare semaphores as global variables:
** sint32_t semaphore1;
*/

void OS_SemaphoreInit (sint32_t* semaphore,sint32_t value){
    *semaphore = value;
}

void OS_SemaphoreSet (sint32_t* semaphore){
    __disable_irq();
    *semaphore +=1;
    __enable_irq();
}

void OS_SemaphoreWait (sint32_t* semaphore){
    __disable_irq();
    while(*semaphore <= 0){
        __disable_irq();
        __enable_irq();
    }
    *semaphore -=1;
    __enable_irq();
}

void OS_FIFOInit(void){
    put_index = 0ul;
    get_index = 0ul;
    OS_SemaphoreInit(&current_fifo_size,0ul);
    lost_data = 0ul;
}

boolean OS_FIFOPut (uint32_t data){
    if(FIFO_SIZE == current_fifo_size){
        lost_data++;
        return false;
    }else{}
    os_fifo[put_index] = data;
    put_index = (put_index+1ul)%FIFO_SIZE;
    OS_SemaphoreSet(&current_fifo_size);
    return true;
}

uint32_t OS_FIFOGet (void){
    uint32_t data;
    OS_SemaphoreWait(&current_fifo_size);
    __disable_irq();
    data = os_fifo[get_index];
    get_index = (get_index+1ul)%FIFO_SIZE;
    __enable_irq();
    return data;
}

/***************************************************Project Logs*******************************************************
 *|    ID   |     Ticket    |     Date    |                               Description                                 |
 *|---------|---------------|-------------|---------------------------------------------------------------------------|
 *|         |               |             |                                                                           |
**********************************************************************************************************************/#
