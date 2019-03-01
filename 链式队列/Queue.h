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
		cout << "��㹹�캯��" <<endl;	
	}

	~Node()
	{
		cout << "�����������" <<endl;	
	}
};

class Queue
{
private:
	Node* _head;
	Node* _tail;

public:
	//���캯��
	Queue()
	{
		cout << "���й��캯��" <<endl;
		_head = new Node();
		_tail = _head;
	}
	//�������캯��
	Queue(const Queue& queue)
	{
		cout << "�������캯��" <<endl;
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

	//�Ⱥ���������غ���
	Queue& operator = (const Queue& queue)
	{
		cout << "�Ⱥ���������غ���" <<endl;
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

	//��������
	~Queue()
	{
		cout << "������������" <<endl;

		while(_head != _tail)
		{
			Node* p = _head;
			_head = _head->_next;
			delete p;
			p = NULL;
		}
		_head = _tail = NULL;
	}
	//�ж϶����Ƿ�Ϊ��
	int IsEmpty_Queue();

	//������
	void Push_Queue(ElemType val);

	//������
	void Pop_Queue();

	//��ȡԪ��ֵ
	ElemType Get_data();

	//�õ����еĳ���
	int Get_len();

	//��ӡ��������
	void Show_Queue();

};