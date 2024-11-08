#include<bits/stdc++.h>
#include "data.h"
#include "chient.h"
#include "guide.h"
#include "game.h"
using namespace std;

//凡心所向，素履以往，生如逆旅，一苇以航。
int main(){
	PrintInfo("输入连接IP (输入0使用默认ip)");
	int opt;
	cin>>opt;
	if(opt != 0){
		cin>>serverIP;
	}
	run_chient();
	return 0;
}
