#include "using_motor.h"
 
Motor test_motor;

void setup() {
  Serial.begin(9600);
  test_motor.SetMode("DIR",3, "DIR",4);
  Serial.println(test_motor.TestMode());
  test_motor.SetSpeed(103);
  
}

void loop () {
  
}
