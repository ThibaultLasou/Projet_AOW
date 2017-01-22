#include <sstream>
#include "Joueur.hpp"
#include "Fantassin.hpp"

const std::vector<int> Fantassin::Portee {1};

Fantassin::Fantassin(Joueur &propri): Unite(propri, Vie, Attaque, Prix, Portee), aJoue(false)
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

std::string Fantassin::toString() const
{
	std::stringstream res;
	res << "Fantassin (" + proprio.sonNom() +") : " << vie << " PV";
	return res.str();
}
