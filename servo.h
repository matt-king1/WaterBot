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
void forward(uint8_t stop_condition);
void backward(uint8_t stop_condition);
bool leftCheck();
void left(void);
void right(uint8_t stop_condition);
void move_right(void);
void move_left(void);


#endif /* SERVO_H_ */
