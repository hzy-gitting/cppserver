#pragma once
#include "TCPServer.h"
class WinsockTCPServer :
    public TCPServer
{
	virtual int listen(char* ip, int port) override;
	virtual void send() override;
	virtual void read() override;
};

