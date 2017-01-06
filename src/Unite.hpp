#ifndef __UNITE_H__
#define __UNITE_H__
#include <vector>
#include "Attaquable.hpp"
#include "Case.hpp"

class Case;

class Unite : public Attaquable
{
	private :
		int attaque;
		int prix;
		std::vector<int> portee;
		Case& saCase;
		bool attaquer();
		bool avancer();

	public :
		Unite(Joueur& propri, int pv, int attaque, int prix, std::vector<int> port);
		virtual ~Unite();
		virtual bool action1() = 0;
		virtual bool action2() = 0;
		virtual bool action3() = 0;
};

#endif
