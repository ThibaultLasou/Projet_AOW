#include "SuperSoldat.hpp"

SuperSoldat::SuperSoldat(Fantassin &f): Fantassin(f)
{
}

SuperSoldat::~SuperSoldat()
{
}

void SuperSoldat::action1()
{
/* attaquer */
attaquer();
}

void SuperSoldat::action2()
{
	avancer();
}

void SuperSoldat::action3()
{
	/* attaquer  */
    attaquer();
}

