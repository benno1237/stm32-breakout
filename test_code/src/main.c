#include "stm32g0xx.h"

static void delay(volatile uint32_t n) {
  while (n--) {
    __asm__("nop");
  }
}

int main(void) {
  RCC->IOPENR |= RCC_IOPENR_GPIOCEN;

  GPIOC->MODER &= ~(3u << (10 * 2));
  GPIOC->MODER |=  (1u << (10 * 2));

  while (1) {
    GPIOC->BSRR = (1u << 10);
    delay(300000);

    GPIOC->BRR = (1u << 10);
    delay(300000);
  }
}