#pragma once
// ·ÉÐÐµÄ×´Ì¬
#include "MarioState.h"

class CapeMario : public MarioState, public Singleton<CapeMario> {
public:
	void GotMushroom(Mario* mario);
	void GotFireFlower(Mario* mario);
	void GotFeather(Mario* mario);
	void GotMonster(Mario* mario);

};
