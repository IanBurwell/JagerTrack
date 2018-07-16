#include <Arduino.h>
#include <Servo.h>

/*
*   Tracking test using two servos and 5 IR reciving diodes
*
*
*
*
*/

Servo tilt;
Servo pan;



void setup() {
    tilt.attach(9);
    pan.attach(10);
    tilt.write(90);
    pan.write(90);
}

void loop() {



}

/*
*   The idea here is to try a weighted average betweek each reciever, weighted with a degree ange 
*(45-225 for example, because including 0 would loose data i think)
*/
double calcLineAvg(int recieved[]){

    return 0;
}


/*
*
*/
double calcLineRatio(int recieved[]){
    
}