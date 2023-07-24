#include "LogisticsCreateFactory.h"
#include "Logistics.h"


void LogisticsCreateFactory::AddTransportFactory(const string& logisticsname, Logistics* logisticsfactory)
{
	LogisticsFactorys[logisticsname] = logisticsfactory;

}
BaseTransport* LogisticsCreateFactory::CreateTransport(const string& logisticsname)
{
	if (LogisticsFactorys.find(logisticsname)!=LogisticsFactorys.end())
	{
		return LogisticsFactorys[logisticsname]->CreateTransport();
	}
	cout << "no the " << logisticsname << endl;
	return nullptr;
	
}