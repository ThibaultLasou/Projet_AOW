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

resultAttaque* Attaquable::recevoirDegats(int deg)
{
	resultAttaque *res = new resultAttaque;
    vie -= deg;
	if(vie <= 0)
	{
		res->fatal = true;
		mort();
	}
	return res;
}

void Attaquable::mort()
{
	delete this;
}

bool Attaquable::estEnnemi(const Attaquable &a) const
{
	return (&(a.proprio) != &(this->proprio));
}
