#pragma once
#include "TCPServer.h"
class SingleThreadBlockTCPServer :
    public TCPServer
{
	// Í¨¹ý TCPServer ¼Ì³Ð
	virtual int start(char* ip, int port) override;
	virtual void send(char* buf, int length) override;
private:
	int initializeWinsock();
	addrinfo* getAddrInfo();
	SOCKET createListenSocket(addrinfo* result);
	void bind(SOCKET listenSocket, addrinfo* result);
	void listen(SOCKET listenSocket);
	SOCKET accept(const SOCKET& listenSocket);
	void recv(const SOCKET& clientSocket);
};

