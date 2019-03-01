#include <iostream>
using namespace std;

/*
类的编译顺序：类名-》成员名-》成员方法体
类的构造顺序：成员对象-》类对象
子类的构造：父类-》子类
子类的析构：子类-》父类
*/

/*
重载：函数名相同 参数列表不同 作用域相同
隐藏：子类隐藏父类中同名的成员方法
覆盖：子类覆盖父类中相同的许成员方法
*/

/*
四种类型强制转换
	1、const_cast:去掉const属性的类型强转  const int a = 1; int b = const_cast<int> (a);
	2、static_cast:编译器认为安全的 int a; double b = static_cast(a);
	3、dynamic_cast:运行时期的强转，依靠RTTL
		·必须是指针
		·继承关系的类型指针
		·有RTTL
		 eg:
			class A {virtual void show(){}}; 基类
			class B : public A{};            派生类
			A* a = new A;
			B* b = new B;
			a = b;  -> a = dynamic_cast<A*> (b);//error return NULL
			这样的强转是不成立的，因为基类中的虚表指针是A* 类型的  但是派生类的虚表指针是B*类型的
			b = a; //error

			B* b = new A;
			A* a = b;     -> a = dynamic_cast<A*> (b)  ->b的类型为B*  *b的类型为A

	4、reinpreter_cast:强制转换 等同于（int）
*/

/*
动多态：继承中的多态   运行时期决定的多态
静多态：模板 重载      编译期决定的多态
*/

/*
虚表什么时候产生？存放在哪里？
虚表在编译期产生，存放在数据段的只读段【.rodata】
*/
/*
动多态调用的要素
1：指针 引用
2：该类型下的虚函数
3：对象完整【对象不完整不可以进行多态调用】
*/

/*
基类指针指向子类对象，指针是什么类型？ *指针是什么类型？【基类中含有虚函数】
Father* f = new Child();
typeid(f).name; ->Father*
typeid(*f).name; ->Child
*/

/*
基类构造清楚所有数据，基类指针调用自己的虚函数，子类调用虚函数
class Base
{
public:
	Base()
	{
		memset(this, 0, sizeof(Base));//vfptr 00000000
	} 

	virtual void show()
	{
		cout << "Base::virtual void show()" << endl;
	}
};

class Derive :public Base
{
public:
	Derive()
		:Base()
	{

	}

	void show()
	{
		cout << "Derive::void show() " << endl;
	}
};

int main()
{
	Base *ba = new Base();
	ba->show();
	因为Base在初始化时已经将自己的虚函数指针清零，所以ba会访问到00000000地址程序崩溃
 
	Derive* de = new Derive();
	de->show();   //正确 调用自己的show方法
	
	return 0;
}
*/

/*基类存在虚函数，子类覆盖，子类的内存布局
Base::
		vfptr
		val
Driver::val		
【继承父类的所有成员变量和方法，加上子类特有的成员变量和方法】
*/

/*基类无虚函数，子类有虚函数，子类的内存布局，基类指针指向堆上的子类对象，
delete指针，崩溃，重载子类new基类delete打印指针值，指针指向子类对象基类开始部分
class Base
{
public:
	void show()
	{
		cout << " Base::void show()" << endl;
	}

	void operator delete(void* p)
	{
		cout << p << endl;
		free(p);
	}
};

class Derive :public Base
{
public:
	virtual void show()
	{
		cout << "Derive::virtual void show()" << endl;
	}

	void* operator new(size_t size)
	{
		void* p = malloc(size);
		cout << p << endl;
		return p;
	}
};

内存布局
Vfptr
Base::
Derive::

int main()
{
	Base* ba = new Derive();
	ba->show();

	//delete (ba - 4);
	return 0;
}*/

/*基类定义虚函数和普通重载函数，子类定义同名函数隐藏普通函数和函数
class Base
{
public:
	void show();
	virtual void show(int);
};

class Derive :public Base
{
public:
	void show();
};
*/

/*基类指针指向堆上的子类对象，delete，子类析构函数未调用，基类析构函数写成虚函数
class Base
{
public:
	Base()
	{
		cout << "Base()" << endl;
	}

	virtual ~Base()
	{
		cout << "~Base()" << endl;
	}

};

class Derive :public Base
{
public:
	Derive()
	{
		cout << "Derive()" << endl;
	}

	~Derive()
	{
		cout << "~Derive()" << endl;
	}

};

int main()
{
	Base* ba = new Derive();
	delete ba;
	return 0;
}
*/

/*基类虚函数放到共有，派生类虚函数放到私有，外部基类指针指向子类对象 能否派生类私有函数否访问
class Base
{
public:
	virtual void show(int)
	{
		cout << "Base::virtual void show(int)" << endl;
	}
};

class Derive : public Base
{
public:
private:
	void show(int)
	{
		cout << "Deriver::void show(int)" << endl;
	}
};

int main()
{
	Base* ba = new Derive();
	ba->show(10);
	return 0;
}
因为在编译时期指令已经生成，因此在最后代码运行时，系统就只能按照指令访问派生类中的私有成员方法
*/


/*基类和子类给不同的函数参数默认值，基类指针指向子类对象，调用函数
class Base
{
public:
	virtual void show(int a = 10)
	{
		cout << "a=" << a << " ___________" << endl;
	}
};

class Deriver :public Base
{
public:
	void show(int a = 30)
	{
		cout << "a = " << a << endl;
	}
};

int main()
{
	Base* p = new Deriver();
	p->show();
	return 0;
}
   p调用的是派生类中的show但是会打印基类中的a，这是因为开始构造Base我们并没有给其传参数，于是给在编译阶段就将a赋值
成为Base本身的默认值，在运行时，P找到正确的成员函数后，由于在编译阶段已经将10"push"进去了，所以只能执行下去，因此a最终为10
*/