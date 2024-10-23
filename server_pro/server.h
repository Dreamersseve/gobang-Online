#ifndef SERVER_H
#define SERVER_H
#include<bits/stdc++.h>
using namespace std;
#include <winsock2.h>  
#include <ws2tcpip.h>  
#include <iostream>  
#include <string>  
#include <thread>  

#pragma comment(lib, "Ws2_32.lib")  
extern const int PORT = 11451;  
extern const int maxn = 100; // 假设我们最多存储100个字符串和整数  
extern std::string strings[maxn];  
extern int integers[maxn];  
extern int aToZ[26]; // 初始化A-Z的变量为0  
extern std::string authTokens; // 用于存储允许的身份验证字符串，这里简单处理为单个字符串（实际中应使用更复杂的验证机制）  

// 处理客户端请求的函数  
void handleClient(SOCKET clientSocket);
void PrintInfo(string str);
void PrintWar(string str);
void PrintErr(string str,int num = 0);
extern bool shutdownflag;
int run_server();
void init();
#endif
