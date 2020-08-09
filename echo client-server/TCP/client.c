#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_ADRESS "192.168.0.103"
#define SERVER_PORT 3425

char message[] = "Hello!\n";
char buf[sizeof(message)];

int main()
{
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Socket client error");
        exit(1);
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_ADRESS);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("Connect client error");
        exit(2);
    }
    send(sock, message, sizeof(message), 0);
    recv(sock, buf, sizeof(message), 0);
    printf(buf);
    close(sock);
    return 0;

}