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
	std::cout << "您输入的是：【" << animal <<"】" <<std::endl;
	if (blackList.count(animal))
	{
		std::cout<<"【" << animal <<"】" << "\t 在黑名单中,返回"<<std::endl;
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
		std::cout<< "【" << animal << "】" << "\t 在缓存中找到了该数据:\t\t" <<"幸运数字是"<<"【"<<temp<<"】" << std::endl;
		return temp;
	}

	// if not in Cache ,find the original data,if exits,add into the cache and return 
	temp = luckyNumber->generate(animal);
	if (!temp)
	{
		std::cout<< "【" << animal << "】" << "\t 为非法输入" << std::endl;
		return 0;
	}else {
		Cache->InsetData(animal, temp);
		std::cout << "【" << animal << "】" << "\t 找到数据,并将数据存入缓存:"<<"幸运数字是：" << "【" << temp << "】" << std::endl;
		return temp;
	}
	return -1;
}

//put name into blacklist
void LuckProxy::addBlackList(string name)
{
	this->blackList.emplace(name);
	std:: cout<<"【" << name <<"】" << "\t已经添加进黑名单" << std::endl;
}

//show blacklist
void LuckProxy::showBlackList() {

	if (blackList.size() == 0)
	{
		std::cout << "目前没有人在黑名单中，此时黑名单为空" << std::endl;
	}else {
		std::cout << "禁止访问的黑名单为:" << std::endl;
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
		cout <<"【" << name << "】" << "\t移除黑名单,可以访问 " << endl;
		blackList.erase(name);
	}
	else {
		cout<<"【" << name << "】" << "\t不在黑名单中，无法移除 " << endl;
	}
}
void LuckProxy::addBlackListCapacity(int size)
{
	Cache->AddCacheSize(size);
}

void LuckProxy::showBlackListCapacity()
{
	std::cout << "黑名单的容量为" << Cache->GetSize() << std::endl;
}
void LuckProxy::removeAllBlackList()
{
	blackList.clear();
}



