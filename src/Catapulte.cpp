#include "Catapulte.hpp"

const std::vector<int> Catapulte::porteeC {2,3,4};

Catapulte::Catapulte(Joueur &propri): Unite(propri, vieC, attC, porteeC, prixC)
{

}

Catapulte::~Catapulte()
{}
