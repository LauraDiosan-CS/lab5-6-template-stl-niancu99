#pragma once
#include "Magazin.h"
#include <set>
#include "RepoFile.h"

using namespace std;

template <class T>
class Repository : public RepoFile<T>
{
private:
	set<T> elem;
public:
	Repository();
	void addElem(const T m);
	void delElem(const T m);
	void updateElem(const T m, const T newM);
	set<T>& getAll();
	void loadfromfile();
	int size();
	~Repository();
};

template<class T>
Repository<T>::Repository()
{
}

template<class T>
void Repository<T>::addElem(const T m)
{
	this->elem.insert(m);
}

template<class T>
void Repository<T>::delElem(const T m)
{
	this->elem.erase(m);
}

template<class T>
void Repository<T>::updateElem(const T m, const T newM)
{
	this->elem.erase(m);
	this->elem.insert(newM);
}

template<class T>
set<T>& Repository<T>::getAll()
{
	return this->elem;
}

template<class T>
void Repository<T>::loadfromfile()
{
	RepoFile<T>::loadFromFile();
}

template<class T>
int Repository<T>::size()
{
	return this->elem.size();
}

template<class T>
Repository<T>::~Repository()
{

}
