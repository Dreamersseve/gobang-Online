#include<bits/stdc++.h>

#include"IO.h"
#include"data.h"
#include"game.h"
using namespace std;

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
	//printWelcome();
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
void sendVSrequst(){
	
	printOnlineList();
	int num;
	bool numSucessFlag = false;
	while(!numSucessFlag){
		PrintInfo("请输入发起请求玩家编号,-1退出");
		cin>>num;
		if(num < -1 || num >= (int)PlayerData.size()){
			PrintWar("非法的编号，请重新输入");
		} else if(num == -1){
			return;
		}else if(PlayerData[num].onlineflag == false){
			PrintWar("请输入列表中的玩家");
		} else if(PlayerData[num].name == userID){
			PrintErr("不能向自己发起对局请求，请重新输入");
		} else{
			break;
		}
	}
	
	string Rawstring;
	Rawstring = sendRequest(sock,"GETSTR",token,4);
	Rawstring.push_back('|');
	Rawstring.insert(Rawstring.length(),userID);
	Rawstring.push_back(':');
	Rawstring.push_back('(');
	Rawstring.insert(Rawstring.length(),PlayerData[num].name);
	Rawstring.push_back(')');
	sendRequest(sock,"SETSTR",token,4,Rawstring);
	PrintInfo("请求已发送，等待对方接受");
	size_t resultcur = 0;
	while(1){
		Sleep(5000);
		Rawstring = sendRequest(sock,"GETSTR",token,4);
		string findstring = PlayerData[num].name;
		findstring.push_back('*');
		size_t resultcur = Rawstring.find(findstring);
		if(resultcur == string::npos) continue;
		if(Rawstring[resultcur - 1] == '(' && Rawstring[resultcur + findstring.length()] == ')'){
			break;
		}
		
	}
	PrintInfo("对方接受了你的请求");
	while(Rawstring[resultcur] != '*') resultcur++;
	Rawstring.erase(resultcur,1);
	int needstring = 4;
	string Rawstring2;
	do{
		++needstring;
		Rawstring2 = sendRequest(sock,"GETSTR",token,needstring);
	}while(Rawstring2.length() > 1);
	
	Rawstring.insert(resultcur,"[");
	Rawstring.insert(++resultcur,to_string(needstring));
	Rawstring.insert(resultcur+to_string(needstring).length(),"]");
	sendRequest(sock,"SETSTR",token,4,Rawstring);
	string Rawstring3;
	Rawstring3.push_back('|');
	Rawstring3.insert(Rawstring3.length(),userID);
	sendRequest(sock,"SETSTR",token,needstring,Rawstring3);
	
	PrintInfo("初始化中，请等待...");
	Sleep(1000);
	
	Rawstring = sendRequest(sock,"GETSTR",token,4);
	string goalstring;
	goalstring = userID;
	goalstring.push_back(':');
	goalstring.insert(0,"|");
	size_t findcur = Rawstring.find(goalstring);
	
	while(Rawstring[findcur] != ')') Rawstring.erase(findcur,1);
	Rawstring.erase(findcur,1);
	
	sendRequest(sock,"SETSTR",token,4,Rawstring);
	
	BeStartgame(needstring,PlayerData[num].name);
	//startgame
}
void checkVSrequst(){
	string Rawstring;
	Rawstring = sendRequest(sock,"GETSTR",token,4);
	vector<string> requestList;
	requestList.clear();
	size_t findcur = Rawstring.find(userID);
	int pos = findcur;
	while(findcur != string::npos){
		if(Rawstring[findcur-1] != '(' || Rawstring[findcur + userID.length()] != ')'){
			pos++;
		}
		string goalstring;
		
		while(Rawstring[findcur] != '|') findcur--;
		findcur++;
		
		while(Rawstring[findcur] != ':'){
			goalstring.push_back(Rawstring[findcur]);
			findcur++;
		}
		requestList.push_back(goalstring);
		
		Rawstring.erase(findcur,userID.length());
		findcur = Rawstring.find(userID,pos);
	}
	if(requestList.size() == 0){
		PrintInfo("目前没有收到请求");
		Sleep(1000);
		return;
	}
	cout<<"======请求列表======="<<endl;
	for(int i = 0;i < (int)requestList.size();i++){
		cout<<i<<".    "<<requestList[i]<<endl;
	}
	int num;
	bool numSucessFlag = false;
	while(!numSucessFlag){
		PrintInfo("请输入欲接收的对局请求");
		   cin>>num;
		if(num < 0 || num >= (int)requestList.size()){
			PrintWar("非法的编号，请重新输入");
		} else{
			break;
		}
	}
	Rawstring = sendRequest(sock,"GETSTR",token,4);
	string goalPlayer = requestList[num];
	goalPlayer.insert(0,"|");
	goalPlayer.push_back(':');
	findcur = Rawstring.find(goalPlayer);
	while(Rawstring[findcur] != ')') findcur++;
	Rawstring.insert(findcur,"*");
	sendRequest(sock,"SETSTR",token,4,Rawstring);
	PrintInfo("等待对方响应中");
	
	Sleep(100);//一点反应时间
	Rawstring = sendRequest(sock,"GETSTR",token,4);
	string stringcur;
	while(Rawstring[findcur] != ')'){
		stringcur.push_back(Rawstring[findcur]);
		findcur++;
	}
	Sleep(2000);
	Startgame(atoi(stringcur.c_str()), goalPlayer);
	
}
void PrintMainMenu(){
	cout<<"================================="<<endl;
	cout<<"五子棋 ONLINE 开始菜单           "<<endl;
	cout<<endl;
	cout<<userID<<"，您好"<<endl;
	cout<<endl;
	
	cout<<"1|发起对局请求, 2|查看对局邀请, 3|查看排行榜"<<endl;
	   
	int ops;
	   cin>>ops;
	while(ops < 0 || ops > 3){
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
