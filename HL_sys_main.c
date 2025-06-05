#include "HL_gio.h"              // GIO header for input/output operations
//#include "HL_gio.c"
#include "HL_sys_common.h"        // System common definitions
#include <stdio.h>


/**
 * @fn      int main(void)
 * @brief   Application main function
*
 * Initializes the GIO module, sets the direction of the GIO pins, and enters
 * an infinite loop where the state of the pins can be manipulated.
 */
int main(void)
{
// Initialize the GIO module
gioInit();

    //    // Set the direction for GIO Port B: Pin 6 as output (0x40 = 01000000b)
    gioSetDirection(gioPORTB, 0x40);
    // Set GIO Port B, Pin 6 to high (1)
    gioSetBit(gioPORTB, 6, 1);

// Infinite loop to keep the microcontroller running
while (1)
{
// Future logic or operations could be added here
//if (gioGetPort(gioPORTA));
//{
//    printf("aaaaaaa");

}
}
