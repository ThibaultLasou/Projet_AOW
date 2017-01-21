#ifndef CATAPULTE_HPP_INCLUDED
#define CATAPULTE_HPP_INCLUDED

#include "Unite.hpp"

/* Catapulte hérite d'Unite, car une catapulte est une unité*/
class Catapulte : public Unite
{
    protected :
        bool aJoue;     /* booléen qui va servir pour effectuer les actions 1-2-3*/

        /* Fonction : attaquer
         * Sortie :
           - boolée : vaut true si l'unite a pu attaquer un ennemi, faux sinon
         * La catapulte tire deux cases à la fois y compris si une unité alliée s'y trouve
         */
		bool attaquer() override;

	public :
        static const int vieC = 12;            /* une catapulte a 12 points de vie*/
		static const int attC = 6;             /* une catapulte a 6 points d'attaque*/
		static const int prixC = 20;           /* une catapulte vaut 20 pieces d'or*/
        static const std::vector<int> porteeC; /* une catapulte a une portée de 2, 3 ou 4 */

        /* Constructeur : Catapulte
         * Entrees :
         *	proprio : proprietaire de l'attaquable
         */
		Catapulte(Joueur &propri);

        /* Destructeur : ~Catapulte
         * Permet de détruire l'objet
         */
		virtual ~Catapulte();

        /* Fonction : action1
         * La première action d'une catapulte est attaquer
         */
		virtual void action1() override;

        /* Fonction : action2
         * La catapulte n'a pas de deuxiemme action
         */
		virtual void action2() override;

        /* Fonction : action3
         * La catapulte avance si elle n'a pas attaqué à la première action
         */
		virtual void action3() override;

        /* Fonction : toString
         * Fontion d'affichage.
         */
		virtual std::string toString() const override;
};


#endif // CATAPULTE_HPP_INCLUDED
