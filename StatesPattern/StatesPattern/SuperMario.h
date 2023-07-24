#pragma once

#include "MarioState.h"
// ³ÔÄ¢¹½µÄ×´Ì¬
class SuperMario : public MarioState, public Singleton<SuperMario> {
public:
	void GotMushroom(Mario* mario);
	void GotFireFlower(Mario* mario);
	void GotFeather(Mario* mario);
	void GotMonster(Mario* mario);
};