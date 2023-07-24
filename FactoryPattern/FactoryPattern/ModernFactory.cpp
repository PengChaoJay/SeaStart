#include "ModernFactory.h"

//init object
ModernFactory ModernFactory::_self;

ModernFactory::~ModernFactory() {

}

Chair* ModernFactory::createChair(){
    return new ModernChair();
}
CoffeeTable* ModernFactory::createCoffeeTable(){
    return new ModernCoffeeTable();
}
Sofa* ModernFactory::createSofa() {
    return new ModernSofa();
}
