#include "TestCode.h"
void test1()
{
	shared_ptr <LuckProxy> number = make_shared<LuckProxy>();

	// input data
	std::cout << "��������:";
	number->generate("Rat");
	number->generate("Horse");

	std::cout << "�Ƿ������룺";
	//invaild input
	number->generate("people");

	std::cout << "������ң�";
	// add into cache
	number->generate("Rat");

	// input data
	std::cout << "��������:";
	number->generate("Ox");
	number->generate("Tiger");
	number->generate("Rabbit");
	number->generate("Goat");
	number->generate("Horse");




	std::cout << "��Ӻ�������";
	number->addBlackList("Horse");
	number->showBlackList();

	std::cout << "����ں������ٴη��ʣ�" << std::endl;
	number->generate("Horse");


	std::cout << "��ʾ������������" << std::endl;
	number->showBlackListCapacity();

	std::cout << "���Ӻ�����������" << std::endl;
	number->addBlackListCapacity(3);
	number->showBlackListCapacity();


	std::cout << "�Ӻ��������Ƴ���" << std::endl;
	number->removeBlackList("Horse");

	std::cout << "������ں�����" << std::endl;
	number->removeBlackList("Ox");

	std::cout << "�Ӻ��������Ƴ��ٴη��ʣ�" << std::endl;
	number->generate("Horse");

	number->generate("Horse");

	std::cout << "��պ�����" << endl;
	number->removeAllBlackList();


}

void show()
{
	std::cout << "(ϵͳ�����ṩ������)��" << endl;
	std::cout << "Rat,Ox,Tiger,Rabbit,Dragon,Snake,Horse,Goat,Monkey,Rooster,Dog,Pig" << std::endl;
	std::cout << "\t1.��������" << "\t2.��Ӻ�����" << std::endl;
	std::cout << "\t3.��ʾ������" << "\t4.�Ƴ�������" << std::endl;
	std::cout << "\t5.���Ӻ���������(�����������롾0-10��)" << "\t6.��ʾ����������" << std::endl;
	std::cout << "\t0.�˳�ϵͳ" << std::endl;
}
void test2()
{
	show();
	std::cout << "���������ݣ�0-6����";
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
			cout << "������ҵ����ݣ�";
			cin >> animal;
			number->generate(animal);
			break;
		case 2:
			cout << "�����������������֣�";
			cin >> animal;
			number->addBlackList(animal);
			break;
		case 3:
			number->showBlackList();
			break;
		case 4:
			cout << "���뽫�����������֣�";
			cin >> animal;
			number->removeBlackList(animal);
			break;
		case 5:
			cout << "�������Ӻ�����������:";
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
			std::cout << "���������ݣ�0-6����";
			break;
		}
	}
}