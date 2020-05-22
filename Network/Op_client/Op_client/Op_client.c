#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>

#define BUF_SIZE 1024
#define OP_SIZE 4
#define RLT_SIZE 4

void ErrorHandling(char *message);

int main(int argc, char *argv[]) {
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAdr;

	char opmsg[BUF_SIZE];
	int result, opnd_cnt, i;

	if (argc != 3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_addr(argv[1]);
	servAdr.sin_port = htons(atoi(argv[2]));

	if (connect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("connect() error");
	else
		printf("Connected................\n");

	fputs("Operand Count : ", stdout);
	scanf("%d", &opnd_cnt);

	opmsg[0] = (char)opnd_cnt;

	for (i = 0; i < opnd_cnt; i++) {
		printf("Opeand %d : ", i + 1);
		scanf("%d", (int*)&opmsg[i * OP_SIZE + 1]);
	}

	fgetc(stdin);
	fputs("Operator : ", stdout);
	scanf("%c", &opmsg[opnd_cnt * OP_SIZE + 1]);

	send(hSocket, opmsg, opnd_cnt * OP_SIZE + 2, 0);

	recv(hSocket, &result, RLT_SIZE, 0);

	printf("Operation result : %d\n", result);

	closesocket(hSocket);

	WSACleanup();

	return 0;
}

void ErrorHandling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
