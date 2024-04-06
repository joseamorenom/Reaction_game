#include "botones.h"
#include "pico/stdlib.h" //Librería estándar de la Raspberry Pi Pico W

// Inicialización como pull-up
void botones_init() {
    // Inicializamos la Raspberry
    stdio_init_all();

    //START
    gpio_init(BOTON_START_PIN);
    gpio_set_dir(BOTON_START_PIN, GPIO_IN);
    gpio_pull_down(BOTON_START_PIN);
    //antirrebote
    gpio_set_input_hysteresis_enabled(BOTON_START_PIN,true);
    //Clear 1
    gpio_init(BOTON_CLEAR_PIN);
    gpio_set_dir(BOTON_CLEAR_PIN, GPIO_IN);
    gpio_pull_down(BOTON_CLEAR_PIN);
    //antirrebote
    gpio_set_input_hysteresis_enabled(BOTON_CLEAR_PIN,true);
    //Amarillo 2
    gpio_init(BOTON_YELLOW_PIN);
    gpio_set_dir(BOTON_YELLOW_PIN, GPIO_IN);
    gpio_pull_down(BOTON_YELLOW_PIN);
    //antirrebote
    gpio_set_input_hysteresis_enabled(BOTON_YELLOW_PIN,true);
    //Rojo 3
    gpio_init(BOTON_RED_PIN);
    gpio_set_dir(BOTON_RED_PIN, GPIO_IN);
    gpio_pull_down(BOTON_RED_PIN);
    //antirrebote
    gpio_set_input_hysteresis_enabled(BOTON_RED_PIN,true);
}

// Función para leer el estado de un pulsador específico
int leer_botones(int pin) {
    return gpio_get(pin);
}
