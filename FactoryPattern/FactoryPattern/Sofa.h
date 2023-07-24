#pragma once

#include <iostream>
#include "BaseFurniture.h"
using namespace std;

class Sofa :public BaseFurniture
{
public:
	Sofa(const string& name) :BaseFurniture(name + "Sofa") {}
	virtual ~Sofa() {}
};