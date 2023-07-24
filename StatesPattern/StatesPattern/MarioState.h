#pragma once
#include "Mario.h"
#include <string>
#include "Singleton.h"
#include < fstream >
#include <iostream>
using namespace std;
class Mario;

class MarioState {
public:
	virtual void GotMushroom(Mario* mario) = 0;
	virtual void GotFireFlower(Mario* mario) = 0;
	virtual void GotFeather(Mario* mario) = 0;
	virtual void GotMonster(Mario* mario) = 0;

};