#include "JoueurHumain.hpp"

JoueurHumain::JoueurHumain(std::string nom, int cote) : Joueur(nom, cote)
{

}

int JoueurHumain::choix()
{
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
				case 1 :
				case 2 :
				case 3 :
					return c;
				default : std::cout << "Blabla" << std::endl;
			}
		}
		else
		{
			std::cin.clear();  
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n' );
		}
	}
}
