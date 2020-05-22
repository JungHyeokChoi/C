#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define OP_SIZE 4
#define RLT_SIZE 4

void error_handling(char *message);

int main(int argc, char *argv[]){
	int sock;
	struct sockaddr_in serv_adr;
	
	char opmsg[BUF_SIZE];
	int result, opnd_cnt, i;

	if(argc != 3){
		printf("Usage : %s <IP> <port>\n",argv[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		error_handling("socket() error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_adr.sin_port = htons(atoi(argv[2]));

	if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("connect() error");
	else
		printf("Connected.............\n");

	fputs("Operand Count : ",stdout);
	scanf("%d",&opnd_cnt);
	
	opmsg[0] = (char)opnd_cnt;

	for(i = 0; i < opnd_cnt; i++){
		printf("Operand %d : ", i+1);
		scanf("%d",(int*)&opmsg[i*OP_SIZE+1]);
	}

	fgetc(stdin);
	fputs("Operator : ",stdout);
	scanf("%c", &opmsg[opnd_cnt * OP_SIZE + 1]);
	write(sock, opmsg, opnd_cnt * OP_SIZE + 2);
	read(sock, &result, RLT_SIZE);

	printf("Operation result : %d\n",result);
	close(sock);
	
	return 0;
}

void error_handling(char *message){
	fputs(message, stdout);
	fputc('\n', stdout);
	exit(1);
}

