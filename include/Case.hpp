#ifndef __CASE_H__
#define __CASE_H__

#include <string>

class Jeu;
class Unite;
class Attaquable;

class Case
{
	protected :
		Jeu &leJeu;
		Unite *occupe;

	public :
		Case(Jeu &jeu);
		virtual ~Case();
		virtual bool estLibre() const;
		virtual Case* getCase(int delta, int dir) const;
		void setUnite(Unite *newUnit);
		virtual	Attaquable* cible();
		virtual std::string toString() const;
		int test;
};


#endif
