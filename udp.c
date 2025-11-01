#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define IP "PUT THE RECEIVER IP ADDRESS"
#define port 12345

int main(){
  printf("UDP message sender\n");
  int s=socket(AF_INET, SOCK_DGRAM, 0);
  if(s<0){
    printf("socket() error\n");
    return -1;
  }

  struct sockaddr_in sock;
  sock.sin_port=htons(port);
  sock.sin_family=AF_INET;
  sock.sin_addr.s_addr=inet_addr(IP);
  
  const char * message="My UDP message sender";

  sendto(s,message, strlen(message), 0, (const struct sockaddr *)&sock,sizeof(sock));
  close(s);
  return 0;
}