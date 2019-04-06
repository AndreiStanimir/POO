#pragma once
#ifndef ARBORE_H
#include "Arbore.h"
#endif // !ARBORE_H

#include "Nod_ABC.h"

class ArboreDeCautare : public Arbore
{
private:
	Nod_ABC* root;
	void InsertUtility(int value, Nod_ABC* head);
	Nod_ABC* SearchUtility(int value, Nod_ABC* head);
	Nod_ABC* SearchParent(int value, Nod_ABC* head);
	Nod_ABC* DeleteUtility(int value, Nod_ABC* head);
public:
	ArboreDeCautare();
	ArboreDeCautare(int value=0);
	void Insert(int value);
	Nod_ABC* Search(int value);
	int FindMax(Nod_ABC* root);
	void Delete(int value);
	void StergeNod(Nod_ABC* &tata,Nod_ABC* &nod);
	void ArboreDeCautare::DestroyTree(Nod_ABC* nod);
	~ArboreDeCautare();

};


