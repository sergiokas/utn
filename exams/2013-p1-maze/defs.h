#define ABIERTO 0
#define CERRADO 1
#define SALIDA 2

typedef struct paso {
	char N, S, O, E;
	struct paso * next;
} paso_t;
