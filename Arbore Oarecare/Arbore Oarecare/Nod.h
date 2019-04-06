#pragma once
#include <iostream>
using namespace std;
class Nod
{
protected:
	int value;
public:
	Nod(int value)
	{
		this->value = value;
	}
	Nod(const Nod& nod)
	{
		value = nod.value;
	}
	Nod& operator =(const Nod& nod)
	{
		value = nod.value;
		return *this;
	}

	friend istream& operator>> (istream& is, Nod& nod)
	{
		is >> nod.value;
		return is;
	}
	friend ostream& operator<< (ostream& os, Nod& nod)
	{
		os << nod.value << endl;
		return os;
	}
	~Nod()
	{
	}
};

