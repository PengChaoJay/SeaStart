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
	void Startup();            //��Ϸ��ֵ��ʼ��
	void Show();               //��Ϸ�������
	void UpdateInput();        //�����뵼�µ���Ϸ״̬����
	void UpdateNormal();       //�������޹ص���Ϸ״̬����
	void HideCursor();         //���ع��
	void gotoxy(int x, int y); //�ص����
	void SetConsoleWindowSize(SHORT w, SHORT h);//���ÿ���̨�Ĵ�С
	void SetConsoleMessage();
	std::string getPlayerName();
	void SetState(int h,int w );
	void SetRandom();

};

