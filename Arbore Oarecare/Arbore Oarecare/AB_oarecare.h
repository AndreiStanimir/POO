#include <iostream>
#ifndef ARBORE_H
#include "Arbore.h"
#endif // !ARBORE_H

#include "Nod_fiu_frate.h"
#include <queue>
#include <stack>
class AB_oarecare : Arbore
{
private:
	Nod_fiu_frate root;
	ostream& os;
public:

	friend istream& operator >> (istream& is, AB_oarecare &arbore);
	friend ostream& operator << (ostream& os, AB_oarecare& arbore);
	AB_oarecare& operator +(AB_oarecare& arbore);
	void InsertNode(int tata, int fiu);

	void PrintTree(ostream& os, Nod_fiu_frate* arbore);

	void PrintChildren(Nod_fiu_frate& arbore);
	Nod_fiu_frate* SearchNode(int value, Nod_fiu_frate* arbore);
	void AddChild(Nod_fiu_frate& tata, int value);
	void BFS(int value);
	void DFS(int value);
	int GetHight();
	void PrintLeafs();
	AB_oarecare(ostream& out);
	void SetOstream(ostream& out);
	void Afisare();
};
