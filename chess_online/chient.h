#ifndef CHIENT_H
#define CHIENT_H
#include <winsock2.h>  
#include <ws2tcpip.h>  
#include <iostream>  
#include <string>  
#include <thread>  
#include<bits/stdc++.h>
#pragma comment(lib, "Ws2_32.lib")  

std::string sendRequest(SOCKET sock, const std::string& action, const std::string& token, int index = -1, const std::string& value = "", int intValue = -1);

int run_chient();
extern std::string token;
extern SOCKET sock;
#endif
