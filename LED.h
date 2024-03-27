//Archivos de cabecera de los led
#ifndef LED_H
#define LED_H

// Definiciones de pines de los LEDs
#define LED_CLEAR_PIN   0  // Pin del led transparente
#define LED_YELLOW_PIN  1  // Pin del led amarillo
#define LED_RED_PIN     2  // Pin del led rojo

// Prototipos de las funciones
void leds_init();             // Inicialización
void led_on(int pin);         // Enciende un LED específico
void led_off(int pin);        // Apaga un LED específico
void led_sequence();      // Ejecuta la secuencia inicial de luces

#endif
