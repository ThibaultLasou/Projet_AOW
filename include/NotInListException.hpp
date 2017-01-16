#ifndef MONEXCEPTION_H
#define MONEXCEPTION_H
#include <exception>

class NotInListException : public std::exception
{
    public:
    const char* what() const noexcept;

};

#endif // MONEXCEPTION_HPP
