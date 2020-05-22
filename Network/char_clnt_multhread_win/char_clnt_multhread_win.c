#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>

#define BUF_SIZE	100
#define NAME_SIZE	20

unsigned WINAPI SendMsg(void* arg);
unsigned WINAPI RecvMsg(void* arg);
void ErrorHandling(char* msg);

char name[NAME_SIZE] = "[DEFAULT]";
char msg[BUF_SIZE];

int main(int argc, char* argv[]) {
	WSADATA wsaData;
	SOCKET hScok;
	SOCKADDR_IN servAdr;
	HANDLE hSndThread, hRcvThread;
}