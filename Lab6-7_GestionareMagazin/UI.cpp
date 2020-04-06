#include "UI.h"
#include "Magazin.h"

void UI::add()
{
	char* nume = new char[10];
	int pret, exemplare;
	cout << "Dati nume: ";
	cin >> nume;
	cout << "Dati pret: ";
	cin >> pret;
	cout << "Dati nr exemplare: ";
	cin >> exemplare;
	Magazin m(nume, pret, exemplare);
	service.addElem(m);
}
void UI::del()
{
	char* nume = new char[10];
	int pret, exemplare;
	cout << "Dati nume: ";
	cin >> nume;
	cout << "Dati pret: ";
	cin >> pret;
	cout << "Dati nr exemplare: ";
	cin >> exemplare;
	Magazin m(nume, pret, exemplare);
	service.delElem(m);
}
void UI::update()
{
	char* nume = new char[10];
	int pret, exemplare;
	cout << "Dati nume: ";
	cin >> nume;
	cout << "Dati pret: ";
	cin >> pret;
	cout << "Dati nr exemplare: ";
	cin >> exemplare;
	Magazin m(nume, pret, exemplare);
	char* newName = new char[10];
	int newPret, newExemplare;
	cout << "Dati noul nume: ";
	cin >> newName;
	cout << "Dati noul pret: ";
	cin >> newPret;
	cout << "Dati noul nr de exemplare: ";
	cin >> newExemplare;
	service.updateElem(m, newName, newPret, newExemplare);
}
void UI::showAll()
{
	cout << "Produse:" << endl;
	for (auto it = service.getAll().begin(); it != service.getAll().end(); ++it)
		cout << *it;
}


void UI::buy()
{
	char* nume = new char[10];
	int pret, exemplare;
	cout << "Numele produsului: "; cin >> nume;
	cout << "Suma: "; cin >> pret;
	cout << "Exemplare dorite: "; cin >> exemplare;
	for (Magazin m : service.getAll())  {
		if (strcmp(m.getNume(), nume) == 0) {
			if (m.getExemplare() >= exemplare && m.getPret() <= pret)
			{
				m.setExemplare(m.getExemplare() - exemplare);
				cout << "Produs achizitionat cu succes!" << endl;
			}
			else
				cout << "Nu sunt suficiente exemplare disponibile!" << endl;
		}
		else
			cout << "Nu exista acest produs!" << endl;
	}
	int op;
	cout << "Doriti sa achizitionati alt produs?(Da=0/Nu=1): "; cin >> op;
	switch (op) {
	case 0: buy();
	case 1: break;
	}

}
void UI::all()
{
	bool gata = false;
	while (!gata)
	{
		cout << endl << "OPTIUNI: " << endl;
		cout << "1.Adauga produs" << endl;
		cout << "2.Sterge produs" << endl;
		cout << "3.Modifica produs" << endl;
		cout << "4.Arata produse" << endl;
		cout << "5.Cumpara produse" << endl;
		cout << "0.EXIT!" << endl;
		cout << "INTRODUCETI: ";
		int opt;
		cin >> opt;
		switch (opt)
		{
		case 1: { add(); break; }
		case 2: { del(); break; }
		case 3: { update(); break; }
		case 4: { showAll(); break; }
		case 5: { buy(); break; }
		case 0: { gata = true; cout << "HAI PA"; }
		}
	}
}