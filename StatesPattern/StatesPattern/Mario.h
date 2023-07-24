#pragma once
#include "MarioState.h"
#include <iostream>
#include <unordered_map>
using namespace std;

class MarioState;


class Mario {
private:
	MarioState* state;
	int coin;
	string name_;
	unordered_map<MarioState*, string> marioStateName;

public:
	Mario();
	void init();
	void SetState(MarioState* state);
	MarioState* getState();

	// get mario name
	string getStateName();

public:
	void SetCoin(int numberOfCoins);
	int  GetCoin();

public:
	void GotMushroom();
	void GotFireFlower();
	void GotFeather();
	void GotMonster();

};