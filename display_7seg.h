//Archivos de cabecera de los 7 segmentos
#ifndef DISPLAY_7SEG_H
#define DISPLAY_7SEG_H

// Definiciones de pines para los segmentos del display de 7 segmentos
#define SEGMENT_A_PIN   0
#define SEGMENT_B_PIN   1
#define SEGMENT_C_PIN   2
#define SEGMENT_D_PIN   3
#define SEGMENT_E_PIN   4
#define SEGMENT_F_PIN   5
#define SEGMENT_G_PIN   6
#define SEGMENT_DP_PIN  7  //punto decimal

// Definiciones de los dígitos del display de 7 segmentos
#define DIGIT_0    0b00111111
#define DIGIT_1    0b00000110
#define DIGIT_2    0b01011011
#define DIGIT_3    0b01001111
#define DIGIT_4    0b01100110
#define DIGIT_5    0b01101101
#define DIGIT_6    0b01111101
#define DIGIT_7    0b00000111
#define DIGIT_8    0b01111111
#define DIGIT_9    0b01101111
#define DIGIT_OFF  0b00000000

// Prototipos de funciones
void display_7seg_init();                           // Inicialización
void display_7seg_show_number(int number);          // Muestra un número en los 4 dígitos del 7 segmentos
#endif
