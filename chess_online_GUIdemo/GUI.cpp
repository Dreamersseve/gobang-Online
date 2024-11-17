#include "GUI.h"
//#define DX
// Point
void GUI::Point::init() {
	x = y = -1;
}

// ButtonPoint
GUI::ButtonPoint::ButtonPoint() : index(-1), type(-1) {}
void GUI::ButtonPoint::init() {
	index = type = -1;
	start.init();
	end.init();
}

// IO

std::vector<std::string> GUI::IO::processString(const std::string& str) {
	
	std::vector<std::string> RawBuffer;
	
	std::string Rawstring;
	
	for (size_t i = 0; i < str.size(); ++i) { // 使用索引来遍历字符串
		char ch = str[i];
		
		if (ch == '\n' && (i + 1 < str.size())) { // 检查是否还有下一个字符{
			RawBuffer.push_back(Rawstring);
			Rawstring.clear();
			//ss << '\n';
			//++i; // 跳过下一个字符（'n'）
			
		} else {
			Rawstring.push_back(ch);
		}
	}
	if(!Rawstring.empty()) RawBuffer.push_back(Rawstring);
	return RawBuffer;
}

GUI::IO::IO() {
	InitConsoleBuffers();
}

void GUI::IO::InitConsoleBuffers() {
	hOutBuf = CreateConsoleScreenBuffer(
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
		);
	hOutput = CreateConsoleScreenBuffer(
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
		);
	
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
#ifdef DX
	SetConsoleCursorInfo(hOutput, &cci);
	SetConsoleCursorInfo(hOutBuf, &cci);
#endif
}

void GUI::IO::ReOutputGUI() {
#ifndef DX
	system("cls");
#endif
	if (showflag == 0) {
		for (size_t i = 0; i < outMap.size(); ++i) {
			coord.Y = i;
			#ifdef DX
			WriteConsoleOutputCharacterA(hOutBuf, outMap[i].c_str(), outMap[i].size(), coord, &bytes);
			#endif
			std::cout<<outMap[i]<<std::endl;
		}
		showflag = 1;
		#ifdef DX
		SetConsoleActiveScreenBuffer(hOutBuf);
		#endif
	} else {
		for (size_t i = 0; i < outMap.size(); ++i) {
			coord.Y = i;
			#ifdef DX
			WriteConsoleOutputCharacterA(hOutput, outMap[i].c_str(), outMap[i].size(), coord, &bytes);
			#endif
			std::cout<<outMap[i]<<std::endl;
		}
		#ifdef DX
		SetConsoleActiveScreenBuffer(hOutput);
		#endif
		
		showflag = 0;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(sd));
}

void GUI::IO::SetPrintcur(int x, int y) {
	PrintCur.x = x;
	PrintCur.y = y;
}
std::string whitestring = "                                                                            ";
void GUI::IO::ClearOutputGUI(){
	//std::string whitestring = "                                                                                                    ";
	for(int i = 0;i < (int)outMap.size();i++){
		outMap[i] = whitestring;
	}
	ReOutputGUI();
	
	
	ReOutputGUI();
	outMap.clear();
}
void GUI::IO::Printf(const std::string& format, ...) {
	va_list args;
	va_start(args, format);
	
	char buffer[2048]; // 增大缓冲区大小以避免潜在的溢出
	vsnprintf(buffer, sizeof(buffer), format.c_str(), args);
	va_end(args);
	
	std::vector<std::string> processedString = processString(buffer);
	
	if (PrintCur.x == -1) {
		bool emptyFlag = true;
		for (int i = 0; i < static_cast<int>(outMap.size()); ++i) {
			if (outMap[i].empty()) {
				emptyFlag = false;
				for (int j = i, k = 0; k < static_cast<int>(processedString.size()); j++, k++) {
					if (static_cast<int>(outMap.size()) < j) 
						outMap.push_back(processedString[k]);
					else 
						outMap[j] = processedString[k];
				}
				break;
			}
		}
		if (emptyFlag) {
			for (int k = 0; k < static_cast<int>(processedString.size()); k++) {
				outMap.push_back(processedString[k]);
			}
		}
	} else {
		std::string ForwardString;
		while (static_cast<int>(outMap.size()) <= PrintCur.y + 1) outMap.push_back("");
		
		for (int j = PrintCur.y, k = 0; k < static_cast<int>(processedString.size()); j++, k++) {
			
			ForwardString.clear();
			for (int i = 0; i < PrintCur.x; i++) {
				if((int)outMap[j].length() > i) ForwardString += outMap[j][i];
				else ForwardString.push_back(' ');
			}
			
			if (static_cast<int>(outMap.size()) <= j) outMap.push_back(ForwardString + processedString[k]);
			else outMap[j] = ForwardString + processedString[k];
		}
	}
}

#ifndef VK_Z
#define VK_Z 0x5A
#endif
		const int NUM_KEYS = 256;
		bool GUI::IO::IsShiftKeyPressed() {
			// 获取左右Shift键的状态
			SHORT shiftStateLeft = GetKeyState(VK_LSHIFT);
			SHORT shiftStateRight = GetKeyState(VK_RSHIFT);
			
			// 判断是否任何一个Shift键被按下
			return (shiftStateLeft & 0x8000) || (shiftStateRight & 0x8000);
		}
		char GUI::IO::GetKeyPressed() {
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
		const int BLOCK_LENGTH = 20;

		void GUI::IO::PrintBlock(int x,int y,const std::string& text, const std::string& prefix, const std::string& suffix){
			//system("cls");
			
			std::string RawoutputString;
			RawoutputString += prefix + '\n';
			
			//std::cout << prefix << std::endl;
			
			// Print top border
			for (int i = 1; i <= BLOCK_LENGTH; ++i) {
				RawoutputString += '-';
				//std::cout << '-';
			}
			//std::cout << std::endl;
			RawoutputString += '\n';
			int currentLength = 0;
			int textIndex = 0;
			while (textIndex < (int)text.length()) {
				if (currentLength == 0) {
					//std::cout << '|';
					RawoutputString += '|';
				}
				
				char character = text[textIndex++];
				RawoutputString += character;
				//std::cout << character;
				currentLength++;
				
				if (currentLength == BLOCK_LENGTH - 2) {
					//std::cout << '|' << std::endl;
					RawoutputString += '|' + whitestring + '\n';
					currentLength = 0;
				}
			}
			
			// Print last line if there's any remaining text
			if (currentLength == 0) {
				//std::cout << '|';
				RawoutputString += '|';
			}
			for (int i = currentLength; i < BLOCK_LENGTH - 2; ++i) {
				//std::cout << ' ';
				RawoutputString += ' ';
			}
			//std::cout << '|' << std::endl;
			RawoutputString += '|' + whitestring + '\n';
			// Print bottom border
			for (int i = 1; i <= BLOCK_LENGTH; ++i) {
				//std::cout << '-';
				RawoutputString += '-';
			}
			RawoutputString += whitestring;
			//std::cout << suffix << std::endl;
			RawoutputString += '\n' + suffix ;
			
			SetPrintcur(x,y);
			Printf(RawoutputString);
			ReOutputGUI();
		}

		void GUI::IO::DisableEchoInput() {
			HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
			DWORD mode;
			GetConsoleMode(hStdin, &mode);
			mode &= ~ENABLE_ECHO_INPUT; // 禁用回显
			SetConsoleMode(hStdin, mode);
		}

		void GUI::IO::EnableEchoInput() {
			HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
			DWORD mode;
			GetConsoleMode(hStdin, &mode);
			mode |= ENABLE_ECHO_INPUT; // 启用回显
			SetConsoleMode(hStdin, mode);
		}
		std::string GUI::IO::GetString(int x,int y,std::string prefix,std::string suffix) {
			Sleep(500);
			ClearOutputGUI();
			std::string currentString;
			char previousChar = 0; // 初始化上一个字符为0（假设0是一个不可能被按下的键）
			char inputChar;
			PrintBlock(x,y,currentString,prefix,suffix);
			while (true) {	
				inputChar = GetKeyPressed();
				
				if (inputChar == '\n') {
					if(!currentString.empty())break;
				}else if (inputChar != previousChar) {
					if (inputChar == '\b') { // 处理退格键
						if (!currentString.empty()) {
							currentString.pop_back();
						}
					} else if (inputChar != 0) { // 忽略值为0的字符
						currentString.push_back(inputChar);
					}
					
					previousChar = inputChar; // 更新上一个字符
					PrintBlock(x,y,currentString,prefix,suffix);
				}
			}
			
			//DisableEchoInput();
			//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//EnableEchoInput();
			//std::cin.sync();
			return currentString;
		}

		GUI::ClickPosition GUI::mouse_checker::GetMouseClickPosition() {  
			POINT p;  
			CONSOLE_FONT_INFO cfi;  
			ClickPosition position = { false, -1, -1 ,-1}; // 初始化为未点击状态  
			
			// 获取当前控制台字体信息  
			GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);  
			
			//while (true) {  
			// 检查鼠标左键是否被按下  
			if (KEY_DOWN(VK_LBUTTON)) {  
				// 获取鼠标位置  
				GetCursorPos(&p);  
				// 将鼠标位置转换为控制台窗口中的坐标  
				ScreenToClient(GetForegroundWindow(), &p);  
				
				// 计算控制台中的字符坐标  
				int x = p.x / cfi.dwFontSize.X;  
				int y = p.y / cfi.dwFontSize.Y;  
				
				// 更新位置信息并退出循环  
				position.isClicked = true;  
				position.x = x;  
				position.y = y;  
				
				position.checkType = 1;
				//break;  
			}  
			// 检查右键是否被按下
			if (KEY_DOWN(VK_RBUTTON)) {  
				// 获取鼠标位置  
				GetCursorPos(&p);  
				// 将鼠标位置转换为控制台窗口中的坐标  
				ScreenToClient(GetForegroundWindow(), &p);  
				
				// 计算控制台中的字符坐标  
				int x = p.x / cfi.dwFontSize.X;  
				int y = p.y / cfi.dwFontSize.Y;  
				
				// 更新位置信息并退出循环  
				position.isClicked = true;  
				position.x = x;  
				position.y = y;  
				
				position.checkType = 2;
				//break;  
			} 
			// 为了让函数不一直占用CPU，可以添加一点延迟（可选）  
			Sleep(10); // 10毫秒延迟  
			//}  
			
			return position;  
		}  
		static GUI::mouse_checker checker;
		
		GUI::BUTTON::BUTTON(){
			for(int i = 0;i < maxnbutton;i++){
				Button[i].init();
			}	
		}
		void GUI::BUTTON::init(){
			for(int i = 0;i < maxnbutton;i++){
				Button[i].init();
			}
		}
		//static bool GUI::BUTTON::checkedflag[maxnbutton];
		void GUI::BUTTON::reCheckingLoop() {
			while (reCheckingFlag) {
				for (int i = 0; i < maxnbutton; i++) {
					
					if (Button[i].index != -1) {
						checkButton(i);
					}
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(10));
			}
		}
		int GUI::BUTTON::addButton(int startx,int starty,int endx,int endy,int type){
			
			int emptycur = -1;
			for(int i = 0;i < maxnbutton;i++){
				if(Button[i].index == -1) emptycur = i;
			}
			if(emptycur == -1) return -1;
			Button[emptycur].index = emptycur;
			Button[emptycur].type = type;
			Button[emptycur].start = {startx,starty};
			Button[emptycur].end = {endx,endy};
			checkedflag[emptycur] = false;
			return emptycur;
		}
		
		void GUI::BUTTON::delButton(int cur){
			Button[cur].init();
			checkedflag[cur] = false;
		}

		bool GUI::BUTTON::checkButton(int cur){
			ClickPosition pos = checker.GetMouseClickPosition();
			if(pos.isClicked == false) return false;
			if(Button[cur].type != pos.checkType) return false;
			if(Button[cur].start.x <= pos.x && pos.x <= Button[cur].end.x &&
				Button[cur].start.y <= pos.y && pos.y <= Button[cur].end.y){
				
				
				
				checkedflag[cur] = true;
				return true;
			}
			return false;
		}

		void GUI::BUTTON::stopChecking(){
			reCheckingFlag = false;
		}

		void GUI::BUTTON::startChecking() {
			stopChecking(); // 确保没有正在运行的线程
			reCheckingFlag = true;
			checkingThread = new std::thread(&BUTTON::reCheckingLoop, this);
			
			//if (checkingThread->joinable()) { // 检查线程是否可连接（即是否已经被分离或完成）
			checkingThread->detach();
			//}
			
		}
GUI gui;
