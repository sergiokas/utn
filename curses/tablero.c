#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "tablero.h"

void inicializar(void) {
  (void) initscr();      /* initialize the curses library */
  keypad(stdscr, TRUE);  /* enable keyboard mapping */
  (void) nonl();         /* tell curses not to do NL->CR/NL on output */
  (void) cbreak();       /* take input chars one at a time, no wait for \n */
  (void) echo();         /* echo input - in color */

  if (has_colors()) {
      start_color();
      init_pair(1, COLOR_RED,     COLOR_BLACK);
      init_pair(2, COLOR_GREEN,   COLOR_BLACK);
      init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
      init_pair(4, COLOR_BLUE,    COLOR_BLACK);
      init_pair(5, COLOR_CYAN,    COLOR_BLACK);
      init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
      init_pair(7, COLOR_WHITE,   COLOR_BLACK);
  }
}

tablero_t * crear_tablero(int f, int c) {
  tablero_t * t;

  t = (tablero_t *) malloc(sizeof(tablero_t));
  t->filas = f;
  t->columnas = c;

  // Tablero
  t->board = newwin(c, f, BOARD_OFFSET, ((COLS - c)/2));
  box(t->board,0,0);

  // Ventana de mensaje
  t->message = newwin(3, COLS, LINES-6, 0);
  box(t->message,0,0);

  // Ventana de entrada
  t->input = newwin(3, COLS, LINES-3, 0);
  box(t->message,0,0);

  // Ventana de titulo
  t->title = newwin(3,COLS,0,0);
  box(t->title,0,0);

  return t;
}

int leer(tablero_t * t, char * s, char * d) {
  wclear(t->input);
  box(t->input,0,0);
  wattron(t->input, A_BOLD);
  mvwprintw(t->input,1,1,s);
  wattroff(t->input, A_BOLD);
  //wscanw(t->input, "%s" , d);
  wgetstr(t->input, d);
  return 0;
}

void titulo(tablero_t * t, char * s) {
  wclear(t->title);
  box(t->title,0,0);
  wattrset(t->title, TITLE_COLOR);
  wattron(t->title, A_BOLD);
  mvwprintw(t->title,1,(COLS-strlen(s))/2,s);
  wattroff(t->title, A_BOLD);
  wattrset(t->title, DEFAULT_COLOR);
}

void mensaje(tablero_t * t, char * s) {
  wclear(t->message);
  box(t->message,0,0);
  wattrset(t->message, MSG_COLOR);
  wattron(t->message, A_BOLD);
  mvwprintw(t->message,1,1,s);
  wattroff(t->message, A_BOLD);
  wattrset(t->message, DEFAULT_COLOR);
}

void error(tablero_t * t, char * s) {
  wclear(t->message);
  box(t->message,0,0);
  wattrset(t->message, ERR_COLOR);
  wattron(t->message, A_BOLD);
  mvwprintw(t->message,1,1,s);
  wattroff(t->message, A_BOLD);
  wattrset(t->message, DEFAULT_COLOR);
}


void actualizar(tablero_t * t) {
  wrefresh(t->board);
  wrefresh(t->message);
  wrefresh(t->input);
  wrefresh(t->title);
}

int destruir_tablero(tablero_t * t) {
  free(t);
  return 0;
}