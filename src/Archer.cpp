#include "Archer.hpp"

const std::vector<int> Archer::porteeA {1,2,3};

Archer::Archer(Joueur &propri): Unite(propri, vieA, attA, porteeA, prixA)
{

}

Archer::~Archer()
{}
