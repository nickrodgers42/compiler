#ifndef TYPEMISMATCHEXCEPTION_HPP
#define TYPEMISMATCHEXCEPTION_HPP

#include<iostream>
#include<exception>

class TypeMismatchException : public std::exception {
    public:
        const char* what() const throw() {
            return "Types Do no match";
        }
};

#endif
