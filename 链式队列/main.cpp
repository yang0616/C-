#include "Queue.h"

int main()
{
	Queue queue;

	//�пղ���
	if(queue.IsEmpty_Queue())
	{
		cout << "queue is empty!" << endl;
	}
	else
	{
		cout << "queue is not empty!" << endl;
	}

	//��Ӳ���
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
	//��ӡ����
	queue.Show_Queue();
	//�󳤶Ȳ���
	int len = queue.Get_len();
	cout << "len = "<< len << endl;

	//���Ӳ���
	cout << "data:";
	for(int i = 0; i < 3; i++)
	{
		int tmp = queue.Get_data();
		//ɾ������
		queue.Pop_Queue();
		cout << tmp << " " ;

	}
	cout << endl;
	queue.Show_Queue();

	return 0;
}