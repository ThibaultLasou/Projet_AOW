#include "Base.hpp"

Base::Base(Jeu &jeu, Joueur &propri, int vie) :
	 Case(jeu), Attaquable(propri, vie)
{

}

Base::~Base()
{

}

bool Base::estLibre() const
{
	return false;
}

bool Base::peutSpawn() const
{
	if(occupe == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
