
#include "Nod.h"
class Nod_fiu_frate : Nod
{
private:
	int nrCopii;
	Nod_fiu_frate* children;
	Nod_fiu_frate* nextFrate;
public:

	Nod_fiu_frate(int val = 0);

	Nod_fiu_frate(const Nod_fiu_frate& nod);
	Nod_fiu_frate& operator =(const Nod_fiu_frate& nod);
	friend istream& operator>> (istream& is, Nod_fiu_frate& nod);
	friend ostream& operator<< (ostream& os, Nod_fiu_frate& nod);
	~Nod_fiu_frate();

	friend class AB_oarecare;
};