#include "led.h"

#if LEDS_NUMBER > 0
static const uint8_t m_led_list[LEDS_NUMBER] = LEDS_LIST;
#endif

void led_init(void)
{
      uint32_t i;
    for (i = 0; i < LEDS_NUMBER; ++i)
    {
     nrf_gpio_cfg_output(m_led_list[i]);
     set_led_status(m_led_list[i],LED_OFF);
    }
}

void set_led_status(uint8_t led,uint8_t status)
{
    nrf_gpio_pin_write(led, status);
}

uint8_t get_led_status(uint8_t led)
{
    uint8_t status;

  status= nrf_gpio_pin_read(led);
  if(status==LED_ON)
  return  LED_ON;

  return  LED_OFF;
}

void led_invert(uint8_t led)
{
    nrf_gpio_pin_toggle(led);
}

void led_invert_index(uint8_t led_idx)
{
    ASSERT(led_idx < LEDS_NUMBER);
    nrf_gpio_pin_toggle(m_led_list[led_idx]);
}
