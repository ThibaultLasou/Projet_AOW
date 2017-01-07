#include "Case.hpp"
#include "Jeu.hpp"

Case::Case(Jeu &jeu) : leJeu(jeu), occupe(nullptr)
{

}

Case::~Case()
{

}

bool Case::estLibre() const
{
	if(occupe == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Case* Case::getCase(int delta, int dir)
{
	return leJeu.getNextCase(this, dir, delta);
}

void Case::setUnite(Unite *newUnit)
{
	occupe = newUnit;
}

Unite* Case::unit()
{
	return occupe;
}
