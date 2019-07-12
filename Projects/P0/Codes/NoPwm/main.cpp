#include "mbed.h"

DigitalIn Switch_pin(PTA1,PullUp);
DigitalOut LED_pin(PTD2);

int main() {
    int CurrentStep =0;
    bool check = false;
    float time = 0.0;
    LED_pin = 0;
    while(1) {    
        if(Switch_pin == 0){
            if(check){
            CurrentStep++;
            CurrentStep = CurrentStep % 6;
            time = (float)CurrentStep/5;
            check = false;}
        } 
        else{
            check = true;
        }  
         LED_pin = 1;
         wait(time*0.005);
         LED_pin = 0;
        wait((1.0-time)*0.005);   
     }
}