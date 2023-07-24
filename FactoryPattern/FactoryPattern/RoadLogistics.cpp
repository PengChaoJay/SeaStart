#include "RoadLogistics.h"

//init object
RoadLogistics RoadLogistics::_self;

RoadLogistics::~RoadLogistics()
{

}
BaseTransport* RoadLogistics::CreateTransport() const
{
    return new Truck();
}
