#include <iostream>
using namespace std;
#define SIZE 10
/*
new operator 和 operator new 的区别
new operator就是我们一般使用的new【eg：new int（10）】它要做两件事申请内存和构造并且不被允许重载
operator new是new的重载函数它只申请内存，允许重载
两者的关系：new operator底层会调用 operator new 
delete operator 和 operator delete 的区别
delete operator就是我们平时用来释放内存的库函数【delete []arr】它要做两件事析构和释放内存，并且不被允许重载
operator delete是delete的重载函数它只释放内存，允许重载
两者关系:delete operator 底层会调用 operator delete 
*/

/*
C++ 空间配置器
一级：申请大于128字节的是向系统申请的
二级：申请小于128字节的是内存的自己管理
*/
template<typename T>//带头结点的链式队列模板
class Queue
{
public:
	class Node; 
	Queue()
	{
		cout << "构造函数" << endl;
		_head = new Node();
		_head->_next = NULL;
		_tail = _head;
	}

	~Queue()
	{
		cout << "析构函数" << endl;
		while (!Isempty())
		{
			Pop();
		}
		delete _head;
		_head = _tail = NULL;
	}

	void Push(T val)
	{	
		cout << "入队" << endl;
		_tail->_next = new Node();//先申请结点再赋值
		_tail = _tail->_next;//tail往后走一步
		_tail->_data = val;//赋值
	}

	void Pop()
	{
		cout << "出队" << endl;
		if (!Isempty())
		{
			Node* tmp = _head->_next;
			_head->_next = tmp->_next;
			delete tmp;
		}
		if (_head->_next == NULL)
		{
			_tail = _head;
		}		
	}

	T top()
	{
		cout << "输出" << endl;
		return _head->_next->_data;
	}

	bool Isempty()
	{
		cout << "判空" << endl;
		return _head == _tail;
	}

	void Show()
	{
		cout << "打印函数" << endl;
		Node *tmp = _head->_next;
		while (tmp != _tail)
		{
			cout << tmp->_data << " ";
			tmp = tmp->_next;
		}
		cout << tmp->_data << " "<< endl;
	}
private:
	Node *_head;
	Node *_tail;
	class space
	{
	private:
		static space* _space;//指向内存池的指针
		Node* _pool;

		space()//内存池的单例模式
		{
			Node* tmp = new Node[SIZE];
			int i = 0;
			for (; i < SIZE - 1; i++)
			{
				tmp[i]._next = &tmp[i + 1];
			}
			tmp[i]._next = NULL;
			_pool = &tmp[0];
		}
		friend class Node;

	public:
		static space* getSpace()//双重if判断 保证多线程下的安全
		{
			  if (_space == NULL)
			  {
				  //加锁
				  if (_space == NULL)
				  {
					  _space = new space();
				  }
				  //解锁
			  }
			  return _space;
	    }		
	};
	class Node
	{
	public:
		Node()
		{
			_next = NULL;
		}

		Node(T data)
		{
			_data = data;
			_next = NULL;
		}

		void *operator new(size_t size)
		{ 
			cout << "void *operator new(size_t size)" << endl;
			if (_space->_pool == NULL)
			{
				//加锁
				if (_space->_pool == NULL)
				{
					Node *tmp = new Node[SIZE];
					int i = 0;
					for (; i < SIZE - 1; i++)
					{
						tmp[i]._next = &tmp[i + 1];
					}
					tmp[i]._next = NULL;
					_space->_pool = &tmp[0];
				}
				//解锁
			}
			Node* ret = _space->_pool;
			_space->_pool = ret->_next;
			return ret;
		}

		void operator delete(void *p)
		{
			cout << "void operator delete(void *p)" << endl;
			Node* tmp = (Node*)p;
			tmp->_next = _space->_pool;
			_space->_pool = tmp;
		}
		friend class Queue;
	private:
		T _data;
		Node* _next;
		static space* _space;
	};
};
template<typename T>
typename Queue<T>::space*  Queue<T>::Node::_space = Queue<T>::space::getSpace();

template<typename T>
typename Queue<T>::space* Queue<T>::space::_space = NULL;

int main()
{
	Queue<int> queue;
	for (int i = 0; i < 4; i++)
	{
		queue.Push(i);
	}
	queue.Show();
	/*while (!queue.Isempty())
	{
		cout << queue.top() << " ";
		queue.Pop();
	}
	cout << endl;

	if (queue.Isempty())
	{
		cout << "queue is empty" << endl;
	}
	else
	{
		cout << "queue is not empty" << endl;
	}

	queue.Show();*/
	return 0;
}


/*
作业：实现栈，内存池、单例模式、new delete 的重载
*/
