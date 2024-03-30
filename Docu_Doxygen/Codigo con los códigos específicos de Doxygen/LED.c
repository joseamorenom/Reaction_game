/**
 * @file leds.c
 * @brief Implementación del control de los LEDs.
 */
#include "LED.h"
#include "pico/stdlib.h" // Incluimos la librería estándar de la Raspberry Pi Pico W
/**
 * @brief Inicializa los pines de los LEDs.
 * 
 * Esta función configura los pines de los LEDs como salidas.
 */
void leds_init() {
    // Inicializamos la Raspberry Pi Pico W
    stdio_init_all();

    // Pines de los LED como salida
    gpio_init(LED_CLEAR_PIN);
    gpio_set_dir(LED_CLEAR_PIN, GPIO_OUT);
    gpio_init(LED_YELLOW_PIN);
    gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT);
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
}

/**
 * @brief Enciende un LED específico.
 * 
 * @param pin El número de pin del LED que se desea encender.
 */
void led_on(int pin) {
    gpio_put(pin, 1);
}

/**
 * @brief Apaga un LED específico.
 * 
 * @param pin El número de pin del LED que se desea apagar.
 */
void led_off(int pin) {
    gpio_put(pin, 0);
}

/**
 * @brief Realiza la secuencia inicial de luces.
 * 
 * Esta función enciende y apaga los LEDs según la secuencia especificada.
 * La secuencia es la siguiente: (1,1,1), (0,1,1), (0,0,1), (0,0,0).
 */
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
