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
	
	char host[255];
	int socketfd, port, size, i;
	
	// Buffer para mandar y recibir datos
	char buffer[BUFFER_SIZE];

	// Copy host and port
	if(argc>1) {
		strcpy(host, argv[1]);
	}	
	port = (argc>2) ? atoi(argv[2]) : PORT;

	// Lee datos del socket
	socketfd = client_socket_open(host, port);
	if(socketfd)
	{
		bzero(buffer, 255);
		size = read(socketfd, buffer, 255);
		while(size>0) {
			for(i=0; i<size; i++) {
				buffer[i] = buffer[i] ^ (char)120;
			}
			fwrite(buffer,1,size,stdout);
			size = read(socketfd, buffer, 255);
		}
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

