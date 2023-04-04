#include "Memento.h"

void client_code2()
{
	originator* _originator = new originator("super-duper-duper-puper-super.");
	caretaker* _caretaker = new caretaker(_originator);
	_caretaker->backup();
	_originator->funtion();
	_caretaker->backup();
	_originator->funtion();
	_caretaker->backup();
	_originator->funtion();

	_caretaker->show_history();
	_caretaker->undo();
	_caretaker->undo();

	delete _originator;
	delete _caretaker;
}

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	client_code2();
	return 0;
}