/*
 * File:   switch.c
 * Author: Dom
 *
 * Created on September 19, 2015, 10:46 AM
 */
#include <xc.h>
#include "switch.h"

#include "proc/p32mx470f512l.h"

#define INPUT 1
#define OFF 0
#define ENABLED 1
#define FLAG_DOWN 0
#define priority 7

void initSW1(){
    //TODO: Initialize the appropriate pins to work with the external switch using a
    //change notification interrupt.
    TRISDbits.TRISD6 = INPUT; //makes the tristate take in inputs
    CNCONDbits.ON = 1; //enable overall interrupt functionality
    CNENDbits.CNIED6 = ENABLED; //enable d pins
    CNPUDbits.CNPUD6 = ENABLED; //enable pull up resistor
    IFS1bits.CNDIF = FLAG_DOWN;
    IPC8bits.CNIP = priority;
//    IPC8bits.CNIS = 3;
    IEC1bits.CNDIE = ENABLED;//enable interrupt
}
