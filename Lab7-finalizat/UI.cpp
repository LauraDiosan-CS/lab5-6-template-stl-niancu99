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
	for (Magazin m : service.getAll())
		cout << m;
}


void UI::buy()
{
	char* nume = new char[20];
	bool done = false;
	int pret, exemplare;
	cout << "Numele produsului: "; cin >> nume;
	cout << "Suma: "; cin >> pret;
	cout << "Exemplare dorite: "; cin >> exemplare;
	for (Magazin m : service.getAll())  {
		if (strcmp(m.getNume(), nume) == 0) {
			if (m.getExemplare() >= exemplare && m.getPret() <= pret)
			{
				Magazin newM(m.getNume(), m.getPret(), m.getExemplare() - exemplare);
				service.delElem(m);
				service.addElem(newM);
				cout << "Produs achizitionat cu succes!" << endl;
				done = true;
				break;
			}
			else
				cout << "Nu sunt suficiente exemplare disponibile!" << endl;
		}
	}
	if (done == false) {
		cout << "Nu exista acest produs." << endl;

		int op;
		cout << "Doriti sa achizitionati alt produs?(Da=0/Nu=1): "; cin >> op;
		switch (op) {
		case 0: buy();
		case 1: break;
		}
	}

}

void UI::retur() {
	char* nume = new char[20];
	int exemplare;
	bool done = false;
	cout << "Numele produsului returnat: "; cin >> nume;
	cout << "Exemplare: "; cin >> exemplare;
	for (Magazin m : service.getAll()) {
		if (strcmp(m.getNume(), nume) == 0)
		{
			Magazin newM(m.getNume(), m.getPret(), m.getExemplare() + exemplare);
			service.delElem(m);
			service.addElem(newM);
			cout << "Produs returnat cu succes!" << endl;
			done = true;
			break;
		}
	}
	if (done != true) {
		cout << "Nu exista niciun produs cu numele dat" << endl;
		int op;
		cout << "Doriti sa incercati din nou? (Da = 0 / Nu = 1): "; cin >> op;
		switch (op) {
		case 0: retur();
		case 1: break;
		}
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
		cout << "6.Retur produse" << endl;
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
		case 6: { retur();  break; }
		case 0: { gata = true; cout << "HAI PA"; }
		}
	}
}