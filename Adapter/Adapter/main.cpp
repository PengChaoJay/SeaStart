#include <iostream>
#include<memory>
#include"AmericanSocket.h"
#include"ChineseSocket.h"
#include"SocketAdapter.h"
using namespace std;

void UseAmericanPlug(shared_ptr<AmericanSocket> socket) {
	cout << "Its American Plug" << endl;
	cout << socket->AmericanInput() << socket->AmericanVolt() << endl;
}
void UseChinesePlug(shared_ptr<ChineseSocket> socket) {
	cout << "Its Chinese Plug" << endl;
	cout << socket->ChineseInput() << socket->ChineseVolt() << endl;
}
int main()
{
	shared_ptr<AmericanSocket> americanSocket = make_shared<AmericanSocket>();
	UseAmericanPlug(americanSocket);

	shared_ptr<SocketAdapter> americanSocketAdapter = make_shared<SocketAdapter>(americanSocket);
	UseChinesePlug(americanSocketAdapter);


	shared_ptr<ChineseSocket> chineseSocket = make_shared<ChineseSocket>();
	UseChinesePlug(chineseSocket);

	shared_ptr<SocketAdapter> chineseSocketAdapter = make_shared<SocketAdapter>(chineseSocket);
	UseAmericanPlug(chineseSocketAdapter);

	return 0;
}
