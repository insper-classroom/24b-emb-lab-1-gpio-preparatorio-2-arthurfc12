#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_A = 6;
const int BTN_PIN_A = 26;

const int LED_PIN_B = 4;
const int BTN_PIN_B = 28;

int main() {
  stdio_init_all();
  
  gpio_init(LED_PIN_A);
  gpio_init(BTN_PIN_A);

  gpio_init(LED_PIN_B);
  gpio_init(BTN_PIN_B);

  gpio_set_dir(LED_PIN_A, GPIO_OUT);
  gpio_set_dir(BTN_PIN_A, GPIO_IN);

  gpio_set_dir(LED_PIN_B, GPIO_OUT);
  gpio_set_dir(BTN_PIN_B, GPIO_IN);

  gpio_pull_up(BTN_PIN_A);
  gpio_pull_up(BTN_PIN_B);
  
  int led_a_status = 0;
  int led_b_status = 0;

  while (true) {
    if (!gpio_get(BTN_PIN_A)) {
      led_a_status = !led_a_status;
      gpio_put(LED_PIN_A, led_a_status);
    }
    if (!gpio_get(BTN_PIN_B)) {
      led_b_status = !led_b_status;
      gpio_put(LED_PIN_B, led_b_status);
    }

  }
}