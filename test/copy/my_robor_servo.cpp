/*
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
 */
#include "my_robor_servo.h"
#pragma once

ServoMotor::ServoMotor(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void ServoMotor::write(int angle, servo_motor_data_cell *data=_servo_motor_data_my) {
  if (!data) { // ячейки не существует
    Serial.print("ERROR: no servo on pin ");
    Serial.println(_pin);
  }
  else { // начинаем искать нужную ячейку
    if (_pin==data->pin) { // это та ячейка
      ServoMotor::my_write(angle); // крутим серву 
      data->angle=angle; // записываем новый угол
    }
    else ServoMotor::write(angle, data->next_cell); // это не та ячейка, идем дальше
  }
}

void ServoMotor::my_write(int angle) {
  digitalWrite(_pin, HIGH);
  delayMicroseconds(angle);
  digitalWrite(_pin, LOW);
  delayMicroseconds(20000-angle);
}

/*void print_servo_data(servo_motor_data_cell *data=_servo_motor_data_my) {
  if (data) {
    Serial.print("pin: ");
    Serial.print(data->pin);
    Serial.print("; angle: ");
    Serial.print(data->angle);
    Serial.print("; ");
    //Serial.print(data->);
    Serial.println();
    print_servo_data(data->next_cell);
  }
}*/

//void motor::motor() {
//  
//}

/*void ServoMotor::SetMode() {
  
}*/
