#pragma once
class HTTPResponse
{
private:
	char* body;
	int bodyLength;
public:
	void setHeaders();
	void setBody(const char *body,int length);
};

