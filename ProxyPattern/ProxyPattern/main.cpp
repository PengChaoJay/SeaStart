#include<iostream>
#include "TestCode.h"
using namespace std;

int main()
{
	int input;
	std::cout << "ѡ����Է�ʽ��1��ֱ�Ӳ��ԣ�2�������в���,0:�˳�ϵͳ:";
	while (true)
	{
		cin >> input;
		switch (input)
		{
		case 1:
			test1();
			std::cout << "�������,����������" << std::endl;
			break;
		case 2:
			test2();
			std::cout << "�������,����������" << std::endl;
			break;
		case 0:
			exit(0);
			break;
		default:
			std::cout << "ѡ����Է�ʽ��1��ֱ�Ӳ��ԣ�2�������в���,0:�˳�ϵͳ:";
			break;
		}
	}
}
