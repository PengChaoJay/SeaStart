#pragma once
#include "Chair.h"
#include <iostream>
using namespace std;
class ModernChair : public Chair
{
public:
	ModernChair() :Chair("Modern") {}
	virtual ~ModernChair() {}

};