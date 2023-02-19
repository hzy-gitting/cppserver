#pragma once
#include"Winsock2.h"
class TCPReadEvent
{
private:
	SOCKET clientSocket;
	int readLenth;
	char* bytes;
};

