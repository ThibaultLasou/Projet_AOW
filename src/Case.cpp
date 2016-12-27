#include "Case.hpp"

Case::Case() : occupe(nullptr)
{

}

Case::~Case()
{

}

bool Case::estLibre() const
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
