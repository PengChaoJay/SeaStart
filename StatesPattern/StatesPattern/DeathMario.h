#pragma once
#include "MarioState.h"
class DeathMario: public MarioState, public Singleton<DeathMario>
{
public:
	void GotMushroom(Mario* mario) {};
	void GotFireFlower(Mario* mario) {};
	void GotFeather(Mario* mario) {};
	void GotMonster(Mario* mario) {};

};

