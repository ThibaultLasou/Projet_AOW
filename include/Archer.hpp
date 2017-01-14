#ifndef ARCHER_HPP_INCLUDED
#define ARCHER_HPP_INCLUDED

#include "Unite.hpp"

class Archer : public Unite
{
    protected :
        bool aJoue;
	public :
        static const int vieA = 8;
		static const int attA = 3;
		static const int prixA = 12;
        static const std::vector<int> porteeA;

		Archer(Joueur &propri);
		virtual ~Archer();

		virtual void action1() override;
		virtual void action2() override;
		virtual void action3() override;
		virtual std::string toString() const override;
};



#endif // ARCHER_HPP_INCLUDED
