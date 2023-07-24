#pragma once
#include "Sofa.h"
#include <iostream>
using namespace std;

class ModernSofa :public Sofa
{
public:
	ModernSofa() :Sofa("Modern") {}
	virtual ~ModernSofa() {}

};
