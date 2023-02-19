#pragma once
#include"TCPSendEvent.h"
class TCPSendEventHandler
{
public:
	virtual void handle(TCPSendEvent* tcpSendEvent) = 0;
};

