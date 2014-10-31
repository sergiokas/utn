#define SCORE_ROWS 2
#define COLS_MULT 5
#define ROWS_MULT 3
#define BOARD_OFFSET 5

// Colores
#define DEFAULT_COLOR COLOR_PAIR(7)
#define MSG_COLOR COLOR_PAIR(2)
#define ERR_COLOR COLOR_PAIR(1)
#define TITLE_COLOR COLOR_PAIR(7)

typedef struct {
  int filas;
  int columnas;
  WINDOW * board; // Ventana del tablero
  WINDOW * message;   // Ventana de mensaje
  WINDOW * input;   // Ventana de comandos
  WINDOW * title; // Ventana de titulo
} tablero_t;

void inicializar(void);
// Crea un tablero de f=filas x c=columnas
tablero_t * crear_tablero(int f, int c);
// Lee un comando, con una etiqueta opcional
int leer(tablero_t * t, char * s, char * d);
// Muestra un mensaje
void mensaje(tablero_t * t, char * s);
// Muestra un error
void error(tablero_t * t, char * s);
// Setea el titulo del tablero
void titulo(tablero_t * t, char * s);
// Actualiza el tablero
void actualizar(tablero_t * t);
// Destruye el tablero
int destruir_tablero(tablero_t * t);