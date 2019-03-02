#include <iostream> 
#include <vector>
#include <iterator>
#include <deque>
#include <list>
#include <map>
#include <string>
using namespace std;

/*
一、仿容器
	string  int size() const char* c_str()
*/

/*
二、顺序容器：
vector:
不存在头插和头删
insert是按照位置进行插入
底层是一位数组，预开辟内存为0，插入第一个元素的时候开辟一个空间，以后按照1.5倍内存开辟【完全重新开辟】
deque：双端队列
底层是一个二维数组
list: 链表
底层是一个双向链表
链表没有[]运算符
list插入 迭代器不失效
list删除 迭代器将会失效
*/
int main()
{
	vector<int> v;
	v.push_back(10);//push_back->尾插
	
	cout << v[0] << endl;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		if (i == 2)
		{
			v.push_back(2);
		}
	}

	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.pop_back(); //pop_back-> 尾删
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	//v.push_front() ->vector 不存在头插和头删

	//按位置插入【迭代器就相当于指向容器内元素的指针】
	vector<int>::iterator it = v.begin();
	cout << *it << endl;

	v.insert(it, 20);//insert是按照it指向的具体位置插入数据
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it2 = v.begin();
	for (it2; it2 != v.end(); ) //20 10 0 1 2 2 3 4 5 6 7 8
	{	
		/*删除操作
		cout << *it2 << " ";
		if (*it2 == 2)
		{
			//v.erase(it2);error 注意这句会引起迭代器失效【在删除时一定要接受返回的新迭代器】
			it2 = v.erase(it2);
		}
		else
		{
			it2++;
		}
		*/	

		//插入操作
		if (*it2 == 3)
		{
			it2 = v.insert(it2, 888);
			it2 += 2; //注意这里是走两步
		}
		else
		{
			it2++;
		}
		
	}
	cout << endl;

	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	cout <<"****************************" <<  endl;
	list<int> l;
	l.push_back(10); //后插
	l.push_front(20); //头插
	for (int i = 100; i < 120; i++)
	{
		l.push_back(i);
	}

	list<int>::iterator it3 = l.begin();
	for (it3; it3 != l.end(); it3++)
	{
		cout << *it3 << " ";
	}
	cout << endl;

	l.pop_back();//尾删
	l.pop_front();//头删

	it3 = l.begin();
	for (it3; it3 != l.end(); it3++)
	{
		cout << *it3 << " ";
	}
	cout << endl;

	it3--;//此时迭代器It3指向的是最后一个元素
	l.insert(it3, 888);
	it3 = l.begin();
	for (it3; it3 != l.end(); it3++)
	{
		cout << *it3 << " ";
	}
	cout << endl;

	it3 = l.begin();
	for (it3; it3 != l.end(); it3++)
	{
		if (*it3 == 106)
		{
			it3 = l.erase(it3); //删除 迭代器会失效
			l.insert(it3, 999);//插入迭代器不会失效
		}
	}
	it3 = l.begin();
	for (it3; it3 != l.end(); it3++)
	{
		cout << *it3 << " ";
	}
	cout << endl;

	cout << "****************************" << endl;
	map<int, string> m;

	/*map表的三种插入方式*/
	m.insert(make_pair(1, "100"));
	m.insert(map<int, string>::value_type(2, "200"));
	m.insert(pair<int, string>(3, "300"));

	/*
	通用公式为：make_pair == pair<keyType, valType> == map<keyType, valType>::value_type
	*/

	m.insert(make_pair(4, "400"));
	m.insert(make_pair(5, "500"));
	m.insert(make_pair(0, "0"));
	m.insert(make_pair(8, "800"));
	m.insert(make_pair(6, "600"));
	m.insert(make_pair(7, "700"));
	m.insert(make_pair(4, "400"));

	map<int, string>::iterator it4 = m.begin();
	for (it4; it4 != m.end(); it4++)
	{
		cout << it4->first << "：" << it4->second << endl;
	}


	it4 = m.find(7);
	cout << it4->first << ":" << it4->second << endl;
	cout << m[7] << endl;

	it4 = m.begin();
	for (it4; it4 != m.end(); it4++)
	{
		if (it4->first == 7)
		{
			it4 = m.erase(it4); //删除迭代器会失效
			m.insert(make_pair(88, "8800")); //插入迭代器不会失效
		}
	}
	it4 = m.begin();
	for (it4; it4 != m.end(); it4++)
	{
		cout << it4->first << ":" << it4->second << endl;
	}
	return 0;
}



/*
三、关联容器
	set：集合
		会自己排序
		底层是一个红黑树
		插入的时间复杂度为log2n
		val值不允许重复、不允许修改
	map：映射表
		存放键值对-》key-val
		会自己排序
		底层是一个红黑树
		插入的时间复杂度为log2n
		key值不允许重复、不允许修改
		删除时迭代器失效【删除时一定要接受返回的新迭代器】
		插入时迭代器不会失效【因为插入数据时候不依靠迭代器】
	multiset：多重集合
		允许val重复
	multimap：多重映射表
		允许key值重复
*/

/*
四、容器适配器【类与类之间的代理关系】
stack：栈
	底层是deque
	不允许使用迭代器
queue：队列
	底层是deque
	不允许使用迭代器
prity_queue：优先队列
	底层是vector
	默认为大根堆
	不允许使用迭代器
*/

//17069