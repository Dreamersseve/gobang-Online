#include"chient.h"
#include<bits/stdc++.h>

using namespace std;
const int MXplayerID = 20;
struct PLAYER{
	string name;
	int win,lose;
	bool onlineflag;
	
	bool operator <(const PLAYER x) const{
		return (double)win / (win+lose) > (double)x.win / (x.win + x.lose);
	}
};
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
string userID;
PLAYER Nowplayer;
string getPassword(string UID){
	string Rawstring = sendRequest(sock, "GETSTR", token, 1);  
	string RawUID = UID;
	RawUID.insert(0,"|");
	RawUID.push_back(':');
	size_t UIDcur = Rawstring.find(RawUID);
	if(UIDcur == std::string::npos){
		PrintErr("UserID不存在");
		return "-1";
	}
	while(Rawstring[UIDcur] != ':') UIDcur++;
	UIDcur++;
	string Password;
	Password.clear();
	while(Rawstring[UIDcur] != '|') Password.push_back(Rawstring[UIDcur++]);
	return Password;
}
bool Can_Be_Username(string UID){
	for(int i = 0;i < (int)UID.length();i++){
		if(!((UID[i] >= 'a' && UID[i] <= 'z') || (UID[i] >= 'A' && UID[i] <= 'Z') || UID[i] == '_')) return false;
	}
	return true;
}
bool Can_Be_Password(string PSW){
	for(int i = 0;i < (int)PSW.length();i++){
		if(!(PSW[i] >= '0' && PSW[i] <= '9')) return false;
	}
	return true;
}
int Register(){
	string Rawstring;
	
	bool IDsucessFlag = false;
	string regID;
	while(!IDsucessFlag){
		PrintInfo("输入注册ID，ID只能由a-z,A-Z,与'_'组成，不可包含数字，且长度在20个字符以内");
		regID.clear();
		 cin>>regID;
		Rawstring = sendRequest(sock, "GETSTR", token, 1); //为了防止注册期间ID被其他人注册，每次都更新一次ID列表
		
		if(regID.length() > MXplayerID){
			PrintInfo("ID长度过长，请重新输入");
		}else if(Rawstring.find(regID) != string::npos && Rawstring[Rawstring.find(regID) - 1] == '|' && Rawstring[Rawstring.find(regID)+ regID.length()] == ':'){
			PrintWar("ID重复，请使用其他ID");
		} else{
			IDsucessFlag = true;
			for(int i = 0;i < (int)regID.length();i++){
				if(!Can_Be_Username(regID)){
					PrintWar("ID中包含非法字符，请重新输入");
					IDsucessFlag = false;
					break;
				}
			}
		}	
	}
	PrintInfo("ID读入成功");//读入后立刻申请账户，防止读入密码时ID被占用
	Rawstring = sendRequest(sock, "GETSTR", token, 1);
	Rawstring.insert(Rawstring.length(),regID);
	Rawstring.insert(Rawstring.length(),":|"); // 暂定密码为空，放置后续申请占用
	int passwordcur = Rawstring.length()-2;
	sendRequest(sock, "SETSTR", token, 1,Rawstring,0);
	string regPSW;
	bool PSWsucessFlag = false;
	while(!PSWsucessFlag){
		PrintInfo("输入密码，密码只能由0-9组成，且长度在20个字符以内");
		regPSW.clear();
		 cin>>regPSW;
		if(regPSW.length() > 20){
			PrintInfo("密码过长，请重新输入");
		}else{
			PSWsucessFlag = true;
			for(int i = 0;i < (int)regPSW.length();i++){
				if(!Can_Be_Password(regPSW)){
					PrintWar("密码中包含非法字符，请重新输入");
					PSWsucessFlag = false;
					break;
				}
			}
		}
	}
	PrintInfo("密码读入成功");
	Rawstring = sendRequest(sock, "GETSTR", token, 1);
	Rawstring.insert(passwordcur+1,regPSW);
	sendRequest(sock, "SETSTR",token,1,Rawstring);
	
	Rawstring = sendRequest(sock, "GETSTR", token, 2);
	Rawstring.insert(Rawstring.length(),regID);
	Rawstring.insert(Rawstring.length(),":0|0|");
	sendRequest(sock, "SETSTR",token,2,Rawstring);
	PrintInfo("注册成功，请重新登录");
	return 0;
}
PLAYER getUserData(string UID){ //请保证UID合法且存在！
	PLAYER ans;
	
	ans.name = UID;
	if(!Can_Be_Username(UID)){
		//PrintErr("非法UID，无法获取数据");
		ans.onlineflag = 0,ans.lose = ans.win = -1;
		return ans;
	}
	string Rawstring;
	Rawstring = sendRequest(sock,"GETSTR",token,2); //2.玩家ID-数据 格式:  ID:赢场数|输场数|
	size_t UIDcur = Rawstring.find(UID);
	
	size_t WINcur = Rawstring.find(":",UIDcur) + 1;
	size_t LOSEcur = Rawstring.find("|",WINcur) + 1;
	size_t ENDcur = Rawstring.find("|",LOSEcur) + 1;
	string WINdata = Rawstring.substr(WINcur,LOSEcur - WINcur - 1);
	string LOSEdata = Rawstring,substr(LOSEcur,ENDcur - LOSEcur - 1);
	
	ans.win = atoi(WINdata.c_str());
	ans.lose = atoi(LOSEdata.c_str());
	Rawstring = sendRequest(sock,"GETSTR",token,3);
	if(Rawstring.find(UID) != string::npos && Rawstring[Rawstring.find(UID) - 1] == '|' && Rawstring[Rawstring.find(UID)+ UID.length()] == '|') ans.onlineflag = true;
	else ans.onlineflag = false;
	
	return ans;
}

int login(){// -1错误 0 成功;
	
	bool UIDsucessFlag = false;
	string needPassword;
	string UID;
	while(!UIDsucessFlag){
		PrintInfo("请输入您的ID");
		cin>>UID;
		if(!Can_Be_Username(UID)){
			continue;
		}
		needPassword = getPassword(UID);
		if(needPassword != "-1") UIDsucessFlag = true;
		else PrintWar("找不到用户，请重新输入");
		Sleep(100);
	}
	bool PSWsuccessFlag = false;
	int choice = 5;
	while(!PSWsuccessFlag){
		choice--;
		PrintInfo("请输入您的密码");
		string PSW;
		cin>>PSW;
		if(!Can_Be_Password(PSW)){
			PrintErr("非法UID");
		}
		else if(PSW == needPassword){
			PrintInfo("密码正确!");
			PSWsuccessFlag = true;
		}
		else{
			if(choice == 0){
				PrintErr("机会用尽，请重启程序以再次登录");
				throw "密码尝试次数过多";
				return -1;
			}
			string showtext = "密码错误，您还剩";
			showtext.insert(showtext.length(),to_string(choice));
			showtext.insert(showtext.length(),"次机会");
			PrintWar(showtext);
		}
	}
	userID = UID;
	PrintInfo("登录成功");
	
	Nowplayer = getUserData(userID);
	string Onlineplayer = sendRequest(sock,"GETSTR",token,3);
	Onlineplayer.push_back('|');
	Onlineplayer.insert(Onlineplayer.length(),UID);
	Onlineplayer.push_back('|');
	sendRequest(sock,"SETSTR",token,3,Onlineplayer);
	return 0;
}
int logout(){
	while(1){
		string Rawstring = sendRequest(sock,"GETSTR",token,3);
		string goalstring = userID;
		goalstring.push_back('|');
		goalstring.insert(0,"|");
		size_t cur = Rawstring.find(goalstring);
		if(cur == string::npos) return 0;
		cur++;
		while(Rawstring[cur] != '|') Rawstring.erase(cur,1);
		Rawstring.erase(cur-1,1),Rawstring.erase(cur-1,1);
		sendRequest(sock,"SETSTR",token,3,Rawstring);
	}
	return 0;
}

vector<PLAYER> PlayerData;
void getALLplayerData(){
	PlayerData.clear();
	string Rawstring;
	string UID;
	Rawstring = sendRequest(sock,"GETSTR",token,1);
	string Onlineplayer = "|";
	for(int i = 0;i < (int)Rawstring.length();i++){
		
		string temp;
		temp.push_back(Rawstring[i]);
		if(Can_Be_Username(temp)){
			UID.push_back(Rawstring[i]);
		} else if(Rawstring[i] == ':'){
			PlayerData.push_back(getUserData(UID));
			if(PlayerData.back().onlineflag){
				Onlineplayer.insert(Onlineplayer.length(),UID);
				Onlineplayer.insert(Onlineplayer.length(),"|");
			}
		} else{
			UID.clear();
		}
	}
	sendRequest(sock, "SETSTR",token,3,Onlineplayer,1);
	
	return;
}
void printPHB(){
	getALLplayerData();
	sort(PlayerData.begin(),PlayerData.end());
	cout<<"排行榜\n";
	cout<<"UID=================|胜====|败====\n";
	for(int i = 0;i < (int)PlayerData.size();i++){
		
		int namelength = MXplayerID;
		cout<<PlayerData[i].name;
		namelength -= PlayerData[i].name.length();
		while(namelength--) cout<<" ";
		
		cout<<"|";
		int intlength = 6;
		string winstr = to_string(PlayerData[i].win);
		cout<<winstr;
		intlength -= winstr.length();
		while(intlength--) cout<<" ";
		
		cout<<"|";
		intlength = 6;
		string losstr = to_string(PlayerData[i].lose);
		cout<<losstr;
		intlength -= losstr.length();
		while(intlength--) cout<<" ";
		cout<<endl;
	}
}
//str2:  |name|0|0|   |名|胜利场数|失败场数|
int updateData(PLAYER player){
	string Rawstring = sendRequest(sock,"GETSTR",token,2);
	string goalplayer = player.name;
	goalplayer.insert(0,"|");
	goalplayer.push_back(':');
	size_t stringcur = Rawstring.find(goalplayer);
	if(stringcur == string::npos){
		return -1;
	}
	stringcur++;
	while(Rawstring[stringcur] != ':'){ // 跳过name
		stringcur++;
	}
	while(Rawstring[stringcur+1] != '|'){//删除原有数据
		Rawstring.erase(stringcur+1,1);
	}
	Rawstring.insert(stringcur+1,to_string(player.win));
	
	
	stringcur += to_string(player.win).length() + 1;
	while(Rawstring[stringcur+1] != '|'){//删除原有数据
		Rawstring.erase(stringcur+1,1);
	}
	Rawstring.insert(stringcur+1,to_string(player.lose));
	
	sendRequest(sock,"SETSTR",token,2,Rawstring);
	return 0;
}
void playerWIN(){
	Sleep(100);
	PLAYER nowplayer = getUserData(userID);
	nowplayer.win++;
	updateData(nowplayer);
}
void playerFAL(){
	PLAYER nowplayer = getUserData(userID);
	nowplayer.lose++;
	updateData(nowplayer);
}



