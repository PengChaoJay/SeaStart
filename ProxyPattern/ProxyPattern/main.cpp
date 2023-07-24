#include<iostream>
#include "TestCode.h"
using namespace std;

int main()
{
	int input;
	std::cout << "选择测试方式：1：直接测试，2：命令行测试,0:退出系统:";
	while (true)
	{
		cin >> input;
		switch (input)
		{
		case 1:
			test1();
			std::cout << "测试完毕,请重新输入" << std::endl;
			break;
		case 2:
			test2();
			std::cout << "测试完毕,请重新输入" << std::endl;
			break;
		case 0:
			exit(0);
			break;
		default:
			std::cout << "选择测试方式：1：直接测试，2：命令行测试,0:退出系统:";
			break;
		}
	}
}
