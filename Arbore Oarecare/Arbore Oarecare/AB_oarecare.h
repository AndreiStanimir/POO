#include <iostream>
#ifndef ARBORE_H
#include "Arbore.h"
#endif // !ARBORE_H

#include "Nod_fiu_frate.h"
#include <queue>
#include <stack>
#include <set>
class AB_oarecare : public Arbore
{
private:
	Nod_fiu_frate* root;
	ostream& os;
public:

	friend istream& operator >> (istream& is, AB_oarecare &arbore);
	friend ostream& operator << (ostream& os, AB_oarecare& arbore);
	AB_oarecare& operator +(AB_oarecare& arbore);
	AB_oarecare& operator =(AB_oarecare& arbore);

	Nod_fiu_frate* CopyTree(Nod_fiu_frate * arbore1, Nod_fiu_frate * arbore2);

	//void CopyTree(Nod_fiu_frate & arbore1, Nod_fiu_frate *& arbore2);
	
	AB_oarecare(ostream& out=cout);
	~AB_oarecare();

	//void CopyTree(Nod_fiu_frate * arbore1, Nod_fiu_frate * arbore2);
	void InsertNode(int tata, int fiu);
	void PrintTree(ostream& os, Nod_fiu_frate* arbore);
	void PrintChildren(Nod_fiu_frate& arbore);
	Nod_fiu_frate* SearchNode(int value, Nod_fiu_frate* arbore);
	void AddChild(Nod_fiu_frate& tata, int value);
	void BFS(int value);
	void DFS(int value);
	int GetHight();
	void PrintLeafs();
	void SetOstream(ostream& out);
	void Afisare();
	void DeleteTree(Nod_fiu_frate * root);
};
