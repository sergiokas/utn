#include <stdio.h>		// Standard I/O
#include <sys/types.h>	// Tipos y estructuras
#include <sys/socket.h>	// Sockets
#include <stdlib.h> 	// Libreria standard de C, para usar exit()
#include <unistd.h>		// Unix standard, para usar close()
#include <netinet/in.h>	// Estructuras para sockets
#include <string.h>		// Para usar strlen() y strcmp()
#include <strings.h>	// Para usar bzero() y bcopy()
#include <netdb.h>		// Para usar gethostbyname()
#include "defs.h"		// Mis propias definiciones

// Open a client socket to the server
int client_socket_open(char *, int);

int main (int argc, char ** argv) {
	
	int result, size;
	FILE * src;
	char host[255], filename[255], ack[3];
	int socketfd, port;
	
	// Buffer para mandar y recibir datos
	char buffer[BUFFER_SIZE];

	// Copy host and port
	if(argc>1) {
		strcpy(host, argv[1]);
	}	
	port = (argc>2) ? atoi(argv[2]) : PORT;

	// Copy filename
	strcpy(filename,argv[3]);

	// Abre un socket
	socketfd = client_socket_open(host, port);

	// Write filename 
	write(socketfd, filename, 255);
	// Read acknowledge
	read(socketfd, ack, 3);
	
	if(!strcmp(ack, "OK")) {
		
		// Abre el archivo pedido
		src = fopen(filename, "w");
		if(src==NULL) {
			perror("Error al abrir el archivo de origen");
			exit(ERROR);
		}

		size = 0;
		// Lee archivo del socket y lo guarda localmente
		while((result=read(socketfd, buffer, BUFFER_SIZE))) {
			size += result;
			fwrite(buffer, 1, result, src);
		}

		printf("Recibimos %d bytes de %s desde el socket\n", size, filename);
		fclose(src);
	}
	else {
		printf("Archivo invalido %s\n", filename);
	}
	// Cierra los sockets al terminar
	close(socketfd);

	return SUCCESS;
}

/**
 * Open a client socket to a host:port 
 */
int client_socket_open(char * host, int port) {

	int result, socketfd;
    struct hostent *server;
	struct sockaddr_in server_addr;	

	// Abre un socket
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	
	// Obtiene los datos del servidor.
	server = gethostbyname(host);
	if(server == NULL) {
		perror("Error obteniendo hostname del servidor");
		exit(ERROR);
	}
	
	// Preparo los datos para conectarme al servidor
	bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&server_addr.sin_addr.s_addr,
         server->h_length);
    server_addr.sin_port = htons(port);
	
	// Intento conectarme al servidor
	result = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
	if(result<0) {
		perror("Error conectandose al servidor");
		exit(ERROR);
	}

	return socketfd;	
}

