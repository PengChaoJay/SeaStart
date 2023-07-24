#pragma once

#include "ListNode.h"
#include "MyIterator.h"
#include "MyReverseIterator.h"


template<class T>
class MyList
{
	using Node = ListNode<T>;
public:
	using Iterator = MyIterator<T, T&, T*>;
	using ConstIterator = MyIterator<T, const T&, const T*>;
	using ReverseIterator = MyReverseIterator<T, T&, T*>;
	using ConstReverseIterator = MyReverseIterator <T, const T&, const T*>;

	MyList()
		:head(NewNode())
	{
		head->_next = head;
		head->_prev = head;
		size = 0;
	}

	~ MyList()
	{
		release();
		delete head;
	}

	// 默认传值
	Node* NewNode(const T& Val)
	{
		return new Node(Val);
	}

	// 用于head传值
	Node* NewNode()
	{
		return new Node();
	}
	//尾插
	void PushBack(const T& Val)   
	{
		Node* tail = head->_prev;
		Node* tmp = NewNode(Val);
		tail->_next = tmp;
		tmp->_prev = tail;
		tmp->_next = head;
		head->_prev = tmp;
		size++;
	}
	

	//定义返回迭代器类型的begin()和end()  
	Iterator begin()    
	{
		return Iterator(head->_next);
	}

	Iterator end()
	{
		return Iterator(head);
	}


	ConstIterator begin()const
	{
		return ConstIterator(head->_next);
	}

	ConstIterator end()const
	{
		return ConstIterator(head);
	}

	//定义返回迭代器类型的rBegin()和rEnd()
	ReverseIterator rbegin()    
	{
		return ReverseIterator(head->_prev);
	}


	ReverseIterator rend()
	{
		return ReverseIterator(head);
	}

	ConstReverseIterator rbegin()const
	{
		return ConstReverseIterator(head->_prev);
	}

	ConstReverseIterator rend()const
	{
		return ConstReverseIterator(head);
	}
	// 释放
	void release() 
	{
		Node* tmp = head->_next;
		while (tmp != head)
		{
			Node* del = tmp;
			tmp = tmp->_next;
			delete del; 
			size--;
		}
	}

	// 删除
	Iterator Erase(Iterator it)
	{
		Node* prev = it._node->_prev;
		Node* next = it._node->_next;
		delete it._node;
		prev->_next = next;
		next->_prev = prev;

		size--;
		return  prev;
	}

	void PopBack()
	{
		Erase(head->_prev);
	}

	size_t Size()
	{
		return size;
	}

	// 指定位置删除
	void remove(int pos)
	{
		Iterator it = begin();
		while (it != end())
		{
			if (pos == 1)
				it = Erase(it);
			++it;
			--pos;
			size--;
			
		}
	}

public:
	Node* head;
private:
	size_t size = 0;
};
