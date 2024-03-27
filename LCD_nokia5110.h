//Profudizar en esto
//sketch inicial
#ifndef LCD_NOKIA5110_H
#define LCD_NOKIA5110_H

#include <stdint.h>

#define PIN_RESET   // Define el pin para el reset
#define PIN_DC      // Define el pin para el comando/datos
#define PIN_SCE     // Define el pin para el chip enable (CE)
#define PIN_SDIN    // Define el pin para los datos de entrada (MOSI)
#define PIN_SCLK    // Define el pin para el reloj de datos (SCK)

#define SPI_PORT    spi0
#define SPI_BAUDRATE 1000000

void LCD_nokia5110_init();
void LCD_nokia5110_display_press_button();
void LCD_nokia5110_display_game_over();

#endif
