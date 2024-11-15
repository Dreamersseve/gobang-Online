#ifndef IO_H
#define IO_H
#include<bits/stdc++.h>
void setColor(int color);

void resetColor();

void PrintInfo(std::string str);
void PrintWar(std::string str);
void PrintErr(std::string str);
std::string GetString(std::string prefix = "",std::string suffix = "");

#endif
