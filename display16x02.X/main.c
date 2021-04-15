/*
 * File:   main.c
 * Author: 20185210
 *
 * Created on 15 de Abril de 2021, 13:46
 */


#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 4000000

#define EN      PORTDbits.RD7
#define RS      PORTDbits.RD6
#define DADOS   PORTB

void LCD_init(void)
{
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    ANSELH = 0;
    TRISB = 0;
    DADOS = 0;
    EN = 1;
    RS = 0;
}
void LCD_on (void)
{
    // ligar o display
    EN = 1;
    RS = 0;
    DADOS = 0X0F;
    EN = 0;
    __delay_us(40);
    EN = 1;
 }
void LCD_printChar( char c)
{
    // inserir dado
    RS = 1;
    DADOS = c;
    EN = 0;
    __delay_us(40);
    EN = 1;
}

void lCD_pos ( char n )
{
    EN = 1;
    RS = 0;
    DADOS = 0X80 | n;
    EN = 0;
    __delay_us(40);
    EN = 1;   
}
void LCD_printStr ( char * ptr )
{
    int cont = 0;
    
    while ( *(ptr + cont) )
    {
        LCD_printChar(*(ptr + cont) );
        cont++;
    }    
}
void main (void)
{
    int n;
    LCD_init();
    LCD_on();
    while(1)
    {
        for ( n = 0; n<128; n++ )
        {
            lCD_pos(14);
            LCD_printStr(" >>  SENAI  >>  ");
            __delay_ms(250);
        }
        // posição 14 é o ultimo caracter da 1° linha e a posição 39 é o primeiro da 2° linha
        // intervalo que não mostra a plavra senai = 25 posições
    }
}





