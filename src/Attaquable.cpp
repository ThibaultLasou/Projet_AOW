#include "Attaquable.hpp"
#include <iostream>
#include "Mstream.hpp"

Attaquable::Attaquable(Joueur &propri, int pv, A_type _type) :
	type(_type), vie(pv), proprio(propri)
{
}

Attaquable::~Attaquable()
{
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
	else
	{
		res.fatal=false;
	}
}

void Attaquable::mort()
{
	mstream::mout << toString() << " est mort" <<"\n";
	delete this;
}

bool Attaquable::estEnnemi(const Attaquable &a) const
{
	return (&(a.proprio) != &(this->proprio));
}
