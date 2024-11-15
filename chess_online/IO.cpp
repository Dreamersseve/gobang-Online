#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

void setColor(int color) {  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleTextAttribute(hConsole, color);  
}  //0: 黑色1: 蓝色2: 绿色3: 青色（浅蓝色）4: 红色5: 紫色6: 黄色7: 白色（默认）

void resetColor() {  
	setColor(7); // 7 是默认的白色（背景为黑色）  
}  

void PrintInfo(string str){
	cout<<"[INFO] "<<str<<'\n';
}
void PrintWar(string str){
	setColor(6);
	cout<<"[WAR]  "<<str<<'\n';
	resetColor();
}
void PrintErr(string str){
	setColor(4);
	cout<<"[ERR]  "<<str<<'\n';
	resetColor();
}

#ifndef VK_Z
#define VK_Z 0x5A
#endif
const int NUM_KEYS = 256;
bool IsShiftKeyPressed() {
	// 获取左右Shift键的状态
	SHORT shiftStateLeft = GetKeyState(VK_LSHIFT);
	SHORT shiftStateRight = GetKeyState(VK_RSHIFT);
	
	// 判断是否任何一个Shift键被按下
	return (shiftStateLeft & 0x8000) || (shiftStateRight & 0x8000);
}
// 封装函数：检测键盘输入，返回对应的单个字符
char GetKeyPressed() {
	for (int vkCode = 8; vkCode <= 190; vkCode++) { // 检查常见的虚拟键码范围
		if (GetAsyncKeyState(vkCode) & 0x8000) { // 0x8000 表示键当前被按下
			//cout<<vkCode;
			if (vkCode == VK_RETURN) {
				return '\n'; // enter
			}
			else if (0x30 <= vkCode && vkCode <= 0x39) {
				return vkCode; // enter
			} 
			else if (vkCode > VK_SPACE && vkCode <= VK_Z) { // 字母和数字键
				char ch = MapVirtualKey(vkCode, MAPVK_VK_TO_CHAR);
				if (IsShiftKeyPressed()) {
					return ch;
				}
				return ch + ('a' - 'A');
			}else if (vkCode == VK_OEM_MINUS) { // '+' 键
				return '_';
			}
			else if (vkCode == VK_SPACE) { // ' ' 键
				return ' ';
			}
			else if (vkCode == VK_BACK) { // backspace 键
				return '\b';
			}
			// 可以添加更多特殊键处理
		}
	}
	return 0; // 没有检测到按键
}
constexpr int BLOCK_LENGTH = 20;

void PrintBlock(const std::string& text, const std::string& prefix = "", const std::string& suffix = "") {
	system("cls");
	std::cout << prefix << std::endl;
	
	// Print top border
	for (int i = 1; i <= BLOCK_LENGTH; ++i) {
		std::cout << '-';
	}
	std::cout << std::endl;
	
	int currentLength = 0;
	int textIndex = 0;
	while (textIndex < (int)text.length()) {
		if (currentLength == 0) {
			std::cout << '|';
		}
		
		char character = text[textIndex++];
		std::cout << character;
		currentLength++;
		
		if (currentLength == BLOCK_LENGTH - 2) {
			std::cout << '|' << std::endl;
			currentLength = 0;
		}
	}
	
	// Print last line if there's any remaining text
	if (currentLength == 0) {
		std::cout << '|';
	}
	for (int i = currentLength; i < BLOCK_LENGTH - 2; ++i) {
		std::cout << ' ';
	}
	std::cout << '|' << std::endl;
	
	// Print bottom border
	for (int i = 1; i <= BLOCK_LENGTH; ++i) {
		std::cout << '-';
	}
	std::cout << suffix << std::endl;
}

void DisableEchoInput() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_ECHO_INPUT; // 禁用回显
	SetConsoleMode(hStdin, mode);
}

void EnableEchoInput() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode |= ENABLE_ECHO_INPUT; // 启用回显
	SetConsoleMode(hStdin, mode);
}

std::string GetString(std::string prefix = "",std::string suffix = "") {
	Sleep(500);
	std::string currentString;
	char previousChar = 0; // 初始化上一个字符为0（假设0是一个不可能被按下的键）
	char inputChar;
	PrintBlock(currentString,prefix,suffix);
	while (true) {	
		inputChar = GetKeyPressed();
		
		if (inputChar == '\n') {
			break;
		}else if (inputChar != previousChar) {
			if (inputChar == '\b') { // 处理退格键
				if (!currentString.empty()) {
					currentString.pop_back();
				}
			} else if (inputChar != 0) { // 忽略值为0的字符
				currentString.push_back(inputChar);
			}
			
			previousChar = inputChar; // 更新上一个字符
			PrintBlock(currentString,prefix,suffix);
		}
	}
	
	DisableEchoInput();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	EnableEchoInput();
	
	return currentString;
}
