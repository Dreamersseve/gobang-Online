#ifndef DATA_H
#define DATA_H

#include<bits/stdc++.h>
#include"chient.h"
using namespace std;

struct PLAYER{
	string name;
	int win,lose;
	bool onlineflag;
	
	bool operator <(const PLAYER x) const{
		return (double)win / (win+lose) > (double)x.win / (x.win + x.lose);
	}
};
void setColor(int color);
void resetColor();
void playerWIN();
void playerFAL();
void PrintInfo(string str);
void PrintWar(string str);
void PrintErr(string str);
extern string userID;
extern PLAYER Nowplayer;
string getPassword(string UID);
bool Can_Be_Username(string UID);
bool Can_Be_Password(string PSW);
int Register();
PLAYER getUserData(string UID,string Rawstring_1 = "",string Rawstring_2 = "");
void printPHB();
int updateData(PLAYER player);
int login();
int logout();
extern vector<PLAYER> PlayerData;
void getALLplayerData();
#endif
