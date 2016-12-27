#include "Base.hpp"

Base::Base(Joueur &propri, int vie) :
	Attaquable(propri, vie)
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