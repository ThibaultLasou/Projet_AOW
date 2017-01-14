#include <sstream>
#include "Joueur.hpp"
#include "Fantassin.hpp"

const std::vector<int> Fantassin::porteeF {1};

Fantassin::Fantassin(Joueur &propri): Unite(propri, vieF, attF, prixF, porteeF), aJoue(false)
{

}

Fantassin::~Fantassin()
{}


void Fantassin::action1()
{
	/* attaquer */
}

void Fantassin::action2()
{
	avancer();
}

void Fantassin::action3()
{
	/* attaquer si pas action 1 */
}

std::string Fantassin::toString() const
{
	std::stringstream res;
	res << "Fantassin (" + proprio.sonNom() +") : " << vie << " PV";
	return res.str();
}
