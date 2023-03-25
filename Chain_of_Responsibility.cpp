#include "Chain_of_Responsibility.h"

void client_code(Ihandler& handler)
{
	vector<string> food{ "nut", "banana", "cup of coffee" };
	for (const string& f : food)
	{
		cout << "client : who wants a " << f << "?" << endl;
		const string result = handler.handle(f);
		if (!result.empty())
		{
			cout << " " << result;
		}
		else {
			cout << " " << f << "was left untouched." << endl;
		}
	}
}


int main()
{
	monkey_handler* monkey = new monkey_handler;
	squirrel_handler* squirrel = new squirrel_handler;
	dog_handler* dog = new dog_handler;
	monkey->set_next(squirrel)->set_next(dog);

	cout << "chain : monkey < squirrel < dogn" << endl;
	client_code(*monkey);
	cout << "subchain : squirrel > dog " << endl;
	client_code(*squirrel);

	delete monkey;
	delete squirrel;
	delete dog;

	return 0;
}