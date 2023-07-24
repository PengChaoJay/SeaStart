#pragma once
#include <iostream>

#include "Singleton.h"
#include <unordered_map>

using namespace std;
class Logistics;
class BaseTransport;

//Use Singleton Template 
class LogisticsCreateFactory:public Singleton<LogisticsCreateFactory>
{
	friend class Singleton<LogisticsCreateFactory>;
public:
	void AddTransportFactory(const string & logisticsname, Logistics* logisticsfactory);
	BaseTransport* CreateTransport(const string & logisticsname);

private:
	LogisticsCreateFactory() = default;
	unordered_map<string, Logistics*> LogisticsFactorys;
};

