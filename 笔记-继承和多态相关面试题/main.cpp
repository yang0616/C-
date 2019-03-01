#include <iostream>
using namespace std;

/*
��ı���˳������-����Ա��-����Ա������
��Ĺ���˳�򣺳�Ա����-�������
����Ĺ��죺����-������
���������������-������
*/

/*
���أ���������ͬ �����б�ͬ ��������ͬ
���أ��������ظ�����ͬ���ĳ�Ա����
���ǣ����า�Ǹ�������ͬ�����Ա����
*/

/*
��������ǿ��ת��
	1��const_cast:ȥ��const���Ե�����ǿת  const int a = 1; int b = const_cast<int> (a);
	2��static_cast:��������Ϊ��ȫ�� int a; double b = static_cast(a);
	3��dynamic_cast:����ʱ�ڵ�ǿת������RTTL
		��������ָ��
		���̳й�ϵ������ָ��
		����RTTL
		 eg:
			class A {virtual void show(){}}; ����
			class B : public A{};            ������
			A* a = new A;
			B* b = new B;
			a = b;  -> a = dynamic_cast<A*> (b);//error return NULL
			������ǿת�ǲ������ģ���Ϊ�����е����ָ����A* ���͵�  ��������������ָ����B*���͵�
			b = a; //error

			B* b = new A;
			A* a = b;     -> a = dynamic_cast<A*> (b)  ->b������ΪB*  *b������ΪA

	4��reinpreter_cast:ǿ��ת�� ��ͬ�ڣ�int��
*/

/*
����̬���̳��еĶ�̬   ����ʱ�ھ����Ķ�̬
����̬��ģ�� ����      �����ھ����Ķ�̬
*/

/*
���ʲôʱ���������������
����ڱ����ڲ�������������ݶε�ֻ���Ρ�.rodata��
*/
/*
����̬���õ�Ҫ��
1��ָ�� ����
2���������µ��麯��
3�������������������������Խ��ж�̬���á�
*/

/*
����ָ��ָ���������ָ����ʲô���ͣ� *ָ����ʲô���ͣ��������к����麯����
Father* f = new Child();
typeid(f).name; ->Father*
typeid(*f).name; ->Child
*/

/*
���๹������������ݣ�����ָ������Լ����麯������������麯��
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
	��ΪBase�ڳ�ʼ��ʱ�Ѿ����Լ����麯��ָ�����㣬����ba����ʵ�00000000��ַ�������
 
	Derive* de = new Derive();
	de->show();   //��ȷ �����Լ���show����
	
	return 0;
}
*/

/*��������麯�������า�ǣ�������ڴ沼��
Base::
		vfptr
		val
Driver::val		
���̳и�������г�Ա�����ͷ����������������еĳ�Ա�����ͷ�����
*/

/*�������麯�����������麯����������ڴ沼�֣�����ָ��ָ����ϵ��������
deleteָ�룬��������������new����delete��ӡָ��ֵ��ָ��ָ�����������࿪ʼ����
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

�ڴ沼��
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

/*���ඨ���麯������ͨ���غ��������ඨ��ͬ������������ͨ�����ͺ���
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

/*����ָ��ָ����ϵ��������delete��������������δ���ã�������������д���麯��
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

/*�����麯���ŵ����У��������麯���ŵ�˽�У��ⲿ����ָ��ָ��������� �ܷ�������˽�к��������
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
��Ϊ�ڱ���ʱ��ָ���Ѿ����ɣ����������������ʱ��ϵͳ��ֻ�ܰ���ָ������������е�˽�г�Ա����
*/


/*������������ͬ�ĺ�������Ĭ��ֵ������ָ��ָ��������󣬵��ú���
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
   p���õ����������е�show���ǻ��ӡ�����е�a��������Ϊ��ʼ����Base���ǲ�û�и��䴫���������Ǹ��ڱ���׶ξͽ�a��ֵ
��ΪBase�����Ĭ��ֵ��������ʱ��P�ҵ���ȷ�ĳ�Ա�����������ڱ���׶��Ѿ���10"push"��ȥ�ˣ�����ֻ��ִ����ȥ�����a����Ϊ10
*/