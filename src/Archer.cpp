#include <sstream>
#include "Joueur.hpp"
#include "Archer.hpp"

const std::vector<int> Archer::Portee {1,2,3};

Archer::Archer(Joueur &propri): Unite(propri, Vie, Attaque, Prix, Portee, ARCHER)
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

std::string Archer::toString(bool grand) const
{
	std::stringstream res;
	res << "Archer " << Unite::toString(grand);
	return res.str();
}
