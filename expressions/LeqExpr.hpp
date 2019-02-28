#ifndef LEQEXPR_HPP
#define LEQEXPR_HPP

#include "Expression.hpp"

class LeqExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
    public:
        LeqExpr(Expression* e1, Expression* e2, Type* type) : Expression(type), a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            auto result = new Register();
            std::cout << "sle " << result->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            return result;
        }
};

#endif
