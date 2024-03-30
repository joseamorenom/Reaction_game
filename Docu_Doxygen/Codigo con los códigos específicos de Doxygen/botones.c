/**
 * @file botones.c
 * @brief Implementación del control de los pulsadores.
 */

#include "botones.h"
#include "pico/stdlib.h" // Librería estándar de la Raspberry Pi Pico W

/**
 * @brief Inicializa los pulsadores como pull-down.
 * 
 * Esta función inicializa los pines de los pulsadores y los configura como entradas
 * con resistencia pull-down activada.
 */
void botones_init() {
    // Inicializa la Raspberry Pi Pico W
    stdio_init_all();

    // Configura el pulsador de START
    gpio_init(BOTON_START_PIN);
    gpio_set_dir(BOTON_START_PIN, GPIO_IN);
    gpio_pull_down(BOTON_START_PIN);

    // Configura el pulsador de CLEAR
    gpio_init(BOTON_CLEAR_PIN);
    gpio_set_dir(BOTON_CLEAR_PIN, GPIO_IN);
    gpio_pull_down(BOTON_CLEAR_PIN);

    // Configura el pulsador de YELLOW
    gpio_init(BOTON_YELLOW_PIN);
    gpio_set_dir(BOTON_YELLOW_PIN, GPIO_IN);
    gpio_pull_down(BOTON_YELLOW_PIN);

    // Configura el pulsador de RED
    gpio_init(BOTON_RED_PIN);
    gpio_set_dir(BOTON_RED_PIN, GPIO_IN);
    gpio_pull_down(BOTON_RED_PIN);
}

/**
 * @brief Lee el estado de un pulsador específico.
 * 
 * Esta función lee el estado del pulsador asociado al pin especificado.
 * @param pin El número del pin del pulsador que se desea leer.
 * @return El estado del pulsador (1 si está presionado, 0 si no lo está).
 */
int leer_botones(int pin) {
    return gpio_get(pin);
}
