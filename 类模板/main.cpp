#include <iostream>
using namespace std;

/*
��ģ�壺
	��ģ��
	��ģ���к�����Ա������ģ��
	��ģ���г�Ա������ģ���������
	�������캯����ģ���������
*/

#define SIZE 10
template<typename T>
class Carry//����
{
private:
	T* _arr;
	int _len;
	int _size;
public:
	Carry()//���캯��
	{
		cout <<"���캯��"<< endl;
		_arr = new T[SIZE];
		_len = 0;
		_size = SIZE;
	}

	~Carry()//��������
	{
		cout <<"��������"<< endl;
		if(_arr != NULL)
		{
			delete []_arr;
		}
		_len = 0;
		_size = 0;
	}

	Carry(const Carry& src)//�������캯��
	{
		cout <<"�������캯��"<< endl;
		_arr = new T[src._size];
		_len = src._len;
		_size = src._size;

		for(int i = 0; i < src._len; i++)
		{
			_arr[i] = src._arr[i];
		}
	}

	Carry& operator = (const Carry& src)
	{
		cout <<"�Ⱥź���"<< endl;
		if(this == &src)
		{
			return *this;
		}
		if(_arr != NULL)
		{
			delete []_arr;
		}
		_arr = new T[src._size];
		_len = src._len;
		_size = src._size;

		for(int i = 0; i < src._len; i++)
		{
			_arr[i] = src._arr[i];
		}
		return *this;
	}

	//�ж������Ƿ�Ϊ��
	bool isfull()
	{
		cout <<"����"<< endl;
		if(_len == _size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isempty()
	{
		cout <<"�п�"<< endl;
		if(_len == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//����
	void expand()
	{
		cout <<"����"<< endl;
		_size *= 2;
		T* new_arr = new T[_size];

		for(int i = 0; i < _len; i++)
		{
			new_arr[i] = _arr[i];
		}

		delete []_arr;
		_arr = new_arr;

	}

	//ͷ��
	void insert_tail(T val)
	{
		cout <<"ͷ��"<< endl;
		if(isfull())
		{
			expand();
		}
		int i;
		for(i = _len ; i > 0; i--)
		{
			_arr[i] = _arr[i - 1];
		}
		_arr[i] = val;
		_len ++;

	}

	//��sitλ�ò���Ԫ��
	void insert(int sit, T val)
	{
		cout <<"sitλ�ò���Ԫ��"<< endl;
		if(isfull())
		{
			expand();
		}
		int i ;
		for( i = _len; i > val; i--)
		{
			_arr[i] = _arr[i - 1];
		}
		_arr[i] = val;
		_len++;
	}

	//ɾ��βԪ��
	bool pop_tail()
	{
		cout <<"ɾβ"<< endl;
		if(isempty())
		{
			return false;
		}
		else
		{
			_len--;
			return true;
		}
	}

	//ɾ��sitλ�õ�Ԫ��
	bool delet(int sit)
	{
		cout <<"sitλ��ɾ��"<< endl;
		if(sit < 0 || sit >= _len)
		{
			return false;
		}
		for(int i = sit; i < _len; i++)
		{
			_arr[i] = _arr[i + 1]��
		}
	    _len--;
	}

	//�õ�βԪ�ص�ֵ
	T get_tail()
	{
		cout <<"�õ�βԪ�ص�ֵ"<< endl;
		if(isempty())
		{
			return T();
		}
		return _arr[_len - 1];
	}

	//�ҵ�valԪ�ص��±�
/*	int find(T val)
	{
		cout <<"��λ�ú���"<< endl;
		int tmp;
		int i;
		for(i = 0; i < _len; i++)
		{
			if(_arr[i] == val)
			{
				tmp = i;
				break;
			}
		}
		if(i == _len)
		{
			return -1;
		}
		else
		{
			return tmp;
		}
	}
*/

//find ������ģ��
/*	template<typename U>
	int find(U val)
	{
		cout << "int find(U val)"<< endl;
		int tmp;
		int i;
		for(i = 0; i < _len; i++)
		{
			if(_arr[i] == val)
			{
				tmp = i;
				break;
			}
		}
		if(i == _len)
		{
			return -1;
		}
		else
		{
			return tmp;
		}
	}
*/
	template<>
	int find<char*>(char* val)
	{
		cout << "int find<char*>(char* val)"<< endl;
		int i;
		int tmp;
		for(i = 0; i < _len; i++)
		{
			if(strcmp(_arr[i], val) == 0)
			{
			    tmp = i;
				break;
			}
		}
		if(i == _len)
		{
			return -1;
		}
		else
		{
			return tmp;
		}
	}

	//�������Ԫ��
	void show();
/*	void show()
	{
		for(int i = 0; i < _len; i++)
		{
			cout << _arr[i] << " ";
		}
		cout << endl;
	}	
*/
};

//����ʵ����ģ�����ͨ��Ա����
template<typename T>
void Carry<T>::show()
{
	for(int i = 0; i < _len; i++)
		{
			cout << _arr[i] << " ";
		}
		cout << endl;
}

//����ʵ����ģ��ĳ�Ա������ģ��
//(ע����ģ��ĳ�Ա������ģ���������ģ�����������ʵ��)
template<typename T>
template<typename U>
int Carry<T>::find(U val)
{
	cout << "int find(U val)"<< endl;
	int tmp;
	int i;
	for(i = 0; i < _len; i++)
	{
		if(_arr[i] == val)
		{
			tmp = i;
			break;
		}
	}
	if(i == _len)
	{
		return -1;
	}
	else
	{
		return tmp;
	}
}



int main()
{
/*	Carry <int>arr;
	for(int i = 0; i < 15; i++)
	{
		arr.insert(i , i + 1);
	}
	int tmp = arr.find(5);
	cout << "tmp = " << tmp << endl;
	arr.show();

	int tail = arr.get_tail();
	cout << "tail = " << tail << endl;
	arr.pop_tail();
	arr.show();
*/
	Carry <char*>arr1;

	arr1.insert_tail("yang");
	arr1.insert_tail("xing");
	arr1.insert_tail("asdsad");
	arr1.show();
	char str[] = {"yang"};
	int tmp1 = arr1.find(str);
	cout << "tmp1 = " << tmp1 << endl;
	return 0;
}

/*
17064 
����carry��ģ�壬ʵ��Stack��ģ��
ʵ��carry�������ʵ�֣������ࣩ
*/