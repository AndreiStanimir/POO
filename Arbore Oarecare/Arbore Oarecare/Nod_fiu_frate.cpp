
#include "Nod_fiu_frate.h"

Nod_fiu_frate::Nod_fiu_frate(int val) : Nod(val)
{
	nrCopii = 0;
	children = nullptr;
	nextFrate = nullptr;
}

Nod_fiu_frate::Nod_fiu_frate(const Nod_fiu_frate & nod) : Nod(nod.value)
{
	nrCopii = nod.nrCopii;
	children = nod.children;
	nextFrate = nod.nextFrate;
}

Nod_fiu_frate& Nod_fiu_frate::operator =(const Nod_fiu_frate& nod)
{
	value = nod.value;
	nrCopii = nod.nrCopii;
	children = nod.children;
	nextFrate = nod.nextFrate;
	return *this;
}

istream& operator>> (istream& is, Nod_fiu_frate& nod)
{
	is >> nod.value;
	return is;
}
ostream& operator<< (ostream& os, Nod_fiu_frate& nod)
{
	os << nod.value << endl;
	return os;
}

Nod_fiu_frate::~Nod_fiu_frate()
{
	nextFrate = children = NULL;
}

