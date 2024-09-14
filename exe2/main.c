#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 2;
const int BTN_PIN_B = 5;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(BTN_PIN_B);
  gpio_set_dir(BTN_PIN_B, GPIO_IN);
  gpio_pull_up(BTN_PIN_B);

    bool lastStateBtn = true; // Assume starting unpressed
    bool lastStateBtnB = true;

    while (true) {
        bool currentStateBtn = gpio_get(BTN_PIN);
        bool currentStateBtnB = gpio_get(BTN_PIN_B);

        // Check for transition from high to low (button press)
        if(lastStateBtn && !currentStateBtn) {
            printf("Button 1\n");
            sleep_ms(200); // Simple debounce
        }
        if(lastStateBtnB && !currentStateBtnB) {
            printf("Button 2\n");
            sleep_ms(200); // Simple debounce
        }

        lastStateBtn = currentStateBtn;
        lastStateBtnB = currentStateBtnB;

        // Small delay to help with debounce and reduce CPU usage
        sleep_ms(10);
    }
}