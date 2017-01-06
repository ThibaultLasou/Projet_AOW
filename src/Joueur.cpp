#include "Joueur.hpp"
#include "Base.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
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
        if(tresor >= Fantassin::prixF)
        {
            if(tresor >= Catapulte::prixC) //choisir une catapulte
            {
                return 3;
            }
            else if(tresor >= Archer::prixA) // choisir un archer
            {
                return 2;
            }
           else
            {
                return 1;
            }
        }
    }
}

void Joueur::acheter()
{
    int choixUnite = choix();
    switch(choixUnite)
    {
        case 1:
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
