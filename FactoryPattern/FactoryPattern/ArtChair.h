#pragma once
#include "Chair.h"
#include <iostream>
using namespace std;
class ArtChair : public Chair
{
public:
	ArtChair():Chair("Art") {}
	virtual ~ArtChair() {}
};

