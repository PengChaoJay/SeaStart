#pragma once
#include <iostream>
#include "BaseFurniture.h"
using namespace std;

class Chair :public BaseFurniture
{
public:
	Chair(const string& name) :BaseFurniture(name+"Chair") {}
	virtual ~Chair() {}
};

