#ifndef __BASE_H__
#define __BASE_H__

#include "Attaquable.hpp"
#include "Case.hpp"

class Base : public Case, public Attaquable
{
	public : 
		Base(Jeu &jeu, Joueur &propri, int vie=100);
		~Base();
		bool estLibre() const override;
		bool peutSpawn() const;
};

#endif
