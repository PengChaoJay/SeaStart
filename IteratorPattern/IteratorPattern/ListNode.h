#pragma once

template<class T>

class ListNode
{
public:
	ListNode(const T& data) :_data(data), _next(nullptr), _prev(nullptr) {}
	ListNode() :_next(nullptr), _prev(nullptr) {}
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;
};