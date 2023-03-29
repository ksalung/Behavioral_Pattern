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
private:
	U* _pdata;
	iter_type _it;
public:
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
};


template <class T>
class container
{
	friend class Iterator<T, container>;
private:
	vector<T> _data;
public:
	void add(T data)
	{
		_data.push_back(data);
	}
	Iterator<T, container>* create_iterator()
	{
		return new Iterator<T, container>(this);
	}
};

class Data
{
private:
	int _data;
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
};


