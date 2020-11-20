#include "servo.h"
#include "reflectanceArray.h"
#include "pca9685.h"
#include "ultrasonic.h"

void forward(uint16_t stop_condition) {
    uint16_t* data; bool dis;
    data = Reflectance_Read();
    dis = Reflectance_Position(data);
    while ((data[3] > stop_condition + 0)&(data[3]< stop_condition -0)) {
        while (!dis) {
            if (leftCheck()) {
                move_right();
            }
            else {
                move_left();
            }
        }
        servo_write(0, 45);
        servo_write(1, 45);
        servo_write(2, 45);
        servo_write(3, 45);
        servo_write(4, 45);
        servo_write(5, 45);
        servo_write(6, 45);
        servo_write(7, 45); //fill in these functions
        data = Reflectance_Read();
    }
    return;
}

void left(void) {
    double distance;
    double distance_fin = 1;// how close to plant pot in order to water 1cm
    distance = readEcho();
    while (distance > distance_fin) {
        servo_write(0, 45);
        servo_write(1, 45);
        servo_write(2, 45);
        servo_write(3, 45);
        servo_write(4, 45);
        servo_write(5, 45);
        servo_write(6, 45);
        servo_write(7, 45); //fill in these functions
        distance = readEcho();
    }
    return;
}

void right(uint16_t stop_condition) {
    uint16_t* data;
    data = Reflectance_Read();
    while (data[4] > stop_condition + 0)&(data[4]< stop_condition -0) {
        servo_write(0, 45);
        servo_write(1, 45);
        servo_write(2, 45);
        servo_write(3, 45);
        servo_write(4, 45);
        servo_write(5, 45);
        servo_write(6, 45);
        servo_write(7, 45); //fill in these functions
        data = Reflectance_Read();
    }
    return;
}

void backward(uint16_t stop_condition) {
    uint16_t* data; bool dis;
    data = Reflectance_Read();
    while ((data[3] > stop_condition + 0)&(data[3]< stop_condition -0)) {
            if (!dis) {
                if (leftCheck()) {
                    move_right();
                }
                else {
                    move_left();
                }
            }
            servo_write(0, 45);
            servo_write(1, 45);
            servo_write(2, 45);
            servo_write(3, 45);
            servo_write(4, 45);
            servo_write(5, 45);
            servo_write(6, 45);
            servo_write(7, 45); //fill in these functions
            data = Reflectance_Read();
        }
    return;
}

bool leftCheck() {
    uint16_t* data;
    uint_t mid = 0;
    data = Reflectance_Read();
    for (i = 0; i<8; i++) {
        if (data[i+1]>data[i]) {
            mid++;
        }
    }
    if (mid > 4)
        return false;
    return true;
}



void move_right(void) {
    uint16_t* data;
    data = Reflectance_Read();
    while (data[4] > stop_condition + 0)&(data[4]< stop_condition -0) {
        servo_write(0, 45);
        servo_write(1, 45);
        servo_write(2, 45);
        servo_write(3, 45);
        servo_write(4, 45);
        servo_write(5, 45);
        servo_write(6, 45);
        servo_write(7, 45); //fill in these functions
        data = Reflectance_Read();
    }
    return;
}

void move_left(void) {
    uint16_t* data;
        data = Reflectance_Read();
        while (data[3] > stop_condition + 0)&(data[3]< stop_condition -0) {
            servo_write(0, 45);
            servo_write(1, 45);
            servo_write(2, 45);
            servo_write(3, 45);
            servo_write(4, 45);
            servo_write(5, 45);
            servo_write(6, 45);
            servo_write(7, 45); //fill in these functions
            data = Reflectance_Read();
     }
     return;
}
