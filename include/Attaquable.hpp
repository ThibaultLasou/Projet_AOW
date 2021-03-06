#ifndef __ATTAQ_H__
#define __ATTAQ_H__
#include <string>

#include "Mstream.hpp"
class Joueur;

/* Enumeration des types d'd'attaquable existants */
typedef enum {BASE=0, FANTASSIN, ARCHER, CATAPULTE, SUPERS} A_type;
typedef struct _resultAttaque resultAttaque;

/* Attaquable est une classe mère qui possède plusieurs fonctions virtulles qui seront redéfinies dans les sous-classes
 * Cette classe permet de mettre en commun les attributs et les fonctions qui seront communes à ses sous-classes
 * Les sous-classes sont : Unite et Base, en effet les unités et les bases peuvent etre attaquées et possèdent
 * donc des points de vie et ont un prioritaire.

 */
class Attaquable
{
	protected:
		A_type type;
		int vie;         /* l'entier vie désigne les points de vie de l'attaquable*/
		Joueur &proprio; /* le joueur proprietaire  */

	public :
        /* Constructeur : Attaquable
         * Entrees :
         *	- proprio : proprietaire de l'attaquable
         *  - pv, designe les points de vie
         */
		Attaquable(Joueur &propri, int pv, A_type _type);

        /* Destructeur : ~Attaquable*/
		virtual ~Attaquable();

        /* Fonction : recevoirDegats
         * Entrée :
         *	- deg : entier qui désigne les degats que peur recevoir l'attaquable
         * Sortie :
         *	-  entier
         * Cette fonction retranche deg des points de vie d'attaquable. Si ce dernier n'a plus de points de vie la
         * fonction mort() est appelée.
         */
		virtual void recevoirDegats(int deg, resultAttaque &res);

        /* Fonction : mort
         * Cette fonction permet de supprimer l'attaquable si ce denrnier est mort, autrement dit s'il n'a plus
         * de points de vie
         */
		virtual void mort();

        /* Fonction : toString
         * Fontion virtuelle pure d'affichage qui va etre definie dans les sous-classes.
         */
		virtual std::string toString(bool grand=false) const =0;

        /* Fonction : estEnnemi
         * Entrée :
         *	- a : attaquable
         * Sortie :
         *	-  booléen : vaut true si a est un ennemi, faux sinon
         * Cette fonction permet de vérifier si l'attaquable passé en paramtre est un ennemi.
         */
		bool estEnnemi(const Attaquable &a) const;
};

struct _resultAttaque
{
	A_type type;
	bool fatal;
	int degats;
	int valeur;
};

#endif
