#ifndef SUBEXPR_HPP
#define SUBEXPR_HPP

#include <iostream>

#include "Expression.hpp"
#include "ExprValue.hpp"
#include "RegisterValue.hpp"
#include "../register.hpp"

class SubExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
        ExprValue* value;
    public:
        SubExpr(Expression* e1, Expression* e2) : a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            value = new RegisterValue();
            std::cout << "sub " << value->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister()
                      << std::endl;
            return value->getRegister();
        }
};

#endif
