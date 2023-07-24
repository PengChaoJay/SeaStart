#pragma once
#include <string>
#include "BaseTransport.h"

class Truck:public BaseTransport
{
public:
	virtual ~Truck();
	string Deliver() const override;
};

