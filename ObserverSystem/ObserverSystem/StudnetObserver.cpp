#include "StudnetObserver.h"

StudnetObserver::StudnetObserver() {

}

StudnetObserver::~StudnetObserver()
{
	//for (auto teacher : teachers) {
	//	delete teacher;
	//}
}	
StudnetObserver::StudnetObserver(string name)
{
	this->setName(name);
}
void StudnetObserver::Update(shared_ptr<IPublisher> teacher,const string& message) {

	cout << "Hi, " + teacher->getName() + " teacher send a message for you ,this message is:" + message << endl;
}

//bool StudnetObserver::addTeacher(IPublisher* teacher,string Subject) {
//	if (teachers.count(teacher)==0){
//		teacher->Subscribe(this);
//		this->teachers.emplace(teacher, Subject);
//		return true;
//	}
//	cout << "you hava follow the teacher, not`t follow again!" << endl;
//	return false;
//}

bool StudnetObserver::addTeacher(shared_ptr<IPublisher>teacher) {
	if (teachers.count(teacher)==0){
		teacher->Subscribe(this->getPtr());
		this->teachers.emplace(teacher);
		return true;
	}
	cout << this->getName() << " student, " << " you hava follow the teacher, not follow again!" << endl;
	return false;
}

void StudnetObserver::show()
{
	
	if (teachers.size()==0)
	{
		cout << this->getName() << " student, " << "don`t follow any teachers" << endl;
		return;
	}
	cout << this->getName() << " student, " <<  " follow the teachers:" << endl;
	for(auto teacher :teachers)
	{
		cout <<"\t" << teacher->getName()<<" this teacher courses name£º\t" <<teacher->getCourseName()<< endl;
	}
}

void StudnetObserver::RemoveMeFromTheList(shared_ptr<IPublisher> teacher)
{
	teacher->UnSubscribe(this->getPtr());
	this->teachers.erase(teacher);
}
