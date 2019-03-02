#ifndef CUSTOMEXCEPTIONS_HPP
#define CUSTOMEXCEPTIONS_HPP

#include <iostream>
#include <exception>

class TypeMismatchException : public std::exception {
    public:
        const char* what() const throw() {
            return "Types Do no match";
        }
};

class IncorrectTypePassed : public std::exception {
    public:
        const char* what() const throw() {
            return "Wrong type of expression passed to function";
        }
};

class CharTooBig : public std::exception {
    public:
        const char* what() const throw() {
            return "The value is too large for a character";
        }
};

class undefinedType : public std::exception {
    public:
        const char* what() const throw() {
            return "Type is undefined";
        }
};


class undefinedVariable : public std::exception {
    public:
        const char* what() const throw() {
            return "Variable is undefined";
        }
};

class incorrectTypePassed : public std::exception {
    public:
        const char* what() const throw() {
            return "An incorrect type has been passed";
        }
};

#endif
