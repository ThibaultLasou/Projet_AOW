#ifndef __UNITE_H__
#define __UNITE_H__

#include "Attaquable.hpp"

class Unite : public Attaquable 
{
	private :
		int attaque;
		int* portee;
		int prix;
		
		//attaquer();
		////avancer();
	
	public :
		virtual ~Unite();
		virtual bool action1() = 0;
		virtual bool action2() = 0;
		virtual bool action3() = 0;
};

#endif
