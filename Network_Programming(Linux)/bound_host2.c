#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30

void error_handling(char *message);

int main(int argc, char *argv[]){
	int sock;
	struct sockaddr_in your_adr;
	socklen_t your_adr_sz;

	char msg1[] = "Hi!";
	char msg2[] = "I'm another UDP Host!";
	char msg3[] = "Nice to meet you";

	if(argc != 3){
		printf("Usage : %s <IP> <port>\n",argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_DGRAM, 0);
	if(sock == -1)
		error_handling("socket() error");
	
	memset(&your_adr, 0, sizeof(your_adr));
	your_adr.sin_family = AF_INET;
	your_adr.sin_addr.s_addr = inet_addr(argv[1]);
	your_adr.sin_port = htons(atoi(argv[2]));

	sendto(sock, msg1, sizeof(your_adr), 0, (struct sockaddr*)&your_adr, sizeof(your_adr));
	sendto(sock, msg2, sizeof(your_adr), 0, (struct sockaddr*)&your_adr, sizeof(your_adr));
	sendto(sock, msg3, sizeof(your_adr), 0, (struct sockaddr*)&your_adr, sizeof(your_adr));

	close(sock);
	
	return 0;
}

void error_handling(char *message){
	fputs(message, stderr);
	fputc('\n',stderr);
	exit(1);
}
