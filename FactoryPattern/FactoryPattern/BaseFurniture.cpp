#include "BaseFurniture.h"


BaseFurniture::~BaseFurniture() 
{
}
void BaseFurniture::setName(const string& _name)
{
	this->name = _name;
}

 string BaseFurniture::getName() const
{
	 return this->name;
}
