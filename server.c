#include<stdio.h>
#include<sys/socket.h>
#include <stdlib.h>
#include<sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
int main(){
    
    int server_desc;
    struct sockaddr_in server_add;
    
    server_add.sin_family=AF_INET;
    server_add.sin_addr.s_addr=INADDR_ANY; 
    server_add.sin_port=htons(9002);
    
    server_desc=socket(AF_INET,SOCK_STREAM,0);
    if(server_desc==0){
        printf("fail socket\n");
        return 0;
    }
    
    int isbind=bind(server_desc,(struct sockaddr*)&server_add,sizeof(server_add));
    if(isbind<0){
        printf("error bind\n");
        return 0;
    }
    int islisten=listen(server_desc,10);
    if(islisten<0){
        printf("error listen\n");
        return 0;
    }
    printf("listening\n" );
    struct sockaddr_in client_add;
    socklen_t addlen=sizeof(client_add);
    int client_skt;
    while(client_skt=accept(server_desc,(struct sockaddr*)&client_add,&addlen)){
    if(client_skt<0){
        printf("error client accept");
        return 0;
    }
    char buf[1024]={0};
    int char_read=recv(client_skt,buf,1024,0);
    printf("%s\n",buf);
    char * hi="hello!";
    send(client_skt,hi,strlen(hi),0);
    printf("messgae sent\n");
    }
    
    close(client_skt);
    close(server_desc);
    
    return 0;
}