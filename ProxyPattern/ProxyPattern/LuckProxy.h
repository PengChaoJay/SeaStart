#pragma once
#include <unordered_set>
#include "LuckyNumber.h"
#include "LRU.h"

class LuckProxy:public Number
{
public:
	LuckProxy();
	virtual ~LuckProxy();
	// get luck Number 
	int generate(string animal);

	//put in blackList
	void addBlackList(string name);

	void addBlackListCapacity(int size);
	void showBlackListCapacity();
	void removeAllBlackList();

	//show blackListName
	void showBlackList();

	//remove form black list
	void removeBlackList(string name);


private:

	shared_ptr<LuckyNumber> luckyNumber = nullptr;
	//unordered_map<string,int> cache;
	unique_ptr<LRUCache> Cache = nullptr;
	//The blacklist
	unordered_set<string>blackList;
	
};

