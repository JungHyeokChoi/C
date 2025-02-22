#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define BUF_SIZE 1024

void ErrorHandling(char *message);

int main(int argc, char *argv[]) {
	WSADATA wsaData;

	SOCKET hSocket;
	char message[BUF_SIZE];
	int strLen, recvLen, recvCnt;
	SOCKADDR_IN servAdr;

	if (argc != 3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == -1)
		ErrorHandling("socket() error");

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = inet_addr(argv[1]);
	servAdr.sin_port = htons(atoi(argv[2]));

	if (connect(hSocket, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("connect() error");
	else
		printf("Connected................\n\n");

	while (1) {
		fputs("Input message(Q to quit):",stdout);
		fgets(message, BUF_SIZE, stdin);

		if(!strcmp(message, "Q\n") || !strcmp(message, "q\n"))
			break;

		strLen = write(hSocket, message, BUF_SIZE - 1, 0);

		recvLen = 0;
		while (recvLen < strLen) {
			recvCnt = read(hSocket, message, BUF_SIZE - 1);
			if (recvCnt == -1)
				ErrorHandling("read() error");

			recvLen += recvCnt;
		}

		message[strLen] = 0;
		printf("Message from server : %s", message);
	}
	closesocket(hSocket);
	WSACleanup();

	return 0;
}

void ErrorHandling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}