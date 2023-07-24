
#include "TestCode.h"

void test1()
{
	//Teacher
	shared_ptr<IPublisher> MathTeachers = make_shared<TeacherPublisher>("Liming", "Math");
	shared_ptr<IPublisher> EnglishTeachers = make_shared<TeacherPublisher>("Lisi", "English");
	shared_ptr<IPublisher> ChineseTeachers = make_shared<TeacherPublisher>("Wu", "Chinese");
	shared_ptr<IPublisher> SoftTeachers = make_shared<TeacherPublisher>("Hong", "Soft");
	shared_ptr<IPublisher> SpokenTeachers = make_shared<TeacherPublisher>("Ming", "Spoken language");
	shared_ptr<IPublisher> SoftWareTestTeachers = make_shared<TeacherPublisher>();

	SoftWareTestTeachers->setName("Test");
	SoftWareTestTeachers->setCourseName("Software Testing course");

	shared_ptr<IObserver> LiStudent = make_shared<StudnetObserver>("Li");
	shared_ptr<IObserver> WangStudent = make_shared<StudnetObserver>("Wang");
	shared_ptr<IObserver> LiuStudent = make_shared<StudnetObserver>("Liu");
	shared_ptr<IObserver> ZhoutStudent = make_shared<StudnetObserver>("Zhou");
	shared_ptr<IObserver> WuStudent = make_shared<StudnetObserver>("Wu");

	cout << "show some studets attention to teacher: " << endl;
	LiStudent->addTeacher(MathTeachers);
	WangStudent->addTeacher(MathTeachers);
	//Repeat add
	LiStudent->addTeacher(MathTeachers);
	LiStudent->addTeacher(SoftTeachers);
	LiStudent->addTeacher(SpokenTeachers);

	LiuStudent->addTeacher(SoftWareTestTeachers);
	ZhoutStudent->addTeacher(SoftWareTestTeachers);
	//not attention MathTeachers

	LiStudent->RemoveMeFromTheList(MathTeachers);

	LiStudent->show();

	//Show followers
	SoftWareTestTeachers->show();
	//news
	MathTeachers->Publish("It's time to go class room");

	//No students concerned about the teacher posted
	EnglishTeachers->Publish("It's time to go class room");

	//There are no teachers that students care about
	ZhoutStudent->show();
}