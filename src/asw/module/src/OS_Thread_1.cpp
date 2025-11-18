#include "fw.h"

inline constexpr Pin_ConfigType PD1 = {
    PORTD,   // Port
    PIN1,    // Pin
    OUTPUT,  // Mode
    PUSH_PULL, // OutputType
    LOW_SPEED, // OutputSpeed
    NO_PULL,   // PullUpDown
    AF0        // Alternate
};

void OS_Thread_1 ()
{
    //uint32_t Thread0_data = 0ul;
    Pin_ConfigType pinList[] = {PD1};
    Port_ConfigType portCfg{pinList,1};
    Port BSP(&portCfg);
    while(true){
        BSP.TooglePin(0u);
        //Thread0_data = OS_FIFOGet();
        //(void)Thread0_data;
        //OS_Yield();
    }
}