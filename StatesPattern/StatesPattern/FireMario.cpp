#include "FireMario.h"
#include "CapeMario.h"
#include "SuperMario.h"


void FireMario::GotMushroom(Mario* mario) {
	mario->SetCoin(100);

}

void FireMario::GotFireFlower(Mario* mario) {
	mario->SetCoin(100);
}

void FireMario::GotFeather(Mario* mario) {
	mario->SetState(&CapeMario::GetInstance());
	mario->SetCoin(100);
}

void FireMario::GotMonster(Mario* mario) {
	mario->SetState(&SuperMario::GetInstance());
}
