#include <iostream>
using namespace std;

#define SIZE 10

template <typename T>
class Stack
{
public:
	class Node;
	Stack()
	{
		cout << "构造Stack" << endl;
		_head = new Node();
		_head->_pre = NULL;
		_head->_next = NULL;
		_top = _head;
	}

	~Stack()
	{
		cout << "析构函数" << endl;
		while (!Isempty())
		{
			Pop();
		}
		delete _head;
		_head = NULL;		
	}

	bool Isempty()
	{
		cout << "判空" << endl;
		return _head == _top;
	}

	T Top()
	{
		if (Isempty())
		{
			return -1;
		}
		return _top->_data;
	}

	void Pop()
	{
		cout << "出栈" << endl;
		if (!Isempty())
		{
			Node* tmp = _top;
			_top = _top->_pre;
			delete tmp;
		}
		else
		{
			cout << "Stack is empty!" << endl;
		}

		if (_head->_next == NULL)
		{
			_top = _head;
		}
	}

	void Push(T data)
	{
		cout << "入栈" << endl;
		Node* tmp = new Node();

		tmp->_next = NULL;
		tmp->_data = data;
		tmp->_pre = _top;

		_top->_next = tmp;
		_top = _top->_next;
	}

	void Show()
	{
		Node* tmp = _head->_next;
		while (tmp != _top)
		{
			cout << tmp->_data << " ";
			tmp = tmp->_next;
		}
		cout << tmp->_data << endl;
	}

private:
	Node* _top;
	Node* _head;

	class Space
	{
	public:
		static Space* getSpace()
		{
			if (_space == NULL)
			{
				//加锁
				if (_space == NULL)
				{
					_space = new Space();
				}
				//解锁
			}
			return _space;
		}
		friend class Node;
	private:
		static Space* _space;
		Node* _pool;

		Space()//单利模式的内存池构造函数
		{
			cout << "构造内存池" << endl;
			Node* tmp = new Node[SIZE];
			for (int i = 0; i < SIZE ; i++)
			{
				if (i == 0)
				{
					tmp[i]._pre = NULL;
				}
				else
				{
					tmp[i]._pre = &tmp[i - 1];
				}

				if (i == SIZE - 1)
				{
					tmp[i]._next = NULL;
				}
				else
				{
					tmp[i]._next = &tmp[i + 1];
				}					
			}
			_pool = &tmp[0];
		}

		void expand()
		{
			cout << "expand函数" << endl;
			Node* tmp = new Node[SIZE];
			for (int i = 0; i < SIZE; i++)
			{
				if (i == 0)
				{
					tmp[i]._pre = NULL;
				}
				else
				{
					tmp[i]._pre = &tmp[i - 1];
				}

				if (i == SIZE - 1)
				{
					tmp[i]._next = NULL;
				}
				else
				{
					tmp[i]._next = &tmp[i + 1];
				}
			}
			_pool = &tmp[0];
		}		
	};

	class Node
	{
	public:
		Node()
		{
			cout << "构造Node" << endl;
			_pre = NULL;
			_next = NULL;
		}

		void* operator new(size_t size)
		{
			cout << "void* operator new(size_t size)" << endl;
			if (_space->_pool == NULL)
			{
				//加锁
				if (_space->_pool == NULL)
				{
					_space->expand();
				}				
				//解锁
			}
			Node* tmp = _space->_pool;
			_space->_pool = tmp->_next;
			return tmp;
		}

		void operator delete(void *p)
		{
			cout << "void operator delete(void *p)" << endl;
			Node* tmp = (Node*)p;
			tmp->_next = _space->_pool;
			tmp->_next->_pre = tmp;
			tmp->_pre = NULL;
			_space->_pool = tmp;
		}
		friend class Stack;
	private:
		Node* _pre;
		Node* _next;
		T _data;
		static Space* _space;
	};	
};

template <typename T>
typename Stack<T>::Space* Stack<T>::Space::_space = NULL;

template <typename T>
typename Stack<T>::Space* Stack<T>::Node::_space = Stack<T>::Space::getSpace();


int main()
{
	Stack<int> stack;
	for (int i = 0; i < 4; i++)
	{
		stack.Push(i);
	}
	stack.Show();

	for (int i = 0; i <10; i++)
	{
		cout << stack.Top() << " ";
		stack.Pop();
	}

	if (stack.Isempty())
	{
		cout << "stack is empty" << endl;
	}
	else
	{
		cout << "stack is not empty" << endl;
	}
	return 0;
}