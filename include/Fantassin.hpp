#ifndef __FANTASSIN_H__
#define __FANTASSIN_H__

#include "Unite.hpp"

/* Fantassin hérite d'Unite, car un fantassin est une unité*/
class Fantassin : public Unite
{
    protected :
        bool aJoue;                             /* booléen qui va servir pour effectuer les actions 1-2-3*/
	public :
        static const int Vie = 10;             /* un fantassin a 10 points de vie*/
		static const int Attaque = 4;              /* un fantassin  a 4 points d'attaque*/
		static const int Prix = 10;            /*un fantassin  vaut 10 pieces d'or*/
		static const std::vector<int> Portee;  /* un fantassin  a une portée de 1 */

        /* Constructeur : Fantassin
         * Entrees :
         *	proprio : proprietaire de l'attaquable
         */
		Fantassin(Joueur &propri);

        /* Destructeur : ~Fantassin
         * Permet de détruire l'objet
         */
		virtual ~Fantassin();

        /* Fonction : action1
         * La première action d'un fantassin est attaquer
         */
		virtual void action1() override;

        /* Fonction : action2
         * La deuxiemme action d'un fantassin est avancer
         */
		virtual void action2() override;

        /* Fonction : action3
         * Le fantassion attaque s'il n'a pas pu attaquer à la première action.
         */
		virtual void action3() override;

        /* Fonction : toString
         * Fontion d'affichage.
         */
		virtual std::string toString(bool grand) const override;
};

#endif
