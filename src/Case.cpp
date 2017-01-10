#include "Case.hpp"
#include "Jeu.hpp"
#include "Unite.hpp"

#include <iostream>

Case::Case(Jeu &jeu) : leJeu(jeu), occupe(nullptr)
{
	std::cerr << "Constructeur <Case>" << std::endl;
}

Case::~Case()
{
	std::cerr << "Destructeur <Case>" << std::endl;
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

Attaquable* Case::cible()
{
	return occupe;
}
