#pragma once
#include <iostream>
using namespace std;

class BaseFurniture
{
public:
	BaseFurniture(const string& _name) :name(_name) {}
	virtual ~BaseFurniture();

	void setName(const string& _name);
	string getName() const;

protected:
	string name;
};

