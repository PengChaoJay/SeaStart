#pragma once
#include<iostream>
#include<string>
using namespace std;

class AmericanSocket
{
private:
	//American volt
	int volt;
public:
	AmericanSocket();
	virtual ~AmericanSocket() = default;
	virtual string AmericanInput() const;
	virtual int AmericanVolt();
};

