#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "tablero.h"

int juego(void) {
    tablero_t * T;
    char buff[255];

    inicializar();

    T = crear(8,8);
    titulo(T, "El titulo del juego");
    mensaje(T, "Bienvenido al juego");
    do {
        dibujar(T,1,2,'X');
        actualizar(T);
        leer(T, "Ingrese un comando: ", buff);
        error(T, buff);
    } while(strcmp(buff,"exit"));
    return 0;
}