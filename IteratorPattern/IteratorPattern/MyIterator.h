#pragma once
#include "ListNode.h"
template<class T, class Ref, class Ptr>

//ÕýÏòµü´úÆ÷
class MyIterator
{
	using Node = ListNode<T>;
	using Self = MyIterator<T, Ref, Ptr>;
public:
	MyIterator(Node* node)
		:_node(node)
	{}
	Ref operator*()
	{
		return _node->_data;
	}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self& operator++(int)
	{
		_node = _node->_next;
		return *this;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self& operator--(int)
	{
		_node = _node->_prev;
		return *this;
	}
	
	bool operator!=(const Self& other)const
	{
		return other._node != _node;
	}
	bool operator==(const Self& other) const
	{
		return other._node == _node;
	}
public:
	Node* _node;
};