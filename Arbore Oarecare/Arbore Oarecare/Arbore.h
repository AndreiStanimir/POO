#ifndef ARBORE_H
#define ARBORE_H

class Arbore
{
protected:
	int nr_noduri;
public:
	Arbore(int nrNoduri=0);
	virtual void Afisare();
	void CresteNrNoduri();
};
#endif // !ARBORE_H
