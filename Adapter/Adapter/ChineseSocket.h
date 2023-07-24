#pragma once
#include<iostream>
#include<string>
using namespace std;

class ChineseSocket
{
private:
	//chinese volt
	int volt;
public:
	ChineseSocket();
	virtual ~ChineseSocket() = default;
	virtual string ChineseInput() const;
	virtual int ChineseVolt();
};

