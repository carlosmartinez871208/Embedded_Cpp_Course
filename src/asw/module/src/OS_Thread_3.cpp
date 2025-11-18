#include "fw.h"

inline constexpr Pin_ConfigType PD3 = {
    PORTD,   // Port
    PIN3,    // Pin
    OUTPUT,  // Mode
    PUSH_PULL, // OutputType
    LOW_SPEED, // OutputSpeed
    NO_PULL,   // PullUpDown
    AF0        // Alternate
};

void OS_Thread_3 ()
{
    Pin_ConfigType pinList[] = {PD3};
    Port_ConfigType portCfg{pinList,1};
    Port BSP(&portCfg);
    while(true){
        BSP.TooglePin(0u);
        //OS_Yield();
    }
}