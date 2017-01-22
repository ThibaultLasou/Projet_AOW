#include "SuperSoldat.hpp"

SuperSoldat::SuperSoldat(Fantassin &f): Fantassin(f)
{
	type = SUPERS;
	this->saCase->setUnite(this);
	delete &f;
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

