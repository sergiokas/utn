#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>

int main(int ac, char *av[])
{
    int s;
    struct sockaddr_in server;
    struct hostent *hp;

    s = socket(AF_INET, SOCK_STREAM, 0 );
    server.sin_family = AF_INET;
    hp = gethostbyname(av[1]);
    bcopy( hp->h_addr, &server.sin_addr, hp->h_length);
    server.sin_port = htons(atoi(av[2]));

    connect(s, (struct sockaddr *) &server, sizeof(server));
    write(s, av[3], strlen(av[3]) );
    close( s );

	return 0;
}
