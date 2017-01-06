#include "Joueur.hpp"
#include "Base.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
#include <iostream>

Joueur::Joueur(std::string nom, int cote) :
	nom(nom), tresor(0), sonCote(cote), armee()
{
}

Joueur::~Joueur()
{

}

int Joueur::choix()
{
    if(!saBase->peutSpawn() && tresor<Fantassin::prixF)
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
    int choixUnite = choix();
    switch(choixUnite)
    {
        case 0:
        {
            std::cout<<"Vous ne possedez pas assez de pieces d'or pour effectuer des achats"<<std::endl;
        }
        case 1:
        {
            tresor -= Fantassin::prixF;
            this->armee.push_back(new Fantassin(*this));
        }
        case 2:
        {
            tresor -= Archer::prixA;
            this->armee.push_back(new Archer(*this));
        }
        case 3:
        {
            tresor -= Catapulte::prixC;
            this->armee.push_back(new Catapulte(*this));
        }
    }
}

const Base& Joueur::getBase() const
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
    this->tresor += montant;
}
