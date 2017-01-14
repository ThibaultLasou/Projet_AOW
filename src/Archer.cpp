#include <sstream>
#include "Joueur.hpp"
#include "Archer.hpp"

const std::vector<int> Archer::porteeA {1,2,3};

Archer::Archer(Joueur &propri): Unite(propri, vieA, attA, prixA, porteeA)
{

}

Archer::~Archer()
{}

void Archer::action1()
{
	attaquer();
}

void Archer::action2()
{
	avancer();
}

void Archer::action3()
{
	/* rien */
}

std::string Archer::toString() const
{
	std::stringstream res;
	res << "Archer (" + proprio.sonNom() +") : " << vie << " PV";
	return res.str();
}
