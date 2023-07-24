#include "VictorianFactory.h"

VictorianFactory VictorianFactory::_self;

VictorianFactory::~VictorianFactory()
{
}
Chair* VictorianFactory::createChair(){
    return new VictorianChair();
}

CoffeeTable* VictorianFactory::createCoffeeTable() {
    return new VictorianCoffeeTable();
}

Sofa* VictorianFactory::createSofa(){
    return new VictorianSofa();
}
