// leds.c

#include "LED.h"
#include "pico/stdlib.h" // Incluimos la librería estándar de la Raspberry Pi Pico W

// Inicialización de los pines de los LEDs
void leds_init() {
    // Inicializamos la Raspberry Pi Pico W
    //stdio_init_all();

    // Pines de los LED como salida
    gpio_init(LED_CLEAR_PIN);
    gpio_set_dir(LED_CLEAR_PIN, GPIO_OUT);
    gpio_init(LED_YELLOW_PIN);
    gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT);
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
}

// Función para encender un LED específico
void led_on(int pin) {
    gpio_put(pin, 1);
}

// Función para apagar un LED específico
void led_off(int pin) {
    gpio_put(pin, 0);
}

// Función para la secuencia inicial de luces
void led_sequence() {
    // Enciende y apaga según la secuencia de la guia
    //(1,1,1)
    led_on(LED_CLEAR_PIN);
    led_on(LED_YELLOW_PIN);
    led_on(LED_RED_PIN);
    sleep_ms(1000);  // Espera 1 segundo
    //(0,1,1)
    led_off(LED_CLEAR_PIN);
    led_on(LED_YELLOW_PIN);
    led_on(LED_RED_PIN);
    sleep_ms(1000);  // Espera 1 segundo
    //(0,0,1)
    led_off(LED_CLEAR_PIN);
    led_off(LED_YELLOW_PIN);
    led_on(LED_RED_PIN);
    sleep_ms(1000);  // Espera 1 segundo
    //(0,0,0)
    led_off(LED_CLEAR_PIN);
    led_off(LED_YELLOW_PIN);
    led_off(LED_RED_PIN);
    sleep_ms(1000);  // Espera 1 segundo
}
