#pragma once
//#include <list>
#include "ListNode.h"
template<class T, class Ref, class Ptr>

//反向迭代器重载
class MyReverseIterator   
{

	using Node = ListNode<T> ;
	using Self = MyReverseIterator<T, Ref, Ptr>;
public:
	MyReverseIterator(Node* node)
		:_node(node)
	{}
	Ref operator*()
	{
		return _node->_data;
	}

	Self& operator++(int)
	{
		_node = _node->_prev;
		return *this ;
	}

	Self& operator++()
	{
		_node = _node->_prev;

		return *this;
	}
	Self& operator--(int)
	{
		_node = _node->_next;
		return *this;
	}

	Self& operator--()
	{
		_node = _node->_next;

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