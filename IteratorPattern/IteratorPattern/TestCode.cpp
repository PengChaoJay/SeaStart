#include "TestCode.h"

void test1()
{
	MyList<int> myList;
	srand((unsigned)time(nullptr));

	//add List
	for (int i = 0; i < 10; i++)
	{
		myList.PushBack(rand()%100);
	}
	//range base for
	std::cout << "base range for loop :" << endl;
	for (auto a : myList)
	{
		std::cout << a <<" ";
	}

	std:: cout<< endl;
	std::cout << "begin for loop:" << endl;
	for (auto it = myList.begin(); it != myList.end(); it++)
	{
		std::cout << *it << " ";
	}
	
	std::cout << endl;
	std::cout << "rbegin for loop" << endl;
	for (auto it = myList.rbegin(); it != myList.rend(); it++)
	{
		std::cout << *it << " ";
	}

	//earse the pos element
	myList.remove(4);
	std::cout << endl;
	std::cout << "remove  fourth element" << endl;
	for (auto it = myList.rbegin(); it != myList.rend(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << endl;
}

void test2()
{
	MyList<std::string> myList;
	myList.PushBack("1. 爱--小虎队");
	myList.PushBack("2. 青花瓷---周杰伦");
	myList.PushBack("3. 稻香---周杰伦");
	myList.PushBack("4. 双截棍---周杰伦");
	myList.PushBack("5. 告白气球---周杰伦");
	myList.PushBack("6. 夜曲---周杰伦");
	cout << myList.Size() << endl;
	std::cout << "输入1，2，0分别代表前进，后退，退出" << std::endl;
	int num;
	auto it = myList.begin();
	cout << *it << endl;
	while (true)
	{
		std::cin >> num;
		switch (num) {
			case 1:
				std::cout << "【前进】---》";
				std::cout << (*++it) << endl;
				break;
			case 2:
				std::cout << "【后退】《---";
				std::cout << (*--it) << endl;
				break;
			case 0:
				exit(0);
			default:
				std::cout << "请输入1，2，0" << endl;
		}
		if (it == myList.end())
		{

			std::cout << "歌曲放完，该循环了" << std::endl;
		}

	}

}
