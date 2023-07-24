#pragma once
#include "MarioState.h"
class SmallMario : public MarioState, public Singleton<SmallMario> {
public:
	void GotMushroom(Mario* mario);
	void GotFireFlower(Mario* mario);
	void GotFeather(Mario* mario);
	void GotMonster(Mario* mario);
};