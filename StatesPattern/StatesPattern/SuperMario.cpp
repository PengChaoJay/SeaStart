#include "SuperMario.h"
#include "CapeMario.h"
#include "SmallMario.h"
#include "FireMario.h"

void SuperMario::GotMushroom(Mario* mario) {
	mario->SetCoin(100);
}

void SuperMario::GotFireFlower(Mario* mario) {
	mario->SetState(&FireMario::GetInstance());
	mario->SetCoin(100);
}

void SuperMario::GotFeather(Mario* mario) {
	mario->SetState(&CapeMario::GetInstance());
	mario->SetCoin(100);
}

void SuperMario::GotMonster(Mario* mario) {
	mario->SetState(&SmallMario::GetInstance());
}
