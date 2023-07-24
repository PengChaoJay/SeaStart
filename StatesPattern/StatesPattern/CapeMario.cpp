#include "CapeMario.h"
#include "FireMario.h"
#include "SmallMario.h"

//CapeMario
void CapeMario::GotMushroom(Mario* mario) {
	mario->SetCoin(100);
}

void CapeMario::GotFireFlower(Mario* mario) {
	mario->SetState(&FireMario::GetInstance());

	mario->SetCoin(100);
}

void CapeMario::GotFeather(Mario* mario) {
	mario->SetCoin(100);
}

void CapeMario::GotMonster(Mario* mario) {
	mario->SetState(&SmallMario::GetInstance());
}
