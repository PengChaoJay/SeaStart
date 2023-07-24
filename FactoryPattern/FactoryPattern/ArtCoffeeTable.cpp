#include "ArtCoffeeTable.h"


ArtCoffeeTable::ArtCoffeeTable()
{
    this->name= "ArtCoffeeTable";
}

ArtCoffeeTable::~ArtCoffeeTable()
{

}

string ArtCoffeeTable::getName() const {
    return this->name;
}
