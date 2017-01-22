#include "SuperSoldat.hpp"
#include "Joueur.hpp"
#include <sstream>

SuperSoldat::SuperSoldat(Fantassin &f): Fantassin(f)
{
	type = SUPERS;
	proprio.remplaceUnite(&f, this);
	this->saCase->setUnite(this);
}

SuperSoldat::~SuperSoldat()
{
}

void SuperSoldat::action1()
{
	attaquer();
}

void SuperSoldat::action2()
{
	avancer();
}

void SuperSoldat::action3()
{
    attaquer();
}

std::string SuperSoldat::toString(bool grand) const
{
	std::stringstream res;
	res << "Super soldat "<< Unite::toString(grand);
	return res.str();
}
