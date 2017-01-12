#ifndef __FANTASSIN_H__
#define __FANTASSIN_H__

#include "Unite.hpp"

class Fantassin : public Unite
{
    protected :
        bool aJoue;
	public :
        static const int vieF = 10;
		static const int attF = 4;
		static const int prixF = 10;
		static const std::vector<int> porteeF;

		Fantassin(Joueur &propri);
		~Fantassin();

		bool action1() override;
		bool action2() override;
		bool action3() override;

};

#endif
