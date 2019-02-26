#ifndef GTEXPR_HPP
#define GTEXPR_HPP

#include "Expression.hpp"

class GtExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
        ExprValue* value;
    public:
        GtExpr(Expression* e1, Expression* e2): a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            value = new RegisterValue();
            std::cout << "sgt " << value->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            return value->getRegister();
        }
};

#endif
