#include "Queue.h"

int main()
{
	Queue queue;

	for(int i = 0; i < 2; i++)
	{
		queue.Push_queue(i); 
	}

	queue.Show_Queue();

	int res = 0;
	for(int i = 0; i < 3; i++)
	{
		if(queue.Pop_queue(&res))
		{
			cout << "res = "<< res << endl;
		}
		else
		{
			cout <<"error!"<<endl;
		}
	}
	
	queue.Show_Queue();


	return 0;
}