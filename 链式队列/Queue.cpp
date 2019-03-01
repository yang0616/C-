#include "Queue.h"

//判断队列是否为空
int Queue::IsEmpty_Queue()
{
	if(_head == _tail)
	{
		return TRUE;
	}
	return FALSE;
}

//进队列
void Queue::Push_Queue(ElemType val)
{
	_tail->_data = val;
	_tail->_next = new Node();
	_tail = _tail->_next;
}

//获取元素值
ElemType Queue::Get_data()
{
	return _head->_data;
}

//出队列
void Queue::Pop_Queue()
{
	Node* Next_Node = _head->_next;
	delete _head;
	_head = Next_Node;
}

//得到队列的长度
int Queue::Get_len()
{
	Node *p = _head;
	int count = 0;
	while(p != _tail)
	{
		count ++;
		p = p->_next;
	}
	return count;
}

//打印队列数据
void Queue::Show_Queue()
{
	if(IsEmpty_Queue())
	{
		cout << "Queue is Empty!"<<endl;
		return ;
	}
	else
	{
		Node *p = _head;
		while(p != _tail)
		{
			cout << p->_data <<" ";
			p = p->_next;
		}
		cout << endl;
		return;
	}	
}