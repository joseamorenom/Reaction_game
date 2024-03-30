#include "display_7seg.h"
#include "pico/stdlib.h" //Librería de las Raspberry Pi Pico

// Conjunto de los segmentos
const int segment_pins[] = {SEGMENT_A_PIN, SEGMENT_B_PIN, SEGMENT_C_PIN, SEGMENT_D_PIN, SEGMENT_E_PIN, SEGMENT_F_PIN, SEGMENT_G_PIN, SEGMENT_DP_PIN};

// Función para inicializar los pines del display de 7 segmentos (revisar con el circuito ya listo)
void display_7seg_init() {
    // Configurar los pines de los segmentos como salidas
    for (int i = 0; i < 8; i++) {
        gpio_init(segment_pins[i]);
        gpio_set_dir(segment_pins[i], GPIO_OUT);
    }
}

//Mostrar un número completo en los 4 dígitos del display de 7 segmentos
void display_7seg_show_number_complete(int number_ms) {
    int digits[4]; // Array para almacenar los dígitos de "number" en cada posición

    // Extraer cada dígito de number y almacenarlo en el array digits
    digits[0] = (number_ms / 1000) % 10; // Dígito de los segundos más significativo
    digits[1] = (number_ms / 100) % 10;  // Dígito de los segundos menos significativo
    digits[2] = (number_ms / 10) % 10;   // Dígito de las milésimas de segundo más significativo
    digits[3] = number_ms % 10;          // Dígito de las milésimas de segundo menos significativo

    // Mostrar los dígitos en los 4 displays de 7 segmentos
    for (int digit_index = 0; digit_index < 4; digit_index++) {
        // Apagar todos los segmentos para comenzar
        for (int i = 0; i < 8; i++) {
            gpio_put(segment_pins[i], 0);
        }

        // Mostrar el dígito correspondiente en el display actual
        switch (digits[digit_index]) {
            case 0:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_0 & (1 << (6 - i)));
                }
                break;
            case 1:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_1 & (1 << (6 - i)));
                }
                break;
            case 2:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_2 & (1 << (6 - i)));
                }
                break;
            case 3:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_3 & (1 << (6 - i)));
                }
                break;
            case 4:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_4 & (1 << (6 - i)));
                }
                break;
            case 5:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_5 & (1 << (6 - i)));
                }
                break;
            case 6:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_6 & (1 << (6 - i)));
                }
                break;
            case 7:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_7 & (1 << (6 - i)));
                }
                break;
            case 8:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_8 & (1 << (6 - i)));
                }
                break;
            case 9:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_9 & (1 << (6 - i)));
                }
                break;
            default:
                // Todo apagado
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_OFF & (1 << (6 - i)));
                }
                break;
        }

        // Enciende el punto decimal en el segundo display
        if (digit_index == 1) {
            gpio_put(segment_pins[SEGMENT_DP_PIN], 1);
        }

        // Retardo para que los dígitos se muestren uno a uno
        sleep_ms(4);
    }
}
