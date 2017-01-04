#include "Unite.hpp"
#include "Case.hpp"

Unite::Unite(Joueur &propri, int pv, int att, std::vector<int> port, int price) :
	Attaquable(propri, pv), attaque(att), portee(port), prix(price), saCase(propri.getBase())
{

}

Unite::~Unite()
{

}
