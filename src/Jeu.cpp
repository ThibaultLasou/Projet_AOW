#include "Jeu.hpp"
#include "Base.hpp"
#include "JoueurHumain.hpp"

#include <iterator>
#include <iostream>
#include <sstream>

Jeu::Jeu(std::string nomJ1, std::string nomJ2, int tourMax, int orTour, int cases) :
	nbTourMax(tourMax), nbTour(0), orParTour(orTour), nbCases(cases)
{
	std::cerr << "Constructeur <Jeu>" << std::endl;

	Joueur *j = new Joueur(nomJ1, 1);
	JoueurHumain *j2 = new JoueurHumain(nomJ2, -1);
	joueurs.push_back(j);
	joueurs.push_back(j2);
	leTerrain.push_back(new Base(*this, *joueurs[1]));
	for(int i=1;i<nbCases-1;i++)
	{
		leTerrain.push_front(new Case(*this));
	}
	leTerrain.push_front(new Base(*this, *joueurs[0]));
}

Jeu::~Jeu()
{
	std::cerr << "Destructeur <Jeu>" << std::endl;
	while(!joueurs.empty())
	{
		delete joueurs.back();
		joueurs.pop_back();
	}
	while(!leTerrain.empty())
	{
		delete leTerrain.back();
		leTerrain.pop_back();
	}
}

void Jeu::tourDeJeu()
{
	std::cout << toString();
    for(Joueur* joueur : joueurs)
    {
       joueur->ajoutArgent(orParTour);
    }

    for(Joueur* joueur : joueurs)
    {
       joueur->jouer();
    }
}

Case* Jeu::getNextCase(const Case *c, int dir, int delta) const
{
	std::list<Case*>::const_iterator it;
	for(it=this->leTerrain.begin();it!= this->leTerrain.end();++it)
	{
		if(c == *it)
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
	return *it;
}

std::string Jeu::toString() const
{
	std::stringstream res;
	int i = 0;
	for(Joueur *j : joueurs)
	{
		res << j->toString() << std::endl;
	}
	for(Case *c : leTerrain)
	{
		res << "Case " << i << " : " << c->toString() << std::endl;;
		i++;
	}
	return res.str();
}
