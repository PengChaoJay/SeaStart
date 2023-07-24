#pragma once
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Mario.h"
#include "Singleton.h"
#include <windows.h>
#include <iostream>

//set Windows size
#define W_width 110
#define W_high   30
//set canvas size
#define high 28   //canvas high
#define width 40 //canvas width
#define border -1 //canvas border
#define blank 0   //canvas black area
#define player 1   //player
#define bullet 2  // bullet
#define worms 3   // worm
#define destroy 4 //destrory worm
#define mushroom 5 //mushroom
#define conins 6  //coins
#define flowers 7 //flowers
#define feather 8 //feather

using namespace std;
class GameUI:public Singleton<GameUI>
{
private:
	std::unique_ptr<Mario> mario= make_unique<Mario>();
public:
	void init();
	void Startup();            //游戏数值初始化
	void Show();               //游戏界面输出
	void UpdateInput();        //因输入导致的游戏状态更新
	void UpdateNormal();       //与输入无关的游戏状态更新
	void HideCursor();         //隐藏光标
	void gotoxy(int x, int y); //回调光标
	void SetConsoleWindowSize(SHORT w, SHORT h);//设置控制台的大小
	void SetConsoleMessage();
	std::string getPlayerName();
	void SetState(int h,int w );
	void SetRandom();

};

