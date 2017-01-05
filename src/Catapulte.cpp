#include "Catapulte.hpp"

const std::vector<int> Catapulte::porteeC {2,3,4};

Catapulte::Catapulte(Joueur &propri): Unite(propri, vieC, attC, prixC, porteeC)
{

}

Catapulte::~Catapulte()
{}

bool Catapulte::action1()
{
	return false;
}

bool Catapulte::action2()
{
	return false;
}

bool Catapulte::action3()
{
	return false;
}
