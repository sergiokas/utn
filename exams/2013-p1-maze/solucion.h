// Soluciona la mazmorra
int solucion(void);

// Funciones de pasos
int avanzar(paso_t ** S, paso_t * p);
void retroceder(paso_t ** S);

// Funciones auxiliares
paso_t * nodo(void);
int intentar(paso_t ** S, char D);
void cerrar(paso_t * p, char D);
char opuesto(char);
