#pragma once
#include"TCPReadEvent.h"
class TCPReadEventHandler
{
public:
	virtual void handle(TCPReadEvent* tcpReadEvent) = 0;
};

