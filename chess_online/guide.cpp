#include<bits/stdc++.h>

#include"IO.h"
#include"data.h"
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
	printWelcome();
	cout<<"================================="<<endl;
	cout<<"五子棋 ONLINE 开始菜单           "<<endl;
	cout<<"                                 "<<endl;
	printPHB();
	cout<<"================================="<<endl<<endl;
	while(1){
		PrintInfo("请登录/注册 (0/1)");
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
		else PrintErr("不合法的输入");
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
		PrintInfo("请输入发起请求玩家编号");
		cin>>num;
		if(num < 0 || num >= (int)PlayerData.size()){
			PrintWar("非法的编号，请重新输入");
		} else if(PlayerData[num].onlineflag == false){
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
	while(1){
		Rawstring = sendRequest(sock,"GETSTR",token,4);
		string findstring = PlayerData[num].name;
		findstring.push_back('*');
		size_t resultcur = Rawstring.find(findstring);
		if(resultcur == string::npos) continue;
		if(Rawstring[resultcur - 1] == '(' && Rawstring[resultcur + findstring.length()] == ')'){
			break;
		}
		Sleep(5000);
	}
	PrintInfo("对方接受了你的请求");
	//startgame
}
void checkVSrequst(){
	string Rawstring;
	Rawstring = sendRequest(sock,"GETSTR",token,4);
	vector<string> requestList;
	requestList.clear();
	size_t findcur = Rawstring.find(userID);
	while(findcur != string::npos && Rawstring[findcur-1] == '(' && Rawstring[findcur + userID.length()] == ')'){
		
		string goalstring;
		
		while(Rawstring[findcur] != ':') findcur--;
		findcur++;
		
		while(Rawstring[findcur] != '(') goalstring.push_back(Rawstring[findcur]);
		goalstring.pop_back();
		requestList.push_back(goalstring);
		
		Rawstring.erase(findcur,userID.length());
		findcur = Rawstring.find(userID);
	}
	if(requestList.size() == 0){
		PrintInfo("目前没有收到请求");
		return;
	}
	for(int i = 0;i < (int)requestList.size();i++){
		cout<<i<<".    "<<requestList[i]<<endl;
	}
	PrintInfo("请输入欲接收的对局请求");
	int num;
	cin>>num;
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
	string goalPlayer = requestList[num];
	
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
}
