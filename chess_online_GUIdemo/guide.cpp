

#include"IO.h"
#include"GUI.h"
#include"data.h"
#include"game.h"
#include"Pvp.h"
#include<bits/stdc++.h>


using namespace std;
int logout();
void printWelcome(){
	int turns = 30;
	while(turns--){
		cout<<"◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n";
		Sleep(30);
	}
	cout<<"◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◆◆◇◇◇◇◇◇◇◇◆◆◇◇◆◆◇◇◆◆◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◆◆◆◆◆◆◆◆◆◆◇◇◇◇◇◇◇◆◆◆◆◆◆◆◆◆◆◇◇◇◇◇◇◇◇◇◆◆◇◆◆◇◇◆◆◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◆◆◆◆◆◆◆◆◆◇◇◇◇◇◇◇◇◇◇◆◆◆◆◇◆◆◆◇◇◇◇◇◇◇◇◇◇◆◇◇◇◆◇◇◆◆◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◇◇◆◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◆◆◆◆◇◇◇◇◇◇◇◇◇◇◇◆◇◇◆◆◆◆◆◆◆◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◇◆◆◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◆◆◆◇◇◇◇◇◇◇◇◇◆◆◆◆◆◆◆◆◆◆◆◆◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◇◆◆◆◆◆◆◇◇◇◇◇◇◇◇◇◇◇◇◇◇◆◇◇◇◆◆◆◇◇◇◇◆◆◆◆◇◇◇◆◆◆◆◆◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◆◆◆◆◆◆◆◆◇◇◇◇◇◇◇◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇◇◇◇◇◇◆◆◆◆◇◆◆◆◆◇◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◇◆◇◇◇◆◇◇◇◇◇◇◇◇◆◆◆◆◆◆◆◆◆◇◇◇◇◇◇◇◇◇◇◆◆◆◆◆◇◆◆◆◆◇◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◇◆◇◇◇◆◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◆◆◇◇◇◇◇◇◇◇◇◇◆◆◆◇◇◇◆◆◆◆◇◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◆◆◇◇◆◆◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◆◆◇◇◇◇◇◇◇◇◇◆◆◇◆◇◇◇◆◇◆◆◆◆◆◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◆◆◇◇◆◆◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◆◆◇◇◇◇◇◇◇◇◇◆◆◇◆◆◆◆◆◆◆◆◆◆◆◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◆◆◆◆◆◆◆◆◆◆◇◇◇◇◇◇◇◇◇◆◇◇◆◇◇◇◇◇◇◇◇◇◇◆◇◇◆◇◇◇◆◆◆◆◆◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◆◆◆◆◆◆◆◆◆◆◆◆◆◆◇◇◇◇◇◇◇◇◆◆◆◆◇◇◇◇◇◇◇◇◇◇◇◇◇◆◇◇◆◆◇◇◆◆◆◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◆◆◆◇◇◇◇◇◇◇◇◇◇◇◇◆◆◆◆◆◇◇◇◇◆◆◇◇◇\n";Sleep(50);
	cout<<R"(◇◇◇◇◇◇                _  _              ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇
)";Sleep(50);
	cout<<R"(◇◇◇◇◇◇   ___   _ __  | |(_) _ __    ___ ◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇
)";Sleep(50);
	cout<<R"(◇◇◇◇◇◇  / _ \ | '_ \ | || || '_ \  / _ \◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇
)";Sleep(50);
	cout<<R"(◇◇◇◇◇◇ | (_) || | | || || || | | ||  __/◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇
)";Sleep(50);
	cout<<R"(◇◇◇◇◇◇  \___/ |_| |_||_||_||_| |_| \___|◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇
)";Sleep(50);
//"
	cout<<"◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n";Sleep(50);
	cout<<"◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n";Sleep(50);

	Sleep(2000);
	turns = 30;
	while(turns--){
		cout<<"◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n";
		Sleep(30);
	}
	turns = 30;
	while(turns--){
		cout<<"\n";
		Sleep(30);
	}
	system("cls");
}
void printStartMenu(){
	printWelcome(); //过于耗时间，调试的时候很烦
	PrintInfo("======================================");
	PrintInfo("五子棋 ONLINE 开始菜单           ");
	PrintInfo("                                 ");
	PrintInfo("请右键控制台窗口边框，点击属性，关闭快速编辑模式");
	PrintInfo("请确保控制台窗口能覆盖至少40列，最好全屏       ");
	//printPHB();
	PrintInfo(" \n======================================");
		//PrintInfo("若要登录，请输入0|若要注册，请输入1");
		gui.io.SetPrintcur(2,8);
		gui.io.Printf("--------    --------\n| 登录 |    | 注册 |\n--------    --------");
		gui.io.ReOutputGUI();
		int button1cur = gui.button.addButton(2,8,9,10,1);
		int button2cur = gui.button.addButton(14,8,20,10,1);
		
		gui.button.startChecking();
		//int op;
		//cin>>op;
		//int i = 0;
		
		while(1){
			//i++;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			//gui.io.Printf("%d",i);
			
			if(gui.button.checkedflag[button2cur]){
				Register();
				if(login() == -1) throw "密码尝试次数过多";
				gui.button.stopChecking();
				break;
			}
			if(gui.button.checkedflag[button1cur]){
				if(login() == -1) throw "密码尝试次数过多";
				gui.button.stopChecking();
				break;
			}
			
		}
	
	
}
void printOnlineList(){
	getALLplayerData();
	gui.io.ClearOutputGUI();
	gui.io.SetPrintcur(-1,-1);
	gui.io.Printf("=====在线玩家=====");
	//cout<<"=====在线玩家====="<<endl;
	for(int i = 0;i < (int)PlayerData.size();i++){
		if(PlayerData[i].onlineflag){
			gui.io.Printf(to_string(i) + ".   " + PlayerData[i].name);
			//cout<<i<<".   "<<PlayerData[i].name<<endl;
		}
	}
	return;
}
void PrintMainMenu(){
	
	gui.button.init();
	
	gui.io.ClearOutputGUI();
	
	gui.io.SetPrintcur(0,0);
	gui.io.Printf("五子棋 ONLINE 开始菜单------------------------------------\n" 
			       + userID + ", 您好\n"
		+         "==========================================================");
	
	gui.io.SetPrintcur(58,0);
	gui.io.Printf(
		(string)  "------------\n"
		+         "|   登出   |\n"
		+         "------------");
	int LoggoutButton = gui.button.addButton(58, 0, 69, 2, 1);

	
	gui.io.SetPrintcur(0,4);
	gui.io.Printf(
(string)"-----------------------------------\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|              发 送              |\n"+
		"|              对 局              |\n"+
		"|              请 求              |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"-----------------------------------");
	int SendRequestButton = gui.button.addButton(0, 4, 38, 24, 1);
	
	
	gui.io.SetPrintcur(35,4);
	gui.io.Printf(
(string)"-----------------------------------\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|              查 看              |\n"+
		"|              对 局              |\n"+
		"|              请 求              |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"-----------------------------------");
	int CheckRequestButton = gui.button.addButton(35, 4, 69, 16, 1);

	
	gui.io.SetPrintcur(35,16);
	gui.io.Printf(
(string)"-----------------------------------\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|            查看排行榜           |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"|                                 |\n"+
		"-----------------------------------");
	int PrintPHBButton = gui.button.addButton(35, 16, 69, 24, 1);
	
	gui.io.ReOutputGUI();
	//gui.io.ReOutputGUI();
	//cout<<"\n1|发起对局请求\n2|查看对局邀请\n 3|查看排行榜\n4|退出登录"<<endl;
	   
	//int ops;
	//cin>>ops;
	
	gui.button.startChecking();
	//Sleep(1000000);
	while(1){
		Sleep(10);
		if(gui.button.checkedflag[LoggoutButton]){
			//PrintWar("1");
			gui.io.SetPrintcur(58,0);
			gui.io.Printf(
				(string)  "------------\n"
				+         "|$$$登出$$$|\n"
				+         "------------");
			gui.io.ReOutputGUI();
			Sleep(500);
			logout();
			PrintInfo("退出登录成功");
			Sleep(1000);
			exit(0);
			return;
			
		}
		if(gui.button.checkedflag[SendRequestButton]){
			gui.io.ReOutputGUI();
			gui.io.SetPrintcur(0,4);
			gui.io.Printf(
				(string)"-----------------------------------\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$发 送$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$对 局$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$请 求$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"-----------------------------------");
			gui.io.ReOutputGUI();
			Sleep(500);
			gui.button.stopChecking();
			sendVSrequst();
			break;
			
		}
		if(gui.button.checkedflag[CheckRequestButton]){
			gui.io.SetPrintcur(35,4);
			gui.io.Printf(
				(string)"-----------------------------------\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$查 看$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$对 局$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$请 求$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"-----------------------------------");
			gui.io.ReOutputGUI();
			Sleep(500);
			gui.button.stopChecking();
			checkVSrequst();
			break;
			
		}
		if(gui.button.checkedflag[PrintPHBButton]){
			gui.io.SetPrintcur(35,16);
			gui.io.Printf(
				(string)"-----------------------------------\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$查看排行榜$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"|$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$|\n"+
				"-----------------------------------");
			gui.io.ReOutputGUI();
			Sleep(500);
			gui.button.stopChecking();
			printPHB();
			break;
			
		}
	}
	/*
	while(ops < 1 || ops > 4){
		PrintErr("不合法的请求");
		cin>>ops;
	}
	if(ops == 1){
		sendVSrequst();
	}
	if(ops == 2){
		checkVSrequst();
	}
	if(ops == 3){
		printPHB();
		system("pause");
	}
	if(ops == 4){
		logout();
		PrintInfo("退出登录成功");
		Sleep(1000);
		exit(0);
		return;
	}
	*/
}
void WIN(){
	system("cls");
	cout<<"====胜利===="<<endl;
	//"保证高亮
	Sleep(2000);
	PLAYER p = getUserData(userID);
	cout<<endl;
	cout<<userID<<", 胜场"<<p.win<<"---->>>"<<p.win+1<<endl;
	playerWIN();
	Sleep(1000);
	return;
}
void FAL(){
	system("cls");
	cout<<"====失败===="<<endl;
	//"保证高亮
	Sleep(2000);
	playerFAL();
	Sleep(1000);
	return;
}
void HE(){
	system("cls");
	cout<<"====平局===="<<endl;
	
}

