#include <assert.h> 
#include "UI.h"


void teste()
{
	Magazin m;
	Magazin m1("lapte", 2, 13);
	Magazin m2(m1);
	m2.setNume("apa");
	m2.setPret(12);
	assert(strcmp(m2.getNume(), "apa") == 0 && m2.getPret() == 12);
	m2.setPret(30);
	assert(m2.getPret() == 30);
	m2 = m1;
	assert(m2 == m1);
	Repository<Magazin> repo;
	Magazin ma1("apa", 12, 30);
	Magazin ma2("lapte", 2, 13);
	repo.addElem(ma1);
	repo.addElem(ma2);
	assert(repo.size() == 2);
	repo.delElem(ma2);
	assert(repo.size() == 1);
	repo.delElem(ma1);
	Magazin m3("aliment", 25, 3);
	repo.updateElem(ma1, m3);
	assert(m3.getExemplare() == 3);
	assert(strcmp(m3.getNume(), "aliment") == 0);
	assert(m3.getPret() == 25);
	Service s;
	s.addElem(m3);
	s.addElem(m1);
	assert(s.size() == 2);
	s.delElem(m1);
	assert(s.size() == 1);
	s.updateElem(m3, "apa", 500, 7);
	Magazin m4("apa", 500, 6);
	assert(!(m4 == m3));
}