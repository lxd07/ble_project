
#ifndef __LED_H
#define __LED_H



#include <stdint.h>

#include "nrf_gpio.h"

#ifdef __cplusplus
extern "C" {
#endif


#define LEDS_NUMBER    3

#define LED_R          NRF_GPIO_PIN_MAP(0,26)
#define LED_G          NRF_GPIO_PIN_MAP(1,15)
#define LED_B          NRF_GPIO_PIN_MAP(1,13)

#define LEDS_LIST { LED_R, LED_G, LED_B }


#define LED_ON   0
#define LED_OFF  1

void led_init(void);
void set_led_status(uint8_t led,uint8_t status);
uint8_t get_led_status(uint8_t led);
void led_invert(uint8_t led);
void led_invert_index(uint8_t led_idx);

#ifdef __cplusplus
}
#endif

#endif 

