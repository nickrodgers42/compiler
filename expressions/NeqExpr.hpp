#ifndef NEQEXPR_HPP
#define NEQEXPR_HPP

#include "Expression.hpp"

class NeqExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
        ExprValue* value;
    public:
        NeqExpr(Expression* e1, Expression* e2): a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            value = new RegisterValue();
            std::cout << "sne " << value->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            return value->getRegister();
        }
};

#endif
