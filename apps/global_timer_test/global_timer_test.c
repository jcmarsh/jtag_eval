/*****************************************************
Getting Started Guide for Zybo

This demo displays the status of the switches on the
LEDs and prints a message to the serial communication
when a button is pressed.

Terminal Settings:
   -Baud: 115200
   -Data bits: 8
   -Parity: no
   -Stop bits: 1

1/6/14: Created by MarshallW

Modifying to make a simple program to inject faults into.
Needs to be computation heavy. Recursive fib seemed to
crash the system... guessing it overwrote the stack.
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include <xgpio.h>
#include <xtime_l.h>
#include "xparameters.h"
#include "sleep.h"
#include <unistd.h>

// For Cache Flush
#include <xil_cache_l.h>

int main()
{
	init_platform();

	print("Starting program\n\r");

	// Just set time, get current time, sleep 1s, get new time, print
	return 0;
}
