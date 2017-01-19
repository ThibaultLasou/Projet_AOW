#ifndef __UNITE_H__
#define __UNITE_H__
#include <vector>
#include "Attaquable.hpp"
#include "Case.hpp"

class Case;

class Unite : public Attaquable
{
	protected :
		int attaque;
		int prix; 
		std::vector<int> portee;
		Case* saCase;

		virtual bool attaquer();
		virtual bool avancer();

	public :
		Unite(Joueur& propri, int pv, int attaque, int prix, std::vector<int> port);
		virtual ~Unite();

		virtual void action1() = 0;
		virtual void action2() = 0;
		virtual void action3() = 0;
		virtual std::string toString() const = 0;
		virtual int recevoirDegats(int deg);
};

#endif
