#pragma once
#include "Person.h"
class Technical :
	public Person
{
public:
	Technical(long long cnp=0, string nume="", string nume_film="", float cutPercentage=0);
	~Technical();

	float GetCutPercentage()
	{
		return cutPercentage;
	}
	void Afiseaza();
	friend istream& operator>>(istream& is, Technical &t)
	{
		t.CitirePersoana(is);
		return is;
	}
};
