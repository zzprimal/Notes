#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char* argv[], char* envp[]){
    char buf[4];
    // network
    int sd;
    struct addrinfo hints;
    struct addrinfo *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;    /* Allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_STREAM; /* Datagram socket */
    hints.ai_protocol = 0;          /* Any protocol */
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    int rval = getaddrinfo("pwnable.kr", "11111", &hints, &result);
    if (rval != 0){
        fprintf(stderr, "Error: getaddr error\n");
        return -1;
    }

    sd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if(sd == -1){
        printf("socket error, tell admin\n");
        return -1;
    }
    if (connect(sd, result->ai_addr, result->ai_addrlen) < 0){
        perror("Error");
        printf("\nConnection Failed \n");
        return -1;
    }
    write(sd, "\xde\xad\xbe\xef", 4);
    printf("Done\n");
    
    return 0;
}