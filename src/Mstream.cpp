#include "Mstream.hpp"

mstream mstream::mout;

mstream::mstream()
{
    coss.open("logPartie.txt");
}

mstream::~mstream()
{
    coss.close();
}


