/*
*********************************************************************************************************
*                                               uC/OS-II
*                                         The Real-Time Kernel
*
*                           (c) Copyright 2002, Nathan Brown, Longview, TX
*                                      http://www.sputnickonline.com/
*                                          All Rights Reserved
*
*                                   PIC18xxxx Interrupt Specific Code
*                                       V1.00 - October 27, 2002
*
* File : VECTORS.C
* By   : Nathan Brown
*********************************************************************************************************
*/

#include "includes.h"
#include <timers.h>

/*
*********************************************************************************************************
*                               INTERRUPT SERVICE ROUTINE HOOK
*
* Description:  This function is called when a interrupt service routine is call.  The state of the
*               current proccess is already saved.  This allows you to order the responses and to
                call your own coded for interrupts.
*
* Arguments  :  none
*
* Note(s)    :  1)  OSTimeTick() must be called from the timer routine that is pulsing at 10 to 100 times
*                   a second.
*               2)  You must clear the interrupt before calling OSTimeTick().
*********************************************************************************************************
*/
void CPUInterruptHook(void)
{
    if(INTCONbits.TMR0IF) {                     // check for TMR0 overflow
        INTCONbits.TMR0IF = 0;                  // clear interrupt flag
        TMR0H = 0xD8;                           // set the timer to expire in 10 ms. (at 4MHz) Prescaler *2
        TMR0L = 0xA0;
        //TMR0H = 0xF8;
        //TMR0L = 0x2F;
		// Valor calculado
        //TMR0H = 60;                           // set the timer to expire in 10 ms. (at 20MHz) prescaler *1
        //TMR0L = 176;
		// Valor ajustado para 10mSeg
        //TMR0H = 60;                           // set the timer to expire in 10 ms. (at 20MHz) prescaler *1
        //TMR0L = 251;
/*
		TMR0H = 158;                           // set the timer to expire in 10 ms. (at 20MHz) prescaler *2
        TMR0L = 88;
		TMR0H = 207;                           // set the timer to expire in 10 ms. (at 20MHz) prescaler *2
        TMR0L = 44;
  */      
        OSTimeTick();                           // Call required os timer
    }

    /* Insert other interrupt items here */

}