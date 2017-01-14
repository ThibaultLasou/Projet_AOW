#ifndef __JOUEUR_HUMAIN_H__
#define __JOUEUR_HUMAIN_H__

#include <string>
#include <list>
#include <iostream>
#include <limits>

#include "Joueur.hpp"

class JoueurHumain : public Joueur
{
	public :
		JoueurHumain(std::string nom, int cote);
		virtual int choix() override;
};

#endif
