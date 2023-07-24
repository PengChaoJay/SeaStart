#include "AirFactory.h"


//init object
AirFactory AirFactory::_self;

AirFactory::~AirFactory() {

}

Chair* AirFactory::createChair() {
    return new ArtChair();
}

CoffeeTable* AirFactory::createCoffeeTable() {
    return new ArtCoffeeTable();
}

Sofa* AirFactory::createSofa()  {
    return new ArtSofa();
}