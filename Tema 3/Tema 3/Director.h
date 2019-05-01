#pragma once
#include "pch.h"
class Director :
	public Person
{
private:
	unsigned int sumaAditionala;
public:
	Director(long long cnp=0, string nume="", string nume_film="", float cutPercentage=0, int sumaAditionala = 0);
	~Director();
	float GetCutPercentage()
	{
		return cutPercentage;
	}
	int GetSumaAditionala()
	{
		return sumaAditionala;
	}
	void Afiseaza();
	friend istream& operator>>(istream& is, Director &d)
	{
		d.CitirePersoana(is);
		is >> d.sumaAditionala;
		return is;
	}
};

