#include "main.h"

#include "led.h"

void Main(){
	LED_GPIO_Config();

	while (1) {
		LED_ON();
		for (int i = 0 ; i < 7200000; i ++);
		LED_OFF();
		for (int i = 0 ; i < 7200000; i ++);
	}
}
