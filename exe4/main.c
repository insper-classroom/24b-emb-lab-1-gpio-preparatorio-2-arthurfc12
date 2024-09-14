#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_A = 5;
const int LED_PIN_B = 8;
const int LED_PIN_C = 11;
const int LED_PIN_D = 15;

const int BTN_PIN_A = 28;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_A);
  gpio_init(LED_PIN_B);
  gpio_init(LED_PIN_C);
  gpio_init(LED_PIN_D);
  gpio_init(BTN_PIN_A);

  gpio_set_dir(LED_PIN_A, GPIO_OUT);
  gpio_set_dir(LED_PIN_B, GPIO_OUT);
  gpio_set_dir(LED_PIN_C, GPIO_OUT);
  gpio_set_dir(LED_PIN_D, GPIO_OUT);
  gpio_set_dir(BTN_PIN_A, GPIO_IN);

  gpio_pull_up(BTN_PIN_A);

  while (true) {
    if (!gpio_get(BTN_PIN_A)) {
      gpio_put(LED_PIN_A, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_B, 1);
      gpio_put(LED_PIN_A, 0);
      sleep_ms(300);
      gpio_put(LED_PIN_C, 1);
      gpio_put(LED_PIN_B, 0);
      sleep_ms(300);
      gpio_put(LED_PIN_D, 1);
      gpio_put(LED_PIN_C, 0);
      sleep_ms(300);
      gpio_put(LED_PIN_D, 0);
    }
    // Use delay de 300 ms entre os estados!
  }
}
