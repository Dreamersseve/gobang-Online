
using namespace std;
#include <winsock2.h>  
#include <ws2tcpip.h>  
#include <iostream>  
#include <string>  
#include <thread>  
#include <sstream>
bool shutdownflag = false;
void setColor(int color) {  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleTextAttribute(hConsole, color);  
}  //0: 黑色1: 蓝色2: 绿色3: 青色（浅蓝色）4: 红色5: 紫色6: 黄色7: 白色（默认）

void resetColor() {  
	setColor(7); // 7 是默认的白色（背景为黑色）  
}  

void PrintInfo(string str){
	cout<<"\n[INFO] "<<str<<'\n';
}
void PrintWar(string str){
	setColor(6);
	cout<<"\n[WAR]  "<<str<<'\n';
	resetColor();
}
void PrintErr(string str,int num = -1){
	setColor(4);
	if(num == -1)cout<<"[ERR]  "<<str<<'\n';
	else cout<<"\n[ERR]  "<<str<<num<<'\n';
	resetColor();
}

const int PORT = 11451;  
const int maxn = 100; // 假设我们最多存储100个字符串和整数  
std::string strings[maxn];  
int integers[maxn];  
int aToZ[26] = {0}; // 初始化A-Z的变量为0  
std::string authTokens = "sever_pro::"; // 用于存储允许的身份验证字符串，这里简单处理为单个字符串（实际中应使用更复杂的验证机制）  
void init(){
	for(int i = 1;i < maxn;i++){
		strings[i] = "|";
	}
	return;
}
// 处理客户端请求的函数  
void handleClient(SOCKET clientSocket) {  
	
	char buffer[2048]; // 更大的缓冲区以处理可能的更大数据包  
	int bytesReceived;  
	std::string request, token, strIndexStr, intValueStr;  
	int strIndex, intValue;  
	
	// 省略了部分代码...  
	
	while (true) {  
		bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);  
		if (bytesReceived <= 0) {  
			// 客户端断开连接或错误  
			break;  
		}  
		buffer[bytesReceived] = '\0';  
		request = std::string(buffer);  
		while(request.back() == '\r') request.pop_back();
		// 解析请求（这里假设请求格式为："ACTION TOKEN INDEX/VALUE"）  
		// 例如："GET abc123 0" 或 "SET abc123 0 newvalue 42"  
		std::istringstream iss(request);  
		std::string action, rest;  
		std::getline(iss, action, ' ');  
		std::getline(iss, token, ' ');  
		std::getline(iss, rest, ' ');  
		//token = rest.substr(0, rest.find(' '));  弃用的代码
		//rest = rest.substr(rest.find(' ') + 1);  
		//cout<<action<<endl<<token<<endl<<rest<<endl;
		if (authTokens.substr(0,11) != token.substr(0,11)) {  
			// 无效的身份验证字符串  
			send(clientSocket, "ERROR: Invalid token\n", 21, 0);  
			break;  
		}  
		if (action == "GETSTR") {  
			// 获取字符串
			//cout<<strings[1]<<endl;
			strIndexStr = rest.substr(0, rest.find(' '));  
			strIndex = std::stoi(strIndexStr.c_str());  
			if (strIndex >= 0 && strIndex < maxn) {  
				cout<<"\n[INFO] st "<<strIndex<<" be "<<clientSocket<<"get:"<<strings[strIndex]<<endl;
				//strings[strIndex].push_back('\n');
				send(clientSocket, strings[strIndex].c_str(), strings[strIndex].size(), 0);  
				//send(clientSocket, "\n", 1, 0); 
			} else {  
				send(clientSocket, "ERROR: Index out of range\n", 20, 0);  
			}  
		} else if (action == "GETINT") {  
			// 获取整数  
			strIndexStr = rest.substr(0, rest.find(' '));  
			strIndex = std::stoi(strIndexStr.c_str());  
			if (strIndex >= 0 && strIndex < maxn) {   
				cout<<"[INFO] int "<<strIndex<<" be "<<clientSocket<<"gt:"<<integers[strIndex]<<endl;
				string sended = std::to_string(integers[strIndex]);
				//sended.push_back('\n');
				send(clientSocket, sended.c_str(), sended.size(), 0);  
			} else {  
				send(clientSocket, "ERROR: Index out of range\n", 20, 0);  
			}  
		} else if (action == "SETINT") {  
			// 设置整数  
			int Setcur = atoi(rest.c_str());
			string setvalue;
			getline(iss,setvalue,' ');
			intValue = atoi(setvalue.c_str());
			if(Setcur >= 0 && Setcur < maxn){
				integers[Setcur] = intValue;
				cout<<"[INFO] int "<<Setcur<<" be "<<clientSocket<<"cg:"<<intValue<<endl;
				send(clientSocket, "OK", 2, 0);  
			} else {
				send(clientSocket, "ERROR: Index out of range\n", 20, 0);  
			}
		} else if (action == "SETSTR") {  
			// 设置字符串  
			int Setcur = atoi(rest.c_str());
			string strvalue;
			getline(iss,strvalue,' ');
			if(Setcur >= 0 && Setcur < maxn){
				strings[Setcur] = strvalue;
				cout<<"\n[INFO] st "<<Setcur<<" be "<<clientSocket<<"cg:"<<strvalue<<endl;
				//cout<<strings[1]<<endl;
				send(clientSocket, "OK", 2, 0);  
			} else {
				send(clientSocket, "ERROR: Index out of range\n", 20, 0);  
			}
			
		} else {  
			// 未知的请求类型  
			send(clientSocket, "ERROR: Unknown action\n", 20, 0);  
		}  
	}  
	
	closesocket(clientSocket);  
}  


int run_server() {  
	WSADATA wsaData;  
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);  
	if (result != 0) {  
		PrintErr("WSAStartup failed: ",result);  
		return 1;  
	}  
	
	SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
	if (listenSocket == INVALID_SOCKET) {  
		PrintErr("Error at socket(): ",WSAGetLastError() );
		WSACleanup();  
		return 1;  
	}  
	
	sockaddr_in serverAddr;  
	serverAddr.sin_family = AF_INET;  
	serverAddr.sin_port = htons(PORT);  
	serverAddr.sin_addr.s_addr = INADDR_ANY;  
	
	if (bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {  
		PrintErr("bind failed: ",WSAGetLastError());
		closesocket(listenSocket);  
		WSACleanup();  
		return 1;  
	}  
	
	if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {  
		PrintErr("listen failed: ",WSAGetLastError());
		closesocket(listenSocket);  
		WSACleanup();  
		return 1;  
	}  
	string infostring = "Server listening on port :";
	infostring.insert(infostring.length(),to_string(PORT));
	PrintInfo(infostring);
	
	while (true) {  
		SOCKET clientSocket = accept(listenSocket, NULL, NULL);  
		if (clientSocket == INVALID_SOCKET) {  
			PrintErr("accept failed: ",WSAGetLastError());
			continue;  
		}  
		
		std::thread(handleClient, clientSocket).detach();  
	}  
	
	closesocket(listenSocket);  
	WSACleanup();  
	return 0;  
}
