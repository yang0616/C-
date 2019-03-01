#include "Queue.h"

//判空函数
int Queue::IsEmpty_Queue()
{
	if(_tail == _head)
	{
		return TRUE;
	}
	return FALSE;
}
//判满函数
int Queue::IsFull_Queue()
{
	if((_tail + 1)%_size == _head)
	{
		return TRUE;
	}
	return FALSE;
}
//打印函数
void Queue::Show_Queue()
{
	for(int i = _head; i != _tail; i = (i+1)%_size)
	{
		cout << _data[i] << "  ";
	}
	cout << endl;
}
//扩容函数
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
//出队函数
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
//入队函数
void Queue::Push_queue(int val)
{
	if(IsFull_Queue())
	{
		Expand_queue();
	}

	_data[_tail++] = val;
	_tail %= _size;
}
