#include "TestCode.h"
void test1()
{
	shared_ptr <LuckProxy> number = make_shared<LuckProxy>();

	// input data
	std::cout << "查找数据:";
	number->generate("Rat");
	number->generate("Horse");

	std::cout << "非法的输入：";
	//invaild input
	number->generate("people");

	std::cout << "缓存查找：";
	// add into cache
	number->generate("Rat");

	// input data
	std::cout << "查找数据:";
	number->generate("Ox");
	number->generate("Tiger");
	number->generate("Rabbit");
	number->generate("Goat");
	number->generate("Horse");




	std::cout << "添加黑名单：";
	number->addBlackList("Horse");
	number->showBlackList();

	std::cout << "如果在黑名单再次访问：" << std::endl;
	number->generate("Horse");


	std::cout << "显示黑名单的容量" << std::endl;
	number->showBlackListCapacity();

	std::cout << "增加黑名单的容量" << std::endl;
	number->addBlackListCapacity(3);
	number->showBlackListCapacity();


	std::cout << "从黑名单中移除：" << std::endl;
	number->removeBlackList("Horse");

	std::cout << "如果不在黑名单" << std::endl;
	number->removeBlackList("Ox");

	std::cout << "从黑名单中移除再次访问：" << std::endl;
	number->generate("Horse");

	number->generate("Horse");

	std::cout << "清空黑名单" << endl;
	number->removeAllBlackList();


}

void show()
{
	std::cout << "(系统可以提供的内容)：" << endl;
	std::cout << "Rat,Ox,Tiger,Rabbit,Dragon,Snake,Horse,Goat,Monkey,Rooster,Dog,Pig" << std::endl;
	std::cout << "\t1.查找数据" << "\t2.添加黑名单" << std::endl;
	std::cout << "\t3.显示黑名单" << "\t4.移除黑名单" << std::endl;
	std::cout << "\t5.增加黑名单容量(容量长度输入【0-10】)" << "\t6.显示黑名单容量" << std::endl;
	std::cout << "\t0.退出系统" << std::endl;
}
void test2()
{
	show();
	std::cout << "请输入数据（0-6）：";
	int input;
	int num;
	string animal;
	shared_ptr <LuckProxy> number = make_shared<LuckProxy>();
	while (true)
	{
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "输入查找的数据：";
			cin >> animal;
			number->generate(animal);
			break;
		case 2:
			cout << "输入插入黑名单的名字：";
			cin >> animal;
			number->addBlackList(animal);
			break;
		case 3:
			number->showBlackList();
			break;
		case 4:
			cout << "输入将黑名单的名字：";
			cin >> animal;
			number->removeBlackList(animal);
			break;
		case 5:
			cout << "输入增加黑名单的容量:";
			cin >> num;
			number->addBlackListCapacity(num);
			break;
		case 6:
			number->showBlackListCapacity();
			break;
		case 0:
			exit(0);
			return;
		default:
			show();
			std::cout << "请输入数据（0-6）：";
			break;
		}
	}
}