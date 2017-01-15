#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include <string>
#include <list>
#include <iostream>

class Unite;
class Base;

class Joueur
{
	protected :
		std::string nom;
		int tresor;
		int sonCote;
		std::list<Unite*> armee; /*  l'unite a la fin est la plus proche de la base */
		Base* saBase;

	public :
		Joueur(std::string nom, int cote);
		virtual ~Joueur();
		virtual int choix();
		void acheter();
        void jouer();
		void ajoutArgent(int montant);
		Base& getBase() const;
		void setBase(Base *b);
		int cote() const;
		std::string sonNom() const;
		std::string toString() const;
		void removeUnite(Unite* u); /* TODO : ajouter une exception si u pas dans la liste*/
		int getTresor() const;
};

#endif
