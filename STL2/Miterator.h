#ifndef MITERATOR_H
#define MITERATOR_H
#include <iostream>
using namespace std;

template<class Type>
class MyVector;

template <class Type>
class MyIterator
{
private:
	MyVector<Type>* _vector;
	int _pos;
	
public:
	MyIterator(MyVector<Type>* src, int pos)
	{
		_vector = src;
		_pos = pos;
	}

	MyIterator(const MyIterator* src)
	{
		_vector = src._vector;
		_pos = src._pos;
	}

	MyIterator& operator = (const MyIterator& src)
	{
		_vector = src._vector;
		_pos = src._pos;
	}

	bool operator == (const MyIterator& src)
	{
		return (_vector == src._vector && _pos == src._pos);
	}

	bool operator != (const MyIterator& src)
	{
		return (_vector != src._vector || _pos != src._pos);
	}

	MyIterator& operator ++ () //前置++
	{
		++_pos;
		return *this;
	}

	MyIterator operator ++ (int) //后置++
	{
		return MyIterator(_vector, _pos++);
	}

	MyIterator& operator -- () //前置--
	{
		--_pos;
		return *this;
	}

	MyIterator& operator -- (int) //后置--
	{
		return MyIterator(_vector, _pos--);
	}

	Type& operator * ();
	/*{
		return _vector[_pos];
	}
	*/
	Type* operator -> ();
	/*{
		return _vector[_pos];
	}*/
};
#endif
