#ifndef ADDEXPR_HPP
#define ADDEXPR_HPP

#include <string>
#include <iostream>

#include "Expression.hpp"
#include "RegisterValue.hpp"
#include "ExprValue.hpp"

class AddExpr : public Expression {
    private: 
        Expression* a;
        Expression* b;
    public:
        AddExpr(Expression* a, Expression* b, Type* type) :
            a(a), b(b), Expression(type) {}
        Register* emit() override {
            auto regA = a->emit();
            auto regB = b->emit();
            auto result = new Register();
            std::cout << "add " << result->getRegister() << ", "
                      << regA->getRegister() << ", " 
                      << regB->getRegister() 
                      << std::endl;
            delete regA;
            delete regB;
            return result;
        }
};

#endif
