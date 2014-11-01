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
    init_pair(1, CP1);
    init_pair(2, CP2);
    init_pair(3, CP3);
    init_pair(4, CP4);
    init_pair(5, CP5);
    init_pair(6, CP6);
    init_pair(7, CP7);

  }

  refresh();
}

tablero_t * crear(int f, int c) {
  tablero_t * t;

  t = (tablero_t *) malloc(sizeof(tablero_t));
  t->filas = f;
  t->columnas = c;
  t->casilleros = f*c;

  // Todos los casilleros
  t->board = (WINDOW **) malloc(sizeof(WINDOW*)*f*c);
  _crear_tablero(t->board,f,c);

  // Borde alrededor del tablero
  t->border = _crear_borde(f,c);

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

void _crear_tablero(WINDOW ** b, int f, int c) {
  int i, hoff, voff, sw;
  // Casilleros
  hoff = (COLS-(CELL_W*c))/2;
  voff = 0;
  sw = 0;
  for(i=0; i<f*c; i++) {
    if(i && !(i%f)) {
      voff += CELL_H;
      sw=(sw)?0:1;
    }
    b[i] = newwin(CELL_H, CELL_W, BOARD_OFFSET+voff, hoff+(i%f)*CELL_W);
    wbkgd(b[i], ((i+sw)%2) ? CELL_ODD : CELL_EVEN );
  }
}

WINDOW * _crear_borde(int f, int c) {
  WINDOW *b;
  int i;
  b = newwin(f*CELL_H+2, c*CELL_W+4, BOARD_OFFSET-1, (COLS-(CELL_W*c))/2-2);
  box(b,0,0);
  // Add col, row numbers
  for(i=0;i<c;i++) {
    mvwprintw(b, 0, (CELL_W*i)+(CELL_W/2)+2, "%d", i);
  }
  for(i=0;i<f;i++) {
    mvwprintw(b, (CELL_H*i)+(CELL_H/2)+1, 0, "%d", i);
  }
  return b;
}

void dibujar(tablero_t * t, int f, int c, char l) {
  WINDOW * w;
  w = t->board[t->columnas*f+c];
  mvwprintw(w,CELL_H/2,CELL_W/2,"%c",l);
}

void borrar(tablero_t * t, int f, int c) {
  dibujar(t,f,c,' ');
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
  int i;
  wrefresh(t->border);
  wrefresh(t->message);
  wrefresh(t->input);
  wrefresh(t->title);
  for(i=0; i<t->casilleros;i++) {
    wrefresh(t->board[i]);
  }
}