#ifndef ADDEXPR_HPP
#define ADDEXPR_HPP

#include <string>
#include <iostream>

#include "Expression.hpp"
#include "RegisterValue.hpp"
#include "ExprValue.hpp"

class AddExpr : public Expression {
    private: 
        Expression* left;
        Expression* right;
    public:
        AddExpr(Expression* left, Expression* right, Type* type) :
            left(left), right(right), Expression(type) {}
        Register* emit() override {
            auto regA = left->emit();
            auto regB = right->emit();
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
