#include "CinException.hpp"

const char* CinException::what() const noexcept
{
    return "Cin exception";
}
