#include "SingleThreadBlockTCPServer.h"

int SingleThreadBlockTCPServer::start(char* ip, int port)
{
	return 0;
}

void SingleThreadBlockTCPServer::send(char* buf, int length)
{
	onSend(length);
}
