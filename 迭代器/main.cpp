#include <iostream>
#include <string.h>
#include <vector>
#include <iterator>
#include "Miterator.h"
using namespace std;

int main()
{
	cout << "************************************************************" << endl;
	cout << "ϵͳstring�͵�����" << endl;
	string str = "hello";
	string::iterator it = str.begin();//���������Լ򵥵�����ָ��������Ԫ�ص�ָ��
	for (it; it != str.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "************************************************************" << endl;
	cout << "�Լ�ʵ��string�͵�����" << endl;
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
