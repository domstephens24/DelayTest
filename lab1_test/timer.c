/*
 * File:   timer.c
 * Authors:
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include <xc.h>
#include "timer.h"

void initTimer1(){
    TMR1 = 0;
    T1CONbits.TCKPS = 0;
    T1CONbits.TCS = 0;
    IFS0bits.T1IF = 0;
}
//Uses timer 2
void delayUs(unsigned int delay){
     TMR1 = 0;
    PR1 = delay*9;
    IFS0bits.T1IF = 0;
    T1CONbits.ON = 1;
    while(IFS0bits.T1IF == 0);
    T1CONbits.ON = 0;
    
}