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
		~Catapulte();

		virtual void action1() override;
		virtual void action2() override;
		virtual void action3() override;
		virtual std::string toString() const override;
};


#endif // CATAPULTE_HPP_INCLUDED
