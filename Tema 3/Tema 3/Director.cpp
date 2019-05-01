#include "pch.h"
#include "Director.h"

Director::Director(long long cnp, string nume, string nume_film, float cutPercentage, int sumaAditionala) : Person(cnp, nume, nume_film, cutPercentage)
{
	this->sumaAditionala = sumaAditionala;
}

Director::~Director()
{
}

void Director::Afiseaza()
{
	AfisarePersoana();
	cout << sumaAditionala << endl;
}
