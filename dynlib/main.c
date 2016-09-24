#include <dlfcn.h>
#include <stdio.h>

#define ERR_NOLIB 1;
#define ERR_NOSYM 2;
#define ERR_NOARG 3;
#define OK 0;

int main (int argc, char ** argv) {

	void * handle;

	// El puntero a funcion deber un prototipo definido por la libreria.
	void (*f)(char *);

	if(argc!=2) {
		printf("No se ingresaron argumentos. Utilice ./main [nombre-de-funcion]\n");
		return ERR_NOARG;
	}

	// Cargo la libreria dinamica.
	handle = dlopen("./libprinter.so.1.0.0", RTLD_LAZY);

	if(!handle) {
		printf("No se encuentra la libreria dinamica\n");
		return ERR_NOLIB;
	}

	// Busco la funcion que me piden
	f = dlsym(handle, argv[1]);

	if(!f) {
		printf("No se encuentra la funcion dentro de la libreria\n");
		return ERR_NOSYM;
	}

	// Todo bien, imprimo el mensaje
	f("Este es mi mensaje");


	// Termino de usar la libreria dinamica
	dlclose(handle);
	
	return OK;
}
