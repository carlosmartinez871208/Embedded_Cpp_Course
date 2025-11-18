#include "fw.h"

inline constexpr Pin_ConfigType PD0 = {
    PORTD,   // Port
    PIN0,    // Pin
    OUTPUT,  // Mode
    PUSH_PULL, // OutputType
    LOW_SPEED, // OutputSpeed
    NO_PULL,   // PullUpDown
    AF0        // Alternate
};

void OS_Thread_0 ()
{
    Pin_ConfigType pinList[] = {PD0};
    Port_ConfigType portCfg{pinList,1};
    Port BSP(&portCfg);
    while(true){
        BSP.TooglePin(0u);
        // Send data to FIFO
        //OS_FIFOPut(0xDEADBEEFul);
        //OS_Yield();
    }
}