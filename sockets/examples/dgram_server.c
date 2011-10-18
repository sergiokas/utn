#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int ac, char *av[]) {
    int res,s;             /* result code, sockeT */
    struct sockaddr_in my_addr, src;/* INET SAPs */
    unsigned int src_len;            /* src lenght in bytes */
    struct hostent *hp;     /* host entity information */
    char hostname[128];     /* buffer for host name */
    char buf[512];          /* input buffer */
    int nb;                 /* bytes recieved */

    /* create the datagram socket for the INET domain */
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if( s < 0 ) {
        printf("socket failed\n");
        return -1;
    }
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = 0; /* the system will pick a port */

    /* find out the local host name */
    gethostname(hostname,sizeof(hostname));
    /* look in "/etc/hosts" or ask the name server */
    hp = gethostbyname(hostname);
    if ( !hp ) {
        printf("gethostbyname failed \n");
        return -1;
    }

    /* copy the IP number */
    memcpy(&my_addr.sin_addr.s_addr, hp->h_addr, hp->h_length);
    res = bind(s, (struct sockaddr *)&my_addr, sizeof(my_addr) );
    if ( res < 0 ) {
        perror("dr - bind failed");
        return -1;
    }
    /* find the assigned port */
    src_len = sizeof(src);
    res = getsockname(s, (struct sockaddr *)&src, &src_len);
    if ( res < 0 ) {
        perror("getsockname");
        return -1;
    }
    /* be sure to convert between the network and the host */
    printf("port number = %d\n", ntohs(src.sin_port));


    /* display message until a "quit" is received */
    do {
        src_len = sizeof(src);
        nb=recvfrom(s, buf, sizeof(buf), 0,
            (struct sockaddr*)&src, &src_len);
        /* find the name of the src */
        hp = gethostbyaddr( (char *)&src.sin_addr,
            sizeof(src.sin_addr),AF_INET);
        if ( !hp ) {
            printf("gethostbyaddr failed \n"); return -1;
        }
        buf[nb] = '\0';
        printf("data: (%s) ", buf);
        /* print both the name and the IP number and port of the src*/
        printf("from: %s(%s) port: %d\n",
            hp->h_name,inet_ntoa(src.sin_addr), ntohs(src.sin_port));
    } while ( strcmp(buf,"quit") );
    close(s);

	return 0;
}
