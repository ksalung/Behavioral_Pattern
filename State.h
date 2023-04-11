#pragma once
#include <iostream>
#include <string>

using namespace std;
class Context;
class State
{
protected:
	Context* context;
public:
	void set_context(Context* context)
	{
		this->context = context;
	}
	virtual void handle1() = 0;
	virtual void handle2() = 0;
};

class Context
{
private:
	State* _state;
public:
	Context(State* state) :_state(nullptr)
	{
		this->Transition_to(state);
	}

	void Transition_to(State* state)
	{
		cout << "transition to" << typeid(*state).name() << endl;
		if (this->_state != nullptr)
			delete this->_state;
		this->_state = state;
		this->_state->set_context(this);
	}
	void request1()
	{
		this->_state->handle1();
	}
	void request2()
	{
		this->_state->handle2();
	}
};



class concretestateA : public State
{
public:
	void handle1() override;
	void handle2() override {
		cout << "concretestateA andles request1." << endl;
	}
};

class concretestateB : public State
{
public:
	void handle1() override {
		cout << "concretestateB andles request1." << endl;
	}
	void handle2() override {
		cout << "concretestateB andles request2.change the state of the context." << endl;
		this->context->Transition_to(new concretestateA);
	}
};


void concretestateA::handle1()
{
	cout << "concretestateA andles request1.change the state of the context." << endl;
	this->context->Transition_to(new concretestateB);
}