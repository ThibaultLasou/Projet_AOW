#ifndef CATAPULTE_HPP_INCLUDED
#define CATAPULTE_HPP_INCLUDED

#include "Unite.hpp"

class Catapulte : public Unite
{
	public :
        static const int vieC = 12;
		static const int attC = 6;
		static const int prixC = 20;
        static const std::vector<int> porteeC;

		Catapulte(Joueur &propri);
		virtual ~Catapulte();

		virtual void action1() override; /*  TODO */
		virtual void action2() override; 
		virtual void action3() override; /* TODO */
		virtual std::string toString() const override;
};


#endif // CATAPULTE_HPP_INCLUDED
