#ifndef __JEU_H__
#define __JEU_H__

class Jeu
{
	private :
		int nbTourMax;
		int nbTour;
		int orParTour;
		int nbCases;
		//Collection de Cases
		Joueur joueurs[2];

	public : 
		void tourDeJeu();
};

#endif
