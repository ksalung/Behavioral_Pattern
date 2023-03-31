#pragma once
#include <iostream>
#include <string>

using namespace std;

class base_component;
__interface IMediator
{
public:
	virtual void notify(base_component* sender, string event) const = 0;
}; 

class base_component
{
protected:
	IMediator* _mediator;
public:
	base_component(IMediator* mediator = nullptr) : _mediator(mediator)
	{
	}
	void set_mediator(IMediator* mediator)
	{
		this->_mediator = mediator;
	}
};

class component : public base_component
{
public:
	void funtionA()
	{
		cout << "component A : " << endl;
		this->_mediator->notify(this, "A");
	}
	void funtionB()
	{
		cout << "component B : " << endl;
		this->_mediator->notify(this, "B");
	}
};

class component2 : public base_component
{
public:
	void funtionC()
	{
		cout << "component C : " << endl;
		this->_mediator->notify(this, "C");
	}
	void funtionD()
	{
		cout << "component D : " << endl;
		this->_mediator->notify(this, "D");
	}
};

class concrete_meidator : public IMediator
{
private:
	component* _component1;
	component2* _component2;

public:
	concrete_meidator(component* com, component2* com2) : _component1(com), _component2(com2)
	{
		this->_component1->set_mediator(this);
		this->_component2->set_mediator(this);
	}
	void notify(base_component* sender, string event) const override
	{
		if (event == "A")
		{
			cout << "Mediator : A" << endl;
			this->_component2->funtionC();
		}
		if (event == "D")
		{
			cout << "Mediator : D" << endl;
			this->_component1->funtionB();
			this->_component2->funtionC();
		}
	}
};

