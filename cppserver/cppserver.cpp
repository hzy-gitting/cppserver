//cpp写的http服务器框架
//接收http请求，做出响应，响应逻辑由程序自定义
/******

1.***底层网络层：

  1.1 TCP层
  接收TCP连接，接收TCP流
  发送TCP流

  1.2 HTTP层
  解析TCP数据流打包为HTTP请求体
  将HTTP响应体序列化为TCP流

2.对象-JSON转换层（序列化与反序列化）

3.控制层
  对HTTP请求体进行响应，返回响应体
 ***/
#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

