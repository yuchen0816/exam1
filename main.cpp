#include "mbed.h"
#include "uLCD_4DGL.h"

AnalogOut aout(D7);
AnalogIn ain(A3);
uLCD_4DGL uLCD(D1, D0, D2);
DigitalIn up(A0);
DigitalIn down(A1);
DigitalIn confirm(A2);
int counter = 0;
float i;
int j;
int x;
int y;
float ADCdata[128];
int conf = 0;
int main(void)
{
    uLCD.color(BLUE);
    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.locate(2,0);
    uLCD.printf("1");
    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.locate(2,2);
    uLCD.printf("1/2");
    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.locate(2,4);
    uLCD.printf("1/4");
    uLCD.text_width(2);
    uLCD.text_height(2);
    uLCD.locate(2,6);
    uLCD.printf("1/8");

    while(1){
        if(up==1){
            counter = counter + 1;
        }
        if(down==1){
            counter = counter - 1;
        }
        if(counter==1){
            uLCD.color(RED);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,0);
            uLCD.printf("1");
            uLCD.color(BLUE);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,2);
            uLCD.printf("1/2");
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,4);
            uLCD.printf("1/4");
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,6);
            uLCD.printf("1/8");
        }
        if(counter==2){
            uLCD.color(BLUE);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,0);
            uLCD.printf("1");
            uLCD.color(RED);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,2);
            uLCD.printf("1/2");
            uLCD.color(BLUE);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,4);
            uLCD.printf("1/4");
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,6);
            uLCD.printf("1/8");
        }
        if(counter==3){
            uLCD.color(RED);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,4);
            uLCD.printf("1/4");
        }
        if(counter==4){
            uLCD.color(RED);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,6);
            uLCD.printf("1/8");
        }
    }
}