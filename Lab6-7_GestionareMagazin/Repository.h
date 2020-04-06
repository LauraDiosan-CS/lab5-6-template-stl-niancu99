#pragma once
#include <list>
#include <algorithm>
#include "Magazin.h"
#include <fstream>
using namespace std;

template <class Magazin>class RepoTemplate
{
private:
	list<Magazin> elem;
public:
	RepoTemplate<T>() {}
	void add(const Magazin&);
	int remove(const Magazin&);
	int find(const Magazin&);
	int size();
	void update(const Magazin& s, const Magazin nou);
	void loadFromFile(const char* fileName);
	list<Magazin> getAll();
	~RepoTemplate();
};





template<class Magazin>
void RepoTemplate<Magazin>::add(const Magazin& e)
{
	elem.push_back(e);
}

template<class Magazin>
int RepoTemplate<Magazin>::remove(const Magazin & e)
{
	elem.remove(e);
	return 0;
}

template<class Magazin>
int RepoTemplate<Magazin>::find(const Magazin& e)
{
	int index = 0;
	for (T crt : elem) {
		index++;
		if (crt == e) return index;
	}
	return -1;
}

template<class Magazin>
int RepoTemplate<Magazin>::size()
{
	return elem.size();
	return 0;
}

template<class Magazin>
void RepoTemplate<Magazin>::update(const Magazin& vechi, const Magazin nou)
{
	replace(elem.begin(), elem.end(), vechi, nou);

}

template<class Magazin>
list<Magazin> RepoTemplate<Magazin>::getAll()
{
	return elem;
	return list<Magazin>();
}


void RepoTemplate<Magazin>::loadFromFile(const char* fileName)
{
	elem.clear();
	ifstream f(fileName);
	char* nume = new char[10];
	int pret;
	int exemplare;
	while (!f.eof()) {
		f >> nume >>pret >>exemplare;
		if (strcmp(nume, "") != 0) {
			Magazin m(nume, pret,exemplare);
			elem.push_back(m);
		}
	}
	delete[] nume;
	f.close();
}


template <class Magazin> RepoTemplate<Magazin>::~RepoTemplate()
{
}

