
#include "TestCode.h"
int main()
{
	int num;
	std::cout << "1��ֱ�Ӳ��ԣ�2.�����в���, 3������0�˳�" << std::endl;
	
	while (true)
	{ 
		std::cin >> num;
		switch (num)
		{
		case 1:
			test1();
			break;
		case 2:
			test2();
			break;
		case 3:
			system("CLS");
			break;
		default:
			std::cout << "1��ֱ�Ӳ��ԣ�2.�����в���,0�˳�" << std::endl;
			break;
		}
	}
}