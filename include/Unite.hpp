#ifndef __UNITE_H__
#define __UNITE_H__
#include <vector>
#include "Attaquable.hpp"
#include "Case.hpp"

class Case;

class Unite : public Attaquable
{
	protected :
		int attaque;             /* points d'attaque */
		int prix;                /* prix de l'unite */
		std::vector<int> portee; /* portee de l'unite*/
		Case* saCase;            /* Emplacement de l'unite*/

        /* Fonction : attaquer
         * Sortie :
           - boolée : vaut true si l'unite a pu attaquer un ennemi, faux sinon
         * Fontion virtuelle qui va permettre d'attaquer, elle va etre redefinie dans les sous-classes.
         */
		virtual bool attaquer();

        /* Fonction : avancer
         * Sortie :
           - boolée : vaut true si l'unite a pu avancer, faux sinon
         * Fontion virtuelle qui va permettre d'avancer sur l'aire de jeu, elle va etre redefinie
         *  dans les sous-classes.
         */
		virtual bool avancer();

	public :
        /* Constructeur : Unite
         * Entrees :
         *	- proprio : proprietaire de l'unite
         *  - pv, designe les points de vie de l'unite
         *  - prix, designe le prix de l'unite
         *  - port, designe la portee de l'unite
         * Fait appel au constructeur d'Attaquable comme c'est une redéfintion
         */
		Unite(Joueur& propri, int pv, int att, int prix, std::vector<int> portee);

        /* Destructeur : ~Unite
         * Permet de détruire l'objet
         */
		virtual ~Unite();

        /* Fonction : action1
         * Fontion virtuelle pure qui va etre definie dans chaque sous-classes selon l'énoncé
         */
		virtual void action1() = 0;

        /* Fonction : action2
         * Fontion virtuelle pure qui va etre definie dans chaque sous-classes selon l'énoncé
         */
		virtual void action2() = 0;

        /* Fonction : action3
         * Fontion virtuelle pure qui va etre definie dans chaque sous-classes selon l'énoncé
         */
		virtual void action3() = 0;

        /* Fonction : recevoirDegats
         * Entrée :
         *	- deg : entier qui désigne les degats que peur recevoir l'attaquable
         * Sortie :
         *	-  entier
         * Cette fonction retranche deg des points de vie d'attaquable. Si ce dernier n'a plus de points de vie la
         * fonction mort() est appelée.
         */
		virtual int recevoirDegats(int deg) override;

        /* Fonction : afficheAtt
         * Entrée :
         *	- a : attaquable
         * Cette fonction est une fontion d'affichage.
         */
		virtual void afficheAtt(Attaquable *a);

        /* Fonction : toString
         * Fontion d'affichage qui sera definie dans chaque sous-classes
         */
		virtual std::string toString(bool grand=false) const;
};

#endif
