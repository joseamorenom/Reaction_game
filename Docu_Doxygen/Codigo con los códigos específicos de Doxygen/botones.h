/**
 * @file botones.h
 * @brief Archivo de cabecera para el control de los pulsadores.
 */

#ifndef BOTONES_H
#define BOTONES_H

/**
 * @def BOTON_START_PIN
 * @brief Número de pin del pulsador de inicio.
 * 
 * Define el número de pin asociado al pulsador de inicio en la Raspberry Pi Pico W.
 */
#define BOTON_START_PIN    13  

/**
 * @def BOTON_CLEAR_PIN
 * @brief Número de pin del pulsador del LED clear.
 * 
 * Define el número de pin asociado al pulsador del LED clear en la Raspberry Pi Pico W.
 */
#define BOTON_CLEAR_PIN    5  

/**
 * @def BOTON_YELLOW_PIN
 * @brief Número de pin del pulsador del LED yellow.
 * 
 * Define el número de pin asociado al pulsador del LED yellow en la Raspberry Pi Pico W.
 */
#define BOTON_YELLOW_PIN   6  

/**
 * @def BOTON_RED_PIN
 * @brief Número de pin del pulsador del LED red.
 * 
 * Define el número de pin asociado al pulsador del LED red en la Raspberry Pi Pico W.
 */
#define BOTON_RED_PIN      7  

/**
 * @brief Inicializa los pulsadores.
 * 
 * Esta función inicializa los pines de los pulsadores y los configura correctamente.
 */
void botones_init();

/**
 * @brief Lee el estado de un pulsador específico.
 * 
 * Esta función lee el estado del pulsador asociado al pin especificado.
 * 
 * @param pin El número del pin del pulsador que se desea leer.
 * @return El estado del pulsador (1 si está presionado, 0 si no lo está).
 */
int leer_botones(int pin);

#endif
