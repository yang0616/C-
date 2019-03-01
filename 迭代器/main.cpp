#include <iostream>
#include <string.h>
#include <vector>
#include <iterator>
#include "Miterator.h"
using namespace std;

int main()
{
	cout << "************************************************************" << endl;
	cout << "系统string和迭代器" << endl;
	string str = "hello";
	string::iterator it = str.begin();//迭代器可以简单地理解成指向容器内元素的指针
	for (it; it != str.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "************************************************************" << endl;
	cout << "自己实现string和迭代器" << endl;
	Mstring mstr = "yxx";
	Mstring::iterator mit = mstr.begin();
	for (mit; mit != mstr.end(); mit++)
	{
		cout << *mit << " ";
	}
	cout << endl;
	cout << "************************************************************" << endl;
	return 0;
}
