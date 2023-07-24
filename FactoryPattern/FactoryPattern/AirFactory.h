#pragma once
#include "FurnitureFactory.h"
#include "ArtChair.h"
#include "ArtCoffeeTable.h"
#include "ArtSofa.h"

class FurnitureFactory;
class AirFactory : public FurnitureFactory
{
public:
    
    virtual ~AirFactory();
    AirFactory() :FurnitureFactory("AirFactory") {}

	Chair* createChair() ;
	CoffeeTable* createCoffeeTable();
	Sofa* createSofa() ;
private:
    static AirFactory _self;
};

