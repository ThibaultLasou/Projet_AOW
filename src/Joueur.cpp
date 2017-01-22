#include "Joueur.hpp"
#include "Base.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
#include "Jeu.hpp"
#include "NotInListException.hpp"
#include "CinException.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>  // pour std::find

Joueur::Joueur(std::string nom, int cote) :
	nom(nom), tresor(0), sonCote(cote), armee()
{
	std::cerr << "Constructeur <Joueur>\t" << this->nom <<  "\t" << this << std::endl;
}

Joueur::~Joueur()
{
	std::cerr << "Destructeur <Joueur>\t" << this->nom <<  "\t" << this << std::endl;
	Unite* it;
	while(!armee.empty())
	{
		it = armee.back();
		delete it;
	}
}

int Joueur::choix()
{
	if(!saBase->peutSpawn())
	{
		return -1;
	}
	else if(tresor < Fantassin::Prix)
	{
		return 0;
	}
	else
	{
		if(tresor >= Catapulte::Prix) //choisir une catapulte
		{
			return CATAPULTE;
		}
		else if(tresor >= Archer::Prix) // choisir un archer
		{
			return ARCHER;
		}
		else //choisir un fantassin
		{
			return FANTASSIN;
		}

	}
}

void Joueur::acheter()
{
	std::cout<< toString() << " : ";
	try{
		int choixUnite = choix();
		switch(choixUnite)
		{
			case -1:
				{
					std::cout<<"La base n'est pas libre";
					break;
				}
			case 0:
				{
					std::cout<<"Pas d'achat";
					break;
				}
			case FANTASSIN:
				{
					tresor -= Fantassin::Prix;
					this->armee.push_back(new Fantassin(*this));
					std::cout<<"Achat d'un fantassin";
					break;
				}
			case ARCHER:
				{
					tresor -= Archer::Prix;
					this->armee.push_back(new Archer(*this));
					std::cout<<"Achat d'un archer";
					break;
				}
			case CATAPULTE:
				{
					tresor -= Catapulte::Prix;
					this->armee.push_back(new Catapulte(*this));
					std::cout<<"Achat d'une catapulte";
					break;
				}
		}
		std::cout<<" (or restant : "<<tresor<<")"<<std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr <<"Exception : " <<e.what() << "\n";
		return;
	}
}

Base& Joueur::getBase() const
{
	return *saBase;
}

void Joueur::jouer(Jeu &jeu)
{
	std::cout << std::endl<< "Tour du " << toString()<<std::endl<<"----------------"<<std::endl;
	std::list<Unite*>::const_iterator it_before = armee.begin();
	--it_before;
	std::list<Unite*>::const_iterator it;
	for(it = armee.end(), it--; it != it_before; --it)
	{
		nettoyer(it,-1);
		std::cout << (*it)->toString() << " : action 1" << std::endl;
		(*it)->action1();
		std::cout << jeu.toString()<<std::endl<<std::endl;
	}

	for(it = armee.begin(); it != armee.end(); it++)
	{
		nettoyer(it,-1);
		std::cout << (*it)->toString() << " : action 2" << std::endl;
		(*it)->action2();
		std::cout << jeu.toString()<<std::endl<<std::endl;
	}

	for(it = armee.begin(); it != armee.end(); it++)
	{
		nettoyer(it,-1);
		std::cout << (*it)->toString() << " : action 3" << std::endl;
		(*it)->action3();
		std::cout << jeu.toString()<<std::endl<<std::endl;
	}
	acheter();
}

void Joueur::ajoutArgent(int montant)
{
	std::cout<<toString()<< " : "<< tresor;
	this->tresor += montant;
	std::cout<<"->"<<tresor<< " or"<<std::endl;

}

int Joueur::cote() const
{
	return sonCote;
}

void Joueur::setBase(Base *b)
{
	saBase = b;
}

std::string Joueur::toString(bool grand) const
{
	std::stringstream res;
	res << "Joueur " + nom;
	if(grand)
	{
		res << " : " << tresor << " or" << std::endl;
	}
	return res.str();
}

/* enleve une unité morte de l'armée du joueur */
void Joueur::removeUnite(Unite* u)
{
	std::list<Unite*>::iterator it;
	it = std::find (armee.begin(), armee.end(), u);// std::find sert a verifier si l'unite u est dans la list armee
	if (it != armee.end()) //L'unite u appartient à larmee
	{
		armee.erase(it) ;
		return;
	}
	else // u n'est pas dans la
	{
		throw NotInListException();
	}
}

void Joueur::remplaceUnite(Unite *old, Unite *nouv)
{
	std::list<Unite*>::iterator it;
	it = std::find (armee.begin(), armee.end(), old);// std::find sert a verifier si l'unite u est dans la list armee
	if (it != armee.end()) //L'unite u appartient à larmee
	{
		armee.insert(it, nouv);
		nettoyage.push_back(old);
		return;
	}
	else // u n'est pas dans la
	{
		throw NotInListException();
	}
}

int Joueur::getTresor() const
{
	return tresor;
}

void Joueur::nettoyer(std::list<Unite*>::const_iterator &it, int dir)
{
	for(Unite *u : nettoyage)
	{
		if(u == *it)
		{
			switch(dir)
			{
				case -1 : it--; break;
				case 1 : it++; break;
				default : ;
			}
		}
		std::list<Unite*>::iterator itf;
		itf = std::find (armee.begin(), armee.end(), u);// std::find sert a verifier si l'unite u est dans la list armee
		if (itf != armee.end()) //L'unite u appartient à larmee
		{
			armee.erase(itf) ;
		}
		else // u n'est pas dans la liste
		{
			throw NotInListException();
		}
	}
	nettoyage.clear();
}
