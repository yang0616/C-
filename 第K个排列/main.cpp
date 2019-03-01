#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getkind(int n)//求n个数的排列方式的种类
{
	int tmp = 1;
	while (n > 1)
	{
		tmp *= n;
		n--;
	}
	return tmp;
}

void remove(char* arr, int len, int pos)//移除数组中的一个元素
{
	for (int i = pos; i < len ; i++)
	{
		if (pos == len - 1)
		{
			arr[pos] = 'd';
			return;
		}
		arr[i] = arr[i + 1];
	}
	return ;
}

void creat(char* arr,int n)//构造数组
{
	for (int i = 0; i < 10 ; i++)
	{
		if (i < n)
		{
			arr[i] = i + 49;//转换成对应的字符 这种方法比较low 我只是为了简单就这样写了
			continue;
		}
		arr[i] = '\0';
		//sprintf_s(arr + i, n - i, "%c", i + 1);//也可以用sprintf_s函数转化成对应的字符
	}
}

void reserve(char* arr,int len)//翻转字符串
{
	char *p1 = NULL;
	char *p2 = NULL;
	p1 = arr;              //指针指向字符串的开头;
	p2 = arr + (len - 1);  //指针指向字符串的最后一个;
	while (p1 < p2)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		++p1;
		--p2;
	}
	return;
}

void getPermutation(int n, int k)
{
	if (n > 9)//判断n是否合法
	{
		printf("error!\n");
		return;
	}

	int count = getkind(n);//判断k是否合法
	if (k > count || k < 0)
	{
		printf("error!\n");
		return;
	}

	int len = n;
	int integer;//保存正数部分
	int reminder;//保存余数部分
	char* target = (char *)malloc(sizeof(char)* (n + 1));//保存目标排列
	char* arr = (char*)malloc(sizeof(char)* (n + 1));//保存构造数列集合
	creat(arr, n);//构造数组
	count = getkind(--n);//集合中每位数都有(n-1)种排序
	int i = 0;
	while (1)
	{
		integer = k / count ;//求目标
		if (!(reminder = k % count))//注意当余数为0时商就不可能为0，因为k！= 0
		{
			integer--;
		}
		target[i++] = arr[integer];//放进目标
		remove(arr, len, integer);//删除元素
		if (reminder < 2)//判断是否符合退出条件（reminder == 1 || reminder == 0）
		{
			if (reminder == 0)//余数为0代表是最后一种排序方式，翻转集合中剩余的数
			{
				reserve(arr, strlen(arr));
			}
			for (int j = 0; arr[j] != '\0'; j++)
			{
				target[i++] = arr[j];
			}
			target[i] ='\0';
			break;
		}
		count = getkind(--n);
	}	
	printf("%s\n", target);
	free(target);
	free(arr);
}


/*
  在此题中，首先明确输出的排列方式必须是一个字符串，所以最后得出的每一位数，都要采取
适当的方法转换为字符形式。
*/
class Solution {
public:
	int func(int n) //计算n个数的排列方式
	{
		if (n == 0) return 1;
		else return n * func(n - 1);
	}

	string getPermutation(int n, int k) 
	{
		string result = "";   //用来存放最终的目标排列方式的字符串
		vector<int> v(n + 1); //相当于申请了一个数组即:v[n+1],
		                      //用vector的好处就是这里可以动态往数组中存数据，
		                      //简单来说就是“n+1”不是一个明确的数，我们往常惯用的
		                      //方式，这里必须是一个明确的常量
		for (int i = 0; i < n; i++)
		{
			v[i] = i + 1;
		}			
		k--;//k-1便于求在数组中的位置
		for (int i = 1; i <= n; i++) 
		{
			int temp = func(n - i);//算剩余的数 有多少种排列方式
			result += to_string(v[k / temp]);//to_string函数是将int型等一系列类型的值转换为对应的字符串
			v.erase(v.begin() + k / temp);//删除指针指向的数据项
			k %= temp;//更新k的值
		}
		return result;
	}
};

int main()
{
	//getPermutation(4, 2);
	Solution soluction;
	string tmp = soluction.getPermutation(3,1);
	cout << tmp << endl;
	/*char arr[10] = "";
	creat(arr, 7);
	printf("%s\n",arr);
	reserve(arr, strlen(arr));
	printf("%s\n", arr);
	remove(arr, strlen(arr), 1);
	printf("%s\n", arr);*/
	return 0; 
}