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
float j;
float slew;
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
            uLCD.color(BLUE);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,0);
            uLCD.printf("1");
            uLCD.color(BLUE);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,2);
            uLCD.printf("1/2");
            uLCD.color(RED);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,4);
            uLCD.printf("1/4");
            uLCD.color(BLUE);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,6);
            uLCD.printf("1/8");
        }
        if(counter==4){
            uLCD.color(BLUE);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,0);
            uLCD.printf("1");
            uLCD.color(BLUE);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,2);
            uLCD.printf("1/2");
            uLCD.color(BLUE);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,4);
            uLCD.printf("1/4");
            uLCD.color(RED);
            uLCD.text_width(2);
            uLCD.text_height(2);
            uLCD.locate(2,6);
            uLCD.printf("1/8");
        }
        if(confirm==1){
            conf = 1;
            if(counter == 1)
                slew = 1;
            else if(counter == 2)
                slew = 0.5;
            else if(counter == 3)
                slew = 0.25;
            else if(counter == 4)
                slew = 0.125;
        }


        if(slew==1){
            for(i=0;i<0.9;i = i + 0.0001268)
                aout = i;
            for(j = 0; j < 0.9; j= j + 0.0001268)
                aout = 0.9;
            for (i = 0.9; i > 0; i = i - 0.0001268)
                aout = i;
        }
        if(slew==0.5){
            for(i=0;i<0.9;i = i + 0.00028)
                aout = i;
            for(j = 0; j < 0.9; j= j + 0.000072)
                aout = 0.9;
            for (i = 0.9; i > 0; i = i - 0.00028)
                aout = i;
        }
        if(slew==0.25){
            for(i=0;i<0.9;i = i + 0.00056)
                aout = i;
            for(j = 0; j < 0.9; j= j + 0.00006)
                aout = 0.9;
            for (i = 0.9; i > 0; i = i - 0.00056)
                aout = i;
        }
        if(slew==0.125){
            for(i=0;i<0.9;i = i + 0.0011)
                aout = i;
            for(j = 0; j < 0.9; j= j + 0.000055)
                aout = 0.9;
            for (i = 0.9; i > 0; i = i - 0.0011)
                aout = i;
        }
        if(conf == 1){
            ADCdata[k] = ain;
            if (k == 99){
                for (x = 0; x < 100; x++){
                    printf("%f\r\n", ADCdata[x]);
                }
                k = 0;
                conf = 0;
            } 
            else {
                k++;
            }
        }
    }
}
