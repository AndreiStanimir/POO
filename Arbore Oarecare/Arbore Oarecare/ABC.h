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
	friend istream& operator >> (istream& is, ArboreDeCautare &arbore);
	friend ostream& operator << (ostream& os, ArboreDeCautare &arbore);
	ArboreDeCautare & ArboreDeCautare::operator=(ArboreDeCautare& arbore);
	ArboreDeCautare(int value=0);
	ArboreDeCautare(const ArboreDeCautare& arbore);
	void CopyTree(Nod_ABC * root1, Nod_ABC * root2);
	void Insert(int value);
	Nod_ABC* Search(int value);
	int FindMax(Nod_ABC* root);
	void Delete(int value);
	void StergeNod(Nod_ABC* &tata,Nod_ABC* &nod);
	void ArboreDeCautare::DestroyTree(Nod_ABC* nod);
	void Afisare();
	void RSD(Nod_ABC * root);
	void SDR(Nod_ABC* root);
	void SRD(Nod_ABC* root);
	~ArboreDeCautare();

};


