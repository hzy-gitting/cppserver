#include "TCPServer.h"

void TCPServer::registerReadEventHandler(TCPReadEventHandler* tcpReadEventHandler)
{
	tcpReadEventHandlers.push_back(tcpReadEventHandler);
}

void TCPServer::registerSendEventHandler(TCPSendEventHandler* tcpSendEventHandler)
{
	tcpSendEventHandlers.push_back(tcpSendEventHandler);
}

void TCPServer::registerAcceptEventHandler(TCPAcceptEventHandler* tcpAcceptEventHandler)
{
	tcpAcceptEventHandlers.push_back(tcpAcceptEventHandler);
}

void TCPServer::onRead(char* buf, int length)
{
	TCPReadEvent *tcpReadEvent = new TCPReadEvent();
	for (int i = 0; i < tcpReadEventHandlers.size(); i++) {
		tcpReadEventHandlers[i]->handle(tcpReadEvent);
	}
	delete tcpReadEvent;
}

void TCPServer::onSend(int length)
{
	TCPSendEvent* tcpSendEvent = new TCPSendEvent();
	for (std::vector<TCPSendEventHandler*>::iterator iterator = tcpSendEventHandlers.begin(); iterator != tcpSendEventHandlers.end(); iterator++) {
		(*iterator)->handle(tcpSendEvent);
	}
	delete tcpSendEvent;
}

void TCPServer::onAccept()
{
	TCPAcceptEvent* tcpAcceptEvent = new TCPAcceptEvent();
	for (std::vector<TCPAcceptEventHandler*>::iterator it = tcpAcceptEventHandlers.begin(); it != tcpAcceptEventHandlers.end(); it++) {
		(*it)->handle(tcpAcceptEvent);
	}
	delete tcpAcceptEvent;
}
