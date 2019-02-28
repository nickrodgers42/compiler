#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <iostream>

#include "../types/Type.hpp"
#include "../register.hpp"
#include "ExprValue.hpp"
#include "LiteralValue.hpp"
#include "RegisterValue.hpp"
#include "../types/IntegerType.hpp"

class Expression {
    private:
        Type* type;
    public:
        Expression() = default;
        ~Expression() = default;
        Expression(Type* type) : type(type) {}
        Type* getType() {
            return type;
        };
        void setType(Type* t) {
            type = t;
        }
        virtual bool isConst() { return false; }
        virtual Register* emit() = 0;
};

#endif
