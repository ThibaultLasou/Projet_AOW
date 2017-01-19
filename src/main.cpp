#include <iostream>

#include "Jeu.hpp"

int main()
{
	Jeu j("X","Y");
	while(true)
	{
		j.tourDeJeu();
	}

	return 0;
}
