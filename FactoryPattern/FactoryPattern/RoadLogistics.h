#pragma once

#include "Truck.h"
#include "Logistics.h"

class RoadLogistics : public Logistics
{
public:
    RoadLogistics() :Logistics("RoadLogistics") {}
    virtual ~RoadLogistics();
    BaseTransport* CreateTransport() const;
private:
    static RoadLogistics _self;
};

