#pragma once
#include "TCPServer.h"
class SingleThreadBlockTCPServer :
    public TCPServer
{
	// ͨ�� TCPServer �̳�
	virtual int start(char* ip, int port) override;
	virtual void send(char* buf, int length) override;
	int initializeWinsock();
	addrinfo* getAddrInfo();
};

