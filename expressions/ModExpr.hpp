#ifndef MODEXPR_HPP
#define MODEXPR_HPP

#include "Expression.hpp"

class ModExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
    public:
        ModExpr(Expression* e1, Expression* e2, Type* type): Expression(type), a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            auto result = new Register();
            std::cout << "div " << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            std::cout << "mflo " << result->getRegister() << std::endl;
            return result;
        }
};

#endif
