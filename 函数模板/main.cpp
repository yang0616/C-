#include <string.h>
#include <assert.h>
#include <iostream>
using namespace std;
/*
2018.11.24
����ģ�壺
	����ģ��
	����ģ���������
	����ģ�����ʽ��ʽʵ����
	��������
		��ȫ������
		����ȫ������
	����
	��ģ�庯��	
*/

/*
ģ���������
	ģ���������ֻ�ڵ�ǰ
����ģ��ı��룺
	ģ�岻���룬ʵ�������ĺ�������Ҫ���б���
����ģ���������ƣ�
	�ܹ����ݲ��������Զ����ݳ�ģ�����Ͳ���
ģ���ʵ������
	����ʱ�ڣ�����ģ����õ����ͷ�ʽ���Զ�����һ�ݶ�Ӧ�ڸ����͵Ĵ���
	eg��
	template<typename T>
	bool compare(const T a, const T b)
	{
		return a > b;
	}
*/

/*
����ģ�����ʽʵ������
	����ģ�庯���Լ�ʵ��������
	eg:
	void fun
	{
		compare<int>(10,20);
		compare(10.2, 22.1);
	}
����ģ�����ʾʵ������
	ֱ�Ӹ�������
	eg��
	template bool compare<int>(int a, int b);
	template bool compare<double>(double a, double b);	
*/

/*
����ģ�����������
	����������µĲ���
	eg��
	template<>//���������治д�κζ���
	bool compare<const char*>(const char* a, const char* b)
	{
		return strcmp(a, b);
	}
*/

/*
define �� typedef������
	eg:
	#define char*  charptr;  
	typedef char*  charptr;

	const charptr
	define�����������ͼ��,ֻ�����ַ��滻 �����const chatptr��ͬ�� const char * ,const���ε���char	
	typedef���Ƕ����͵�������������const���ε�Ϊchar*
*/

/*
����ģ������أ�

template<typename T>
bool compare(T* arr1, int len1, T* arr2, int len2)
{
	cout << "bool compare(T* arr1, int len1, T* arr2, int len2)" << endl;
	int i, j;
	for(i = 0; j = 0; i < len1 && j < len2; i++,j++)
	{
		if(arr1[i] > arr2[j])
		{
			return true;
		}
	}
	if(i == len1)
	{
		return false;
	}
	return false;
}
*/	

/*
ģ��������ȼ���
	��ģ�庯��-�� ģ�������� -�� ģ�庯��
*/

/*
//������ʾ
template<typename T>//����ģ��
bool compare(const T a, const T b)
{
	return a > b;
}

bool compare(const double a, const double b)//��ģ�庯������ͨ���ͺ�����
{
	return a > b;
}

typedef char* charstr;//����ģ��������
template<>
bool compare<charstr>(const charstr a, const charstr b)
{
	return strcmp(a, b) > 0;
}
*/


template<typename C>
bool compare_min(const C a, const C b)
{
	cout << "bool compare(const C a, const C b)"<< endl;
	return a > b;
}

template<>
bool compare_min<char*>( char* a, char* b)
{
	cout << "bool compare<char*>( char* a, char* b)" << endl;
	return strcmp(a, b) > 0;
}

template<typename M,int len>
void Sort_min( M arr[])
{
	cout << "void Sort_min( M arr[],  int len)" << endl;
	M tmp;
	for(int i = 0; i < len; i++)
	{
		for(int j = i; j < len; j++)
		{
			if(compare_min(arr[i], arr[j]))
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main()
{
	//int arr[5] = {3,42,7,65,25};
	char* brr[] = {"acd","vvv","cxa"};
	Sort_min<char*, 3>(brr);
	for(int i = 0; i < 3; i++)
	{
		cout <<brr[i] << " " ;
	}
	cout << endl;

	return 0;
}