#include "Unite.hpp"
#include "Joueur.hpp"
#include "Case.hpp"
#include "Base.hpp"

#include <iostream>
#include <sstream>

Unite::Unite(Joueur &propri, int pv, int att, int _prix, std::vector<int> _portee, A_type _type) :
	Attaquable(propri, pv, _type), attaque(att), prix(_prix), portee(_portee), saCase(&(propri.getBase()))
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
					afficheAtt(nextCase->cible());
					resultAttaque res;
					nextCase->cible()->recevoirDegats(this->attaque, res);
					if(res.fatal)
					{
						meurtre(res);
					}
					return true;
				}
			}
		}
	}
	afficheAtt(nullptr);
	return false;
}

void Unite::recevoirDegats(int deg, resultAttaque &res)
{
	res.valeur = this->prix;
	Attaquable::recevoirDegats(deg, res);
}

void Unite::meurtre(resultAttaque &res)
{
	proprio.ajoutArgent(res.valeur);
}

bool Unite::avancer()
{
	Case *nextCase = this->saCase->getCase(1, proprio.cote());
	if(nextCase != nullptr && nextCase->estLibre())
	{
		std::cout << toString() << " avance sur la ";
		nextCase->setUnite(this);
		saCase->setUnite(nullptr);
		this->saCase = nextCase;
		std::cout << this->saCase->toString()<< std::endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Unite::afficheAtt(Attaquable *a)
{
	if(a == nullptr)
	{
		std::cout << this->toString() << " n'a pas attaqué" << std::endl;
	}
	else
	{
		std::cout << this->toString() << " attaque " << a->toString() << std::endl;
	}
}

std::string Unite::toString(bool grand) const
{
	std::stringstream res;
	if(!grand)
	{
		res << "(" << saCase->Case::toString() << ")";
	}
	if(grand)
	{
		res << "(" << proprio.toString() << ") : " << vie << " PV";
	}
	return res.str();
}
