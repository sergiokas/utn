#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* usage: dw host port message */

int main(int ac, char *av[]) {
    int s;                    /* the socket handel */
    struct sockaddr_in  dest; /* destination address */
    struct hostent *hp;       /* host entity information */
    int nb;                   /* number of bytes sent */

    if ( ac != 4 ) {
        printf("usage: dw host port message\n"); return -1;
    }
    /* create a datagram socket for the INET */
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if( s < 0 ) {
        perror("socket failed\n"); return -1;
    }
    dest.sin_family = AF_INET; dest.sin_port = htons(atoi(av[2]));
    /* find the host's IP number */
    hp = gethostbyname(av[1]);
    if ( !hp ) {
        printf("gethost failed \n"); return -1;
    }
    memcpy(&dest.sin_addr, hp->h_addr, hp->h_length);
    nb = sendto(s, av[3], strlen(av[3])+1, 0,
        (struct sockaddr*)&dest, sizeof(dest));
    close(s);

	return 0;
}
