#include <iostream>

#include "Jeu.hpp"

int main()
{
	Jeu j("X","Y");
	for(int i=0;i<15;i++)
	{
		j.tourDeJeu();
	}

	return 0;
}
