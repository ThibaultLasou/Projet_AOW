#include "Unite.hpp"
#include "Joueur.hpp"
#include "Case.hpp"
#include "Base.hpp"

#include <iostream>

Unite::Unite(Joueur &propri, int pv, int att, int price, std::vector<int> port) :
	Attaquable(propri, pv), attaque(att), prix(price), portee(port), saCase(&(propri.getBase()))
{
	std::cerr << "Constructeur <Unite>" << std::endl;
	saCase->setUnite(this);
}

Unite::~Unite()
{
	std::cerr << "Destructeur <Unite>" << std::endl;
	saCase->setUnite(nullptr);
	proprio.removeUnite(this);
}

bool Unite::attaquer()
{
	for(int i : portee)
	{
		Case *nextCase = this->saCase->getCase(i, proprio.cote());
		if(nextCase != nullptr)
		{
			if(!nextCase->estLibre())
			{
				if(nextCase->cible()->estEnnemi(*this)) 
				{
					proprio.ajoutArgent(nextCase->cible()->recevoirDegats(this->attaque));
					return true;
				}
			}
		}
	}
	return false;
}

bool Unite::avancer()
{
	Case *nextCase = this->saCase->getCase(1, proprio.cote());
	if(nextCase != nullptr && nextCase->estLibre())
	{
		nextCase->setUnite(this);
		saCase->setUnite(nullptr);
		this->saCase = nextCase;
		return true;
	}
	else
	{
		return false;
	}
}

int Unite::recevoirDegats(int deg)
{
    int gold = 0;
	vie -= deg;
	if(vie <= 0)
	{
		gold = this->prix;
		mort();
	}
	return gold;
}	
