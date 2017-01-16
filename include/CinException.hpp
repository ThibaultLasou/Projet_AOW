#ifndef CINEXCEPTION_HPP
#define CINEXCEPTION_HPP
#include <exception>

class CinException : public std::exception
{
    public:
    const char* what() const noexcept;


};

#endif // CINEXCEPTION_HPP
