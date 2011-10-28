#include <stdio.h>		// Standard I/O
#include <sys/types.h>	// Tipos y estructuras
#include <sys/socket.h>	// Sockets
#include <stdlib.h> 	// Libreria standard de C, para usar exit()
#include <unistd.h>		// Unix standard, para usar close()
#include <netinet/in.h>	// Estructuras para sockets
#include <strings.h>	// Para usar bzero()
#include <string.h>		// Para usar bzero()
#include "defs.h"		// Mis propias definiciones

int validate_file(char *);

int main (int argc, char ** argv) {
	
	int result, size;
	int socketfd, clientfd, port;
	socklen_t client_length;
	struct sockaddr_in server_addr, client_addr;

	// Get port number, set default otherwise
	port = (argc<2) ? PORT : atoi(argv[1]);

	// Buffer para mandar y recibir datos
	char buffer[BUFFER_SIZE];
	char filename[255];

	FILE * dest;

	// Abre un socket
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	
	if(!socketfd) {
		perror("Error al abrir socket");
		exit(ERROR);
	}

	// Preparo la estructura de direccionamiento del server
	bzero((char*) &server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(port);

	// Vincula el socket con el puerto
	result = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
	if(result<0) {
		perror("Error al bindear socket");
		exit(ERROR);
	}

	// Se pone a esperar conexiones que lleguen a ese puerto
	result = listen(socketfd, BACKLOG);
	if(result<0) {
		perror("Error intentando escuchar en puerto");
		exit(ERROR);
	}

	printf("Servidor conectado en puerto %d\n", port);
	
	// Y cuando llega una conexion...
	client_length = sizeof(client_addr);
	while(1) { 
		clientfd = accept(socketfd, (struct sockaddr *) &client_addr, &client_length);

		if(clientfd<0) {
			perror("Error recibiendo conexion");
			exit(ERROR);
		}
			
		// Build the and open the destination filename
		//sprintf(filename, "recv/image-%d.jpg", rand());
		read(clientfd, filename, 255);

		// validate filename
		if(!validate_file(filename)) {
			printf("Error recibiendo archivo no permitido %s\n", filename);
			write(clientfd, "ER", 3);
		}
		else {
		  write(clientfd, "OK", 3);
		  dest = fopen(filename, "w");
		  if(dest == NULL) {
			  perror("No se puede abrir el archivo de salida");
			  exit(ERROR);
		  }
		  size = 0;
		  while((result = read(clientfd, buffer, BUFFER_SIZE))) {
			  size += result;
			  if(result>0) {
				  fwrite(buffer, 1, result, dest);
			  }
		  }
		  printf("Recibidos %d bytes desde el socket, guardado en %s\n", size, filename);
		  fclose(dest);
		}
		// Cierra socket al terminar
		fflush(stdout);
		close(clientfd);
	}
	close(socketfd);

	return SUCCESS;
}

int validate_file(char * filename) {
	return (
		strstr(filename, ".jpg") ||
		strstr(filename, ".gif") ||
		strstr(filename, ".png")
	);
}