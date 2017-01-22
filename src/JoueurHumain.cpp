#include "JoueurHumain.hpp"
#include "Joueur.hpp"
#include "Base.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
#include "CinException.hpp"

JoueurHumain::JoueurHumain(std::string nom, int cote) : Joueur(nom, cote)
{

}

int JoueurHumain::choix()
{
    if(!saBase->peutSpawn())
    {
        mstream::mout << "Joueur : "<<nom<<" La base n'est pas libre." << std::endl;
        return -1;
    }
	int c;
	while(true)
	{
		std::cin >> c;
            if(std::cin.eof())
            {
				throw CinException();
            }
            else if(!std::cin.fail())
            {
                switch(c)
                {
                    case 0 :
                    {
                        return 0;
                    }
                    case FANTASSIN :
                    {
                         if(getTresor() >= Fantassin::Prix)
                         {
                            return FANTASSIN;
                         }
                    }
                    case ARCHER :
                    {
                         if(getTresor() >= Archer::Prix)
                         {
                            return ARCHER;
                         }
                    }
                    case CATAPULTE :
                    {
                        if(getTresor() >= Catapulte::Prix)
                        {
                            return CATAPULTE;
                        }
                        mstream::mout << "Pas assez d'argent" << std::endl;
                    }
                    default : mstream::mout << "Ressaisir un chiffre" << std::endl;
                }
            }
            else
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
            }

	}
}
