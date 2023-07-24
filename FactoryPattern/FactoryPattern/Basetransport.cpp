
#include "BaseTransport.h"

void BaseTransport::addFurniture(BaseFurniture* Furniture)
{
	furnitures[Furniture->getName()]++;
}
void BaseTransport::showFurniture()
{
	cout << "The items in the order are£º" << endl;
	for (auto furniture : furnitures)
	{
		cout << "\t " << furniture.first << "\t " << "the nums " << furniture.second << endl;
	}
}

void BaseTransport::setLoginstic(BaseTransport* transports)
{

}