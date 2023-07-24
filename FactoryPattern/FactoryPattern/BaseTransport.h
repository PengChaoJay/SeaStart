#pragma once
#include <iostream>
using namespace std;
#include "BaseFurniture.h"
#include <unordered_map>

//What is the content of transport
class BaseTransport {
public:
    virtual ~BaseTransport() {}
    virtual string Deliver() const = 0;

	void addFurniture(BaseFurniture* Furniture);
	////void subFurniture(const string& FurniturName);
	void showFurniture();
	////setloginstic
	void setLoginstic(BaseTransport* transports);
	//void showLoginstic();
	//void show();
private:
	unordered_map<string, int> furnitures;
	BaseTransport* transports = nullptr;
};

