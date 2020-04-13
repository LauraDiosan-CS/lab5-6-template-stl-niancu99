#include "Magazin.h"
#include <string.h>
#include <sstream>
using namespace std;

Magazin::Magazin() {
	nume = NULL;
	pret = 0;
	exemplare = 0;

}

Magazin::Magazin(const char* nume, int pret, int exemplare) {
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->pret = pret;
	this->exemplare = exemplare;
}

Magazin::Magazin(const Magazin& m) {
	this->nume = new char[strlen(m.nume) + 1];
	strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);
	this->pret = m.pret;
	this->exemplare = m.exemplare;
}


int Magazin::getPret() {
	return pret;
}

void Magazin::setPret(int p) {
	pret = p;
}

int Magazin::getExemplare() {
	return exemplare;
}

void Magazin::setExemplare(int newexemplare) {
	exemplare = newexemplare;
}

char* Magazin::getNume() {
	return nume;

}

void Magazin::setNume(const char* n) {
	if (nume) delete[]nume;
	nume = new char[strlen(n) + 1];
	strcpy_s(nume, strlen(n) + 1, n);
}

Magazin::~Magazin() {
	if (nume) delete[]nume;
	nume = NULL;
	pret = -1;
	exemplare = -1;

}


Magazin& Magazin::operator=(const Magazin& m) {
	if (this == &m) return *this; //self-assignment 

	if (nume) delete[] nume;
	nume = new char[strlen(m.nume) + 1];
	strcpy_s(nume, strlen(m.nume) + 1, m.nume);
	pret = m.pret;
	exemplare = m.exemplare;
	return *this;
}

bool Magazin::operator==(const Magazin& m) const{
	return (strcmp(nume, m.nume) == 0);
}

bool Magazin::operator<(const Magazin& m) const
{
	return (strcmp(nume, m.nume) < 0);

}

ostream& operator<<(ostream& os, Magazin m) {
	os << m.nume << " " << m.pret << " " << m.exemplare << endl;
	return os;
}
