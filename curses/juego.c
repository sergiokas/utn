#include <string.h>
#include <curses.h>
#include "tablero.h"

int juego(void) {
    tablero_t * T;
    char buff[255], c;
    int x, y;

    inicializar();

    T = crear(8,8);
    titulo(T, "El titulo del juego");
    mensaje(T, "Bienvenido al juego");
    do {
        actualizar(T);
        leer(T, "Ingrese un comando: ", buff);
        // Leo coordenadas y caracter del comando ingresado
        sscanf(buff,"%d,%d,%c",&x,&y,&c);
        dibujar(T,x,y,c);
        error(T, buff);
    } while(strcmp(buff,"exit"));
    return 0;
}