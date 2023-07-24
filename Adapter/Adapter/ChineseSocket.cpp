#include "ChineseSocket.h"

ChineseSocket::ChineseSocket()
{
	this->volt = 220;
}

string ChineseSocket::ChineseInput() const
{
	return "Input Chinese Standard Socket.";
}

int ChineseSocket::ChineseVolt()
{
	return this->volt;
}
