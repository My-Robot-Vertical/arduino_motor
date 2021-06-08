/*
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
 */
#include "my_robor_servo.h"
#pragma once

servo_motor_data_cell *_servo_motor_data_my = 0;

void teeeeeeeeeeeeeeeest() {
  servo_motor_data_cell* &data = _servo_motor_data_my;
  data = new servo_motor_data_cell;
  data->pin = 7;
  data->angle = 8;
  data->next_cell = 0;
}

ServoMotor::ServoMotor(int pin, servo_motor_data_cell* &data = _servo_motor_data_my) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  if (!data) {
    data = new servo_motor_data_cell;
    data->pin = pin;
    data->angle = 2;
    data->next_cell = 0;
    Serial.println("test");
  }
  else if (data->pin != pin) ServoMotor::ServoMotor(pin, data->next_cell);
  else Serial.println("ERROR: this servo has already been initialized");
}

/*void ServoMotor::write(int angle, servo_motor_data_cell* data = &_servo_motor_data_my) {
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
  digitalWrite(_pin, 1);
  delayMicroseconds(angle);
  digitalWrite(_pin, 0);
  delayMicroseconds(20000-angle);
}*/

void print_servo_data(servo_motor_data_cell* data = _servo_motor_data_my) {
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
}

//void motor::motor() {
//  
//}

/*void ServoMotor::SetMode() {
  
}*/
