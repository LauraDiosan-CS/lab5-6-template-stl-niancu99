#include "RepositoryFile.h"
#include <fstream>
#include <string>
using namespace std;


RepositoryFile::RepositoryFile()
{

}

RepositoryFile::RepositoryFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* nume = new char[10];
	int pret;
	int exemplare;
	while (!f.eof()) {
		f >> nume >> pret >> exemplare;
		if (nume != "") {
			Magazin m(nume, pret, exemplare);
			elem.insert(m);
		}
	}
	delete[] nume;
	f.close();
}

void RepositoryFile::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[10];
	int pret;
	int exemplare;
	while (!f.eof()) {
		f >> nume >> pret >> exemplare;
		if (strcmp(nume, "") != 0) {
			Magazin m(nume,pret, exemplare);
			elem.insert(m);
		}
	}
	delete[] nume;
	f.close();
}

void RepositoryFile::addElem(Magazin m)
{
	elem.insert(m);
}

set<Magazin> RepositoryFile::getAll()
{
	return elem;
}