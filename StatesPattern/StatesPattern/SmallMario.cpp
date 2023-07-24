#include "SmallMario.h"
#include "CapeMario.h"
#include "FireMario.h"
#include "SuperMario.h"
#include "DeathMario.h"

void SmallMario::GotMushroom(Mario* mario) {

	mario->SetState(&SuperMario::GetInstance());
	mario->SetCoin(100);
}

void SmallMario::GotFireFlower(Mario* mario) {

	mario->SetState(&FireMario::GetInstance());
	mario->SetCoin(200);
}

void SmallMario::GotFeather(Mario* mario) {
	mario->SetState(&CapeMario::GetInstance());
	mario->SetCoin(200);
}

void SmallMario::GotMonster(Mario* mario) {
	mario->SetState(&DeathMario::GetInstance());
}
