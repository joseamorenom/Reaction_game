#include "botones.h"
#include "pico/stdlib.h" //Librería estándar de la Raspberry Pi Pico W

// Debounce delay en milisegundos
#define DEBOUNCE_DELAY_MS 20

// Inicialización como pull-down
void botones_init() {
    // Inicializamos la Raspberry
    stdio_init_all();

    //START
    gpio_init(BOTON_START_PIN);
    gpio_set_dir(BOTON_START_PIN, GPIO_IN);
    gpio_pull_down(BOTON_START_PIN);

    //Clear 1
    gpio_init(BOTON_CLEAR_PIN);
    gpio_set_dir(BOTON_CLEAR_PIN, GPIO_IN);
    gpio_pull_down(BOTON_CLEAR_PIN);
    //Amarillo 2
    gpio_init(BOTON_YELLOW_PIN);
    gpio_set_dir(BOTON_YELLOW_PIN, GPIO_IN);
    gpio_pull_down(BOTON_YELLOW_PIN);
    //Rojo 3
    gpio_init(BOTON_RED_PIN);
    gpio_set_dir(BOTON_RED_PIN, GPIO_IN);
    gpio_pull_down(BOTON_RED_PIN);
}

// Función de debounce
int debounce(int pin) {
    int estado_actual = gpio_get(pin);
    sleep_ms(DEBOUNCE_DELAY_MS);
    int estado_debounce = gpio_get(pin);
    return (estado_actual == estado_debounce) ? estado_actual : -1;
}

// Función para leer el estado de un pulsador específico
int leer_botones(int pin) {
    return debounce(pin);
}