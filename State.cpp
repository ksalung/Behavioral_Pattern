#include "State.h"

void client_state()
{
	Context* context = new Context(new concretestateA);
	context->request1();
	context->request2();
	delete context;
}

int main()
{
	client_state();
	return 0;
}