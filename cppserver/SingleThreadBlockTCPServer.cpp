#include "SingleThreadBlockTCPServer.h"
#include<iostream>
#pragma comment (lib, "Ws2_32.lib")
#include<ws2tcpip.h>
#include"Exception.h"
#include<sstream>

int SingleThreadBlockTCPServer::start(char* ip, int port)
{
	initializeWinsock();
	struct addrinfo* result = getAddrInfo();
	SOCKET listenSocket = createListenSocket(result);
	bind(listenSocket, result);
	listen(listenSocket);
	while (1) {
		SOCKET clientSocket = accept(listenSocket);
		recv(clientSocket);
		const char* sendBuf = "HTTP/7.9 79.40 OhgchgK\r\nServer:cppserver\r\ncontent-Length:  13  \r\ncogth: 13  tr\r\n\r\nhello client!";
		int res = ::send(clientSocket, sendBuf, strlen(sendBuf), 0);
		if (res == SOCKET_ERROR) {
			int errcode = WSAGetLastError();
			std::stringstream fmt;
			fmt << "send failed with err code=" << errcode;
			throw Exception(fmt.str().c_str());
		}
		std::cout << "send " << res << " byte(s)" << std::endl;
	}
	return 0;
}

void SingleThreadBlockTCPServer::recv(const SOCKET& clientSocket)
{
	char buf[1024 * 4];
	int bufLen = 1024 * 4;
	int res = ::recv(clientSocket, buf, bufLen, 0);
	if (res > 0) {
		std::cout << "recv " << res << " byte(s)" << " from client:" << std::endl;;
		std::cout << buf;
	}
	else if (res == 0) {
		std::cout << "connection closed." << std::endl;
	}
	else {
		int errcode = WSAGetLastError();
		std::stringstream fmt;
		fmt << "recv failed with err code=" << errcode;
		throw Exception(fmt.str().c_str());
	}
}

SOCKET SingleThreadBlockTCPServer::accept(const SOCKET& listenSocket)
{
	sockaddr addr;
	int addrLen = sizeof(addr);
	SOCKET clientSocket = ::accept(listenSocket, &addr, &addrLen);
	if (clientSocket == INVALID_SOCKET) {
		int errcode = WSAGetLastError();
		closesocket(listenSocket);
		WSACleanup();
		std::stringstream fmt;
		fmt << "accept failed with err code=" << errcode;
		throw Exception(fmt.str().c_str());
	}
	onAccept();
	return clientSocket;
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

void SingleThreadBlockTCPServer::bind(SOCKET listenSocket, addrinfo* result) {
	int res = ::bind(listenSocket, result->ai_addr, result->ai_addrlen);
	if (res == SOCKET_ERROR) {
		closesocket(listenSocket);
		WSACleanup();
		throw Exception("bind failed with error:" + WSAGetLastError());
		
	}
}

void SingleThreadBlockTCPServer::listen(SOCKET listenSocket) {
	int res = ::listen(listenSocket, SOMAXCONN);
	if (res == SOCKET_ERROR) {
		closesocket(listenSocket);
		WSACleanup();
		throw Exception("listen failed with error:" + WSAGetLastError());
	}
}