#include "Attaquable.hpp"

Attaquable::Attaquable(Joueur &propri, int pv) :
	vie(pv), proprio(propri)
{

}

Attaquable::~Attaquable()
{

}

void Attaquable::recevoirDegats(int deg)
{

}

bool Attaquable::estEnnemi(const Attaquable &a) const
{
	return (&(a.proprio) == &(this->proprio));
}
