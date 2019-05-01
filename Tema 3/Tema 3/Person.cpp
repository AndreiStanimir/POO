#include "pch.h"
#include "Person.h"


void Person::AfisarePersoana()
{
	cout << "Cnp: "<< cnp << endl <<
		"nume: "<< nume << endl <<
		"nume film: " << nume_film << endl <<
		"Cut percentage: " << cutPercentage << endl;
}

void Person::CitirePersoana(istream& is)
{
	is >> cnp >>
		nume >>
		nume_film >>
		cutPercentage ;
}


Person::Person(long long cnp, string nume, string nume_film, float cutPercentage)
{
	this->cnp = cnp;
	this->nume = nume;
	this->nume_film = nume_film;
	this->cutPercentage = cutPercentage;
}

Person::~Person()
{
}

float Person::GetCutPercentage()
{
	return 0.0f;
}

void Person::Afiseaza()
{
}

