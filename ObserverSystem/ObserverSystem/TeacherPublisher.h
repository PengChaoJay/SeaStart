#pragma once
#include "IPublisher.h"
#include <string>

using namespace std;

class TeacherPublisher :
    public IPublisher, public std::enable_shared_from_this<TeacherPublisher>
{
public:
    TeacherPublisher();
    TeacherPublisher(string name);
    TeacherPublisher(string name,string coursename);
    ~TeacherPublisher();
	std::shared_ptr<TeacherPublisher> getPtr()
	{
		return shared_from_this();
	}
    bool Subscribe(shared_ptr<IObserver> observer);
    bool UnSubscribe(shared_ptr<IObserver>  observer) ;
    void Notify();
    void show() ;
    void Publish(string message = "Empty");
private:

    unordered_set <shared_ptr<IObserver>> observers;
};

