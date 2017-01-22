#ifndef __JEU_H__
#define __JEU_H__

#include <string>
#include <list>
#include <vector>

#include "Joueur.hpp"
#include "Case.hpp"

/* Jeu regroupe les caractéristique d'une partie du jeu*/
class Jeu
{
	private :
		int nbTourMax;  /* nombre de tour max (afin que la partie ne dure pas eternellement) */
		int nbTour;     /* numéro du tour actuel*/
		int orParTour;  /* A chaque tour un certain nombre de pieces d'or est distribué aux joueurs*/
		int nbCases;    /* nombre de cases de l'aire de jeu*/
		std::vector<Case*> leTerrain; /* Terrain qui est une liste de cases*/
		std::vector<Joueur*> joueurs; /* joueurs qui stocke les joueurs*/

	public :
        /* Constructeur : Jeu
         * Entrees :
         *	nomJ1 : nom du joueur 1
         *  nomJ2 : nom du joueur 1
         *  tourMax : initilisé à 100
         *  orTour : fixé à 8 pièces d'or
         *  cases : fixé à 12 cases
         */
		Jeu(std::string nomJ1="A", std::string nomJ2="B",int tourMax=100, int orTour=8, int cases=12);

        /* Destructeur : ~Jeu
         * Permet de détruire l'objet
         */
		~Jeu();

        /* Fonction : getNextCase
         * Entrees :
            - delta : nombre de cases
            - dir : direction
         * Sortie :
         *	-  Case : case obtenue
         * Cette fonction renvoie la case qui se trouve à delta*dir de la case actuelle
         * Elle lance une exception si case n'est pas dans Terrain
         */
		Case* getNextCase(const Case* c, int dir, int delta) const;

        /* Fonction : tourDeJeu
         * Cette fonction met en place un tour de jeu, d'abord incrémenter le trésor des
         * joueurs pour faire jouer les joueurs
         */
		void tourDeJeu();

        /* Fonction : toString
         * Fontion d'affichage.
         */
		std::string toString() const;

        /* Fonction : fin
         * Permet d'afficher le joueur gagnant. De plus, elle met fin à la partie
         */
		void fin(Joueur* perdant);
};

#endif
