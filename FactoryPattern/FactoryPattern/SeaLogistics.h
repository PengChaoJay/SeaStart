#pragma once
#include "BaseTransport.h"
#include "Logistics.h"
#include "Ship.h"
class Logistics;
class SeaLogistics : public Logistics
{
public:
    SeaLogistics() :Logistics("SeaLogistics") {}
    virtual ~SeaLogistics();
    BaseTransport* CreateTransport() const;
private:
    static SeaLogistics _self;
};


