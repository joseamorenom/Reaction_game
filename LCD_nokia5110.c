#include "LCD_nokia5110.h"
#include "pico/stdlib.h" 

// Definición de mensajes
const uint8_t press_button_message[6][84] = {
    // Matriz de bytes para el mensaje "Presiona el botón"
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const uint8_t game_over_message[6][84] = {
    // Matriz de bytes para el mensaje "Game Over"
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void LCD_nokia5110_init() {
    // Configurar los pines necesarios para el control del display Nokia 5110
    // Esto incluye los pines para RESET, DC, SCE, SDIN (MOSI) y SCLK (SCK)

    // Configurar la interfaz SPI para comunicarse con el display
    spi_init(SPI_PORT, SPI_BAUDRATE);

    // Configurar el chip enable (CE) del display
    gpio_init(PIN_SCE);
    gpio_set_dir(PIN_SCE, GPIO_OUT);

    // Inicialización del display
    gpio_put(PIN_SCE, 0); // Habilitar el chip (CE) del display

    // Enviar los comandos de inicialización al display
    LCD_nokia5110_send_command(0x33); // 110011
    LCD_nokia5110_send_command(0x32); // 110010
    LCD_nokia5110_send_command(0x06); // 000110
    LCD_nokia5110_send_command(0x6C); // 011011
    LCD_nokia5110_send_command(0x84); // 100001
    LCD_nokia5110_send_command(0x01); // 000001
    LCD_nokia5110_send_command(0xF0); // 111100
}

void LCD_nokia5110_display_press_button() {
    // Enviar los datos del mensaje "Presiona el botón" al display
    // (aquí deberías enviar los datos de la matriz press_button_message al display)
    LCD_nokia5110_send_data(press_button_message);
    gpio_put(PIN_SCE, 1); // Deshabilitar el chip (CE) del display
    sleep_ms(100);

}

void LCD_nokia5110_display_game_over() {
    // Enviar los datos del mensaje "Game Over" al display
    // (aquí deberías enviar los datos de la matriz game_over_message al display)
    LCD_nokia5110_send_data(game_over_message);
    gpio_put(PIN_SCE, 1); // Deshabilitar el chip (CE) del display
    sleep_ms(100);
}
