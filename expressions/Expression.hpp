#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <iostream>

#include "../types/Type.hpp"
#include "../register.hpp"
#include "ExprValue.hpp"
#include "RegisterValue.hpp"

class Expression {
    private:
        Type* type;
        ExprValue* value;
    public:
        Type* getType() {
            return type;
        }
        ExprValue* getExprValue() {
            return value;
        }
        virtual Register* emit() = 0;
};

#endif
