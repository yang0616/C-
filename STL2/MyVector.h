#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <vector>
#include "Miterator.h"
using namespace std;

template <class Type>
class MyVector
{
private:
	Type* _tmp;
	int _valSize; //容器中真正存在的元素长度
	int _len; //容器的总大小

	void Expand() //扩容
	{
		if (_len == 0 || _len == 1) //注意这里如果不加1 就会死循环，因为1的1.5倍还是1，永远的扩容不成功
		{
			_len++;
		}

		_len = _len + (_len << 1);
		Type* new_tmp = new Type[_len];

		for (int i = 0; i < _valSize; i++)
		{
			new_tmp[i] = _tmp[i];
		}

		if (_tmp != NULL) //注意如果是第一次申请空间这里不判断就会崩溃
		{
			delete _tmp;
		}

		_tmp = new_tmp;

	}

public:
	typedef MyIterator<Type> iterator;

	MyVector() //构造函数
	{
		_tmp = NULL;
		_valSize = 0;
		_len = 0;
	}

	~MyVector()//析构函数
	{
		if (_tmp != NULL)
		{
			delete _tmp;
		}
	}

	MyVector(const MyVector& src)//拷贝构造函数
	{
		if (src._len == 0)
		{
			_tmp = NULL;
			_valSize = 0;
			_len = 0;
			return;
		}

		_valSize = src._valSize;
		_len = src._len;
		_tmp = new Type[src._len];

		for (int i = 0; i < _valSize; i++)
		{
			_tmp[i] = src._tmp[i];
		}
	}

	MyVector& operator = (const MyVector& src)//等号运算符重载
	{
		if (this == &src) //防止自赋值
		{
			retunr *this;
		}

		if (_tmp != NULL) //防止内存泄漏
		{
			delete _tmp;
		}

		_valSize = src._valSize;
		_len = src._len;

		if (src._len == 0) //防止越界
		{
			_tmp = NULL;
			return;
		}

		_tmp = new Type[src._len];

		for (int i = 0; i < _valSize; i++)
		{
			_tmp[i] = src._tmp[i];
		}

		return;
	}

	Type& operator[] (int pos)//[]运算符重载
	{
		return _tmp[pos];
	}

	void Push_back(Type val) //在容器中尾插一个元素
	{
		if (_valSize == _len)
		{
			Expand();
		}
		_tmp[_valSize++] = val;
	}

	bool empty() //判断容器是否为空
	{
		return _valSize == 0;
	}

	bool full() //判断容器是否为满
	{
		return _valSize == _len;
	}

	void Pop_back() //删除容器中最后一个元素
	{
		if (!empty())
		{
			_valSize--;
		}
	}

	Type Front() //得到容器中的第一个元素
	{
		if (!empty())
		{
			return _tmp[0];
		}
		throw "vector is empty"; //如果容器为空就抛出一个异常
	}

	Type Back() //得到容器中最后一个元素
	{
		if (!empty())
		{
			return _tmp[_valSize - 1];
		}
		throw "vector is empty";
	}

	int size()//得到容器中真是存在的元素个数
	{
		return _valSize;
	}

	void clear() //清空容器
	{
		_valSize = 0;
	}

	void reserve(int len) //重载扩容
	{
		if (_len > len)
		{
			return;
		}

		Type* new_tmp = new Type[len];

		for (int i = 0; i < _valSize; i++)
		{
			new_tmp[i] = _tmp[i];
		}

		if (_tmp != NULL)
		{
			delete _tmp;
		}

		_len = len;
		_tmp = new_tmp;
	}

	void Show()
	{
		for (int i = 0; i < _valSize; i++)
		{
			cout << _tmp[i] << " ";
		}
		cout << endl;
	}

	iterator begin()
	{
		return iterator(this, 0);
	}

	iterator end()
	{
		return iterator(this, _valSize);
	}
};

template<class Type>
Type& MyIterator<Type> :: operator * ()
{
	return  (*_vector)[_pos];
}
/*{
return _vector[_pos];
}
*/

template<class Type>
Type* MyIterator<Type> :: operator -> ()
{
	return (*_vector)[_pos];
}
/*{
return _vector[_pos];
}*/

#endif