#include "pch.h"
#include "CppUnitTest.h"
#include "../cppserver/TCPServer.h"
#include "../cppserver/SingleThreadBlockTCPServer.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::cout << "asd";
			Assert::AreEqual<int>(1, 2,L"QQQwed");
		}
		TEST_METHOD(TestMethod2)
		{
			std::cout << "fswcfwsdcff";
			Assert::AreEqual<int>(2, 2, L"fsdcwd");
		}
		TEST_METHOD(TestMethod3)
		{
			TCPServer* tcpServer = new SingleThreadBlockTCPServer();
			tcpServer->start(NULL, 7892);

		}
	};
}
