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

void TCPServer::onRead()
{

}

void TCPServer::onSend()
{
}

void TCPServer::onAccept()
{
}
