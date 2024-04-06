#include "display_7seg.h"
#include "pico/stdlib.h" //Librería de las Raspberry

// Conjunto de los segmentos
const int segment_pins[] = {SEGMENT_A_PIN, SEGMENT_B_PIN, SEGMENT_C_PIN, SEGMENT_D_PIN, SEGMENT_E_PIN, SEGMENT_F_PIN, SEGMENT_G_PIN};

// Función para inicializar los pines del display de 7 segmentos (revisar con el circuito ya listo)
void display_7seg_init() {
    // Configurar los pines de los segmentos como salidas
    for (int i = 0; i < 7; i++) {
        gpio_init(segment_pins[i]);
        gpio_set_dir(segment_pins[i], GPIO_OUT);
    }
}

// Conjunto de los enable
const int segment_enab[] = {DENABLE_ONE, DENABLE_TWO, DENABLE_THREE, DENABLE_FOUR};

// Función para inicializar los enable de los 7 segmentos
void enables_init() {
    // Configurar los pines de los segmentos como salidas
    for (int i = 0; i < 4; i++) {
        gpio_init(segment_enab[i]);
        gpio_set_dir(segment_enab[i], GPIO_OUT);
    }
}

//Habilita los enable de los 7 segmentos
void habilitar_7seg(){

    gpio_put(DENABLE_ONE,1);
    gpio_put(DENABLE_TWO,1);
    gpio_put(DENABLE_THREE,1);
    gpio_put(DENABLE_FOUR,1);
}

//Deshabilita los enable de los 7 segmentos
void Deshab_7seg(){

    gpio_put(DENABLE_ONE,0);
    gpio_put(DENABLE_TWO,0);
    gpio_put(DENABLE_THREE,0);
    gpio_put(DENABLE_FOUR,0);
}

//Mostrar un número en los 4 dígitos del display de 7 segmentos
void display_7seg_show_number(int number) {
    int digits[4]; // Array para almacenar los dígitos de "number" en cada posición

    // Extraer cada dígito de number y almacenarlo en el array digits
    digits[0] = number % 10;
    number /= 10;
    digits[1] = number % 10;
    number /= 10;
    digits[2] = number % 10;
    number /= 10;
    digits[3] = number % 10;

    // Mostrar los dígitos en los 4 displays de 7 segmentos
    for (int digit_index = 0; digit_index < 4; digit_index++) {
        // Apagar todos los segmentos para comenzar
        for (int i = 0; i < 8; i++) {
            gpio_put(segment_pins[i], 0);
        }

        if (digit_index==0){
            gpio_put(DENABLE_ONE,1);
            gpio_put(DENABLE_TWO,0);
            gpio_put(DENABLE_THREE,0);
            gpio_put(DENABLE_FOUR,0);
        }else if (digit_index==1){
            gpio_put(DENABLE_TWO,1);
            gpio_put(DENABLE_ONE,0);
            gpio_put(DENABLE_THREE,0);
            gpio_put(DENABLE_FOUR,0);
        }else if(digit_index==2){
            gpio_put(DENABLE_THREE,1);
            gpio_put(DENABLE_ONE,0);
            gpio_put(DENABLE_TWO,0);
            gpio_put(DENABLE_FOUR,0);
        }else{
            gpio_put(DENABLE_FOUR,1);
            gpio_put(DENABLE_ONE,0);
            gpio_put(DENABLE_TWO,0);
            gpio_put(DENABLE_THREE,0);
        }

        // Mostrar el dígito correspondiente en el display actual (va de a uno)
        switch (digits[digit_index]) {
            case 0:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_0 & (1 << i));
                }
                break;
            case 1:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_1 & (1 << i));
                }
                break;
            case 2:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_2 & (1 << i));
                }
                break;
            case 3:
                for (int i = 0; i < 7; i++)  {
                    gpio_put(segment_pins[i], DIGIT_3 & (1 << i));
                }
                break;
            case 4:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_4 & (1 << i));
                }   
                break;
            case 5:
                for (int i = 0; i < 7; i++) {   
                    gpio_put(segment_pins[i], DIGIT_5 & (1 << i));
                }   
                break;
            case 6:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_6 & (1 << i));
                }   
                break;
            case 7:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_7 & (1 << i));
                }   
                break;
            case 8:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_8 & (1 << i));
                }   
                break;
            case 9:
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_9 & (1 << i));
                }   
                break;
            
            default:
                //Todo apagado
                for (int i = 0; i < 7; i++) {
                    gpio_put(segment_pins[i], DIGIT_OFF & (1 << i));
                }
                break;
            
        }

        // Reatrdo para que los dígitos se muestren uno a uno
        busy_wait_ms(4);
    }
}
