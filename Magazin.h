#pragma once
#include <iostream>
#include <string>
using namespace std;

class Magazin {
private:
	char* nume;
	int pret;
	int exemplare;

public:
	Magazin();
	Magazin(const char*, int, int);
	Magazin(const Magazin&);
	Magazin(string);//constructor de conversie
	Magazin& operator=(const Magazin&);
	char* getNume();
	int getPret();
	int getExemplare();
	void setNume(const char*);
	void setExemplare(int);
	void setPret(int);
	bool operator==(const Magazin&);
	bool operator<(const Magazin&);
	~Magazin();
	friend ostream& operator<<(ostream& os, Magazin s);
	friend istream& operator>>(istream&, Magazin&);
};
