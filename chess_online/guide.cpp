

#include"IO.h"
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
	//printWelcome(); 过于耗时间，调试的时候很烦
	cout<<"======================================"<<endl;
	cout<<"五子棋 ONLINE 开始菜单           "<<endl;
	cout<<"                                 "<<endl;
	cout<<"请右键控制台窗口边框，点击属性，关闭快速编辑模式"<<endl;
	cout<<"请确保控制台窗口能覆盖至少40列，最好全屏       \n\n"<<endl;
	printPHB();
	cout<<"================================="<<endl<<endl;
	while(1){
		PrintInfo("若要登录，请输入0|若要注册，请输入1");
		int op;
		cin>>op;
		if(op == 1){
			Register();
			if(login() == -1) throw "密码尝试次数过多";
			break;
		}
		else if(op == 0){
			if(login() == -1) throw "密码尝试次数过多";
			break;
		}
		else{
			PrintErr("不合法的输入");
			break;
		}
	}
	
	
}
void printOnlineList(){
	getALLplayerData();
	cout<<"=====在线玩家====="<<endl;
	for(int i = 0;i < (int)PlayerData.size();i++){
		if(PlayerData[i].onlineflag) cout<<i<<".   "<<PlayerData[i].name<<endl;
	}
	return;
}
void PrintMainMenu(){
	cout<<"================================="<<endl;
	cout<<"五子棋 ONLINE 开始菜单           "<<endl;
	cout<<endl;
	cout<<userID<<"，您好"<<endl;
	cout<<endl;
	
	cout<<"\n1|发起对局请求\n2|查看对局邀请\n 3|查看排行榜\n4|退出登录"<<endl;
	   
	int ops;
	   cin>>ops;
	while(ops < 1 || ops > 4){
		PrintErr("不合法的请求");
		cin.get();
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

