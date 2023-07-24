
#include <iostream>
#include "GameUI.h"
#include <iostream>
using namespace std;
int main()
{
	std::unique_ptr<GameUI> game(new GameUI());
	game->Startup();
}