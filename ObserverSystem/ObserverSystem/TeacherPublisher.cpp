#include "TeacherPublisher.h"


TeacherPublisher::TeacherPublisher() {
}

TeacherPublisher::TeacherPublisher(string name) {
	this->setName(name);
}

TeacherPublisher::TeacherPublisher(string name,string coursename) {
	this->setName(name);
	this->setCourseName(coursename);
}

TeacherPublisher::~TeacherPublisher() {

}

bool TeacherPublisher::Subscribe(shared_ptr<IObserver>  observer)
{
	if (observers.count(observer) == 0) {
		observers.emplace(observer);
		cout<<"\t" << observer->getName()<<" student, " << "you follw the " << this->getName() << " teacher." << endl;
		return true;
	}
	cout << observer->getName() << " student, "<< " you have follow this teachers" << endl;
	return false;
}


bool TeacherPublisher::UnSubscribe(shared_ptr<IObserver>  observer) {
	if (observers.count(observer) == 1) {

		cout << observer->getName() << " student, " <<" unfollw the " << this->getName() << " teacher." << endl;
		observers.erase(observer);
		return true;
	}
	cout << observer->getName() << " student, "  << " you have not follow  "<<this->getName() << " teacher." << endl;
	return false;
}

//show some that i have attention
void TeacherPublisher::show() {
	if (observers.size() == 0)
	{
		cout << this->getName()<<" teacher, " << " you not any follow" << endl;
		return;
	}

	cout  << "the follower student's name:" << endl;
	for (auto observer : observers)
	{
		cout << "\t" << observer->getName() << endl;
	}
}
//notified message
void TeacherPublisher::Notify() {

	if (observers.size() == 0)
	{
		cout<<this->getName()<<" teacher," << " have no any students follow you" << endl;
		return;
	}

	cout<<this->getName()<<" teacher, " << " you hava " << observers.size() << " follows:" << endl;
	this->show();

	for (auto observer :observers) {
		observer->Update(this->getPtr(), this->getMessage());
	}
}

void TeacherPublisher::Publish(string message) {
	this->setMessage(message);
	Notify();
}
