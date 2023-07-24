#include "Mario.h"
#include "SmallMario.h"
#include "FireMario.h"
#include "SuperMario.h"
#include "DeathMario.h"
#include "CapeMario.h"

Mario::Mario() {
	coin = 0;
	this->state = &SmallMario::GetInstance();
	init();
}
void Mario::init()
{
	this->marioStateName.insert(pair<MarioState*, string>(&SmallMario::GetInstance(),"SmallMario"));
	this->marioStateName.insert(pair<MarioState*, string>(&SuperMario::GetInstance(), "SuperMario"));
	this->marioStateName.insert(pair<MarioState*, string>(&FireMario::GetInstance(), "FireMario"));
	this->marioStateName.insert(pair<MarioState*, string>(&CapeMario::GetInstance(), "CapeMario"));
	this->marioStateName.insert(pair<MarioState*, string>(&DeathMario::GetInstance(), "DeathMario"));

}

void Mario::SetState(MarioState* state) {
	this->state = state;
}

MarioState* Mario::getState()
{
	return this->state;
}

std::string Mario::getStateName()
{
	return this->marioStateName[this->getState()];
}

int Mario::GetCoin() {
	return this->coin;
}


void Mario::SetCoin(int numberOfCoins) {
	coin += numberOfCoins;
}


void Mario::GotMushroom() {
	this->state->GotMushroom(this);
};

void Mario::GotFireFlower() {
	this->state->GotFireFlower(this);
};


void Mario::GotFeather() {
	this->state->GotFeather(this);
};


void Mario::GotMonster() {
	this->state->GotMonster(this);
};
