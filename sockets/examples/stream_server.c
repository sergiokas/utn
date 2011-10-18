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
    int as, ms;
	unsigned int len;
    struct sockaddr_in server;
    char buf[1024];

    as = socket(AF_INET, SOCK_STREAM, 0 );
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = 0;
    bind(as, (struct sockaddr *) &server, sizeof(server));
    len = sizeof(len);
    getsockname(as, (struct sockaddr *)&server, &len);
    printf("port = %d\n", ntohs(server.sin_port));
    listen(as, 5);
    while( 1 ) {
        ms = accept( as, 0, 0 );
        bzero( buf, sizeof(buf));
        read(ms, buf, sizeof(buf));
        close( ms );
        printf("message is = %s\n", buf );
        if ( strcmp(buf, "quit") == 0 ) break;
    }
    close( as );
	return 0;
}
