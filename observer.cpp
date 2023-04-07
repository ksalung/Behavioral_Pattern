#include "observer.h"

void client_code_ob()
{
	subject* sub = new subject;
	observer* obs1 = new observer(*sub);
	observer* obs2 = new observer(*sub);
	observer* obs3 = new observer(*sub);
	observer* obs4;
	observer* obs5;

	sub->create_message("hello1.");
	obs3->remove_from_list();

	sub->create_message("hello2.");
	obs4 = new observer(*sub);

	obs2->remove_from_list();
	obs5 = new observer(*sub);

	sub->create_message("new message create.");
	obs5->remove_from_list();

	obs4->remove_from_list();
	obs1->remove_from_list();

	delete obs5;
	delete obs4;
	delete obs3;
	delete obs2;
	delete obs1;
}

int main()
{
	client_code_ob();
	return 0;
}