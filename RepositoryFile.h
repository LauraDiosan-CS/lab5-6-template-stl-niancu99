#pragma once
#include "Magazin.h"
#include <set>
using namespace std;

class RepositoryFile
{
private:
	set<Magazin> elem;
public:
	RepositoryFile();
	void addElem(Magazin);
	set<Magazin> getAll();
	int size();
	~RepositoryFile();
};