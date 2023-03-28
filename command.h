#pragma once
#include <iostream>
#include <string>

using namespace std;
__interface Icommand
{
public:
	virtual void excute() const = 0;
}; 

class simple_command : public Icommand
{
private :
	string _pay_load;
public:
	simple_command(string pay_load) : _pay_load(pay_load)//explicit
	{ }
	void excute() const override
	{
		cout << "simpleCommand : printing (" << this->_pay_load <<endl;
	}
};

class receiver
{
public:
	void dosomething(const string& workingdo)
	{
		cout << "receive : working on " << workingdo << "." << endl;
	}
	void dosomthingelse(const std::string& workingdo)
	{
		cout << "receiver : also working on " << workingdo << "." << endl;
	}
};

class complex_command : public Icommand
{
private:
	receiver* _receive;
	string str_a;
	string str_b;
public:
	complex_command(receiver*_receiver, string a, string b):_receive(_receiver), str_a(a), str_b(b)
	{}
	void excute() const override
	{
		cout << "complexCommand : should be done by a receiver." << endl;
		this->_receive->dosomething(this->str_a);
		this->_receive->dosomthingelse(this->str_b);
	}
};

class invoker
{
private:
	Icommand* on_start;
	Icommand* on_finish;
public:
	~invoker()
	{
		delete on_start;
		delete on_finish;
	}

	void set_on_start(Icommand* command)
	{
		this->on_start = command;
	}
	void set_on_finish(Icommand* command)
	{
		this->on_finish = command;
	}

	void do_something_important()
	{
		cout << "Invoker : do anything done before I begin?" << endl;
		if (this->on_start)
		{
			this->on_start->excute();
		}
		cout << "Invoker : doing somthing really impotant..." << endl;
		cout << "something done after finish." << endl;
		if (this->on_finish)
		{
			this->on_finish->excute();
		}
	}
};