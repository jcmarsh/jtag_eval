/*****************************************************
Attempts to show that fault injection in the cache
may be done using L2C-310 Debugging features

Meant to be executed on the zybo without DrSEUs
****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include <xgpio.h>
#include "xparameters.h"
#include <xil_cache_l.h>
#include <xl2cc.h>
#include "sleep.h"
#include <unistd.h>

// For Cache Flush
#include <xil_cache_l.h>

int cache_freeze() {
  register u32 L2CCReg;

  L2CCReg = Xil_In32(XPS_L2CC_BASEADDR + XPS_L2CC_DEBUG_CTRL_OFFSET);
  printf("Cache freeze DEBUG_CTRL: 0x%08lX\n", L2CCReg);
  L2CCReg = 0x00000003;
  Xil_Out32(XPS_L2CC_BASEADDR + XPS_L2CC_DEBUG_CTRL_OFFSET, L2CCReg);

  L2CCReg = Xil_In32(XPS_L2CC_BASEADDR + XPS_L2CC_DEBUG_CTRL_OFFSET);
  printf("Post update DEBUG_CTRL: 0x%08lX\n", L2CCReg);
  
  return 0;
}

int cache_unfreeze() {
  register u32 L2CCReg;

  L2CCReg = Xil_In32(XPS_L2CC_BASEADDR + XPS_L2CC_DEBUG_CTRL_OFFSET);
  printf("Cache unfreeze DEBUG_CTRL: 0x%08lX\n", L2CCReg);
  L2CCReg = 0x00000000;
  Xil_Out32(XPS_L2CC_BASEADDR + XPS_L2CC_DEBUG_CTRL_OFFSET, L2CCReg);

  L2CCReg = Xil_In32(XPS_L2CC_BASEADDR + XPS_L2CC_DEBUG_CTRL_OFFSET);
  printf("Post update DEBUG_CTRL: 0x%08lX\n", L2CCReg);
  
  return 0;
}

int write_data(unsigned int data) {
  printf("Write data\n");

  return 0;
}

int main()
{
  unsigned int x = 0xDEADBEEF, temp;

  init_platform();

  printf("Starting program, x = %u\n", x);
  printf("X address is %p\n", &x);


  /* Attempt #1 <- Doesn't work
  // 1. Disable write back / through
  cache_freeze();

  // 2. Change a value
  x = 8;

  // 3. Re-enable write back / through
  cache_unfreeze();

  // 4. Print the value <- pull from cache
  printf("After injection, x = %u\n", x);

  // 5. Flush the cache <- doesn't write back because not dirty
  Xil_L2CacheFlush();

  // 6. Print the value again <- pull from backing memory the original value
  printf("After cache flush, x = %u\n", x);
  */

  /* Attempt #2 */
  // 1. Read good value from memory
  temp = x;
  // 2. Write bad value <- writes to cache and backing memory (I hope)
  x = 8;
  // 3. Disable write-back and linefill
  cache_freeze();
  // 4. Write good value <- should skip the cache on to backing memory
  x = temp;
  // 5. Set cache back to normal / resume execution
  cache_unfreeze();
  // 6. Print value <- should read from cache / print bad value
  printf("After injection, x = %u\n", x);
  // 7. Flush cache <- wouldn't this write back the bad value?
  Xil_L2CacheFlush();
  // 8. Print value <- should read good value from backing memory
  printf("After cache flush, x = %u\n", x);

  /* Set a breakpoint on this label to let DrSEUS restart exectuion when ready. */
  //asm("drseus_start_tag:");
        
  exit_platform();

  //xil_printf("safeword ");

  return 0;
}
