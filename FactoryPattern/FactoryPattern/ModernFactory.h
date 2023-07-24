#pragma once



#include "FurnitureFactory.h"
#include "ModernChair.h"
#include "ModernCoffeeTable.h"
#include "ModernSofa.h"
class FurnitureFactory;

class ModernFactory : public FurnitureFactory
{
public:
    ModernFactory() :FurnitureFactory("ModernFactory") {}
	virtual ~ModernFactory();
	Chair* createChair() ;
	CoffeeTable* createCoffeeTable();
	Sofa* createSofa();
private:
    static ModernFactory _self;
};

