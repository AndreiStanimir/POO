#pragma once
#include "Person.h"
class Actor :
	public Person
{
	bool estePersonajPrincipal;
public:
	Actor(long long cnp=0, string nume="", string nume_film="", float cutPercentage=0,int estePersonajPrincipal=0);
	~Actor();
	int ProcentajPersonajPrincipal()
	{
		if (estePersonajPrincipal)
			return 10;
		else
			return 0;
		
	}
	float GetCutPercentage()
	{
		return cutPercentage + ProcentajPersonajPrincipal();
	}
	void Afiseaza();
	
	friend istream& operator>>(istream& is, Actor &a)
	{
		a.CitirePersoana(is);
		is >> a.estePersonajPrincipal;
		return is;
	}
};

