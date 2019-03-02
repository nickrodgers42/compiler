#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <iostream>
#include <string>

#include "../register.hpp"

class Statement {
    public:
    virtual void emit() = 0;
};

#endif
