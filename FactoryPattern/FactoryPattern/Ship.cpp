#include "Ship.h"

Ship::~Ship()
{

}
string Ship::Deliver() const
{
	string result = "SeaTransport : Transport by ship";
	return result;
}