/*
多态：
	1、静多态【重载、模板；编译时期发生的多态】
	2、动多态【继承的多态；运行时期发生的多态】

动多态发生的要素：
	1、一定是指针的解引用
	2、解引用访问的一定是虚函数或者类型

构造：先构造父类（基类）后构造子类（派生类）
析构：先析构子类后析构父类

以下情况下析构函数必须写成虚函数：
	1、存在基类指针指向堆上的子类对象的时候

可不可以写成虚函数表：
	1、static【不可以，因为没有this指针，无法找到对象的地址就无法找到虚函数表，static函数可以不依赖对象调用】
	2、inline【不可以，编译器在调用点展开，realse版本没有地址】
	3、构造【不可以，对象没有产生，无法调用】
	4、析构【可以】
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
	纯虚函数：拥有纯虚函数的类成为虚基类，虚基类不允许实例化对象
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
		cout << _name << ":喵喵喵" << endl;
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
		cout << _name << ":汪汪汪" << endl;
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