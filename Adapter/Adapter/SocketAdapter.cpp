
#include "SocketAdapter.h"

SocketAdapter::SocketAdapter(shared_ptr<ChineseSocket> socket)
{
	this->socket_c = socket;
}

SocketAdapter::SocketAdapter(shared_ptr<AmericanSocket> socket)
{
	this->socket_a = socket;
}

string SocketAdapter::AmericanInput() const
{
	return this->socket_c->ChineseInput();
}

int SocketAdapter::AmericanVolt()
{
	return this->socket_c->ChineseVolt();
}

string SocketAdapter::ChineseInput() const
{
	return this->socket_a->AmericanInput();
}

int SocketAdapter::ChineseVolt()
{
	return this->socket_a->AmericanVolt();
}
