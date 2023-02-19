#pragma once
#include"TCPAcceptEventHandler.h"
#include"TCPReadEventHandler.h"
#include"TCPSendEventHandler.h"
#include<vector>
class TCPServer
{
public:
	virtual int listen(char *ip,int port) = 0;
	virtual void send() = 0;
	virtual void read() = 0;
	
	void registerReadEventHandler(TCPReadEventHandler *);
	void registerSendEventHandler(TCPSendEventHandler *);
	void registerAcceptEventHandler(TCPAcceptEventHandler *);
private:
	void onRead();
	void onSend();
	void onAccept();

private:
	std::vector<TCPAcceptEventHandler*> tcpAcceptEventHandlers;
	std::vector<TCPReadEventHandler*> tcpReadEventHandlers;
	std::vector<TCPSendEventHandler*> tcpSendEventHandlers;
};

