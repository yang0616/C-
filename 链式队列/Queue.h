#include <iostream>
#include <stdio.h>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef int ElemType;

class Node
{
private:		
public:
	ElemType _data;
	Node*  _next;
	Node()
	{
		cout << "结点构造函数" <<endl;	
	}

	~Node()
	{
		cout << "结点析构函数" <<endl;	
	}
};

class Queue
{
private:
	Node* _head;
	Node* _tail;

public:
	//构造函数
	Queue()
	{
		cout << "队列构造函数" <<endl;
		_head = new Node();
		_tail = _head;
	}
	//拷贝构造函数
	Queue(const Queue& queue)
	{
		cout << "拷贝构造函数" <<endl;
		_head = new Node();
		_tail = _head;

		Node *s = queue._head;
		while( s != queue._tail)
		{	
			_tail->_data = s->_data;	
			s = s->_next;
			_tail->_next = new Node();
			_tail = _tail->_next;
		}
	}

	//等号运算符重载函数
	Queue& operator = (const Queue& queue)
	{
		cout << "等号运算符重载函数" <<endl;
		if(this == &queue)
		{
			return *this;
		}

		if(!IsEmpty_Queue())
		{
			while(!IsEmpty_Queue())
			{
				Node* next_head = _head->_next;
				delete _head;
				_head = next_head;
			}		
		}

		_head = new Node();
		_tail = _head;

		Node *s = queue._head;
		while( s != queue._tail)
		{	
			_tail->_data = s->_data;	
			s = s->_next;
			_tail->_next = new Node();
			_tail = _tail->_next;
		}
		return *this;
	}

	//析构函数
	~Queue()
	{
		cout << "队列析构函数" <<endl;

		while(_head != _tail)
		{
			Node* p = _head;
			_head = _head->_next;
			delete p;
			p = NULL;
		}
		_head = _tail = NULL;
	}
	//判断队列是否为空
	int IsEmpty_Queue();

	//进队列
	void Push_Queue(ElemType val);

	//出队列
	void Pop_Queue();

	//获取元素值
	ElemType Get_data();

	//得到队列的长度
	int Get_len();

	//打印队列数据
	void Show_Queue();

};