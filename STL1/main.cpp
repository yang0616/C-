#include <iostream> 
#include <vector>
#include <iterator>
#include <deque>
#include <list>
#include <map>
#include <string>
using namespace std;

/*
һ��������
	string  int size() const char* c_str()
*/

/*
����˳��������
vector:
������ͷ���ͷɾ
insert�ǰ���λ�ý��в���
�ײ���һλ���飬Ԥ�����ڴ�Ϊ0�������һ��Ԫ�ص�ʱ�򿪱�һ���ռ䣬�Ժ���1.5���ڴ濪�١���ȫ���¿��١�
deque��˫�˶���
�ײ���һ����ά����
list: ����
�ײ���һ��˫������
����û��[]�����
list���� ��������ʧЧ
listɾ�� ����������ʧЧ
*/
int main()
{
	vector<int> v;
	v.push_back(10);//push_back->β��
	
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

	v.pop_back(); //pop_back-> βɾ
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	//v.push_front() ->vector ������ͷ���ͷɾ

	//��λ�ò��롾���������൱��ָ��������Ԫ�ص�ָ�롿
	vector<int>::iterator it = v.begin();
	cout << *it << endl;

	v.insert(it, 20);//insert�ǰ���itָ��ľ���λ�ò�������
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it2 = v.begin();
	for (it2; it2 != v.end(); ) //20 10 0 1 2 2 3 4 5 6 7 8
	{	
		/*ɾ������
		cout << *it2 << " ";
		if (*it2 == 2)
		{
			//v.erase(it2);error ע���������������ʧЧ����ɾ��ʱһ��Ҫ���ܷ��ص��µ�������
			it2 = v.erase(it2);
		}
		else
		{
			it2++;
		}
		*/	

		//�������
		if (*it2 == 3)
		{
			it2 = v.insert(it2, 888);
			it2 += 2; //ע��������������
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
	l.push_back(10); //���
	l.push_front(20); //ͷ��
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

	l.pop_back();//βɾ
	l.pop_front();//ͷɾ

	it3 = l.begin();
	for (it3; it3 != l.end(); it3++)
	{
		cout << *it3 << " ";
	}
	cout << endl;

	it3--;//��ʱ������It3ָ��������һ��Ԫ��
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
			it3 = l.erase(it3); //ɾ�� ��������ʧЧ
			l.insert(it3, 999);//�������������ʧЧ
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

	/*map������ֲ��뷽ʽ*/
	m.insert(make_pair(1, "100"));
	m.insert(map<int, string>::value_type(2, "200"));
	m.insert(pair<int, string>(3, "300"));

	/*
	ͨ�ù�ʽΪ��make_pair == pair<keyType, valType> == map<keyType, valType>::value_type
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
		cout << it4->first << "��" << it4->second << endl;
	}


	it4 = m.find(7);
	cout << it4->first << ":" << it4->second << endl;
	cout << m[7] << endl;

	it4 = m.begin();
	for (it4; it4 != m.end(); it4++)
	{
		if (it4->first == 7)
		{
			it4 = m.erase(it4); //ɾ����������ʧЧ
			m.insert(make_pair(88, "8800")); //�������������ʧЧ
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
������������
	set������
		���Լ�����
		�ײ���һ�������
		�����ʱ�临�Ӷ�Ϊlog2n
		valֵ�������ظ����������޸�
	map��ӳ���
		��ż�ֵ��-��key-val
		���Լ�����
		�ײ���һ�������
		�����ʱ�临�Ӷ�Ϊlog2n
		keyֵ�������ظ����������޸�
		ɾ��ʱ������ʧЧ��ɾ��ʱһ��Ҫ���ܷ��ص��µ�������
		����ʱ����������ʧЧ����Ϊ��������ʱ��������������
	multiset�����ؼ���
		����val�ظ�
	multimap������ӳ���
		����keyֵ�ظ�
*/

/*
�ġ�������������������֮��Ĵ����ϵ��
stack��ջ
	�ײ���deque
	������ʹ�õ�����
queue������
	�ײ���deque
	������ʹ�õ�����
prity_queue�����ȶ���
	�ײ���vector
	Ĭ��Ϊ�����
	������ʹ�õ�����
*/

//17069