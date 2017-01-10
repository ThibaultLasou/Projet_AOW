#ifndef __CASE_H__
#define __CASE_H__

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
		virtual Case* getCase(int delta, int dir);
		void setUnite(Unite *newUnit);
		virtual	Attaquable* cible();
};


#endif
