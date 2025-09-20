/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

#include <stdio.h>
#include "stm32f10x.h"

void InitAll( void)
{
  RCC->APB2ENR |= 0x1D;
}

void SetPortToOutput( GPIO_TypeDef* port, unsigned char pin )
{
  if (pin < 8)
  {
    port->CRL &= (unsigned int) ~(0xF << (pin * 4));
    port->CRL |= (unsigned int) 3 << (pin *4);
  }
  else 
  {
    pin &= 7;
    port->CRH &= (unsigned int) ~(0xF << (pin * 4));
    port->CRH |= (unsigned int) 3 << (pin * 4); 
  }
}
//------------------------------------------------------------------------------

void Delay( unsigned int Val) {
  for( ; Val != 0; Val--) {
    __NOP();
  }
}


int main(void) {
  int i;
  InitAll();
  SetPortToOutput(GPIOC, 13);

//  for (i = 0; i < 100; i++) {
//   printf("Hello World %d!\n", i);
//  }
  do {
    i++;

    GPIOC->BSRR = 1<<13;
    Delay(3600000);
    GPIOC->BRR = 1 << 13;
    Delay(250000);
  } while (1);
}

/*************************** End of file ****************************/


    ////------------------------------------------------------------------------------

    //void InitAll( void)
    //{

    //  // Enable PORTB Periph clock  
    ////  RCC->APB2ENR	|= RCC_APB2ENR_IOPCEN;
    //// 
    ////
    ////  // Clear PB.5 control register bits
    ////  GPIOC->CRL &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
    ////  
    ////  // Configure PB.5 as Push Pull output at max 10Mhz
    ////  GPIOC->CRL   |= GPIO_CRH_MODE13_0;
    ////  
    //  RCC->APB2ENR |= 0x1D;
    //}

    //void SetPortToOutput( GPIO_TypeDef* port, unsigned char pin )
    //{
    //	if (pin < 8)
    //	{
    //		port->CRL &= (unsigned int) ~(0xF << (pin * 4));
    //		port->CRL |= (unsigned int) 3 << (pin *4);
    //	}
    //	else 
    //	{
    //		pin &= 7;
    //		port->CRH &= (unsigned int) ~(0xF << (pin * 4));
    //		port->CRH |= (unsigned int) 3 << (pin * 4); 
    //	}
    //}
    ////------------------------------------------------------------------------------

    //void Delay( unsigned int Val) {
    //  for( ; Val != 0; Val--) {
    //    __NOP();
    //  }
    //}


    //void main()
    //{
    //  InitAll();
    //  SetPortToOutput(GPIOC, 13);
    //  while( 1)
    //  {
    //    // Set PB.5 bit
    ////    GPIOC->BSRR = GPIO_BSRR_BS13;
    ////    Delay( 600000);
    ////    
    ////    // Reset PB.5 bit
    ////    GPIOC->BSRR = GPIO_BSRR_BR13;
    ////    Delay( 600000);
    //    GPIOC->BSRR = 1<<13;
    //    Delay(1200000);
    //    GPIOC->BRR = 1 << 13;
    //    Delay(50000);
    //  }
    //}
