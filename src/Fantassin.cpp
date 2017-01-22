#include <sstream>
#include "Joueur.hpp"
#include "Fantassin.hpp"
#include "SuperSoldat.hpp"

const std::vector<int> Fantassin::Portee {1};

Fantassin::Fantassin(Joueur &propri): Unite(propri, Vie, Attaque, Prix, Portee, FANTASSIN), aJoue(false)
{

}

Fantassin::~Fantassin()
{}


void Fantassin::action1()
{
    aJoue = attaquer();
}

void Fantassin::action2()
{
	avancer();
}

void Fantassin::action3()
{
	if(!aJoue)
	{
        attaquer();
        aJoue = false;
	}
}

void Fantassin::meurtre(resultAttaque &res)
{
	Unite::meurtre(res);
	if(res.type == FANTASSIN)
	{
		new SuperSoldat(*this);
	}
}

std::string Fantassin::toString(bool grand) const
{
	std::stringstream res;
	res << "Fantassin "<< Unite::toString(grand);
	return res.str();
}
