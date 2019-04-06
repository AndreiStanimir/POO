
#include "Nod.h"
class Nod_ABC : public Nod
{
private:
	Nod_ABC* stanga;
	Nod_ABC* dreapta;

public:
	Nod_ABC(int val = 0, Nod_ABC* st = nullptr, Nod_ABC* dr = nullptr);
	Nod_ABC(const Nod_ABC& nod);
	friend istream& operator>> (istream& is, Nod_ABC& nod);
	friend ostream& operator<< (ostream& os, Nod_ABC& nod);
	~Nod_ABC();
	friend class ArboreDeCautare;
};
