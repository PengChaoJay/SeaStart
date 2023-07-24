#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <unordered_set>
#include "IObserver.h"
using namespace std;


class IObserver;
//Abstract publisher
class IPublisher
{
public:
	virtual ~IPublisher() {};
	//Set publisher name in order to return name
	void setName(string name) { this->publishname_ = name; }
	string getName() { return this->publishname_; }

	//Set messages in order to messages
	void setMessage(string message) { this->message = message; }
	string getMessage() { return this->message; }

	//Set to return to course
	void setCourseName(string coursename) { this->coursename = coursename; }
	string getCourseName() { return this->coursename; }

	virtual bool Subscribe(shared_ptr<IObserver>  observer)=0;
	virtual bool UnSubscribe(shared_ptr<IObserver>  observer) = 0;
	virtual void Notify() = 0;
	virtual void show() = 0;
	virtual void Publish(string message = "Empty") = 0;

private:
	string  message;
	string  publishname_;
	string  coursename;
};

