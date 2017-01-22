#include "Case.hpp"
#include "Jeu.hpp"
#include "Unite.hpp"

#include <iostream>
#include <sstream>

int Case::nbCases = 0;

Case::Case(Jeu &jeu) : leJeu(jeu), occupe(nullptr), num(nbCases)
{
	std::cerr << "Constructeur <Case>" << std::endl;
	nbCases++;
}

Case::~Case()
{
	std::cerr << "Destructeur <Case>" << std::endl;
	nbCases--;
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

Case* Case::getCase(int delta, int dir) const
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

std::string Case::toString(bool grand) const
{
	std::stringstream res;
	res << "Case "<< num;
	if(grand)
	{
		if(occupe != nullptr)
		{
			res << " : " << occupe->toString(true);
		}
		else
		{
			res << " : vide";
		}
	}
	return res.str();
}
