/*
 * servo.c
 *
 *  Created on: Jul 14, 2020
 *      Author: Tyler Davidson
 */
#include "servo.h"
#include "reflectanceArray.h"
#include "pca9685.h"


void forward(uint8_t stop_condition) {
    uint8_t data; uint8_t dis;
    data = Reflectance_read(1000);
    while (data != stop_condition) {
        dis = Reflectance_Position(data);
        if (dis > 5) {
            if (leftCheck()) {
                move_right();
            }
            else {
                move_left();
            }
        }
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        data = Reflectance_read(1000);
    }
    return;
}

void backward(uint8_t stop_condition) {
    uint8_t data; uint8_t dis;
    data = Reflectance_read(1000);
    while (data != stop_condition) { //checks if reflectance is equal to what would signify plant
        dis = Reflectance_Position(data);
        if (dis > 5) { //checks if straight
            if (leftCheck()) {
                move_right();
            }
            else {
                move_left();
            } // moves direction needed to be straight
        }
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        data = Reflectance_Read(1000);
    }
    return;
}

bool leftCheck() {
    uint8_t init; uint8_t fin;
    init = Reflectance_Read(1000);
    init = Reflectance_Position(init)
    servo_write();
    servo_write();
    servo_write();
    servo_write();
    servo_write();
    servo_write();
    servo_write();
    servo_write();
    fin = Reflectance_Read(1000);
    fin = Reflecatance_Read(fin)
    if (fin > init) {
        return false;
    }
    else {
        return true;
    }
}



void move_right() {
    uint8_t dis;
    dis = Reflectance_Position(Reflectance_Read(1000));
    while (dis > 3) {
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        dis = Reflectance_Position(Reflectance_Read(1000));
    }
    return;
}

void move_left() {
    uint8_t dis;
    dis = Reflectance_Position(Reflectance_Read(1000));
    while (dis > 3) {
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        servo_write();
        dis = Reflectance_Position(Reflectance_Read(1000));
    }
}
