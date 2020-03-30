#include "RepositoryFile.h"
#include <fstream>
#include <string>
using namespace std;


RepositoryFile::RepositoryFile()
{
}

void RepositoryFile::addElem(Magazin m)
{
	elem.insert(m);
}

set<Magazin> RepositoryFile::getAll()
{
	return elem;
}

int RepositoryFile::size()
{
	return elem.size();
}

RepositoryFile::~RepositoryFile()
{

}