#include <iostream>
#include <assert.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

using namespace std;

class Queue
{
private:
	int* _data;
	int _size;
	int _head;
	int _tail;
//判空函数声明
	int IsEmpty_Queue();
//判满函数声明
	int IsFull_Queue();
public:
//构造函数
	Queue()
	{
		cout << "构造函数" << endl;

		_data = new int[SIZE];//注意：防止浅拷贝
		assert(_data != NULL);

		_head = 0;
		_tail = 0;
		_size = SIZE;
	}
//拷贝构造函数
	Queue(const Queue& queue)
	{
		cout << "拷贝构造函数" << endl;

		_data = new int[queue._size];//注意：防止浅拷贝
		assert(_data != NULL);

		for(int i = queue._head; i != queue._tail; i = (i+1)%queue._size)
		{
			_data[i] = queue._data[i];
		}

		_head = queue._head;
		_tail = queue._tail;
		_size = queue._size;
	}
//等号运算符重载函数
	Queue& operator = (const Queue& queue)
	{
		cout << "等号运算符重载函数" << endl;

		if(this == &queue)//注意：防止自己给自己赋值
		{
			return *this;
		}

		if(_data != NULL)//注意：防止内存泄漏
		{
			delete []_data;
		}

		_data = new int[queue._size];
		assert(_data != NULL);

		for(int i = queue._head; i != queue._tail; i = (i+1)%queue._size)
		{
			_data[i] = queue._data[i];
		}

		_head = queue._head;
		_tail = queue._tail;
		_size = queue._size;
	}
//析构函数
	~Queue()
	{
		cout << "析构函数" << endl;
		if(_data != NULL)
		{
			delete []_data;
			_data = NULL;
		}
		_head = 0;
		_tail = 0;
		_size = 0;
	}
//打印函数声明
	void Show_Queue();
//扩容函数声明
	void Expand_queue();
//出队函数声明
	int Pop_queue(int *res);
//入队函数声明
	void Push_queue(int val);
};
