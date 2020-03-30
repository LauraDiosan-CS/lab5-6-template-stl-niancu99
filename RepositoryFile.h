#pragma once
#include "Magazin.h"
#include <set>
using namespace std;

class RepositoryFile
{
private:
	set<Magazin> elem;
	const char* fis;
public:
	RepositoryFile();
	RepositoryFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void addElem(Magazin);
	void updateElem(Magazin, const char*, int, int);
	int findElem(Magazin);
	int delElem(Magazin);
	Magazin elemAtPos(int);
	set<Magazin> getAll();
	int size();
	void saveToFile();
	~RepositoryFile();
};