#ifndef DIVEXPR_HPP
#define DIVEXPR_HPP

#include "Expression.hpp"

class DivExpr : public Expression{ 
    private:
        Expression* a;
        Expression* b;
    public:
        DivExpr(Expression* e1, Expression* e2, Type* type) : Expression(type), a(e1), b(e2) {} 
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            auto result = new Register();
            std::cout << "div "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            std::cout << "mfhi " << result->getRegister() << std::endl;
            return result;
        }
};

#endif
