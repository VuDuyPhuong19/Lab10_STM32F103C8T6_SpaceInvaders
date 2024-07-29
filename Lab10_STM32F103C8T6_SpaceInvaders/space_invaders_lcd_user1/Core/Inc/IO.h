#ifndef _IO_H_
#define _IO_H_

#include <stdint.h>

// Initialize GPIO Port for a switch and an LED
void IO_Init(void);

// Toggle the output stage of the LED
void IO_HeartBeat(uint32_t Pin);

#endif