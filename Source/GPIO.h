#ifndef GPIO_H
#define GPIO_H
#include "stm32f10x.h" 

void SetPortToInput( GPIO_TypeDef* port, unsigned char pin );

void SetPortToOutput( GPIO_TypeDef* port, unsigned char pin );

void SetPortToAlternateOut( GPIO_TypeDef* port, unsigned char pin );


#endif


