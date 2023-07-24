#pragma once
#include <iostream>
#include <assert.h>
#include <map>
using namespace std;


//** Linked list node structure

struct CacheNode
{
	string m_key;
	int m_value;
	CacheNode *pPre, *pNext;
	CacheNode(string key, int value) :m_key(key), m_value(value), pPre(nullptr), pNext(nullptr) {}
};

//*  LRU cache implements bidirectional linked lists.¡£
class LRUCache
{
public:
	//constructor initializes the cache size
	LRUCache(int size = 5);

	~LRUCache();
	// remove Node
	void Remove(CacheNode* pNode);

	//  Put the  recently used data in ListNode's head
	void SetHead(CacheNode* pNode);
	// Insert data, if it exists and update data only 

	void InsetData(string key, int value);

	//add Cache Size 
	void AddCacheSize(int size);

	//  Get the data in the cache
	int Get(string key);
	//  return the Cache Size 
	int GetSize();

private:
	int m_capacity;    //the capacity of LRUCache
	CacheNode* pHead;   //Head Node
	CacheNode* pTail;   //Tail Node
	map<string, CacheNode *>  mp;

};