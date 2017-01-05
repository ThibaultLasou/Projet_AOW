#include "Archer.hpp"

const std::vector<int> Archer::porteeA {1,2,3};

Archer::Archer(Joueur &propri): Unite(propri, vieA, attA, prixA, porteeA)
{

}

Archer::~Archer()
{}

bool Archer::action1()
{
	return false;
}

bool Archer::action2()
{
	return false;
}

bool Archer::action3()
{
	return false;
}
