#include "Joueur.hpp"
#include "Base.hpp"
#include "Attaquable.hpp"
#include "Unite.hpp"

#include <iostream>

Base::Base(Jeu &jeu, Joueur &propri, int vie) :
	 Case(jeu), Attaquable(propri, vie)
{
	std::cout << "Constructeur <Base>" << std::endl;
	propri.setBase(this);
}

Base::~Base()
{
	std::cout << "Destructeur <Base>" << std::endl;
}

bool Base::estLibre() const
{
	return false;
}

bool Base::peutSpawn() const
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

Attaquable* Base::cible()
{
	if(occupe == nullptr)
	{
		return occupe;
	}
	else
	{
		return this;
	}
}
