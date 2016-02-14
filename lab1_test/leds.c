/*
* File:   leds.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/
#include <xc.h>
#include "leds.h"
#include "proc/p32mx470f512l.h"

#define ON 1
#define OFF 0
#define OUTPUT 0
#define INPUT 1

void initLEDs(){
    //Initializes LEDs
    TRISDbits.TRISD2 = OUTPUT;
    LATDbits.LATD2 = OFF;
    

}

void turnOnLED(int led){
    //Turns on corresponding LED
    if (led == 0)
    {
        LATDbits.LATD2 = ON;

    }else if (led == 1)
    {
        LATDbits.LATD2 = OFF;
    }
    
}
