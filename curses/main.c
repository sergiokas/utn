#include <stdlib.h>
#include <curses.h>
#include <signal.h>
#include "tablero.h"

static void finish(int sig);

int main(int argc, char *argv[]) {
    int num = 0;
    tablero_t * T;
    char buff[255];
    /* initialize your non-curses data structures here */

    (void) signal(SIGINT, finish);      /* arrange interrupts to terminate */

    inicializar();


    // for (;;)
    // {
    //     int c = getch();     /* refresh, accept single keystroke of input */
    //     attrset(COLOR_PAIR(num % 8));
    //     num++;

    //     /* process the command keystroke */
    // }

    refresh();
    T = crear_tablero(5,3);
    titulo(T, "El titulo del juego");
    mensaje(T, "Bienvenido al juego");
    while(1) {
        actualizar(T);
        leer(T, "Ingrese un comando: ", buff);
        error(T, buff);
    }
    finish(0);               /* we're done */
    return 0;
}

static void finish(int sig) {
    endwin();

    /* do your non-curses wrapup here */

    exit(0);
}