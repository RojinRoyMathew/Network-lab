#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>

void main(){
int client;
char buffer[1024];
struct sockaddr_in servAddr;
socklen_t addrsize;


client=socket(PF_INET,SOCK_STREAM,0);

servAddr.sin_family = AF_INET;
servAddr.sin_port = htons(6265);
servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

memset(servAddr.sin_zero, '\0', sizeof servAddr.sin_zero);

connect(client,(struct sockaddr*) &servAddr,sizeof(servAddr));
printf("sending data to server\n");
strcpy(buffer,"hello who is it ");
send(client,buffer,sizeof(buffer),0);

recv(client,buffer,1024,0);
printf("data recived from server %s\n",buffer);

close(client);
}
