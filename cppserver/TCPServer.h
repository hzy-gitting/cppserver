#pragma once
#include"TCPAcceptEventHandler.h"
#include"TCPReadEventHandler.h"
#include"TCPSendEventHandler.h"
#include<vector>
class TCPServer
{
public:
	virtual int start(char *ip,int port) = 0;
	virtual void send(char *buf, int length) = 0;
	void registerReadEventHandler(TCPReadEventHandler *);
	void registerSendEventHandler(TCPSendEventHandler *);
	void registerAcceptEventHandler(TCPAcceptEventHandler *);
protected:
	void onRead(char* buf, int length);
	void onSend(int length);
	void onAccept();

private:
	std::vector<TCPAcceptEventHandler*> tcpAcceptEventHandlers;
	std::vector<TCPReadEventHandler*> tcpReadEventHandlers;
	std::vector<TCPSendEventHandler*> tcpSendEventHandlers;
};

