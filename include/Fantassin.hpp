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
		virtual ~Fantassin();

		virtual void action1() override; /* TODO */
		virtual void action2() override; 
		virtual void action3() override; /* TODO */
		virtual std::string toString() const override;
};

#endif
