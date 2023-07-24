#pragma once
#include "CoffeeTable.h"
#include <iostream>
using namespace std;

class VictorianCoffeeTable : public CoffeeTable
{
public:
	VictorianCoffeeTable() :CoffeeTable("Victorian") {}
	virtual ~VictorianCoffeeTable() {}
};