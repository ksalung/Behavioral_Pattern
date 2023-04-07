#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;
__interface Iobserver
{
public:
	virtual void update(const string& message_from_subject) = 0;
};

__interface Isubject
{
public:
	virtual void attach(Iobserver* observer) = 0;
	virtual void detach(Iobserver* observer) = 0;
	virtual void notify() = 0;
};

class subject : public Isubject
{
private:
	list<Iobserver*> list_observer;
	string message;
public:
	virtual ~subject()
	{
		cout << "goodbye." << endl;
	}
	void attach(Iobserver* observer) override
	{
		list_observer.push_back(observer);
	}
	void detach(Iobserver* observer) override
	{
		list_observer.remove(observer);
	}
	void howmany()
	{
		cout << "There are " << list_observer.size() << "observers in the list." << endl;
	}
	void notify() override
	{
		list<Iobserver*>::iterator iterator = list_observer.begin();
		howmany();
		while (iterator != list_observer.end())
		{
			(*iterator)->update(message);
			++iterator;
		}
	}
	void create_message(string message = "empty")
	{
		this->message = message;
		notify();
	}
	void business_logic()
	{
		this->message = "chage message.";
		notify();
		cout << "I'm about to do some thing important." << endl;
	}
};

class observer : public Iobserver
{
private :
	string message_from_sub;
	subject& _sub;
	static int s_num;
	int num;
public:
	observer(subject& sub) : _sub(sub)
	{
		this->_sub.attach(this);
		cout << "observer excute : " << ++observer::s_num << ". "<< endl;
		this->num = observer::s_num;
	}
	virtual ~observer()
	{
		cout << "goodbye. observer." << this->num << endl;
	}
	void print_info()
	{
		cout << "observer : " << this->num << "new message is available -> " << this->message_from_sub << endl;
	}
	void update(const string& _message_from_sub) override
	{
		message_from_sub = _message_from_sub;
		print_info();
	}
	void remove_from_list()
	{
		_sub.detach(this);
		cout << "observer : " << this->num << "new message is available->" << this->message_from_sub << endl;
	}
};
int observer::s_num = 0;

