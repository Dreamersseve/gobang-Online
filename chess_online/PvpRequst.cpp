#include "chient.h"
#include "data.h"
#include "guide.h"
#include "data.h"
#include "game.h"
const int startgetstring = 5;
using namespace std;

void printOnlineList();
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
	int needstring = startgetstring;
	
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

void PvpMatching(){
	system("cls");
	getALLplayerData();
	PrintInfo("正在为你匹配势均力敌的对手...");
	double nowPlayer_winrol = (double)(Nowplayer.win + Nowplayer.lose) / (double)(Nowplayer.win+1);
	PLAYER goalplayer;
	for(int i = 0;i < (int)PlayerData.size();i++){
		double goalPlayer_winrol = (double)(PlayerData[i].win + PlayerData[i].lose) / (double)(PlayerData[i].win+1);
		if(abs(nowPlayer_winrol - goalPlayer_winrol) <= 2){
			goalplayer = PlayerData[i];
			break;
		}
		if(i == (int)PlayerData.size() - 1){
			PrintInfo("目前没有与你实力匹配的对手...");
			return;
		}
	}
	//dosth
}
