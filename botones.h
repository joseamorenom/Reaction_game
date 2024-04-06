//Archivos de cabecera de los pulsadores
#ifndef BOTONES_H
#define BOTONES_H

// Definiciones de pines de los pulsadores en la Raspberry Pi Pico W
#define BOTON_START_PIN    13  // Pin del pulsador de start
#define BOTON_CLEAR_PIN    5  // Pin del pulsador del LED clear
#define BOTON_YELLOW_PIN   6  // Pin del pulsador del LED yellow
#define BOTON_RED_PIN      7  // Pin del pulsador del LED red

// Prototipos de las funciones
void botones_init();               // Inicialización de los pulsadores
int leer_botones(int pin);         // Lee el estado de un pulsador específico

#endif
