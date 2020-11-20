#ifndef REFLECTANCE_H_
#define REFLECTANCE_H_

void Reflectance_Init(void);

uint16_t* Reflectance_Read(void);


uint8_t Reflectance_Center(uint32_t time);


int32_t Reflectance_Position(uint8_t data);

void Reflectance_Start(void);

void Reflectance_End(void);

void configReflectanceTimer(void);
void startReflectanceTimer(void);
void stopReflectanceTimer(void);

#endif /* REFLECTANCE_H_ */
