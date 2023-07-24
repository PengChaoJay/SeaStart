#pragma once
#include <memory>
#include "IObserver.h"
#include "IPublisher.h"


class StudnetObserver : public IObserver , public std::enable_shared_from_this<StudnetObserver>{
public:
	StudnetObserver();
	//Student, Name
	StudnetObserver(string name);

	virtual ~StudnetObserver();
	bool addTeacher(shared_ptr<IPublisher> teacher);

	shared_ptr<StudnetObserver> getPtr()
	{
		return shared_from_this();
	}

	// Just choose the teacher
	//bool addTeacher(IPublisher* teacher,string Subject);
	void Update(shared_ptr<IPublisher> teacher,const string& message);
	void show();
	void RemoveMeFromTheList(shared_ptr<IPublisher> teacher);
private:
	unordered_set <shared_ptr<IPublisher>>teachers;

};