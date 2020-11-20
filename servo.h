/*
 * servo.h
 *
 *  Created on: Jul 14, 2020
 *      Author: Tyler Davidson
 */

#ifndef SERVO_H_
#define SERVO_H_

#include "pca9685.h"
#include "reflectanceArray.h"

//Servo Definitions
//-----Servo-----Channel
#define URL         0
#define LRL         1

#define URA         4
#define LRA         5

#define ULL         9
#define LLL         10

#define ULA         13
#define LLA         14

//URA-> Upper Right Arm
//LLL-> Lower Left Leg
//etc.
void forward(uint16_t stop_condition);
void backward(uint16_t stop_condition);
bool leftCheck();
void left(void);
void right(uint16_t stop_condition);
void move_right(uint16_t stop_condition);
void move_left(uint16_t stop_condition);


#endif /* SERVO_H_ */
