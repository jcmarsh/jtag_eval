/*
 * Copyright (c) 2009-2012 Xilinx, Inc.  All rights reserved.
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
// #include "xil_cache.h"
#include <xil_cache_l.h>
#include "xtime_l.h"
#include "sleep.h"

#include "platform.h"

#include "input.h"

char matrix_multiplication(int a[A_ROWS][A_COLUMNS], int b[B_ROWS][B_COLUMNS], int correct_answer[A_ROWS][B_COLUMNS], int id);

#ifdef MEM_USAGE
	INPUT
#endif

int main()
{
    init_platform();

    Xil_L1ICacheEnable();
    Xil_L1DCacheEnable();
    Xil_L2CacheEnable();

    char isEqual = 1;

    XTime time1;
    XTime time2;

    int count = 0;

    while(1)
    {
		XTime_GetTime((XTime *) &time1);

		printf("\n\r__________TEST_MATRIX_MULTIPLICATION__________\n\r");

		// TODO: Need to make this a build option and make sure matches cache enable calls
		printf("CACHE_L1I ON\n\r");
		printf("CACHE_L1D ON\n\r");
		printf("CACHE_L2 ON\n\r");

#ifndef MEM_USAGE
	INPUT
#endif

		isEqual &= matrix_multiplication(a_0, b_0, c_0, 0);
		isEqual &= matrix_multiplication(a_1, b_1, c_1, 1);
		isEqual &= matrix_multiplication(a_2, b_2, c_2, 2);
		isEqual &= matrix_multiplication(a_3, b_3, c_3, 3);
		isEqual &= matrix_multiplication(a_4, b_4, c_4, 4);
		isEqual &= matrix_multiplication(a_5, b_5, c_5, 5);
		isEqual &= matrix_multiplication(a_6, b_6, c_6, 6);
		isEqual &= matrix_multiplication(a_7, b_7, c_7, 7);
		isEqual &= matrix_multiplication(a_8, b_8, c_8, 8);
		isEqual &= matrix_multiplication(a_9, b_9, c_9, 9);
		isEqual &= matrix_multiplication(a_10, b_10, c_10, 10);
		isEqual &= matrix_multiplication(a_11, b_11, c_11, 11);
		isEqual &= matrix_multiplication(a_12, b_12, c_12, 12);
		isEqual &= matrix_multiplication(a_13, b_13, c_13, 13);
		isEqual &= matrix_multiplication(a_14, b_14, c_14, 14);
		isEqual &= matrix_multiplication(a_15, b_15, c_15, 15);
		isEqual &= matrix_multiplication(a_16, b_16, c_16, 16);
		isEqual &= matrix_multiplication(a_17, b_17, c_17, 17);
		isEqual &= matrix_multiplication(a_18, b_18, c_18, 18);
		isEqual &= matrix_multiplication(a_19, b_19, c_19, 19);
		isEqual &= matrix_multiplication(a_20, b_20, c_20, 20);
		isEqual &= matrix_multiplication(a_21, b_21, c_21, 21);
		isEqual &= matrix_multiplication(a_22, b_22, c_22, 22);
		isEqual &= matrix_multiplication(a_23, b_23, c_23, 23);
		isEqual &= matrix_multiplication(a_24, b_24, c_24, 24);
		isEqual &= matrix_multiplication(a_25, b_25, c_25, 25);
		isEqual &= matrix_multiplication(a_26, b_26, c_26, 26);
		isEqual &= matrix_multiplication(a_27, b_27, c_27, 27);
		isEqual &= matrix_multiplication(a_28, b_28, c_28, 28);
		isEqual &= matrix_multiplication(a_29, b_29, c_29, 29);
		isEqual &= matrix_multiplication(a_30, b_30, c_30, 30);
		isEqual &= matrix_multiplication(a_31, b_31, c_31, 31);
		isEqual &= matrix_multiplication(a_32, b_32, c_32, 32);
		isEqual &= matrix_multiplication(a_33, b_33, c_33, 33);
		isEqual &= matrix_multiplication(a_34, b_34, c_34, 34);
		isEqual &= matrix_multiplication(a_35, b_35, c_35, 35);
		isEqual &= matrix_multiplication(a_36, b_36, c_36, 36);
		isEqual &= matrix_multiplication(a_37, b_37, c_37, 37);
		isEqual &= matrix_multiplication(a_38, b_38, c_38, 38);
		isEqual &= matrix_multiplication(a_39, b_39, c_39, 39);
		isEqual &= matrix_multiplication(a_40, b_40, c_40, 40);
		isEqual &= matrix_multiplication(a_41, b_41, c_41, 41);
		isEqual &= matrix_multiplication(a_42, b_42, c_42, 42);
		isEqual &= matrix_multiplication(a_43, b_43, c_43, 43);
		isEqual &= matrix_multiplication(a_44, b_44, c_44, 44);
		isEqual &= matrix_multiplication(a_45, b_45, c_45, 45);
		isEqual &= matrix_multiplication(a_46, b_46, c_46, 46);
		isEqual &= matrix_multiplication(a_47, b_47, c_47, 47);
		isEqual &= matrix_multiplication(a_48, b_48, c_48, 48);
		isEqual &= matrix_multiplication(a_49, b_49, c_49, 49);
		isEqual &= matrix_multiplication(a_50, b_50, c_50, 50);
		isEqual &= matrix_multiplication(a_51, b_51, c_51, 51);
		isEqual &= matrix_multiplication(a_52, b_52, c_52, 52);
		isEqual &= matrix_multiplication(a_53, b_53, c_53, 53);
		isEqual &= matrix_multiplication(a_54, b_54, c_54, 54);
		isEqual &= matrix_multiplication(a_55, b_55, c_55, 55);
		isEqual &= matrix_multiplication(a_56, b_56, c_56, 56);
		isEqual &= matrix_multiplication(a_57, b_57, c_57, 57);
		isEqual &= matrix_multiplication(a_58, b_58, c_58, 58);
		isEqual &= matrix_multiplication(a_59, b_59, c_59, 59);
		isEqual &= matrix_multiplication(a_60, b_60, c_60, 60);
		isEqual &= matrix_multiplication(a_61, b_61, c_61, 61);
		isEqual &= matrix_multiplication(a_62, b_62, c_62, 62);
		isEqual &= matrix_multiplication(a_63, b_63, c_63, 63);
		isEqual &= matrix_multiplication(a_64, b_64, c_64, 64);
		isEqual &= matrix_multiplication(a_65, b_65, c_65, 65);
		isEqual &= matrix_multiplication(a_66, b_66, c_66, 66);
		isEqual &= matrix_multiplication(a_67, b_67, c_67, 67);
		isEqual &= matrix_multiplication(a_68, b_68, c_68, 68);
		isEqual &= matrix_multiplication(a_69, b_69, c_69, 69);
		isEqual &= matrix_multiplication(a_70, b_70, c_70, 70);
		isEqual &= matrix_multiplication(a_71, b_71, c_71, 71);
		isEqual &= matrix_multiplication(a_72, b_72, c_72, 72);
		isEqual &= matrix_multiplication(a_73, b_73, c_73, 73);
		isEqual &= matrix_multiplication(a_74, b_74, c_74, 74);
		isEqual &= matrix_multiplication(a_75, b_75, c_75, 75);
		isEqual &= matrix_multiplication(a_76, b_76, c_76, 76);
		isEqual &= matrix_multiplication(a_77, b_77, c_77, 77);
		isEqual &= matrix_multiplication(a_78, b_78, c_78, 78);
		isEqual &= matrix_multiplication(a_79, b_79, c_79, 79);
		isEqual &= matrix_multiplication(a_80, b_80, c_80, 80);
		isEqual &= matrix_multiplication(a_81, b_81, c_81, 81);
		isEqual &= matrix_multiplication(a_82, b_82, c_82, 82);
		isEqual &= matrix_multiplication(a_83, b_83, c_83, 83);
		isEqual &= matrix_multiplication(a_84, b_84, c_84, 84);
		isEqual &= matrix_multiplication(a_85, b_85, c_85, 85);
		isEqual &= matrix_multiplication(a_86, b_86, c_86, 86);
		isEqual &= matrix_multiplication(a_87, b_87, c_87, 87);
		isEqual &= matrix_multiplication(a_88, b_88, c_88, 88);
		isEqual &= matrix_multiplication(a_89, b_89, c_89, 89);
		isEqual &= matrix_multiplication(a_90, b_90, c_90, 90);
		isEqual &= matrix_multiplication(a_91, b_91, c_91, 91);
		isEqual &= matrix_multiplication(a_92, b_92, c_92, 92);
		isEqual &= matrix_multiplication(a_93, b_93, c_93, 93);
		isEqual &= matrix_multiplication(a_94, b_94, c_94, 94);
		isEqual &= matrix_multiplication(a_95, b_95, c_95, 95);
		isEqual &= matrix_multiplication(a_96, b_96, c_96, 96);
		isEqual &= matrix_multiplication(a_97, b_97, c_97, 97);
		isEqual &= matrix_multiplication(a_98, b_98, c_98, 98);
		isEqual &= matrix_multiplication(a_99, b_99, c_99, 99);
		isEqual &= matrix_multiplication(a_100, b_100, c_100, 100);
		isEqual &= matrix_multiplication(a_101, b_101, c_101, 101);
		isEqual &= matrix_multiplication(a_102, b_102, c_102, 102);
		isEqual &= matrix_multiplication(a_103, b_103, c_103, 103);
		isEqual &= matrix_multiplication(a_104, b_104, c_104, 104);
		isEqual &= matrix_multiplication(a_105, b_105, c_105, 105);
		isEqual &= matrix_multiplication(a_106, b_106, c_106, 106);
		isEqual &= matrix_multiplication(a_107, b_107, c_107, 107);
		isEqual &= matrix_multiplication(a_108, b_108, c_108, 108);
		isEqual &= matrix_multiplication(a_109, b_109, c_109, 109);
		isEqual &= matrix_multiplication(a_110, b_110, c_110, 110);
		isEqual &= matrix_multiplication(a_111, b_111, c_111, 111);
		isEqual &= matrix_multiplication(a_112, b_112, c_112, 112);
		isEqual &= matrix_multiplication(a_113, b_113, c_113, 113);
		isEqual &= matrix_multiplication(a_114, b_114, c_114, 114);
		isEqual &= matrix_multiplication(a_115, b_115, c_115, 115);
		isEqual &= matrix_multiplication(a_116, b_116, c_116, 116);
		isEqual &= matrix_multiplication(a_117, b_117, c_117, 117);
		isEqual &= matrix_multiplication(a_118, b_118, c_118, 118);
		isEqual &= matrix_multiplication(a_119, b_119, c_119, 119);
		isEqual &= matrix_multiplication(a_120, b_120, c_120, 120);
		isEqual &= matrix_multiplication(a_121, b_121, c_121, 121);
		isEqual &= matrix_multiplication(a_122, b_122, c_122, 122);
		isEqual &= matrix_multiplication(a_123, b_123, c_123, 123);
		isEqual &= matrix_multiplication(a_124, b_124, c_124, 124);
		isEqual &= matrix_multiplication(a_125, b_125, c_125, 125);
		isEqual &= matrix_multiplication(a_126, b_126, c_126, 126);
		isEqual &= matrix_multiplication(a_127, b_127, c_127, 127);
		isEqual &= matrix_multiplication(a_128, b_128, c_128, 128);
		isEqual &= matrix_multiplication(a_129, b_129, c_129, 129);
		isEqual &= matrix_multiplication(a_130, b_130, c_130, 130);
		isEqual &= matrix_multiplication(a_131, b_131, c_131, 131);
		isEqual &= matrix_multiplication(a_132, b_132, c_132, 132);
		isEqual &= matrix_multiplication(a_133, b_133, c_133, 133);
		isEqual &= matrix_multiplication(a_134, b_134, c_134, 134);
		isEqual &= matrix_multiplication(a_135, b_135, c_135, 135);
		isEqual &= matrix_multiplication(a_136, b_136, c_136, 136);
		isEqual &= matrix_multiplication(a_137, b_137, c_137, 137);
		isEqual &= matrix_multiplication(a_138, b_138, c_138, 138);
		isEqual &= matrix_multiplication(a_139, b_139, c_139, 139);

		if(isEqual == 1)
		{
			printf("TEST_MATRIX_MULTIPLICATION PASSED\n\r");
		}
		else
		{
			printf("TEST_MATRIX_MULTIPLICATION FAILED\n\r");
		}

		XTime_GetTime((XTime *) &time2);
		printf("EXECUTION_TIME %lld\n\r", time2-time1);

		printf("______________________________________________\n\r");
		printf("\n\r");

		sleep(5);
		count++;
		if (count > 5) printf("safeword \n");
    }

    return 0;
}

char matrix_multiplication(int a[A_ROWS][A_COLUMNS], int b[B_ROWS][B_COLUMNS], int correct_answer[A_ROWS][B_COLUMNS], int id)
{
	int resultant[A_ROWS][B_COLUMNS];
	char isEqual = 1;
	int i, j, k;

	for(i=0; i<A_ROWS; i++)
	{
		for(j=0; j<B_COLUMNS; j++)
		{
			resultant[i][j] = 0;
		}
	}

	for(i=0; i<A_ROWS; i++)
	{
		for(j=0; j<B_COLUMNS; j++)
		{
			for(k=0; k<A_COLUMNS; k++)
			{
				resultant[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for(i=0; i<A_ROWS; i++)
	{
		for(j=0; j<B_COLUMNS; j++)
		{
			if(resultant[i][j] != correct_answer[i][j])
			{
				isEqual = 0;
			}
		}
	}

	return isEqual;
}
