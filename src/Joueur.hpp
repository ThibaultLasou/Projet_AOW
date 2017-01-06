#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include <string>
#include <list>

class Unite;
class Base;

class Joueur
{
	private :
		std::string nom;
		int tresor;
		int sonCote;
		std::list<Unite*> armee;
		Base* saBase;

	public :
		Joueur(std::string nom, int cote);
		virtual ~Joueur();
		virtual int choix();
		void acheter();
        void jouer();
		const Base& getBase() const;
};

#endif
