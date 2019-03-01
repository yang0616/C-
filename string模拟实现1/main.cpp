#include <iostream>
#include <string.h>

using namespace std;

class Mstring
{
private:
	char* _str;
	int _size;
	friend  bool operator==(const char* str, const Mstring& src);
public:
	Mstring(const char* str=NULL)
	{
		cout << "char 转 string 函数"<< endl;
		if(str == NULL)
		{
			_str = NULL;
			return;
		}
		int len = strlen(str) + 1;
		_str = new char[len]; 
		_size = len - 1;
		strcpy_s(_str, len,str);		 
	}

	Mstring(const Mstring& str)
	{
		cout << "拷贝构造函数"<< endl;
		if(str._str == NULL)
		{
			_str = NULL;
			return;
		}
		int len = strlen(str._str) + 1;
		_str = new char[len];
		_size = len - 1;
		strcpy_s(_str, len, str._str);	
	}

	Mstring operator=(const Mstring& str)
	{
		cout << "等号运算符重载函数"<< endl;
		if(this == &str)
		{
			return *this;
		}
	
		int len = strlen(str._str) + 1;
		_str = new char[len];
		_size = len - 1;
		strcpy_s(_str, len, str._str);
	}
	Mstring operator = (const char* str)
	{
		cout << "char* 的等号重载" << endl;
		if (_str != NULL)
		{
			delete[] _str;
		}
		if (str == NULL)
		{
			_str = NULL;
			return *this;
		}

		_str = new char[strlen(str) + 1];
		strcpy_s(_str, strlen(str) + 1, str);
	}

	~Mstring()
	{
		cout << "析构函数" << endl;
		if(_str != NULL)
		{
			delete []_str;
			_str = NULL;
		}
		_size = 0;
	}

	Mstring operator+(const Mstring& src)//char*
	{
		cout << "+函数"<< endl;
		Mstring tmp(" ");
		delete []tmp._str;

		int len_src = strlen(src._str);
		int len_str = strlen(_str);
		int len = len_src + len_str + 1;

		tmp._size = len - 1;
		tmp._str = new char[len];

		strcpy_s(tmp._str, len, _str);
		strcat_s(tmp._str, len, src._str);

		return tmp;
	}

	/*Mstring(const Mstring str1, const Mstring str2)
	{
	if(str1._str == NULL && str2._str == NULL)
	{
	_str = NULL;
	return;
	}
	_str = new char[strlen(str1._str) + strlen(str2._str) + 1];
	strcpy_s(_str, strlen(_str) + 1, str1._str);
	strcat_s(_str, strlen(str1._str) + strlen(str2._str) + 1, str2._str);
	}*/

	bool operator>(const Mstring& src)const
	{
		cout << ">函数"<< endl;
		return strcmp(_str, src._str) > 0;
	}

	bool operator>(const char* str)//char*
	{
		cout << "char* >函数" << endl;
		return strcmp(_str, str) > 0;
	}

	bool operator<(const Mstring& src)const
	{
		cout << "<函数"<< endl;
		return strcmp(_str, src._str) < 0;
	}

	bool operator<(const char* str)//char*
	{
		cout << "char* <函数" << endl;
		return strcmp(_str, str) < 0;
	}

	bool operator==(const Mstring& src)const
	{
		cout << "==函数"<< endl;
		return strcmp(_str, src._str) == 0;
	}

	bool operator==(const char* src)//Mstring == char*
	{
		cout << "Mstring == char*" << endl;
		return strcmp(_str, src) == 0;
	}

	bool operator!=(const Mstring& src)const
	{
		cout << "!=函数"<< endl;
		return strcmp(_str, src._str) != 0;
	}

	bool operator != (const char* str)//char*
	{
		cout << "char* != 函数" << endl;
		return strcmp(_str, str) != 0;
	}

	ostream& operator<<( ostream & c_out)
	{
		cout << "输出函数"<< endl;
		c_out << _str << endl;
		c_out << _size << endl;
		return c_out;
	}

	istream& operator>>(istream & c_put)
	{
		cout << "输入函数"<< endl;
		c_put >> _str ;
		_size = strlen(_str);
		return c_put;
	}

	char& operator[](int pos)
	{
		cout << "[]函数"<< endl;
		return _str[pos];
	}

	void show()
	{
		cout << "输出函数" << endl;
		if (_str != NULL)
		{
			cout << "_str: " << _str << endl;
			cout << "_size: " << _size << endl;
		}
		else
		{
			cout << "this is null string" << endl;
		} 	
	}
};
bool operator==(const char* str,const Mstring& src)// char* == Mstring 
{
	cout << " char* == Mstring" << endl;
	return strcmp(str, src._str) == 0;
}

int main()
{
	char* arr = "yangxingxing";
	char* brr = "hello  world";
	char* crr = "yangxingxing";
	Mstring str1 = "yang";
	Mstring str2 = brr;
	//Mstring str3 = str1;

	str1.show();

	if (str1 > str2)
	{
		cout << "str1 > str2" << endl;
	}
	if (str1 < str2)
	{
		cout << "str1 < str2" << endl;
	}

	/*str2.show();*/
	//str1.operator<<(cout);
	//str1.operator>>(cin);//内存溢出问题

	/*if (str1 == str2)
	{
		cout << "str1 == str2" << endl;
	}
	if (crr == str1)
	{
		cout << "crr == str1" << endl;
	}
	if (str2 == brr)
	{
		cout << "str2 == brr" << endl;
	}*/

	//Mstring str3 = str1 + str2;
	//Mstring str4 = str2 + str1;
	//Mstring tmp = str1.operator+(str2);
	//str3.show();
	//str4.show();
	//tmp.show();

	return 0;
}
