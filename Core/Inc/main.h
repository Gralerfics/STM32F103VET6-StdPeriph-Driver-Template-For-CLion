#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* +==============================+
 * |            Macros            |
 * +==============================+ */
#define MANUAL_SYSCLK_CONFIG // Automatical Configuration in system_stm32f10x.c (line 110, appr.)
#define USE_USER_MAIN
#define USE_ERROR_HANDLER

/* +==============================+
 * |           Includes           |
 * +==============================+ */
#include "stm32f10x.h"

/* +==============================+
 * |          Prototypes          |
 * +==============================+ */
#ifdef MANUAL_SYSCLK_CONFIG
	void SystemClock_Config(void);
#endif

#ifdef USE_USER_MAIN
	void Main();
#endif

#ifdef USE_ERROR_HANDLER
	void Error_Handler(void);
#endif

#ifdef __cplusplus
}
#endif

#endif
