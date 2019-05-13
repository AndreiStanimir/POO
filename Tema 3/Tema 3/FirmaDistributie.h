#pragma once
//#include "pch.h"
#ifdef DEBUG

#endif // DEBUG

template <typename T>
class FirmaDistributie
{
public:
	static T nrTotalPersoane;
	static T nrActori;
private:
	vector<Person*> persoane;
	vector<Movie> filme;
public:
	void AddPerson(Person*& p)
	{
		persoane.push_back(p);
		IncrementTotals(p);
	}
	void IncrementTotals(Person*& p)
	{
		nrTotalPersoane++;
		try
		{
			Actor* a = static_cast<Actor*>(p);
			if (a)
				nrActori++;
		}
		catch (exception e)
		{
			cout << e.what();
		}
	}
	void AddMovie(Movie& m)
	{
		filme.push_back(m);
		vector<Person*> persoane = m.GetPersoane();
		for (Person* p : persoane)
			//IncrementTotals(p);
			AddPerson(p);
	}
	void AfiseazaFilme()
	{
		for (Movie m : filme)
		{
			m.AfiseazaPersoane();
		}
	}
public:
	FirmaDistributie(vector<Movie> filme = vector<Movie>(0))
	{
		nrActori = 0;
		nrTotalPersoane = 0;
		this->persoane = vector<Person*>(0);
		this->filme = filme;
		for (auto f : filme)
		{
			AddMovie(f);
		}
	}
	~FirmaDistributie()
	{

	}
};
template<typename T>
	T FirmaDistributie<T>::nrActori = 0;
template<typename T>
T FirmaDistributie<T>::nrTotalPersoane = 0;

template<>
class FirmaDistributie<unsigned>
{
	static unsigned nrTotalPersoane;
	static unsigned nrActoriPrincipali;
	vector<Person*> persoane;
	vector<Movie> filme;

public:
	void AddPerson(Person*& p)
	{
		persoane.push_back(p);
		IncrementTotals(p);
	}
	void IncrementTotals(Person*& p)
	{
		nrTotalPersoane++;
		try
		{
			Actor* a = static_cast<Actor*>(p);
			if (a)
				if (a->ProcentajPersonajPrincipal()!=0)
					nrActoriPrincipali++;
		}
		catch (exception e)
		{
			cout << e.what();
		}
	}
	void AddMovie(Movie& m)
	{
		filme.push_back(m);
		vector<Person*> persoane = m.GetPersoane();
		for (Person* p : persoane)
			//IncrementTotals(p);
			AddPerson(p);
	}
	FirmaDistributie(vector<Movie> filme=vector<Movie>(0))
	{
		nrActoriPrincipali = 0;
		nrTotalPersoane = 0;
		this->persoane = vector<Person*>(0);
		this->filme = filme;
		for (auto f : filme)
		{
			AddMovie(f);
		}
	}
	~FirmaDistributie()
	{

	}
};
unsigned FirmaDistributie<unsigned>::nrActoriPrincipali= 0;
unsigned FirmaDistributie<unsigned>::nrTotalPersoane = 0;

