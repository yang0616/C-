/*
��̬��
	1������̬�����ء�ģ�壻����ʱ�ڷ����Ķ�̬��
	2������̬���̳еĶ�̬������ʱ�ڷ����Ķ�̬��

����̬������Ҫ�أ�
	1��һ����ָ��Ľ�����
	2�������÷��ʵ�һ�����麯����������

���죺�ȹ��츸�ࣨ���ࣩ�������ࣨ�����ࣩ
�������������������������

���������������������д���麯����
	1�����ڻ���ָ��ָ����ϵ���������ʱ��

�ɲ�����д���麯����
	1��static�������ԣ���Ϊû��thisָ�룬�޷��ҵ�����ĵ�ַ���޷��ҵ��麯����static�������Բ�����������á�
	2��inline�������ԣ��������ڵ��õ�չ����realse�汾û�е�ַ��
	3�����졾�����ԣ�����û�в������޷����á�
	4�����������ԡ�
*/

#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	Animal(string name)   
	 :_name(name)      
	{

	}

	/*
	���麯����ӵ�д��麯�������Ϊ����࣬����಻����ʵ��������
	*/
	virtual void Call() = 0;

	/*
	virtual void Call()
	{
		cout << "I am a ..." << endl;
	}
	*/

protected:
	string _name;	
};

class Cat :public Animal
{
public:
	Cat(string name)
		:Animal(name)
	{

	}

	void Call()
	{
		cout << _name << ":������" << endl;
	}
protected:
};

class Dog :public Animal
{
public:
	Dog(string name)
		:Animal(name)
	{

	}

	void Call()
	{
		cout << _name << ":������" << endl;
	}
protected:
};


int main()
{
	Cat cat("cat");
	//cat.Call();

	Dog dog("dog");
	//dog.Call();

	int* p1 = (int *)&cat;
	int* p2 = (int *)&dog;
	
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
	 
	Cat* cat1 = &cat;
	Dog* dog1 = &dog;

	cat1->Call();
	dog1->Call();

	return 0;
}




/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode* tmp = NULL;
		int count1 = 0;
		int count2 = 0;
		ListNode* tmp1 = l1;
		ListNode* tmp2 = l2;
		while (tmp1 != NULL)
		{
			count1++;
			tmp1 = tmp1->next;
		}

		while (tmp2 != NULL)
		{
			count2++;
			tmp2 = tmp2->next;
		}

		int differ = tmp1 - tmp2;
		ListNode* first = new ListNode();

		if (differ > 0)
		{
			while (differ > 0)
			{
				first->val = l1->val;
				first->next = new ListNode();
				first = first->next;
				l1 = l1->next;
				differ--;
			}
		}

		if (differ < 0)
		{
			while (differ < 0)
			{
				first->val = l2->val;
				first->next = new ListNode();
				first = first->next;
				l2 = l2->next;
				differ++;
			}
		}

		ListNode* second = first->next;
		second->next = new ListNode();

		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val + l2->val >= 10)
			{

			}
		}

	}
};
*/