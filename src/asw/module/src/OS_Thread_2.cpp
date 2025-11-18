#include "fw.h"

inline constexpr Pin_ConfigType PD2 = {
    PORTD,   // Port
    PIN2,    // Pin
    OUTPUT,  // Mode
    PUSH_PULL, // OutputType
    LOW_SPEED, // OutputSpeed
    NO_PULL,   // PullUpDown
    AF0        // Alternate
};

void OS_Thread_2 ()
{
    Pin_ConfigType pinList[] = {PD2};
    Port_ConfigType portCfg{pinList,1};
    Port BSP(&portCfg);
    while(true){
        BSP.TooglePin(0u);
        //OS_Yield();
    }
}