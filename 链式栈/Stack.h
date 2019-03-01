#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

typedef int ElemType ;

class Node
{
private:
public: 
	ElemType _data;
	Node* _next;

	Node()
	{
		//cout << "结点构造" << endl;
	}

	~Node()
	{
		//cout << "结点析构" << endl;
	}
};

class Stack
{
private:
public:
	Node* _top;
	Node* _head;
	int _len;
	//构造函数
	Stack()
	{
		//cout << "构造函数" << endl;
		_top = new Node();
		_head = _top;
		_len = 0;
	}

	//拷贝构造函数
	Stack(const Stack& stack)
	{
		//cout << "拷贝构造函数" << endl;

		Node* p = stack._head;
		_top = new Node();
		_head = _top;
		_len = 0;
		while(p != stack._top)
		{
			_top->_data = p->_data;
			p = p->_next;
			_top->_next = new Node();
			_top = _top->_next;
			_len++;
		}
	}

	//等号运算符重载函数
	Stack& operator = (const Stack& stack)
	{
		//cout << "等号运算符重载函数" << endl;
		if(this == &stack)
		{
			return *this;
		}

		while(!IsEmpty_Stack())
		{
			Node* p = _head;
			_head = _head->_next;
			delete p;
			_len--;
		}	

		_top = new Node();
		_head = _top;
		Node* s = stack._head;
		while(s != stack._top)
		{
			_top->_data = s->_data;
			s = s->_next;
			_top->_next = new Node();
			_top = _top->_next;
			_len++;
		}
		return *this;
	}

	//析构函数
	~Stack()
	{
		//cout << "析构函数" << endl;
		while(!IsEmpty_Stack())
		{
			Node* p = _head;
			_head = _head->_next;
			delete p;
			_len--;
		}
	}

	//判断栈是否为空
	int IsEmpty_Stack();

	//入栈
	void Push_Stack(ElemType val);

	//得到栈顶数据
	ElemType Get_Top_Stack();

	//出栈
	void Pop_Stack();

	//长度
	int Get_Len_Stack();

	//打印
	void Show_Stack();
};
