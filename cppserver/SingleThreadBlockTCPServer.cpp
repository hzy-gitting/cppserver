#include "SingleThreadBlockTCPServer.h"
#include<iostream>
#pragma comment (lib, "Ws2_32.lib")
#include<ws2tcpip.h>
int SingleThreadBlockTCPServer::start(char* ip, int port)
{
	initializeWinsock();
	struct addrinfo* result = getAddrInfo();

	return 0;
}

void SingleThreadBlockTCPServer::send(char* buf, int length)
{
	onSend(length);
}


int SingleThreadBlockTCPServer::initializeWinsock()
{
	WSADATA wsaData;
	int iResult;
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		std::cout << "WSAStartup failed with error = " + iResult;
		return -1;
	}
	return 0;
}


addrinfo* SingleThreadBlockTCPServer::getAddrInfo()
{
	struct addrinfo hints;
	struct addrinfo* result;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;
	getaddrinfo(NULL, "http", &hints, &result);
	return result;
}
