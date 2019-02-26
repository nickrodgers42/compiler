#ifndef UNMINUSEXPR_HPP
#define UNMINUSEXPR_HPP

#include "Expression.hpp"

class UnminusExpr : public Expression { 
    private:
        Expression* a;
        ExprValue* value;
    public:
        UnminusExpr(Expression* e1): a(e1) {}
        Register* emit() {
            auto regA = a->emit();
            value = new RegisterValue();
            std::cout << "neg " << value->getRegister() << ", "
                      << regA->getRegister()
                      << std::endl;
            return value->getRegister();
        }
};

#endif
