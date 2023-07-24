#include "LRU.h"


// set the default size =5;
LRUCache::LRUCache(int size)
{
	m_capacity = size;
	pHead = nullptr;
	pTail = nullptr;
}

// 析构函数
LRUCache::~LRUCache()
{
	// map释放内存时，先释放内部new的内存，然后释放map的内存
	map<string, CacheNode*>::iterator it = mp.begin();
	for (; it != mp.end();)
	{
		delete it->second;
		mp.erase(it++); 
	}
}


void LRUCache::Remove(CacheNode* pNode)
{
	if (pNode->pPre != nullptr)
	{
		pNode->pPre->pNext = pNode->pNext;
	}else
	{
		pHead = pNode->pNext;
	}
	
	if (pNode->pNext != nullptr)
	{
		pNode->pNext->pPre = pNode->pPre;
	}
	else
	{
		pTail = pNode->pPre;
	}
}

//Set the Head 
void LRUCache::SetHead(CacheNode* pNode)
{
	pNode->pNext = pHead;
	pNode->pPre = nullptr;

	if (pHead!=nullptr)
	{
		pHead->pPre = pNode;
	}
	pHead = pNode;
	
	if (pTail == nullptr)
	{
		pTail = pHead;
	}
}



//If it doesn't exist in the cache, add it into the cache, if yes and update it 
void LRUCache::InsetData(string key, int value)
{
	map<string, CacheNode*>::iterator it = mp.find(key);
	if (it != mp.end())
	{
		CacheNode* Node = it->second;
		Node->m_value = value;
		Remove(Node);
		SetHead(Node);
	}
	else
	{
		// Cache is Full
		CacheNode* NewNode = new CacheNode(key,value);
		if (mp.size() >= m_capacity)
		{
			// Cache is Full
			map<string, CacheNode*>::iterator iter = mp.find(pTail->m_key);
			std::cout << "\t 缓存容量不足,进行缓存调整:" << "【" << pTail->m_key << "】" << "移除缓存\t" << "【" << key <<"】" << "添加进入缓存" << std::endl;
			//remove the Tail Node
			Remove(pTail);
			mp.erase(iter);
		}
		//
		SetHead(NewNode);
		mp[key] = NewNode;
	}
}

int LRUCache::Get(string key)
{
	map<string, CacheNode*>::iterator it = mp.find(key);
	if (it != mp.end())
	{
		CacheNode* Node = it->second;
		Remove(Node);
		SetHead(Node);
		return Node->m_value;
	}
	else
	{
		return 0;
	}
}

void LRUCache::AddCacheSize(int size)
{
	assert(size >= 0);
	assert(size < 10);
	this->m_capacity += size;
}

int LRUCache::GetSize()
{
	return this->m_capacity;
}

