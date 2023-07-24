#pragma once
#include <iostream>
#include "FurnitureCreateFactory.h"

using namespace std;

class FurnitureCreateFactory;

class FurnitureFactory
{
public:
    virtual ~FurnitureFactory() {};

    FurnitureFactory(const string furnitureFactoryName) :_furnitrueFactoryName(furnitureFactoryName)
    {
        Singleton<FurnitureCreateFactory>::GetInstance().AddFurnitureFactory(furnitureFactoryName,this);
    }

public:
    virtual Chair* createChair() = 0;
    virtual CoffeeTable* createCoffeeTable() = 0;
    virtual Sofa* createSofa()= 0;
private:
    string _furnitrueFactoryName;
};

