#include "Jeu.hpp"
#include "Base.hpp"
#include <iterator>

#include <iostream>

Jeu::Jeu(std::string nomJ1, std::string nomJ2, int tourMax, int orTour, int cases) :
	nbTourMax(tourMax), nbTour(0), orParTour(orTour), nbCases(cases)
{
	std::cerr << "Constructeur <Jeu>" << std::endl;
	joueurs.emplace_back(nomJ1,1);
	joueurs.emplace_back(nomJ2,-1);
	leTerrain.emplace_back(Base(*this, joueurs[1]));
	for(int i=1;i<nbCases-1;i++)
	{
		leTerrain.emplace_front(Case(*this));
	}
	leTerrain.emplace_front(Base(*this, joueurs[0]));
}

Jeu::~Jeu()
{
	std::cerr << "Destructeur <Jeu>" << std::endl;
}

void Jeu::tourDeJeu()
{
    for(Joueur& joueur : joueurs)
    {
       joueur.ajoutArgent(orParTour);
    }

    for(Joueur& joueur : joueurs)
    {
       joueur.jouer();
    }
}

Case* Jeu::getNextCase(const Case *c, int dir, int delta) const
{
	std::list<Case>::const_iterator it;
	for(it=this->leTerrain.begin();it!= this->leTerrain.end();++it)
	{
		if((Case*)&(*it) == c)
		{
			break;
		}
	}
	for(int i=0;i!=dir*delta;i+=dir)
	{
		if(dir == -1)
		{
			it--;
		}
		else
		{
			it++;
		}
		if(it == this->leTerrain.end())
		{
			return nullptr;
		}
	}
	return (Case*)&(*it);
}
