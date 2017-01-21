#ifndef MONEXCEPTION_H
#define MONEXCEPTION_H
#include <exception>

/* NotInListException hérite de Exception. Cette exception est levée lorsqu'on cherche dans une liste un élement qui n'y est pas*/
class NotInListException : public std::exception
{
    public:
    const char* what() const noexcept;

};

#endif // MONEXCEPTION_HPP
