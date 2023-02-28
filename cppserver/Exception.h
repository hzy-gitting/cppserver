#pragma once
class Exception
{
private:
	int code;
	const char* message;
public:
	Exception();
	Exception(int code,const char *message = nullptr);
	
	Exception(const char* message);
	~Exception();
	Exception(const Exception& e);

	virtual void print();
	void setCode(int code);
	int getCode();
	void setMessage(const char* msg);
	const char* getMessage();
private:
	void deepCloneMessage(const char* message);
};

