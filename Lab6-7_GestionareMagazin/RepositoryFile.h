#pragma once
#include "Magazin.h"
#include <set>

using namespace std;

template <class T>
class RepositoryFile
{
private:
	set<Magazin> elem;
public:
	RepositoryFile() {}
	void addElem(const T m) {
		elem.insert(m);
	}
	void delElem(const T m) {
		elem.erase(m);
	}
	void updateElem(const T m, const T newM) {
		elem.erase(m);
		elem.insert(newM);
	}
	set<T>& getAll() {
		return elem;
	}
	int size() {
		return elem.size();
	}
	~RepositoryFile() {}
};