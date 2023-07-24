#pragma once
#include <iostream>
#include <unordered_map>
#include "Singleton.h"

using namespace std;

class Chair;
class CoffeeTable;
class Sofa;
class FurnitureFactory;

class FurnitureCreateFactory:public Singleton<FurnitureCreateFactory>
{
public:

	void AddFurnitureFactory(const string& factoryname, FurnitureFactory* furnitureFactory);
	Chair* createChair(const string& factoryname);
	CoffeeTable* createCoffeeTable(const string& factoryname);
	Sofa* createSofa(const string& factoryname);

//private:
	FurnitureCreateFactory() = default;

	unordered_map<string,FurnitureFactory*> furnitureFactorys;
};

