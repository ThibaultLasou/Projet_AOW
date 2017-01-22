#include <sstream>
#include "Joueur.hpp"
#include "Catapulte.hpp"

const std::vector<int> Catapulte::Portee {2,3,4};

Catapulte::Catapulte(Joueur &propri): Unite(propri, Vie, Attaque, Prix, Portee, CATAPULTE)
{

}

Catapulte::~Catapulte()
{}

void Catapulte::action1()
{
	/* attaquer */
	aJoue = attaquer();
}

void Catapulte::action2()
{
	/* rien */
}

void Catapulte::action3()
{
	/* avancer si pas action1 */
		if(!aJoue)
	{
        avancer();
        aJoue = false;
	}
}

std::string Catapulte::toString(bool grand) const
{
	std::stringstream res;
	res << "Catapulte " << Unite::toString(grand);
	return res.str();
}

bool Catapulte::attaquer()
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
					Case *nextCase2 = nextCase->getCase(1, proprio.cote());
					if(nextCase2 != nullptr)
					{
						if(!nextCase2->estLibre())
						{
							afficheAtt(nextCase2->cible());
							nextCase2->cible()->recevoirDegats(this->attaque, res);
							if(res.fatal)
							{
								meurtre(res);
							}
						}
					}
					return true;
				}
			}
		}
	}
	afficheAtt(nullptr);
	return false;
}

