#ifndef NEQEXPR_HPP
#define NEQEXPR_HPP

#include "Expression.hpp"

class NeqExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
    public:
        NeqExpr(Expression* e1, Expression* e2, Type* type) : Expression(type), a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            auto result = new Register();
            std::cout << "sne " << result->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            return result;
        }
};

#endif
