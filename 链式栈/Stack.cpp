#include "Stack.h"

//判断栈是否为空
int Stack::IsEmpty_Stack()
{
	if(_len == 0)
	{
		return TRUE;
	}
	return FALSE;
}

//入栈
void Stack::Push_Stack(ElemType val)
{
	_top->_data = val;
	_top->_next = new Node();
	_top = _top->_next;
	_len++;
}

//得到栈顶数据
ElemType Stack::Get_Top_Stack()
{
	Node* p = _head;
	while(p->_next != _top)
	{
		p = p->_next;
	}
	return p->_data;
}

//出栈
void Stack::Pop_Stack()
{
	Node* p = _head;
	while(p->_next != _top)
	{
		p = p->_next;
	}
	delete _top;
	_top = p;
	_len--;
}

//长度
int Stack::Get_Len_Stack()
{
	return _len;
}

//打印
void Stack::Show_Stack()
{
	Node* p = _head;
	cout << "data:";
	while(p != _top)
	{
		cout << p->_data << " ";
		p = p->_next;
	}
	cout << endl;
}