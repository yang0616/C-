#include "Stack.h"

int main()
{
	//�������
	Stack stack;

	//�����������
	Stack stack1(stack);

	//�Ⱥ��������
	Stack stack2;
	stack2 = stack;

	//�пղ���
	if(stack.IsEmpty_Stack())
	{
		cout << "stack is empty!" << endl;
	}
	else
	{
		cout << "stack is not empty!" << endl;
	}

	//��ջ����
	for(int i = 0; i < 10; i++)
	{
		stack.Push_Stack(i);
	}
	//�������
	stack.Show_Stack();

	if(stack.IsEmpty_Stack())
	{
		cout << "stack is empty!" << endl;
	}
	else
	{
		cout << "stack is not empty!" << endl;
	}

	//�õ�ջ��Ԫ��
	cout << "data:";
	for(int i = 0; i < 3; i++)
	{
		int tmp = stack.Get_Top_Stack();
		cout << "tmp" << " ";
		stack.Pop_Stack();//��ջ����
	}

	stack.Show_Stack();
	return 0;
}