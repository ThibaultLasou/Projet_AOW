#ifndef __BASE_H__
#define __BASE_H__

#include "Attaquable.hpp"
#include "Case.hpp"
/* Base hérite de Case car une base est installée sur une case
 * Base hérite aussi de attaquable, car une base peut etre attaquée par des unités
 */
class Base : public Case, public Attaquable
{
	public :
		static const int Vie = 100;
        /* Constructeur : Base
         *  - jeu : L'aire de jeu auquel la case appartient
         *  - proprio : proprietaire de la base
         *  - pv, designe les points de vie et vaut 100 à l'initialisation
         * Fait appel au constructeurs de Case et Attaquable car c'est une sous-classe
         */
		Base(Jeu &jeu, Joueur &propri);

        /* Destructeur : ~Base*/
		~Base();

        /* Fonction : estLibre
         * Sortie :
         *	-  booléen : vaut vrai si la case est libre, faux sinon.
         * Cette fonction permet de savoir si la case est libre ou pas.
         */
		bool estLibre() const override;

        /* Accesseur : cible
         * Renvoie l'unite qui occupe la case
         */
		Attaquable* cible() override;

        /* Fonction : peutSpawn
         * Sortie :
         *	-  booléen : vaut vrai si la base est libre, faux sinon.
         * Cette fonction permet de savoir si la case est libre ou pas.
         */
		bool peutSpawn() const;

        /* Fonction : mort
         * Cette fonction permet de détruire la Base si cette dernière est morte.
         */
		void mort();

        /* Fonction : toString
         * Fontion d'affichage
         */
		std::string toString(bool grand=false) const;
};

#endif
