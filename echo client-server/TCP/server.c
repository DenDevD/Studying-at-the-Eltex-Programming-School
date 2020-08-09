#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_ADRESS "192.168.0.103"
#define SERVER_PORT 3425

int main()
{
    int sock, listener;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;
    FILE *fp;

    listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener < 0)
    {
        perror("Socket server error");
        exit(1);
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_ADRESS);
    if (bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("Bind server error");
        exit(2);
    }
    listen(listener, 1);
    while (1)
    {
        sock = accept(listener, NULL, NULL);
        if (sock < 0)
        {
            perror("Accept server error");
            exit(3);
        }
        while (1)
        {
            bytes_read = recv(sock, buf, 1024, 0);
            if (bytes_read <= 0)
            {
                break;
            }
            fp = fopen("server.log", "a");
            fprintf(fp, "%s", buf);
            fclose(fp);
            send(sock, buf, bytes_read, 0);
        }
        close(sock);
    }
    return 0;
}