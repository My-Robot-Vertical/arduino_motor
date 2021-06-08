#include <Arduino.h>
#pragma once

#define motor_lib_version  1.0

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

    float version(float a=0);
    
  private:
  
    //void Initialize();
    //double dispKp; 
    int _max_speed;
    byte _mode;
    byte _pwm_pin;
    byte _dir_1_pin;
    byte _dir_2_pin;
    
  
};
