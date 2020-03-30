#include "TestRepositoryFile.h"
#include <assert.h> 



TestRepositoryFile::TestRepositoryFile()
{

	assert(repo.size() == 0);
}

void TestRepositoryFile::testLoadFromFile()
{
	repo.loadFromFile("TestMagazin.txt");
	assert(repo.size() == 4);
}

void TestRepositoryFile::testAddElem()
{
	repo.loadFromFile("TestMagazin.txt");
	repo.addElem(Magazin("lapte", 5,10));
	assert(repo.size() == 5);
	repo.saveToFile();
}


void TestRepositoryFile::testGetAll()
{
	repo.loadFromFile("TestMagazin.txt");
	set<Magazin> rez = repo.getAll();
	assert(rez.size() == 4);
	repo.saveToFile();
}

void TestRepositoryFile::testSaveToFile()
{
	repo.loadFromFile("TestMagazin.txt");
	int n = repo.size();
	repo.addElem(Magazin("conserva ton", 8, 25));
	repo.saveToFile();
	repo.loadFromFile("TestMagazin.txt");
	assert(repo.getAll().size() == (n + 1));

}


TestRepositoryFile::~TestRepositoryFile()
{
}
