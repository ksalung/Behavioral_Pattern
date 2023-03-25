#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

__interface Ihandler
{
public:
	virtual Ihandler* set_next(Ihandler* _handler) = 0;
	virtual string handle(string request) = 0;
}; 

class abstract_handler : public Ihandler
{
private:
	Ihandler* next_handler;
public:
	abstract_handler() : next_handler(nullptr) {	}
	Ihandler* set_next(Ihandler* handler) override
	{
		this->next_handler = handler;
		return handler;
	}
	string handle(string request) override
	{
		if (this->next_handler)
		{
			return this->next_handler->handle(request);
		}
		return {};
	}
};

class monkey_handler : public abstract_handler
{
public:
	string handle(string request) override
	{
		if (request == "banana")
		{
			return "monkey : I'll eat the " + request + ".\n";
		}
		else {
			return abstract_handler::handle(request);
		}
	}
};

class squirrel_handler : public abstract_handler
{
public:
	string handle(string request) override
	{
		if(request == "nut")
		{ 
			return "Squirrel : I'll eat the " + request + ".\n";
		}
		else {
			return abstract_handler::handle(request);
		}
	}
};

class dog_handler : public abstract_handler
{
public:
	string handle(string request) override
	{
		if (request == "meatball")
		{
			return "dog : I'll eat the " + request + "./ n";
		}
		else {
			return abstract_handler::handle(request);
		}
	}
};

