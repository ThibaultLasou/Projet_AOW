#ifndef __CASE_H__
#define __CASE_H__

#include <string>

class Jeu;
class Unite;
class Attaquable;

/* Une case est un element de l'aire de jeu*/
class Case
{
	private:
		static int nbCases;
	protected :
		Jeu &leJeu;     /* L'aire de jeu auquel la case appartient*/
		Unite *occupe;  /* L'unite qui occupe la case*/
		int num;

	public :

        /* Constructeur : Case
         * Entrees :
         *	- jeu : L'aire de jeu auquel la case appartient
         */
		Case(Jeu &jeu);

        /* Destructeur : ~Case*/
		virtual ~Case();

        /* Fonction : estLibre
         * Sortie :
         *	-  booléen : vaut vrai si la case est libre, faux sinon.
         * Cette fonction permet de savoir si la case est libre ou pas.
         */
		virtual bool estLibre() const;

        /* Fonction : getCase
         * Entrees :
            - delta : nombre de cases
            - dir : direction
         * Sortie :
         *	-  Case : case obtenue
         * Cette fonction renvoie la case qui se trouve à delta*dir de la case actuelle
         */
		virtual Case* getCase(int delta, int dir) const;

        /* Mutateur : setUnite
         * Entrees :
         *	- newUnit : Unite
         * Fait en sorte que newUnite occupe la case.
		 */
		void setUnite(Unite *newUnit);

        /* Accesseur : cible
         * Renvoie l'unite qui occupe la case
         */
		virtual	Attaquable* cible();

        /* Fonction : toString
         * Fontion d'affichage
         */
		virtual std::string toString() const;
};


#endif
