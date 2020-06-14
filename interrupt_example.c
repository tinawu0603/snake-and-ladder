#include "address_map_arm.h"

/* setup HPS timer */
void config_HPS_timer(int counter)
{
    // timer 0
    volatile int *HPS_timer_ptr = (int *)HPS_TIMER0_BASE; // timer base address

    *(HPS_timer_ptr + 0x2) = 0; // write to control register to stop timer
    *(HPS_timer_ptr) = counter; // write to timer load register

    /* write to control register to start timer, with interrupts */
    *(HPS_timer_ptr + 2) = 0b011; // int mask = 0, mode = 1, enable = 1
}

/* setup the interval timer interrupts in the FPGA */
void config_interval_timer(int counter)
{
    volatile int *interval_timer_ptr =
        (int *)TIMER_BASE; // interal timer base address

    *(interval_timer_ptr + 0x2) = (counter & 0xFFFF);
    *(interval_timer_ptr + 0x3) = (counter >> 16) & 0xFFFF;

    /* start interval timer, enable its interrupts */
    *(interval_timer_ptr + 1) = 0x7; // STOP = 0, START = 1, CONT = 1, ITO = 1
}
