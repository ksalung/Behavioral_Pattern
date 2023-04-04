#include "Mediator.h"

void client_code()
{
	component* com = new component;
	component2* com2 = new component2;
	concrete_meidator* mediator = new concrete_meidator(com, com2);
	cout << "client A : " << endl;
	com->funtionA();
	cout << "client D : " << endl;
	com2->funtionD();

	delete com;
	delete com2;
	delete mediator;
}

//int main()
//{
//	client_code();
//	return 0;
//}