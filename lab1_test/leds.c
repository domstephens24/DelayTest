/*
* File:   leds.c
* Author: Dom Stephens
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
    TRISDbits.TRISD1 = OUTPUT;
    LATDbits.LATD1 = OFF;
    

}

void turnOnLED(int led){
    //Turns on corresponding LED
    if (led == 0)
    {
        LATDbits.LATD1 = ON;

    }else if (led == 1)
    {
        LATDbits.LATD1 = OFF;
    }
    
}
