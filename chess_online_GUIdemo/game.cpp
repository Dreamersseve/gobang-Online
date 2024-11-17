#include<bits/stdc++.h>

#include"guide.h"
#include"data.h"
#include <conio.h>
using namespace std;
extern int nowplayer;

int runGAME();

extern int nowplayer;
extern int stringcur;
extern string VSname;
void Startgame(int stringcur,string VSname);
void BeStartgame(int stringcur,string VSname);
void uploadchess(int row,int col);
void downloadchess(int &row,int &col);

class mouse_checker{
public:
// 定义宏以检查按键是否被按下  
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)  
	
// 定义一个结构体来存储点击位置的坐标  
	struct ClickPosition {  
		bool isClicked;  
		int x;  
		int y;  
	};  

// 获取鼠标在控制台窗口中的点击位置  
	ClickPosition GetMouseClickPosition() {  
		POINT p;  
		CONSOLE_FONT_INFO cfi;  
		ClickPosition position = { false, -1, -1 }; // 初始化为未点击状态  
		
		// 获取当前控制台字体信息  
		GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);  
		
		while (true) {  
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
				break;  
			}  
			
			// 为了让函数不一直占用CPU，可以添加一点延迟（可选）  
			Sleep(10); // 10毫秒延迟  
		}  
		
		return position;  
	}  
}checker;


//版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。
//原文链接：https://blog.csdn.net/adorable_/article/details/80295916
namespace GB{
	
	const int N = 15;       //15*15的棋盘
	const char ChessBoard = ' ';  //棋盘标志
	const char flag1 = 'o';    //玩家1或电脑标志
	const char flag2 = 'x';    //玩家2标志
	
	typedef struct Position{    //坐标
		int row;        //行
		int col;        //列
	}Position;
	
	class GoBang{     //五子棋类
	public:
		GoBang(){
			InitChessBoard();      //初始化棋盘
		}
		void Play(){      //下棋
			Position Play1;   //玩家1
			Position Play2;   //玩家2
			while (1){
					PlayChess(Play1, 1, flag1);         //玩家1走
					if (GetVictory(Play1, 1, flag1)){       //玩家1赢
						break;
					}
					PlayChess(Play2, 2, flag2);         //玩家2走
					if (GetVictory(Play2, 2, flag2)){       //玩家2赢
						break;
					}
			}
		}
		
	protected:
		void InitChessBoard(){          //初始化棋盘
			for (int i = 0; i < N + 1; ++i){
				for (int j = 0; j < N + 1; ++j){
					_ChessBoard[i][j] = ChessBoard;
				}
			}
		}
		/*
		int ChoiceMode(){           //选择模式
		system("cls");
		//系统调用，清屏
		InitChessBoard();       //重新初始化棋盘
		cout << "*************************************************" << endl;
		cout << "******************0、退出************************" << endl;
		cout << "******************1、电脑VS玩家******************" << endl;
		cout << "******************2、玩家VS玩家******************" << endl;
		cout << "*************************************************" << endl;
		while (1){
		int i = 0;
		cout << "请选择模式：";
		cin >> i;
		if (i == 0){       //退出
		exit(1);
		}
		if (i == 1 || i == 2){
		return i;
		}
		else{
		cout << "非法输入，请重新输入！" << endl;
		}
		}
		}
		*/
		void PrintChessBoard(){        //打印棋盘
			
			system("cls");
			//      012345678901234
			printf("     1   2   3   4   5   6   7   8   9  10  11  12  13  14  15\n");
			printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
			for (int i = 1; i < N + 1; ++i)
			{
				printf("%2d ", i);
				printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n", _ChessBoard[i][1], _ChessBoard[i][2], _ChessBoard[i][3], _ChessBoard[i][4], _ChessBoard[i][5], _ChessBoard[i][6], _ChessBoard[i][7], _ChessBoard[i][8], _ChessBoard[i][9], _ChessBoard[i][10], _ChessBoard[i][11], _ChessBoard[i][12], _ChessBoard[i][13], _ChessBoard[i][14], _ChessBoard[i][15]);
				printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
			}
			cout << endl;
		}
		void PlayChess(Position& pos, int player, char flag){
			PrintChessBoard();      //打印棋盘
			
			if(nowplayer == player){
				PrintInfo("你的回合，请点击棋盘落子");
				while(1){
					PrintChessBoard();
					
					pos.row = checker.GetMouseClickPosition().y;
					pos.col = checker.GetMouseClickPosition().x;
					if(pos.row % 2 == 1) continue;
					if((pos.col + 1) % 4 == 0) continue;
					pos.row /= 2;
					pos.col /= 4;
					
					if (JudgeValue(pos) == 1){        //判断坐标是否合法
						uploadchess(pos.row,pos.col);
						break;
					}
					//PrintWar("坐标不合法");
					
				}
			}
			else{
				cout<<"[INFO] 等待"<<VSname<<"做出决策"<<endl;
				downloadchess(pos.row,pos.col);
			}
			
			
			_ChessBoard[pos.row][pos.col] = flag;
		}
		
		int JudgeValue(const Position& pos){       //判断坐标的合法性
			//1.在棋盘上
			if (pos.row > 0 && pos.row <= N && pos.col > 0 && pos.col <= N){
				//2.所在位置为空（没有棋子）
				if (_ChessBoard[pos.row][pos.col] == ChessBoard){
					return 1;      //合法
				} 
			}
			return 0;       //非法
		}
		
		int JudgeVictory(Position pos, char flag){     //判断是否有玩家获胜（底层判断）
			int begin = 0;
			int end = 0;
			
			//1.判断行是否满足条件
			(pos.col - 4) > 0 ? begin = (pos.col - 4) : begin = 1;
			(pos.col + 4) > N ? end = N : end = (pos.col + 4);
			for (int i = pos.row, j = begin; j + 4 <= end; ++j){
				if (_ChessBoard[i][j] == flag && _ChessBoard[i][j + 1] == flag &&
					_ChessBoard[i][j + 2] == flag && _ChessBoard[i][j + 3] == flag &&
					_ChessBoard[i][j + 4] == flag)
					return 1;
			}
			//2.判断列是否满足条件
			(pos.row - 4) > 0 ? begin = (pos.row - 4) : begin = 1;
			(pos.row + 4) > N ? end = N : end = (pos.row + 4);
			for (int j = pos.col, i = begin ; i + 4 <= end; ++i){
				if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j] == flag &&
					_ChessBoard[i + 2][j] == flag && _ChessBoard[i + 3][j] == flag &&
					_ChessBoard[i + 4][j] == flag)
					return 1;
			}
			//3.判断主对角线是否满足条件
			int len = 0;    //相对长度
			int start = 0;
			int finish = 0;
			pos.row > pos.col ? len = pos.col - 1 : len = pos.row - 1;
			if (len > 4){
				len = 4;
			}
			begin = pos.row - len;       //横坐标起始位置
			start = pos.col - len;       //纵坐标起始位置
			
			pos.row > pos.col ? len = N - pos.row : len = N - pos.col;
			if (len > 4){
				len = 4;
			}
			end = pos.row + len;         //横坐标结束位置
			finish = pos.col + len;      //纵坐标结束位置
			
			for (int i = begin, j = start; (i + 4 <= end) && (j + 4 <= finish); ++i, ++j){
				if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j + 1] == flag &&
					_ChessBoard[i + 2][j + 2] == flag && _ChessBoard[i + 3][j + 3] == flag &&
					_ChessBoard[i + 4][j + 4] == flag)
					return 1;
			}
			//4.判断副对角线是否满足条件
			(pos.row - 1) > (N - pos.col) ? len = N - pos.col : len = pos.row - 1;
			if (len > 4){
				len = 4;
			}
			begin = pos.row - len;       //横坐标起始位置
			start = pos.col + len;       //纵坐标起始位置
			
			(N - pos.row) > (pos.col - 1) ? len = pos.col - 1 : len = N - pos.row;
			if (len > 4){
				len = 4;
			}
			end = pos.row + len;         //横坐标结束位置
			finish = pos.col - len;      //纵坐标结束位置 
			for (int i = begin, j = start; (i + 4 <= end) && (j - 4 >= finish); ++i, --j){
				if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j - 1] == flag &&
					_ChessBoard[i + 2][j - 2] == flag && _ChessBoard[i + 3][j - 3] == flag &&
					_ChessBoard[i + 4][j - 4] == flag)
					return 1;
			}
			//该位置并未下棋
			for (int x = 1; x < N + 1; ++x){
				for (int y = 1; y < N + 1; ++y){
					if (_ChessBoard[x][y] == ChessBoard){
						return 0;       //未下棋
					}
				}
			}
			return -1;      //和局
		}
		
		bool GetVictory(Position& pos, int player, char flag){       //判断具体哪位玩家赢
			if (JudgeVictory(pos, flag) != 0){    //判断有无人获胜
				if (JudgeVictory(pos, flag) == 1){     //判断是否有人获胜,1表示获胜
					PrintChessBoard();     //打印棋盘
					if(player == nowplayer){
						Sleep(1000);
						WIN();
						return true;
					}
					else{
						Sleep(1000);
						FAL();
						return true;
					}
					
				}
				else{
					Sleep(1000);
					HE();
				}
				return true;      //有人获胜
			}   
			return false;         //没人获胜
		}
		
	private:
		char _ChessBoard[N + 1][N + 1];    //棋盘
	};
}

int runGAME(){
	printStartMenu();
	Sleep(1000);
	system("cls");
	while(1){
		PrintMainMenu();
		system("cls");
	}
}

int nowplayer;
int stringcur;
string VSname;
void Startgame(int stringcur,string VSname){
	PrintInfo("游戏准备中...");
	PrintInfo("您为先手（黑子），存在禁手原则");
	nowplayer = 1;
	stringcur = stringcur;
	VSname = VSname;
	sendRequest(sock,"SETSTR",token,stringcur,"NEXT");
	GB::GoBang g;
	g.Play();
}
void BeStartgame(int stringcur,string VSname){
	PrintInfo("游戏准备中...");
	PrintInfo("您为后手（白子）");
	nowplayer = 2;
	stringcur = stringcur;
	VSname = VSname;
	GB::GoBang g;
	g.Play();
}
void uploadchess(int row,int col){
	string Rawstring;
	Rawstring.insert(0,to_string(row));
	Rawstring.push_back(',');
	Rawstring.insert(Rawstring.length(),to_string(col));
	sendRequest(sock,"SETSTR",token,stringcur,Rawstring);
}
void downloadchess(int &row,int &col){
	string Rawstring;
	while(1){
		Sleep(500);
		Rawstring = sendRequest(sock,"GETSTR",token,stringcur);
		if(Rawstring != "NEXT"){
			string R,C;
			int cur = 0;
			while(Rawstring[cur] != ','){
				if(Rawstring[cur] >= '0' && Rawstring[cur] <= '9')
					R.push_back(Rawstring[cur]);
				cur++;
			}
			cur++;
			while(cur < (int)Rawstring.length()){
				C.push_back(Rawstring[cur]);
				cur++;
			}
			row = atoi(R.c_str());
			col = atoi(C.c_str());
			break;
		}
		
	}
	sendRequest(sock,"SETSTR",token,stringcur,"NEXT");
}


