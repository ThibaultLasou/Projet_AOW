#include "Jeu.hpp"
#include "Base.hpp"

Jeu::Jeu(int tourMax, int orTour, int cases, std::string nomJ1, std::string nomJ2) :
	nbTourMax(tourMax), nbTour(0), orParTour(orTour), nbCases(cases), joueurs()
{
	joueurs.push_back(Joueur(nomJ1,1));
	joueurs.push_back(Joueur(nomJ2,-1));
	leTerrain.push_front(Base(joueurs[1]));
	for(int i=1;i<nbCases-1;i++)
	{
		leTerrain.push_front(Case());
	}
	leTerrain.push_front(Base(joueurs[0]));
}

Jeu::~Jeu()
{}

void Jeu::tourDeJeu()
{

}
