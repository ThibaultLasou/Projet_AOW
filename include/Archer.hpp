#ifndef ARCHER_HPP_INCLUDED
#define ARCHER_HPP_INCLUDED

#include "Unite.hpp"

/* Archer hérite d'Unite, car un archer est une unité*/
class Archer : public Unite
{
    protected :
        bool aJoue;                 /* booléen qui va servir pour effectuer les actions 1-2-3*/
	public :
        static const int Vie = 8;  /* un archer a 8 points de vie*/
		static const int Attaque = 3;  /* un archer a 3 points d'attaque*/
		static const int Prix = 12;/* un archer vaut 12 pieces d'or*/
        static const std::vector<int> Portee; /* un archer a une portée de 1, 2 ou 3 */

        /* Constructeur : Archer
         * Entrees :
         *	proprio : proprietaire de l'attaquable
         */
		Archer(Joueur &propri);

        /* Destructeur : ~Archer
         * Permet de détruire l'objet
         */
		virtual ~Archer();

        /* Fonction : action1
         * La première action d'un archer est attaquer
         */
		virtual void action1() override;

        /* Fonction : action2
         * La deuxiemme action d'un archer est avancer
         */
		virtual void action2() override;

        /* Fonction : action3
         * L'archer ne fait rien pas de troisieme action
         */
		virtual void action3() override;

        /* Fonction : toString
         * Fontion d'affichage.
         */
		virtual std::string toString() const override;
};



#endif // ARCHER_HPP_INCLUDED
