#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

#define BUF_SIZE	30

void ErrorHandling(char *message);

int main(int argc, char *argv[]) {
	WSADATA wsaData;
	SOCKET hSendSock;
	SOCKADDR_IN broad_adr;
	FILE *fp;
	char buf[BUF_SIZE];
	int so_brd = 1;

	if (argc != 3) {
		printf("Usage : %s <Broadcast IP><PORT>\n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error");

	hSendSock = socket(PF_INET, SOCK_DGRAM, 0);
	if (hSendSock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&broad_adr, 0, sizeof(broad_adr));
	broad_adr.sin_family = AF_INET;
	broad_adr.sin_addr.s_addr = inet_addr(argv[1]);
	broad_adr.sin_port = htons(atoi(argv[2]));

	if (setsockopt(hSendSock, SOL_SOCKET, SO_BROADCAST, (void*)&so_brd, sizeof(so_brd)) == SOCKET_ERROR)
		ErrorHandling("setsockopt() error");

	if ((fp = fopen("news.txt", "r")) == NULL)
		ErrorHandling("fopen() error");

	while (!feof(fp)) {
		fgets(buf, BUF_SIZE, fp);
		sendto(hSendSock, buf, strlen(buf), 0, (SOCKADDR*)&broad_adr, sizeof(broad_adr));
		Sleep(2000);
	}

	closesocket(hSendSock);
	WSACleanup();

	return 0;
}

void ErrorHandling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}