// ******************************************************************************************* //
//
// File:         lab1p1.c
// Date:         
// Authors:  Dom    
//
// Description: Part 1 for lab 1
// ******************************************************************************************* //

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "leds.h"
#include "switch.h"
#include "interrupt.h"
#include "config.h"


#define OUTPUT 0
#define INPUT 1
#define FLAG_DOWN 0

//Defines the states of the state machine
typedef enum stateTypeEnum{
    ledON, ledOFF,DB1,DB2
} stateType;
 
volatile stateType state = ledON;
unsigned int sw = 0;

/* Please note that the configuration file has changed from lab 0.
 * the oscillator is now of a different frequency.
 */
int main(void)
{
    SYSTEMConfigPerformance(10000000);
    enableInterrupts(); 
    
    initLEDs();
    initTimer2();
    initSW1();
   
    
    
    while(1){
        
        switch(state){
            
        case ledON:
            turnOnLED(0);
            break;
            
        case ledOFF:
            turnOnLED(1);
            break; 
        
            
        } 
        
    }
    
    return 0;
}

//interrupt service routines that manage the change of states
//for particular events as needed

void __ISR(_CHANGE_NOTICE_VECTOR,IPL7SRS) _CNInterupt(void){
    sw = PORTDbits.RD6;
    IFS1bits.CNDIF = FLAG_DOWN;
    
    
    if(sw == 0)
    {
        
        switch(state)
        {
            case ledOFF: state = DB1; break;
            
            case ledON: state = DB2;break;       
        }
    }else if(sw == 1)
    {
        
            switch(state)
            {
            case DB1: delayUs(5); state = ledON; break;
            
            case DB2: delayUs(5); state = ledOFF; break;
                
            }
    }   
}