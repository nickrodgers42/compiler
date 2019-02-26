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
        ExprValue* value;
    public:
        AddExpr(Expression* e1, Expression* e2) : a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            value = new RegisterValue();
            std::cout << "add " << value->getRegister() << ", "
                      << regA->getRegister() << ", " 
                      << regB->getRegister() 
                      << std::endl;
            return value->getRegister();
        }
};

#endif
