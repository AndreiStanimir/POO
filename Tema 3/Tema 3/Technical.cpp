#include "pch.h"
#include "Technical.h"


Technical::Technical(long long cnp, string nume, string nume_film, float cutPercentage) :Person(cnp, nume, nume_film, cutPercentage)
{
}

Technical::~Technical()
{
}

void Technical::Afiseaza()
{
	AfisarePersoana();
}
