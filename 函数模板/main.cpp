#include <string.h>
#include <assert.h>
#include <iostream>
using namespace std;
/*
2018.11.24
函数模板：
	函数模板
	函数模板的作用域
	函数模板的显式隐式实例化
	特例化：
		完全特例化
		不完全特例化
	重载
	非模板函数	
*/

/*
模板的作用域：
	模板的作用域只在当前
函数模板的编译：
	模板不编译，实例出来的函数代码要进行编译
函数模板类型自推：
	能够根据参数类型自动推演出模板类型参数
模板的实例化：
	编译时期，根据模板调用的类型方式，自动生成一份对应于该类型的代码
	eg：
	template<typename T>
	bool compare(const T a, const T b)
	{
		return a > b;
	}
*/

/*
函数模板的隐式实例化：
	利用模板函数自己实例化类型
	eg:
	void fun
	{
		compare<int>(10,20);
		compare(10.2, 22.1);
	}
函数模板的显示实例化：
	直接给出类型
	eg：
	template bool compare<int>(int a, int b);
	template bool compare<double>(double a, double b);	
*/

/*
函数模板的特例化：
	对特殊情况下的操作
	eg：
	template<>//尖括号里面不写任何东西
	bool compare<const char*>(const char* a, const char* b)
	{
		return strcmp(a, b);
	}
*/

/*
define 和 typedef的区别：
	eg:
	#define char*  charptr;  
	typedef char*  charptr;

	const charptr
	define：不进行类型检查,只进行字符替换 这里的const chatptr等同于 const char * ,const修饰的是char	
	typedef：是对类型的重命名，这里const修饰的为char*
*/

/*
函数模板的重载：

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
模板调用优先级：
	非模板函数-》 模板特例化 -》 模板函数
*/

/*
//代码演示
template<typename T>//函数模板
bool compare(const T a, const T b)
{
	return a > b;
}

bool compare(const double a, const double b)//非模板函数（普通类型函数）
{
	return a > b;
}

typedef char* charstr;//函数模板特例化
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