#include <Arduino.h>
#pragma once

/*
0 - ERROR
1 - DIR
2 - DIR, DIR
3 - SPEED, DIR
4 - SPEED, DIR, DIR
*/

//#define motor_lib_version  1.0

//#include "arduino_motor.h"
//Motor test_motor;
  //test_motor.SetMode("DIR",3, "DIR",4);
  //Serial.println(test_motor.TestMode());
  //test_motor.SetSpeed(103);

class Motor {

  public:

    //#define AUTOMATIC  1

    //motor();
    void SetMode(String a, int a_pin, String b="", int b_pin=0,  String c="", int c_pin=0);
    int TestMode();
    void SetSpeed(int predel);

    void run(int speed);
    void stop();
    void block();

    //float version(float a=0);

  private:

    //void Initialize();
    //double dispKp;
    int _max_speed;
    byte _mode;
    byte _pwm_pin;
    byte _dir_1_pin;
    byte _dir_2_pin;


};
