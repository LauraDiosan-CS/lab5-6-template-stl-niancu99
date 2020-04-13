#pragma once
#include "Repository.h"


class Service
{
private:
	Repository<Magazin> repo;
public:
	Service() {}
	void addElem(const Magazin m)
	{
		repo.addElem(m); 
	}
	void delElem(const Magazin m) 
	{ 
		repo.delElem(m);
	}
	void updateElem(const Magazin m, const char* nume, int pret, int exemplare)
	{
		Magazin newM(nume, pret, exemplare);
		repo.updateElem(m, newM);
	}
	set<Magazin>& getAll()
	{
		return repo.getAll();
	}
	int size() 
	{
		return repo.size();
	}
};