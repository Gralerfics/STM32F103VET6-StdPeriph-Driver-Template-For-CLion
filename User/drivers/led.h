#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f10x.h"

#define LED_GPIO_CLK RCC_APB2Periph_GPIOB
#define LED_GPIO_Pin GPIO_Pin_5
#define LED_GPIO_PORT GPIOB

void LED_GPIO_Config(void);
void LED_ON(void);
void LED_OFF(void);

#ifdef __cplusplus
}
#endif

#endif
