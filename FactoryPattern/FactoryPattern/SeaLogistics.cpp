#include "SeaLogistics.h"

SeaLogistics SeaLogistics::_self;

SeaLogistics::~SeaLogistics()
{

}

BaseTransport* SeaLogistics::CreateTransport() const
{
    return new Ship();
}

