#include "Miterator.h"
#include <iostream>
using namespace std;

int& Mstring::get_Count()//得到同一块地址被使用的数量
{
	return *((int*)_str);
}

char* Mstring::get_Start()const//返回地址中真正开始存数据的起始位置
{
	return _str + 4;
}

Mstring::Mstring(const char* str = NULL)//用char* 型拷贝构造函数
{
	cout << "char 转 string 函数" << endl;
	if (str == NULL)
	{
		_str = NULL;
		return;
	}
	int len = strlen(str) + 1 + 4;
	_str = new char[len];//注意：构造时要申请内存
	//让地址中的前四个自己保存地址被使用的数量
	_size = strlen(str);
	get_Count() = 1;
	strcpy_s(get_Start(), len - 4, str);
}

Mstring::Mstring(const Mstring& str)//用同类型（Mstring）拷贝构造函数
{
	cout << "拷贝构造函数" << endl;
	if (str._str == NULL)
	{
		_str = NULL;
		return;
	}
	int len = strlen(str.get_Start()) + 1 + 4;
	_str = str._str;
	_size = strlen(str.get_Start());
	strcpy_s(get_Start(), len - 4, str.get_Start());
	get_Count()++;//地址使用增加一个
}

Mstring Mstring::operator=(const Mstring& str)
{
	cout << "Mstring等号重载函数" << endl;
	if (this == &str)//防止自赋值
	{
		return *this;
	}
	if (_str != NULL && get_Count() - 1 == 0)//防止内存泄漏
	{
		delete[]_str;
	}
	else
	{
		get_Count()--;//旧地址使用减少一个
	}
	if (str.get_Start() == NULL)
	{
		_str = NULL;
		return *this;
	}
	//只要没有改变原来地址上数据的企图，就不用申请新空间（进行浅拷贝）
	_str = str._str;
	_size = str._size;
	get_Count()++;//新地址使用增加一个
	return *this;
}

Mstring Mstring::operator = (const char* str)
{
	cout << "char* 的等号重载" << endl;
	if (_str != NULL && get_Count() - 1 == 0)
	{
		delete[] _str;
	}
	else
	{
		get_Count()--;
	}
	if (str == NULL)
	{
		_str = NULL;
		return *this;
	}
	int len = strlen(str) + 1 + 4;
	_str = new char[len];
	_size = strlen(str);
	strcpy_s(get_Start(), len - 4, str);
	get_Count()++;//新地址使用增加一个
	return *this;
}

Mstring::~Mstring()
{
	cout << "析构函数" << endl;
	if (_str != NULL && get_Count() - 1 == 0)
	{
		delete[]_str;
	}
	else
	{
		get_Count() -= 1;;
	}
	_str = NULL;
	_size = 0;

}

Mstring Mstring::operator+(const Mstring& src)//char*
{
	cout << "+函数" << endl;
	Mstring tmp(" ");
	delete[]tmp._str;

	int len_src = strlen(src.get_Start());
	int len_str = strlen(get_Start());
	int len = len_src + len_str + 1 + 4;

	tmp._size = len - 1;
	tmp._str = new char[len];
	tmp.get_Count() = 1;
	strcpy_s(tmp.get_Start(), len - 4, get_Start());
	strcat_s(tmp.get_Start(), len - 4, src.get_Start());

	return tmp;
}

bool Mstring::operator>(const Mstring& src)const
{
	cout << ">函数" << endl;
	return strcmp(get_Start(), src.get_Start()) > 0;
}

bool Mstring::operator>(const char* str)//char*
{
	cout << "char* >函数" << endl;
	return strcmp(get_Start(), str) > 0;
}

bool Mstring::operator<(const Mstring& src)const
{
	cout << "<函数" << endl;
	return strcmp(get_Start(), src.get_Start()) < 0;
}

bool Mstring::operator<(const char* str)//char*
{
	cout << "char* <函数" << endl;
	return strcmp(get_Start(), str) < 0;
}

bool Mstring::operator==(const Mstring& src)const
{
	cout << "==函数" << endl;
	return strcmp(get_Start(), src.get_Start()) == 0;
}

bool Mstring::operator==(const char* src)//Mstring == char*
{
	cout << "Mstring == char*" << endl;
	return strcmp(get_Start(), src) == 0;
}

bool Mstring::operator!=(const Mstring& src)const
{
	//cout << "!=函数" << endl;
	return strcmp(get_Start(), src.get_Start()) != 0;
}

bool Mstring::operator != (const char* str)//char*
{
	cout << "char* != 函数" << endl;
	return strcmp(get_Start(), str) != 0;
}

ostream& Mstring::operator<<(ostream& c_out)
{
	cout << "输出函数" << endl;
	if (get_Start() != NULL)
	{
		c_out << "string: " << get_Start() << endl;
		c_out << "size: " << _size << endl;
		c_out << "count: " << get_Count() << endl;
	}
	else
	{
		c_out << "this is null string" << endl;
	}
	return c_out;
}

istream& Mstring::operator>>(istream& c_put)
{
	cout << "输入函数" << endl;
	c_put >> _str;
	_size = strlen(_str);
	return c_put;
}

char& Mstring::operator[](int pos)
{
	//cout << "[]函数" << endl;
	int len = strlen(get_Start()) + 1 + 4;
	char* new_str = new char[len];

	strcpy_s(new_str + 4, len - 4, get_Start());
	if (get_Count() - 1 == 0 && _str != NULL)
	{
		delete[]_str;
	}
	else
	{
		get_Count()--;
	}

	_str = new_str;
	get_Count() = 1;

	char* tmp = get_Start();
	return tmp[pos];
}

void Mstring::show()
{
	cout << "输出函数" << endl;
	if (_str != NULL)
	{
		cout << "_str: " << get_Start() << endl;
		cout << "_size: " << _size << endl;
		cout << "count: " << get_Count() << endl;
	}
	else
	{
		cout << "this is null string" << endl;
	}
}

Mstring::iterator Mstring::begin()
{
	return Miterator(*this, 0);
}

Mstring::iterator Mstring::end()
{
	return Miterator(*this, strlen(get_Start()));
}

bool operator==(const char* str, const Mstring& src)// char* == Mstring 
{
	cout << " char* == Mstring" << endl;
	return strcmp(str, src.get_Start()) == 0;
}