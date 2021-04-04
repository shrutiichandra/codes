#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<thread>
#include<iostream>
#include<string.h>
#include<unistd.h>
using namespace std;
// typedef struct {
// 	char 
// }
void* thread_function(void *socket_desc)
{
	 int client_socket = *(int*)socket_desc;
	char server_message[256]="Server sends best wishes";
	cout<<"FFF";
	char client_msg[256];

		while(1){
		int r=recv(client_socket,&client_msg,sizeof(client_msg),0);
		if(r<0){printf("Recieve on server error\n");}

		printf("%s",client_msg );
		printf("checl\n");
		if(strcmp(client_msg,"exit")==0){
		printf("Connection terminated with client");
		close(client_socket);
		exit(1);
		}
		send(client_socket,server_message,sizeof(server_message),0);
		bzero(client_msg,sizeof(server_message));
	}

}

int main(){
	char server_message[256]="Server sends best wishes";

	//create servere socket
	int server_socket=socket(AF_INET,SOCK_STREAM,0);

	//define the server address
	struct sockaddr_in server_address;

	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(9002);
	server_address.sin_addr.s_addr=INADDR_ANY;//any ip on local machine

	//bind the socket to our specified IP and port
	int b=bind(server_socket,(struct sockaddr *)&server_address,sizeof(server_address));
	if(b<0){printf("error on server bind\n");exit(1);}
	//listen to client:2nd parameter is backlog that is how many connections can be waiting at one time

	listen(server_socket,10);
	printf("listening.......\n");
	//accept connections:returns the client socket
	int client_socket;
	//1st param:socket on wchich we are accepting connection
	//2nd and 3rd parametr:to get client connection information:where the connection is coming from
	// client_socket=accept(server_socket,NULL,NULL);
	//1st param:who to send to
	//2nd param:data to be sent
	// send(client_socket,server_message,sizeof(server_message),0);
	// close(server_socket);

	struct sockaddr_in client_address;
	socklen_t addr_size=sizeof(client_address);
	while(client_socket=accept(server_socket,(struct sockaddr *)&client_address,&addr_size)){
	
	if(client_socket<0){printf("error in accepting client\n");break;}
	// if(client_address==NULL){close(server_socket);close(client_socket);exit(1);}
	// else{
	// 	printf("%s\n",client_address );
	// }
	printf("Connection accepted from client %s : %d\n",inet_ntoa(client_address.sin_addr),ntohs(client_address.sin_port));
		pthread_t thread_id;
	 if( pthread_create( &thread_id , NULL ,  thread_function , (void*)&client_socket) < 0)
        {
            perror("could not create thread");
            return 1;
		}
  if (client_socket < 0)
  	  {
        perror("accept failed");
        return 1;
}
	// std::thread t(&thread_function, client_socket);
	// std::cout << "child thread id = " << t.get_id() << std::endl;
	// t.join();
	// if(fork()==0){
		
	// }
	// close(client_socket);
	}


return 0;
}