#include "GameUI.h"
#include "SmallMario.h"
#include "CapeMario.h"
#include "FireMario.h"
#include "SuperMario.h"

int canvas[high + 2][width + 2]; //game map high width
int pos_h, pos_w;                //player position
int wormsnum;                    //create worm number
int interval;				
int itv_move;                    //移动的时间间隔
int itv_new;                     //worms flush time
int IsOver;                      //判断游戏是否结束

//show Mario some Messsage
void GameUI::SetConsoleMessage()
{
	gotoxy((width + 3) * 2, 3);
	std::cout<<"金币："<<mario->GetCoin();
	gotoxy((width + 3) * 2, 5);
	std::cout << "马里奥状态: " << mario->getStateName();

	int hightV = 2;
	gotoxy((width + 3) * 2, (high / 3) + hightV);
	std::cout<<"控制信息：";
	gotoxy((width + 3) * 2 + 2, (high / 3) + hightV + 1);
	std::cout<<"\t\tW";
	gotoxy((width + 3) * 2 - 2, (high / 3) + hightV + 2);
	std::cout<<"\t    A";
	gotoxy((width + 3) * 2 + 4, (high / 3) + hightV + 2);
	std::cout<<"\t    D";
	gotoxy((width + 3) * 2 + 2, (high / 3) + hightV + 3);
	std::cout<<"\t\tS";

	gotoxy((width + 3) * 2, (high / 3) + hightV + 4);
	std::cout<<"   道具\t 获得金币数";
	gotoxy((width + 3) * 2, (high / 3) + hightV + 5);
	std::cout<<" 金：金币\t    100";
	gotoxy((width + 3) * 2, (high / 3) + hightV + 6);
	std::cout<<" 菇：蘑菇\t    100";
	gotoxy((width + 3) * 2, (high / 3) + hightV + 7);
	std::cout<<" 花：花朵\t    100";
	gotoxy((width + 3) * 2, (high / 3) + hightV + 8);
	std::cout<<" 羽：羽毛\t    100";
	gotoxy((width + 3) * 2, (high / 3) + hightV + 9);
	std::cout<<" 虫：虫子\t    10";

	gotoxy((width + 3) * 2, (high / 3) + hightV + 11);
	std::cout<<"字符代表\t  马里奥";
	gotoxy((width + 3) * 2, (high / 3) + hightV + 12);
	std::cout<<" 小        Small Mario";
	gotoxy((width + 3) * 2, (high / 3) + hightV + 13);
	std::cout<<" 大        Super Mario";
	gotoxy((width + 3) * 2, (high / 3) + hightV + 14);
	std::cout<<" 火        Fire Mario";
	gotoxy((width + 3) * 2, (high / 3) + hightV + 15);
	std::cout<<" 飞        Cape Mario";
	gotoxy((width + 3) * 2, (high / 3) + hightV + 16);
	std::cout<<" 死        Death Mario";
	gotoxy((width + 3) * 2, high);
	HideCursor();
}


// change the mario state
std::string GameUI::getPlayerName()
{
	if ("SmallMario" == mario->getStateName())
	{
		return "小";
	}
	else if("SuperMario" == mario->getStateName()) {

		return "大";

	}else if ("FireMario"== mario->getStateName())
    {  
		return "火";

	}else if("CapeMario" == mario->getStateName()) {
		return "飞";
	}
	else {
		return "死";
	}
}
// game start
void GameUI::Startup()
{
	SetConsoleWindowSize(W_width, W_high);
	system("mode con cols=110 lines=30");
	init(); //
	while (IsOver)
	{ 
		UpdateInput();
		UpdateNormal();
		Show();
	}
	//printf("\t\tgame over!\n");
	Sleep(2500); //暂停游戏结束界面（毫秒）
	system("pause");
}

void GameUI::init()
{
	IsOver = 1;
	for (int i = 0; i < high + 2; i++)
	{ //init GUI
		for (int j = 0; j < width + 2; j++)
		{
			if ((i == 0 || i == high + 1) ||
				(j == 0 || j == width + 1))
			{
				canvas[i][j] = border;
			}
			else
				canvas[i][j] = blank;
		}
	}

	pos_h = high / 2;             //init the player pos_h
	pos_w = width / 2;            //init the player pos_w
	canvas[pos_h][pos_w] = player; //
	wormsnum = 3;                 //the worm

	srand((unsigned)time(NULL));
	interval = 4; //初始化时间间隔计数
	itv_move = 10; //初始化敌机移动时间间隔
	itv_new = 40; //初始化敌机刷新时间间隔
}



void GameUI::Show()
{                
	HideCursor(); 
	gotoxy(1, 1); //flush screen
	for (int i = 0; i < high + 2; i++)
	{
		for (int j = 0; j < width + 2; j++)
		{
			if (canvas[i][j] == player)
			{ 
				std::cout<<getPlayerName();
			}
			else if (canvas[i][j] == bullet)
			{ 
				std::cout<<"哒";
			}
			else if (canvas[i][j] == worms)
			{ 
				std::cout<<"虫";
			}
			else if (canvas[i][j] == border)
			{ 
				std::cout<<"墙";
			}
			else if (canvas[i][j] == blank)
			{
				std::cout<<"  ";
			}
			else if (canvas[i][j] == destroy)
			{
				std::cout<<"死";
			}else if (canvas[i][j] == mushroom )
			{
				std::cout << "菇";
			}
			else if (canvas[i][j] == conins)
			{
				std::cout << "金";
			}else if (canvas[i][j] == flowers)
			{
				std::cout << "花";
			}
			else if (canvas[i][j] == feather)
			{
				std::cout << "羽";
			}

			if (j == width + 1)
			{
				if ((i == 0 || i == high + 1) || i == high / 3)
				{
					for (int k = 0; k < W_width / 2 - width - 2; k++)
					{
						std::cout<<"墙";
					}
				}
				if (i != 0)
				{
					gotoxy(W_width - 1, i);
					std::cout<<"墙";
				}
			}
		}
		std::cout<<std::endl;
	}
	SetConsoleMessage();
}

void GameUI::SetState(int h, int w)
{
	//eat flower
	if (canvas[h][w] == conins)
	{
		mario->SetCoin(100);
	}
	if (canvas[h][w] == flowers)
	{
		mario->GotFireFlower();
	}
	//eat feather
	else if (canvas[h][w] == feather)
	{
		mario->GotFeather();
	}
	//eat mushroom
	else if (canvas[h][w] == mushroom)
	{
		mario->GotMushroom();
	}
	else if (canvas[h][w] == worms)
	{
		if ("SmallMario" == mario->getStateName())
		{
			canvas[pos_h][pos_w] = destroy;
			IsOver = 0;
		}
		mario->GotMonster();
	}
		canvas[h][w] = player;
}


void GameUI::SetRandom()
{
	//add worm and  props
// The time interval
	if (interval % itv_new == 0)
	{
		for (int i = 0; i < wormsnum; i++)
		{ //add worm
			canvas[rand() % 2 + 1][rand() % width + 1] = worms;
		}
		for (int i = 0; i < 1; i++)
		{ //add props
			canvas[rand() % 2 + 1][rand() % width + 1] = flowers;
			canvas[rand() % 2 + 1][rand() % width + 1] = feather;
			canvas[rand() % 2 + 1][rand() % width + 1] = mushroom;
			canvas[rand() % 2 + 1][rand() % width + 1] = conins;
		}
	}
	if (interval <= 10000)
	{
		interval++;
	}
	else
	{
		interval = 0;
	}
}

void GameUI::UpdateInput()
{                                     
	short key_W = GetKeyState('W'),    
		key_S = GetKeyState('S'),      
		key_A = GetKeyState('A'),      
		key_D = GetKeyState('D'),      
		key_attack = GetKeyState(' '); 
	if (_kbhit())
	{ 
		if (key_W < 0)
		{ 
			if (pos_h > 1)
			{
				canvas[pos_h][pos_w] = blank;
				SetState(--pos_h, pos_w);
			}
		}
		if (key_S < 0)
		{ 
			if (pos_h < high)
			{
				canvas[pos_h][pos_w] = blank;
				SetState( ++pos_h, pos_w);
			}
		}
		if (key_A < 0)
		{ 
			if ( pos_w >1)
			{
				canvas[pos_h][pos_w] = blank;
				SetState(pos_h,--pos_w);
			}
		}
		if (key_D < 0)
		{ 
			if (pos_w < width)
			{ 
				canvas[pos_h][pos_w] = blank;
				SetState(pos_h,++pos_w);
				
			}
		}
		if (key_attack < 0)
		{ 
			if ("FireMario"==mario->getStateName())
			{
				if (pos_h > 1 && pos_w <= width)
					canvas[pos_h - 1][pos_w] = bullet;
			}
		}
	}
}
// updataNormal
void  GameUI::UpdateNormal()
{                                  //update the screen
	int temp[high + 2][width + 2]; //save the original array
	for (int i = 1; i <= high; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			temp[i][j] = canvas[i][j];
		}
	}
	//Iterate through the temporary array to modify the canvas
	for (int i = 1; i <= high; i++)
	{ 
		for (int j = 1; j <= width; j++)
		{
			if (temp[i][j] == worms && interval % itv_move == 0)
			{ //worms current position  
				canvas[i][j] = blank;
				if (temp[i + 1][j] == bullet)
				{ //worms is bulleted 
					canvas[i + 1][j] = blank;
					mario->SetCoin(10);
					std::cout<<"\a";
				}else if (i < high)
				{
					canvas[i + 1][j] = worms;
				}

				if (i + 1 == pos_h && j == pos_w)
				{ 
					if ("SmallMario" ==mario->getStateName())
					{
						canvas[i + 1][j] = destroy;
						IsOver = 0;
						mario->getStateName();
					}
					else
					{
						canvas[i + 1][j] = blank;
						mario->GotMonster();
						canvas[i + 1][j] = player;
					}
				}
			}
			else if(temp[i][j] == mushroom && interval % itv_move == 0)
			{
				canvas[i][j] = blank;
				if (i < high)
				{
					canvas[i + 1][j] = mushroom;
				}
				if (i + 1 == pos_h && j == pos_w)
				{ 
					canvas[i + 1][j] = mushroom;
					mario->GotMushroom();
					canvas[i + 1][j] = player;
				}
			}
			else if (temp[i][j] == flowers && interval % itv_move == 0)
			{
				canvas[i][j] = blank;
				if (i < high)
				{
					canvas[i + 1][j] = flowers;
				}
				if (i + 1 == pos_h && j == pos_w)
				{ 
					canvas[i + 1][j] = flowers;
					mario->GotFireFlower();
					canvas[i + 1][j] = player;
				}
			}else if (temp[i][j] == feather && interval % itv_move == 0)
			{
				canvas[i][j] = blank;
				if (i < high)
				{
					canvas[i + 1][j] = feather;
				}
				if (i + 1 == pos_h && j == pos_w)
				{ 
					canvas[i + 1][j] = feather;
					mario->GotFeather();
					canvas[i + 1][j] = player;
				}
			}
			else if (temp[i][j] == conins && interval % itv_move == 0)
			{
				canvas[i][j] = blank;
				if (i < high)
				{
					canvas[i + 1][j] = conins;
				}
				if (i + 1 == pos_h && j == pos_w)
				{ 
					canvas[i + 1][j] = feather;
					mario->SetCoin(100);
					canvas[i + 1][j] = player;
				}
			}
			if (temp[i][j] == bullet)
			{ 
				//attack the worms 
				canvas[i][j] = blank;
				if (temp[i - 1][j] == worms)
				{ 
					canvas[i - 1][j] = blank;
					mario->SetCoin(10);
					std::cout<<"\a";
				}
				else if (temp[i - 1][j] !=blank)
				{
					
				}
				else if (i > 1)
				{
					canvas[i - 1][j] = bullet;
				}
				
			}
		}
	}
	SetRandom();
}

//git cursor position
void GameUI::gotoxy(int x, int y)
{ 
	COORD pos;
	pos.X = x - 1;
	pos.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// hide cursor
void GameUI::HideCursor()
{ 
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);	
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

//set windows size
void GameUI::SetConsoleWindowSize(SHORT w, SHORT h)
{
	HANDLE hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT wrt = { 0, 0, w - 1, h - 1 };
	SetConsoleWindowInfo(hStdOutput, TRUE, &wrt);
	COORD coord = { w, h };
	SetConsoleScreenBufferSize(hStdOutput, coord);
}
