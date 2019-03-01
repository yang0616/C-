#include "Queue.h"

int main()
{
	Queue queue;

	//≈–ø’≤‚ ‘
	if(queue.IsEmpty_Queue())
	{
		cout << "queue is empty!" << endl;
	}
	else
	{
		cout << "queue is not empty!" << endl;
	}

	//»Î∂”≤‚ ‘
	for(int i = 0; i < 10; i++)
	{
		queue.Push_Queue(i);
	}

	if(queue.IsEmpty_Queue())
	{
		cout << "queue is empty!" << endl;
	}
	else
	{
		cout << "queue is not empty!" << endl;
	}
	//¥Ú”°≤‚ ‘
	queue.Show_Queue();
	//«Û≥§∂»≤‚ ‘
	int len = queue.Get_len();
	cout << "len = "<< len << endl;

	//≥ˆ∂”≤‚ ‘
	cout << "data:";
	for(int i = 0; i < 3; i++)
	{
		int tmp = queue.Get_data();
		//…æ≥˝≤‚ ‘
		queue.Pop_Queue();
		cout << tmp << " " ;

	}
	cout << endl;
	queue.Show_Queue();

	return 0;
}