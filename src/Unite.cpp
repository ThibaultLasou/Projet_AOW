#include "Unite.hpp"
#include "Joueur.hpp"
#include "Case.hpp"
#include "Base.hpp"

Unite::Unite(Joueur &propri, int pv, int att, int price, std::vector<int> port) :
	Attaquable(propri, pv), attaque(att), prix(price), portee(port), saCase(propri.getBase())
{
}

Unite::~Unite()
{

}

bool Unite::attaquer()
{

}

bool Unite::avancer()
{
	Case &nextCase = saCase.getCase(proprio.cote, 1);
	if(nextCase.estLibre())
	{
		nextCase.setUnite(this);
		saCase.setUnite(nullptr);
		this->saCase = nextCase;
		return true;
	}
	else
	{
		return false;
	}
}
