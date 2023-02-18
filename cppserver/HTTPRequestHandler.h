#pragma once
#include"HTTPRequest.h"
#include"HTTPResponse.h"
class HTTPRequestHandler
{
public:
	virtual void handle(HTTPRequest *request, HTTPResponse *response) = 0;
};

