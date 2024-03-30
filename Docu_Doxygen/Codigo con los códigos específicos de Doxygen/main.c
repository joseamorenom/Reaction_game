/**
 * @file main.c
 * @brief Implementación de la lógica del juego con mensajes en pantalla.
 */

#include "LCD_nokia5110.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LED_RED_PIN    // Define el pin para el LED rojo
#define LED_YELLOW_PIN // Define el pin para el LED amarillo
#define LED_CLEAR_PIN  // Define el pin para el LED clear
#define BUTTON_1_PIN   // Define el pin para el botón 1
#define BUTTON_2_PIN   // Define el pin para el botón 2
#define BUTTON_3_PIN   // Define el pin para el botón 3
#define START_BUTTON_PIN // Define el pin para el botón de inicio

#define GAME_TIME 10 // Duración del juego en segundos

// Función para generar un tiempo aleatorio entre min y max
int generate_random_time(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Función para mostrar el mensaje "Presiona el botón"
void display_press_button_message() {
    LCD_nokia5110_init();
    LCD_nokia5110_display_press_button();
}

// Función para mostrar el mensaje "Game Over"
void display_game_over_message() {
    LCD_nokia5110_init();
    LCD_nokia5110_display_game_over();
}

/**
 * @brief Función principal del programa.
 * @return 0 si la ejecución fue exitosa.
 */
int main() {
    stdio_init_all();

    // Configurar los pines de los LEDs y los botones
    gpio_init(LED_RED_PIN);
    gpio_init(LED_YELLOW_PIN);
    gpio_init(LED_CLEAR_PIN);
    gpio_init(BUTTON_1_PIN);
    gpio_init(BUTTON_2_PIN);
    gpio_init(BUTTON_3_PIN);
    gpio_init(START_BUTTON_PIN);

    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT);
    gpio_set_dir(LED_CLEAR_PIN, GPIO_OUT);
    gpio_set_dir(BUTTON_1_PIN, GPIO_IN);
    gpio_set_dir(BUTTON_2_PIN, GPIO_IN);
    gpio_set_dir(BUTTON_3_PIN, GPIO_IN);
    gpio_set_dir(START_BUTTON_PIN, GPIO_IN);

    srand(time(NULL)); // Inicializar la semilla para generar números aleatorios

    while (1) {
        // Esperar a que se presione el botón de inicio
        while (gpio_get(START_BUTTON_PIN)) {}

        // Mostrar el mensaje "Presiona el botón"
        display_press_button_message();

        // Encender los LEDs en secuencia
        gpio_put(LED_RED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_YELLOW_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_CLEAR_PIN, 1);
        sleep_ms(500);

        // Apagar todos los LEDs
        gpio_put(LED_RED_PIN, 0);
        gpio_put(LED_YELLOW_PIN, 0);
        gpio_put(LED_CLEAR_PIN, 0);

        // Esperar un tiempo aleatorio después de la secuencia
        sleep_ms(generate_random_time(1000, 10000));

        // Encender un LED al azar
        int random_led = rand() % 3;
        if (random_led == 0) {
            gpio_put(LED_RED_PIN, 1);
        } else if (random_led == 1) {
            gpio_put(LED_YELLOW_PIN, 1);
        } else {
            gpio_put(LED_CLEAR_PIN, 1);
        }

        // Iniciar el tiempo de reacción
        uint64_t start_time = time_us_64();

        // Esperar a que se presione un botón
        while (1) {
            if (!gpio_get(BUTTON_1_PIN) || !gpio_get(BUTTON_2_PIN) || !gpio_get(BUTTON_3_PIN)) {
                break;
            }
        }

        // Calcular el tiempo de reacción
        uint64_t reaction_time = time_us_64() - start_time;

        // Apagar todos los LEDs
        gpio_put(LED_RED_PIN, 0);
        gpio_put(LED_YELLOW_PIN, 0);
        gpio_put(LED_CLEAR_PIN, 0);

        // Mostrar el tiempo de reacción en la consola
        printf("Tiempo de reacción: %lu us\n", reaction_time);

        // Esperar un segundo antes de reiniciar el juego
        sleep_ms(1000);
    }

    return 0;
}

//Segundo main

/**
 * @file main.c
 * @brief Implementación de la lógica completa del juego con LED, botones y 7 segmentos.
 */

#include "LED.h"
#include "botones.h"
#include "display_7seg.h"
#include "LCD_nokia5110.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_DELAY_MIN_MS 1000
#define START_DELAY_MAX_MS 10000
#define MAX_GAME_TIME_SEC 10

/**
 * @brief Función principal del programa.
 * @return 0 si la ejecución fue exitosa.
 */
int main() {
    // Inicialización de los componentes
    leds_init();
    botones_init();
    display_7seg_init();
    LCD_nokia5110_init();
    
    // Semilla aleatoria para generar números aleatorios
    srand(time(NULL));

    while (1) {
        // Esperar a que se presione el botón de start
        while (!leer_botones(BOTON_START_PIN)) {
            sleep_ms(100);
        }

        // Ejecutar la secuencia de luces
        led_sequence();
        sleep_ms(1000); // Espera adicional después de la secuencia de luces

        // Generar un tiempo aleatorio entre START_DELAY_MIN_MS y START_DELAY_MAX_MS
        int start_delay = rand() % (START_DELAY_MAX_MS - START_DELAY_MIN_MS + 1) + START_DELAY_MIN_MS;
        sleep_ms(start_delay); // Esperar el tiempo aleatorio
        
        // Encender un LED aleatorio (0, 1, 2)
        int random_led = rand() % 3;
        led_on(random_led);
        int game_time_ms = 0; // Reiniciar el tiempo de juego
        while (leer_botones(BOTON_CLEAR_PIN) || leer_botones(BOTON_YELLOW_PIN) || leer_botones(BOTON_RED_PIN)) {
            // Verificar si se presionó algún botón
            sleep_ms(100); // Pequeña pausa para evitar rebotes en el botón
        }

        // Verificar el botón presionado
        uint
