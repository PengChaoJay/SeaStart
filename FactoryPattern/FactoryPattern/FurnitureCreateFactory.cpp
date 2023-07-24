#include "FurnitureCreateFactory.h"
#include "FurnitureFactory.h"


void FurnitureCreateFactory::AddFurnitureFactory(const string& factoryname, FurnitureFactory* furnitureFactory)
{
	furnitureFactorys[factoryname] = furnitureFactory;
}

Chair* FurnitureCreateFactory::createChair(const string& factoryname)
{
	if (furnitureFactorys.find(factoryname) != furnitureFactorys.end())
	{
		return furnitureFactorys[factoryname]->createChair();
	}
	cout << "no factory" << factoryname << endl;
	return nullptr;
	
}
CoffeeTable* FurnitureCreateFactory::createCoffeeTable(const string& factoryname)
{
	if (furnitureFactorys.find(factoryname) != furnitureFactorys.end())
	{
		return furnitureFactorys[factoryname]->createCoffeeTable();
	}
	cout << "no factory" << factoryname << endl;
	return nullptr;
}
Sofa* FurnitureCreateFactory::createSofa(const string& factoryname)
{
	if (furnitureFactorys.find(factoryname) != furnitureFactorys.end())
	{
		return furnitureFactorys[factoryname]->createSofa();
	}
	cout << "no factory" << factoryname << endl;
	return nullptr;
}