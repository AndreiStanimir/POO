#include "Nod_ABC.h"
Nod_ABC::Nod_ABC(int val, Nod_ABC* st, Nod_ABC* dr) : Nod(val)
{
	value = val;
	stanga = st;
	dreapta = dr;
}
Nod_ABC::Nod_ABC(const Nod_ABC& nod) : Nod(nod.value)
{
	value = nod.value;
	stanga = nod.stanga;
	dreapta = nod.dreapta;
}
istream& operator>> (istream& is, Nod_ABC& nod)
{
	is >> nod.value; //>> nod.stanga >> nod.dreapta;
	return is;
}
ostream& operator<< (ostream& os, Nod_ABC& nod)
{
	os << nod.value << endl;
	return os;
}

Nod_ABC::~Nod_ABC()
{

}
