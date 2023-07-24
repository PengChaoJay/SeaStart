#pragma once
#include <string>
#include "BaseTransport.h"

class Air:public BaseTransport
{
public:
	virtual ~Air();
	string Deliver() const override;
};

