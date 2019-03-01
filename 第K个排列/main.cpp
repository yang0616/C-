#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getkind(int n)//��n���������з�ʽ������
{
	int tmp = 1;
	while (n > 1)
	{
		tmp *= n;
		n--;
	}
	return tmp;
}

void remove(char* arr, int len, int pos)//�Ƴ������е�һ��Ԫ��
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

void creat(char* arr,int n)//��������
{
	for (int i = 0; i < 10 ; i++)
	{
		if (i < n)
		{
			arr[i] = i + 49;//ת���ɶ�Ӧ���ַ� ���ַ����Ƚ�low ��ֻ��Ϊ�˼򵥾�����д��
			continue;
		}
		arr[i] = '\0';
		//sprintf_s(arr + i, n - i, "%c", i + 1);//Ҳ������sprintf_s����ת���ɶ�Ӧ���ַ�
	}
}

void reserve(char* arr,int len)//��ת�ַ���
{
	char *p1 = NULL;
	char *p2 = NULL;
	p1 = arr;              //ָ��ָ���ַ����Ŀ�ͷ;
	p2 = arr + (len - 1);  //ָ��ָ���ַ��������һ��;
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
	if (n > 9)//�ж�n�Ƿ�Ϸ�
	{
		printf("error!\n");
		return;
	}

	int count = getkind(n);//�ж�k�Ƿ�Ϸ�
	if (k > count || k < 0)
	{
		printf("error!\n");
		return;
	}

	int len = n;
	int integer;//������������
	int reminder;//������������
	char* target = (char *)malloc(sizeof(char)* (n + 1));//����Ŀ������
	char* arr = (char*)malloc(sizeof(char)* (n + 1));//���湹�����м���
	creat(arr, n);//��������
	count = getkind(--n);//������ÿλ������(n-1)������
	int i = 0;
	while (1)
	{
		integer = k / count ;//��Ŀ��
		if (!(reminder = k % count))//ע�⵱����Ϊ0ʱ�̾Ͳ�����Ϊ0����Ϊk��= 0
		{
			integer--;
		}
		target[i++] = arr[integer];//�Ž�Ŀ��
		remove(arr, len, integer);//ɾ��Ԫ��
		if (reminder < 2)//�ж��Ƿ�����˳�������reminder == 1 || reminder == 0��
		{
			if (reminder == 0)//����Ϊ0���������һ������ʽ����ת������ʣ�����
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
  �ڴ����У�������ȷ��������з�ʽ������һ���ַ������������ó���ÿһλ������Ҫ��ȡ
�ʵ��ķ���ת��Ϊ�ַ���ʽ��
*/
class Solution {
public:
	int func(int n) //����n���������з�ʽ
	{
		if (n == 0) return 1;
		else return n * func(n - 1);
	}

	string getPermutation(int n, int k) 
	{
		string result = "";   //����������յ�Ŀ�����з�ʽ���ַ���
		vector<int> v(n + 1); //�൱��������һ�����鼴:v[n+1],
		                      //��vector�ĺô�����������Զ�̬�������д����ݣ�
		                      //����˵���ǡ�n+1������һ����ȷ�����������������õ�
		                      //��ʽ�����������һ����ȷ�ĳ���
		for (int i = 0; i < n; i++)
		{
			v[i] = i + 1;
		}			
		k--;//k-1�������������е�λ��
		for (int i = 1; i <= n; i++) 
		{
			int temp = func(n - i);//��ʣ����� �ж��������з�ʽ
			result += to_string(v[k / temp]);//to_string�����ǽ�int�͵�һϵ�����͵�ֵת��Ϊ��Ӧ���ַ���
			v.erase(v.begin() + k / temp);//ɾ��ָ��ָ���������
			k %= temp;//����k��ֵ
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