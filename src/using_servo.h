#include <Arduino.h>
#pragma once

struct servo_motor_data_cell
{
    byte pin;
    int angle;
    servo_motor_data_cell *next_cell;
};

extern servo_motor_data_cell *_servo_motor_data_my;

void print_servo_data(servo_motor_data_cell* data = _servo_motor_data_my);
void ServoUpdate(servo_motor_data_cell* data = _servo_motor_data_my);
void ServoMotor_my_write(int pin, int angle);

class ServoMotor {

  public:

    ServoMotor(int pin, servo_motor_data_cell* &data = _servo_motor_data_my);
    void write(int angle, servo_motor_data_cell* &data = _servo_motor_data_my);
    void writeMicroseconds(int timer);
    int read(servo_motor_data_cell* data = _servo_motor_data_my);

  private:

    byte _pin;

};
