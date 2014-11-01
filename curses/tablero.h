// Offset del tablero respecto al borde superior
#define BOARD_OFFSET 5
// Alto de celda en caracteres
#define CELL_H 3
// Ancho de celda en caracteres
#define CELL_W 7

// Color pairs
#define CP1 COLOR_WHITE, COLOR_BLACK
#define CP2 COLOR_BLACK, COLOR_WHITE
#define CP3 COLOR_GREEN, COLOR_BLACK
#define CP4 COLOR_RED,   COLOR_BLACK
#define CP5 COLOR_WHITE, COLOR_BLACK
#define CP6 COLOR_WHITE, COLOR_GREEN
#define CP7 COLOR_WHITE, COLOR_BLUE

// Colores
#define DEFAULT_COLOR COLOR_PAIR(1)
#define MSG_COLOR COLOR_PAIR(3)
#define ERR_COLOR COLOR_PAIR(4)
#define TITLE_COLOR COLOR_PAIR(1)
#define CELL_ODD COLOR_PAIR(6)
#define CELL_EVEN COLOR_PAIR(7)

typedef struct {
  int filas;
  int columnas;
  int casilleros;
  WINDOW ** board; // Ventana del tablero
  WINDOW * border;
  WINDOW * message;   // Ventana de mensaje
  WINDOW * input;   // Ventana de comandos
  WINDOW * title; // Ventana de titulo
} tablero_t;

// Inicializa la interfaz grafica
void inicializar(void);

// Crea un tablero de f=filas x c=columnas, con elementos de control
tablero_t * crear(int f, int c);

// Crea todos los casilleros del tablero
void _crear_tablero(WINDOW ** b, int f, int c);

// Crea borde del tablero
WINDOW * _crear_borde(int f, int c);

// Dibuja un caracter en una posicion del tablero
void dibujar(tablero_t * t, int f, int c, char l);

// Borra el caracter del tablero
void borrar(tablero_t * t, int f, int c);

// Lee un comando, con una etiqueta opcional
int leer(tablero_t * t, char * s, char * d);

// Muestra un mensaje
void mensaje(tablero_t * t, char * s);

// Muestra un error
void error(tablero_t * t, char * s);

// Setea el titulo del tablero
void titulo(tablero_t * t, char * s);

// Actualiza los elementos del tablero
void actualizar(tablero_t * t);