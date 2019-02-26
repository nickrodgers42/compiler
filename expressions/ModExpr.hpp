#ifndef MODEXPR_HPP
#define MODEXPR_HPP

#include "Expression.hpp"

class ModExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
        ExprValue* value;
    public:
        ModExpr(Expression* e1, Expression* e2): a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            value = new RegisterValue();
            std::cout << "div " << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            std::cout << "mflo " << value->getRegister() << std::endl;
        }
};

#endif
