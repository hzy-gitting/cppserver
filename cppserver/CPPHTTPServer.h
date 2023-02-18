#pragma once
#include"HTTPRequestHandler.h"
class CPPHTTPServer
{
public:
	virtual void get() = 0;
	virtual void addHTTPRequestHandler(HTTPRequestHandler* handler);
	virtual void start();
};

