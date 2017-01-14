#include "JoueurHumain.hpp"
#include "Joueur.hpp"
#include "Base.hpp"
#include "Fantassin.hpp"
#include "Archer.hpp"
#include "Catapulte.hpp"
JoueurHumain::JoueurHumain(std::string nom, int cote) : Joueur(nom, cote)
{

}

int JoueurHumain::choix()
{
    if(!saBase->peutSpawn())
    {
        std::cout << "Joueur : "<<nom<<" La base n'est pas libre." << std::endl;
        return -1;
    }
	int c;
	while(true)
	{
		std::cin >> c;
		if(std::cin.eof())
		{
			/*  TODO Exception */
		}
		else if(!std::cin.fail())
		{
			switch(c)
			{
                case 0 :
                {
                    std::cout << "Pas d'achat" << std::endl;
                    return 0;
                }
				case 1 :
				{
                     if(getTresor() >= Fantassin::prixF)
                     {
                        std::cout << "1" << std::endl;

                     }
                     else
                     {
                        std::cout << "1-Pas assez d'or" << std::endl;
                     }
                     return FANTASSIN;

				}
				case 2 :
				{
                     if(getTresor() >= Archer::prixA)
                     {
                        std::cout << "2" << std::endl;

                     }
                     else
                     {
                        std::cout << "2-Pas assez d'or" << std::endl;
                     }
                     return ARCHER;

				}
				case 3 :
				{
                    if(getTresor() >= Catapulte::prixC)
                    {
                        std::cout << "3" << std::endl;


                    }
                    else
                     {
                         std::cout << "3-Pas assez d'or" << std::endl;
                     }
                     return CATAPULTE;
				}
				std::cout << "4-Pas assez d'argent" << std::endl;
				default : std::cout << "Ressaisir un chiffre" << std::endl;
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
		}
	}
}
