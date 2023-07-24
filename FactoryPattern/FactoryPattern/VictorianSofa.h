#pragma once
#include "Sofa.h"
#include <iostream>
using namespace std;

class VictorianSofa :public Sofa
{
public:
	VictorianSofa() :Sofa("Victorian") {}
	virtual ~VictorianSofa() {}
};

