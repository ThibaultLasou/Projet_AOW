#ifndef __CASE_H__
#define __CASE_H__

#include "Unite.hpp"

class Case
{
	private :
		Unite *occupe;

	public :
		virtual ~Case();
		virtual bool estLibre();
};


#endif
