#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

void ErrorHandling(char *message);

int main(int argc, char *argv[]) {
	WSADATA wasData;
	if (WSAStartup(MAKEWORD(2, 2), &wasData) != 0)
		ErrorHandling("WSAStarup() Error!");
	
	//inet_addr 함수
	/*
	char *addr = "127.212.124.78";
	unsigned long conv_addr = inet_addr(addr);
	if (conv_addr == INADDR_NONE)
		ErrorHandling("Error occured! \n");
	else
		printf("Network ordered integer addr : %#lx \n", conv_addr);
	*/

	//inet_ntoa 함수
	struct sockaddr_in addr;
	char *strPtr;
	char strArr[20];

	addr.sin_addr.s_addr = htonl(0x1020304);
	strPtr = inet_ntoa(addr.sin_addr);
	strcpy(strArr, strPtr);

	printf("Dotted-Decimal notation : %s \n", strArr);

	WSACleanup();

	return 0;
}

void ErrorHandling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}