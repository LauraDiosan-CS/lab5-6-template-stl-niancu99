#pragma once
#include "RepositoryFile.h"
class TestRepositoryFile
{
private:
	RepositoryFile repo;
public:
	TestRepositoryFile();
	void testLoadFromFile();
	void testAddElem();
	void testGetAll();
	void testSaveToFile();
	~TestRepositoryFile();
};