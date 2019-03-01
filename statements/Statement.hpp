#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <iostream>
#include <string>

#include "../register.hpp"

class Statement {
    virtual void emit() = 0;
};

#endif
