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

int Attaquable::recevoirDegats(int deg)
{
    vie -= deg;
	if(vie <= 0)
	{
		mort();
	}
	return 0;
}

void Attaquable::mort()
{
	delete this;
}

bool Attaquable::estEnnemi(const Attaquable &a) const
{
	return (&(a.proprio) != &(this->proprio));
}
