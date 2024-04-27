#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>

void main(){
int shock,server;
char buffer[1024];

struct sockaddr_in servAddr;
struct sockaddr_storage store;

socklen_t addrsize;

server=socket(PF_INET, SOCK_STREAM, 0);

servAddr.sin_family = AF_INET;
servAddr.sin_port = htons(6265);
servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

memset(servAddr.sin_zero, '\0', sizeof servAddr.sin_zero);


if(bind(server,(struct sockaddr*) &servAddr,sizeof(servAddr))<0){
printf("error");
}

if(listen(server,5)==0){
printf("Listening\n");
}else{
printf("Error\n");
}

shock=accept(server,(struct sockaddr*) &store, &addrsize);

recv(shock,buffer,1024,0);
printf("data recived from client %s\n",buffer);

strcpy(buffer,"data send by server-hai\n");
printf("data sent by server/n");
send(shock,buffer,sizeof(buffer),0);

close(shock);


 
}
