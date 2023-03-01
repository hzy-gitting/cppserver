#include "SingleThreadBlockTCPServer.h"
#include<iostream>
#pragma comment (lib, "Ws2_32.lib")
#include<ws2tcpip.h>
#include"Exception.h"

int SingleThreadBlockTCPServer::start(char* ip, int port)
{
	initializeWinsock();
	struct addrinfo* result = getAddrInfo();
	SOCKET listenSocket = createListenSocket(result);
	bind(listenSocket, result->ai_addr, result->ai_addrlen);
	return 0;
}

SOCKET SingleThreadBlockTCPServer::createListenSocket(addrinfo* result)
{
	SOCKET listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (listenSocket == INVALID_SOCKET) {
		throw Exception("create listenSocket failed");
	}
	return listenSocket;
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
		throw Exception(iResult,"WSAStartup failed");
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
