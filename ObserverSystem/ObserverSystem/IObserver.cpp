#include "IObserver.h"


Observer::Observer(IPublisher* subject, int number)
{
	this->subject_ = subject;
	this->number_ = number;

}

Observer::~Observer()
{

}

void Observer::Update(const string& message) {

}
void Observer::RemoveMeFromTheList()
{

}