#include "Mstream.hpp"

mstream::mstream()
{
    coss.open("myFile.txt");
}

mstream::~mstream()
{
    coss.close();
}


