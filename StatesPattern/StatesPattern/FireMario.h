#pragma once

#include "MarioState.h"

// ³Ô»¨µÄ×´Ì¬
class FireMario : public MarioState, public Singleton<FireMario> {
public:
	void GotMushroom(Mario* mario);
	void GotFireFlower(Mario* mario);
	void GotFeather(Mario* mario);
	void GotMonster(Mario* mario);
};
