#include "botones.h"
#include "pico/stdlib.h" //Librería estándar de la Raspberry Pi Pico W

// Inicialización como pull-up
void botones_init() {
    // Inicializamos la Raspberry
    stdio_init_all();

    //START
    gpio_init(BOTON_START_PIN);
    gpio_set_dir(BOTON_START_PIN, GPIO_IN);
    gpio_pull_up(BOTON_START_PIN);

    //Clear 1
    gpio_init(BOTON_CLEAR_PIN);
    gpio_set_dir(BOTON_CLEAR_PIN, GPIO_IN);
    gpio_pull_up(BOTON_CLEAR_PIN);
    //Amarillo 2
    gpio_init(BOTON_YELLOW_PIN);
    gpio_set_dir(BOTON_YELLOW_PIN, GPIO_IN);
    gpio_pull_up(BOTON_YELLOW_PIN);
    //Rojo 3
    gpio_init(BOTON_RED_PIN);
    gpio_set_dir(BOTON_RED_PIN, GPIO_IN);
    gpio_pull_up(BOTON_RED_PIN);
}

// Función para leer el estado de un pulsador específico
int leer_botones(int pin) {
    return gpio_get(pin);
}
