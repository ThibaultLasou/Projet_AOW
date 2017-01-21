#ifndef __JOUEUR_HUMAIN_H__
#define __JOUEUR_HUMAIN_H__

#include <string>
#include <list>
#include <iostream>
#include <limits>

#include "Joueur.hpp"

/* JoueurHumain sous classe de Joueur*/
class JoueurHumain : public Joueur
{
	public :
        /* Constructeur : JoueurHumain
         * Entrees :
         *	- nom
         *  - cote, cote designe la base du joueur crée
         */
		JoueurHumain(std::string nom, int cote);

        /* Fonction : choix
         * Sortie :
         *	- -1 : si l'unite ne peut pas etre créee dans la base du joueur
         *	-  0 : si le joueur ne souhaire pas effectuer d'achat
         *	-  1 : si le joueur souhaite acher un fantassin et qu'il a suffisemment d'or pour
         *	-  2 : si le joueur souhaite acher un archer et qu'il a suffisemment d'or pour
         *	-  3 : si le joueur souhaite acher une catapulte et qu'il a suffisemment d'or pour
         * Retourne l'entier qui correspond à l'unité que le joueur souhaite acheter.
         * Lance une exception si le joueur entre Ctrl+D
         */
		virtual int choix() override;
};

#endif
