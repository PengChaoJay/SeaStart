#include "AirLogistics.h"

//init object
AirLogistics AirLogistics::_self;

AirLogistics::~AirLogistics()
{

}
BaseTransport* AirLogistics::CreateTransport() const
{
    return new Air();
}