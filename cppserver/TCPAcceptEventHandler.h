#pragma once
#include"TCPAcceptEvent.h"
class TCPAcceptEventHandler
{
public:
	virtual void handle(TCPAcceptEvent* tcpAcceptEvent) = 0;
};

