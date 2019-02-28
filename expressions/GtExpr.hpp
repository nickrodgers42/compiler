#ifndef GTEXPR_HPP
#define GTEXPR_HPP

#include "Expression.hpp"

class GtExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
    public:
        GtExpr(Expression* e1, Expression* e2, Type* type) : Expression(type), a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            auto result = new Register();
            std::cout << "sgt " << result->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            return result;
        }
};

#endif
