#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

#define	BUF_SIZE	30

void ErrorHandling(char *message);

int main(int argc, char *argv[]){
	WSADATA wsaData;
	int hRecvSock;
	SOCKADDR_IN adr;
	int strLen;
	char buf[BUF_SIZE];

	if (argc != 2) {
		printf("Usage : %s <PORT>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error");

	hRecvSock = socket(PF_INET, SOCK_DGRAM, 0);
	if (hRecvSock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&adr, 0, sizeof(adr));
	adr.sin_family = AF_INET;
	adr.sin_addr.s_addr = htonl(INADDR_ANY);
	adr.sin_port = htons(atoi(argv[1]));

	if (bind(hRecvSock, (SOCKADDR*)&adr, sizeof(adr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");

	while (1) {
		strLen = recvfrom(hRecvSock, buf, BUF_SIZE - 1, 0, NULL, 0);
		if (strLen < 0)
			break;
		buf[strLen] = 0;
		fputs(buf, stdout);
	}

	closesocket(hRecvSock);
	WSACleanup();

	return 0;
}

void ErrorHandling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}