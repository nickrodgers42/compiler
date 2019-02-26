#ifndef EQEXPR
#define EQEXPR

#include "Expression.hpp"

class EqExpr : public Expression { 
    private:
        Expression* a;
        Expression* b;
        ExprValue* value;
    public:
        EqExpr(Expression* e1, Expression* e2): a(e1), b(e2) {}
        Register* emit() {
            auto regA = a->emit();
            auto regB = b->emit();
            value = new RegisterValue();
            std::cout << "seq " << value->getRegister() << ", "
                      << regA->getRegister() << ", "
                      << regB->getRegister() 
                      << std::endl;
            return value->getRegister();
        }
};

#endif
