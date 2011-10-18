#include <stdio.h>		// Standard I/O
#include <sys/types.h>	// Tipos y estructuras
#include <sys/socket.h>	// Sockets
#include <stdlib.h> 	// Libreria standard de C, para usar exit()
#include <unistd.h>		// Unix standard, para usar close()
#include <netinet/in.h>	// Estructuras para sockets
#include <strings.h>	// Para usar bzero()
#include "defs.h"		// Mis propias definiciones

int main (void) {
	
	int result;
	int socketfd, clientfd;
	socklen_t client_length;
	struct sockaddr_in server_addr, client_addr;

	// Buffer para mandar y recibir datos
	char buffer[255];

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
	server_addr.sin_port = htons(PORT);

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

	printf("Servidor conectado en puerto %d\n", PORT);
	
	// Y cuando llega una conexion...
	client_length = sizeof(client_addr);
	clientfd = accept(socketfd, (struct sockaddr *) &client_addr, &client_length);

	if(clientfd<0) {
		perror("Error recibiendo conexion");
		exit(ERROR);
	}
	
	bzero(buffer, 256);
	result = read(clientfd, buffer, 255); 
	if(result>0) {
		printf("El mensaje recibido es es: %s\n", buffer);
	}
	
	// Cierra los sockets al terminar
	close(clientfd);
	close(socketfd);

	return SUCCESS;
}
