#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "json.h"
#include <iostream>
#define MAXLINE 4096
using namespace::std;
int main(int argc, char**argv)
{
    int sockfd,n;
    char recvline[4096],sendline[4096];
    struct sockaddr_in servaddr;
    Json::Value root;
    Json::FastWriter fast_writer;
    root["REGION_ID"]="600901";
    root["REGION_ID2"]="6001";

    string A=root.toStyledString().c_str();


//printf("%c\n",A);

   while(strcmp(sendline,"exit")!=0)
    {
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5000);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");


    //?«Øsocket
    if( (sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
        printf(" create socket error: %s (errno :%d)\n",strerror(errno),errno);
        return 0;
    }


        //?±µ
        if( connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr)) <0)
        {
            printf(" connect socket error: %s(errno :%d)\n",strerror(errno),errno);
            return 0;
        }


//char *p=A.c_str();


        memset(sendline,0,sizeof(sendline));
        printf("if you want to leave, please enter exit\n");



        printf("send msg to server:\n");
        fgets(sendline,4096,stdin);
        //send?°e
        if ( send(sockfd,A.c_str(),A.size(),0) <0)
        {
            printf("send msg error: %s(errno :%d)\n",strerror(errno),errno);
            return 0;
        }



    close(sockfd);
    }return 0;
}
