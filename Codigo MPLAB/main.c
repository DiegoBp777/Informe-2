/*
 * File:   main.c
 * Author: LOS MAKIAS
 *
 * Created on 25 de agosto de 2026, 09:01 PM
 */


#include <xc.h>

//Configuracion del oscilador interno a 1MHz
#pragma config FOSC = INTIO67 //oscilador interno, puerto en Ra6 y Ra7
#pragma config WDTEN = OFF //perro guardian (watchdog) apagado
#pragma config LVP = OFF //programa en baja tension apagado

#define _XTAL_FREQ 1000000 //frecuencia de 1MHz para los retardos

void main(void) {
    
    //congigurar un oscilador a 1MHz
    OSCCON = 0b10000000; //RCF 100 (1MHz)
    
    //configuracion pin como salida (ejemplo: PIN RD0 del puerto D)
    ANSELD = 0; //desactivar las entradas analogicas de la entrada D
    TRISDbits.TRISD0 = 0; //RD0 como salida
    
    while(1)    {
        LATDbits.LATD0 = 1; //encender led en RD0
        __delay_ms(500);//esperar 500ms 
        
        LATDbits.LATD0 = 0; //encender led en RD0
        __delay_ms(500);//esperar 500ms 
        
    }
    
    return;
}
