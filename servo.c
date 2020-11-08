#include "servo.h"
#include "reflectanceArray.h"
#include "pca9685.h"


void forward(uint8_t stop_condition) {
    uint8_t data; uint8_t dis;
    data = Reflectance_Read(1000);
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
        servo_write(0, 45);
        servo_write(1, 45);
        servo_write(2, 45);
        servo_write(3, 45);
        servo_write(4, 45);
        servo_write(5, 45);
        servo_write(6, 45);
        servo_write(7, 45); //fill in these functions
        data = Reflectance_Read(1000);
    }
    return;
}

void backward(uint8_t stop_condition) {
    uint8_t data; uint8_t dis;
    data = Reflectance_Read(1000);
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
        servo_write(0, 45);
        servo_write(1, 45);
        servo_write(2, 45);
        servo_write(3, 45);
        servo_write(4, 45);
        servo_write(5, 45);
        servo_write(6, 45);
        servo_write(7, 45); //fill in these functions
        data = Reflectance_Read(1000);
    }
    return;
}

bool leftCheck() {
    uint8_t init; uint8_t fin;
    init = Reflectance_Read(1000);
    init = Reflectance_Position(init);
    servo_write(0, 45);
    servo_write(1, 45);
    servo_write(2, 45);
    servo_write(3, 45);
    servo_write(4, 45);
    servo_write(5, 45);
    servo_write(6, 45);
    servo_write(7, 45); //fill in these functions
    fin = Reflectance_Read(1000);
    fin = Reflectance_Read(fin);
    if (fin > init) {
        return false;
    }
    else {
        return true;
    }
}



void move_right(void) {
    uint8_t dis;
    dis = Reflectance_Position(Reflectance_Read(1000));
    while (dis > 3) {
        servo_write(0, 45);
        servo_write(1, 45);
        servo_write(2, 45);
        servo_write(3, 45);
        servo_write(4, 45);
        servo_write(5, 45);
        servo_write(6, 45);
        servo_write(7, 45); //fill in these functions
        dis = Reflectance_Position(Reflectance_Read(1000));
    }
    return;
}

void move_left(void) {
    uint8_t dis;
    dis = Reflectance_Position(Reflectance_Read(1000));
    while (dis > 3) {
        servo_write(0, 45);
        servo_write(1, 45);
        servo_write(2, 45);
        servo_write(3, 45);
        servo_write(4, 45);
        servo_write(5, 45);
        servo_write(6, 45);
        servo_write(7, 45); //fill in these functions
        dis = Reflectance_Position(Reflectance_Read(1000));
    }
    return;
}
