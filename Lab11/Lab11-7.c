#include <stdio.h>
#include <errno.h>
#include <wiringPi.h>
#define BUTTON_PIN 0
#define pin0 1
#define pin1 2
#define pin2 3
// Use GPIO Pin 17 = Pin 0 of wiringPi library
volatile int delayInput = 250;
int i = 0;
void myInterrupt(void)   // called every time an event occurs
{
    if(delayInput == 250)
    {
        delayInput = 500;
    }
    else if(delayInput == 500)
    {
        delayInput = 1000;
    }
    else if(delayInput == 1000)
    {
        delayInput = 250;
    }
    printf("Press!\n");
}
int main(void)
{
    if (wiringPiSetup()<0) // check the existence of wiringPi library
    {
        printf ("Cannot setup wiring Pi\n");
        return 1; // error code = 1
    }
// set wiringPi Pin 0 to generate an interrupt from 1-0 transition
// myInterrupt() = my Interrupt Service Routine
    if (wiringPiISR (BUTTON_PIN, INT_EDGE_FALLING, &myInterrupt) < 0)
    {
        printf ("Cannot setup ISR\n");
        return 2; // error code = 2
    }

    pinMode(pin0,OUTPUT);
    pinMode(pin1,OUTPUT);
    pinMode(pin2,OUTPUT);
// display counter value every second
    while(1)
    {

        for (i=7; i>=0; i--)
        {
        printf("%d\n",i);
            switch(i)
            {
            case 0:
                digitalWrite(pin0,0);
                digitalWrite(pin1,0);
                digitalWrite(pin2,0);
                break;

            case 1:
                digitalWrite(pin0,1);
                digitalWrite(pin1,0);
                digitalWrite(pin2,0);
                break;

            case 2:
                digitalWrite(pin0,0);
                digitalWrite(pin1,1);
                digitalWrite(pin2,0);
                break;

            case 3:
                digitalWrite(pin0,1);
                digitalWrite(pin1,1);
                digitalWrite(pin2,0);
                break;

            case 4:
                digitalWrite(pin0,0);
                digitalWrite(pin1,0);
                digitalWrite(pin2,1);
                break;

            case 5:
                digitalWrite(pin0,1);
                digitalWrite(pin1,0);
                digitalWrite(pin2,1);
                break;

            case 6:
                digitalWrite(pin0,0);
                digitalWrite(pin1,1);
                digitalWrite(pin2,1);
                break;

            case 7:
                digitalWrite(pin0,1);
                digitalWrite(pin1,1);
                digitalWrite(pin2,1);
                break;

            }
            delay(delayInput);
        }
        i = 1;
        for (i; i<=7; i++)
        {
        printf("%d\n",i);
            switch(i)
            {
            case 0:
                digitalWrite(pin0,0);
                digitalWrite(pin1,0);
                digitalWrite(pin2,0);
                break;

            case 1:
                digitalWrite(pin0,1);
                digitalWrite(pin1,0);
                digitalWrite(pin2,0);
                break;

            case 2:
                digitalWrite(pin0,0);
                digitalWrite(pin1,1);
                digitalWrite(pin2,0);
                break;

            case 3:
                digitalWrite(pin0,1);
                digitalWrite(pin1,1);
                digitalWrite(pin2,0);
                break;

            case 4:
                digitalWrite(pin0,0);
                digitalWrite(pin1,0);
                digitalWrite(pin2,1);
                break;

            case 5:
                digitalWrite(pin0,1);
                digitalWrite(pin1,0);
                digitalWrite(pin2,1);
                break;

            case 6:
                digitalWrite(pin0,0);
                digitalWrite(pin1,1);
                digitalWrite(pin2,1);
                break;

            case 7:
                digitalWrite(pin0,1);
                digitalWrite(pin1,1);
                digitalWrite(pin2,1);
                break;

            }
            delay(delayInput);
        }
    }

    return 0; // error code = 0 (No Error)
}
