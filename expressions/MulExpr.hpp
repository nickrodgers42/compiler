#ifndef MULEXPR_HPP
#define MULEXPR_HPP

#include "Expression.hpp"
#include "RegisterValue.hpp"

class MulExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
        ExprValue* value;
    public:
        MulExpr(Expression* e1, Expression* e2): a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            value = new RegisterValue();
            std::cout << "mul " << regA->getRegister() << ", "
                      << regB->getRegister()
                      << std::endl;
            std::cout << "mflo " << value->getRegister() << std::endl;
            return value->getRegister();
        }
};

#endif
