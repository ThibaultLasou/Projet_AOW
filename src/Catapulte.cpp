#include <sstream>
#include "Joueur.hpp"
#include "Catapulte.hpp"

const std::vector<int> Catapulte::porteeC {2,3,4};

Catapulte::Catapulte(Joueur &propri): Unite(propri, vieC, attC, prixC, porteeC)
{

}

Catapulte::~Catapulte()
{}

void Catapulte::action1()
{
	/* attaquer */
	aJoue = attaquer();
}

void Catapulte::action2()
{
	/* rien */
}

void Catapulte::action3()
{
	/* avancer si pas action1 */
		if(!aJoue)
	{
        avancer();
        aJoue = false;
	}
}

std::string Catapulte::toString() const
{
	std::stringstream res;
	res << "Catapulte (" + proprio.sonNom() +") : " << vie << " PV";
	return res.str();
}

bool Catapulte::attaquer()
{
	return false;
}
