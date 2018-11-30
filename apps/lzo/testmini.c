/* testmini.c -- very simple test program for the miniLZO library

   This file is part of the LZO real-time data compression library.

   Copyright (C) 1996-2017 Markus Franz Xaver Johannes Oberhumer
   All Rights Reserved.

   The LZO library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   The LZO library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the LZO library; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

   Markus F.X.J. Oberhumer
   <markus@oberhumer.com>
   http://www.oberhumer.com/opensource/lzo/
 */


#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include <xgpio.h>

// To flush cache
#include <xil_cache_l.h>

// Don't always include this!
#include "kepler_data.h"

/*************************************************************************
// This program shows the basic usage of the LZO library.
// We will compress a block of data and decompress again.
//
// For more information, documentation, example programs and other support
// files (like Makefiles and build scripts) please download the full LZO
// package from
//    http://www.oberhumer.com/opensource/lzo/
**************************************************************************/

/* First let's include "minizo.h". */

#include "minilzo.h"


/* We want to compress the data block at 'in' with length 'IN_LEN' to
 * the block at 'out'. Because the input block may be incompressible,
 * we must provide a little more output space in case that compression
 * is not possible.
 */

//#define IN_LEN      (128*1024ul)
#define IN_LEN      (64*1024ul)
//#define IN_LEN      (32*1024ul)
//#define IN_LEN      (16*1024ul)
//#define IN_LEN      (1*1024ul)
#define OUT_LEN     (IN_LEN + IN_LEN / 16 + 64 + 3)

static unsigned char __LZO_MMODEL in  [ IN_LEN ];
static unsigned char __LZO_MMODEL out [ OUT_LEN ];
static unsigned char __LZO_MMODEL cmp [ OUT_LEN ];


/* Work-memory needed for compression. Allocate memory in units
 * of 'lzo_align_t' (instead of 'char') to make sure it is properly aligned.
 */

#define HEAP_ALLOC(var,size) \
    lzo_align_t __LZO_MMODEL var [ ((size) + (sizeof(lzo_align_t) - 1)) / sizeof(lzo_align_t) ]

static HEAP_ALLOC(wrkmem, LZO1X_1_MEM_COMPRESS);


/*************************************************************************
//
**************************************************************************/
int lzo_test(lzo_uint* in_len, lzo_uint* out_len) {
    int r;
    lzo_uint new_len;

/*
 * Step 3: compress from 'in' to 'out' with LZO1X-1
 */
    r = lzo1x_1_compress(in,*in_len,out,out_len,wrkmem);
    if (r == LZO_E_OK) { }
      //printf("compressed %lu bytes into %lu bytes\n",
      //      (unsigned long) in_len, (unsigned long) out_len);
    else
    {
        /* this should NEVER happen */
        printf("internal error - compression failed: %d\n", r);
        return 2;
    }
    /* check for an incompressible block */
    if (*out_len >= *in_len)
    {
        printf("This block contains incompressible data.\n");
        return 3;
    }

/*
 * Step 4: decompress again, now going from 'out' to 'in'
 */
    new_len = *in_len;
    r = lzo1x_decompress(out,*out_len,in,&new_len,NULL);
    if (r == LZO_E_OK && new_len == *in_len) { }
        //printf("decompressed %lu bytes back into %lu bytes\n",
        //    (unsigned long) out_len, (unsigned long) in_len);
    else
    {
        /* this should NEVER happen */
        printf("internal error - decompression failed: %d\n", r);
        return 1;
    }

    //printf("\nminiLZO simple compression test passed.\n");
    return 0;
}


int main(int argc, char *argv[])
{
    int ret_val = 0;
    lzo_uint in_len;
    lzo_uint out_len;

    if (argc < 0 && argv == NULL)   /* avoid warning about unused args */
        return 0;

    printf("\nLZO real-time data compression library (v%s, %s).\n",
           lzo_version_string(), lzo_version_date());
    printf("Copyright (C) 1996-2017 Markus Franz Xaver Johannes Oberhumer\nAll Rights Reserved.\n\n");

    // Init zybo platform
    init_platform();

    /*
     * Step 1: initialize the LZO library
     */
    if (lzo_init() != LZO_E_OK)
    {
        printf("internal error - lzo_init() failed !!!\n");
        printf("(this usually indicates a compiler bug - try recompiling\nwithout optimizations, and enable '-DLZO_DEBUG' for diagnostics)\n");
        return 3;
    }


    /*
     * Step 2: prepare the input block that will get compressed.
     *         We just fill it with zeros in this example program,
     *         but you would use your real-world data here.
     */
    in_len = IN_LEN;
    // Set to all 0's
    /*
    lzo_memset(in,0,in_len);
    printf("Setting input to all 0's\n");
    */

    // Set to all random... if I'm doing this right
    // All random is incompressible, so try making some data repeated
    /*
    for (int i = 0; i < in_len / 4; i = i + 4) {
        in[i] = rand() % 256;
        in[i+1] = in[i];
        in[i+2] = in[i];
        in[i+3] = in[i];
    }
    printf("Setting input to random: 0x%02X 0x%02X 0x%02X 0x%02X\n", in[0], in[1], in[2], in[3]);
    printf("Setting input to random: 0x%02X 0x%02X 0x%02X 0x%02X\n", in[0], in[4], in[8], in[12]);
    */

    // Set data to be from the kepler_data array
    printf("Using kepler data, no more that 32K: %d\n", in_len);
    memcpy(in, kepler_data, in_len);
    printf("Setting input to Kepler: 0x%02X 0x%02X 0x%02X 0x%02X\n", in[0], in[1], in[2], in[3]);
    printf("Setting input to Kepler: 0x%02X 0x%02X 0x%02X 0x%02X\n", in[4], in[5], in[6], in[7]);

    // Run once for warmup, tags on second - JM
    /*
    ret_val = lzo_test(&in_len, &out_len);
    if (ret_val == 0) {
        printf("compressed %lu bytes into %lu bytes\n",
               (unsigned long) in_len, (unsigned long) out_len);
        printf("decompressed %lu bytes back into %lu bytes\n",
               (unsigned long) out_len, (unsigned long) in_len);
        printf("\nminiLZO simple compression test passed.\n");
    }
    */

    // Save data to test against fault injection
    //memcpy(cmp, out, in_len);

    Xil_L2CacheFlush();
    asm("drseus_start_tag:");
    ret_val = lzo_test(&in_len, &out_len);
    asm("drseus_end_tag:");
    Xil_L2CacheFlush();

    if (ret_val == 0) {
        printf("compressed %lu bytes into %lu bytes\n",
               (unsigned long) in_len, (unsigned long) out_len);
        printf("decompressed %lu bytes back into %lu bytes\n",
               (unsigned long) out_len, (unsigned long) in_len);
        printf("\nminiLZO simple compression test passed.\n");
    }

    // check if results are the same
    /*
    ret_val = memcmp(cmp, out, in_len);
    if (ret_val != 0) {
      printf("Data does not match with warm-up run\n");
    }
    */

    exit_platform();

    printf("safeword ");
}

/* vim:set ts=4 sw=4 et: */
