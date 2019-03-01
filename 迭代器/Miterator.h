#ifndef __MITERATOR_H
#define __MITERATOR_H
#include <iostream>
using namespace std;

class Miterator;
class Mstring
{
private:
	char* _str;
	int _size;
	friend  bool operator==(const char* str, const Mstring& src);
public:
	typedef Miterator iterator;
	Mstring(const char* str);

	Mstring(const Mstring& str);

	~Mstring();

	int& get_Count();

	char* get_Start()const;

	Mstring operator = (const Mstring& str);
	Mstring operator = (const char* str);//char*

	Mstring operator+(const Mstring& src);

	bool operator>(const Mstring& src)const;
	bool operator>(const char* str);//char*

	bool operator<(const Mstring& src)const;
	bool operator<(const char* str);//char*	

	bool operator==(const Mstring& src)const;
	bool operator==(const char* src);//Mstring == char*

	bool operator!=(const Mstring& src)const;
	bool operator!=(const char* str);//char*

	ostream& operator<<(ostream & c_out);

	istream& operator>>(istream & c_put);

	char& operator[](int pos);

	iterator begin();

	iterator end();

	void show();
};

class Miterator
{
public:
	Miterator(Mstring& str, int pos)
		:_str(str), _pos(pos)
	{}

	Miterator(const Miterator& src)
		:_str(src._str), _pos(src._pos)
	{}

	char& operator*()
	{
		return _str[_pos];
	}

	bool operator != (const Miterator& src)
	{
		return (_str != src._str) || (_pos != src._pos);
	}

	Miterator operator++(int)
	{
		return Miterator(_str, _pos++);
	}

private:
	Mstring&  _str;
	int _pos;
};
#endif