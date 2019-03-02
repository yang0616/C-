#include "MyVector.h"

int main()
{
	MyVector<int> v1;
	v1.reserve(5);

	for (int i = 0; i < 10; i++)
	{
		v1.Push_back(i);
	}

	v1.Show();

	cout << v1.Back() << endl;
	cout << v1.Front() << endl;
	
	v1.Pop_back();
	v1.Show();

	MyVector<int> ::iterator it = v1.begin();

	for (it; it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}