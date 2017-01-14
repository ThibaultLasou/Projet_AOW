#ifndef __JEU_H__
#define __JEU_H__

#include <string>
#include <list>
#include <vector>

#include "Joueur.hpp"
#include "Case.hpp"

class Jeu
{
	private :
		int nbTourMax;
		int nbTour;
		int orParTour;
		int nbCases;
		std::list<Case*> leTerrain;
		std::vector<Joueur*> joueurs;
		int e; 

	public : 
		Jeu(std::string nomJ1="A", std::string nomJ2="B",int tourMax=100, int orTour=8, int cases=12);
		~Jeu();
		Case* getNextCase(const Case* c, int dir, int delta) const;
		void tourDeJeu();
		std::string toString() const;
};

#endif