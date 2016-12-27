#ifndef __FANTASSIN_H__
#define __FANTASSIN_H__

#include "Unite.hpp"

class Fantassin : public Unite
{
	private :
		static int vieF;
		static int attF;
		static int prixF;
		static int[1] porteeF = {1};
	
	public :
		Fantassin();
		~Fantassin();
		action1();
		action2();
		action3();
}

#endif
