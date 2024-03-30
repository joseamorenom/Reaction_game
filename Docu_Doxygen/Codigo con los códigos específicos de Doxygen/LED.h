/**
 * @file LED.h
 * @brief Definiciones y prototipos de funciones para controlar los LEDs.
 */
#ifndef LED_H
#define LED_H

/**
 * @brief Definiciones de pines de los LEDs.
 * 
 * Se definen los pines correspondientes a cada LED.
 */

#define LED_CLEAR_PIN   2  // Pin del led transparente
#define LED_YELLOW_PIN  3  // Pin del led amarillo
#define LED_RED_PIN     4  // Pin del led rojo

/**
 * @brief Inicializa los pines de los LEDs.
 * 
 * Esta función configura los pines de los LEDs como salidas.
 */
void leds_init();             // Inicialización
/**
 * @brief Enciende un LED específico.
 * 
 * @param pin El número de pin del LED que se desea encender.
 */
void led_on(int pin);         // Enciende un LED específico
/**
 * @brief Apaga un LED específico.
 * 
 * @param pin El número de pin del LED que se desea apagar.
 */
void led_off(int pin);        // Apaga un LED específico
/**
 * @brief Ejecuta la secuencia inicial de luces.
 * 
 * Esta función enciende y apaga los LEDs según una secuencia predefinida.
 */
void led_sequence();      // Ejecuta la secuencia inicial de luces

#endif
