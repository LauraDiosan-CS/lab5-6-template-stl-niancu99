#pragma once
#pragma once
#include "Magazin.h"
#include "Magazin1.h"
#include <vector>
using namespace std;

class RepositoryFile
{
private:
	vector<Magazin1> elem;
	const char* fis;
public:
	RepositoryFile();
	RepositoryFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void addElem(Magazin);
	void updateElem(Magazin, const char*, int);
	int findElem(Magazin);
	int delElem(Magazin);
	Student elemAtPos(int);
	vector<Student> getAll();
	int size();
	void saveToFile();
	~RepositoryFile();
};
