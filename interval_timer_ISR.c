#include "address_map_arm.h"

extern volatile int tick2;
/*****************************************************************************
 * Interval timer interrupt service routine
 *
 * This code increments the tick variable, and clears the interrupt
 *
******************************************************************************/

void interval_timer_ISR()
{
    volatile int *interval_timer_ptr = (int *)TIMER_BASE;
    *(interval_timer_ptr) = 0; // Clear the interrupt

    ++tick2; // used by main program
    return;
}
