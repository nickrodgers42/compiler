#ifndef SUBEXPR_HPP
#define SUBEXPR_HPP

#include <iostream>

#include "Expression.hpp"
#include "ExprValue.hpp"
#include "RegisterValue.hpp"

class SubExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
    public:
        SubExpr(Expression* e1, Expression* e2, Type* type) : Expression(type), a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            auto result = new Register();
            std::cout << "sub " << result->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister()
                      << std::endl;
            delete regA;
            delete regB;
            return result;
        }
};

#endif
