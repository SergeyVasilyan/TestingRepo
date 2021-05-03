#include"matrix.h"
#include<iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 6996

int main()
{
    Matrix mat;
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    if ((sock = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) 
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_UNIX;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    std::cin >> mat;
    send(sock , mat, strlen(mat), 0);
    if(recv( sock , buffer, 1024) > 0) {
	printf("%s\n",buffer );
    } else {
	printf("\nServer don't work. \n");
	close(sock)
    }
    return 0;
}
