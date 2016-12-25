#ifndef __ATTAQ_H__
#define __ATTAQ_H__

#include "Joueur.hpp"

class Attaquable
{
	private :
		int pv;
		Joueur* proprio;	

	public :
		Attaquable(int pv);
		virtual ~Attaquable();
		virtual void recevoirDegats(int deg);
};

#endif
