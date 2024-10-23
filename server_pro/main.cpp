#include <bits/stdc++.h>  
#include "server.h"  
#include <thread>  

using namespace std;  

// 假设 server.h 中有 run_server() 函数的声明  
// void run_server();  

// 全局字符串数组（假设在 server.h 或其他地方已经声明并初始化）  
// std::string strings[10];  // 示例大小，实际应根据需要调整  

void runServerInThread() {  
	run_server();  
}  

int main(int argc, char** argv) {  
	// 初始化字符串数组（如果未在 server.h 或其他地方初始化）  
	// std::string strings[10] = {};  // 示例初始化，实际应根据需要调整  
	init();
	PrintInfo("读取数据中");  
	
	// 使用文件输入流替代 freopen 和 cin，以避免全局标准输入流的潜在问题  
	ifstream inputFile("data.txt");  
	if (!inputFile.is_open()) {  
		PrintErr("无法打开数据文件",-1);
		return 1;  
	}  
	
	string tempStr1, tempStr2;  
	if (!(inputFile >> tempStr1 >> tempStr2)) {  
		PrintErr("读取数据失败",-1);
		inputFile.close();  
		return 1;  
	}  
	
	inputFile.close();  
	
	// 将读取的数据存储到全局数组（假设已经声明）  
	strings[1] = tempStr1;  
	strings[2] = tempStr2;  
	//cout<<tempStr1<<endl;
	//cout<<tempStr2<<endl;
	// 创建并启动新线程来运行 run_server()  
	thread serverThread(runServerInThread);  
	
	serverThread.detach();  
	while(1){
		string CTstring;
		cin>>CTstring;
		if(CTstring == "save"){
			ofstream outputFile("data.txt", ios::trunc);  // 以截断模式打开文件，这会清空文件内容  
			if (outputFile.is_open()) {  
				while(strings[1].back() == '\n') strings[1].pop_back();
				outputFile << strings[1]<<endl;  // 写入 strings[1] 并换行  
				outputFile << strings[2];          // 写入 strings[2]（不换行，如果需要换行则再加 endl）  
				outputFile.close();  // 关闭文件  
				PrintInfo("保存成功"); 
			} else {  
				PrintErr("无法打开数据文件以进行写入",-1); 
			}  
		} else{
			PrintErr("未知指令",-1); 
		}
	}
	
	
	return 0;  
}
