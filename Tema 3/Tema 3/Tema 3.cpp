// Tema 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("C:\\Users\\andreio\\Tema 3\\Tema 3\\avengers.txt");
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
	Movie m("Avengers",1,180,100000);
	
	fin >> m;
	m.AfiseazaPersoane();
	auto persoane = m.GetPersoane();
	for (auto p : persoane)
	{
		p->Afiseaza();
		cout << m.GetEarnings(p) << endl << endl;
	}
	
}
