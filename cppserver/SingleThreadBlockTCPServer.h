#pragma once
#include "TCPServer.h"
class SingleThreadBlockTCPServer :
    public TCPServer
{
	// Í¨¹ý TCPServer ¼Ì³Ð
	virtual int start(char* ip, int port) override;
	SOCKET createListenSocket(addrinfo* result);
	virtual void send(char* buf, int length) override;
	int initializeWinsock();
	addrinfo* getAddrInfo();
};

