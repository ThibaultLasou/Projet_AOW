#include <iostream>

#include "Jeu.hpp"
/* Programme principal*/

int main()
{
/*
mstream m;
m<<"sfdgvsg"<<212<<"\n"<<"fsggrse"<<12121<<"fsg\n";
*/

	Jeu j("X","Y");
	while(true)
	{
		j.tourDeJeu();
	}

	return 0;
}
