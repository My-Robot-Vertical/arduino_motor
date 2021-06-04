#include <Arduino.h>
#pragma once

//#define VERSION  "1.0"

class motor {
  
  public:

    //#define AUTOMATIC  1
    
    //motor(); 
    void SetMode(String a, int a_pin, String b="", int b_pin=0,  String c="", int c_pin=0);
    int TestMode();
    
  private:
  
    //void Initialize();
    //double dispKp; 
    byte mode;
    byte pwm_pin;
    byte dir_1_pin;
    byte dir_2_pin;
    
  
};
