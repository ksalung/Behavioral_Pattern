#include "Iterator.h"

void clientcode()
{
	cout << "iterator" << endl;
	container<int> value;
	for (int i = 0; i < 10; i++)
	{
		value.add(i);
	}
	Iterator<int, container<int>> *it = value.create_iterator();
	for (it->First(); it->IsDone(); it->Next())
	{
		cout << *it->current() << endl;
	}
	container<Data> value2;
	Data a(100), b(200), c(300);
	value2.add(a);
	value2.add(b);
	value2.add(c);

	cout << "iterator2" << endl;
	Iterator<Data, container<Data>>* it2 = value2.create_iterator();
	for (it2->First(); it2->IsDone(); it2->Next())
	{
		cout << it2->current()->get_data() << endl;
	}
	delete it;
	delete it2;
}

int main()
{
	clientcode();
	return 0;
}