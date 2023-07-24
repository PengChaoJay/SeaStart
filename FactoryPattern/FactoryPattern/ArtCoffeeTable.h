#pragma once
#include "CoffeeTable.h"
#include <iostream>
using namespace std;

class ArtCoffeeTable:public CoffeeTable
{
public:
	ArtCoffeeTable() :CoffeeTable("Art") {}
	virtual ~ArtCoffeeTable() {}

};

