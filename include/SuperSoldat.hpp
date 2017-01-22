#ifndef SUPERSOLDAT_HPP
#define SUPERSOLDAT_HPP

#include "Fantassin.hpp"

/* SuperSoldat hérite de Fantassin, un super-soldat possède les memes caractéristiques qu'un fantassin
 * mais n'a pas les memes actions 1-2-3 qui seront redéfinies dans SuperSoldat
 */
class SuperSoldat : public Fantassin
{
    public:
        /* Constructeur : SuperSoldat
         * Entrees :
         *	proprio : proprietaire de l'attaquable
         */
        SuperSoldat(Fantassin &f);

        /* Destructeur : ~SuperSoldat
         * Permet de détruire l'objet
         */
        virtual ~SuperSoldat();

        /* Fonction : action1
         * La première action d'un super-soldat est attaquer
         */
		virtual void action1() override;

        /* Fonction : action2
         * La deuxiemme action d'un super-soldat est avancer
         */
		virtual void action2() override;

        /* Fonction : action3
         * La troisièmme action d'un super-soldat est attaquer
         */
		virtual void action3() override;
		
		std::string toString(bool grand) const override;
};

#endif // SUPERSOLDAT_HPP
