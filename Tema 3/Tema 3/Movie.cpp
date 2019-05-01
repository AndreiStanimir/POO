#include "pch.h"
#include "Movie.h"



Movie::Movie(string nume, int tip,  int durata, int earnings)
{
	this->nume = nume;
	this->tip = tip;
	this->durata = durata;
	this->earnings = earnings;
	this->persoane = vector<Person*>();
}

Movie::~Movie()
{
}
