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
#include "xparameters.h"
#include "sleep.h"
#include <unistd.h>

int fib_i(int n) {
	int ii;
	int prev_0 = 1;
	int prev_1 = 1;
	int old_val = 0;

	for (ii = 2; ii < n; ii++) {
		old_val = prev_0;
		prev_0 += prev_1;
		prev_1 = old_val;
	}
	return prev_0;
}

int fib_r(int n) {
	if (n == 1) {
		return 1;
	} else if (n == 2) {
		return 1;
	} else {
		return fib_r(n-1) + fib_r(n-2);
	}
}

#define FIB_COUNT 38 // 40 takes about 15 seconds

int main()
{
   //XGpio input, output;
	XGpio output;
	int fib_out_i = 0;
	int fib_out_r = 0;
	int fib_sum_i = 0;
	int fib_sum_r = 0;
	int loop_count = 0;
	int ii = 0;
	int switch_data = 0;
	int switch_data_error = 0;

	// XGpio_Initialize(&input, XPAR_AXI_GPIO_0_DEVICE_ID);	//initialize input XGpio variable
	XGpio_Initialize(&output, XPAR_AXI_GPIO_1_DEVICE_ID);	//initialize output XGpio variable

	// XGpio_SetDataDirection(&input, 1, 0xF);			//set first channel tristate buffer to input
	// XGpio_SetDataDirection(&input, 2, 0xF);			//set second channel tristate buffer to input

	XGpio_SetDataDirection(&output, 1, 0x0);		//set first channel tristate buffer to output
	init_platform();

	/* Let the debugger catch up */
	sleep(1);

	xil_printf("Starting program\n\r");
	while(loop_count < 6){
		xil_printf("Starting big loop: %d\n\r", loop_count++);
		fib_sum_i = 0;
		fib_sum_r = 0;

		// xil_printf("sizeof int: %d, sizeof long: %d\n", sizeof(int), sizeof(long));
		switch_data = (switch_data + 1) % 2;	// flip light
		XGpio_DiscreteWrite(&output, 1, switch_data | switch_data_error);	//write switch data to the LEDs

		for (ii = 1; ii <= FIB_COUNT; ii++) {
			fib_out_i = fib_i(ii);
			fib_out_r = fib_r(ii);

			if (fib_out_i != fib_out_r) {
				xil_printf("Fibs do not match: %d, %d %d\n\r", ii, fib_out_i, fib_out_r);
			}
			if (fib_out_i < 0 || fib_out_r < 0) {
				xil_printf("Fib overflow: %d, %d %d\n\r", ii, fib_out_i, fib_out_r);
			}
			fib_sum_i += fib_out_i;
			fib_sum_r += fib_out_r;
			// xil_printf("Fib sum %d: %d (%d)\n\r", ii, fib_sum_i, fib_out_i);
		}
		if (fib_sum_i != fib_sum_r) {
			xil_printf("MISMATCH in results: %d, %d\n\r", fib_sum_i, fib_sum_r);
			switch_data_error = 4;
		} else {
			xil_printf("Result: %d, %d\n\r", fib_sum_i, fib_sum_r);
		}
	}
	cleanup_platform();
	xil_printf("safeword ");
	return 0;
}
