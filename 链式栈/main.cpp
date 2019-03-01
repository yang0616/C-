#include "Stack.h"

int main()
{
	//ππ‘Ï≤‚ ‘
	Stack stack;

	//øΩ±¥ππ‘Ï≤‚ ‘
	Stack stack1(stack);

	//µ»∫≈‘ÀÀ„≤‚ ‘
	Stack stack2;
	stack2 = stack;

	//≈–ø’≤‚ ‘
	if(stack.IsEmpty_Stack())
	{
		cout << "stack is empty!" << endl;
	}
	else
	{
		cout << "stack is not empty!" << endl;
	}

	//»Î’ª≤‚ ‘
	for(int i = 0; i < 10; i++)
	{
		stack.Push_Stack(i);
	}
	// ‰≥ˆ≤‚ ‘
	stack.Show_Stack();

	if(stack.IsEmpty_Stack())
	{
		cout << "stack is empty!" << endl;
	}
	else
	{
		cout << "stack is not empty!" << endl;
	}

	//µ√µΩ’ª∂•‘™Àÿ
	cout << "data:";
	for(int i = 0; i < 3; i++)
	{
		int tmp = stack.Get_Top_Stack();
		cout << "tmp" << " ";
		stack.Pop_Stack();//≥ˆ’ª≤‚ ‘
	}

	stack.Show_Stack();
	return 0;
}