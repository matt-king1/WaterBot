#ifndef REFLECTANCE_H_
#define REFLECTANCE_H_

#include <stdbool.h>

void Reflectance_Init(void);

uint16_t* Reflectance_Read(void);


bool Reflectance_Position(uint16_t data[]);

void Reflectance_Start(void);

uint16_t* Reflectance_End(void);

void configReflectanceTimer(void);
void startReflectanceTimer(void);
void stopReflectanceTimer(void);

#endif /* REFLECTANCE_H_ */
