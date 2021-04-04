#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
int main(){
	struct sockaddr_in server_add;
	server_add.sin_family=AF_INET;
	server_add.sin_port=htons(9002);
	server_add.sin_addr.s_addr=INADDR_ANY;

	int server_skt=socket(AF_INET,SOCK_STREAM,0);
	if(server_skt==0){
		printf("socket create error\n");
		return 0;
	}
	int conn=connect(server_skt,(struct sockaddr*)&server_add,sizeof(server_add));
	if(conn<0){
		printf("error conn\n");
		return 0;
	}
	char buf[1024]={0};
	char *hi="ji";
	if(send(server_skt,hi,strlen(hi),0)<0){printf("error client send\n");};
	int r=recv(server_skt,buf,1024,0);
	printf("%s\n",buf );
	close(server_skt);
	return 0;
}