#pragma once
#include "pch.h"
using namespace std;

class Movie
{
	string nume;
	int tip;
	int durata;
	double earnings;
	vector<Person*> persoane;
public:
	Movie(string nume,
		int tip,
		int durata,
		int earnings);
	~Movie();
	void AddPersoana(long long cnp, string nume, float cutPercentage)
	{
		persoane.push_back(new Person(cnp, nume, this->nume, cutPercentage));
	}
	void AddPersoana(Person* persoana)
	{
		persoane.push_back(persoana);
	}
	void AfiseazaPersoane()
	{
		for (auto p : persoane)
		{
			p->Afiseaza();
			cout << endl;
		}
	}

	double GetEarnings(Person* p)
	{
		Director* director = dynamic_cast<Director*> (p);
		if (director)
		{
			return earnings * director->GetCutPercentage() / 100 + director->GetSumaAditionala();
		}
		return earnings * p->GetCutPercentage() / 100;
	}
	vector <Person*>& GetPersoane()
	{
		return persoane;
	}
	friend istream& operator>>(istream& is, Movie& m)
	{
		try {
			is >> m.nume >> m.tip >> m.durata >> m.earnings;

			if (m.durata < 0)
				throw out_of_range("Durata filmului este negativa...");

			// regizor

			Director* d=new Director();
			is >> *d;
			m.AddPersoana(d);

			int n, i;
			is >> n;
			//actori
		
			for (i = 0; i < n; i++)
			{
				Actor* a = new Actor();
				is >> *a;
				m.AddPersoana(a);
			}
			// tehnic
			
			is >> n;
			for (i = 0; i < n; i++)
			{
				Technical* t = new Technical();
				is >> *t;
				m.AddPersoana(t);
			}
		}
		catch (ifstream::failure e) {
			cout << "Exception opening/reading/closing file\n";
		}
		return is;
	}
};
