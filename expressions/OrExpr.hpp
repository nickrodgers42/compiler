#ifndef OREXPR_HPP
#define OREXPR_HPP

#include "Expression.hpp"

class OrExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
    public:
        OrExpr(Expression* e1, Expression* e2, Type* type) : Expression(type), a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            auto result = new Register();
            std::cout << "or " << result->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            delete regA;
            delete regB;
            return result;
        }
};

#endif
