#include <stdlib.h>
#include <signal.h>
#include <curses.h>
#include "juego.h"

// Termina el programa
static void finish(int sig);

static void finish(int sig) {
    endwin();
    exit(0);
}

int main(int argc, char *argv[]) {
    (void) signal(SIGINT, finish); // Captura Ctrl+C
    finish(juego());               /* we're done */
    return 0;
}
