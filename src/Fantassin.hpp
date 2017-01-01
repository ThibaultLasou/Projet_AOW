#ifndef __FANTASSIN_H__
#define __FANTASSIN_H__

#include "Unite.hpp"

class Fantassin : public Unite
{
	public :
        static const int vieF = 10;
		static const int attF = 4;
		static const int prixF = 10;
		//static constexpr int porteeF[1] = {1};
		static const std::vector<int> porteeF;

		Fantassin();
		Fantassin(Joueur &propri);
		~Fantassin();
		/*
		bool action1();
		bool action2();
		bool action3();
		*/
};

#endif
