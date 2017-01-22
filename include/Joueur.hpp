#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include <string>
#include <list>
#include <iostream>

class Unite;
class Base;
class Jeu;

class Joueur
{
	protected :
		std::string nom;        /* Nom du joueur */
		int tresor;             /* Tresor du joueur correspond au nombres de piece d'or du joueur */
		int sonCote;            /* sonCote désigne le sens dans lequel se déplacent les unités sur l'aire de jeu */
		std::list<Unite*> armee; /* armee est la liste d'unite du joueur. L'unite a la fin est la plus proche de la base */
		Base* saBase;

	public :
        /* Constructeur : Joueur
         * Entrees :
         *	- nom
         *  - cote, cote designe la base du joueur crée
         */
		Joueur(std::string nom, int cote);

		/* Destructeur : ~Joueur*/
		virtual ~Joueur();

		/* Fonction : choix
         * Sortie :
         *	- -1 : si l'unite ne peut pas etre créee dans la base du joueur
         *	-  0 : si le joueur ne possede pas suffiseament d'argent, meme pour l'unite la moins chere
         *	-  1 : si le joueur a suffisemment d'or pour s'acheter un fantassin
         *	-  2 : si le joueur a suffisemment d'or pour s'acheter un archer
         *	-  3 : si le joueur a suffisemment d'or pour s'acheter une catapulte
         * Retourne l'entier qui correspond à l'unité la plus chère que ce que le tresor du joueur permet.
         */
		virtual int choix();

        /* Fonction : acheter
         * Cette fonction appelle la fonction choix qui le retourne un indice (voir ci-dessus) qui désigne
         * le type d'unite à acheter, ensuite une fois que le type d'unité est établie, on retranche le prix de
         * l'unité achetée du trésor du joueur, et on crée cette unité. Elle affiche aussi le trésor restant au
         * joueur après l'achat de l'unité.
         * Cette fonction va etre redifinie dans sa sous-classe JoueurHumain.
         */
		void acheter();

        /* Fonction : jouer
         * Entrees :
         *	- jeu : le jeu actuel
         *  Cette fonction permet de définir les actions à réaliser durant un tour de jeu, d'abord action1, puis
         * action2 puis action3 et enfin appeler la méthode acheter.
         */
        void jouer(Jeu &jeu);

         /* Fonction : ajoutArgent
         * Entrees :
         *	- montant : entier
         *  Cette fontion ajoute le montant d'argent pris en paramètre au trésor du joueur
         */
		void ajoutArgent(int montant);

        /* Accesseur : getBase
         * Renvoie la base du joueur
         */
		Base& getBase() const;

		/* Mutateur : setBase
         * Entrees :
         *	- b : base
         * Fait en sorte que b soit la base du joueur
		 */
		void setBase(Base *b);

        /* Accesseur : cote
         * Renvoie le cote du joueur
         */
		int cote() const;

        /* Fonction : toString
         * Fontion d'affichage
		 * Entrees :
		 *	- grand : bool
		 * Le booléen permet d'afficher plus d'informations
         */
		std::string toString(bool grand = false) const;

         /* Fonction : removeUnite
         * Entrees :
         *	- u : unite morte a supprimer
         *  Cette fontion permet de supprimer l'unite u de l'armée du joueur
         *  Cette fonction lève une exception dans le cas où elle n'existe pas dans l'armée
         */
		void removeUnite(Unite* u);

        /* Accesseur : getTresor
         * Renvoie le tresor du joueur
         */
		int getTresor() const;
};

#endif
