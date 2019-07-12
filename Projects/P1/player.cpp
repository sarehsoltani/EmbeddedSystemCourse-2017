#include "mbed.h"
PwmOut Player(PTD2);

int main()
{
    //e4
    wait(0.6);
    Player.period(1.0/329.63);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.05);
    

    //d4#
    Player.period(1.0/311.13);
    Player =0.5; 
    wait(0.3);
    Player=0.0; 
    wait(0.05);

    //e4
    Player.period(1.0/329.63);
    Player =0.5; 
    wait(0.3);
    Player=0.0; 
    wait(0.05);

    //d4#
    Player.period(1.0/311.13);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.05);

    //e4
    Player.period(1.0/329.63);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.05);

    //b3
    Player.period(1.0/246.94);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //d4
    Player.period(1.0/293.66);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //c4
    Player.period(1.0/261.63);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //a3
    Player.period(1.0/220.0);
    Player =0.5;
    wait(0.9);
    Player=0.0; 
    wait(0.1);

    //d3
    Player.period(1.0/146.83);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.05);

    //f3
    Player.period(1.0/174.61);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //a3
    Player.period(1.0/220.0);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //b3
    Player.period(1.0/246.94);
    Player =0.5;
    wait(0.9);
    Player=0.0; 
    wait(0.1);

    //f3
    Player.period(1.0/174.61);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //a3#
    Player.period(1.0/233.08);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //b3
    Player.period(1.0/246.94);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //c4
    Player.period(1.0/261.63);
    Player =0.5;
    wait(0.9);
    Player=0.0; 
    wait(0.1);
    
    //e4
    Player.period(1.0/329.63);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //d4#
    Player.period(1.0/311.13);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //e4
    Player.period(1.0/329.63);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //b3
    Player.period(1.0/246.94);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //d4
    Player.period(1.0/293.66);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //c4
    Player.period(1.0/261.63);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //a3
    Player.period(1.0/220.0);
    Player =0.5;
    wait(0.9);
    Player=0.0; 
    wait(0.1);
 

    //d3
    Player.period(1.0/146.83);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //f3
    Player.period(1.0/174.61);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //a3
    Player.period(1.0/220.0);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //b3
    Player.period(1.0/246.94);
    Player =0.5;
    wait(0.9);
    Player=0.0; 
    wait(0.1);

    //f3
    Player.period(1.0/174.61);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //c4
    Player.period(1.0/261.63);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //b3
    Player.period(1.0/246.94);
    Player =0.5;
    wait(0.3);
    Player=0.0; 
    wait(0.1);

    //a3
    Player.period(1.0/220.0);
    Player =0.5;
    wait(0.9);
    Player=0.0; 
    wait(0.1);

   wait(5);
}
 
