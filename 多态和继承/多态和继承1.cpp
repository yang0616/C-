#include <iostream>
#include <string>
using namespace std;

#if 0
/*
类与类之间的关系：
组合：一个类是另一个类的一部分
代理：一个类的方法是另一个类方法的子集
继承：一个类是另一个类的一种
*/

class animal //12
{
public:
	int a;
private:
	int b;
protected:
	int a1;
};

class cat :public animal //20
{
public:
	int c;
	/*
	子类无法访问父类的私有成员
	cout << a << "" << b << " " << c << " "<< endl;//error
	*/
private:
	int d;
	/*
	父类的protected成员只可以被子类访问，但是不可以被外界访问

	*/
};

class whiteCat : cat//不写代表默认为public
{
public:
	void show()
	{

	}

};

/*
父类                    继承方式                子类                外界
public                   public                  public
                         protected               protected
                         private                 private
						  

protected                public                   protected
                         protected                protected
                         private                  private

private                  public                    *
                         protected                 *
						 private                   *
*/

/*
构造：
先构造成员对象 再构造类对象
先构造父类 再构造子类
【注意如果父类中的成员方法必须需要外界为其提供参数，就必须写在参数列表中先构造】
*/

/*
析构：
先析构子类 再析构父类
*/

/*
成员方法之间的关系：
重载：作用域相同、函数名相同、参数列表不同
	  子类和父类之间不可能形成函数重载，因为作用域永远不可能相同
隐藏：子类会隐藏父类中成员方法相同的成员
覆盖（重写）：子类中的成员方法和父类中的相同虚成员方法【同函数名、返回值、函数名】构成覆盖关系
      【只会发生在虚函数表中】

*/

#endif


class Animal
{
public:
	Animal(string name)
		:_name(name)//放在初始化列表中的一定是构造，如果不能初始化，就代表已经被构造过了
	{

	}

	void eat()
	{
		cout << _name << "：eat eat ……" << endl;
	}

	void call()
	{
		cout << _name << "：call" << endl;
	}
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

	void call()
	{
		cout << _name << "：我是小猫 喵喵喵！" << endl;
	}
};


/*
父类对象--》子类对象//error 因为子类中的成员必定大于等于父类
子类对象--》父类对象//ok 继承关系中提供有子类构造父类的函数
                    //先用子类构造一个父类对象，然后用此父类对象进行赋值			
父类指针--》子类指针//error 相同的道理 如果赋值成功了，子类的指针就会访问自己的成员，
                    //但实际上，子类的成员已经不存在，增加了无效的可访问内存
子类指针--》父类指针//ok 这样的赋值虽然会造成子类的成员丢失，但是不会造成访问出错，所以成立
*/

/*
virtual 修饰的函数叫虚函数 虚函数存在再虚函数表中
父类中的虚函数继承到子类中 同样是虚函数【同返回值、同名、同参数列表】
*/

/*
多态
静多态：重载 、模板【编译时期的多态即在编译的时候就是知道了应该用那个函数、应该是什么类型】       
动多态：在继承中的多态【在运行时期的多态即在程序运行时才会知道用那个函数】

动多态发生的条件
	1：一定是指针调用
	2:virtual关键字（虚函数）
*/

int main()
{                                 
	Cat cat("cat");
	cat.eat();
	cat.call();

	Animal* pa = new Cat("cat"); //父类指针指向子类对象
	return 0;
}

/*
作业：
	什么时候析构函数必须写成虚函数？
	构造函数是否能够写成虚函数？
	inline函数是否能写成虚函数？
	static函数是否能够写成虚函数？
*/