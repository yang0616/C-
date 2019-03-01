#include <iostream>
using namespace std;
#define SIZE 10
/*
new operator �� operator new ������
new operator��������һ��ʹ�õ�new��eg��new int��10������Ҫ�������������ڴ�͹��첢�Ҳ�����������
operator new��new�����غ�����ֻ�����ڴ棬��������
���ߵĹ�ϵ��new operator�ײ����� operator new 
delete operator �� operator delete ������
delete operator��������ƽʱ�����ͷ��ڴ�Ŀ⺯����delete []arr����Ҫ���������������ͷ��ڴ棬���Ҳ�����������
operator delete��delete�����غ�����ֻ�ͷ��ڴ棬��������
���߹�ϵ:delete operator �ײ����� operator delete 
*/

/*
C++ �ռ�������
һ�����������128�ֽڵ�����ϵͳ�����
����������С��128�ֽڵ����ڴ���Լ�����
*/
template<typename T>//��ͷ������ʽ����ģ��
class Queue
{
public:
	class Node; 
	Queue()
	{
		cout << "���캯��" << endl;
		_head = new Node();
		_head->_next = NULL;
		_tail = _head;
	}

	~Queue()
	{
		cout << "��������" << endl;
		while (!Isempty())
		{
			Pop();
		}
		delete _head;
		_head = _tail = NULL;
	}

	void Push(T val)
	{	
		cout << "���" << endl;
		_tail->_next = new Node();//���������ٸ�ֵ
		_tail = _tail->_next;//tail������һ��
		_tail->_data = val;//��ֵ
	}

	void Pop()
	{
		cout << "����" << endl;
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
		cout << "���" << endl;
		return _head->_next->_data;
	}

	bool Isempty()
	{
		cout << "�п�" << endl;
		return _head == _tail;
	}

	void Show()
	{
		cout << "��ӡ����" << endl;
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
		static space* _space;//ָ���ڴ�ص�ָ��
		Node* _pool;

		space()//�ڴ�صĵ���ģʽ
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
		static space* getSpace()//˫��if�ж� ��֤���߳��µİ�ȫ
		{
			  if (_space == NULL)
			  {
				  //����
				  if (_space == NULL)
				  {
					  _space = new space();
				  }
				  //����
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
				//����
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
				//����
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
��ҵ��ʵ��ջ���ڴ�ء�����ģʽ��new delete ������
*/
