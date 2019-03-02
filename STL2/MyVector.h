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
	int _valSize; //�������������ڵ�Ԫ�س���
	int _len; //�������ܴ�С

	void Expand() //����
	{
		if (_len == 0 || _len == 1) //ע�������������1 �ͻ���ѭ������Ϊ1��1.5������1����Զ�����ݲ��ɹ�
		{
			_len++;
		}

		_len = _len + (_len << 1);
		Type* new_tmp = new Type[_len];

		for (int i = 0; i < _valSize; i++)
		{
			new_tmp[i] = _tmp[i];
		}

		if (_tmp != NULL) //ע������ǵ�һ������ռ����ﲻ�жϾͻ����
		{
			delete _tmp;
		}

		_tmp = new_tmp;

	}

public:
	typedef MyIterator<Type> iterator;

	MyVector() //���캯��
	{
		_tmp = NULL;
		_valSize = 0;
		_len = 0;
	}

	~MyVector()//��������
	{
		if (_tmp != NULL)
		{
			delete _tmp;
		}
	}

	MyVector(const MyVector& src)//�������캯��
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

	MyVector& operator = (const MyVector& src)//�Ⱥ����������
	{
		if (this == &src) //��ֹ�Ը�ֵ
		{
			retunr *this;
		}

		if (_tmp != NULL) //��ֹ�ڴ�й©
		{
			delete _tmp;
		}

		_valSize = src._valSize;
		_len = src._len;

		if (src._len == 0) //��ֹԽ��
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

	Type& operator[] (int pos)//[]���������
	{
		return _tmp[pos];
	}

	void Push_back(Type val) //��������β��һ��Ԫ��
	{
		if (_valSize == _len)
		{
			Expand();
		}
		_tmp[_valSize++] = val;
	}

	bool empty() //�ж������Ƿ�Ϊ��
	{
		return _valSize == 0;
	}

	bool full() //�ж������Ƿ�Ϊ��
	{
		return _valSize == _len;
	}

	void Pop_back() //ɾ�����������һ��Ԫ��
	{
		if (!empty())
		{
			_valSize--;
		}
	}

	Type Front() //�õ������еĵ�һ��Ԫ��
	{
		if (!empty())
		{
			return _tmp[0];
		}
		throw "vector is empty"; //�������Ϊ�վ��׳�һ���쳣
	}

	Type Back() //�õ����������һ��Ԫ��
	{
		if (!empty())
		{
			return _tmp[_valSize - 1];
		}
		throw "vector is empty";
	}

	int size()//�õ����������Ǵ��ڵ�Ԫ�ظ���
	{
		return _valSize;
	}

	void clear() //�������
	{
		_valSize = 0;
	}

	void reserve(int len) //��������
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