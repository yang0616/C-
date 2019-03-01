#include <iostream>
using namespace std;

/*
类模板：
	类模板
	类模板中函数成员方法的模板
	类模板中成员方法的模板的特例化
	拷贝构造函数的模板和特例化
*/

#define SIZE 10
template<typename T>
class Carry//容器
{
private:
	T* _arr;
	int _len;
	int _size;
public:
	Carry()//构造函数
	{
		cout <<"构造函数"<< endl;
		_arr = new T[SIZE];
		_len = 0;
		_size = SIZE;
	}

	~Carry()//析构函数
	{
		cout <<"析构函数"<< endl;
		if(_arr != NULL)
		{
			delete []_arr;
		}
		_len = 0;
		_size = 0;
	}

	Carry(const Carry& src)//拷贝构造函数
	{
		cout <<"拷贝构造函数"<< endl;
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
		cout <<"等号函数"<< endl;
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

	//判断数组是否为满
	bool isfull()
	{
		cout <<"判满"<< endl;
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
		cout <<"判空"<< endl;
		if(_len == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//扩容
	void expand()
	{
		cout <<"扩容"<< endl;
		_size *= 2;
		T* new_arr = new T[_size];

		for(int i = 0; i < _len; i++)
		{
			new_arr[i] = _arr[i];
		}

		delete []_arr;
		_arr = new_arr;

	}

	//头插
	void insert_tail(T val)
	{
		cout <<"头插"<< endl;
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

	//在sit位置插入元素
	void insert(int sit, T val)
	{
		cout <<"sit位置插入元素"<< endl;
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

	//删除尾元素
	bool pop_tail()
	{
		cout <<"删尾"<< endl;
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

	//删除sit位置的元素
	bool delet(int sit)
	{
		cout <<"sit位置删除"<< endl;
		if(sit < 0 || sit >= _len)
		{
			return false;
		}
		for(int i = sit; i < _len; i++)
		{
			_arr[i] = _arr[i + 1]；
		}
	    _len--;
	}

	//得到尾元素的值
	T get_tail()
	{
		cout <<"得到尾元素的值"<< endl;
		if(isempty())
		{
			return T();
		}
		return _arr[_len - 1];
	}

	//找到val元素的下标
/*	int find(T val)
	{
		cout <<"找位置函数"<< endl;
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

//find 函数的模板
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

	//输出所有元素
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

//类外实现类模板的普通成员方法
template<typename T>
void Carry<T>::show()
{
	for(int i = 0; i < _len; i++)
		{
			cout << _arr[i] << " ";
		}
		cout << endl;
}

//类外实现类模板的成员方法的模板
//(注：类模板的成员方法的模板的特例化模板必须在类内实现)
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
利用carry类模板，实现Stack的模板
实现carry类的完整实现（代理类）
*/