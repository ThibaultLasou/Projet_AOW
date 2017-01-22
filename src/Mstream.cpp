#include "Mstream.hpp"

mstream mstream::mout;

mstream::mstream()
{
    coss.open("myFile.txt");
}

mstream::~mstream()
{
    coss.close();
}


