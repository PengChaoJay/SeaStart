#pragma once
#include <string>
#include "BaseTransport.h"

class Ship:public BaseTransport
{
public:
	virtual ~Ship();
	string Deliver() const override;
};

