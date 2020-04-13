#pragma once
#include <vector>
#include <fstream>

using namespace std;

template <class T>
class RepoFile {
private:
	vector<T> elements;
	char* fileNameIn;
	char* fileNameOut;
public:
	RepoFile();
	RepoFile(const char* fileNameIn, const char* fileNameOut);
	~RepoFile();

	void setFileNameIn(const char* fileNameIn);
	void setFileNameOut(const char* fileNameIOut);

	void addElement(T elem);
	vector<T> getAll();

	int getSize();
	T getElementAtPosition(int pos);
	void updateElement(T& oldElement, T& newElement);
	void deleteElement(T& elem);
	void loadFromFile();
	void saveToFile();
};

template <class T>
RepoFile<T>::RepoFile() {
	this->fileNameIn = NULL;
	this->fileNameOut = NULL;
}

template <class T>
RepoFile<T>::RepoFile(const char* fileNameIn, const char* fileNameOut)
{
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
	this->loadFromFile();
}

template <class T>
RepoFile<T>::~RepoFile()
{
	this->elements.clear();
}

template <class T>
void RepoFile<T>::setFileNameIn(const char* fileNameIn)
{
	if (this->fileNameIn != NULL)
	{
		delete[]this->fileNameIn;
	}
	this->fileNameIn = new char[strlen(fileNameIn) + 1];
	strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
}

template <class T>
void RepoFile<T>::setFileNameOut(const char* fileNameOut)
{
	if (this->fileNameOut != NULL)
	{
		delete[]this->fileNameOut;
	}
	this->fileNameOut = new char[strlen(fileNameOut) + 1];
	strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

template <class T>
void RepoFile<T>::addElement(T elem) {
	this->elements.push_back(elem);
	this->saveToFile();
}

template <class T>
vector<T> RepoFile<T>::getAll() {
	return this->elements;
}

template <class T>
int RepoFile<T>::getSize()
{
	return this->elements.size();
}

template <class T>
T RepoFile<T>::getElementAtPosition(int pos)
{
	if (pos >= 0 && pos < this->getSize())
	{
		return this->elements[pos];
	}
	return T();
}

template <class T>
void RepoFile<T>::updateElement(T& oldElement, T& newElement)
{
	typename vector<T>::iterator it;

	it = find(this->elements.begin(), this->elements.end(), oldElement);
	if (!(it == this->elements.end()))
	{
		*it = newElement;
	}

	this->saveToFile();
}

template <class T>
void RepoFile<T>::deleteElement(T& elem)
{
	typename vector<T>::iterator it;

	it = find(this->elements.begin(), this->elements.end(), elem);
	if (!(it == this->elements.end()))
	{
		this->elements.erase(it);
	}

	this->saveToFile();
}

template <class T>
void RepoFile<T>::loadFromFile()
{
	if (this->fileNameIn != NULL)
	{
		this->elements.clear();
		ifstream f(this->fileNameIn);
		T element;
		while (f >> element)
		{
			this->addElement(element);
		}
		f.close();
	}
}

template <class T>
void RepoFile<T>::saveToFile()
{
	if (this->fileNameOut != NULL)
	{
		ofstream f(this->fileNameOut);
		for (size_t i = 0; i < this->elements.size(); i++)
		{
			f << this->elements[i] << endl;
		}
		f.close();
	}
}
