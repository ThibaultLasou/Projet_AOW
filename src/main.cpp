#include <iostream>

#include "Jeu.hpp"

/* Programme principal*/
int main()
{
	Jeu j("X","Y");
	while(true)
	{
		j.tourDeJeu();
	}

	return 0;
}
