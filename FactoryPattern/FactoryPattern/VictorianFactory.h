#pragma once

#include "FurnitureFactory.h"
#include "VictorianChair.h"
#include "VictorianCoffeeTable.h"
#include "VictorianSofa.h"

class FurnitureFactory;

class VictorianFactory : public FurnitureFactory
{
public:
    virtual ~VictorianFactory();
    VictorianFactory() :FurnitureFactory("VictorianFactory") {}
	Chair* createChair() ;
	CoffeeTable* createCoffeeTable();
	Sofa* createSofa();

private:
    static VictorianFactory _self;
};

