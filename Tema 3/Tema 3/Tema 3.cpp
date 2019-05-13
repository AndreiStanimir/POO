// Tema 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <fstream>
using namespace std;


int main()
	{	
	ifstream fin("avengers.txt");
	try {
	fin.exceptions(istream::failbit | istream::badbit);
		if (!fin.is_open())
			throw "File not found";
	}
	catch (const char* c)
	{
		cout << c;
		return -1;
	}
	catch (exception e)
	{
		cout << e.what();
	}
	Movie m;
	
	fin >> m;
	//m.AfiseazaPersoane();
	auto persoane = m.GetPersoane();
	for (auto p : persoane)
	{
		p->Afiseaza();
		cout << "Castiga: "<< m.GetEarnings(p) << endl << endl;
	}

	Movie m2 = m;
	//m2.AfiseazaPersoane();
	
	FirmaDistributie<int> firma;
	firma.AddMovie(m);
	firma.AfiseazaFilme();
	
}
