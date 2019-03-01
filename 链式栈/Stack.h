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
		//cout << "��㹹��" << endl;
	}

	~Node()
	{
		//cout << "�������" << endl;
	}
};

class Stack
{
private:
public:
	Node* _top;
	Node* _head;
	int _len;
	//���캯��
	Stack()
	{
		//cout << "���캯��" << endl;
		_top = new Node();
		_head = _top;
		_len = 0;
	}

	//�������캯��
	Stack(const Stack& stack)
	{
		//cout << "�������캯��" << endl;

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

	//�Ⱥ���������غ���
	Stack& operator = (const Stack& stack)
	{
		//cout << "�Ⱥ���������غ���" << endl;
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

	//��������
	~Stack()
	{
		//cout << "��������" << endl;
		while(!IsEmpty_Stack())
		{
			Node* p = _head;
			_head = _head->_next;
			delete p;
			_len--;
		}
	}

	//�ж�ջ�Ƿ�Ϊ��
	int IsEmpty_Stack();

	//��ջ
	void Push_Stack(ElemType val);

	//�õ�ջ������
	ElemType Get_Top_Stack();

	//��ջ
	void Pop_Stack();

	//����
	int Get_Len_Stack();

	//��ӡ
	void Show_Stack();
};
