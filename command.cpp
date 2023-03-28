#include "command.h"
int main()
{
	invoker* _invoker = new invoker;
	_invoker->set_on_start(new simple_command("hi"));
	receiver* _receiver = new receiver;
	_invoker->set_on_finish(new complex_command(_receiver, "send email", "save report"));
	_invoker->do_something_important();

	delete _invoker;
	delete _receiver;
	return 0;
}