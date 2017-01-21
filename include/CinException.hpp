#ifndef CINEXCEPTION_HPP
#define CINEXCEPTION_HPP
#include <exception>

/* Cin hérite de Exception. Cette exception est levée lorsque l'utilisateur saisie à l'entrée standard Ctrl+D*/
class CinException : public std::exception
{
    public:
    const char* what() const noexcept;


};

#endif // CINEXCEPTION_HPP
