/*
 * File:   timer.c
 * Authors:
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include <xc.h>
#include "timer.h"

void initTimer2(){
    TMR2 = 0;
    T2CONbits.TCKPS = 1;
    T2CONbits.TCS = 0;
    IFS0bits.T2IF = 0;
}
//Uses timer 2
void delayUs(unsigned int delay){
     TMR2 = 0;
    PR2 = delay*6249;
    IFS0bits.T2IF = 0;
    T2CONbits.ON = 1;
    while(IFS0bits.T2IF == 0);
    T2CONbits.ON = 0;
}