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
        if(tresor >= Catapulte::prixC) //choisir une catapultre
        {
            return 1;
        }
        if(tresor >= Archer::prixA && tresor < Catapulte::prixC) // choisir un archer
        {
            return 2;
        }
        if(tresor >= Fantassin::prixF && tresor < Archer::prixA) // choisir fantassin
        {
            return 3;
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
            tresor = tresor-Catapulte::prixC;
            Catapulte c(this);
        }

    }
}
