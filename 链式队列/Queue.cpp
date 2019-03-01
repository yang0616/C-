#include "Queue.h"

//�ж϶����Ƿ�Ϊ��
int Queue::IsEmpty_Queue()
{
	if(_head == _tail)
	{
		return TRUE;
	}
	return FALSE;
}

//������
void Queue::Push_Queue(ElemType val)
{
	_tail->_data = val;
	_tail->_next = new Node();
	_tail = _tail->_next;
}

//��ȡԪ��ֵ
ElemType Queue::Get_data()
{
	return _head->_data;
}

//������
void Queue::Pop_Queue()
{
	Node* Next_Node = _head->_next;
	delete _head;
	_head = Next_Node;
}

//�õ����еĳ���
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

//��ӡ��������
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