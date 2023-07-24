#pragma once

#include "Sofa.h"
#include <iostream>
using namespace std;


class ArtSofa :public Sofa
{
public:
	ArtSofa() :Sofa("Art") {}
	virtual ~ArtSofa() {}

};

