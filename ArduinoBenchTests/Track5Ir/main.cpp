#include <Arduino.h>
#include <Servo.h>
#include <Serial.h>

/*
*   Tracking test using two servos and 5 IR reciving diodes
*
*
*
*
*/


Servo pan;
float[5] values;

void setup() {
    pan.attach(10);
    pan.write(90);

    Serial.begin(9600);
}

void loop() {

    for(int i = 0; i < 5; i++)
       values[i] = (float)analogRead(i)/1023;

    Serial.print(calcLineRatio(values));

    for(int i = 0; i < 5; i++)
        Serial.print(" " + values[i])

    Serial.println();

    delay(100);
}


/*
*
*/
double calcLineRatio(double recieved[]){
    
    //find largest 2 elements
    int a = 0, b = 0;
    for(int i = 1; i < 5; i++){
        if(recieved[i] > recieved[a]){
            a = i;
        }
    }
    for(int i = 1; i < 5; i++){
        if(i != a && recieved[i] > recieved[b]){
            b = i;
        }
    }
    //make a the rightmost (hopefully) reciever
    if(a > b){
        double c = a;
        a = b;
        b = c;
    }

    //calculates ration from a to b
    return a*45+45*recieved[a]/(recieved[a]+recieved[b]);
}

/*
*   The idea here is to try a weighted average betweek each reciever, weighted with a degree ange 
*
*/
double calcLineAvg(int recieved[]){

    return 0;
}

