#ifndef GEQEXPR_HPP
#define GEQEXPR_HPP

#include "Expression.hpp"

class GeqExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
    public:
        GeqExpr(Expression* e1, Expression* e2, Type* type) : Expression(type), a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            auto result = new Register();
            std::cout << "sge " << result->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            delete regA;
            delete regB;
            return result;
        }
};

#endif
