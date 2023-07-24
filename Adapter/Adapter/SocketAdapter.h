#pragma once
#include<memory>
#include "AmericanSocket.h"
#include"ChineseSocket.h"
using namespace std;

class SocketAdapter :
	public AmericanSocket, public ChineseSocket
{
private:
	shared_ptr<ChineseSocket> socket_c;
	shared_ptr<AmericanSocket> socket_a;

public:
	SocketAdapter(shared_ptr<ChineseSocket> socket);
	SocketAdapter(shared_ptr<AmericanSocket> socket);
	string AmericanInput() const override;
	int AmericanVolt() override;
	string ChineseInput() const override;
	int ChineseVolt() override;
};
