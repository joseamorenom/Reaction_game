
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "LED.h"
#include "display_7seg.h"
#include "botones.h"
#include <stdio.h>
#include <time.h>
#include <pico/rand.h>
#include <stdlib.h>
#include <unistd.h>
#include <pico/time.h>

#define LED_RED_PIN    4 // Define el pin para el LED rojo
#define LED_YELLOW_PIN 3 // Define el pin para el LED amarillo
#define LED_CLEAR_PIN  2 // Define el pin para el LED clear
#define BUTTON_1_PIN   7 // Define el pin para el botón 1
#define BUTTON_2_PIN   6 // Define el pin para el botón 2
#define BUTTON_3_PIN   5 // Define el pin para el botón 3
#define START_BUTTON_PIN 13 // Define el pin para el botón de inicio

#define GAME_TIME 10000 // Duración del juego en segundos



// Función para generar un tiempo aleatorio entre min y max
void wait_random(uint64_t min_us, uint64_t max_us) {
    uint64_t random_us = min_us + (get_rand_64() % (max_us - min_us + 1)); 
    busy_wait_us(random_us); //hace la pausa del tiempo aleatorio
}

//Genera un numero aleatorio entre 1 y 10, que representa el tiempo de espera aleatorio
int tiempo_aleatorio() {
    // Semilla para la generación de números aleatorios
    srand(time(NULL));
    // Generar un número aleatorio entre 1 y 10
    return (rand() % 10) + 1;
}


//Recibe el numero del pin asociado al led encendido y retorna un arreglo con los pines asociado a los leds apagados
//Este arreglo contiene los pines de los pulsadores que generaría una penalidad al ser presionados.
int* bad_button(int bueno) {
    static int arreglo[2];

    if (bueno == 5) {
        arreglo[0] = 6;
        arreglo[1] = 7;
    } else if (bueno == 6) {
        arreglo[0] = 5;
        arreglo[1] = 7;
    } else if (bueno == 7) {
        arreglo[0] = 5;
        arreglo[1] = 6;
    }

    return arreglo;
}

int main() {
    
    leds_init();
    stdio_init_all();
    display_7seg_init();
    enables_init();
    int boton_correcto;
    uint32_t penalty;
    uint32_t elapsed_time_ms;
    uint32_t anteriortime;
    elapsed_time_ms = 0;
    while(1){
        display_7seg_show_number(elapsed_time_ms);
        if(leer_botones(START_BUTTON_PIN)==1){

            //Variables para el conteo del tiempo
            uint32_t start_time_us, end_time_us;

            boton_correcto = 0;
            penalty = 0;


            //Ejecuto la secuencia
            led_sequence();

            //Espero un tiempo aleatorio
            sleep_ms(tiempo_aleatorio()*1000);
            
            //Genero un indice para escoger un led aleatorio y lo prendo
            srand(time(NULL));
            int led_aleatorio = (rand() % 3) + 1;

            //printf("El pin selecciondo es%d", led_aleatorio);

            //Enciendo el LED aleatorio
            if(led_aleatorio == 1){
                led_on(LED_RED_PIN);
                boton_correcto = BUTTON_1_PIN;
            } else if(led_aleatorio == 2){
                led_on(LED_YELLOW_PIN);
                boton_correcto = BUTTON_2_PIN;
            } else{
                led_on(LED_CLEAR_PIN);
                boton_correcto = BUTTON_3_PIN;
            }
            
            //Identifico los LED que generarían penalidades
            int *resultado = bad_button(boton_correcto);

            //Comienzo con el conteo del tiempo
            start_time_us = to_ms_since_boot(get_absolute_time());
            //printf("tiempo de inicio:%d", start_time_us);

            //tiempo transcurrido
            elapsed_time_ms = (to_ms_since_boot(get_absolute_time()) - start_time_us);

            //Limit el tiempo de juego a 10 segundos
            while(elapsed_time_ms+penalty<10000){
                //Se sale si se oprime el boton correcto
                if(leer_botones(boton_correcto)==1){
                    break;
                }
                //Actualizo el tiempo iterativamente para verificar la condición del while
                end_time_us = to_ms_since_boot(get_absolute_time());
                elapsed_time_ms = (end_time_us - start_time_us);
                
                //Añado las penalidades al timepo
                if(leer_botones(START_BUTTON_PIN) || leer_botones(resultado[0]) || leer_botones(resultado[1])){
                    penalty += 1000;
                    sleep_ms(250);
                    
                }
                if(elapsed_time_ms + penalty>9999){
                    break;
                }
                
            }
            //Apago todos los LED

            led_off(LED_RED_PIN);
            led_off(LED_CLEAR_PIN);
            led_off(LED_YELLOW_PIN);

            //printf("Tiempo final %d", elapsed_time_ms);
            printf("Antes de las penalties el tiempo es \n %d", elapsed_time_ms);
            printf("Las penalidades valen: \n %d", penalty);
            elapsed_time_ms = elapsed_time_ms + penalty;
            printf("Después de las penalties el tiempo es \n %d", elapsed_time_ms);
            penalty = 0;
            //Muestro el tiempo en los 7 segmentos
            if(elapsed_time_ms+penalty>=9999){
                //Si se pasa de los 10 segundos, muestro el tiempo anterior
                elapsed_time_ms = anteriortime;
                display_7seg_show_number(elapsed_time_ms);
            }else{
                //Si no se pasa de los 10 segundos, muestro el tiempo obtenido
                anteriortime = elapsed_time_ms;
                display_7seg_show_number(elapsed_time_ms);
            }

        }
       
    }//Del while 1
}