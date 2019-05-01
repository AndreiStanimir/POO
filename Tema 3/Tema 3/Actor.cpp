#include "pch.h"
#include "Actor.h"


Actor::Actor(long long cnp, string nume, string nume_film, float cutPercentage, int estePersonajPrincipal) :Person(cnp, nume, nume_film, cutPercentage)
{
	this->estePersonajPrincipal = estePersonajPrincipal;
}

Actor::~Actor()
{
}

void Actor::Afiseaza()
{
	AfisarePersoana();
	cout << (estePersonajPrincipal ? "Este personaj principal" : "Nu este personaj principal") << endl;
}
