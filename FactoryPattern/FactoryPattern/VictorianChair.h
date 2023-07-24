#pragma once
#include "Chair.h"
#include <iostream>
using namespace std;

class VictorianChair : public Chair
{
public:
	VictorianChair() :Chair("Victorian") {}
	virtual ~VictorianChair() {}
};
