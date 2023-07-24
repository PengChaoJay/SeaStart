#pragma once
#include <iostream>
#include <memory>
#include <unordered_set>
#include "IPublisher.h"
using namespace std;

class IPublisher;
//Abstract observer
class IObserver
{
public:
	virtual ~IObserver() {};
	
	virtual void Update(shared_ptr<IPublisher> teacher, const string& message) = 0;
	// Pay attention to the teacher and put yourself under a certain teacher
	void setName(string name) { this->myName = name; }
	string getName() { return this->myName; }
	//virtual bool addTeacher(IPublisher* teacher, string Subject) = 0;
	virtual bool addTeacher(shared_ptr<IPublisher> teacher) = 0;
	// show  teachers that I have attention 
	virtual void show() = 0;
	// Remove yourself from the attention of the teacher
	virtual void RemoveMeFromTheList(shared_ptr<IPublisher> teacher) = 0;
private:
	string myName;
};


