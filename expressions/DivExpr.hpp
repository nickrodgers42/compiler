#ifndef DIVEXPR_HPP
#define DIVEXPR_HPP

#include "Expression.hpp"

class DivExpr : public Expression{ 
    private:
        Expression* a;
        Expression* b;
        ExprValue* value;
    public:
        DivExpr(Expression* e1, Expression* e2) : a(e1), b(e2) {} 
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            value = new RegisterValue();
            std::cout << "div " << value->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            std::cout << "mfhi " << value->getRegister() << std::endl;
            return value->getRegister();
        }
};

#endif
