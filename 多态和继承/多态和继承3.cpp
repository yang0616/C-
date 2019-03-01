#include <iostream>
using namespace std;

/*
菱形继承是什么？
	一个派生类D是由多继承产生的，他的多个基类B、C继承了同一个基类A，造成派生类D中会具有多份A类
的属性是一种不合理的现象
菱形继承会有什么问题？
	会让高层的基类在底层的派生类会拥有多个成员，造成不合理
菱形继承怎么解决？
	利用虚继承解决，在虚继承中会在本来保存虚基类的地方保存vbptr
	如果一个类中有重复的虚基类，就会让多个vbptr指向同一个虚基类作用域
*/

/*
拥有纯虚函数的类和拥有虚函数的类的比较：【虚基类和抽象类的比较】
	纯虚函数的类在其派生类中必须定义自己这个函数的版本，而且纯虚函数是没有实际意义的，他的目的
告知编译器派生类将会定义自己的版本。
	类中拥有纯虚函数表示这个类是抽象类，不存在此类的对象。而虚函数仅表示派生类可以定义自己的版本，
但是基类也可以有意义，若没有定义自己的版本，将使用基类的版本。
*/

//////////////////////////////////////////////////////////////////
class A  //虚基类
{
public:
	int _a;
};

class B : public A
{
public:
	int _b;
};

class C : public A
{
public:
	int _c;
};

class D :public B, public C
{
public:
	int _d;
};

/*
D的内存布局
	B::
		A::_a
		_b
	C::
		A::_a
		_c
	_d
*/
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
class A  //虚基类
{
public:
	int _a;
};

class B : virtual public A
{
public:
	int _b;
};

class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

/*
D的内存布局
	B::
		vbptr ---->vbtable
		_b
	C::
		vbptr ---->vbtable
		_c
	_d
	A::
		_a
*/
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
class A//虚基类
{
public:
	int _a;
	virtual void show()
	{}
};

class B :virtual public A
{
public:
	int _b;
	virtual void showA()
	{}
};

class C : virtual public A
{
public:
	int _c;
	virtual void showC()
	{}
};

class D : public B, public C
{
public:
	int _d;
	virtual void showB()
	{}
	virtual void showC()
	{}
};

/*
D的内存布局 ????
	B::
		vfptr --->D 0 show
		vbptr --->-4 20
		_b
	C::
		vbptr --->0 12
		_c
	_d
	A::
		_a
*/
//////////////////////////////////////////////////////////////////
	
//////////////////////////////////////////////////////////////////
/*
cd 打开文件夹
dir 查看文件夹下的文件
CL(小写) main.cpp /d1reportSingleClassLayoutDerive  > log.txt
start log.txt
*/
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
/*
拥有纯虚函数的类叫抽象类或者接口类  
特征：不能实例化对象，强制派生类必须实现此函数。派生类必须实现该成员方法后才能使用
*/
class Base
{	
public:
	virtual void show() = 0;//纯虚函数
	/*
		纯虚函数是一种特殊的虚函数，在许多情况下，在基类中不能对虚函数给出有意义的实现，
	而把它声明为纯虚函数，它的实现留给该基类的派生类去做。这就是纯虚函数的作用。
	*/
};

class Driver:public Base
{
public:
	//实现基类的穿虚函数
	virtual void show()
	{
		cout << "virtual void show()" << endl;
	}
	int _dirver;
};
//////////////////////////////////////////////////////////////////

int main()
{

	return 0;
}