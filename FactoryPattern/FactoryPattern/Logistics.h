#pragma once

#include "LogisticsCreateFactory.h"

class Logistics
{
public:
    virtual ~Logistics() {}
    virtual BaseTransport* CreateTransport() const = 0;

    Logistics(const string& logisticsName) :_LogisticsName(logisticsName)
    {
        LogisticsCreateFactory::GetInstance().AddTransportFactory(logisticsName,this);
    }
private:
    string _LogisticsName;
};

