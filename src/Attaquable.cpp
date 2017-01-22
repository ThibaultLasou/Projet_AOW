#include "Attaquable.hpp"

#include <iostream>

Attaquable::Attaquable(Joueur &propri, int pv, A_type _type) :
	type(_type), vie(pv), proprio(propri)
{
	std::cerr << "Constructeur <Attaquable>" << std::endl;
}

Attaquable::~Attaquable()
{
	std::cerr << "Destructeur <Attaquable>" << std::endl;
}

void Attaquable::recevoirDegats(int deg, resultAttaque &res)
{
	vie -= deg;	
	res.degats = deg;
	res.type = type;
	if(vie <= 0)
	{
		res.fatal = true;
		mort();
	}
}

void Attaquable::mort()
{
	std::cout << toString() << " est mort" << std::endl;
	delete this;
}

bool Attaquable::estEnnemi(const Attaquable &a) const
{
	return (&(a.proprio) != &(this->proprio));
}
