#ifndef ARCHER_HPP_INCLUDED
#define ARCHER_HPP_INCLUDED

#include "Unite.hpp"

class Archer : public Unite
{
	public :
        static const int vieA = 8;
		static const int attA = 3;
		static const int prixA = 12;
        static const std::vector<int> porteeA;

		//Archer();
		Archer(Joueur &propri);
		~Archer();
		/*
		bool action1();
		bool action2();
		bool action3();
		*/
};



#endif // ARCHER_HPP_INCLUDED
