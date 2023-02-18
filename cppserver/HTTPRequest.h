#pragma once
#include<string>
#include<map>
class HTTPRequest
{
private:
	std::string url;
public:
	std::string getMethod();
	std::string getUrl();
	std::map<std::string, std::string> getHeaders();
	std::map<std::string, std::string> getParameters();
	char* getBody();
};

