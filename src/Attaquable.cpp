#include "Attaquable.hpp"

#include <iostream>

Attaquable::Attaquable(Joueur &propri, int pv) :
	vie(pv), proprio(propri)
{
	std::cout << "Constructeur <Attaquable>" << std::endl;
}

Attaquable::~Attaquable()
{
	std::cout << "Destructeur <Attaquable>" << std::endl;
}

void Attaquable::recevoirDegats(int deg)
{
    vie -= deg;
}

bool Attaquable::estEnnemi(const Attaquable &a) const
{
	return (&(a.proprio) == &(this->proprio));
}
