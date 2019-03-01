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

	void show();
};

int& Mstring::get_Count()//�õ�ͬһ���ַ��ʹ�õ�����
{
	return *((int*)_str);
}

char* Mstring::get_Start()const//���ص�ַ��������ʼ�����ݵ���ʼλ��
{
	return _str + 4;
}

Mstring::Mstring(const char* str = NULL)//��char* �Ϳ������캯��
{
	cout << "char ת string ����" << endl;
	if (str == NULL)
	{
		_str = NULL;
		return;
	}
	int len = strlen(str) + 1 + 4;
	_str = new char[len];//ע�⣺����ʱҪ�����ڴ�
	//�õ�ַ�е�ǰ�ĸ��Լ������ַ��ʹ�õ�����
	_size = strlen(str);
	get_Count() = 1;
	strcpy_s(get_Start(), len - 4, str);
}

Mstring::Mstring(const Mstring& str)//��ͬ���ͣ�Mstring���������캯��
{
	cout << "�������캯��" << endl;
	if (str._str == NULL)
	{
		_str = NULL;
		return;
	}
	int len = strlen(str.get_Start()) + 1 + 4;
	_str = str._str;
	_size = strlen(str.get_Start());
	strcpy_s(get_Start(), len - 4, str.get_Start());
	get_Count()++;//��ַʹ������һ��
}

Mstring Mstring::operator=(const Mstring& str)
{
	cout << "Mstring�Ⱥ����غ���" << endl;
	if (this == &str)//��ֹ�Ը�ֵ
	{
		return *this;
	}
	if (_str != NULL && get_Count() - 1 == 0)//��ֹ�ڴ�й©
	{
		delete[]_str;
	}
	else
	{
		get_Count()--;//�ɵ�ַʹ�ü���һ��
	}
	if (str.get_Start() == NULL)
	{
		_str = NULL;
		return *this;
	}
	//ֻҪû�иı�ԭ����ַ�����ݵ���ͼ���Ͳ��������¿ռ䣨����ǳ������
	_str = str._str;
	_size = str._size;
	get_Count()++;//�µ�ַʹ������һ��
	return *this;
}

Mstring Mstring::operator = (const char* str)
{
	cout << "char* �ĵȺ�����" << endl;
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
	get_Count()++;//�µ�ַʹ������һ��
	return *this;
}

Mstring::~Mstring()
{
	cout << "��������" << endl;
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
	cout << "+����" << endl;
	Mstring tmp(" ");
	delete[]tmp._str;

	int len_src = strlen(src.get_Start());
	int len_str = strlen(get_Start());
	int len = len_src + len_str + 1 + 4;

	tmp._size = len - 1;
	tmp._str = new char[len];
	tmp.get_Count() = 1;
	strcpy_s(tmp.get_Start(), len - 4, get_Start());
	strcat_s(tmp.get_Start(), len - 4 , src.get_Start());

	return tmp;
}

bool Mstring::operator>(const Mstring& src)const
{
	cout << ">����" << endl;
	return strcmp(get_Start(), src.get_Start()) > 0;
}

bool Mstring::operator>(const char* str)//char*
{
	cout << "char* >����" << endl;
	return strcmp(get_Start(), str) > 0;
}

bool Mstring::operator<(const Mstring& src)const
{
	cout << "<����" << endl;
	return strcmp(get_Start(), src.get_Start()) < 0;
}

bool Mstring::operator<(const char* str)//char*
{
	cout << "char* <����" << endl;
	return strcmp(get_Start(), str) < 0;
}

bool Mstring::operator==(const Mstring& src)const
{
	cout << "==����" << endl;
	return strcmp(get_Start(), src.get_Start()) == 0;
}

bool Mstring::operator==(const char* src)//Mstring == char*
{
	cout << "Mstring == char*" << endl;
	return strcmp(get_Start(), src) == 0;
}

bool Mstring::operator!=(const Mstring& src)const
{
	cout << "!=����" << endl;
	return strcmp(get_Start(), src.get_Start()) != 0;
}

bool Mstring::operator != (const char* str)//char*
{
	cout << "char* != ����" << endl;
	return strcmp(get_Start(), str) != 0;
}

ostream& Mstring::operator<<(ostream & c_out)
{
	cout << "�������" << endl;
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

istream& Mstring::operator>>(istream & c_put)
{
	cout << "���뺯��" << endl;
	c_put >> _str;
	_size = strlen(_str);
	return c_put;
}

char& Mstring::operator[](int pos)
{
	cout << "[]����" << endl;
	int len = strlen(get_Start()) + 1 + 4;
	char* new_str = new char[len];

	strcpy_s(new_str + 4, len - 4, get_Start());
	if (get_Count() - 1 == 0 && _str != NULL)
	{
		delete []_str;
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
	cout << "�������" << endl;
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

bool operator==(const char* str, const Mstring& src)// char* == Mstring 
{
	cout << " char* == Mstring" << endl;
	return strcmp(str, src.get_Start()) == 0;
}

int main()
{
	char* arr = "yangxingxing";
	char* brr = "hello  world";
	char* crr = "yangxingxing";
	
	Mstring str1 = "yang";
	Mstring str2 = str1;
	Mstring str3 = str1 + str2;
	Mstring str4 = str3;

	str1.show();
	str2.show();
	str3.show();
	str4.show();

	str3[2] = 'w';
	str1.show();
	str2.show();
	str3.show();
	return 0;
}
