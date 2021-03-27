/*
 * main.c
 *
 * 
 *
 * description: Blinks 1 on-board LED at roughly 1 second intervals. system 
 *   clock is running from HSI which is 16 Mhz. Delay function is just a simple 
 *   counter so is not accurate and the delay time will change based on the 
 *   optimization flags.
 */

#include "stm32g0xx.h"
#include "cmsis_device.h"
#include "stdio.h"
void Hard_Fault_Handler(uint32_t stack[]);

__asm void HardFault_Handler(void){
	asm volatile();

}
enum { r0, r1, r2, r3, r12, lr, pc, psr};

int main(void);
void delay(volatile uint32_t);


int main(void) {



    while(1) {

    return 0;
}

void Hard_Fault_Handler(uint32_t stack[])
{
   static char msg[80];
  // printErrorMsg("In Hard Fault Handler\n");
  // sprintf(msg, "SCB->HFSR = 0x%08lx\n", SCB->HFSR);
  // printErrorMsg(msg);
   if ((SCB->HFSR & (1 << 30)) != 0) {
    //   printErrorMsg("Forced Hard Fault\n");
       //sprintf(msg, "SCB->CFSR = 0x%08lx\n", SCB->CFSR );
      // printErrorMsg(msg);
       if((SCB->CFSR & 0xFFFF0000) != 0) {
        // printUsageErrorMsg(SCB->CFSR);
      }
   }

   sprintf(msg, "r0  = 0x%08lx\n", stack[r0]);  printErrorMsg(msg);
   sprintf(msg, "r1  = 0x%08lx\n", stack[r1]);  printErrorMsg(msg);
   sprintf(msg, "r2  = 0x%08lx\n", stack[r2]);  printErrorMsg(msg);
   sprintf(msg, "r3  = 0x%08lx\n", stack[r3]);  printErrorMsg(msg);
   sprintf(msg, "r12 = 0x%08lx\n", stack[r12]); printErrorMsg(msg);
   sprintf(msg, "lr  = 0x%08lx\n", stack[lr]);  printErrorMsg(msg);
   sprintf(msg, "pc  = 0x%08lx\n", stack[pc]);  printErrorMsg(msg);
   sprintf(msg, "psr = 0x%08lx\n", stack[psr]); printErrorMsg(msg);
   __ASM volatile("BKPT #01");
   while(1);
}

