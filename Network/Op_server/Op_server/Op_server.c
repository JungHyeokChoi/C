#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>

#define BUF_SIZE 1024
#define OP_SIZE 4

int calculate(int opnum, int opnds[], char oprator);
void ErrorHandling(char *message);

int main(int argc, char *argv[]) {
	WSADATA wasData;
	SOCKET hServSock, hClntSock;
	SOCKADDR_IN servAdr, clntAdr;
	int clntAdrSz;

	int result, opndCnt;
	int recvCnt, recvLen;
	char opinfo[BUF_SIZE];

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wasData) != 0) {
		ErrorHandling("WSAStartup() error");
	}

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET) {
		ErrorHandling("socket() error");
	}

	memset(&servAdr, 0, sizeof(servAdr));
	servAdr.sin_family = AF_INET;
	servAdr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAdr.sin_port = htons(atoi(argv[1]));

	if (bind(hServSock, (SOCKADDR*)&servAdr, sizeof(servAdr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");

	if (listen(hServSock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	clntAdrSz = sizeof(clntAdr);

	opndCnt = 0;

	hClntSock = accept(hServSock, (SOCKADDR*)&clntAdr, &clntAdrSz);


	recv(hClntSock, &opndCnt, 1, 0);

	recvLen = 0;
	while ((opndCnt * OP_SIZE + 1) > recvLen) {
		recvCnt = recv(hClntSock, &opinfo[recvLen], BUF_SIZE - 1, 0);
		recvLen += recvCnt;
	}

	result = calculate(opndCnt, (int*)opinfo, opinfo[recvLen - 1]);
	send(hClntSock, (char*)&result, sizeof(result), 0);

	closesocket(hClntSock);
	closesocket(hServSock);

	WSACleanup();

	return 0;
}

int calculate(int opnum, int opnds[], char op){
	int result = opnds[0], i;

	switch (op) {
	case '+' : 
		for (i = 1; i < opnum; i++)
			result += opnds[i];
		break;
	case '-':
		for (i = 1; i < opnum; i++)
			result -= opnds[i];
		break;
	case '*':
		for (i = 1; i < opnum; i++)
			result *= opnds[i];
		break;
	}

	return result;
}

void ErrorHandling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

