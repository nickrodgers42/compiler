#ifndef STATEMENT_HPP
#define STATEMENT_HPP

#include <iostream>
#include <string>

#include "../types/BooleanType.hpp"
#include "../types/CharacterType.hpp"
#include "../types/IntegerType.hpp"
#include "../types/StringType.hpp"

#include "../register.hpp"
#include "../expressions/Expression.hpp"

#include "../exceptions/customExceptions.hpp"

class Statement {
    public:
    virtual void emit() = 0;
};

#endif
