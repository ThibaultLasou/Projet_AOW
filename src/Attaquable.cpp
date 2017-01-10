#include "Attaquable.hpp"

#include <iostream>

Attaquable::Attaquable(Joueur &propri, int pv) :
	vie(pv), proprio(propri)
{
	std::cerr << "Constructeur <Attaquable>" << std::endl;
}

Attaquable::~Attaquable()
{
	std::cerr << "Destructeur <Attaquable>" << std::endl;
}

void Attaquable::recevoirDegats(int deg)
{
    vie -= deg;
}

bool Attaquable::estEnnemi(const Attaquable &a) const
{
	return (&(a.proprio) == &(this->proprio));
}
