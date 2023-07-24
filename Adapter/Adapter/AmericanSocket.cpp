#include "AmericanSocket.h"

AmericanSocket::AmericanSocket()
{
	this->volt = 110;
}

string AmericanSocket::AmericanInput() const
{
	return "Input American Standard Socket.";
}

int AmericanSocket::AmericanVolt()
{
	return this->volt;
}
