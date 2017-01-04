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
		/*
		bool action1();
		bool action2();
		bool action3();
		*/
};


#endif // CATAPULTE_HPP_INCLUDED