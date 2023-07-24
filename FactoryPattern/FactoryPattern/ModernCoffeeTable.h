#pragma once
#include "CoffeeTable.h"
#include <iostream>
using namespace std;

class ModernCoffeeTable : public CoffeeTable
{
public:
	ModernCoffeeTable() : CoffeeTable("Modern") {}
	virtual ~ModernCoffeeTable() {}
};