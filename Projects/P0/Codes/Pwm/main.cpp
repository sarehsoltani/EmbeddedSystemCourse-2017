#include "mbed.h"

DigitalIn  Switch_pin(PTA1,PullUp);
PwmOut     LED_pin(PTD2);

int main() {
    int CurrentStep =0;
    bool p = false;
    LED_pin.period(0.01f);
    LED_pin = 0;
    while(true){
        if(Switch_pin == 0){
            if(p){
                CurrentStep++;
                CurrentStep = CurrentStep % 6;
                LED_pin = (float)CurrentStep/5;
                wait(0.01f);
                p = false;
            }
        }
        else{
            p = true;
        }
    }
}
