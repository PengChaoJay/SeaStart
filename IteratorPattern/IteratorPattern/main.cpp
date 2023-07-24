
#include "TestCode.h"
int main()
{
	int num;
	std::cout << "1£¬Ö±½Ó²âÊÔ£¬2.ÃüÁîĞĞ²âÊÔ, 3ÇåÆÁ£¬0ÍË³ö" << std::endl;
	
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
			std::cout << "1£¬Ö±½Ó²âÊÔ£¬2.ÃüÁîĞĞ²âÊÔ,0ÍË³ö" << std::endl;
			break;
		}
	}
}