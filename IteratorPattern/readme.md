#### 迭代器设计模式


#### 实现的内容

##### 双向的迭代器

采用模板的形式设计的list的双向迭代器，迭代器里面有一个ListNode节点来实现迭代器的操作符。

其中Self，和Node，分别使用using 来


```
using Node = ListNode<T>; 

​using Self = MyIterator<T, Ref, Ptr>;

```
​  迭代器分别实现的操作符：

++，--，*，!=，==
  

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



##### 实现的容器

实现的容器是List容器



##### 容器的设计

​	采用循环链表实现list的容器，

容器实现的内容包括

​	容器实现的接口包括：

```
        void PushBack(const T& Val)    // 插入元素
	Iterator begin()               // 正向迭代的Begin
	Iterator end()                 // 正向迭代的End
	ConstIterator begin()const     // const 迭代器
	ConstIterator end()const  
	ReverseIterator rbegin()       //反向迭代器rbegin
	ReverseIterator rend()         //反向迭代器rend
	ConstReverseIterator rbegin()const  // const 迭代器
        ConstReverseIterator rend()const
	void release()              // 删除全部数据
	Iterator Erase(Iterator it)  // 删除末尾数据
	void PopBack()              //弹出
	size_t Size()              //获取大小
        void remove(int pos)      //删除指定位置的数据
```




结构体设计

设计的结构体包括两个指针分别代表指针的前后指向


```
class ListNode
{
public:
	ListNode(const T& data) :_data(data), _next(nullptr), _prev(nullptr) {}
	ListNode() :_next(nullptr), _prev(nullptr) {}
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;
};
```

