#include "Stack.h"

//�ж�ջ�Ƿ�Ϊ��
int Stack::IsEmpty_Stack()
{
	if(_len == 0)
	{
		return TRUE;
	}
	return FALSE;
}

//��ջ
void Stack::Push_Stack(ElemType val)
{
	_top->_data = val;
	_top->_next = new Node();
	_top = _top->_next;
	_len++;
}

//�õ�ջ������
ElemType Stack::Get_Top_Stack()
{
	Node* p = _head;
	while(p->_next != _top)
	{
		p = p->_next;
	}
	return p->_data;
}

//��ջ
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

//����
int Stack::Get_Len_Stack()
{
	return _len;
}

//��ӡ
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