#define _CRT_SECURE_NO_WARNINGS
#include "Exception.h"
#include<string.h>
#include<iostream>


Exception::Exception():
	code(0)
{
	deepCloneMessage("Unkown exception");
}

Exception::Exception(int code, const  char* message) :
	code(code)
{
	deepCloneMessage(message);
}

void Exception::deepCloneMessage(const char* message)
{
	this->message = new char[strlen(message) + 1];
	strcpy((char*)(this->message), message);
}

Exception::Exception(const char* message):
	code(0)
{
	deepCloneMessage(message);
}

Exception::~Exception()
{
	delete [] (this->message);
}

Exception::Exception(const Exception& e)
{
	this->code = e.code;
	deepCloneMessage(e.message);
}

void Exception::print() const
{
	std::cout << "Exception" << "(code=" << code << ")"": " << message << std::endl;
}

void Exception::setCode(int code)
{
	this->code = code;
}

int Exception::getCode()
{
	return code;
}

void Exception::setMessage(const char* msg)
{
	deepCloneMessage(msg);
}

const char* Exception::getMessage()
{
	return message;
}
