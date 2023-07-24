#include "LuckProxy.h"

LuckProxy::LuckProxy():Cache(make_unique<LRUCache>(5))
{
	//Cache = make_unique<LRUCache>(5);
}

LuckProxy::~LuckProxy()
{
}

int LuckProxy::generate(string animal)
{
	//checks whether it is in the blacklist. If it is in the blacklist,returns
	std::cout << "��������ǣ���" << animal <<"��" <<std::endl;
	if (blackList.count(animal))
	{
		std::cout<<"��" << animal <<"��" << "\t �ں�������,����"<<std::endl;
		return -1;
	}
	// postpone Create
	if (luckyNumber == nullptr)
	{
		luckyNumber = make_shared<LuckyNumber>();
	}

	// determine if it is in the cache
	int temp = Cache->Get(animal);
	if(temp)
	{
		std::cout<< "��" << animal << "��" << "\t �ڻ������ҵ��˸�����:\t\t" <<"����������"<<"��"<<temp<<"��" << std::endl;
		return temp;
	}

	// if not in Cache ,find the original data,if exits,add into the cache and return 
	temp = luckyNumber->generate(animal);
	if (!temp)
	{
		std::cout<< "��" << animal << "��" << "\t Ϊ�Ƿ�����" << std::endl;
		return 0;
	}else {
		Cache->InsetData(animal, temp);
		std::cout << "��" << animal << "��" << "\t �ҵ�����,�������ݴ��뻺��:"<<"���������ǣ�" << "��" << temp << "��" << std::endl;
		return temp;
	}
	return -1;
}

//put name into blacklist
void LuckProxy::addBlackList(string name)
{
	this->blackList.emplace(name);
	std:: cout<<"��" << name <<"��" << "\t�Ѿ���ӽ�������" << std::endl;
}

//show blacklist
void LuckProxy::showBlackList() {

	if (blackList.size() == 0)
	{
		std::cout << "Ŀǰû�����ں������У���ʱ������Ϊ��" << std::endl;
	}else {
		std::cout << "��ֹ���ʵĺ�����Ϊ:" << std::endl;
		for (auto s : blackList)
		{
			std::cout << "\t" << s << std::endl;
		}

	}

}

//remove name form blacklist
void LuckProxy::removeBlackList(string name) 
{
	if (blackList.count(name))
	{
		cout <<"��" << name << "��" << "\t�Ƴ�������,���Է��� " << endl;
		blackList.erase(name);
	}
	else {
		cout<<"��" << name << "��" << "\t���ں������У��޷��Ƴ� " << endl;
	}
}
void LuckProxy::addBlackListCapacity(int size)
{
	Cache->AddCacheSize(size);
}

void LuckProxy::showBlackListCapacity()
{
	std::cout << "������������Ϊ" << Cache->GetSize() << std::endl;
}
void LuckProxy::removeAllBlackList()
{
	blackList.clear();
}



