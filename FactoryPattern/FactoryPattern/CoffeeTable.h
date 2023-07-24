#pragma once
#include <iostream>
#include "BaseFurniture.h"
using namespace std;

class CoffeeTable :public BaseFurniture
{
public:
	CoffeeTable(const string& name) :BaseFurniture(name + "CoffeeTable") {}
	virtual ~CoffeeTable() {}
};

