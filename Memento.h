#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
__interface IMemento
{
public:
	virtual string get_name() const = 0;
	virtual string date() const = 0;
	virtual string state() const = 0;
};

class concrete_memento : public IMemento
{
private:
	string _state;
	string _date;
public:
	concrete_memento(string state) : _state(state)
	{
		this->_state = state;
		time_t now = time(0);
		this->_date = ctime(&now);
	}
	string state() const override
	{
		return this->_state;
	}
	string get_name() const override
	{
		return this->_date + "/ ( " + this->_state.substr(0, 9) + "...)";
	}
	string date() const override
	{
		return this->_date;
	}
};

class originator
{
private:
	string _state;
public:
	string generate_string(int len = 10)
	{
		const char alphanum[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		int string_len = sizeof(alphanum) - 1;

		string random_string;
		for (int i = 0; i < len; i++)
		{
			random_string += alphanum[rand() % string_len];
		}
		return random_string;
	}
	originator(string state) :_state(state)
	{
		cout << "originator : initial state is " << this->_state << endl;
	}

	void funtion()
	{
		cout << "originator : do something." << endl;
		this->_state = this->generate_string(30);
		cout << "originaor : and my state has chaged to " << this->_state << endl;
	}
	IMemento* save()
	{
		return new concrete_memento(this->_state);
	}
	void restore(IMemento* memento)
	{
		this->_state = memento->state();
		cout << "orginator : state changed to " << this->_state << endl;
	}
};
class caretaker
{
private:
	vector < IMemento*> vec_me;
	originator* _originator;
public:
	caretaker(originator* originator) :_originator(originator)
	{}
	~caretaker()
	{
		for (auto m : vec_me) delete m;
	}
	void backup()
	{
		cout << "caretaker : saving originator state " << endl;
		this->vec_me.push_back(this->_originator->save());
	}
	void undo()
	{
		if (!this->vec_me.size())
		{
			return;
		}
		IMemento* memento = this->vec_me.back();
		this->vec_me.pop_back();
		cout << "restore :  restoring state to : " << memento->get_name() << endl;
		try
		{
			this->_originator->restore(memento);
		}
		catch (...)
		{
			this->undo();
		}
	}
	void show_history()
	{
		cout << "caretaker : mementos list" << endl;
		for (IMemento* memento : this->vec_me)
		{
			cout << memento->get_name() << endl;
		}
	}
};

