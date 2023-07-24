#pragma once
#include "BaseTransport.h"
#include "Logistics.h"
#include "Air.h"


class AirLogistics : public Logistics 
{
public:
    AirLogistics() :Logistics("AirLogistics") {}
    virtual ~AirLogistics();
    BaseTransport* CreateTransport() const;
private:
    static AirLogistics _self;
};

