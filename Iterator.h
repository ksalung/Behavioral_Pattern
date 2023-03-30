#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;


template <typename T, typename U>
class Iterator
{
public:
	typedef typename vector<T>::iterator iter_type;
	Iterator(U* p_data, bool reverse = false) : _pdata(p_data)
	{
		_it = _pdata->_data.begin();
	}
	void First()
	{
		_it = _pdata->_data.begin();
	}
	void Next()
	{
		_it++;
	}
	bool IsDone()
	{
		return (_it == _pdata->_data.end());
	}
	iter_type current()
	{
		return _it;
	}
private:
	U* _pdata;
	iter_type _it;
};


template <class T>
class Container
{
	friend class Iterator<T, Container>;

public:
	void add(T data)
	{
		_data.push_back(data);
	}
	Iterator<T, Container>* create_iterator()
	{
		return new Iterator<T, Container>(this);
	}
private:
	vector<T> _data;
};

class Data
{

public:
	Data(int __data = 0) :_data(__data) {}
	void set_data(int __data)
	{
		_data = __data;
	}
	int get_data()
	{
		return _data;
	}
private:
	int _data;
};


