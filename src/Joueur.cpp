#include "Joueur.hpp"
#include "Base.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"

#include <iostream>

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
		armee.pop_back();
	}
}

int Joueur::choix()
{
    if(!saBase->peutSpawn())
    {
        return -1;
    }
    else if(tresor < Fantassin::prixF)
    {
        return 0;
    }
    else
    {
        if(tresor >= Catapulte::prixC) //choisir une catapulte
        {
            return 3;
        }
        else if(tresor >= Archer::prixA) // choisir un archer
        {
            return 2;
        }
       else //choisir un fantassin
        {
            return 1;
        }

    }
}

void Joueur::acheter()
{
    std::cout<<"joueur "<<nom<<" : ";
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
            std::cout<<"Pas assez d'or";
            break;
        }
        case 1:
        {
            tresor -= Fantassin::prixF;
            this->armee.push_back(new Fantassin(*this));
            std::cout<<"Achat d'un fantassin";
            break;
        }
        case 2:
        {
            tresor -= Archer::prixA;
            this->armee.push_back(new Archer(*this));
            std::cout<<"Achat d'un archer";
            break;
        }
        case 3:
        {
            tresor -= Catapulte::prixC;
            this->armee.push_back(new Catapulte(*this));
            std::cout<<"Achat d'une catapulte";
            break;
        }
    }
    std::cout<<" (or restant : "<<tresor<<")"<<std::endl;
}

Base& Joueur::getBase() const
{
	return *saBase;
}

void Joueur::jouer()
{
    std::list<Unite*>::const_iterator it_before = armee.begin();
    --it_before;
    std::list<Unite*>::const_iterator it;
    for( it = armee.end(); it != it_before; it--)
    {
       (*it)->action1();
    }

    for( it = armee.begin(); it != armee.end(); it++)
    {
       (*it)->action2();
    }

    for( it = armee.begin(); it != armee.end(); it++)
    {
       (*it)->action3();
    }
    acheter();
}

void Joueur::ajoutArgent(int montant)
{
    std::cout<<"Or joueur "<<nom<< " : "<< tresor;
    this->tresor += montant;
    std::cout<<"->"<<tresor<<std::endl;

}

int Joueur::cote() const
{
	return sonCote;
}

void Joueur::setBase(Base *b)
{
	saBase = b;
}
