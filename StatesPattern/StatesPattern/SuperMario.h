#pragma once

#include "MarioState.h"
// ��Ģ����״̬
class SuperMario : public MarioState, public Singleton<SuperMario> {
public:
	void GotMushroom(Mario* mario);
	void GotFireFlower(Mario* mario);
	void GotFeather(Mario* mario);
	void GotMonster(Mario* mario);
};