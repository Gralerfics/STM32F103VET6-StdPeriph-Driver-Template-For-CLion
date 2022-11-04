#include "main.h"

int main(void) {
#ifdef MANUAL_SYSCLK_CONFIG
	SystemClock_Config();
#endif

#ifdef USE_USER_MAIN
	Main();
#endif

	while (1) {}
}

#ifdef MANUAL_SYSCLK_CONFIG
	void SystemClock_Config(void) {
		RCC_DeInit();

		RCC_HSEConfig(RCC_HSE_ON);
		while ((RCC_WaitForHSEStartUp()) != SUCCESS);

		RCC_ClockSecuritySystemCmd(ENABLE);

		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_3);
		RCC_PLLCmd(ENABLE);
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY) != SET);

		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div2);
		RCC_PCLK2Config(RCC_HCLK_Div1);

		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while (RCC_GetSYSCLKSource() != 0x08);
	}
#endif

#ifdef USE_ERROR_HANDLER
	void Error_Handler(void) {
		__disable_irq();
		while (1) {}
	}
#endif

#ifdef  USE_FULL_ASSERT
	void assert_failed(uint8_t *file, uint32_t line) {
	}
#endif
