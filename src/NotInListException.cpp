#include "NotInListException.hpp"

    const char* NotInListException::what() const noexcept
    {
        return "L'element n'est pas dans la liste";
    }
