#include "Jeu.hpp"
#include "Base.hpp"
#include "JoueurHumain.hpp"
#include "NotInListException.hpp"

#include <iterator>
#include <iostream>
#include <sstream>
#include <exception>

Jeu::Jeu(std::string nomJ1, std::string nomJ2, int tourMax, int orTour, int cases) :
	nbTourMax(tourMax), nbTour(0), orParTour(orTour), nbCases(cases)
{
	Joueur *j = new Joueur(nomJ1, 1);
/* 	Joueur *j = new JoueurHumain(nomJ1, 1); */
	Joueur *j2 = new Joueur(nomJ2, -1);
/* 	Joueur *j2 = new JoueurHumain(nomJ2, -1);*/
	joueurs.push_back(j);
	joueurs.push_back(j2);
	leTerrain.push_back(new Base(*this, *joueurs[0]));
	for(int i=1;i<nbCases-1;i++)
	{
		leTerrain.push_back(new Case(*this));
	}
	leTerrain.push_back(new Base(*this, *joueurs[1]));
}

Jeu::~Jeu()
{
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
	mstream::mout	<< std::endl <<std::endl
					<< "===========" << std::endl
					<< "  Tour " << nbTour << std::endl
					<< "===========" << std::endl << std::endl;
	mstream::mout << toString();
    for(Joueur* joueur : joueurs)
    {
       joueur->ajoutArgent(orParTour);
    }

    for(Joueur* joueur : joueurs)
    {
       joueur->jouer(*this);
    }
	nbTour++;
}
/* throw exception si Case pas dans Terrain */
Case* Jeu::getNextCase(const Case *c, int dir, int delta) const
{
	if(c->num+(dir*delta) >= 0 && c->num+(dir*delta) <= this->nbCases)
	{
		return leTerrain[c->num+(dir*delta)];
	}
	else
	{
		return nullptr;
	}
}

std::string Jeu::toString() const
{
	std::stringstream res;
	int i = 0;
	for(Joueur *j : joueurs)
	{
		res << j->toString(true);
	}
	for(Case *c : leTerrain)
	{
		res << c->toString(true) << std::endl;
		i++;
	}
	res << std::endl << std::endl;
	return res.str();
}

void Jeu::fin(Joueur* perdant)
{
	Joueur* gagnant;
	if(joueurs[0] == perdant)
	{
		gagnant = joueurs[1];
	}
	else
	{
		gagnant = joueurs[0];
	}
	mstream::mout<< "---------------------------"<< std::endl<<gagnant->toString() << " a gagné " << std::endl << "---------------------------"<<std::endl<<toString();
	this->~Jeu(); /* bizarre mais nécessaire, a cause du exit */
	exit(EXIT_SUCCESS);
}
