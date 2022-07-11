/*
* using a struct to define the relative memory offsets, 
* the compiler generate all the correct address accesses relative to the base address.
*/
#include <stdio.h>
#include <stdint.h>


typedef struct
{
  uint32_t MODER;   // mode register,                     offset: 0x00
  uint32_t OTYPER;  // output type register,              offset: 0x04
  uint32_t OSPEEDR; // output speed register,             offset: 0x08
  uint32_t PUPDR;   // pull-up/pull-down register,        offset: 0x0C
  uint32_t IDR;     // input data register,               offset: 0x10
  uint32_t ODR;     // output data register,              offset: 0x14
  uint32_t BSRR;    // bit set/reset register,            offset: 0x18
  uint32_t LCKR;    // configuration lock register,       offset: 0x1C
  uint32_t AFRL;    // GPIO alternate function registers, offset: 0x20
  uint32_t AFRH;    // GPIO alternate function registers, offset: 0x24
} GPIO_t;


volatile GPIO_t*   const portd       = (GPIO_t*)0x40020C00;

int main(void)
{

        return 0;
}
