/*************************************************************************
	> File Name: server1.cpp
	> Author: LHC 
	> Mail: 3115629644@qq.com 
	> Created Time: 2018年09月29日 星期六 15时34分38秒
 ************************************************************************/

#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>		
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/file.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdarg.h>
#include <stdio.h>

#include<iostream>
using namespace std;
#define max_size 1024
int socket_create(int port);

int main(int argc, char *argv[]) {
    int a = 0;
    int server_listen, socketfd, port, pid;
    if (argc != 2) {
        printf("Usage: ./tcp_server port\n");
        exit(0);
    }
    
    port = atoi(argv[1]);

    if ((server_listen = socket_create(port)) < 0) {
        printf("Error creating server_listen socket");
        exit(1);
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        if ((socketfd = accept(server_listen, (struct sockaddr*)&client_addr, &len)) < 0) 
            break;
        /*
        struct sockadddr_in peer;
        socklen_t peer_len = sizeof(struct sockaddr_in);
        bzero(&peer, sizeof(struct sockaddr_in));
        getpeername(socketfd, (struct sockaddr *)&peer, &peer_len);
        char buff_peer[64] = {'\0'};
        inet_ntop(AF_INET, (void *)&peer.sin_addr, buff_peer, 63);
        printf("%s已连接：\n", buff_peer);
        */

        if ((pid = fork()) < 0) 
            printf("Error forking child process");
        if (pid == 0) {
            close(server_listen);
            char buffer[max_size];
            while ((a = recv(socketfd, buffer, max_size, 0)) > 0) {
                //printf("%s:%d : recv %d 字节 %s\n", buff_peer, ntohs(peer.sin_addr), a, buffer);
                printf("%s\n", buffer);
                fflush(stdout); //清空缓冲区
                memset(buffer, 0, sizeof(buffer));
            }
            printf("\n");  //a = 0 对方关闭
            close(socketfd);
            printf("socketfd = %d", socketfd);
            exit(0);
        }

        //printf("par\n");
        close(socketfd);
        printf("socketfd = %d", socketfd);
    }
    return 0;
}

/*
 * 创建监听套接字
 * 返回套接字描述符，错误返回-1
 */

int socket_create(int port) {
    int sockfd;
    int yes = 1;
    struct sockaddr_in sock_addr;
    
    struct linger m_sLinger;
    m_sLinger.l_onoff = 1;
    m_sLinger.l_linger = 0;

    //创建套接字
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() error");
        return -1;
    }

    //设置本地套接字地址
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port); //转化为网络字节序
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY); //0.0.0.0

    //设置本地套接字
    setsockopt(sockfd, SOL_SOCKET, SO_LINGER, (const char*)&m_sLinger, sizeof(struct linger));

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        close(sockfd);
        perror("setsockopt() error\n");
        return -1;
    }
    //绑定本地套接字到套接字
    if (bind(sockfd, (struct sockaddr *) &sock_addr, sizeof(sock_addr)) < 0) {
        close(sockfd);
        perror("bind() error\n");
        return -1;
    }
    //将套接字设置为监听状态
    if (listen(sockfd, 20) < 0) {
        close(sockfd);
        perror("listen() error");
        return -1;
    }
    return sockfd;
}
