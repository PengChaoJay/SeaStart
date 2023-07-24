#include "LRU.h"


// set the default size =5;
LRUCache::LRUCache(int size)
{
	m_capacity = size;
	pHead = nullptr;
	pTail = nullptr;
}

// ��������
LRUCache::~LRUCache()
{
	// map�ͷ��ڴ�ʱ�����ͷ��ڲ�new���ڴ棬Ȼ���ͷ�map���ڴ�
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
			std::cout << "\t ������������,���л������:" << "��" << pTail->m_key << "��" << "�Ƴ�����\t" << "��" << key <<"��" << "��ӽ��뻺��" << std::endl;
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

