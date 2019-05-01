#pragma once

#include "pch.h"

using namespace std;

class Person
{
protected:
	long long cnp;
	string nume;
	string nume_film;
	float cutPercentage;
	void AfisarePersoana();
	void CitirePersoana(istream& is);
public:
	Person(long long cnp=0,string nume="",string nume_film="",float cutPercentage=0);
	~Person();
	virtual float GetCutPercentage();
	virtual void Afiseaza();
};
