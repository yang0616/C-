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
//�пպ�������
	int IsEmpty_Queue();
//������������
	int IsFull_Queue();
public:
//���캯��
	Queue()
	{
		cout << "���캯��" << endl;

		_data = new int[SIZE];//ע�⣺��ֹǳ����
		assert(_data != NULL);

		_head = 0;
		_tail = 0;
		_size = SIZE;
	}
//�������캯��
	Queue(const Queue& queue)
	{
		cout << "�������캯��" << endl;

		_data = new int[queue._size];//ע�⣺��ֹǳ����
		assert(_data != NULL);

		for(int i = queue._head; i != queue._tail; i = (i+1)%queue._size)
		{
			_data[i] = queue._data[i];
		}

		_head = queue._head;
		_tail = queue._tail;
		_size = queue._size;
	}
//�Ⱥ���������غ���
	Queue& operator = (const Queue& queue)
	{
		cout << "�Ⱥ���������غ���" << endl;

		if(this == &queue)//ע�⣺��ֹ�Լ����Լ���ֵ
		{
			return *this;
		}

		if(_data != NULL)//ע�⣺��ֹ�ڴ�й©
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
//��������
	~Queue()
	{
		cout << "��������" << endl;
		if(_data != NULL)
		{
			delete []_data;
			_data = NULL;
		}
		_head = 0;
		_tail = 0;
		_size = 0;
	}
//��ӡ��������
	void Show_Queue();
//���ݺ�������
	void Expand_queue();
//���Ӻ�������
	int Pop_queue(int *res);
//��Ӻ�������
	void Push_queue(int val);
};
