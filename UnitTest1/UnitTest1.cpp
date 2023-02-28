#include "pch.h"
#include "CppUnitTest.h"
#include "../cppserver/TCPServer.h"
#include "../cppserver/SingleThreadBlockTCPServer.h"
#include"../cppserver/Exception.h"

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
			Logger::WriteMessage("²âÊÔ2");
		}
		TEST_METHOD(TestMethod3)
		{
			TCPServer* tcpServer = new SingleThreadBlockTCPServer();
			tcpServer->start(NULL, 7892);

		}
		TEST_METHOD(TestExecption)
		{
			Exception e;
			Assert::AreEqual<int>(0, e.getCode());
			Assert::AreEqual("Unkown exception", e.getMessage(), "message not equal");
			e.print();
		}
		TEST_METHOD(TestExecption2)
		{
			Exception e(3,"Network error!");
			Assert::AreEqual<int>(3, e.getCode());
			Assert::AreEqual("Network error!", e.getMessage(), "message not equal");
			e.print();
		}
		TEST_METHOD(TestExecption3)
		{
			Exception e("Network error!");
			Assert::AreEqual<int>(0, e.getCode());
			Assert::AreEqual("Network error!", e.getMessage(), "message not equal");
			e.print();
		}
	};
}
