#include "Queue.h"

//�пպ���
int Queue::IsEmpty_Queue()
{
	if(_tail == _head)
	{
		return TRUE;
	}
	return FALSE;
}
//��������
int Queue::IsFull_Queue()
{
	if((_tail + 1)%_size == _head)
	{
		return TRUE;
	}
	return FALSE;
}
//��ӡ����
void Queue::Show_Queue()
{
	for(int i = _head; i != _tail; i = (i+1)%_size)
	{
		cout << _data[i] << "  ";
	}
	cout << endl;
}
//���ݺ���
void Queue::Expand_queue()
{
	_size *= 2;
	int* new_data = new int[_size];
	assert(new_data != NULL);

	for(int i = _head; i != _tail; i = (i + 1)%_size)
	{
		new_data[i] = _data[i];
	}

	delete []_data;
	_data = new_data;
}
//���Ӻ���
int Queue::Pop_queue(int *res)
{
	if(IsEmpty_Queue())
	{
		return FALSE;
	}

	*res = _data[_head++];
	_head %= _size;

	return TRUE;
}
//��Ӻ���
void Queue::Push_queue(int val)
{
	if(IsFull_Queue())
	{
		Expand_queue();
	}

	_data[_tail++] = val;
	_tail %= _size;
}
