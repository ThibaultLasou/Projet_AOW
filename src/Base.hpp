#ifndef __BASE_H__
#define __BASE_H__

#include "Attaquable.hpp"
#include "Case.hpp"

class Base : public Attaquable, public Case
{
	public : 
		bool peutSpawn();
};

#endif
